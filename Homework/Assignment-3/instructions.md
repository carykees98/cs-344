# Homework 3 - Instructions

1. ### Create three functions to calculate a^n, where n is a non-negative integer, according to the following definitions (the first is iterative, and the other two are recursive):

	- x<sup>n</sup> = a * a * a * ... * a

	- x<sup>0</sup> = 1; otherwise x<sup>n</sup> = x * x<sup>n-1</sup>

	- x<sup>0</sup> = 1; otherwise x<sup>n</sup> = x * x<sup>n/2</sup> * x<sup>n/2</sup> if n is odd; x<sup>n</sup> = x<sup>n/2</sup> * x<sup>n/2</sup> if n is even.

2. ### Solve the max sum problem. In this problem, you are given an array of integers, and you want to calculate 4 different things:

	1. The sum of the entire array, with associated lo and hi index (called entire in my code).

	2. The prefix with the best sum, and its lo and hi index (called begin in my code).

	3. The suffix with the best sum, and its lo and hi index (called end in my code).

	4. The contiguous subarray with the best sum and its lo and hi index (called best).

---
## __You must solve this problem using 2 methods__

1.  The brute force iterative method that calculates all sums. __I have already done this.__

2.  The recursive divide and conquer method that breaks the array in half, and uses the solutions for the 2 halves to get a solution for the entire array. Your function should only use a constant amount of time in addition to the recursive calls. There is no need for any loop or to use my sum_array function. But you should make heavy use of my maxsol and concat functions, using the algorithm I suggested in pictures at the end of class today.

There are 3 functions in the first part, and 2 functions in the second part (although one is already done). For each function, you need to turn in a copy of your function, a recurrence equation describing the running time (if the function is recursive), and the running time of the function.

There are three files associated with each problem. You only have update the body of maxsum_fast in maxsum.cpp, and the body of power_iter, power_recur and power_half in power.cpp