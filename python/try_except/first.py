#When in the runtime an error that occurs after passing the syntax test is called exception or logical type.
'''
Try and Except statement is used to handle these errors within our code in Python.
The try block is used to check some code for errors i.e the code inside the try 
block will execute when there is no error in the program. Whereas the code inside the except
block will execute whenever the program encounters some error in the preceding try block.
'''

#1.divide by zero
def main():
    x=int(input())
    y=int(input())
    print(divide(x,y))

def divide(x,y):
    try:
        return x//y
    except ZeroDivisionError:
        return "Sorry ! You are dividing by zero "
         
main()     

'''
Else Clause
In python, you can also use the else clause on the try-except block which must be present 
after all the except clauses.
The code enters the else block only if the try clause does not raise an exception.
'''

'''
Finally Keyword in Python
Python provides a keyword finally, which is always executed after the try and except blocks.
 The final block always executes after normal termination of try block or after try block 
 terminates due to some exceptions.
'''
