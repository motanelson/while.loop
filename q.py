import time

def qbit_change(qbit):
    qbit=qbit+1
    if qbit >2:
        qbit=0
    return qbit     


print("\033c\033[40;37m\nquantum emulator of a qbit\n")
Qbit=0
for a in range (10):
     print(Qbit)
     Qbit=qbit_change(Qbit)
     