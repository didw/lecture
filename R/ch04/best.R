best <- function(state, outcome) {
  ## Read outcome data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
  
  ## Check that state and outcome are valid
  if (all(data[,7] != state)){
      stop("invalid state")
  }
  if (all(c("heart attack", "heart failure", "pneumonia") != outcome)){
      stop("invalid outcome")
  }
  
  ## Return hospital name in that state with lowest 30-day death rate
  if (outcome == "heart attack") {
    data <- data[,c(2,7,11)]
  }
  else if (outcome == "heart failure"){
    data <- data[,c(2,7,17)]
  }
  else if (outcome == "pneumonia"){
    data <- data[,c(2,7,23)]
  }
  data[,3] <- as.numeric(data[,3])
  data <- data[!is.na(data[,3]) & data[,2] == state,]
  data[,1][data[,3] == min(data[,3])]
}
