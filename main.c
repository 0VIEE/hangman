#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MISTAKES 6

static const char *const words[] = {
    "hello", "result", "world", "programming", "engineer",
    "computer", "algorithm", "developer", "keyboard", "function"
};

static int read_line(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) == NULL) {
        return 0;
    }

    if (strchr(buffer, '\n') == NULL && !feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
    }

    buffer[strcspn(buffer, "\r\n")] = '\0';
    return 1;
}

static void display_word(const char *word, const int guessed[26])
{
    for (size_t i = 0; word[i] != '\0'; ++i) {
        if (i > 0) {
            putchar(' ');
        }

        if (guessed[word[i] - 'a']) {
            putchar(word[i]);
        } else {
            putchar('_');
        }
    }
    putchar('\n');
}

static int is_word_guessed(const char *word, const int guessed[26])
{
    for (size_t i = 0; word[i] != '\0'; ++i) {
        if (!guessed[word[i] - 'a']) {
            return 0;
        }
    }
    return 1;
}

/* Returns 1 for a valid guess, -1 for invalid input, and 0 for end-of-input. */
static int read_guess(char *guess)
{
    char input[128];

    printf("Guess a letter: ");
    if (!read_line(input, (int)sizeof input)) {
        return 0;
    }

    if (strlen(input) != 1 || !isalpha((unsigned char)input[0])) {
        puts("Please enter exactly one letter (A-Z).");
        return -1;
    }

    *guess = (char)tolower((unsigned char)input[0]);
    return 1;
}

static void play_round(void)
{
    const size_t word_count = sizeof words / sizeof words[0];
    const char *word = words[(size_t)rand() % word_count];
    int guessed[26] = {0};
    int mistakes = 0;

    printf("\nA new word has been selected (%zu letters).\n", strlen(word));

    while (mistakes < MAX_MISTAKES && !is_word_guessed(word, guessed)) {
        char guess;
        int result;

        display_word(word, guessed);
        printf("Mistakes: %d/%d | Attempts left: %d\n",
               mistakes, MAX_MISTAKES, MAX_MISTAKES - mistakes);

        result = read_guess(&guess);
        if (result == 0) {
            puts("\nInput ended. Closing the game.");
            return;
        }
        if (result < 0) {
            continue;
        }

        if (guessed[guess - 'a']) {
            puts("You already guessed that letter.");
            continue;
        }

        guessed[guess - 'a'] = 1;

        if (strchr(word, guess) != NULL) {
            puts("Good guess!");
        } else {
            ++mistakes;
            puts("That letter is not in the word.");
        }
    }

    display_word(word, guessed);
    if (is_word_guessed(word, guessed)) {
        puts("\nYou win! You found the word.");
    } else {
        printf("\nNo attempts left. The word was \"%s\".\n", word);
    }
}

static int play_again(void)
{
    char input[32];

    for (;;) {
        printf("\nPlay again? (y/n): ");
        if (!read_line(input, (int)sizeof input)) {
            return 0;
        }

        if (strlen(input) == 1) {
            char answer = (char)tolower((unsigned char)input[0]);
            if (answer == 'y') {
                return 1;
            }
            if (answer == 'n') {
                return 0;
            }
        }

        puts("Please enter y or n.");
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));

    puts("====================================");
    puts("             HANGMAN");
    puts("====================================");
    puts("Guess the hidden word one letter at a time.");
    printf("You can make up to %d incorrect guesses.\n", MAX_MISTAKES);

    do {
        play_round();
    } while (play_again());

    puts("Thanks for playing!");
    return 0;
}
