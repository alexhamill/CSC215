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

### Twos complement

a - sign is not stored with a negative number instead they use a signed number with the twos complement.
basically it's just a binary number with the digit of most magnitude as 1 and all the bits are flipped then one is added.

FC = 11111100 $ \rightarrow $ 00000011 + 1 = 00000100 or -4

-4 = 00000100 $ \rightarrow $ 11111011 + 1 = 11111100 or FC

Two's complement is not only how the number is stored though it is also how the machine acutaly does the subtraction

say we want to do 3 - 2 = 1 the computer actually does 3 + (-2) = 1

the machine uses the twos complement of 2 to complete this (twos complement of 2 is 11111110)

00000011 + 11111110 if you follow that through all numbers rollover just leaving 00000001 or 1

the key to this method is that the numbers that exceed the 2 byte of storage are just lost.


### Extra

The commands take 2 bytes as an input, low then high bytes, because an address needs to be 2 bytes of data because they are too long to just fit in 1 byte. It starts with a low byte then the high byte so it would be writing 3456 as 56 34.

Also I made a [.bin file](https://github.com/alexhamill/CSC215/blob/main/binfiles/subtract-V1.bin?raw=true) so you can easly inport it using a [hex editor](https://hexed.it/)
