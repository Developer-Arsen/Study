import math


def fibonachi(num: int) -> int:
    if num <= 0:
        return 0
    a = 0
    b = 1
    c = a + b

    while num - 2:
        a = b
        b = c
        c = a + b
        num -= 1

    return c

def print_multiplication_table(number, up_to=10) -> None:
    for i in range(1, up_to + 1):
        print(f"{number} x {i} = {number * i}")

def sumOfNums(num: int) -> int:
    if num <= 0:
        return 0
    
    sum = 0
    while num:
        sum += int(num % 10)
        num /= 10
    return sum

def factorial(num: int) -> int:
    if num < 0:
        return -1
    
    if num == 0:
        return 0

    fact = 1
    count = 1
    while num != count:
        count += 1
        fact *= count

    return fact


def isPrimeNumber(num: int) -> bool: 
    if num <= 1:
        return False

    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True


def power(num: int, exp: int) -> int:
    count = 1
    step = num
    while count != exp:
        count += 1
        num *= step
        print(num)
    return num    



# print(power(2, 5))
# print(isPrimeNumber(9))
# print_multiplication_table(5)
# print(factorial(5))
# print(sumOfNums(123))
# print(fibonachi(2))