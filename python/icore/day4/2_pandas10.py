# Plot Stock Price
import datetime
import matplotlib.pyplot as plt
from pandas_datareader import data

startDate = datetime.datetime(2015,6,16)
endDate = datetime.datetime(2016,6,16)
dr = data.DataReader('066570.KS', 'yahoo', startDate, endDate)
print(dr)
font = {'family' : 'Arial',
        'weight' : 'bold',
        'size'   : 22}
plt.rc('font', family='Gulim')

plt.plot(dr.index, dr['Open'], 'r--', dr.index, dr['Close'], 'b-')
plt.show()
