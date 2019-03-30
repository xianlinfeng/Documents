# 6.1
library(leaflet)

m <- leaflet() %>% 
  setView(lng = 145.0431, lat = -37.8773, zoom = 15) %>% 
  addTiles()
m


m <- leaflet() 
m
m <- setView(m, lng = 145.0431, lat = -37.8773, zoom = 15)
m
m <- addTiles(m)
m
m %>% addProviderTiles("Stamen.Toner") # Add a tile layer from a known map provider 
m %>% addProviderTiles("Stamen.Watercolor")
m %>% addProviderTiles("Stamen.TonerHybrid") 

############################################################################################################
# 6.2

library(leaflet)
data <- read.csv("vet_schools_in_victoria.csv")
head(data)


leaflet(data = data[1:30, ]) %>% addTiles() %>%
  addMarkers(~longitude, ~latitude, popup = ~as.character(location)) 
# addMarkers --- Add graphics elements and layers to the map widget. 


leaflet(data = data) %>% addTiles() %>%
  addMarkers(~longitude, ~latitude, popup = ~as.character(location)) 

leaflet(data = data) %>% addTiles() %>%
  addMarkers(
    ~longitude, 
    ~latitude, 
    popup = ~as.character(location),
    clusterOptions = markerClusterOptions()
  )

###############################################################################################
#6.3 Choropleth Map
data <- read.csv("Household-heating-by-State-2008.csv", header=T) 
names(data)[4] <- "MobileHomes"
head(data)
ag <- aggregate(MobileHomes ~ States, FUN = mean, data = data)
ag
ag$States <- tolower(ag$States)
ag

library(maps)
mapStates <- map("state", fill = TRUE, plot = FALSE)
# find the related rate for each state
rates <- ag$MobileHomes[match(mapStates$names, ag$States)] 
mapStates

library(leaflet)
cpal <- colorNumeric("Blues", rates) # prepare the color mapping
leaflet(mapStates) %>% # create a blank canvas
  addTiles() %>% # add tile
  addPolygons( # draw polygons on top of the base map (tile)
    stroke = FALSE, 
    smoothFactor = 0.2, 
    fillOpacity = 1,
    color = ~cpal(rates) # use the rate of each state to find the correct color
  ) 

mapStates$names
ag$States

spliteNames <- strsplit(mapStates$names, ":") 
firstPartNames <- lapply(spliteNames, function(x) x[1])  
rates <- ag$MobileHomes[match(firstPartNames, ag$States)]

cpal <- colorNumeric("Blues", rates) # prepare the color mapping
leaflet(mapStates) %>% # create a blank canvas
  addTiles() %>% # add tile
  addPolygons( # draw polygons on top of the base map (tile)
    stroke = FALSE, 
    smoothFactor = 0.2, 
    fillOpacity = 1,
    color = ~cpal(rates) # use the rate of each state to find the correct color
  )




library(rgdal)
world_map <- readOGR("ne_50m_admin_0_countries.shp")
gdp_data <- read.csv("WorldGDP.csv")














