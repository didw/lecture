# Pandas Series
import pandas as pd

sr = pd.Series( ['aaa', 'bbb' ,'ccc', 'ddd' ])
sr1 = pd.Series( [ 1010, 2020, 3030, 4040, 5050],
                 index = ['15-01', '15-02', '15-03', '15-04', '15-05'] )
sr2 = pd.Series( {'a':0, 'b':1, 'c': 2 } )

print(sr)
print(sr1)
print(sr2)

print(sr[0:4])
print(sr1['15-01':'15-04'])
print(sr2['a':'c'])
