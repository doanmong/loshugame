#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printSquare(int square[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",square[i][j]);
        }
        printf("\n");
    }
}

int isMagicSquare(int square[3][3]){
    //Storing sum of first row in val, and comparing it with all the other values
    int val = 0,tempVal = 0;
    //Checking first row
    for (int i = 0; i < 3; i++)
    {
        val = val + square[0][i];
    }

    //Checking 2nd and 3rd row
    for (int i = 1; i < 3; i++)
    {
        tempVal = 0;
        for (int j = 0; j < 3; j++)
        {
            tempVal = tempVal + square[i][j];
        }
        if (tempVal != val)
        {
            return 0;
        }  
    }

    //Checking all columns
    for (int i = 0; i < 3; i++)
    {
        tempVal = 0;
        for (int j = 0; j < 3; j++)
        {
            tempVal = tempVal + square[j][i];
        }
        if (tempVal != val)
        {
            return 0;
        }  
    }
    
    //Cheking diagonals
    tempVal = 0;
    for (int i = 0; i < 3; i++)
    {
        tempVal = tempVal + square[i][i];
    }
     if (tempVal != val)
    {
        return 0;
    }

    tempVal = square[0][2] + square[1][1] + square[2][0];    
     if (tempVal != val)
    {
        return 0;
    }

    return 1;
    
}

int main(){
    int square[3][3];
    int count = 0; //Count of squares that are generated
    while (1)
    {        
        count++;
        int used[10] = {0};
        srand(time(0)+count); // Changing seed , so that we get new values each time
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int n = rand()%9 + 1;
                while (used[n])
                {
                    n = rand()%9 + 1;
                }
                square[i][j] = n;
                used[n] = 1;
            }
        }

        /*//UNCOMMENT to see all squares that generated
        printf("No. of squares generated : %d \n",count);
        printSquare(square);*/

        //Breaks the loop if a magic square is found
        if(isMagicSquare(square) == 1){
            break;
        }
    }

    printf("No. of squares generated : %d \n",count);

    printSquare(square);
    return 0;
}