/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 * continued by Clariz Mariano
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];
int winboard[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(int d);
void draw(int d);
bool move(int tile);
bool won(int d);
int col0;
int row0;


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    //int biggestnumber = d*d - 1;
    
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init(d);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(d);

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won(d))
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(d)

{
    col0 = d-1;         // first init of 0
    row0 = d-1;
    
    int number = d*d - 1; // starts off as the biggest number
    
    int even_tiles = d%2;
    //printf("even tiles? %i\n", even_tiles);
    for (int r = 0; r <= d-1; r++) 
        {
        for (int c = 0; c <= d-1; c++) 
            {
            //printf("number: %i\n",  number);
            if (even_tiles == 0 && number == 2)
                {
                //printf("number two %i\n", even_tiles);
                board[r][c] = 1;
                }
            else if  (even_tiles == 0 && number == 1)
                {
                board[r][c] = 2;
                // printf("number one %i\n", even_tiles);
                }
            else
                {
                board[r][c] = number;
//              printf("board[%i][%i] %i\n", r,c, board[r][c]);
                }
        number--;
        }
    }
    
// initializes winning arrangement
    int largestnumber = 0;
    //printf("even tiles? %i\n", even_tiles);
    for (int r = 0; r <= d-1; r++) 
        {
        for (int c = 0; c <= d-1; c++) 
            {
                if (d-1 == r && d-1 == c )  //for 0 at the end
                    {
//                  printf("board[%i][%i] %i\n", r,c, board[r][c]);
                    winboard[r][c] = 0; 
               //     printf("winboard[%i][%i] %i\n", r,c, winboard[r][c]);

                    }
                else
                    {
                    winboard[r][c] = largestnumber+1; // square must start at 1, not 0
                //    printf("winboard[%i][%i] %i\n", r,c, winboard[r][c]);
                
                    }
        largestnumber++;
            }

        }
    }
    
    


/* Prints the board in its current state.
 */

void draw(d)
{
    for (int r = 0; r <= d-1; r++) 
        {
        for (int c = 0; c <= d-1; c++)
            {
            if ( board[r][c] == 0)
            {
            printf("__ ");
            }                
            else 
            {
            printf("%2d ", board[r][c]);
            }
            }
        printf("\n");

        }    
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // search the tile's position
//    printf("row0 [%i]  col0: [%i]: %i \n", row0, col0, board[row0][col0]);

    for (int r = 0; r <= d-1; r++) 
        {
        for (int c = 0; c <= d-1; c++)
            {
            if (board[r][c] == tile)
                {
                    // checks if tile's position is valid for moving
                    if ((r == row0 && c == col0-1) || 
                        (r == row0-1 && c == col0) || 
                        (r == row0 && c == col0+1)  ||
                        (r == row0+1 && c == col0))
                        {
                        if (c == col0 || c == col0-1 || c == col0+1)
                            {
                            //    printf("~~~~~~~~\n\nboard[%i][%i]: %i \n", row0, col0, board[row0][col0]);
                            //    printf("board[%i][%i]: %i \n", r, c, board[r][c]);
                                // switch positions of tile with 0
                                board[r][c] = 0;
                                board[row0][col0] = tile;
                                // update 0's pos
                                row0 = r;
                                col0 = c;
                                return true;
                            }
                        }
                }
            }
        }    
    
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(int d)
{
    // compare the winning array against the current board array
    int correctctr = 0;
    for (int r = 0; r <= d-1; r++) 
        {
        for (int c = 0; c <= d-1; c++) 
            {
            if (board[r][c] == winboard[r][c])
                {
 //                   printf("board[%i][%i] = %i == %i winboard[%i][%i] \n", r,c, board[r][c], winboard[r][c],r,c );
 //                   printf("\nTRUE correctctr: %i & %i\n",correctctr, d*d-1 );
                    
                correctctr++;
                }
            // the exception for 0 at the end
            else if (d-1 == r && d-1 == c && winboard[r][c] == 0) 
                {
                correctctr++;
                }                
            else
                {
                 return false; 
                }    
            }
        }
        
    if (correctctr == d*d)
    {
   //     printf("\n~~~~TRUE correctctr: %i & %i\n",correctctr, d*d-1 );
        return true;
    }
    else 
    {
        return false; 
    }
    //        printf("\ncorrectctr: %i & %i\n",correctctr, d*d-1 );

}