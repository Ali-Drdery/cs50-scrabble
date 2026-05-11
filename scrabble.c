#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// points for letters A-Z
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score_word(string word);

int main(void)
{
    // get words from players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // calculate scores
    int score1 = score_word(word1);
    int score2 = score_word(word2);

    // decide winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// function to calculate score
int score_word(string word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        // uppercase letters
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }

        // lowercase letters
        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }

    return score;
}