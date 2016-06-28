from bs4 import BeautifulSoup
import urllib.request as urlreq

jURL = "http://rss.joins.com/joins_news_list.xml"
response = urlreq.urlopen(jURL)
#raw_text = response.read().decode()

xml_text = BeautifulSoup(response, "html.parser")
for itemElm in xml_text.findAll('item'):
    print("Title: ", itemElm.title.string)
    print("Contents: ", itemElm.description.string)
