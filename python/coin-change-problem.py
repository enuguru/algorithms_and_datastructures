currency = [50,25,10,5,1]
change = 0
change_remaining=0
total_amount=2.00
Actual_amount=1.33
change=(total_amount-Actual_amount)*100
print(change)
change_remaining=change
change_built=0
i=0
while i<len(currency):
    
    if((currency[i]<=change_remaining) and (change_remaining!=0)):
        print(currency[i])
        change_built+=currency[i]
        change_remaining-=currency[i]
    else:
        i=i+1



