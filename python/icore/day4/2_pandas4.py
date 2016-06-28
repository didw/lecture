import pandas as pd
# Our small data set
d = [0,1,2,3,4,5,6,7,8,9]
# Create dataframe
df = pd.DataFrame(d)
df.columns = ['Rev']
df['Col'] = df['Rev']
i = ['a','b','c','d','e','f','g','h','i','j']
df.index = i

print(df.head(10))

print(df.tail())
