def process_instructions(instructions, grid_size):
    dir = 2 #each direction is represented by an integer(1234 = ENWS rotating anticlockwise) 2 means North
    x=0  #current position in 0,0
    y=0
    row,col = grid_size #number of rows and columns in2D grip
    for action in instructions: #loopinf through instructions
        if action == 'F': #moves forward only if destination is within grid
            if dir ==1:
                if x+1<=col:
                    x+=1
            elif dir ==2:
                if y+1<=row:
                    y+=1
            elif dir ==3:
                if x-1>=0:
                    x-=1
            else :
                if y-1>=0:
                    y-=1

        elif action == 'R':
            if dir ==1: #turning right on E(1) means turning S(4)
                dir = 4
            else:
                dir-=1

        else :
            if dir == 4: #turning left on S(4) means turning E(1)
                dir =1
            else:
                dir+=1
    x= str(x) #turning int into str to insert in a tuple
    y=str(y)
    directions ="0ENWS" #value of int dir is the index in which we'll find the direction from this string
    curr_direction =directions[dir]
    result= (x,y,curr_direction) #result tuple containing position and direction
    return result



#taking inputs
instructions = input("Give instructions:")
r = input("Input grid size AxB:")
grid_size = tuple(map(int, r.split('x')))
#calling function and passing values
result =process_instructions(instructions, grid_size)
print(result)