def present_value(cash, rate, years, compunding=1):
    """The users have the cash,rate and years, they return the present value p of the money with compunding=1."""
    d = 1/(1+rate/compunding)**(compunding*years)
    return d*cash
cash = 2000 # USD
rate = 0.04 # 4%
years = 3
pv = present_value(cash, rate, years)
print(f"Present Value of $", cash ,"is", round(pv,2))
cash = 3000 # USD
rate = 0.05 # 5%
years = 4
compounding = 2
pv = present_value(cash, rate, years, compounding)
print(f"Present Value of $",cash,"is $",round(pv,2),"(with n = 2 compounding)")
def present_value_of_cash_flow(cash_flow): # should use the function `present_value()` above
    sum_pv=[]
    for i in cash_flow:
        sum_pv.append(i['cash']*(1/(1+i['rate']/(i['compounding']))**(i['compounding']*i['years'])))
    return sum(sum_pv)
cash_1 = {'cash': 2000, 'rate': 0.04, 'years': 3, 'compounding': 1}
cash_2 = {'cash': 3000, 'rate': 0.05, 'years': 4, 'compounding': 2}
cash_flow = [cash_1, cash_2]
pv = present_value_of_cash_flow(cash_flow)

print(f"Cash flow is",pv)
def add_to_cash_flow(cash_1,cash_2,cash_3):
    cash_flow = [cash_1,cash_2,cash_3]
    return cash_flow
cash_flow = []

print("The cash flow is [cash_1,cash_2,cash_3].", ) # Write nicely
cash_1 = {'cash': 2000, 'rate': 0.04, 'years': 3, 'compounding': 1}
cash_2 = {'cash': 3000, 'rate': 0.05, 'years': 4, 'compounding': 2}
def create_cash(cash,rate,years,compunding):
    cash_3 = {'cash': cash, 'rate': rate, 'years': years, 'compounding': compounding}
    return cash_3
cash_3 = create_cash(5000,0.04,2,3) 

print("The present value of cash flow ",present_value_of_cash_flow(add_to_cash_flow(cash_1,cash_2,cash_3)))
