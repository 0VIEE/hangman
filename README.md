# Hangman in C

A small, terminal-based word-guessing game written in C. Guess the hidden word one letter at a time before using all six incorrect attempts.

## Features

- Random word selection from a built-in word list
- Letter-by-letter guessing with revealed letters
- Case-insensitive input
- Detection of repeated guesses
- Validation for invalid input
- Option to play multiple rounds
- No external libraries required

## Requirements

- A C compiler, such as GCC or Clang
- A terminal or command prompt

## Build and run

### Linux or macOS

Compile the game:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror -O2 main.c -o hangman
```

Run it:

```bash
./hangman
```

If you have `make` installed, you can also use:

```bash
make
make run
```

### Windows with MinGW-w64 GCC

Open PowerShell in the project folder and run:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror -O2 main.c -o hangman.exe
.\hangman.exe
```

## How to play

1. The game selects a random word.
2. Enter one letter each turn.
3. Correct guesses reveal every occurrence of that letter.
4. An incorrect guess uses one of your six attempts.
5. Guess the complete word before you run out of attempts to win.
6. Choose whether to start another round when the game ends.

Repeated letters and invalid input do not use an attempt.

## Project structure

```text
hangman/
├── .github/
│   └── workflows/
│       └── ci.yml
├── .editorconfig
├── .gitignore
├── Makefile
├── README.md
└── main.c
```

## What this project practises

This project is an exercise in C fundamentals, including functions, arrays, strings, loops, character handling, input validation, and basic random number generation.

The word list is defined near the top of `main.c`. You can add or change words there.

---

Built as a learning project while practising C programming.
