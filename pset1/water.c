/**
~ Clariz Mariano
PSET1: Water
Computes number of bottles consumed based on user-input minutes of shower.
**/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Minutes of Shower: ");
    int mins = GetInt();
    int bottles = mins * 12;
    printf("Bottles of Water Used: %i\n", bottles);
}