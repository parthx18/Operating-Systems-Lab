Experiment 9: Basic Shell Commands and Scripting
#!/bin/bash
echo Enter first number
read a
echo Enter second number
read b
C=$(( $a +$b ))
echo Addition is $C
D=$(( $a - $b))
echo Subtraction is $D
E=$(( $a * $b ))
echo Multiplication is $E
F=$(( $a % $b ))
echo Remainder is $F
G=$(( $a / $b ))
echo Quotient is $G


#!/bin/bash
echo "Welcome to SIT"
echo "You are working with"
whoami
echo "on"
date

#!/bin/bash
echo "Present working directory"
pwd
echo "List of content of pwd"
ls
echo "Number of process running with current user"
ps


To run these scripts on a Linux system, follow these steps:
Create the file: nano script_name.sh
Make it executable: chmod u+x script_name.sh 
Run the script: ./script_name.sh
