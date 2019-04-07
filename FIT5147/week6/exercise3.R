# 3.A
library(igraph)
g <- graph.formula(1-2, 1-3, 2-3, 2-4)
plot(g)
V(g) # get the Vertices of g 
E(g) # get the edges of g
diameter(g) # get the diameter of g. diameter = maximum eccentricity of any vertex in the graph.
get.adjacency(g) # a matrix view

V(g)$name <- c("Adam", "Bob", "Con", "Doug")  # asign name for each node
# and replot using $name
plot(g, vertex.label = V(g)$name) # add labels
get.adjacency(g) # have a look at the new matrix

dg <- graph.formula(1-+2, 1-+3, 2-+3, 2-+4) # directed network
plot(dg)

V(dg)$name <- c("Adam", "Bob", "Con", "Doug") # names! 
plot(dg, vertex.label = V(dg)$name)

is.weighted(dg)  # check if the network is weighted or not
# False



