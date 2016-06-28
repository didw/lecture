# Read XML data
from bs4 import BeautifulSoup

fp = open("song.xml")


soup = BeautifulSoup(fp, "html.parser")

for songElm in soup.findAll('song'):
    print(songElm)
    print(songElm['sname'])
    print(songElm.title.string)
    print(songElm.singer.string)
