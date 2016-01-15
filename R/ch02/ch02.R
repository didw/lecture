getfilename <- function(directory, id) {
	if (id < 10) filename = paste(directory,"/00",id,".csv",sep="")
	else if (id < 100) filename = paste(directory,"/0",id,".csv",sep="")
	else filename = paste(directory,"/",id,".csv",sep="")
	filename
	
}
pollutantmean <- function(directory, pollutant, id = 1:332) {
	## 'directory' is a character vector of length 1 indicating
	## the location of the CSV files

	## 'pollutant' is a character vector of length 1 indicating
	## the name of the pollutant for which we will calculate the
	## mean; either "sulfate" or "nitrate".

	## 'id' is an integer vector indicating the monitor ID numbers
	## to be used

	## Return the mean of the pollutant across all monitors list
	## in the 'id' vector (ignoring NA values)
	## NOTE: Do not round the result!
	sum_all <- 0
	length_all <- 0
	for (i in id) {
		filename <- getfilename(directory, i)
		data <- read.csv(filename, head=TRUE)
		sum_all <- sum_all + sum(data[[pollutant]], na.rm=TRUE)
		length_all <- length_all + length(data[[pollutant]][!is.na(data[[pollutant]])])
	}
	sum_all / length_all
}

complete <- function(directory, id = 1:332) {
	## 'directory' is a character vector of length 1 indicating
	## the location of the CSV files

	## 'id' is an integer vector indicating the monitor ID numbers
	## to be used

	## Return a data frame of the form:
	## id nobs
	## 1 117
	## 2 1041
	## ...
	## where 'id' is the monitor ID number and 'nobs' is the
	## number of complete cases
	nobs <- c(id)
	for (i in id) {
		filename <- getfilename(directory, i)
		data <- read.csv(filename, head=TRUE)
		nobs <- append(nobs, length(data$sulfate[!is.na(data$sulfate)&!is.na(data$nitrate)]))
	}
	my_matrix <- matrix(nobs, length(id), 2)
	colnames(my_matrix) <- c("id", "nobs")
	my_matrix
}

corr <- function(directory, threshold = 0) {
	## 'directory' is a character vector of length 1 indicating
	## the location of the CSV files

	## 'threshold' is a numeric vector of length 1 indicating the
	## number of completely observed observations (on all
	## variables) required to compute the correlation between
	## nitrate and sulfate; the default is 0

	## Return a numeric vector of correlations
	## NOTE: Do not round the result!
	
}
