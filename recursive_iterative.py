# RECURSIVE APPROACH TO FIND A FACTORIAL OF A GIVEN NUMBER

def recur(n):
    return n * recur(n-1)
    
 print(recur())
  
 # ITERATIVE APPROACH TO FIND THE FACTORIAL OF A NUMBER
  
 def itera(n):
     sum = 1
     for i in range(n):
         print(sum *= i)
         
 itera(5)
     
