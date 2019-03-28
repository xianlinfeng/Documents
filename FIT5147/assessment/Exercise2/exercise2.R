library(ggplot2)

# task 1
df <- read.csv('assignment-02-data-formated.csv',header = TRUE,stringsAsFactors = FALSE)
df$value <- gsub("%","",df$value)
df$value <- as.numeric(df$value)
df$value <- (df$value)/100
df$location <- factor(df$location,levels = c("site04","site02","site06","site08","site07","site05","site01","site03"))
str(df)

# task 2
g0 <- ggplot(data = df, aes(x=year, y = value))
g1 <- g0 + geom_point(aes(color = location))
g2 <- g1 + facet_grid(coralType~location)
g3 <- g2 + geom_smooth(method = "lm",formula = y ~ x,color = "black",size = 0.2,se=F)
g4 <- g3 + theme_bw() +
  scale_x_continuous("the year, location and coral type") +
  scale_y_continuous("the bleaching of corals") +
  theme(legend.position = "buttom", legend.direction = "horizontal")
g4 

# task 4
library(leaflet)
m <- leaflet() %>% 
  setView(lng = 145.0431, lat = -37.8773, zoom = 15) %>% 
  addTiles()
m

