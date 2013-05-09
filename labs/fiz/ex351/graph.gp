set terminal postscript eps enhanced 22        # old epsf2
set output "graph.eps"
set title "accelerating anode voltage {/Oblique U} vs squared magnitude of magnetic\ninduction {/Oblique B}^2" 
set xlabel "squared magnitude of magnetic induction {/Oblique B}^2 [10^{-7} {T}^2]" 
set ylabel "accelerating anode voltage {/Oblique U} [V]" 
set format x "%.1f"
f(x) = m*x + b
fit f(x) 'data.tab' using 7:2 via m,b
plot 'data.tab' using 7:2 w points pt 1 ps 2 lc 7 title 'measured points', f(x) title 'linear approximation'

