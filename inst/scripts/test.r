setwd("~/masters/r-workspace/within")
devtools::document()
devtools::install()
library(within)
summits<-c(1,10,100,200)
body<-rbind(c(0,2),c(1,10),c(11,9),c(201,199))
#inbetween(summits,body[,1],body[,2])
summits %within% body
