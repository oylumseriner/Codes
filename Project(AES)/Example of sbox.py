#!/usr/bin/env python
# coding: utf-8

# In[14]:


import boolean as bo

def f(coef,x):
    return (coef[0]&x[0])^(coef[1]&x[1])^(coef[2]&x[2])^(coef[3]&x[3])

def func(c,convert):
    for i in range (16):
        func=[]
        for j in convert:
            func.append(int(j[c-1]))
    return func
def s(x):
    return convert6[x]

def SAC(x1,x2,x3,x4):
    inputs=[]
    for j in range(16):
        inputs.append([x4[j],x3[j],x2[j],x1[j]])
    SAC1=[]
    for i in range(16):
        SAC1.append(s(convert_to_decimal(inputs[i])))

    SAC_change=[]
    for i in range(1,7):
        count=0
        for j in range(16):
            if func(i,SAC1)[j]!=func(i,convert6)[j]:
                count+=1
        SAC_change.append(count)
    return (SAC_change)


convert2=bo.convert_to_binary(4)
convert4=bo.convert_to_binary(6)
V_6=[46,10,3,15,48,60,22,43,50,2,50,30,13,38,58,7]
convert6=bo.convert_to_binary_given(6,V_6)

#-----------------
#f1,f2,f3,f4,f5,f6

print("f1: ",func(1,convert6))
print("f2: ",func(2,convert6))
print("f3: ",func(3,convert6))
print("f4: ",func(4,convert6))       
print("f5: ",func(5,convert6))
print("f6: ",func(6,convert6))    
    
#truth table alpha
alpha=[]
for i in convert2:
    for k in range(16):
        truth1=[]
        for j in convert2:
            truth1.append(f(j,i))
    alpha.append(truth1)

#print("Truth table of alpha:",alpha)


#truth table of betha

betha=[]
for j in (convert4):
    bs=[]
    for i in range(16):
        bs.append((j[0]&func(1,convert6)[i])^(j[1]&func(2,convert6)[i])                  ^(j[2]&func(3,convert6)[i])^(j[3]&func(4,convert6)[i])^                  (j[4]&func(5,convert6)[i])^(j[5]&func(6,convert6)[i]))
    betha.append(bs)
#print("Truth table of betha:",betha)


LAT_last=bo.LAT(alpha,betha,4)
#LAT_last[0]-->str
#LAT_last[1]-->int
print(LAT_last[0])


ddt=[]
for i in range (16):
    ddt1=[]
    for j in range (16):
        ddt1.append(convert_to_decimal(bo.xor(s(convert_to_decimal(bo.xor(convert2[i],convert2[j]))),s(j))))
    ddt.append(ddt1)
#print(ddt)

last_ddt=[]
for i in range(16):
    ddt2=[]
    for j in range(64):
        ddt2.append(ddt[i].count(j))
    last_ddt.append(str(ddt2))


print("DDT: ")
for i in last_ddt:
    print(i)

x1=[0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1]
x2=[0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1]
x3=[0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1]
x4=[0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1]

print("SAC: " )
from tabulate import tabulate
table = [["x1",SAC(x1[::-1],x2,x3,x4)],["x2",SAC(x1,x2[::-1],x3,x4)],         ["x3",SAC(x1,x2,x3[::-1],x4)],["x4",SAC(x1,x2,x3,x4[::-1])]]
headers = ["f1  f2  f3  f4  f5  f6"]
print(tabulate(table, headers, tablefmt="plain"))

list1 = [i/16 for i in SAC(x1[::-1],x2,x3,x4)]
list2 = [i/16 for i in SAC(x1,x2[::-1],x3,x4)]
list3 = [i/16 for i in SAC(x1,x2,x3[::-1],x4)]
list4 = [i/16 for i in SAC(x1,x2,x3,x4[::-1])]

table = [["x1",list1],["x2",list2],["x3",list3],["x4",list4]]
headers = ["f1     f2     f3     f4     f5     f6"]
print(tabulate(table, headers, tablefmt="plain"))

    
    
#Compute the ratio of zero cells to all cells in DDT
last_ddt1=[]
for i in range(16):
    ddt2=[]
    for j in range(64):
        ddt2.append(ddt[i].count(j))
    last_ddt1.append(ddt2)
sums=0
for i in range (16):
    sums=last_ddt1[i].count(0)+sums
print("Ratio of zero cells to all cells in DDT: ", sums/(2**4 * 2**6))

#Nonlinearity
non=[]
for i in range(64):
    non1=[]
    for j in range(16):
        non1.append(abs(LAT_last[0][i][j]-(2**(4-1))))
    non.append((2**(4-1))-max(non1))    
print("Non linearity: ", min(non))

#Dıfferantial uniformity
diff_uni=[]
for i in last_ddt1:
    diff_uni.append(max(i))
print("Differential uniformity: ",max(diff_uni))

with open('LAT.txt', 'w') as f:
    for i in LAT_last[1]:
        f.write(i+"\n")
        
with open('DDT.txt', 'w') as g:
    for i in last_ddt:
        g.write(i+"\n")





   
    
    
    
    


