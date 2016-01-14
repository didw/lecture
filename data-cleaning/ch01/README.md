    download.file(fileUrl, destfile="./data/ngap.xlsx",method="curl")
    restaurants <- read.xlsx("./data/restaurants.xlsx", sheetIndex=1,header=TRUE)
    
