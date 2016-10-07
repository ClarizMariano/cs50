/**
~ Clariz Mariano
PSET1: Vigenere
User inputs a cipher key from the console and text to be translated.
Program encrypts the text using the charaters from the cipher key,
procedurally from the first char to the last, then cycles again, until
all of the characters from the text is translated.
**/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int indexUpper = 65;
int indexLower = 97;
int numericfound = 0;
char TranslateLetter(int, string, int);
int argNumberCheck(int);
int GetKey(char);
int cyphertextCheck(string);


int main(int argNumber, string cyphertext[])
{
    //checks if there is only one key is passed from the console
    argNumberCheck(argNumber);
    string key = cyphertext[1];
    //checks if the first argument is all alphabeth
    cyphertextCheck(key);
    char* plaintext = GetString();
    int length = strlen(plaintext);
         int revolvingkey = 0;   
    for (int i = 0; i < length; i++)
    {
        char translate = plaintext[i];
        // check if char is a letter
        if (isalpha(translate)) 
        {
            //    printf("\n translate: %c | key: %s |revolvingkey: %i\n",translate, key, revolvingkey);
                TranslateLetter(translate, key, revolvingkey) ;
                revolvingkey++;
        }
        // if not, normally print it
        else 
        {
            printf("%c", translate);
        }
    }
       printf("\n");
}
       char TranslateLetter(int translate, string key, int revolvingkey) 
       {
         //  char translateChar;
            int indexChar;      
            int keylength = strlen(key);
            int keyplace = revolvingkey % keylength;

            if (isupper(translate))
            {
                indexChar = indexUpper;
            }
            if (islower(translate))
            {
                indexChar = indexLower;
            }
      // find alpha index of cipher
            int newkey = key[keyplace] - indexChar;

            if (isupper(key[keyplace]) && (islower(translate)))
            {
                indexChar = indexLower;
                newkey = (tolower(key[keyplace])) - indexChar;

//               printf("such is true\n");
            }

//               printf("key[keyplace] %i \n", key[keyplace]);

//               printf("newkey %i \n", newkey);

      int keypass = ((translate + newkey) - indexChar) % 26;
//               printf("keypass %i \n", keypass);
//               printf("to be translated %i  \n", translate);
//               printf("indexchar %i  \n", indexChar);


   // convert back to ASCII index of cipher
            char translatedtext;
            translatedtext = indexChar + keypass;

            printf("%c", translatedtext);

   return 0;        
}

// Handles if the characters in the cipher key are not alphabeth
int cyphertextCheck(string key)
{
        int klength = 0;
        klength = strlen(key);
     //   int numericfound = 0;
    for (int k = 0; k < klength; k++)
    {
        char checkkey = key[k];
        // check if char is a letter
        if (isalpha(checkkey)) 
        {
          //  printf("%c, %i | %i\n", checkkey, numericfound, k);
            numericfound = 0;
        } else {
            numericfound = 1;
       //     printf("%c, %i \n", checkkey, numericfound);
            printf("Keyword must only contain letters A-Z and a-z.\n");
           // exit(1);
        }
    }
    if (numericfound == 1)
    {
        
            printf("Keyword must only contain letters A-Z and a-z.\n");
            exit(1);
    }
    else {
     return(0);
}}


// Handles if there is no cipher key
int argNumberCheck (int argNumber) 
{
    if(argNumber == 2) 
        {
        return 0;

// Handles when there is more than 1 argument
    } else if(argNumber < 2) 
        {   
        printf("You need a key.\n");
    //    return 1;
        exit(1);
    } else 
        {
        printf("You just need one key!\n");
       // return 1;
        exit(1);
    }
    return 0;
}