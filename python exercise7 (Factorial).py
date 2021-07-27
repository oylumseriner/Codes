#!/usr/bin/env python
# coding: utf-8

# In[2]:


#We can consider the factorial of non-negative integer n. It means that the n can be 0. Then, we can explain some clear examples,
#0!=1
#1!=1
#2!=1 * 2 = 2
#3!=1 * 2 * 3 = 6
#4!=1 * 2 * 3 * 4 = 24

import math
import numpy as np
x = int(input("Enter number of elements: "))
if x < 0:
    print ("Invalid number!!!")
else:
    print("{}! =".format(x),(math.prod(np.arange(1,x+1))))

