# Divison

## program
| address | command | Hex |comment|
-----|--------|-------|---
1|LDA|3a| loads the dividen into the acumultor
2|LB|30|
3|HB|00|
4|MOV|47| move dividen into B register
5|LDA|3a| loads the divisor into acumulator
6|LB|31|
7|HB|00|
8|MOV|4f| moves acumulator into C register

| address | command | Hex | comment|
-----|--------|-------|----
10|MVI|50| removes garbage in register E
11|LB|1e| 
12|HB|00|
13|MOV|7a| moves acumulator to D
14|CMP|b9| compairs dividen with divisor and turns on cary flag if divisor bigger
15|JC|da| jumps out of loop if cary flag on
16|LB|1e|
17|HB|00|
18|SUB|91| subtracts A from C
19|MOV|57| moves A to D
1a|INR|1c| incriments register E for each subtraction from quotient
1b|JMP|c3| jumps back to adress 13 to restart the loop
1c|LB|13|
1d|HB|00|
1e|JMP|c3|  jumps to the re storing of the numbers
1f|LB|21|
20|HB|00|

| address | command | Hex |comment|
-----|--------|-------|---
21|MOV|7b| moves E(quotient) to A
22|STA|32|  stores the quotient in 32
23|LB|32| 
24|HB|00|
25|MOV|7a| moves D(remainder) to A
26|STA|32| stores the remainder in 33 
27|LB|33|
28|HB|00|
29|NOP|00| padding
2a|HALT|76| stops program


## commands

MVI - Move immediate just puts the number directly into the register. This is just to remove the garbage so its not embedding the numbers into the code.

CMP - Compares the values and sets the carry flag if A is less than the register you are comparing it to. This actually works by just subtracting and turning on the carry flag.

JC - This command is like the jump command but only jumps if the cary flag is turned on. in this case it will only jump if the dividend is less than the divisor.

INR - adds one to a register.

JMP - just always jumps.

## The process

The code moves the dividend to a register then subtracts the divisor from the dividend incrementing the quotient and checking to make sure the dividend is still larger than the divisor. Once it isn't what was the dividend is now the remainder and the number that was being incremented is the quotient. then it stores them back into the ram.

## base of commands

The commands with registers have them built in sometimes they have the base + the register * 2^shift as the code

so for INR register E it would be $ 4 + 3  \cdot  2^3 $  so 1C

|Comand|Base|Shift
---|----|--
INR|04|3
MVI|06|3
CPM|B8|0

Register|code
----|----
B|0
C|1
D|2
E|3
H|4
L|5
M(HL)|6
A|7


[bin file](https://github.com/alexhamill/CSC215/blob/main/binfiles/division.bin)