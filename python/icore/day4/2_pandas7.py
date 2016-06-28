import pandas as pd

names = ['Bob','Jessica','Mary','John','Mel']
births = [968, 155, 77, 578, 973]
BabyDataSet = list(zip(names,births))
df = pd.DataFrame(data = BabyDataSet,
columns=['Names', 'Births'])
print(df)

print(df.describe())
print(df.info())

df.to_excel("pandas.xls")

