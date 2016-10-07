/**
~ Clariz Mariano
PSET2: Caesar
Substitutes user's inputted string with an integer passed from the console.
**/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int indexUpper = 65;
int indexLower = 97;
char TranslateLetter(int, int);
int argNumberCheck(int);


int main(int argNumber, string cyphernumber[])
{
    argNumberCheck(argNumber);
    
    char* plaintext = GetString();
    
    //checks if a key number is passed from the console
 
    int length = strlen(plaintext);
    int key = atoi(cyphernumber[1]);
    
    for (int i = 0; i < length; i++)
    {
        char translate = plaintext[i];

        // check if char is a letter
        if (isalpha(translate)) 
        {
          TranslateLetter(translate, key) ;

        }
        // if not, normally print it
        else 
        {
            printf("%c", translate);
        }
       
    }
       printf("\n");
}
       char TranslateLetter( translate, key) 
       {
         //  char translateChar;
           int indexChar;      
  
            if (isupper(translate))
            {
                indexChar = indexUpper;
            }
            if (islower(translate))
            {
                indexChar = indexLower;
            }
            
                    
        
        
  // find alpha index of cipher
            key = ((translate - indexChar) + key) % 26;

   // convert back to ASCII index of cipher
            char translatedtext;
            translatedtext = indexChar + key;

            printf("%c", translatedtext);

   return 0;        
}

int argNumberCheck (int argNumber) 
    {
    if(argNumber == 2) 
        {
        return 0;

  // this program was executed with too few console arguments.
    } else if(argNumber < 2) 
        {   
        printf("You need a number, dumbass.\n");
    //    return 1;
        exit(1);


    } else 
        {
        printf("You put too much number!\n");
       // return 1;
        exit(1);
    }
}