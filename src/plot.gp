set term pdf
set output "plot.pdf"

set xlabel "Prob. per Cell [p]"
set ylabel "Prob. Percolate [P(p, L)]"
#set logscale x 2
#set autoscale
set xrange [0 : 1]
set yrange [0 : 1]
set grid



set title "Probability for percolating vs probability for each cell"

plot "32.dat" u 1:2 w lines lc "red" lw 1 title "L = 32" ,\
    "64.dat" u 1:2 w lines lc "green" lw 1 title "L = 64", \
    "128.dat" u 1:2 w lines lc "blue" lw 1 title "L = 128", \
    "256.dat" u 1:2 w lines lc "cyan" lw 1 title "L = 256", \
    "512.dat" u 1:2 w lines lc "orange" lw 1 title "L = 512"
