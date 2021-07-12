import random
import matplotlib.pyplot as plt
def die2coin(m):
    die=random.randint(1,6)
    if m==1:
    # method 1 gives H when die=1,2 or 3 and tail otherwise
        if die<=3:
            return "H"
        else:
            return "T"
    elif m==2:
        # method 2 gives H when die=1, tail when die =2 and no output otherwise
        if die==1:
            return "H"
        elif die==2:
            return "T"
        else:
            return None
    elif m==3:
    # method 3 gives H when die rolls an even no. and T on odd no.
        if die%2==0:
            return "H"
        else:
            return "T"
m=int(input("Enter method no.: "))
n=int(input("Enter no. of rolls: "))
storage={'H':0, 'T':0}
for i in range(n):
    toss= die2coin(m)
    if toss=="H" or toss=="T":
        storage[toss]=storage[toss]+1
print ("\nThe obtained Heads and Tails are as follows:")
print("Heads:\t",storage["H"])
print("Tails:\t",storage["T"])
coinface=list(storage.keys())
times=list(storage.values())
fig=plt.figure(figsize=(6,6))
plt.bar(coinface,times,color='blue',width=0.1,align="center")
plt.xlabel("Toss result")
2
plt.ylabel("No. of times occoured")
plt.title("Simulation of fair coin toss")
plt.show()
