/**
~ Clariz Mariano
PSET2: Initials
Gets the first characters of a string with multiple words.
User inputss a tring of words, then program splits each words into an array, delimited by " ". Then print the first char of each array element
 **/


#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
 //   printf("Name: ");
    string name = GetString();

// count occurence of " " to initialize array
    int i = 1; // i = # of names
    char *countspace=strchr(name,' ');
    while (countspace!=NULL) {
    i++;
    countspace=strchr(countspace+1,' ');
  }

  //  printf("%i\n", i); // for debugging
    string words[i]; // initialize array
    int y = 0;
    string token = strtok(name, " ");

    while (token != NULL)
    {
       // string initial = toupper(* token);
        words[y] = token; y++;
        token = strtok (NULL, " ");
    }
    
// print first letter per array element    
    for(int z = 0; z < i; z++)
    {
        string initial = words[z];
        char firstletter = initial[0];
        firstletter = toupper(firstletter);
        printf ("%c",firstletter);
    }
        printf ("\n");
}