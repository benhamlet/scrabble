// A program to take a scrabble word from 2 players and return who wins.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes for my functions outside of main.
string conv_upper(string word);
int return_score(char wordupper[], int wordlength, char alphabetarray[], int score[]);

// Constant integer for numbers of letters in alphabet.
const int N = 26;

int main(void)
{
    // Arrays set for letters of the alphabet and value of each scrabble tile. Each location corresponds to
    // the other.
    char letter[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int score[N] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Variables to take an input from player 1, convert the input to upper case and then store length of
    // word.
    string player1 = get_string("Player 1: What is your word? ");
    string player1u = conv_upper(player1);
    int player1len = strlen(player1);
    // Variables to take an input from player 2, convert the input to upper case and then store length of
    // word.
    string player2 = get_string("Player 2: What is your word? ");
    string player2u = conv_upper(player2);
    int player2len = strlen(player2);

    // variables to record scores of each player after calling return_score function.
    int score1 = return_score(player1u, player1len, letter, score);
    int score2 = return_score(player2u, player2len, letter, score);

    // Conditional statements to determine winner, or if it is tied.
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Function to convert a string to uppercase.
string conv_upper(string word)
{
    // Create a loop through the length of the word and convert each character to upper case, returning word.
    for (int i = 0; word[i]; i++)
    {
        word[i] = toupper(word[i]);
    }
    return word;
}

// Create a function to take multiple inputs and return the scrabble score for a given word.
int return_score(char wordupper[], int wordlength, char alphabetarray[], int score[])
{
    int wordscore = 0;
    int i = 0;
    // Loop for the number of letters in the word
    for (; i < wordlength; i++)
    {
        // Nested loop for checking each letter, if it matches the alphabet array, it adds the value from the
        // score array to wordscore variable.
        for (int j = 0; j < N; j++)
        {
            if (wordupper[i] == alphabetarray[j])
            {
                wordscore = wordscore + score[j];
            }
        }
        int j = 0;
    }
    return wordscore;
}
