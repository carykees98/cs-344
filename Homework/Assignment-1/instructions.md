# Homework 1 - Instructions

Your program must read a file called personin.txt. Each line of the file will be a person's name, the time they arrived at the professor's office, and the amount of time they want to meet with the professor. These entries will be sorted by the time the person arrived. 

Your program must then print out a schedule for the day, printing each person's arrival, and printing when each person goes in to meet with the professor. You need to print the events in order of the time they happen. In other words, your output will be sorted by the arrival times and the times the person goes into the professor's office.

Actually, in your output you need to print out two schedules: a fair schedule and an unfair schedule. In the fair schedule , new students go to the end of the line. In the unfair schedule, new students go the beginning of the line. Whenever the professor is free, the professor will either meet with the first person in line, or meet with the first person in line if nobody is waiting. Assume no two people arrive at the same time.

You should solve this problem using a stack and a queue. You can include the implementation I will give in class for C++, the implementation on the course webpage for Java, or the libraries in C++ or Java. But you can only use the operations I gave in class: push, pop and isEmpty for Stack, or enqueue, dequeue and isEmpty for Queue, or their equivalents.