rankall <- function(outcome, num="best") {
  ## Read outcome data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
  
  ## Check that state and outcome are valid
  if (all(c("heart attack", "heart failure", "pneumonia") != outcome))
    stop("invalid outcome")
  
  if (outcome == "heart attack") {
    data <- data[,c(2,7,11)]
  }
  else if (outcome == "heart failure"){
    data <- data[,c(2,7,17)]
  }
  else if (outcome == "pneumonia"){
    data <- data[,c(2,7,23)]
  }
  data[,3] = as.numeric(data[,3])
  data <- data[!is.na(data[,3]), ]
  names(data) <- c("Name", "State", "Rate")
  
  ## For each state, find the hospital of the given rank
  hospitallist = matrix("", length(unique(data[,2])), 2)
  rownames(hospitallist) <- unique(data[,2])[order(unique(data[,2]))]
  for (state in unique(data[,2])) {
    data2 <- data[data[,2] == state, ]
    data2 <- data2[with(data2, order(Rate, Name)),]
    if (num == "best") {
      hospitallist[state,] <- c(data2[[1,1]], state)
    }
    else if (num == "worst") {
      hospitallist[state,] <- c(data2[[nrow(data2),1]], state)
    }
    else if (num <= nrow(data2)) {
      hospitallist[state,] <- c(data2[[num,1]],state)
    }
    else {
      hospitallist[state,] <- c("NA", state)
    }
  }
  
  ## Return a data frame with the hospital names and the
  ## (abbreviated) state name
  colnames(hospitallist) <- c("hospital", "state")
  data.frame(hospitallist)
}