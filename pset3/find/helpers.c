/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <math.h>
bool BinaryRecursiveSearch(int x, int val[], int y, int z, int n);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);

    int pass_counter = 0;
    int needlefound = 0;
        int originalmax = 0;


/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int xneedle, int xhaystack[], int size)
{
    int min = 0;
    int max = size;
    int halved = 0;
    return BinaryRecursiveSearch(xneedle, xhaystack, min, max, halved);
}

bool BinaryRecursiveSearch(int xneedle, int xhaystack[], int min, int max, int halved)
 {
    if (halved == 0 && pass_counter == 0) 
    {
        originalmax = max;
        halved = round((max+1)/2);
    } 
    else if (max == min)
    {
        halved = max;
    }

     if (pass_counter == originalmax+1)
     {
         return false;
     }  

    pass_counter++;

    if (xhaystack[halved] == xneedle)
    {
        needlefound = 1;
    }
  
    else if (xhaystack[halved] > xneedle) 
    {
        if (max == min)
        {
          halved = max;
        }
        else 
        {
            max = halved - 1 ;
            halved = round(max/2);
    }
    return BinaryRecursiveSearch(xneedle, xhaystack, min, max, halved);
    }
    
    else if (xhaystack[halved] < xneedle ) 
    {
        if (max == min)
        {
            halved = max;
        }
        else 
        {
        min = halved + 1;
        halved = halved + (max+1-min)/2;
        }
    return BinaryRecursiveSearch(xneedle, xhaystack, min, max, halved);
    }
    
    
    if (needlefound == 1)
        {
            return true;
        }
     else  
        {   
            return false;
        }
        
     
// Linear Search
//    int needlefound = 0;
//         printf("xneedle: %i \n", xneedle);
//            printf("size: %i \n", xsize);

//    for  (int i = 0; i <= xsize; i++)
//        {
//            printf("xhaystack[%i]%i \n", i, xhaystack[i]);
//            if (xhaystack[i] == xneedle) 
//            {
//            needlefound = 1;
//            return true;
//            }

}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int nochanges = 0;
    int tmpholder = 0;
    int swapcounter = 1;
    int mastercounter = 0;
//                printf("start\n");
//                printf("n = %i\n", n);
int p = 0;


    do {
 //          printf("tmpholder: %i here at do loop \n", tmpholder);
//         printf("BEFORE @for loop: p = %i, n = %i, \n~~~~~~~~\n",p, n);

     for (p = 0; p < n && nochanges != n; p++) 
     {
 //        printf("\n@for loop: p = %i, n = %i, \n~~~~~~~~\n",p, n);
//         printf("%i AND %i\n", values[p+1], values[p]);

         if (values[p+1] < values[p])
         {
             mastercounter++;

             tmpholder = values[p+1];
//          printf("p value %i here at IF loop \n", p);
  
//           printf("tmpholder %i\n", tmpholder);
//           printf("before array%i: %i | array%i: %i \n", p, values[p], p+1, values[p+1]);

           values[p+1] = values[p];
           values[p] = tmpholder;
           swapcounter++;
             nochanges--;


       }
         
         else if (values[p+1] > values[p] && nochanges != n && p <= n)
         {
             nochanges++;
 //                  printf("~~~~~nochanges %i\n", nochanges);

         }
         if (p == n) {
                 swapcounter = 0; // reset

         }
     }
//                   printf("~~~~~swapcounter %i\n", swapcounter);


    }  while (swapcounter !=0 && nochanges != n );

// print
        for (int r = 0; r <= n; r++) 
        {
          //  printf("values[%i] %i\n", r, values[r]);
        }
}
