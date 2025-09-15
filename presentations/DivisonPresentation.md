# Divison

## program

| address | command | Hex |
-----|--------|-------
10|MVI|50
11|LB|1e
12|HB|00
13|MOV|7a
14|CMP|b9
15|JC|da
16|LB|1e
17|HB|00
18|SUB|91
19|MOV|57
1a|INR|1c
1b|JMP|c3
1c|LB|13
1d|HB|00
1e|JMP|c3
1f|LB|21
20|HB|00

## comands

MVI - Move immidate just puts the number directly into the register. This is just to remove the garbage so its not embeding the numbers into the code.

CMP - Compares the values and sets the carry flag if A is less than the register you are comparing it to. This actualy works by just subtracting and turning on the cary flag.

JC - This command is like the jump comand but only jumps if the cary flag is turned on. in this case it will only jump if the divdend is less than the divisor.

INR - adds one to a register.

JMP - just always jumps.

## The process

The code moves the the dividen to a register then subtracts the divisor from the dividen incrimenting the quotient and checking to make sure the dididen is still larger than the divisor. Once it isnt what was the dividen is now the remainder and the number that was being incrimented is the quotient. then it stores them back into the ram.

## base of commands

The comands with registers have them build in somtimes they have the base + the register * 2^shift

so for INR register E it would be $ 4 + 3*2^3 $  so 1C

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

