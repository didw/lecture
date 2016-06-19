library(sqldf)
library(data.table)
url <- 'https://d396qusza40orc.cloudfront.net/getdata%2Fdata%2Fss06pid.csv'
f <- file.path(getwd(), 'ss06pid.csv')
if(!file.exists(f)) {
  download.file(url, f)
}
acs <- data.table(read.csv(f))
query1 <- sqldf("select pwgtp1 from acs where AGEP < 50")
