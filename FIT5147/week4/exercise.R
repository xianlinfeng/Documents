library(leaflet)
data <- read.csv("vet_schools_in_victoria.csv")
head(data)

leaflet(data = data[1:30, ]) %>% addTiles() %>%
  addMarkers(~longitude, ~latitude, popup = ~as.character(location))


leaflet(data = data) %>% addTiles() %>%
  addMarkers(~longitude, ~latitude, popup = ~as.character(location)) 


leaflet(data = data) %>% addTiles() %>%
  addMarkers(
    ~longitude, 
    ~latitude, 
    popup = ~as.character(location),
    clusterOptions = markerClusterOptions()
  )

############################################################################
data <- read.csv("Household-heating-by-State-2008.csv", header=T) 
names(data)[4] <- "MobileHomes"
ag <- aggregate(MobileHomes ~ States, FUN = mean, data = data)
ag$States <- tolower(ag$States)

library(maps)
mapStates <- map("state", fill = TRUE, plot = FALSE)
# find the related rate for each state
rates <- ag$MobileHomes[match(mapStates$names, ag$States)] 


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


# split the string with : as seperator
spliteNames <- strsplit(mapStates$names, ":") 
# get first part of the origin string;
# e.g. get washington from washington:san juan island
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


##############################################################################
library(leaflet)
m <- leaflet() %>% addTiles()
m


 

