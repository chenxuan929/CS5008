# Midterm p1: Report on Analysis of Fibonacci  Series
* **Author**: Chenxaun Xu 
* **GitHub**: git@github.com:Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-chenxuan929.git
* **Semester** Spring 2023
* **Languages Used**: c, python

## Overview
This report focus on the speed differences between implementation of [Fibonacci Series]. Fibonacci is a sequence of numbers starting with 0 and 1, where each number is the sum of the previous two numbers. The first few values in the sequence are：0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144... It can be presented mathematically as: 
$$F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for  n > 1$$

In this report, python and C language is mainly used to implement Fibonacci Series through iteration, recursion, and dynamic programming. The table below represents the big O values and the detail of each will be discuss later.
| Version |  Big O | Space Used | 
| :-- | :-- |  :-- |
| Iterative | $O(n)$ | $O(1)$ |
| Recursive | $O(2^n)$  | $O(n)$ |
| Dynamic Programming | $O(n)$ | $O(n)$ |

* Iterative
The iterative approach in simple terms is by using loops to find the nth Fibonacci number by initializing the first and second number, then looping from index 2 to n+1 where each term is the sum of previous 2 terms. It is also the easiest way to understand the mathematical formula of Fibonacci number in my opinion.The algorithm loops through every number from 1 to n inclusive, so, the time complexity of this algorithm is O(n). Since, the algorithm uses the constant space, the space complexity of the algorithm is O(1).
The iterative version is in pseudocode:
```
if n == 0:
    return 0
if n == 1:
    reutn 1
first = 0
second = 1
for 2...n:
    next_num = first + second
    first = second
    second = next_num
return second
```

* Recursive
The recursive approach is to find the nth Fibonacci number by using the recursive formula for Fibonacci sequence, $Fn = Fn-1 + Fn-2$. After checking and eliminating the base case where n is equal to 1 or 2, use recursive to return sum of previous two terms by calling the function two times one with an argument $n-1$ and other with $n-2$. So, the time complexity of this function is $O(2n)$.
The recursive version is in pseudocode:
```
function fib_recursive(n)
if n == 0 or n == 1:
    return n
return fib_recursive(n-1) + fib_recursive(n-2)
```

* Dynamic Programming
This approach is achieve Fibonacci number by using [dynamic programming]. Besides the same base case when N is 1 and 2, it will store the answer in an array. When n is repeating, we don't need to calculate again, just get the answer by index from the array. Otherwise calculate the value for nth key using $(n-1) and $(n-2)$. This algorithm reduces many steps and runs in a linear time complexity, O(n), much better compared to the recursive method.
The dynamic programming version is in pseudocode:
```
fib_lst = [-1] * (n + 1)
fib_lst[0] = 0
fib_lst[1] = 1
for i in 2...n+1:
    fib_lst = fib_lst[i-1] + fib_lst[i-2]
return fib_lst
```

The reason I chose python as my second language is that my analysis report focuses on speed. The contrast between python and C is relatively strong, especially easy to observe and analyze in the chart. And python as my introductory programming language, I am very willing to practice it again.

## Empirical Data & Discussion 
For all empirical results, the max time interval is set to 60 seconds. I considered if I need a very large data N to observe changes in the data more clearly. For the recursive approach, it's important to consider the size of N since O(2^N) time complexity. It can be doubted that a very large N can lead to a significan increase in computation time and may cause issues. However, for the iterative and dynamic programming approach it is not necessary since they both have a linear time complexity of O(N). Considering the time cost and the main purpose of our study, I choose to use a moderate N to complete the analysis. I chose 50, 1000, and 10000 as the N value to draw different comparison charts.

### Resursive Versions
![Recursive P]
Recursive P graph is not absolutely stable, but it has been floating within a very constant and small range. As a contract to recursive, I also choose a data range of N equal to 48 to show.
![Recursive C]
Recursive C graph stops abruptly at N equal to 48 after a plateau and then a relatively quick and smooth rise.

### Iterative and Dynamic Programming Versions
![IandDP_P]
I use a relatively larger N value which is 1000 to try to show data changes, but it seems that it is not large enough for dynamic programming. It can be seen in the image that the red dp-line still tends to float stably in a small range. For blue iterative-line, the time increased significantly between N is 700 and 800 and the time finally increased from 0.03 to 0.07.
![IandDP_C]
The time of dynamic programming increases in a step shape with the increase of N, and the stabilization time of each time is also increasing. Nevertheless, in the range of N equal to 1000, time still increased from 0.02 to 0.07. However, the iterative line remained stable. It can be concluded here that iteration is a more efficient method, recursion is a relatively less efficient method, and dynamic programming is in the middle of these two.

### Big Number C Comparation Versions
![bignum]
I use a larger N which is equal to 10000 to compare the efficiency of dynamic programming and iterative from a wider range. Taking steps in 500. It is not difficult to see that with the increase of N, the iterative curve is more stable, never exceeding the range of 0 to 0.1. However, with the increase of N, the curve of dynamic programming has been rising significantly until over 0.7, and even when N=10000, there is no tendency to stabilize.

## Language Analysis
Coding attached in the following files:
* [fib.c] -- implementation of functions in c
* [fib.py]  -- implementation of function in python
* [test_runner.py] -- run script to help with tests and keep timings

