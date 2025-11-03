# hangman working on it to make the game basics 
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>//used for rand() and srand()
    #include <time.h>//new stuff for randomization


    void check(char array[]) {

    srand(time(NULL));

    char str[3][100] = {"hello", "result", "world"};
    int count=3;
    int ans=rand()%count;
    char strans[100];
    strcpy( strans,str[ans]);

    printf("\n(Secret word was: %s)\n", strans); 

    int found = 0;

    //for (int i = 0; i < 3; i++) {
        if (strcmp(array, strans) == 0) {
            found = 1;

        }
    

    if (found)
        printf("wow good guesser.\n");
    else
        printf("well game over.\n");
    }
    int main() {
    printf("lets play a game of guesses.\n");
    printf("from this list of words: hello, result, world, programming, engineer, death\n");
    printf("try to guess one of the words.\n");
    char array[100];
    printf("Enter the string: ");
    scanf("%s", array);

    check(array);
    return 0;
    }

just completed this much

log 2 
next chnages that occured quite a mess but did some stuff as time was less with testa and all 

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>//used for rand() and srand()
    #include <time.h>//new stuff for randomization

    /*keywords used
    strans1 to print blanks 
    strans answer word 
    str all the options
    count no of options
    compare to compareee*/
    void compare(char array[], char strans[])       
    {
    for (int i=0;i<strlen(strans);i++)
    {
        if (array[i]==strans[i])
        {
            printf("%c",array[i]);
        }
        else
        {
            printf("_");
        }
    }
    }
    char blank(char strans1[])
    {   
    int a =strlen(strans1);
    printf("your word is of length %d\n",a);
    
    for (int i=0;i<a;i++){
        printf("_ ");
    }
    printf("\n");
    printf("\n");
    return 0;
    }

    void check(char array[],char strans[]) 
    {
    printf("\n(Secret word was: %s)\n", strans); 

    int found = 0;

    //for (int i = 0; i < 3; i++) {
        if (strcmp(array, strans) == 0) 
        {
            found = 1;
        }
    if (found)
        printf("wow good guesser.\n");
    else
        printf("well game over.\n");
    }

    int main() {
    printf("lets play a game of guesses.\n");
    printf("from this list of words: hello, result, world, programming, engineer, death\n");
    printf("try to guess one of the words.\n");
    char array[100];
    
    srand(time(NULL));

    char str[3][100] = {"hello", "result", "world"};
    int count=3;
    int ans=rand()%count;
    char strans[100];
    
    strcpy( strans,str[ans]);
    blank(strans);
    printf("Enter the string: ");
    scanf("%s", array);
    compare(array, strans);
    check(array,strans);
    return 0;
    }
