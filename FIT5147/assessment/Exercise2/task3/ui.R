# ui.R
library(shiny)

fluidPage(
  # Application title
  titlePanel("Bleaching of corals"),
  
  sidebarLayout(
    # Sidebar with a slider and selection inputs
    sidebarPanel(
      selectInput(inputId = "coral",
                  label = "Please select one type of coral:",
                  choices = c("blue corals","hard corals","sea pens","soft corals","sea fans" ),
                  selected = "blue corals"),
      
      checkboxInput(inputId = "smooth",
                    label = strong("Show the smooth line?"),
                    value = FALSE)
    ),
    
    # Show Word Cloud
    mainPanel(
      plotOutput(outputId = "coralPlot")
    )
  )
)