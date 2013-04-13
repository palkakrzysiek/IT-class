set terminal postscript eps enhanced 22        # old epsf2
set output "plot.eps"
set title "Intensity of light depending on angle."
set xlabel "Angle [mrad]"
set ylabel "Current [mA]"
plot [-23:20.5] 'data.tab' using 3:2 w points pt 1 ps 2 lc 7 title 'measured points', 'data.tab' using 3:2 smooth csplines with lines title 'approximation'

