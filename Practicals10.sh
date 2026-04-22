Experiment 10: Shell Script for If-Else Statements
The Script (conditional.sh)
This script demonstrates how to handle numerical comparisons (even/odd) and check file properties.


#!/bin/bash
echo enter any number:
read num
if [ $num -eq 40 ]
then
echo PASS
fi

#!/bin/bash
echo Enter any number;
read num
r=$(( $num % 2 ))
if [ $r -eq 0 ]
then
echo Number is even
else
echo Number is odd
fi

#!/bin/bash
echo Enter OS marks:
read os
echo Enter EM 2 marks:
read em2
echo Enter DS marks:
read ds

# Calculate total and percentage [cite: 3, 7]
total=$(( $os + $em2 + $ds ))
echo Total marks $total
percentage=$(( $total / 3 ))
echo Percentage is $percentage
# Determine passing class [cite: 4, 7]
if [ $percentage -ge 75 ]
then
echo PASS with DISTINCTION
elif [ $percentage -ge 60 -a $percentage -le 74 ]
then
echo PASS with FIRST CLASS
elif [ $percentage -ge 45 -a $percentage -le 59 ]
then
echo PASS
else
echo FAIL
fi

How to Run:
Save the code as exp10.sh.
Open the terminal and run: chmod +x exp10.sh
Execute it using: ./exp10.sh
