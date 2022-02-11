# my_mastermind

Welcome to my implementaiton of the famous mastermind game in the C programming language. 
This project was completed on November 5th, 2021.

## Description

Mastermind is a game composed of 8 different colors.
For this implementation it was composed of 8 different numbers. Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.
A secret code is then composed of 4 different pieces.

By default the player has 10 attempts to find the secret code.
After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

If the player finds the code, he wins, and the game stops.

## Usage

To compile the program enter the below command:

`$ make my_mastermind`

There are a few ways to run the program. See example below:

`$ ./my_mastermind -c 1735 -t 15`

where 1735 is the secret code(-c) specified and 15 is the number of attempts (-t).

Feel free to specify your own code and number of attempts if desired.

No entry will result in a randomly generated code and a default of 10 attempts. Good Luck!