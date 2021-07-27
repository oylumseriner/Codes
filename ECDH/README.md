**Question1** 

Implement Koblitz Imbedding for the curve:\
y^2=x^3+ax+b\
over Fp where a, b and p are given in the file parameters.txt.\
Your program should read an input text from a file input_text (take a look at the attached code if you need a refresher), encode it into an integer m and represent it as a point P = (x, y) on the curve using Koblitz Imbedding, then print the point on the console. Take the failure probability as 2−κ = 2−30. Also print out the j value in x = mκ + j for the correct x. Imbed the following three text strings as points on the curve and print the result as above. We don’t want a pdf report for this homework so write these values at the beginning of your code as comments.\
* Is it imbed or embed?
* Koblitz calls it imbed.
* And a text of your choosing

**Question2** 

Implement ECDH between two people A and B using the above curve. The generator point G and its order n is also given in parameters.txt. Randomly choose a secret key for A and B, find their public keys and the shared secret. Print their private and public keys and the shared secret on the console. You’ll need to implement point addition, point doubling and scalar multiplication. Implement double and add for scalar multiplication.
