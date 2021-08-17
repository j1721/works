from django.shortcuts import render
from .models import Blog

# Create your views here.
def hello(request):
    return render(request,'hello.html',{'message':'Hello World'})


def list(request):
    blog_list = Blog.objects.all()
    return render(request,'list.html',{'blog_list':blog_list})



