import pandas as pd
import matplotlib.pyplot as plt

"""
plt.plot([0,3,10], [3,10,13])
plt.bar([0,3,10], [3,10,13])
plt.show()
"""

df = pd.read_excel("pandas.xls")

print(df)
x1 = [1,2,3,4,5]
plt.xticks(x1, df['Names'])
plt.bar(x1, df['Births'], align='center', color='red')
plt.show()
