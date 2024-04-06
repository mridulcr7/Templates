from decimal import DivisionByZero


try:
    print(4//0)
except ZeroDivisionError:
    print("You are dividing by zero")