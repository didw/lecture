## chapter1 quiz

## Problem 1 read csv
if(!file.exists('data/survey.csv')) {
  fileUrl <- 'https://d396qusza40orc.cloudfront.net/getdata%2Fdata%2Fss06hid.csv'
  download.file(fileUrl, destfile='data/survey.csv')
}
survey <- read.csv('data/survey.csv')
print(paste0("P1: ", sum(survey$VAL==24, na.rm=TRUE)))


## Problem 3 read xlsx
library(xlsx)
colIndex <- 7:15
rowIndex <- 18:23
dat <- read.xlsx('./data/ngap.xlsx', sheetIndex=1, colIndex=colIndex, rowIndex=rowIndex)
print(paste0("P3: ", sum(dat$Zip * dat$Ext, na.rm=T)))


## problem 4 read xml
library(XML)
if(!file.exists('data/restaurants.xml')) {
  fileUrl <- "https://d396qusza40orc.cloudfront.net/getdata%2Fdata%2Frestaurants.xml"
  download.file(fileUrl, destfile = 'data/restaurants.xml')
}
doc <- xmlTreeParse('data/restaurants.xml', useInternal=TRUE)
rootNode <- xmlRoot(doc)
zip <- xpathSApply(rootNode, "//zipcode", xmlValue)
print(paste0('P4: ', sum(zip==21231)))

## problem 5 to use fread
library(data.table)
if(!file.exists('data/survey2.csv')) {
  fileUrl <- 'https://d396qusza40orc.cloudfront.net/getdata%2Fdata%2Fss06pid.csv'
  download.file(fileUrl, destfile = 'data/survey2.csv')
}
DT <- fread('data/survey2.csv')
print("DT[,mean(pwgtp15),by=SEX]: ")
print(system.time(DT[,mean(pwgtp15),by=SEX]))
print("mean(DT$pwgtp15,by=DT$SEX): ")
print(system.time(mean(DT$pwgtp15,by=DT$SEX)))
print("mean(DT[DT$SEX==1,]$pwgtp15): ") 
print(system.time(mean(DT[DT$SEX==1,]$pwgtp15)))
print("mean(DT[DT$SEX==2,]$pwgtp15): ")
print(system.time(mean(DT[DT$SEX==2,]$pwgtp15)))
print("tapply(DT$pwgtp15,DT$SEX,mean): ")
print(system.time(tapply(DT$pwgtp15,DT$SEX,mean)))
print("rowMeans(DT)[DT$SEX==1]: ")
# print(system.time(rowMeans(DT)[DT$SEX==1]))
print("rowMeans(DT)[DT$SEX==2]: ")
# print(system.time(rowMeans(DT)[DT$SEX==2]))
print("sapply(split(DT$pwgtp15,DT$SEX),mean): ")
print(system.time(sapply(split(DT$pwgtp15,DT$SEX),mean)))

      
