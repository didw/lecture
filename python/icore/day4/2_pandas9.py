# plot
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_excel("pandas.xls")
print(df)
print(type(df['Births']))

df.plot(kind='bar')
plt.show()
