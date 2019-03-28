# ui.R
library(shiny)

bootstrapPage(
  # Application title
  titlePanel("Bleaching of corals"),
  
  selectInput(inputId = "coral",
    label = "Please select one type of coral:",
    choices = c("blue corals","hard corals","sea pens","soft corals","sea fans" ),
    selected = "blue corals"),

  checkboxInput(inputId = "smooth",
    label = strong("Show the smooth line?"),
    value = FALSE),

  # Show the caption and plot of the requested variable against mpg
  mainPanel(
    plotOutput(outputId = "coralPlot",width = 800, height = 600)
  )
)
