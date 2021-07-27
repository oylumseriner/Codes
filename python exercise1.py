cycling = float(input("Enter number of hours cycling: "))
running = float(input("Enter number of hours running: "))
swimming = float(input("Enter number of hours swimming: "))
weight_loss = float((1/3500)*(200*cycling + 475*running + 275*swimming))
print("Weight loss: ", round(weight_loss,1)," pounds")
def pound_to_kilograms(pound):
    """1 pound equals 0.45359237 kilograms. When users prefer this definition, 
    they can convert pound to kilograms with this function. 
    """
    kilograms = pound * 0.45359237
    return kilograms
def triathlon(hours, metric):
    """The 'hours' have list form and it inclueds cycling, running and swimming hours.Then,
    the 'metric' can be True or False, if users choose the metric is True, the function gives the
    kilograms types, otherwise the function gives the pound types.
    """
    weight_loss = float((1/3500)*(200*hours[0] + 475*hours[1]  + 275*hours[2] ))
    if (metric == True):
        print(weight_loss * 0.45359237)
    elif (metric == False):
        print(weight_loss)
c_r_s=[]
cycling = float(input("Enter number of hours cyling: "))
c_r_s.append(cycling)
running = float(input("Enter number of hours running: "))
c_r_s.append(running)
swimming = float(input("Enter number of hours swimming: "))
c_r_s.append(swimming)     
# In metric, kilograms:
triathlon(c_r_s, True)
triathlon(c_r_s, False)
