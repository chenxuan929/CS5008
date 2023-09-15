# Homework 03 - Stacks and Queues -

Name: Chenxuan Xu

Github Account name: chenxuan

How many hours did it take you to complete this assignment (estimate)? 4 hours

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
No
- one per row, add more if needed


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
https://www.geeksforgeeks.org/difference-between-stack-and-queue-data-structures/
https://www.programiz.com/c-programming/c-dynamic-memory-allocation
https://www.digitalocean.com/community/tutorials/queue-in-c
- one row per resource


(Optional) What was your favorite part of the assignment? 


(Optional) How would you improve the assignment? 

## Further Thinking Questions

1. Circular queues are used quite a bit in operating systems and high performance systems, especially when performance matters. Do a little outside research, and answer this question specifically: Why is a ring buffer useful and/or when should it be used?
Ring buffer is useful because it is very efficient and simplicity. First, it's achieveing by FIFO, and it can be pre-allocated upfront and allow an efficient memory access pattern. it is constant time O(1), and doesn't require a shifting of elements.
It can be used to: be sized to max expexted incoming data streams and won't lost data; inter-process communication; real-time data processing system; logging large amounts of data.

2. We are going to talk about stacks quite a lot in this course, so it will be important to understand them. Do a little outside research, and edit this section of the readme answering specifically: Why is a stack useful and/or when should it be used?
It is useful because it's LIFO principle, it can be used to manage complex algorithms and function calls.
it can be used for processing nested structures or for functions which call other functions, evaluating consisting of operands andoperators, store information about previous operations in program, recursion, and backtracking.


For each of these questions, we are expecting your answer to be in the range of 2-3 paragraphs (can include complexity, example usage, pros/cons, etc). Make sure to cite your sources. It is recommended you use [IEEE citation style](https://owl.purdue.edu/owl/research_and_citation/ieee_style/ieee_overview.htm) as it is most common for CS papers and research. 

https://medium.com/javarevisited/when-to-use-stack-data-structure-9ac3dfa4d10
https://byjus.com/gate/stack-and-its-applications/
https://stackoverflow.com/questions/2553637/what-are-the-uses-of-circular-buffer
https://byjus.com/gate/stack-and-its-applications
/https://www.cse.unr.edu/~sushil/class/cs202/notes/stacks/stacks.html
## Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

