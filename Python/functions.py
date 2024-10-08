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
    
# def range(n : int) -> None:
#     if n == 0:
#         return
    
#     print(n)
#     n -= 1
#     range(n)
    
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
    
# print(sum(123))

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
# Create a 3x3 matrix
# matrix = [
#     [1, 2, 3],  
#     [4, 5, 6],
#     [7, 8, 9]
# ]

# matrix = [
# [0, 'M', 0, 'M', 0],
# [0, 0, 'M', 0, 0 ],
# [0, 0, 0, 0, 0 ],
# ['M', 'M', 0, 0, 0],
# [0, 0, 0, 'M', 0 ],
# ]

# def sumsum(i, j):
#     sum = 0
    
#     istart = i
#     iend = i + 2
    
#     jstart = j
#     jend = j + 2
    
#     istep = 1
#     jstep = 1
    
    # if j >= len(matrix[i]) - 1:
    #     jstart, jend = jend -1, jstart
    #     istep = -1
        
    # if i >= len(matrix) -1:
    #     istart, iend = iend -1 , istart
    #     jstep = -1
    
#     for a in range(istart, iend):
#         print(a)
#         for b in range(jstart, jend):
#             if matrix[a][b] == "M":
#                 sum += 1
#     return sum    

# for i in range(len(matrix)):
#     for j in range(len(matrix[i])):
#         if matrix[i][j] == 0:
#             matrix[i][j] = sumsum(i, j)


# for i in range(len(matrix)):
#     for j in range(len(matrix[i])):
#         print(matrix[i][j], end="")
#     print()

# import itertools

# for i in itertools.count():
#     print(f"Loop iteration {i}")
#     user_input = input("Type 'exit' to stop: ")
#     if user_input.lower() == 'exit':
#         print("Exiting the loop.")
#         break

# 0 M 0 M 0 	1 M 3 M 1 
# 0 0 M 0 0   	1 2 M 2 1 
# 0 0 0 0 0    	2 3 2 1 0
# M M 0 0 0  	M M 2 1 1 
# 0 0 0 M 0   	2 2 2 M 1




def greet(name, lastname, grt = "default "):
    return name + " " + lastname + " " + grt

def calc(cart,tax=10):
    sum = 0
    for item in cart:
        sum += item + tax
        
    return sum

cart = [10,20,30]
print(calc(cart, tax=20))

import math

dict = {
    "square": lambda x: x * x,
    "circle": lambda radius: math.pi * radius ** 2,
    "rectangle": lambda width, height:  width * height ,
    "triangle": lambda base, height: base * height * 0.5
}


def calculate_area(shape, **kwargs):
    vals = list(kwargs.values())
    return dict[shape](*vals) if shape in dict else 0 

temp_dict = {
    "celsius_to_fahrenheit" : lambda c: (c * 9/5) + 32,
    "fahrenheit_to_celsius" : lambda f: (f - 32) * 5/9,
    "celsius_to_kelvin" : lambda c: c + 273.15,
    "kelvin_to_celsius" : lambda k: k - 273.15,
    "fahrenheit_to_kelvin" : lambda f: (f - 32) * 5/9 + 273.15,
    "kelvin_to_fahrenheit" : lambda k: (k - 273.15) * 9/5 + 32,
}


def calculate_temp(temp, from_unit, to_unit):
    str = from_unit + "_to_" + to_unit
    return temp_dict[str](temp) if str in temp_dict else 0 


res = map(lambda x: x * x , [1,2,3])
res = filter(lambda x: x % 2 != 0, [1,2,4,5])

ls_operations = {
    "reverse": lambda ls : ls[::-1],
    "double": lambda ls: list(map(lambda x: x*x, ls))
}

def transform_list(operand, list):
    return ls_operations[operand](list) if operand in ls_operations else []


text_dict = {
    "upper": lambda str: str.upper(),
    "lower": lambda str: str.lower(),
    "replace": lambda str, old, new: str.replace(old, new) ,
}

def text_operations(text, operand, **kwargs):
    vals = {"text": text }
    vals = {**vals , **kwargs}
    vals = list(vals.values())
    return text_dict[operand](*vals) if operand in text_dict else []

# print(text_operations("hello word", "replace", **{"old": "word", "new": "ahaa"}))

z = set("123")
z.add("45")
print(z)