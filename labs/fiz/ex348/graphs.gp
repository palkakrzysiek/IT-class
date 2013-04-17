set terminal postscript eps enhanced 22

set output "U_H-vs-B.eps"
set title "Hall voltage depending on strength of magnetic field"
set xlabel "Magnetic field [mT]"
set ylabel "Hall voltage [mV]"
f(x) = a*x + b
fit f(x) 'U_H-vs-B.csv' using 1:2 via a,b
plot [-410:410] 'U_H-vs-B.csv' using 1:2 w points pt 1 ps 2 lc 7 title 'measured points', f(x) title 'linear approximation'

set output "U_H-vs-I_P.eps"
set title "Hall voltage depending on current through sample field"
set xlabel "Current through sample [mA]"
set ylabel "Hall voltage [mV]"
f(x) = a*x + b
fit f(x) 'U_H-vs-I_P.csv' using 1:2 via a,b
plot [-60:62] 'U_H-vs-I_P.csv' using 1:2 w points pt 1 ps 2 lc 7 title 'measured points', f(x) title 'linear approximation'
