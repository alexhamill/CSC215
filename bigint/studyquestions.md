# Answers to the study questions
## Set 1
1. Suppose you want to add unary operations (i.e., ones requiring only one operand) to the calculator. For example, we might add "M" to indicate unary minus (i.e., change the sign of the old value) and "A" to indicate absolute value. What changes would need to be made to the program?

I would add a new part to the switch statement and a if statement around the scan for the new number if statement and just say if op == to + * or - then look for the new number input. Otherwise it would just go on without a second input and be able to do the unary operator. and then obvious you would need the logic to actually preform that operation in the switch statement for it.

2. Suppose that words rather than single character symbols are to be used for the operators (e.g., the user types "times" instead of "*"). Where in the program would the necessary changes occur?

I think i would convert the input into the correct * - or + when reading in the operator I would just make some if statements and compare the input to see if it is add sub or times ect. then just change the op to the corresponding symbol and leave the switch statement code alone.

3. Suppose that the calculator is to be converted to use C++ double values rather than integers. Where would changes need to be made?

on out machine we cant use doubles.

4. Most modern systems support graphical displays and mouse (or other pointer) input. Rewrite the Calculator program to take advantage of these features to produce an on-screen push-button calculator (this is a large programming project).

we also cannot do graphical displays.

5. Show how a new command, "C", which acts like the "Clear" command on a calculator could be implemented. The clear command sets the current value to zero.

I would add another switch statement and then it would set accumulator to 0 when c was the op and I would use the same logic as before to skip the other input option.

6. (AB only) How could the calculator be modified to allow the use of parentheses to control the order of operations?


you would have to change the way that numbers are input it would have to not be number operator next number format it would more have to be a string input of a bunch of numbers and operators. then you would have to make a parser where it would look for the innermost parentheses then work backwards from there