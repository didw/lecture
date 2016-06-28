import pandas as pd
names = ['Bob','Jessica','Mary','John','Mel']
births = [968, 155, 77, 578, 973]
BabyDataSet = list(zip(names,births))
df = pd.DataFrame(data = BabyDataSet,
columns=['Names', 'Births'])
print(df)

dd = {'names': names, 'births':births}
print(dd)
df1 = pd.DataFrame(dd)
print(df1)

area_dict = {'California': 423967, 'Texas':
695662, 'New York': 141297, 'Florida': 170312,
'Illinois': 149995}
area = pd.Series(area_dict)
pop_dict = {'California': 1423967, 'Texas':
1695662, 'New York': 1141297, 'Florida':
1170312, 'Illinois': 1149995}
population = pd.Series(pop_dict)
states = pd.DataFrame({'population': population,
 'area': area})

print(states)
print(states.index)
print(states.values)
