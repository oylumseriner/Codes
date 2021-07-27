# IAM592-Project-Sbox and AES
Hi everyone, I prepare the S-Box project for IAM 592 Programming Techniques in Applied Mathematics II. You can find explaination of code.  
### Example of Boolean:
I try to show one example about Boolean function, this example of code shows that Truth Table,Non linearity,Non homomoprpicity,Correlation immunity and Propogation characteristics of f.
### Example of S-box:
In cryptography, an S-box (substitution-box) is a basic component of symmetric key algorithms which performs substitution. In block ciphers, they are typically used to obscure the relationship between the key and the ciphertext, thus ensuring Shannon's property of confusion. Mathematically, an S-box is a vectorial Boolean function.\
We have 4x6 S-Box,\
0  &  1  &  2 &  3   & 4  & 5  & 6 & 7 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15 \
46 &  10 &  3 &  15  & 48 & 60 & 22& 43& 50& 2 & 50 & 30 & 13 & 38 & 58 & 7 \
First of all, we calculate the truth table of beta S(x) by using all B in V_6 and $f1,f2,f3,f4,f5,f6$. Then, we compute the truth table of ax and compare them. So, we create the **LAT**.\
Now, we should use this equations,\
beta = S(x xor alpha) xor S(x)\
The largest value in **DDT** is called differential uniformity of S and entries of DDT are all even and >2. So, we create the DDT. I added the horizontal page for it because it is very long table. Then, we compute ratio of zero cells to all cells in DDT and the largest value in DDT_s called differential uniformity.
For **SAC**, We observe changes of old and new results and we change the inputs, respectively. 
### AES Block cipher:
The Rijndael algorithm , a symmetric block cipher that can process data blocks of 128 bits, using cipher keys with lengths of 128, 192, and 256 bits. After winning the AES competition, “The AES algorithm” is preferred over the Rijndael algorithm.  The algorithm can be used the three different version depend on key lengths. Their name is “AES-128”, “AES-192”, and “AES-256”. We choose the “AES-128” for the Python code.\
**1. SubBytes()Transformation:**
It is a non-linear transformation where each input byte of the state matrix is replaced by another byte produced by the transformation. Both the input and output are interpreted as polynomials over GF(2). The input is mapped to its multiplicative inverse. Then, affine transformations(over GF($2^8$)) is used.\
The subbytes transformation is defined two steps:
* **Multiplicative inverse**: The input byte a is replaced by its multiplicative inverse x = a^{-1} , with x = 0 for a = 0.
* **Affine transformation:** Defined by y = M * x xor b, where M is a constant matrix of 8 x 8 bits, x represents the value to transform while b is a constant byte equal to 63 or 01100011 (Daemen & Rijmen, 2002).

Why this M matrix is used? The matrix used in AES is a rotational matrix based on the value 0x1F, which is 00011111 in binary. Each column is the previous column rotated to the left by a single bit.Let us try to one example, we have 0x53 firstly, we find its inverse, then it it is 0xCA or 11001010.
And, we can multiply by 8x8 main matrix. this result's is 10001110=0x8e. Finally, This value is then added (XOR) to the final vector 0x63, giving an output of 0xED. Imagine that, we calculate all inputs and put the one table. We can check the our example in the S-Box table. This table very useful. We can find the all Subbyte results. For instance, we want to calculate subbyte of 0x80. Firstly, we find the row (8). Secondly, we find the column (0).\
**2. ShiftRows() Transformation:**
In the ShiftRows() transformation, the bytes in the last three rows of the State are cyclically shifted over different numbers of bytes (offsets). In this operation, the first row of the matrix remains the same, while the second row is shifted to the left by 1 byte, the third row by 2 bytes, and the fourth row by 3 bytes.\
**3. MixColumns() Transformation:**
The MixColumns() transformation operates on the State column-by-column, treating each
column as a four-term polynomial as described in Sec. 4.3. It is the primary source of diffisuion in AES. Each column is multiplied with a fixed polynomial, a(x)=3x^3+x^2+x+2mod (x^4+1).\
We can consider the a(x) xor b(x)=d(x).
* d_0=(2 * b_0) xor (3 * b_1) xor (1 * b_2) xor (1 * b_3)
* d_1=(1 * b_0) xor (2 * b_1) xor (3 * b_2) xor (1 * b_3)
* d_2=(1 * b_0) xor (1 * b_1) xor (2 * b_2) xor (3 * b_3)
* d_3=(3 * b_0) xor (1 * b_1) xor (1 * b_2) xor (2 * b_3)

