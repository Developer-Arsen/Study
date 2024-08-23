import math
import time


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

def binarySearch(ls: list, target: int) -> int:
    start = 0
    end = len(ls)

    while start != end:
        mid = int((start + end) / 2)
        if ls[mid] == target:
            return mid
        
        if ls[mid] >= target:
            end = mid - 1
        elif ls[mid] <= target:
            start = mid + 1
    
    return mid
        
def hex(num : int) -> None:
    numberAsHex = bytearray()
    hexObj = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

    while num > 0:
        n = int(num % 16)
        if n < 10:
            print(n)
        else :
            print(hexObj[n])
        num = int(num / 16)


numberAsHex = bytearray()
hexObj = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
def hexRec(num: int):
    if num <= 0:
        return
    
    hexRec(int(num / 16))
    n = num % 16
    if n > 9:
        numberAsHex.extend(hexObj[n].encode("UTF-8"))  
    else:
        numberAsHex.extend(str(n).encode("UTF-8"))  
        
        
def binaryRec(num: int):
    if num <= 0:
        return
    binaryRec(int(num / 2))
    numberAsHex.extend(str(int(num % 2)).encode("UTF-8"))  
    
    
def longestWord(string: str) -> None:
    ls = string.split()
    index = 0 
    max = len(ls[0])
    i = 0
    for word in ls:
        if max < len(word):
            index = i
            max = len(word)
        i += 1
        
    print(ls[index])
    
def onlyDigits(string: str) -> None:
    for i in string:
        print(i)    
        # if i and i.isdigit() == True:
    
    
def to_upper_case(string:str) -> None:
    print(string.upper())
    


def polindromCount(n : int) -> int:
    x = 0
    while True:
        x += 1
        reversed_int = int(str(n)[::-1] if n >= 0 else -int(str(-n)[::-1]))
        sum = reversed_int + n
        if isPolindrom(sum):
            return x
        n = sum

def isPolindrom(n : int) -> bool:
    s = str(n)
    return s == s[::-1]
    
def range(n : int) -> None:
    if n == 0:
        return
    
    print(n)
    n -= 1
    range(n)
    
def a (arr, n):
    if n == len(arr):
        return
    print(arr[n])
    n +=1
    a(arr, n)
    

def sum(n):
    if not n:
        return 0
    return int(n % 10) + sum(int(n/10))
    
print(sum(123))

# to_upper_case("string")
# dic2 = {"b" : 1}
# dic =  dic * dic2
# print(to_upper_case("12asda"))
# longestWord("barev eeee")

# binaryRec(60)
# print(numberAsHex)
# print(hex(16))
# bn = [1,2,3,4,5]
# x = int(input("ENTER UMBER \n"))
# print(binarySearch(bn, x))
# print(power(2, 5))
# print(isPrimeNumber(9))
# print_multiplication_table(5)
# print(factorial(5))
# print(sumOfNums(123))
# print(fibonachi(2))