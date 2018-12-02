#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Scrabble score calculator. Input your word letter by letter\n How many letters is your word long?\n");
    char letter;
    int points = 0;
    int lenght;
    scanf("%d", &lenght);
    lenght = lenght * 2;
    for(int i = 0; i < lenght; i++) {
        scanf("%c", &letter);
        switch(letter) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'l':
        case 'n':
        case 'r':
        case 's':
        case 't':
            points++;
            break;
        case 'd':
        case 'g':
            points = points + 2;
            break;
        case 'b':
        case 'c':
        case 'm':
        case 'p':
            points = points + 3;
            break;
        case 'f':
        case 'h':
        case 'v':
        case 'w':
        case 'y':
            points = points + 4;
            break;
        case 'k':
            points = points + 5;
            break;
        case 'j':
        case 'x':
            points = points + 8;
            break;
        case 'q':
        case 'z':
            points = points + 10;
            break;
        }
    }
    printf("Your word is worth: %d points", points);
    return 0;
}
