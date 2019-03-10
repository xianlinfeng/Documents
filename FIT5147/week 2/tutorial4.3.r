library(ggplot2)

dat <- read.csv("EconomistData.csv")

head(dat)

ggplot(dat, aes(x = CPI, y = HDI)) + geom_point()


plot1 <- ggplot(dat, aes(x = CPI, y = HDI, color = Region)) 
plot1 <- plot1 + geom_point(shape = 1) 
plot1

labels <- c("Congo", "Sudan", "Afghanistan", "Greece", "China",
            "India", "Rwanda", "Spain", "France", 
            "United States", "Japan", "Norway", "Singapore")

plot2 <- plot1 +
  geom_text(aes(label = Country),
  color = "black", size = 3, hjust = 1.1,
  data = dat[dat$Country %in% labels, ])
plot2

plot3 <- plot2 +
  geom_smooth(aes(group = 1),
  method = "lm",
  color = "black",
  formula = y~ poly(x, 2),
  se = FALSE)
plot3

plot4 <- plot3 + theme_bw() +
  scale_x_continuous("Corruption Perceptions Index, 2011\n(10 = least corrupt)") +
  scale_y_continuous("Human Development Index, 2011\n(1 = best)") +
  theme(legend.position = "top", legend.direction = "horizontal")
plot4

