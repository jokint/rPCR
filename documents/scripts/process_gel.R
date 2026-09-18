process_gel <- function(img,marker_size,sdfac=10,quant=0.5,margin = c(10,10,10,10)){

  ## cropping image
  img <- normalize(img)
  row_prof <- rowMeans(img)
  col_prof <- colMeans(img)


  col_dif <- abs(diff(col_prof))
  threshold <- quantile(col_dif, probs = quant, na.rm = TRUE)
  col_low <- col_dif[col_dif <= threshold]
  tre <- mean(col_low)+ sdfac*sd(col_low)
  h_first <- min(which(col_dif > tre)) + margin[1]
  h_last <- max(which(col_dif > tre)) - margin[2]
  # plot(col_prof, type="l", main="gel edges")
  # abline(v = h_first, col="blue", lwd=2)
  # abline(v = h_last, col="blue", lwd=2)

  row_dif <- abs(diff(row_prof))
  threshold <- quantile(row_dif, probs = quant, na.rm = TRUE)
  row_low <- row_dif[row_dif <= threshold]
  tre <- mean(row_low)+ sdfac*sd(row_low)
  v_first <- min(which(row_dif > tre)) + margin[3]
  v_last <- max(which(row_dif > tre)) -margin[4]
  # plot(row_prof, type="l", main="gel edges")
  # abline(v = v_first, col="blue", lwd=2)
  # abline(v = v_last, col="blue", lwd=2)


  return(img[v_first:v_last,h_first:h_last])

  # # 1. Profil manuell normalisieren (0 bis 1)
  # col_prof_norm <- (col_prof - min(col_prof)) / (max(col_prof) - min(col_prof))
  #
  # # 2. Otsu auf den normalisierten Vektor anwenden (als Matrix getarnt)
  # thr_norm <- otsu(as.matrix(col_prof_norm))
  # thr_norm <- quantile(col_prof_norm,0.1)
  # # 3. Den Schwellenwert zurück auf die Original-Skala rechnen
  # thr_col <- thr_norm * (max(col_prof) - min(col_prof)) + min(col_prof)
  #
  # # 4. Kanten finden
  # first_edge <- min(which(col_prof > thr_col))
  # last_edge  <- max(which(col_prof > thr_col))
  #
  #
  #
  #
  #
  #   # 4. Zur Kontrolle ausgeben
  # cat("Das Gel beginnt bei Pixel:", first_edge, "\n")
  # cat("Das Gel endet bei Pixel:", last_edge, "\n")
  #
  # # 5. Im Plot visualisieren
  # plot(col_prof, type="l", main="Horizontale Gel-Kanten")
  # abline(v = first_edge, col="blue", lwd=2) # Linke Kante
  # abline(v = last_edge, col="blue", lwd=2)  # Rechte Kante
  #
  #














  #
  #
  #
  # max <- max(row_prof,col_prof)
  # min <- min(row_prof,col_prof)
  # img_norm <- (img-min)/(max-min)
  # row_prof <- rowMeans(img_norm)
  # col_prof <- colMeans(img_norm)
  # thr <-   quantile(img_norm, 0.1)
  # thr <-   otsu(img_norm)
  # y_indices <- which(row_prof > thr)
  # x_indices <- which(col_prof > thr)
  # y_min <- min(y_indices); y_max <- max(y_indices)
  # x_min <- min(x_indices); x_max <- max(x_indices)
  #
  # buffer <- 0
  # img_cropped <- img_norm[(x_min+buffer):(x_max-buffer), (y_min+buffer):(y_max-buffer)]
  #
  # display(img_cropped)
  #
  #


}


detect_rows <- function(img) {
  # Optimalen Schwellenwert für das Profil finden
  y_profile <- rowMeans(img)
  thr <- otsu(as.matrix(y_profile))

  # Alle Indizes finden, die über dem Schwellenwert liegen
  active_y <- which(y_profile > thr)

  # Sprünge in den Indizes finden (da, wo eine Reihe aufhört und die nächste beginnt)
  diffs <- diff(active_y)
  breaks <- which(diffs > 5) # 5 Pixel Lücke als Trennung definieren

  # Start- und Endpunkte der Reihen extrahieren
  starts <- c(active_y[1], active_y[breaks + 1])
  ends <- c(active_y[breaks], active_y[length(active_y)])

  # Ergebnisse im Plot anzeigen
  abline(v = starts, col="green", lty=2) # Reihen-Anfang
  abline(v = ends, col="red", lty=2)    # Reihen-Ende



  # Profil-Datenrahmen erstellen
  df_prof <- data.frame(y = 1:length(y_profile), intensity = y_profile)

  ggplot(df_prof, aes(x = y, y = intensity)) +
    geom_line() +
    # Die rote Threshold-Linie einzeichnen
    geom_hline(yintercept = thr, color = "red", linetype = "dashed", linewidth = 1) +
    annotate("text", x = 10, y = thr + 0.02, label = "Threshold", color = "red") +
    theme_minimal() +
    labs(title = "Profil mit aktivem Schwellenwert", x = "Pixel Position", y = "Intensität")



}
