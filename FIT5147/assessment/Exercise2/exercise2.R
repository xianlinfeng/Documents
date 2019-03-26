#1. Create a static tabular visualisation using ggplot2 that shows for each kind of coral and for 
#         each site how the bleaching varies from year to year. use faceting .
#2. Fit smoothers to the data.
#3.  use Shiny to create an interactive visualisation
#4. Create a map by using Leaflet that shows the location of the sites.
#5. Merge the map into your interactive visualisation. 

# location   coralType longitude latitude year  value

# import library
library(ggplot2) 

# read data
data <- read.csv("assignment-02-data-formated.csv", header = TRUE)

