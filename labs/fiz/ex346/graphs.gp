set terminal postscript eps enhanced 22        # old epsf2
set output "epsilon.eps"
set title "Permittivity depending on temperature" 
set xlabel "Temperature {/Oblique T} [K]" 
set ylabel "Permittivity {/Symbol-Oblique e}" 
plot 'plot.tab' using 1:3 w points pt 1 ps 2 lc 7 title 'measured points', 'plot.tab' using 1:3 smooth csplines with lines title 'approximation'

set output "epsilon-1.eps"
set key left top 
set format y "%.1f"
set title "Inverse of permittivity depending on temperature" 
set xlabel "Temperature {/Oblique T} [K]" 
set ylabel "Inverse of a Permittivity {/Symbol-Oblique e}^{-1} [10^{-3}]" 
f(x) = m*x + b
fit f(x) 'plot-lin.tab' using 1:4 via m,b
plot [][0:] 'plot.tab' using 1:4 w points pt 1 ps 2 lc 7 title 'measured points', f(x) title 'linear approximation'
