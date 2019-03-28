# ui.R
library(shiny)
library(ggplot2)

# Define UI for miles per gallon application
shinyUI(fluidPage( 
  
  # Application title
  titlePanel("Bleaching of corals"),
  
  # Sidebar with controls to select the variable to plot against
  # mpg and to specify whether outliers should be included
  sidebarLayout(
      selectInput(inputId = "coral",
      label = "Please select one type of coral:",
      choices = c("blue corals","hard corals","sea pens","soft corals","sea fans" ),
      selected = "blue corals"),
  
      checkboxInput(inputId = "smooth",
      label = strong("Show the smooth line?"),
      value = FALSE)
    ),
  
  # Show the caption and plot of the requested variable against mpg
  mainPanel(
    plotOutput(outputId = "coralPlot"),
  )
)
)
