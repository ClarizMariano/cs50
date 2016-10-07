/**
~ Clariz Mariano
PSET1: Mario Pyramid
Prints a right-aligned pyramid with blocks based from user input. 
Blocks can only be between 1-23 rows.
**/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
int NumberCheck = -1;

while (NumberCheck == -1)
{
    printf("Height: ");
    int Height = GetInt();
    
    if (Height < 24 && Height > -1)
    {
        NumberCheck =  Height;   
        for (int i = 0; i < Height; i++)
        {
        int BlankSpaceCtr = 0;
        int HashCtr = 0;
        int BlankSpaceNeeded = Height - i - 1;

        //print spaces
        while (BlankSpaceCtr < BlankSpaceNeeded)
        {
            printf(" ");
            BlankSpaceCtr++;
        }
     
            
        //print hashes
        do {
            printf("#");
            HashCtr++;
        } while (HashCtr < i+1);
    
        //print new line
        printf("#");
        printf("\n");
        }
    }
}
}