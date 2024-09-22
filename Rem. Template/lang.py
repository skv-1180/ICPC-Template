# print("Hello World")
# name = "Shubham"
# age = 18
# print(name , age)
# name = "Shubham Kumar Verma"
# print(name)
# first_name = "CodeLegend"
# last_name = "X"
# is_Legend = True
# print(first_name + last_name + " is Legend:", is_Legend)
# name = input("What is my name? \n");
# print("My name is:", name)
# age = input();
# print(int(age) + 4)

# String 
# name = "Tony Stark"
# print(name.upper())
# print(name)
# print(name.lower())
# print(name)
# print(name.find('y'))
# print(name.find('Y'))
# print(name.find("Stark"))
# print(name.find("stark"))
# print(name.replace("Tony Stark", "Ironman"))
# print(name)
# #to check if a character/string is part of the main string
# print("Stark" in name)
# print("S" in name)
# print("s" in name)

# Arithmetic Operators
# print(5 + 2)
# print(5 - 2)
# print(5 * 2)
# print(5 / 2)
# print( 5 // 2) #floor division
# print(5 % 2)
# print(5 ** 4) #exponent
# i = 5
# i = i + 2
# i += 2
# i -= 2
# i *= 2

# Comparison Operators
is_greater = 1 > 5
is_lesser = 1 < 5
# 1 <= 5
# 1 >= 5
is_not_equal = 1 != 5
is_equal = 1 == 5

# Logical Operators
# or -> (atleast one is true)
# and -> (both are true)
# not -> (reverses any value)
number = 2
# print(number > 3)
# print(number < 3)
# print(not number > 3)
# print(not number < 3)
# print(number > 3 and number > 1)
# print(number > 3 or number > 1)

# If statements
# age = 18
# if age >= 18:
#     print("you are an adult")
#     print("you can vote")
# elif age < 3:
#     print("you are a child")
# else:
#     print("you are in school")
# print("thank you")

# Let’s build a Calculator
#Our Calculator
# first = input("Enter first number : ")
# second = input("Enter second number : ")
# first = int(first)
# second = int(second)
# print("----press keys for operator (+,-,*,/,%)----------")
# operator = input("Enter operator : ")
# if operator == "+":
#     print(first + second)
# elif operator == "-":
#     print(first - second)
# elif operator == "*":
#     print(first * second)
# elif operator == "/":
#     print(first / second)
# elif operator == "%":
#     print(first % second)
# else:
#     print("Invalid Operation")

# Range in Python
# range() function returns a range object that is a sequence of numbers.
# numbers = range(15)
# print(numbers)

# While Loop
# i = 1
# while(i <= 5):
#     print(i)
#     i = i + 1
# i = 1
# while(i <= 5):
#     print(i * "*")
#     i = i + 1
# i = 5
# while(i >= 1):
#     print(i * "*")
#     i = i - 1

# For Loop (to iterate over a list)
# for i in range(1,5,2):
#     print(i)
#     i = i + 1
# for i in range(5):
#     print(i * "*")
#     i = i + 1

# Lists
# friends = ["amar", "akbar", "anthony"]
# print(friends[0])
# print(friends[1])
# print(friends[-1])
# print(friends[-2])
# friends[0] = "aman"
# print(friends)
# print(friends[0:2]) #returns a new list
# for friend in friends:
#     print(friend)

# List Methods :
# marks = ["english", 95, "chemistry", 98]
# marks.append("physics")
# marks.append(97)
# print(marks)
# marks.insert(0, "math")
# marks.insert(1, 99)
# print(marks)
# print("math" in marks)
# print(len(marks)/2)
# marks.clear()
# print(marks)
# i = 0
# while i < len(marks):
#     print(marks[i])
#     print(marks[i+1])
#     i = i + 2

# Break & Continue
# students = ["ram", "shyam", "kishan", "radha", "radhika"]
# for student in students:
#     if(student == "radha"):
#         break
#     print(student)
# for student in students:
#     if(student == "kishan"):
#         continue
#     print(student)

# Tuples
# They are like lists (sequence of objects) but they are immutable i.e. once they have been
# defined we cannot change them.
# Parenthesis in tuples are optional.
# marks = (95, 98, 97, 97)
# #marks[0] = 98
# print(marks.count(97))
# print(marks.index(97))

# Sets
# Sets are a collection of all unique elements.
# Indexing is not supported in sets.
# marks = {98, 97, 95, 95}
# print(marks)
# for score in marks:
#     print(score)

# Dictionary
# Dictionary is an unordered collection of Items. Dictionary stores a (key, value) pair.
# marks = {"math" : 99, "chemistry" : 98, "physics" : 97}
# print(marks)
# print(marks["chemistry"])
# marks["english"] = 95
# print(marks)
# marks["math"] = 96
# print(marks)

# import math
# print(dir(math))
# import random
# print(dir(random))
# import string
# print(dir(string))
# from math import sqrt
# print(sqrt(4))

# def sum(a, b=4):
#     print(a + b)
# sum(1, 2)
# sum(1)