# Subtraction

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


### through the process of the program


0: takes the number from the address of 10 and puts it into the accumulator

3: saves address of 11 to the HL registers

6: subtracts the value stored at HL from the accumulator and saves to the accumulator

7: sets the HL to the address 12

10: moves the accumulator value to the address HL is "pointing to"

11: Halts the program


### commands in the program

LDA: loads a value to the accumulator takes 2 bytes of as an address for the number

LXI: Saves an address of a number to HL. Like a pointer in c++.

Sub M: subtracts the value at HL from the accumulator

Move M: sets the value at HL to the accumulator

### Extra

The commands take 2 bytes as an input, low then high bytes, because an address needs to be 2 bytes of data because they are too long to just fit in 1 byte. It starts with a low byte then the high byte so it would be writing 3456 as 56 34.

