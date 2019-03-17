library(ggmap) 
library(ggplot2) 
library(maps) 
library(mapproj)
# or you can try e.g. require(maps) 
# map("usa") 
map('state') # ninst  ot necessary, just checking we can draw a map

data <- read.csv("Household-heating-by-State-2008.csv", header=T) 
head(data) 
names(data) 

names(data)[4] <- "MobileHomes"
names(data)

ag <- aggregate(MobileHomes ~ States, FUN = mean, data = data)


head(ag) 
dim(ag)

m.usa <- map_data("state") # we want the states 
head(m.usa) 
dim(m.usa) # more info than we need


df <- data.frame(region = tolower(ag$States), MobileHomes = ag$MobileHomes, stringsAsFactors = F) 
dim(df)

ggplot(df, aes(map_id = region)) +                  # Create a empty canvas
  expand_limits(x = m.usa$long, y = m.usa$lat) +    # draw the grid
  geom_map(aes(fill = MobileHomes), map = m.usa) +  # draw a us map, fill = MobileHomes means color the map according to MobileHomes property
  coord_map()                                       # fix the ratio of the x and y axises, to match a map
