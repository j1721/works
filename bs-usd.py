from bs4 import BeautifulSoup
import requests

url='https://stocks.finance.yahoo.co.jp/stocks/detail/?code=USDJPY=X'
response=requests.get(url)
print(response)

soup=BeautifulSoup(response.content,"html.parser")

price=soup.select_one('.stoksPrice').string

print("USD/JPY:",price)