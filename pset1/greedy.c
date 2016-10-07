/**
~ Clariz Mariano
PSET1: Greedy
User inputs a number and the code below calculates the 
least number of coints to given to the 
**/
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{


int CoinsNeeded = 0;
int QuarterCtr = 0;           // 25c
int DimeCtr = 0;              // 10c
int NickleCtr = 0;            // 5c
int PennyCtr = 0;             // 1c
int NumberCheck = -1;

while (NumberCheck == -1) {

    printf("O hai! How much change is owed? \n");

    float Change = GetFloat();
    int Cents = round(Change * 100);

    if ( Cents > 0 ){
        
        NumberCheck = 0;

        if (Cents >= 25)
        {
            QuarterCtr = Cents/25;
            Cents = Cents%25;
            
        }   

        if (Cents < 25 && Cents != 0)
        {

            DimeCtr = Cents/10;
            Cents = Cents%10;
        } 
        
        if (Cents < 10 && Cents != 0)
        {
            NickleCtr = Cents/5;
            Cents = Cents%5;
            
        } 
        
        if (Cents < 5 && Cents != 0)
        {
            PennyCtr = Cents; ///1;

        } 
}

CoinsNeeded = QuarterCtr + DimeCtr + NickleCtr + PennyCtr;

 printf("%d\n", CoinsNeeded);

// for debugging 
//printf("qtr %d\n", QuarterCtr);
//printf("dime %d\n", DimeCtr);
//printf("nickle %d\n", NickleCtr);
//printf("penny %d\n", PennyCtr);
}
}