I started the python part first, because I think that for simple programs, python is easier to write and think quickly. It's more like a mind map for me.

### Language 1: C
The program supports three different methods to get fibonacci numbers; iterative, recursive, and dynamic programming.
Iteration and recursion are implemented using direct computation:
```
ull fib_iterative(int n) {
    uint64_t fibTotal = 0, fib1 = 0, fib2 = 1;
    for (int i = 0; i < n; i++) {
        fibTotal = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibTotal;
    }
    return fib1;
}

ull fib_recursive(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fib_recursive(n-1) + fib_recursive(n-2);
    }
}
```
Dynamic programming uses arrays to store precomputed numbers, and then quickly look them up at runtime:
```
ull fib_dynamic(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    fib_lst[0] = 0;
    fib_lst[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib_lst[i] = fib_lst[i - 1] + fib_table[i - 2];
    }
    ull answer = fib_lst[n];
    return answer;
}
```
When using print, 0 does not print any output, only for speed comparison. When 1, print the Nth fibonacci number. When 2, print the first N fibonacci sequence. Also, the implementation is not optimized for memory usage, as it allocates and frees memory for the fibArr array for each call to the print_fib_series function.

### Language 2: Python
The Python code also calculates and prints the first n Fibonacci numbers using different methods, including iteration, recursion, and dynamic programming with memoization. By defining an enumeration type FibType, it represents different methods of calculating the Fibonacci sequence. This keeps code tightly organized and makes it easier to switch between different methods. 
```
class FibType(Enum):
    DP = 2
    RECURSIVE = 1
    ITERATIVE = 0
```
In the fib_dp function I use dynamic programming with memory to calculate the nth fibonacci number. Avoid redundant calculations by storing intermediate results in the cache. Makes computing Fibonacci numbers efficient, even for large values of n. The @lru_cache decorator is used to memoize the function, which automatically stores the results of the function calls in a cache.
```
@lru_cache(maxsize=None)
def fib_dp(n: int) -> list[int]:
    fib_lst = [-1] * (n + 1)
    fib_lst[0] = 0
    fib_lst[1] = 1
    for i in range(2, n + 1):
        fib_lst[i] = fib_lst[i - 1] + fib_lst[i - 2]
    return fib_lst
```
The print_fib() function computes and prints the first n numbers in the Fibonacci sequence using the specified method. This function is used to print the Fibonacci numbers when the --print-type option is set to single or all.
In main() use the Click function, click.argument() and option click.option(). Then call the get_fib() function to calculate the Fibonacci sequence using the algorithm specified by the user, and print the result according to the print type specified by the user. Two options can be defined using the decorator @click.option(). The algo option allows the user to specify the algorithm to use, which is recursion, dynamic programming, or iteration. And the print type option allows the user to specify how many Fibonacci numbers to print, which is all, none, or single.
```
def main(n: int, algo: str, print_type: str):
    print_it = print_type == 'all'
    t = FibType.ITERATIVE
    if algo == 'recursive':
        t = FibType.RECURSIVE
    elif algo == 'dp':
        t = FibType.DP
    fib_nums = get_fib(n, t)
    if print_type == 'single':
        print(fib_nums[-1])
```

### Comparison and Discussion Between Experiences
When writing the initial version of the code, I chose to start with python as a mind map. But when I almost finished python code and started to write C, it didn't go as smoothly as I imagined. I began to think about memory leaks and the how to use malloc table, etc. These are things I haven't considered at all in python. Besides that, I spend more time debugging recursive methods. During the test, the recursive method prevented me from testing larger data in terms of time, and I only reached an N value of 10,000 in the end. Also, compared with python's iterative, the final dynamic programming data did not let me see the fluctuations I wanted. I think this is caused by the fact that the N value is not large enough. Although python has many helpful and simple libraries, python takes more time to run than C language.


## Conclusions / Reflection
The results show that the iterative approach has the best performance in both C and Python, followed by the dynamic programming approach, and finally the recursive approach. In Python, the dynamic programming approach using memoization with the decorator lru_cache is easiest to implement and provides good performance. The recursive method is the slowest and may cause stack overflow error in C when computing large Fibonacci numbers. Dynamic programming methods have better time complexity than recursive methods, but require more memory. I always believe that the choice of method will depend on the specific needs and requirements of the project. There is no best program and no worst program.


## Reference
1. Wikipedia, "Fibonacci number," Wikipedia: The Free Encyclopedia, March 3, 2023.
https://en.wikipedia.org/wiki/Fibonacci_number. Accuess on: March 5, 2023.
2. Opengenus, "Different ways to calculate nᵗʰ Fibonacci number".
https://iq.opengenus.org/calculate-n-fibonacci-number/. Accuess on: March 5, 2023.

<!-- auto references --> 
[Fibonacci Series]: https://en.wikipedia.org/wiki/Fibonacci_number
[dynamic programming]: https://iq.opengenus.orgcalculate-n-fibonacci-number/
[Recursive P]: recursive_P.png
[Recursive C]: recursice_C.png
[IandDP_P]: IandDP_P.png
[IandDP_C]: IandDP_C.png
[bignum]: bignum.png
[fib.c]: fib.c
[fib.py]: fib.py
[test_runner.py]:test_runner.py 