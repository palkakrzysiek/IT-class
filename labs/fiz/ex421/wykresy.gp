set terminal postscript eps 22        # old epsf2
unset key
set output "ip.eps"
set title "Measured current of polarization P versus angle of incident." 
set xlabel "Angle [degrees]" 
set ylabel "Current [mA]" 
plot [0:][0:] 'data.tab' using 1:2 w points pt 1 ps 2 lc 7, 'data.tab' using 1:2:(1):5 w boxxyerrorbars lc 7
set title "Measured current of polarization S versus angle of incident." 
set xlabel "Angle [degrees]" 
set ylabel "Current [mA]" 
set output "is.eps"
plot [0:][0:] 'data.tab' using 1:3 w points pt 1 ps 2 lc 7, 'data.tab' using 1:3:(1):6 w boxxyerrorbars lc 7
set title "Calculated level of polarization versus angle of incident." 
set xlabel "Angle [degrees]" 
set ylabel "Level of polarization"  
set label "MAX LEVEL" at 56,0.99 point ps 3.5 lc 1 pt 13
set output "pollev.eps"
plot [0:][0:1] 'data.tab' using 1:4 w points pt 1 ps 2 lc 7, 'data.tab' using 1:4:(1):7 w boxxyerrorbars lc 7
