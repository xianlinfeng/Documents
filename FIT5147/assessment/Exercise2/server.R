# server.R
library(shiny)
library(ggplot2)

function(input, output) {
  df <- read.csv('assignment-02-data-formated.csv',header = TRUE,stringsAsFactors = FALSE)
  df$value <- gsub("%","",df$value)
  df$value <- as.numeric(df$value)
  df$value <- (df$value)/100
  df$location <- factor(df$location,levels = c("site04","site02","site06","site08","site07","site05","site01","site03"))
  
  output$coralPlot <- renderPlot({
    g0 <- ggplot(data = df[which(df$coralType == input$coral),], aes(x=year, y = value)) + geom_point(aes(color = location)) + facet_grid(location~coralType)+theme_bw()
    
    if(input$smooth){
      g0 + geom_smooth(method = "lm",formula = y ~ x,color = "black",size = 0.2,se=F)
    }else{
      g0
    }

  })
}

