library(ggplot2)
library(shiny)
library(leaflet)

# task 1
df <- read.csv('assignment-02-data-formated.csv',header = TRUE,stringsAsFactors = FALSE)
df$value <- gsub("%","",df$value)
df$value <- as.numeric(df$value)
df$value <- (df$value)/100
df$location <- factor(df$location,levels = c("site04","site02","site06","site08","site07","site05","site01","site03"))
str(df)
df

############################################################################################
# task 2
g0 <- ggplot(data = df, aes(x=year, y = value))
g1 <- g0 + geom_point(aes(color = location))
g2 <- g1 + facet_grid(coralType~location)
g3 <- g2 + geom_smooth(method = "lm",formula = y ~ x,color = "blue",size = 0.5,se=F)
g4 <- g3 + theme_bw() +
  scale_x_continuous("the year, location and coral type") +
  scale_y_continuous("the bleaching of corals") +
  theme(legend.position = "buttom", legend.direction = "horizontal") + ggtitle("Coral Bleaching Situation for five Corals")
g4 
#########################################################################################
# task 4
library(leaflet)
leaflet(data = df) %>% addTiles() %>%
  addMarkers(~longitude, ~latitude, popup = ~as.character(location)  )

#########################################################################################
# task 5: key codes
dd <- aggregate(value ~ coralType + location + longitude + latitude, data = df, mean) # aggregate the data

getColor <- function(df) { # set the color
  sapply(df$value, function(value) {
    if(value <= 0.3) {
      "green"
    } else if(value <= 0.6) {
      "orange"
    } else if(value <= 0.9){
      "red"
    } else {
      "black"
    }
  })
}

icons <- awesomeIcons( # set the icon
  icon = 'ios-close',
  iconColor = 'black',
  library = 'ion',
  markerColor = getColor(df)
)  

dr <- dd[which(dd$coralType == input$coral),]
leaflet(dr) %>% addTiles() %>% addAwesomeMarkers(~longitude, ~latitude, icon=icons)
   # it will change the color when choose the different coral 
   # the color indicate the situation of the site for the choosen coral 
