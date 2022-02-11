#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

//function to read user input
void my_get (char* input)
{
    read(0, input, 32);
}

//function to generate a random 4 digit code from 0000 to 7777
void generateCode (char* code)
{
    srand(time(NULL));
    char arrayNumber[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    int i;
    for (i = 0; i < 4; i++)
    {
        code[i] = arrayNumber[(rand() % 8)];
    }
}

//function to check if input is number from 0-7
int my_isDigit (char input)
{
    if (input > 057 && input < 070) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

int main(int argc, char** argv)
{

    int attempts = 0;
    int defaultAttempts;
    int inputTest = 0;
    char guess[32];
    char secretCode[32];

    //Check to see if attempts specified, if not set to 10
    if (argc == 5)
    {
        defaultAttempts = atoi(argv[4]);
    }
    else
    {
        defaultAttempts = 10;
    }

    //If no code specified, random code generated
    if (argc != 3 && argc != 5)
    {
        printf("Random Secret Code Generated. Game on!\n");
        generateCode(secretCode);
    }

    //If secret code is does not contain 4 digits from 1-7, random code generated
    else
    { 
        for (int i = 0; i<4; i++)
        {
            inputTest += my_isDigit(argv[2][i]);
        }
        if (inputTest != 4)
        {
            printf("Invalid Secret Code, Random Secret Code Generated. Game on!\n");
            generateCode(secretCode);
        }
        else if (inputTest == 4)
        {
            for (int i = 0; argv[2][i] != '\0'; i++)
            {
                secretCode[i] = argv[2][i];
            }
        }
    }

    //Start of Game
    printf("Will you find the secret code?\n");
    while (attempts < defaultAttempts)
    {
        printf("---\nRound %d\n",attempts);
        do
        {
            printf("Please enter a valid guess\n");
            my_get(guess);
        }
        while (my_isDigit(guess[0]) != 1 || my_isDigit(guess[1]) != 1 || my_isDigit(guess[2]) != 1 || my_isDigit(guess[3]) != 1 );

        int RNRP = 0; 
        int RNWP = 0; 
        int remainCode[5];
        int remainGuess[5];
        int j = 0;

        //Loop to check Right Number Right Place
        for (int i = 0; i<4; i++)
        {
            if(guess[i] == secretCode[i])
            {
                RNRP += 1;
            }
            if(guess[i] != secretCode[i])
            {
                remainCode[j] = secretCode[i];
                remainGuess[j] = guess[i];
                j++;
            }
        }
        
        //Loop to check Right Number Wrong Place
        for (int k = 0; k< 4-RNRP; k++)
        {
            for (int l = 0; l<4-RNRP-RNWP ; l++)
            {
                if(remainGuess[k] == remainCode[l])
                {
                    RNWP +=1;
                    remainCode[l] = remainCode[l+1];
                }
            }
        }
        if (RNRP != 4)
        {
            printf("Well placed pieces: %d\n", RNRP);
            printf("Misplaced pieces: %d\n", RNWP);
        }
        if (RNRP == 4)
        {
            printf("Congratz! You Crushed it!\n");
            return 0;
        }
        attempts++;
    }
    if (attempts == defaultAttempts)
    {
        printf("Sorry friend, today is not your day. Please re-run program to try again!");
        return 0;
    }
}