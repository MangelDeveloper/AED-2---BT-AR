library(here)

n_fija <- read.csv("./tiemposN.txt", header = TRUE)
m_fija <- read.csv("./tiemposM.txt", header = TRUE)


medianas_nFija <- c(
  median(n_fija$i0),
  median(n_fija$i1),
  median(n_fija$i2),
  median(n_fija$i3),
  median(n_fija$i4),
  median(n_fija$i5),
  median(n_fija$i6)
)

medianas_mFija <- c(
  median(m_fija$i0),
  median(m_fija$i1),
  median(m_fija$i2),
  median(m_fija$i3),
  median(m_fija$i4),
  median(m_fija$i5),
  median(m_fija$i6)
)

m_vector <- 20 * 2^(0:6)
n_vector <- (20+130) * 2^(0:6)

# --- Gráfica Fijo n
plot(m_vector, medianas_nFija,
     main = "Crecimiento D(2560,m)",
     xlab = "Tamaño de entrada m",
     ylab = "Mediana del Tiempo (ms)",
     pch = 19,
     col = "blue")

legend("topleft",
       legend = c("Tiempos"),
       col = c("blue"),
       pch = 19)

# --- Gráfica Fijo m
plot(n_vector, medianas_mFija,
     main = "Crecimiento D(n,130)",
     xlab = "Tamaño de entrada n",
     ylab = "Mediana del Tiempo (ms)",
     pch = 19,
     col = "blue")

legend("topleft",
       legend = c("Tiempos"),
       col = c("blue"),
       pch = 19)



# Regresión
modelo_nFija <- lm(medianas_nFija ~ m_vector) #O(n)
modelo_mFija <- lm(medianas_mFija ~ I(n_vector*n_vector)) #O(n^2) <- Orden real del algoritmo
       
r_cuadrado_nFija = summary(modelo_nFija)$r.squared #O(n)
r_cuadrado_mFija = summary(modelo_mFija)$r.squared #O(n^2)            

c('n fija O(n)'=r_cuadrado_nFija,'m fija O(n^2)'=r_cuadrado_mFija)

# --- Nube de puntos recta de regresión  n fija ---
plot(m_vector, medianas_nFija,
     main = "Crecimiento D(2560,m)",
     xlab = "Tamaño de entrada m",
     ylab = "Mediana del Tiempo (ms)",
     pch = 19,
     col = "blue")

legend("topleft",
       legend = c("D(2560,m)", expression(paste("Ajuste ", Theta(n)))),
       col = c("blue", "red"),   # colores
       pch = c(19, NA),             # primer punto, segundo nada
       lty = c(NA, 1),              # primer sin línea, segundo línea sólida
       lwd = c(NA, 2))              # grosor de la línea

lines(m_vector, predict(modelo_nFija), col="red", lwd=2)


# --- Nube de puntos recta de regresión m fija---
plot(n_vector, medianas_mFija,
     main = "Crecimiento D(n,130)",
     xlab = "Tamaño de entrada n",
     ylab = "Mediana del Tiempo (ms)",
     pch = 19,
     col = "blue")

legend("topleft",
       legend = c("D(n,130)", expression(paste("Ajuste ", Theta(n^2)))),
       col = c("blue", "red"),   # colores
       pch = c(19, NA),             # primer punto, segundo nada
       lty = c(NA, 1),              # primer sin línea, segundo línea sólida
       lwd = c(NA, 2))              # grosor de la línea

lines(n_vector, predict(modelo_mFija), col="red", lwd=2)


r_cuadrado_nFija

r_cuadrado_mFija