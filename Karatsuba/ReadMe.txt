Problem  : Multiply two integers using Karatsuba algorithm
Writer   : Sameer Kolte
===================================================================================================
Algorithm description:
This algorithm multiplies two integer values using recursive karatsuba multiplication.
Suppose we want to multiply x and y.
Then we can represent x and y as follows-
x = 10^(n/2)a +b;
y = 10^(n/2)c +d;
where n is the length of integers. 

The multiplication can be represented as-
P1 = a.c
P2 = b.d
P3 = (a+b).(c+d) - P1 - P2
x.y = (10^n)P1 + (10^(n/2))P3 + P2
===================================================================================================


