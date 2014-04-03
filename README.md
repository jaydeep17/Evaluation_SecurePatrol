Evaluation_SecurePatrol
=======================

This repo contains the souce code used while evaluationg a proposed defense mechanism called Secure Patrol.

This code is a simulator for Secure Patrol.


Description:
------------
`test.c` contains the code to be tested on gcc's default stack protection.

`securePatrol.c` contains the code that simulates the proposed defense mechanism.

`stackLib.c` contains an implementation of stack.


How to test:
------------

1) &nbsp;compile `test.c` with gcc stack protector turned on

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`gcc -O2 -fstack-protector-all test.c -ogccProtector`
  
2) &nbsp;compile `securePatrol.c` with gcc stack protector turned off

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`gcc -fno-stack-protector -O2 securePatrol.c -osecurePatrol`
  
3) &nbsp;`time` program is used to compute the time taken to execute each executable

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`time ./gccProtector someText 1000`
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`time ./securePatrol someText 1000`
