
# Render the maze as a string
## Introduction
        Generate a maz's by compute is a wonderful game. We can present the maze's road by Road Grid. Thus, the input of 3*3 size of maze  
        will get a 7*7 output Render Grid.
        
### Requirements
* python3
* Numpy
        
### Input Preparation
#### maze_size: 
        Here you need to input two interger numbers: m n.
>m is rows of the maze and n is the cols of the maze.<br>
>Please note that: m and n must be inerger and greater than 0. If not, the program will raise a Error.<br>
>Example: 3 3
```python
def input_the_maze_parma():
    '''
    Input two rows of the data：
    Row one: two interger separate by a blank
    Row two: the maze's link information.   

    First check the abnormal situation of the first row.
    If true:
        Check the second input. 
    '''   
    while(True):
        try:
            input_size = input("please input the maze's size(m n), separate the rows and cols by the balnk: ")
            # Get the nums of the blank and the nums must be one. If not, except a ValueError            
            blank = 0
            for i in input_size:
                if(i == ' '):
                    blank+=1            
            input_size = input_size.split(' ')
            # Get the numns of data and it must be 2. If the nums  is 1, except a Error.  
            # In addition, the data input must be interger>0. If not >>> ValueError.
            numOfNumbers = len(input_size)
            if(isinstance(int(input_size[0]),int) and isinstance(int(input_size[1]),int) and blank == 1 and numOfNumbers==2):
                break                
        except: 
            # 小于0的时候抛出异常
            print("Invalid number format") 
    while(True):  
        # If there's no Error before,that means that the input must be two intergers and separate by blank.
        # Now we judge that if one of them <0, then we reaise a ValueError.
        if (int(input_size[0])<0 or int(input_size[1])<0):           
            raise ValueError("Number out of range")
        else:
            break
    input_size[0]=int(input_size[0])
    input_size[1]=int(input_size[1])
    return input_size
```
#### linkInfo: 
        Here you need to input m*n*4 numbers to represent the linked information of the maze.
>Please note that: Each input must be an inerger and greater than 0. If not, the program will raise a Error.<br>
>Example: 0 1 0 2 0 0 1 0 0 1 1 1 0 2 1 2 1 0 1 1 1 1 1 2 1 1 2 1 1 2 2 2 2 0 2 1
```python
def input_linkInfo(input_size):
    '''
    Input two rows of the data：
    Row one: two interger separate by a blank
    Row two: the maze's link information.   

    First check the abnormal situation of the first row.
    If true:
        Check the second input. 
    '''   
    while(True):
        input_link_info = input("Please input the link information (Num: m*n; separate by: ','; interger > 0): ")
                                            
        blank = 0  
        for i in input_link_info:  
           if(i == ' '):
               blank+=1                   
        # First, if the numbers of the blank is not equal to the input_szie*4, we can judge that input is wrong.  
        if ((blank != input_size[0]*input_size[1]*4-1)):                   
            raise ValueError("Invalid number format​")            
        # Then, check each input is or not a interger type, and check it is or not >0
        lists = []
        for i in (input_link_info):  
            if(i == ' '):
                i = ''
            else:
                i = int(i)
                lists.append(i)  
        # If the input is not a interger of not meet > 0, then rasie a Error
        for element in lists:         
            if((not isinstance(element,int) or element < 0)):                                                              
                 raise ValueError("Number out of range") 
        # Only meet the requriment: (each element >0) and (interger) and (numbers of them == rows * cols * 4), we can break to go ahead.
        else:
            break 
    lists = ([lists[i:i + 9] for i in range(0, len(lists), 4)])     
    return lists
```
### Generate the maze's graph
```python
                    
def gen_maze(linkInfo):
    '''
    Generate a maze. 
    But after this process, the init_maze need adjust the location of it's element by function: gen_maze_graph()
    '''         
    #Set a dict to save the names and it's Corresponding cell.
    #Give the init_arr of every cell for 3*3, as follows:    
        # w w w
        # w R w                                
        # w w w 
    cell_size = [3,3]
    rows = cell_size[0]
    cols = cell_size[1]
    names = {} 
    for i in range (rows):
        for j in range(cols):       
            names['cell%s%s'%(i,j)] = np.array(list(('W'*3+'WRW'+'W'*3)))  
            
    ''' Accofding to the LinkInfo, update corresponding cell.'''   
    for i in range(len(linkInfo)):   # Traverse the linkInfo, we can find the feature as follows:  
        # Link the cols   
        if(linkInfo[i][0] == linkInfo[i][2] and linkInfo[i][1] != linkInfo[i][3]):
            names['cell'+str(linkInfo[i][0])+str(linkInfo[i][1])][5] = 'R'
            names['cell'+str(linkInfo[i][2])+str(linkInfo[i][3])][3] = 'R'
        # Link the rows
        elif(linkInfo[i][1] == linkInfo[i][3] and linkInfo[i][0] != linkInfo[i][2]):
            names['cell'+str(linkInfo[i][0])+str(linkInfo[i][1])][7] = 'R'
            names['cell'+str(linkInfo[i][2])+str(linkInfo[i][3])][1] = 'R'
        else:
            raise Exception("Maze format error")      
    lists = []
    # We need to transfrom it to string.
    for i in range(0,cell_size[0]):
        for j in range (0,cell_size[1]):
             lists.extend(''.join((names['cell'+str(i)+str(j)])))
    return lists      

def gen_maze_graph(maze_size,lists):
    '''
    Adjust the location of each element of the maze.
    '''
    # The base means that the transform step.
    base = maze_size[0]*maze_size[1]
    graph = []
    times = int(len(lists)/27) # Times means that we need to print this number times 
    for time in range(0,int(len(lists)/27)):
        for i in range(0,maze_size[0]):
            for j in range(0,maze_size[1]):            
                graph.extend((''.join( (lists[3*i+base*j+time*27:3*i+base*j+time*27+3]))))  
    # Split the list for print.
    graph = ([graph[i:i + 9] for i in range(0, len(graph), 9)]) 
    # Finally, transform the list to string and print it.
    for i in range(0,len(graph)):
        print(' '.join((graph[i])))
```
### Testing Sample
        3 3
        0 1 0 2 0 0 1 0 0 1 1 1 0 2 1 2 1 0 1 1 1 1 1 2 1 1 2 1 1 2 2 2 2 0 2 1
### Running result
        

### Verifying code
All of the input and generate functions were packed. The graph will be generate by:   
        python TW_Assignment_WSH.py
        
