# Answers to the study questions
## Set 1
1. Suppose you want to add unary operations (i.e., ones requiring only one operand) to the calculator. For example, we might add "M" to indicate unary minus (i.e., change the sign of the old value) and "A" to indicate absolute value. What changes would need to be made to the program?

I would add a new part to the switch statment and a if statment around the scan for the new number if statment and just say if op == to + * or - then look for the new number input. Otherwise it would just go on without a second input and be able to do the unary operator. and then obviiuols you would need the logic to actualy preform that operation in the switch statment for it.

2. Suppose that words rather than single character symbols are to be used for the operators (e.g., the user types "times" instead of "*"). Where in the program would the necessary changes occur?



3. Suppose that the calculator is to be converted to use C++ double values rather than integers. Where would changes need to be made?
4. Most modern systems support graphical displays and mouse (or other pointer) input. Rewrite the Calculator program to take advantage of these features to produce an on-screen push-button calculator (this is a large programming project).
5. Show how a new command, "C", which acts like the "Clear" command on a calculator could be implemented. The clear command sets the current value to zero.
6. (AB only) How could the calculator be modified to allow the use of parentheses to control the order of operations?