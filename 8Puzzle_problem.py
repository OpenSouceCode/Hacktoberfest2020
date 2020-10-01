initial_state = [[1,2,3],[0,4,6],[7,5,8]]

final_state = [[1,2,3],[4,5,6],[7,8,0]]

val=0
#checking whether the inital abd final state are Same or not
def areSame(A,B):
   for i in range(3):
      for j in range(3):
         if (A[i][j] != B[i][j]):
            return False
   return True

# counting the number of mismatches

def mismatches(A,B):
   count_different = 0
   for i in range(3):
      for j in range(3):
         if (A[i][j]!=B[i][j] and A[i][j]!=0):
            count_different += 1
   return count_different


# movements of the 0 box in all directions
# in this I have simply swappped the 0 box with the correct direction and then counted mismatches .
def moveDown(initial_state,row_index,column_index):

   initial_state[row_index][column_index] , initial_state[row_index+1][column_index] = initial_state[row_index+1][column_index],initial_state[row_index][column_index]
   different_elements = mismatches(initial_state,final_state)
   initial_state[row_index+1][column_index],initial_state[row_index][column_index]=initial_state[row_index][column_index] , initial_state[row_index+1][column_index]
   
   return different_elements

def moveUp(initial_state,row_index,column_index):

   initial_state[row_index][column_index] , initial_state[row_index-1][column_index]= initial_state[row_index-1][column_index], initial_state[row_index][column_index]
   different_elements=mismatches(initial_state,final_state)
   initial_state[row_index-1][column_index], initial_state[row_index][column_index]=initial_state[row_index][column_index] , initial_state[row_index-1][column_index]
  

   return different_elements

def moveLeft(initial_state,row_index,column_index):

   initial_state[row_index][column_index], initial_state[row_index][column_index-1] = initial_state[row_index][column_index-1], initial_state[row_index][column_index]
   different_elements=mismatches(initial_state,final_state)
   initial_state[row_index][column_index-1], initial_state[row_index][column_index]=initial_state[row_index][column_index], initial_state[row_index][column_index-1]

   return different_elements

def moveRight(initial_state,row_index,column_index):

   initial_state[row_index][column_index] , initial_state[row_index][column_index+1] = initial_state[row_index][column_index+1],initial_state[row_index][column_index]
   different_elements=mismatches(initial_state,final_state)
   initial_state[row_index][column_index+1],initial_state[row_index][column_index]=initial_state[row_index][column_index] , initial_state[row_index][column_index+1]

   return different_elements


#this is for counting iterations
count_iterations = 0




while areSame(initial_state,final_state)!=True:
    

    entry_one =1000
    entry_two = 1000
    entry_three = 1000
    entry_four = 1000
    #this is the shorthand code for finding the index of 0 box , i copied it from stack overflow
    index = [(index, row.index(val)) for index, row in enumerate(initial_state) if val in row]

    (row_index , column_index) = index[0]

    count_iterations += 1
    # all possible cases of the 0 box and then appropriate directions are called.
    if row_index != 0:
        entry_one= moveUp(initial_state,row_index,column_index)        
    if column_index!=0:
        entry_four= moveLeft(initial_state,row_index,column_index)

    if column_index != 2:
        entry_two= moveRight(initial_state,row_index,column_index)
            

    if row_index != 2:
        entry_three = moveDown(initial_state,row_index,column_index)

   
   # h(n) = misplaced tiles + no of iterations
    entry_one += count_iterations
    entry_two += count_iterations
    entry_three += count_iterations
    entry_four += count_iterations

   # finding the minimum heuristic value

    min_entry = min(entry_one,entry_two,entry_three,entry_four)
   
  
    if min_entry == entry_one:
        initial_state[row_index][column_index] , initial_state[row_index-1][column_index]= initial_state[row_index-1][column_index], initial_state[row_index][column_index]
    elif min_entry == entry_two:
        initial_state[row_index][column_index] , initial_state[row_index][column_index+1] = initial_state[row_index][column_index+1],initial_state[row_index][column_index]
    elif min_entry == entry_three:
        initial_state[row_index][column_index] , initial_state[row_index+1][column_index] = initial_state[row_index+1][column_index],initial_state[row_index][column_index]
    else:
        initial_state[row_index][column_index], initial_state[row_index][column_index-1] = initial_state[row_index][column_index-1], initial_state[row_index][column_index]
   
   
    print(f"intermediate state = {initial_state}")