**4. AddRoundKey() Transformation:**
In the AddRoundKey() transformation, a Round Key is added to the State by a simple bitwise XOR operation. It is very simple step.
#### Key Expansion:
The key generation process in the AES algorithm must be done beforehand for the encryption process. Each cycle provides a different key input. Therefore, the key generation process includes as many turns as the number of cycles and all keys are obtained by using the keys calculated in the previous round.
* SubWord is a function that takes a four-byte input word and applies the S-box to each of the four bytes to produce an output word.
* The function RotWord takes a word [a_0, a_1, a_2, a_3] as input, performs a cyclic permutation, and returns the word [a_1, a_2, a_3, a_0]. 
* The round constant word array, Rcon[i], contains the values given by [x^{i-1},{00},{00},{00}], with x^{i-1} being powers of x (x is denoted as {02}) in the field GF(2^8).
#### Inverse Cipher:
The Cipher transformations can be inverted and then implemented in reverse order to produce a straightforward Inverse Cipher for the AES algorithm.\
**1. InvShiftRows() Transformation** 
InvShiftRows() is the inverse of the ShiftRows() transformation. This time the state matrix is shifted to the right, not to the left. The second line is shifted one byte, the third line two bytes, the fourth line three bytes to the right.\
**2. InvSubBytes() Transformation**
InvSubBytes() is the inverse of the byte substitution transformation, in which the inverse Sbox is applied to each byte of the State. This S-Box is not the same S-Box. So, the value 0x19 showed the value 0xD4 in the S-Box. In the current S-Box, 0xD4 is expected to display the value 0x19. So, the inverse is used with an S-Box.\
**3. InvMixColumns() Transformation**
We can focus this equation, a^{-1}(x)=11x^3+13x^2+9x+14.\
Remember that, we can consider the a(x) xor b(x)=d(x),
* d_0=(14 * b_0) xor (11 * b_1) xor (13 * b_2) xor (19 * b_3)
* d_1=(9 * b_0) xor (14 * b_1) xor (11 * b_2) xor (13 * b_3)
* d_2=(13 * b_0) xor (9 * b_1) xor (14 * b_2) xor (11 * b_3)
* d_3=(11 * b_0) xor (13 * b_1) xor (9 * b_2) xor (14 * b_3)

##### In Boolean Library,
**1. convert_to_binary(size):**
  * This def provides to create the inputs for any n size of bollean function.You can enter the n and you can get the list of all n size inputs for binary form.

**2. convert_to_binary_given(size,results):**
  * This def provides to create the inputs for any n size of bollean function. This def works on given inputs.

**3. truth_table(f,string_convert2):** 
  * If you add the funciton, input size and list of inputs, you can reach the truth table of function. Remmeber that, your function should be def form. For example,
  * It means that x7 + x8 + x1x2 + x3x4 + x5x6 + x7x8 + x1x2x3x4 + x3x4x5x7

**4. non_linearity (f,affine,size,string_convert2):**
  * We use the this formula, Nf=min(min\ d(f,l_alpha),2^n-max d(f,l_alpha)). We compute the min and max value of d(f,l_alpha), then we choose the min value in all values.

**5. non_homo(f,size,string_convert2):**
  * It means that NH_f=prob(f(x + y) + f(x) + f(y)=0), then we apply this.

**6. correlation_im1(f,affine,size,string_convert2):**
  * We check the l_\alpha, the we start the wt(f)=1. d(f,l_{\alpha})=2^{n-1}. If we have the all restults are not 2**(size-1), we should stop.
   
**7. correlation_im2(f,affine,size,string_convert2):**
  * Remember that if the boolean function is corelation im 1, then check the correlation im 2. It cannot be best waoy for correlation, It should be improved.

**8. correlation_im3(f,affine,size,string_convert2):**

**9. xor(x,y)**:
  * This def providec clasical xor operations between two arrays.
    
**10. pc1(f,xor,size,string_convert2):**
  * We use the this equation |x:f(x + \alpha) = f(x)|=2^{n-1}.If there are equality between two results (Tf and outputs after XOR operation) and we can move the pc2. 

**11. pc2(f,xor,size,string_convert2):**
    
**12. pc3(f,xor,size,string_convert2):**
    
**13. LAT(alpha,betha,size):**
  * For example, we calculate the truth table of beta S(x) by using all V_6 and f1,f2,f3,f4,f5,f6. Then, we compute the truth table of ax and compare them. So, we create the LAT.

**14. convert_to_decimal(x):**
  * This provides binary convert to decimal numbers.



    

