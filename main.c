//
//  main.c
//  Roulette
//
//  Created by Alessandro Carmelo Chiarelli on 05/11/2018.
//  Copyright © 2018 Alessandro Carmelo Chiarelli. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMBERS 38
#define ZZ 37

int main() {
    // insert code here...
    //follow rules from wikipedia for American Roulette
    //We accept only simple bets: red and black, odd or even, single number, manque ou passe
    //currently only for one player
    //ideas for further versions:
    //1) using array to make a list of n players (that will be printed as player 1, 2 etc)
    //2) allow other types of bet
    //3) make a starting money, like a balance, so that there is a game over at some point
    printf("+-----------------------------------------------------------------------------------------+\n");
    printf("|                               American Roulette game                                    |\n");
    printf("|                                    version:1.0                                          |\n");
    printf("|(C) alexcarchiar, realised as an exercise                                                |\n");
    printf("|This is a simple one player game, place your bet and good luck!                          |\n");
    printf("|Remark that for the current version only simple bets are allowed.                        |\n");
    printf("+-----------------------------------------------------------------------------------------+\n");
    int user_bet;
    int flag_rouge = 0;
    int flag_noir = 0;
    int pair_ou_impair;
    int money, winner_number, user_number;
    //in order to have the '00' cell, we write 'ZZ'
    int roulette[NUMBERS];
    for(int i = 0; i<(NUMBERS - 1); ++i)
        roulette[i] = i;
    roulette[NUMBERS-1] = ZZ;
    //let's create two arrays for Rouge ou Noir
    int rouge[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    int noir[] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
    char user_choice = 0;
    while (user_choice != 'q' && user_choice != 'Q'){ //end condition
        printf("\nPress C to continue, press R to show rules, press Q to quit.\n"); //condition for user choice
    scanf("%c", &user_choice);
        if (user_choice == 'r' || user_choice == 'R'){ //show rules
            printf("The rules are simple: you place your bet. There are 38 numbers going from 0 to 36 and 00. There are different types of bets:\n");
            printf("1) Plein (single number): you bet on a single number. Potential gain: 35 times your bet;\n");
            printf("2) Pair ou Impair (odd or even): you bet on all even numbers or on all odd numbers except 0 and 00. Potential gain: your bet;\n");
            printf("3) Rouge ou Noir (red or black): you bet on all red numbers or all black numbers (remember that 0 and 00 are green). Potential gain: your bet;\n");
            printf("4) Manque ou Passe: you bet on all numbers from 1 to 18 (Manque) or from 19 to 36 (Passe). Potential gain: your bet;\n");
            printf("5) Cheval vert (green horse): you bet on 0 and 00 couple. Potential gain: 17 times your bet.\n");
            printf("In the following versions of this game I will add the other types of bets.\nFor the commands, keep in mind that the console will always show you how to proceed\n");
        }else if(user_choice == 'c' || user_choice == 'C'){ //play game
            printf("What type of bet do you wanna place? Press: \n"); //show all possibilities, will be the same in switch
            printf("1 for Plein\n");
            printf("2 for Pair ou Impair\n");
            printf("3 for Rouge ou Noir\n");
            printf("4 for Manque ou Passe\n");
            printf("5 for Cheval vert\n");
            scanf("%d", &user_bet);
            srand(time(NULL));
            winner_number = rand() % NUMBERS;
            printf("How much are you betting?\n");
            scanf("%d", &money);
            switch(user_bet){
                case 1:
                    printf("On which number do you place your bet? (Type %d for 00)\n", ZZ);
                    scanf("%d", &user_number);
                    if(user_number == winner_number){
                        money *= 35;
                        printf("Wow! You won %d", money);
                    } else{
                        printf("You lost! That happens when you gamble\n");
                        printf("The winner number was: %d\n", winner_number);
                    }
                    break;
                case 2:
                    printf("Press 1 for Pair or 2 for Impair");
                    scanf("%d", &pair_ou_impair);
                    if(pair_ou_impair==1){
                        if((winner_number % 2) == 0){
                            printf("Wow! You won %d", money);
                        } else if((winner_number % 2) == 1){
                            printf("You lost! That happens when you gamble\n");
                            printf("The winner number was: %d\n", winner_number);
                        }
                    } else if(pair_ou_impair ==2){
                        if((winner_number % 2) == 1){
                            printf("Wow! You won %d", money);
                        } else if((winner_number % 2) == 0){
                            printf("You lost! That happens when you gamble\n");
                            printf("The winner number was: %d\n", winner_number);
                        }
                    }
                    break;
                case 3:
                    printf("Press 1 for Rouge or 2 for Noir"); //it's the same as pair ou impair, too lazy to change name of variable
                    scanf("%d", &pair_ou_impair);
                    for(int i = 0; i < 18; ++i){
                        if(winner_number == rouge[i]){
                            flag_rouge = 1;
                        }
                        if(winner_number == noir[i]){
                            flag_noir = 1;
                        }
                    }
                    if(pair_ou_impair==1){
                        if(flag_rouge == 1){
                            printf("Wow! You won %d", money);
                        } else {
                            printf("You lost! That happens when you gamble\n");
                            printf("The winner number was: %d\n", winner_number);
                        }
                    } else if(pair_ou_impair ==2){
                        if(flag_noir == 1){
                            printf("Wow! You won %d", money);
                        } else {
                            printf("You lost! That happens when you gamble\n");
                            printf("The winner number was: %d\n", winner_number);
                        }
                    }
                    break;
                case 4:
                    printf("Press 1 for Manque or 2 for Passe");
                    scanf("%d", &pair_ou_impair); //it's the same as pair ou impair, too lazy to change name of variable
                    if(pair_ou_impair==1){
                        if(winner_number >= 1 && winner_number <= 18){
                            printf("Wow! You won %d", money);
                        } else {
                            printf("You lost! That happens when you gamble\n");
                            printf("The winner number was: %d\n", winner_number);
                        }
                    } else if(pair_ou_impair ==2){
                        if(winner_number >= 19 && winner_number <= 36){
                            printf("Wow! You won %d", money);
                        } else {
                            printf("You lost! That happens when you gamble\n");
                            printf("The winner number was: %d\n", winner_number);
                        }
                    }
                    break;
                case 5:
                    if(winner_number == 0 || winner_number == ZZ){
                        money *= 17;
                        printf("Wow, you won %d\n", money);
                    } else {
                        printf("You lost! That happens when you gamble\n");
                        printf("The winner number was: %d\n", winner_number);
                    }
                    break;
                default:
                    printf("Error: invalid input\n");
                    break;
            }
        }
    }
    
    printf("Thanks for playing! Goodbye!\n");
    
    return 0;
}
