import random
 

def insert(s, pos, ch):
        return(s[:pos] + ch + s[pos:])
         

def add_more_char(s, need):
        pos = 0
 
        # add 26 letters
        low_case = "abcdefghijklmnopqrstuvwxyz"
 
        for i in range(need):
                pos = random.randint(0, len(s)-1)
                s = insert(s, pos, low_case[random.randint(0,25)])
 
        return(s)
 

def suggester(l, u, d, s, st):
 
        
        num = '0123456789'
 
        
        low_case = "abcdefghijklmnopqrstuvwxyz"
        up_case = low_case.upper()
        spl_char = '@#$_()!'
 
        
        pos = 0
 
       
        if( l == 0 ):
           
               
                pos = random.randint(0,len(st)-1)
 
                
                st = insert(st, pos, low_case[random.randint(0,25)])
 
        
        if( u == 0 ):
           
                
                pos = random.randint(0,len(st)-1)
 
                
                st = insert(st, pos, up_case[random.randint(0,25)])
 
        
        if( d == 0 ):
           
                
                pos = random.randint(0,len(st)-1)
 
              
                st = insert(st, pos, num[random.randint(0,9)])
 
        
        
        if( s == 0 ):
           
                
                pos = random.randint(0,len(st)-1)
 
                
                st = insert(st, pos, low_case[random.randint(0,6)])
 
        return st
 

def generate_password(n, p):
   
        
        l = 0; u = 0; d = 0; s = 0; need = 0
 
       
        suggest = ''
 
        for i in range(n):
           
                
                if( p[i].islower() ):
                        l = 1
                elif( p[i].isupper() ):
                        u = 1
                elif( p[i].isdigit() ):
                        d = 1
                else:
                        s = 1
 
        
        if( (l + u + d + s) == 4):
                print("Your Password is Strong")
                return
        else:
                print("Suggested Passwords")
 
        
        for i in range(10):
                suggest = suggester(l, u, d, s, p)
                need = 8 - len(suggest)
 
                if(need > 0):
                        suggest = add_more_char(suggest, need)
                print(suggest)
 
 

input_string = 'geek@2018'
 
generate_password( len(input_string), input_string)