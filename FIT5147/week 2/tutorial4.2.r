library(ggplot2)

myGraph <- ggplot(mtcars, aes(mpg, hp))

g1 <- myGraph + geom_point(colour = "Blue")

## another example

myData <- read.csv('sample-data-for-r-plot.csv')
# first plot
ggplot(myData, aes(Year, Number)) + geom_point(aes(shape = Sex, colour = State, size = Sex)) + facet_wrap(~Sex, nrow=1)

# seconde plot
ggplot(myData, aes(Year, Number)) + geom_point(aes(shape = Sex, colour = State, size = Sex)) + facet_grid(Sex~State)

# third plot
ggplot(myData,aes(Year,Number)) + geom_bar(stat = "identity") + facet_grid(Sex~State)

