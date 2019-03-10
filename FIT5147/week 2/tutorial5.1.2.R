# ui.R
library(shiny)
library(ggplot2)
library(datasets)

# Define UI for miles per gallon application
ui <- fluidPage( 
  
  # Application title
  headerPanel("Miles Per Gallon"),
  
  # Sidebar with controls to select the variable to plot against
  # mpg and to specify whether outliers should be included
  sidebarLayout(
    sidebarPanel(
      selectInput("variable", "Variable:", 
                  c("Cylinders" = "cyl", 
                    "Transmission" = "am",
                    "Gears" = "gear")
      ),
      
      checkboxInput("outliers", "Show outliers", FALSE)
    ),
    
    # Show the caption and plot of the requested variable against mpg
    mainPanel(
      h3(textOutput("caption")),
      plotOutput("mpgPlot")
    )
  )
)


# server.R


mpgData <- mtcars
mpgData$am <- factor(mpgData$am, labels = c("Automatic", "Manual"))
# Define server logic required to plot various variables against mpg
server <- function(input, output) {
  
  # Return the formula text for printing as a caption
  output$caption <- reactiveText(function() {
    paste("mpg ~", input$variable)
  })
  
  # Generate a plot of the requested variable against mpg and only 
  # include outliers if requested
  # ggplot version
  
  output$mpgPlot <- reactivePlot(function() {
    # check for the input variable
    if (input$variable == "am") {
      # am
      mpgData <- data.frame(mpg = mtcars$mpg, 
                            var = factor(mtcars[[input$variable]], 
                                         labels = c("Automatic", "Manual")))
    }
    else {
      # cyl and gear
      mpgData <- data.frame(mpg = mtcars$mpg, 
                            var = factor(mtcars[[input$variable]])
      )
    }
    
    p <- ggplot(mpgData, aes(var, mpg)) + 
      geom_boxplot(outlier.size = ifelse(input$outliers, 2, NA)) + 
      xlab(input$variable)
    print(p)
  })
  
}



# create shiny app
shinyApp(ui = ui, server = server)

