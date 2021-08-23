from django.shortcuts import render,redirect
from .models import Blog
from django.contrib.auth.decorators import login_required
from bs4 import BeautifulSoup
# モジュールインポート
import requests
import re

# Create your views here.
def hello(request):
    return render(request,'hello.html',{'message':'Hello World'})

@login_required
def list(request):
    blog_list = Blog.objects.all()
    return render(request,'list.html',{'blog_list':blog_list})


def detail(request,pk):
    blog = Blog.objects.get(pk=pk)
    return render(request,'detail.html',{'blog':blog})


def create(request):
    if request.method == 'POST':
        blog = Blog(title=request.POST.get('title'), content=request.POST.get('content'))
        blog.save()
        return redirect('list')
    else:
        return render(request, 'create.html')

def update(request, pk):
    blog = Blog.objects.get(pk=pk)
    if request.method == 'POST':
        blog.title = request.POST.get('title')
        blog.content = request.POST.get('content')
        blog.save()
        return redirect('list')
    return render(request, 'update.html', {'blog': blog})

def delete(request, pk):
    blog = Blog.objects.get(pk=pk)
    if request.method == 'POST':
        blog.delete()
        return redirect('list')
    return render(request, 'delete.html', {'blog': blog})

def get_info(request):
    if request.method == 'POST':
        # OSDN magazineのURLを変数に確認
        URL = 'https://mag.osdn.jp/news/'
        # requests.get()でHTMLを取得
        result = requests.get(URL)
        # BeautifulSoupの機能、html.parserでHTMLやXMLをパースできる。
        data1 = BeautifulSoup(result.text, 'html.parser')
        # find_allでclassを指定し、見出しを取得
        data2 = data1.find_all("h2", class_="entry-title")
        data3 = data1.find_all("a")
        # 配列に格納された値をfor文とprint文で出力
        for item in data2:
            print(item.getText())
        i=0
        for item in data3:
            print(i,item.get('href'))
            i+=1
        
        blog_list = Blog.objects.all()
        i=0
        for item in reversed(data2):
            flg=0
            for blog in blog_list:
                if blog.title==item.getText():
                    flg=1
            if flg==0:
                a = Blog(title=item.string, content=data3[data2.index(item)+16].get('href'))
                a.save()
            i+=1
            flg=0
        #print(data3[16].get('href'))
        return redirect('list')
    else:
        return render(request, 'get_info.html')



