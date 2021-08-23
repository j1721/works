# coding: UTF-8
# モジュールインポート
import requests
from bs4 import BeautifulSoup
import re
#from .models import Blog

# OSDN magazineのURLを変数に確認
URL = 'https://mag.osdn.jp/news/'

# requests.get()でHTMLを取得
result = requests.get(URL)

# BeautifulSoupの機能、html.parserでHTMLやXMLをパースできる。
data1 = BeautifulSoup(result.text, 'html.parser')

# find_allでclassを指定し、見出しを取得
data2 = data1.find_all("h2", class_="entry-title")

data3 = data1.find_all("a")
# URLを出力
print(URL)

# 配列に格納された値をfor文とprint文で出力
for item in data2:
    print(item.getText())

i=0
for item in data3:
    print(i,item.get('href'))
    i+=1

i=0
for item in data2:
    blog = Blog(title=data2[i], content=data3[i+16])
    blog.save()
    i+=1