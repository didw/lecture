### read data and get specific information from data
    data<-read.csv(file="hw1_data.csv", head=TRUE)

- from the condition on Ozone>31 and Temp>90, what is the mean of Solar.R
    cri1<-data$Ozone>31
    cri2<-data$Temp>90
    data2<-data$Solar.R(cri1&cri2)
    mean(data2[!is.na(data2)])

