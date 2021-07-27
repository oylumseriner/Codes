def convert_to_binary(size):
    """This def provides to create the inputs for any n size of bollean function.
    You can eneter the n and yo can get the list of all n size inputs for binary form.
    """
    inputs = []
    for i in range(0,(2**size)):
        bnr = bin(i).replace('0b','')
        x = bnr[::-1]
        while len(x) < size: 
            x += '0'
        bnr = x[::-1]
        inputs.append(bnr)
    string_convert2=[]
    for i in range(2**size):
        string_convert=[]
        for j in range(size):
            string_convert.append(int(inputs[i][j]))
        string_convert2.append(string_convert)
    return string_convert2
def convert_to_binary_given(size,results):
    """This def provides to create the inputs for any n size of bollean function.
    You can eneter the n and yo can get the list of all n size inputs for binary form for given results.
    """
    inputs_given = []
    for i in results:
        bnr = bin(i).replace('0b','')
        x = bnr[::-1]
        while len(x) < size:
            x += '0'
        bnr = x[::-1]
        inputs_given.append(bnr)
    convert6=[]
    for i in inputs_given:
        convert5=[]
        for j in range(size):
            convert5.append(int(i[j]))
        convert6.append(convert5)
    return convert6
def truth_table(f,string_convert2): 
    """If you add the funciton, input size and list of inputs, you can reach the truth table of function.
    Remmeber that, your function should be def form. For example,
    def f(x):
    return x[6]^x[7]^(x[0]&x[1])^(x[2]&x[3])^(x[4]&x[5])^(x[6]&x[7])^(x[0]&x[1]&x[2]&x[3])^(x[2]&x[3]&x[4]&x[6])
    It means that x7 + x8 + x1x2 + x3x4 + x5x6 + x7x8 + x1x2x3x4 + x3x4x5x7
    """
    fonk_input=[]
    for i in string_convert2:
        fonk_input.append(f(i))
    return fonk_input

def non_linearity (f,affine,size,string_convert2):
    """We use the this formula, Nf=min(min\ d(f,l_alpha),2^n-max d(f,l_alpha))
    We compute the min and max value of d(f,l_alpha), then we choose the min value in all values.
    """
    for k in range(2): 
        aft=[]
        for i in string_convert2:
            count=0
            for j in string_convert2:
                if affine(i,j,size,k)!=f(j):
                    count+=1
                    continue 
            aft.append(count)
    return min(aft)
def non_homo(f,size,string_convert2):
    """It means that NH_f=prob(f(x + y) + f(x) + f(y)=0), then we apply this.
    """
    N_homo=[]
    cn=0
    for i in string_convert2:
        for j in string_convert2:
            sums=[]
            for k in range(size):
                sums.append(i[k]^j[k])
            f_x=f(i)
            f_y=f(j)
            if f(sums)==f_x^f_y:
                cn+=1
    return cn/2**(2*size)

def correlation_im1(f,affine,size,string_convert2):
    """We check the l_\alpha, the we start the wt(f)=1. d(f,l_{\alpha})=2^{n-1}. If we have the all restults are not 2**(size-1),
    we should stop.
    
    """
    wt_1=[]
    for i in string_convert2:
        if i.count(1)==1:
            wt_1.append(i)
    for i in string_convert2:
        for j in range(size):
            cor=[]
            if (f(i)^affine(wt_1[j],i,size,0))!=2**(size-1):
                cor.append(wt_1[j])
    if cor == []:
        print("This function satisfies correlation immune 1")
    else:
        print("Not correlation immune because of ", cor)
def correlation_im2(f,affine,size,string_convert2):
    """Remember that if the boolean function is corelation im 1, then check the correlation im 2. It cannot be best waoy for correlation,
    It should be improved."""
    wt_1=[]
    for i in string_convert2:
        if i.count(1)==2:
            wt_1.append(i)
    for i in string_convert2:
        for j in range(size):
            cor=[]
            if (f(i)^affine(wt_1[j],i,size,0))!=2**(size-1):
                cor.append(wt_1[j])
    if cor == []:
        print("This function satisfies correlation immune 2")
    else:
        print("Not correlation immune because of ", cor)
def correlation_im3(f,affine,size,string_convert2):
    wt_1=[]
    for i in string_convert2:
        if i.count(1)==3:
            wt_1.append(i)
    for i in string_convert2:
        for j in range(size):
            cor=[]
            if (f(i)^affine(wt_1[j],i,size,0))!=2**(size-1):
                cor.append(wt_1[j])
    if cor == []:
        print("This function satisfies correlation immune 3")
    else:
        print("Not correlation immune because of ", cor)
def xor(x,y):
    xor=[]
    for i in range(len(x)):
        xor.append(x[i]^y[i])
    return xor
    
def pc1(f,xor,size,string_convert2):
    """ We use the this equation |x:f(x + \alpha) = f(x)|=2^{n-1}.If there are equality between two results
    (Tf and outputs after XOR operation) and we can move the pc2""" 
    wt_1=[]
    for i in string_convert2:
        if i.count(1)==1:
            wt_1.append(i)
    prop=[]
    for j in range(size):
        count=0
        for i in string_convert2:
            if f(i)==f(xor(i,wt_1[j])):
                count+=1
        if count != 2**(size-1):
            prop.append(wt_1[j])
    if prop ==[]:
        print("This function satisfies prop. characteristic 1")
    else:
        print("Not prop. characteristic because of ", prop)
    return
def pc2(f,xor,size,string_convert2):
    wt_1=[]
    for i in string_convert2:
        if i.count(1)==2:
            wt_1.append(i)
    prop=[]
    for j in range(size):
        count=0
        for i in string_convert2:
            if f(i)==f(xor(i,wt_1[j])):
                count+=1
        if count != 2**(size-1):
            prop.append(wt_1[j])
    if prop ==[]:
        print("This function satisfies prop. characteristic 2")
    else:
        print("Not prop. characteristic because of ", prop)
def pc3(f,xor,size,string_convert2):
    wt_1=[]
    for i in string_convert2:
        if i.count(1)==3:
            wt_1.append(i)
    prop=[]
    for j in range(size):
        count=0
        for i in string_convert2:
            if f(i)==f(xor(i,wt_1[j])):
                count+=1
        if count != 2**(size-1):
            prop.append(wt_1[j])
    if prop ==[]:
        print("This function satisfies prop. characteristic 3")
    else:
        print("Not prop. characteristic because of ", prop)
    return
def LAT(alpha,betha,size):
    LAT=[]
    for i in betha:
        LAT1=[]
        for k in alpha:
            count=0
            for j in range(2**size):
                if i[j]==k[j]:
                    count+=1
            LAT1.append(count)
        LAT.append(LAT1)
    LAT_last=[]
    for i in range(2**size):
        LAT2=[]
        for j in LAT:
            LAT2.append(j[i])
        LAT_last.append(str(LAT2))
    return [LAT,LAT_last]
def convert_to_decimal(x):
    result=0
    for i in range(len(x)):
        result+=(x[len(x)-i-1]*(2**i))
    return result
