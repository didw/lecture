rankhospital <- function(state, outcome, num = "best") {
  ## Read outcome data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
  
  ## Check that state and outcome are valid
  if (all(data[,7] != state)){
    stop("invalid state")
  }
  if (all(c("heart attack", "heart failure", "pneumonia") != outcome)){
    stop("invalid outcome")
  }
  
  ## Return hospital name in that state with the given rank
  ## 30-day death rate
  if (outcome == "heart attack") {
    data <- data[,c(2,7,11)]
  }
  else if (outcome == "heart failure"){
    data <- data[,c(2,7,17)]
  }
  else if (outcome == "pneumonia"){
    data <- data[,c(2,7,23)]
  }
  names(data) <- c("Name", "State", "Rate")
  data[,3] <- as.numeric(data[,3])
  data <- data[!is.na(data[,3]),]
  data <- data[data[,2] == state,]
  data <- data[with(data, order(Rate, Name)),]
  if (num == "best")
    res = data[1,1]
  else if (num == "worst")
    res = data[nrow(data),1]
  else if (num <= nrow(data)){
    res = data[num,1] 
  }
  else{
    res = NA
  }
  res
}
