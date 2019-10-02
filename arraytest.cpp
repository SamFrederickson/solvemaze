/*
Samuel Frederickson
9/24/2019
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include "Stack.h"
#include "LinkedList.h"
using namespace std;

//--------------------------------Function Declartions--------------------------------------------------//
char **readfile(); // returns 2d dynamic array
bool checkifcomplete(char **array); // Checks that maze has a start and end.
void FindStart(char **array, int &x, int &y);  //find the Start in the maze
void AddNodes(char **array, int **visits, Stack &l, int j, int h);
int isAtEnd(char **array, int j, int h);
void determineDirection(char **array, int **visits, int x, int y);
int **visitedArray();
int rows;
int cols;

//---------------------------------------Int Main()-----------------------------------------------------//
int main()
{
    int startx;
    int starty;
//------------------------------Array made and determine if complete maze-------------------------------//
   char **maze = readfile();
   int **visited = visitedArray();

    if(checkifcomplete(maze))
    {
        cout <<endl << "Maze has a start and an end!";
    }
    else
    {
        cout << "Maze does not have a start and/or an end, can not compute.";
        delete [] maze;
        delete [] visited;
        return 0;
    }
//------------------------------------------------------------------------------------------------------//
    
    Stack pos;  //controls flow of events 
    FindStart(maze, startx, starty);
    int x = startx;
    int y = starty;
    cout<< endl;
    cout << endl << "Starting spot is: "<< x << ", " << y;
    pos.Push(x,y);
    //pos.Pop(x,y);   //make

    while( (isAtEnd(maze,x,y)) == 0 )
    {
        if(pos.IsEmpty())
        {
           cout<< endl << "Maze does not have a solution"<< endl;
           break;
           delete [] maze;
           delete [] visited;
           return 0;
        }
        else
        {
            visited[x][y] = 1;
            AddNodes(maze, visited, pos, x, y); 
            pos.Pop(x,y);
            //cout<< endl << "Position: " << x << ", " << y;
            determineDirection(maze,visited,x,y);
        }   
    }
    for(int j = 0; j < rows; j++)
    {
        for(int h = 0;h < cols;h++)
        {
            cout << maze[j][h];
        }
        cout<< endl;
    }
    delete [] maze;
    delete [] visited;
    return 0;
}
char **readfile()
{
//-----------------------------Variable declaration and ifstream setup----------------------------------//

    ifstream fin("maze1.txt");  //change text file to maze you want to read.
    char c;
    int count = 0;
    char array[2]; // array for char to int max size is 40x40 so only need two spots

//-------------------------Makes the two numbers at top of file into ints-------------------------------//

    while(fin.get(c))  //looping character by character
    {
        if(c == ' ')            //if space means new number after, convert array to int and reset the array.
        {
            count = 0;
            cols = atoi(array);
            cout << cols << " by";
        }
        else if(c == '\n')  //if new line, then no more numbers in file so convert array to int.
        {
            cout << " ";
            rows = atoi(array);
            cout << rows << endl;
            break;
        }
        else
        {
            array[count] = c;   //add character to array
            //cout << array[count];
            count++;
        }
    }

//-----------------------------------Dynamic Array allocation-------------------------------------------//

    char **maze = new char*[rows];  //create a 1d array pointer
    for(int i = 0; i < rows; i++)
        maze[i] = new char[cols];   //each row points to a new array

        int u = 0;
        int g = 0;
    while(fin.get(c))
    {
        if(c == '\n') // if newline character, increment the row and set the cols back to 0;
        {
            u++;
            g = 0;
        }
        else
        {
            maze[u][g] = c;
            //cout << maze[u][g];
            g++;
        }
    }
    fin.close();       //close it

//--------------------------------------Cout the final array--------------------------------------------//

    //for(int j = 0; j < rows; j++)
    //{
    //  for(int h = 0;h < cols;h++)
    //  {
    //      cout << maze[j][h];
    //  }
    //  cout<< endl;
    //}
//-------------------------------------Return and Delete Array------------------------------------------//
    return maze;
    delete [] maze;
}
bool checkifcomplete(char **array)
{
    bool start = false;
    bool end = false;
    for(int j = 0; j < rows; j++)
    {
        for(int h = 0;h < cols;h++)
        {
            if(array[j][h] == 'S')                  //Has Start
            {
                start = true;
            }
            else if(array[j][h] == 'G')            //Has End
            {
                end = true;
            }
            else
            {
                continue;
            }
        }
    }
    return (start & end);
}
void FindStart(char **array, int &x, int &y)
{
    for(int j = 0; j < rows; j++)
    {
        for(int h = 0; h < cols; h++)
        {
            if(array[j][h] == 'S')               // Finds S, and adds to top of stack.
            {
                x = j;
                y = h;
               // cout << "found";
                break;
            }
            else
            {
               // cout << endl << "Not found for " << j << ", " << h;
                continue;
            }
        }
    }
}
void AddNodes(char **array, int **visits, Stack &l, int j, int h)
{

    if(j != rows-1 && array[j+1][h] == '.' && visits[j+1][h] == 0)    //down
    {
        l.Push(j+1,h);
       // cout<< endl << "added down";
    }
    else
    {
        //cout<< "Cant add down" << endl;
    }
    
    if( j != 0 && array[j-1][h] == '.' && visits[j-1][h] == 0)  //up
    {
        l.Push(j-1,h);
         //cout<< endl << "added up";
    }
    else
    {
        //cout<< "Cant add down" << endl;
    }
    
    if(h != cols-1 && array[j][h+1] == '.' && visits[j][h+1] == 0)   //right
    {
        l.Push(j,h+1);
        //cout<< endl << "added right";
    }
    else
    {
        //cout<< "Cant add down" << endl;
    }

    
    if(h != 0 && array[j][h-1] == '.' && visits[j][h-1] == 0) //left
    {
        l.Push(j,h-1);
        //cout<< endl << "added left";
    }
    else
    {
        //cout<< "Cant add down" << endl;
    }
}
int isAtEnd(char **array, int j, int h)
{
    int found = 0;
    if(j != rows-1 && array[j+1][h] == 'G')    //down
    {
        cout<< endl << "Solution Found at " << j+1 << ", " << h << endl;
        found = 1;
    }
    else
    {

    }
    
    if( j != 0 && array[j-1][h] == 'G')  //up
    {
        cout<< endl << "Solution Found at " << j-1 << " , " << h << endl;
        found = 1;
    }
    else
    {

    }
    
    if(h != cols-1 && array[j][h+1] == 'G')  //right
    {
        cout<< endl << "Solution Found at " << j << ", " << h+1 << endl;
        found = 1;

    }
    else
    {

    }

    
    if(h != 0 && array[j][h-1] == 'G') //left
    {
         cout<< endl << "Solution Found at "<< j << ", " << h-1 << endl;
         found = 1;
    }
    else
    {
        
    }
    return found;
}
int **visitedArray()
{
    int **visited = new int*[rows];  //create a 1d array pointer
    for(int i = 0; i < rows; i++)
        visited[i] = new int[cols];   //each row points to a new array

    for(int j = 0; j < rows; j++)
    {
        for(int h = 0;h < cols;h++)
        {
            visited[j][h] = 0;
            //cout << visited[j][h];
        }
    }
    
    return visited;
    delete [] visited;
}
void determineDirection(char **array, int **visits, int x, int y)
{
    //find closest node to x and y that has been visited, either up down left or right
    int vx; //visited x
    int vy; //visited y

    if(x != 0 && visits[x-1][y] == 1 && array[x][y] != 'S') // final movement down
    {
        array[x][y] = 'v';
    }
    else{}
     if(x != rows-1 && visits[x+1][y] == 1 && array[x][y] != 'S') // final movement up
    {
        array[x][y] = '^';
    }
    else{}
    if(y != 0 && visits[x][y-1] == 1 && array[x][y] != 'S') // final movement right
    {
        array[x][y] = '>';
    }
    else{}
    if(y != cols-1 && visits[x][y+1] == 1 && array[x][y] != 'S') // final movement left
    {
        array[x][y] = '<';
    }
    else{}
}
