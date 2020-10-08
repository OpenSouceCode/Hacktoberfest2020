''' This is a simplified interpreter for the Befunge-93 language. The pointer defaults to moving right through
    the code. A singular stack is assumed. Size unbounded. 

    Note: The implementation doesn't use user input instructions and deals with division by zero by simply 
    outputting zero. '''

import random

def interpret(code):
    code = code.split('\n')
    row, col = 0, 0
    dire, stack, out = 'R', [], ''
    while code[row][col] != '@':
        v = code[row][col]
        if v in '0123456789':
            stack.append(int(v))
        elif v in '+':
            a = stack.pop()
            b = stack.pop()
            stack.append(a+b)
        elif v in '-':
            a = stack.pop()
            b = stack.pop()
            stack.append(b-a)
        elif v in '*':
            a = stack.pop()
            b = stack.pop()
            stack.append(a*b)
        elif v in '/':
            a = stack.pop()
            b = stack.pop()
            stack.append(0 if a == 0 else round(b / a, 0))
        elif v in '%':
            a = stack.pop()
            b = stack.pop()
            stack.append(0 if a == 0 else b%a)
        elif v in '!':
            a = stack.pop()
            stack.append(1 if a == 0 else 0)
        elif v in '`':
            a = stack.pop()
            b = stack.pop()
            stack.append(1 if b>a else 0)
        elif v in '>':
            dire = 'R'
        elif v in '<':
            dire = 'L'
        elif v in '^':
            dire = 'U'
        elif v in 'v':
            dire = 'D'
        elif v in '?':
            dirs = 'RLUD'
            dire = random.choice(dirs)
        elif v in '_':
            a = stack.pop()
            dire = 'R' if a == 0 else 'L'
        elif v in '|':
            a = stack.pop()
            dire = 'D' if a == 0 else 'U'
        elif v in '"':
            if dire in 'R':
                col += 1
                while code[row][col] not in '"':
                    stack.append(ord(str(code[row][col])))
                    col += 1
            elif dire in 'L':
                col -= 1
                while code[row][col] not in '"':
                    stack.append(ord(str(code[row][col])))
                    col -= 1
            elif dire in 'U':
                row -= 1
                while code[row][col] not in '"':
                    stack.append(ord(str(code[row][col])))
                    row -= 1
            elif dire in 'D':
                row += 1
                while code[row][col] not in '"':
                    stack.append(ord(str(code[row][col])))
                    row += 1
        elif v in ':':
            stack.append(stack[-1] if len(stack) != 0 else 0)
        elif v in '\\':
            if len(stack) > 1:
                stack[-1], stack[-2] = stack[-2], stack[-1]
            else:
                stack.append(0)
        elif v in '$':
            stack.pop()
        elif v in '.':
            out += str(stack.pop())
        elif v in ',':
            out += chr(stack.pop())
        elif v in '#':
            if dire is 'R':
                col += 1
            elif dire is 'L':
                col -= 1
            elif dire is 'U':
                row -= 1
            elif dire is 'D':
                row += 1
        elif v in 'p':
            y = stack.pop()
            x = stack.pop()
            v = stack.pop()
            code[y] = code[y][:x] + chr(v) + code[y][x+1:]
        elif v in 'g':
            y = stack.pop()
            x = stack.pop()
            stack.append(ord(code[y][x]))
        if dire is 'R':
            col += 1
        elif dire is 'L':
            col -= 1
        elif dire is 'U':
            row -= 1
        elif dire is 'D':
            row += 1
        
        
    

    return out