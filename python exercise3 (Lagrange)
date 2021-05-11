def lagrange_polynomials(x, x_coords):
    """The function gives the all data points such that p0(x), p1(x), p2(x), p3(x)..., users can
    calculate the each point."""
    
    import math
    #x_coords_f=[]
    #for i in x_coords:
        #x_coords_f.append(float(i))
    poly_values_2=[]
    for i in range(len(x_coords)):
        poly_values_1=[]
        for j in range(len(x_coords)):
            if i != j:
                poly_values_1.append((x-x_coords[j])/(x_coords[i]-x_coords[j]))
        poly_values_2.append(math.prod(poly_values_1))
        
    return (poly_values_2)# list or tuple
data_x = [0, 40, 85, 96, 111, 120] # x-coordinates
print(lagrange_polynomials(50, data_x))
def lagrange_polynomial_interpolant(x, x_coords, y_coords):
    """The function help us for calculating the lagrange polynomial interpolant, we have the y values."""
    
    import math
    #x_coords_f=[]
    #for i in x_coords:
        #x_coords_f.append(float(i))
    poly_values_2=[]
    for i in range(len(x_coords)):
        poly_values_1=[]
        for j in range(len(x_coords)):
            if i != j:
                poly_values_1.append((x-x_coords[j])/(x_coords[i]-x_coords[j]))
        poly_values_2.append(math.prod(poly_values_1))
    t=0
    poly_values_3=[]
    for i in range(6):
        poly_values_3.append(float(poly_values_2[i])*float(y_coords[t]))
        t+=1
        
    return (sum(poly_values_3))
    # Lagrange Interpolation of the data
data_x = [0, 40, 85, 96, 111, 120] # x-coordinates
data_y = [17.0, 48.6, 68.9, 77.6, 89.3, 99.29] # y-coordinates

xp = 50 # for which we wish to find p(50)

yp = lagrange_polynomial_interpolant(xp, data_x, data_y)
print('For x = %.2f, y = %f' %(xp, yp))
# Lagrange Interpolation of the data
xp = [50, 350]
#yp = lagrange_polynomial_interpolant(xp, data_x, data_y)

# print all the values calculated; it should be similar to:
# For x = 50.00, y = 47.990239
# For x = 350.00, y = 105888.631483
for i in range (len(xp)):
    print('For x =',xp[i],' y = ',lagrange_polynomial_interpolant(xp[i], data_x, data_y)) 
