import numpy as np
import pandas as pd
A = np.array(['one', 'one', 'two', 'two', 'three', 'three'])
B = np.array(['start', 'end']*3)
C = [np.random.randint(10, 99, 6)]*6
df = pd.DataFrame(list(zip(A, B, C)), columns=['A', 'B', 'C'])
print(df)
print(df.index)
print(df.columns)
print(df["A"])
print(df.T)
#print(df.describe())
print(df.info())
