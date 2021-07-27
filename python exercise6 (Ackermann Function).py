#!/usr/bin/env python
# coding: utf-8

# In[1]:


#We try to compute the Ackermann Function A(m,n) with m,n. Now, we can use the this formula:
#if m=0,then use n+1
#if m>0 and n=0, then use A(m-1,1)
#if m>0 and n>0, then use A(m-1,A(m,n-1))
def A(m,n):
    if m == 0:
        return (n+1)
    elif m > 0 and n == 0:
        return(A(m-1,1))
    elif m > 0 and n > 0:
        return (A(m-1 , A(m,n-1)))
m = int(input("Enter number of elements for m : "))
n = int(input("Enter number of elements for n : "))
print("A({})=".format((m,n)),A(m,n))

