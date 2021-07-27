#!/usr/bin/env python
# coding: utf-8

# In[2]:


#Example of proporties of given boolean function.
import boolean as bo
def f(x):
    return x[6]^x[7]^(x[0]&x[1])^(x[2]&x[3])    ^(x[4]&x[5])^(x[6]&x[7])^(x[0]&x[1]&x[2]    &x[3])^(x[2]&x[3]&x[4]&x[6])
def g(x):
    return(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7])
def affine(coef,x,size,const):
    sums=0
    for i in range(size):
        sums^=(coef[i]&x[i])
    return sums^const
def xor(x,y):
    xor=[]
    for i in range(len(x)):
        xor.append(x[i]^y[i])
    return xor
        
size=8
inputs = bo.convert_to_binary(size)

#Truth Table 
fonk_input=bo.truth_table(f,inputs)
print("Truth table: ", fonk_input )
print("Weight:", fonk_input.count(1))
#Non linearity
aft=bo.non_linearity (f,affine,size,inputs)
print("Non linearity: ", aft)       
#Non homomoprpicity
x=bo.non_homo(f,size,inputs)
print("Non homomorpicity: ", x)
#Correlation immunity
cor=bo.correlation_im1(f,affine,size,inputs)
print("Not correlation immune because of ", cor) 

# Propogation characteristics of f
prop=bo.pc1(f,xor,size,inputs)
print("Not prop. characteristic because of ", prop)


# In[ ]:




