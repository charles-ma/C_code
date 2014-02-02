a) how to attack the system
The name array in the source code is of fixed length of 128 bytes, and we can use buffer overflow to stuff in more than 
128 bytes of data into it. After checking out the stack layout of the program on speclab, I found that the variable evil
which represents the address of the evil String can be overwritten to point to the address of the good String(the address)
is 0x4008ac. If we stuff a String combined from arbitray 128 characters(except '\0') and hex String "\xac\x08\x40", we can
overwrite the variable evil to point to the good String so that no matter whether the login and pw are the same, the 
output String will be "Welcome to the machine!".

b) what the source and input file does
There are no source files. The input file demostrates an example input which will carry on the attack on the target. The 
input file provides inputs for login and pw and they are different, but the output of the program will be "Welcome to the
machine".
