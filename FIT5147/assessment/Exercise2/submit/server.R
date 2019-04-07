# server.R
library(shiny)
library(ggplot2)
library(leaflet)

function(input, output) {
  df <- read.csv('assignment-02-data-formated.csv',header = TRUE,stringsAsFactors = FALSE)
  df$value <- gsub("%","",df$value)
  df$value <- as.numeric(df$value)
  df$value <- (df$value)/100
  df$location <- factor(df$location,levels = c("site04","site02","site06","site08","site07","site05","site01","site03"))
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
    markerColor = getColor(df))
  
  output$coralPlot <- renderPlot({
    ggplot(data = df[which(df$coralType == input$coral),], aes(x=year, y = value)) + geom_point(aes(color = location),size = 5) + 
      facet_wrap(~location,nrow = 2 )+theme_bw()+geom_smooth(method = input$smooth,color = "blue",size = 0.6,se=T) + 
      ggtitle(paste("Bleaching Situation of ",input$coral))
    })
  
  # geom_smooth(method = input$smooth,color = "black",size = 0.2,se=F)
  output$siteMap <- renderLeaflet({ # create leaflet map
    leaflet(dd[which(dd$coralType == input$coral),]) %>% addTiles() %>% addAwesomeMarkers(~longitude, ~latitude, icon=icons)
  })
}

