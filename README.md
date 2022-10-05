# Push_swap
My Attempt at 42's assignment Push_swap

This Project looks at sorting a stack given as an input using only on other stacks and the command to push the top of one stack to the top of another, to roate either stack clockwise or anti-clockwise and to rotate both stacks clockwise or anti-clockwise, the goal is to organize the input stack as efficiently as possible. 

The Steps to run this program:

1. Type "Make" while in the directory.
2. type ./push_swap "Numbers to sort"

the output is set to just print the instrutions (e.g ra, pa, rra), however if you want to visualize each step simply change the name of funtion "printb" in
utils3.c to "printa" and change the name of "printa" located in utils2.c to "printb". This will print each entire array along with the step used and
current count of steps for each move. (be warned when dealing with more than 500 numbers if you pipe the output to a text file the size can become unnecesarily large). To switch back to the orginal for testing simply rename the funtions back to what they were before.
