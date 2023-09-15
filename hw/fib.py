from enum import Enum
from typing import List
from functools import lru_cache
import click
import sys

sys.setrecursionlimit(100000)


class FibType(Enum):
    DP = 2
    RECURSIVE = 1
    ITERATIVE = 0


def fib_iterative(n: int) -> int:
    """
        Calculates the nth Fibonacci number using an iterative approach.

        Args:
            n: An integer specifying which Fibonacci number to calculate.

        Returns:
            An integer representing the nth Fibonacci number.
        """
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        first = 0
        second = 1
        for i in range(2, n+1):
            next_num = first + second
            first = second
            second = next_num
        return second


def fib_recursive(n: int) -> list[int]:
    """
        Calculates the nth Fibonacci number using a recursive approach.

        Args:
            n: An integer specifying which Fibonacci number to calculate.

        Returns:
            A list of integers representing the first n Fibonacci numbers.
        """
    if n <= 0:
        return [0]
    elif n == 1:
        return [0, 1]
    else:
        fib_list = fib_recursive(n - 1)
        fib_list.append(fib_list[-1] + fib_list[-2])
        return fib_list


@lru_cache(maxsize=None)
def fib_dp(n: int) -> list[int]:
    """
        Calculates the nth Fibonacci number using dynamic programming with memoization.

        Args:
            n: An integer specifying which Fibonacci number to calculate.

        Returns:
            A list of integers representing the first n Fibonacci numbers.
        """
    fib_lst = [-1] * (n + 1)
    fib_lst[0] = 0
    fib_lst[1] = 1
    for i in range(2, n + 1):
        fib_lst[i] = fib_lst[i - 1] + fib_lst[i - 2]
    return fib_lst


def get_fib(n: int, version: FibType) -> List[int]:
    """
        Returns the first n Fibonacci numbers using the specified calculation method.

        Args:
            n: An integer specifying how many Fibonacci numbers to calculate.
            version: A member of the FibType enum specifying which calculation method to use.

        Returns:
            A list of integers representing the first n Fibonacci numbers.
        """
    if version == FibType.ITERATIVE:
        return [fib_iterative(i) for i in range(n)]
    elif version == FibType.RECURSIVE:
        return fib_recursive(n)
    elif version == FibType.DP:
        return fib_dp(n)[:n]


def print_fib(n: int, print_it: bool = False, version: FibType = FibType.ITERATIVE) -> List[int]:
    """
        Computes and prints the first n numbers in the Fibonacci sequence using the specified method.

        Args:
            n (int): The number of Fibonacci numbers to compute.
            print_it (bool, optional): Whether to print each number as it is computed. Defaults to False.
            version (FibType, optional): The method to use for computing the Fibonacci numbers. Defaults to FibType.ITERATIVE.

        Returns:
            List[int]: A list of the first n Fibonacci numbers.
    """
    if version == FibType.RECURSIVE:
        return fib_recursive(n)
    if version == FibType.DP:
        return fib_dp(n)
    for i in range(n):
        fib_lst = [fib_iterative(i) for i in range(n)]
        if print_it:
            print(fib_lst[-1], end="")
    if print_it:
        print()
    return fib_lst


@click.command()
@click.argument("n", type=click.IntRange(min=0, max=50000, clamp=True))
@click.option("--algo", type=click.Choice(['recursive', 'dp', 'iterative'], case_sensitive=False), default='iterative')
@click.option("--print-type", type=click.Choice(['all', 'none', 'single'], case_sensitive=False), default='none')
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


if __name__ == "__main__":
    main()
