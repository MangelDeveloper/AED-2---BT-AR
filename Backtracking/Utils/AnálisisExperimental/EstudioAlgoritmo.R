datos <- read.table("tiempos.txt")

n <- datos$V1
sin_poda <- datos$V2
con_poda <- datos$V3

options(scipen = 999)
par(mar=c(4,4,2,1))

plot(n, sin_poda,
     type="p",
     pch=16,
     col=rgb(82, 138, 255, maxColorValue = 255),
     cex=1.3,
     xlab="Número de prendas (n)",
     ylab="Tiempo (s)",
     main="Peor caso (Con poda y Sin poda)")

# Puntos sin poda
points(n, con_poda,
       pch=4,
       col="orange",
       lwd=2.5)

grid(lty=3, col="gray80")

legend("topleft",
       legend=c("Sin poda","Con poda"),
       col=c(rgb(82, 138, 255, maxColorValue = 255),"orange"),
       pch=c(16,4),
       pt.lwd=2.5,
       bty="n")