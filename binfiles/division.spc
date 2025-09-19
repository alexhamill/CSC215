00
3a	#loads dividen to acumulator
30
00
47	#move dividen in to b register
3a	#divisor to A
31
00
4f	#Move A into C
00
00
00
00
00
00
00
50	#remove E garbage
1e
00
7a	#moves A to D
b9	#comp dividen with divisor
da	#jump out of loop if carry flag
1e
00
91	#sub A from C
57	#move A to D
1c	#incriment register E
c3	#jumps back to begining of loop
13
00
c3	#jumps to re storing numbers
21
00
7b	#move E to A
32	#stores quotient in 31
32
00
7a	#moves D to A
32	#stores the remainder in 33
33
00
00	#padding
76	#stops program
===
30:25
31:05
