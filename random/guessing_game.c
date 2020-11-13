// practicing loops, functions, variables
// a game that asks the user to guess a randomly generated number
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// function to create a random number
// learned from stackoverflow :)
int generate_random_number()
{
    srand(time(NULL)); 
    int r = rand() % 11; //divide any random number by 11 and returns its remainder
    return r;
    
}

int main()
{
    int user_guess;
    int target_number = generate_random_number();
    int guess_limit = 3;

    
    while (user_guess != target_number)
    {
        printf("I am thinking of a number between 0 to 10. Guess my number?\n you have %d guesses left\n", guess_limit);
        scanf("%d", &user_guess);
        guess_limit--;

        if (guess_limit == 0)
        {
            printf("sorry, you're out of guesses\n");
            break;
        }
    }

    if (user_guess == target_number)
    {
        printf("yes, you guessed right!");
    }

    printf("\nmy guess was %d", target_number);
    return 0;
}