#' @useDynLib within, .registration =TRUE
NULL

#' within
#'
#' @examples
#' summits<-c(1,10,100,200)
#' body<-rbind(c(0,2),c(1,10),c(11,9),c(201,199))
#' within(summits,body[,1],body[,2])
inbetween <- function(summits,starts,ends){
    results<-.C("within",
                summits=as.integer(summits),
                start=as.integer(starts),
                end=as.integer(ends),
                ret=integer(length(summits)),
                length=as.integer(length(summits)),
                range=as.integer(length(ends)))
    as.logical(results$ret)
}

#' within
#'
#' Determines if the values in summits fall between the columns of twoCol.
#' Note that the columns in twoCol must be integer values and that the order
#' has no impact.
#' 
#' @param summits A vector of numeric to be tested
#' @param towCol Two columns the values of the vectors should fall between
#' @return a vector of logical the same length as summits 
#' @examples
#' summits<-c(1,10,100,200)
#' body<-rbind(c(0,2),c(1,10),c(11,9),c(201,199))
#' summits %within% body
#' # or
#' do.call("%within%",list(summits,body))
#' # if there are two rows and not two columns the body
#' # will automaticaly be transposed
#' (summits %within% t(body)) == (summits %within% body)
#' @export
`%within%` <- function(summits,twoCol){
    if(!is.numeric(twoCol) | !is.numeric(summits))
        stop("Inputs to %within% must be numeric.")
    if(is.null(dim(twoCol)))
        stop("twoCol must be two columns.")
    if(dim(twoCol)[1]==2 & dim(twoCol)[2]!=2){
        warning("Using rows rather than columns")
        twoCol<-t(twoCol)
    }
    if(dim(twoCol)[2]>2)
        warning("Using the first two columns only")    
    if(dim(twoCol)[2]<2)
        stop("To few columns in the second argument")    
    inbetween(summits,twoCol[,1],twoCol[,2])
}
