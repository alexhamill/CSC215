

## Subtraction




| address | command | Hex |
-----|--------|-------
|0|LDA|3a|
|1|low byte|10|
|2|high byte|0|
|3|LXI|21|
|4|low byte|11|
|5|High byte|0|
|6|Sub M|96|
|7|LXI|21|
|8|low byte|12|
|9|High byte|0|
|10|Move M|77|
|11|Halt|76|


0: takes the number from the address of 10 and puts it into the accumulator


3: saves  address of 11 to the H and L registers


6: subtracts the H and L from the accumulator and saves to the accumulator


7: sets the H and L to the address 12


10: moves the accumulator value to H and L


11: Halts the program



