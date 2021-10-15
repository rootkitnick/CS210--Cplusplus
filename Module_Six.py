import re
import string


def exitprogram():         #Functin designed to print a program exit message to user
    print("Exiting program...")

def DoubleValue(v):           #Function designed to double a value and return the doubled value
    print(' ')
    return v * 2

def MultiplicationTable(v):   #Function designed to print a multiplication table based on user input
    print(' ')
    for i in range(1, 11):
        print(v, 'x', i, '=', v*i)
    
    print(' ')       
    return 0
