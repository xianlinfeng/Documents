# ui.R
library(shiny)
library(ggplot2)
library(leaflet)

fluidPage(
  # Application title
  titlePanel("Bleaching of corals"),
  
  sidebarLayout(
    # Sidebar with a slider and selection inputs
    sidebarPanel(
      selectInput(inputId = "coral",
                  label = "Please select one type of coral:",
                  choices = c("sea fans","blue corals","hard corals","sea pens","soft corals"),
                  selected = "sea fans"),

      selectInput(inputId = "smooth",
                  label = "Please select the type of smoother:",
                  choices = c("auto","lm","glm","gam","loess" ),
                  selected = "auto")
    ),
    
    mainPanel(
      plotOutput(outputId = "coralPlot"),
      leafletOutput("siteMap")
    )
  )
)

