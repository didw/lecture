install.packages("JPEG")
library("JPEG")

fileUrl <- "https://d396qusza40orc.cloudfront.net/getdata%2Fjeff.jpg"
download.file(fileUrl, destfile="jeff.jpg", method="curl")
jeff <- readJPEG("jeff.jpg", native=TRUE)

> jeff[30]
[1] -11888696


> fileUrl <- "https://d396qusza40orc.cloudfront.net/getdata%2Fdata%2FGDP.csv"
> download.file(fileUrl, destfile="FGDP.csv",method="curl")
> fgdp <- read.csv("FGDP.csv")
> fileUrl <- "https://d396qusza40orc.cloudfront.net/getdata%2Fdata%2FEDSTATS_Country.csv"
> download.file(fileUrl, destfile="FEDSTATS.csv",method="curl")
> fed <- read.csv("FEDSTATS.csv")


> fgdpdf <- tbl_df(fgdp)
> feddf <- tbl_df(fed)
> gdp <- gather(fgdpdf, feddf)
Warning message:
attributes are not identical across measure variables; they will be dropped 
> 




