import pandas as pd


myDic = {"LG1":[1000,2000,3000,4000,3000],
         "LG2":[3000,2400,1000,4000,1000],
         "LG3":[4000,2200,2000,4000,3000],
         }
myDicIdx = ['15-01','15-02','15-03','15-04','15-05']
colm = ['LG1', 'LG2', 'LG3']
df = pd.DataFrame(myDic, columns = colm, index = myDicIdx)
print(df)

print(df.sum(axis = 0))
print(df.sum(axis = 1))
print(df.max(axis = 0))
print(df.sort_values(by='LG1', ascending=False))
print(df.sort_index(axis=1, ascending=False))
