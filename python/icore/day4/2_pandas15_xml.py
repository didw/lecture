from bs4 import BeautifulSoup
import pandas as pd

df = pd.DataFrame( columns=['title','singer'] )

fp = open("song.xml")
soup = BeautifulSoup(fp, "html.parser")

for songElm in soup.findAll('song'):
    row = dict( zip(['title','singer'],
                    [songElm.title.string, songElm.singer.string]))
    df = df.append(pd.Series(row), ignore_index=True)

print(df)
