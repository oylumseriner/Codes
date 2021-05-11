def newton_raphson(f, df, x, tol=0.0001, maxit=1000):
    """
    f and df are (python) functions returning the values at x
    """
    for i in range(maxit):
        xnew = x - f(x) / df(x) # nr formula
        if abs(xnew - x) < tol: 
            break
        x = xnew
    else:
        print("Maximum number of iterations is reached!..")
    return xnew, i
x0 = 10 # initial guess
func = lambda x : x**4 - 5 * x**2 + 4
dfunc = lambda x : 4*x**3 - 10*x
func(x0)
result = newton_raphson(func, dfunc, x0, tol=0.0001, maxit=1000)
print('The root is (approx)', result[0],'after',result[1],'iterations')
def newton_raphson_while(f, df, x, tol=0.0001, maxit=1000):
    i=0
    while i<maxit:
        xnew = x - f(x) / df(x) 
        if abs(xnew - x) < tol:
            break
        x = xnew
        i+=1
    else:
        print("Maximum number of iterations is reached!..")
    return xnew,i
x0 = -100 # initial guess
tol = 0.000001
max_it = 1000
func = lambda x : x**4 - 5 * x**2 + 4
dfunc = lambda x : 4*x**3 - 10*x
result = newton_raphson_while(func, dfunc, x0, tol=0.0001, maxit=1000)
print('The root is (approx)', result[0],'after',result[1],'iterations')
