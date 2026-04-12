library(here)

#Leer datos
datos <- read.table(here("Backtracking","Utils", "tiempos.txt"))
n <- datos$V1
sin_poda <- datos$V2

#Transformación logarítmica
log_t <- log(sin_poda)
#Creamos el modelo con escala logarítmica
modelo <- lm(log_t ~ n)

#Calculamos el coeficiente de determinación R^2
summary(modelo)
r2 <- summary(modelo)$r.squared

#Simular 100 valores de n entre el mínimo y el máximo para dibujar una curva más suave
n_seq <- seq(min(n), max(n), length.out = 100)

#Predicción con el modelo en base a los valores generados previamente
log_pred <- predict(modelo, newdata = data.frame(n = n_seq))

#Transformación exponencial volvemos a la escala original
t_pred <- exp(log_pred)

#Ajuste de escala (factor_ajuste) (Para que la recta pase por el último punto)
factor_ajuste <- sin_poda[length(sin_poda)] / t_pred[length(t_pred)]
t_pred <- t_pred * factor_ajuste

#Creamos la gráfica
options(scipen = 999)
par(mar=c(4,4,2,1))

#Puntos del peor caso sin poda
plot(n, sin_poda,
     pch=16,
     col=rgb(82, 138, 255, maxColorValue = 255),
     cex=1.3,
     xlab="Número de prendas (n)",
     ylab="Tiempo (s)",
     main=paste("Ajuste exponencial (R² =", round(r2,4), ")"))

#Curva ajustada
lines(n_seq, t_pred,
      col="red",
      lwd=2)

grid(lty=3, col="gray80")

legend("topleft",
       legend=c("Peor caso sin poda",expression("Ajuste "~m^n~"(m=4)")),
       col=c(rgb(82, 138, 255, maxColorValue = 255),"red"),
       pch=c(16, NA),
       lty=c(NA,1),
       bty="n")