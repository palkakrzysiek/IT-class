set terminal postscript eps enhanced 22        # old epsf2
set key left top 
set format x "%.1f"
set output "r-ang1.eps"
set title "Radius of first circle depending on wavelength." 
set xlabel "Wavelength [10^{-21} m]" font "Helvetica,24"
set ylabel "Radius [10^{-3} m]" 
f(x) = m*x + b
fit f(x) 'data.tab' using 6:2 via m,b
plot 'data.tab' using 6:2 w points pt 1 ps 2 lc 7 title 'measured points', f(x) title 'linear approximation'
set output "r-ang2.eps"
set xlabel "Wavelength [10^{-21} m]" font "Helvetica,24"
set title "Radius of second circle depending on wavelength." 
set ylabel "Radius [10^{-3} m]" 
fit f(x) 'data.tab' using 6:4 via m,b
plot 'data.tab' using 6:4 w points pt 1 ps 2 lc 7 title 'measured points', f(x) title 'linear approximation'
