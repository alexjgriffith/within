%within%
==
Alexander Griffith, University of Ottawa
--

Provides %within% as an infix function to test wheather or not the values of summits fall within any two pairs.

```r
library(within)

summits <- c(100, 150, 310, 900, 1100)
start <- c(-50, 120 , 310, 1000)
end <- c(200, 300 , 400, 2000)

summits %within% cbind(start,end)

summits %within% cbind(end,start)

summits %within% rbind(end,start)

```