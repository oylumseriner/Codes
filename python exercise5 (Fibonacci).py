#!/usr/bin/env python
# coding: utf-8

# In[1]:


#It relates Fibonacci numbers, then we can use the this formula:
#Fibonacci -- > F_n=F_{n-1}+F_{n-2}
def F(n):
    #There are initial values.
    a = 0
    b = 1
    result = [a,b]
    for i in range(n):
        c = a + b
        a = b
        b = c
        result.append(c)
    return (result[n])
n = int(input("Enter number of elements : "))
print("F({})=".format(n),F(n))




           

