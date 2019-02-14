//I need some help to improve it: my snake moves only when you give it a direction via the keyboard
//How do I make it move with a time delay?

//It works with Unix systems: I'm calling system("clear");

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//definitions
#define FOOD 'o'
#define TOP '-'
#define LEFT '|'
#define SNAKE '*'
#define SIZE 30
typedef struct _POINT{
    int x, y;
} Point;

//protos
void up(char **map, Point *snake, int size);
void down(char **map, Point *snake, int size);
void left(char **map, Point *snake, int size);
void right(char **map, Point *snake, int size);
void delay();

int main(int argc, char **argv){
    if(argc != 1){
        fprintf(stderr, "Wrong number of arguments");
        exit(EXIT_FAILURE);
    }

    int end = 0;
    printf("Snake by alexcarchiar\n");
    printf("Use WASD to move\nPress enter to start\n");
    getchar();
    system("clear");
    char map[SIZE][SIZE];

    //initializing map
    for(int i = 0; i<SIZE; ++i){
        for(int j = 0; j<SIZE; ++j){
            map[i][j] = ' ';
        }
    }
    //finished initialzing map

    Point snake[SIZE*SIZE], food;
    srand(time(NULL));
    int size = 0;
    snake[0].x = rand()%SIZE;
    snake[0].y = rand()%SIZE;
    map[snake[0].x][snake[0].y] = SNAKE;
    int eaten = 1;

    while(end == 0){
        //generating new food and new snake
        if(eaten){
            do{
            food.x = rand()%SIZE;
            food.y = rand()%SIZE;
            }while(map[food.x][food.y] == SNAKE);
            map[food.x][food.y] = FOOD;
            eaten = 0;
        }
        //finished generations


        //Printing map
        printf("+");
        for(int i = 0; i< SIZE; ++i){
            printf("-");
        }
        printf("+\n");
        for(int i = 0; i < SIZE; ++i){
            printf("|");
            for(int j = 0; j<SIZE; ++j){
                printf("%c", map[i][j]);
            }
            printf("|\n");
        }
        printf("+");
        for(int i = 0; i< SIZE; ++i){
            printf("-");
        }
        printf("+\n");
        //finished printing
        char move = tolower(getchar());
        /*do{
            move = tolower(getchar());
            char lose = getchar(); //used to get rid of the new line character
        }while(move != 'w' && move != 'a' && move != 's' && move != 'd');*/
        
        Point tmp = snake[size]; //used to add a new piece of the snake
        switch(move){
            default:
                ;
                break;
            case 'w':
                //up(map, snake, size);
                if(size > 0){
                    for(int i = size; i > 0; --i){
                        snake[i] = snake[i-1];
                    }
                }

                snake[0].x--;
                if(snake[0].x < 0){
                    printf("You hit the border: game over\n");
                    for(int i = 0; i < 20; ++i){
                        delay();
                    }
                    end = 1;
                }
                if(map[snake[0].x][snake[0].y] == SNAKE){ //death by eating own tail
                    printf("You ate your own tail: game over\n");
                    for(int i = 0; i < 20; ++i){
                        delay();
                    }
                    end = 1;
                }

                for(int i = 0; i<SIZE; ++i){ //erasing snake from map
                    for(int j = 0; j<SIZE; ++j){
                        if(map[i][j] != FOOD)
                            map[i][j] = ' ';
                    }
                }

                
                if(map[snake[0].x][snake[0].y] == FOOD){ //if we find food, increase the snake
                    eaten = 1;
                    size++;
                    snake[size] = tmp; //used in order to let the snake have a logical increase
                    map[snake[size].x][snake[size].y] = SNAKE;
                }
                for(int i = 0; i<size+1; ++i){ //putting the snake back into the map
                    map[snake[i].x][snake[i].y] = SNAKE;
                }
                break;
            case 'a':
                //left(map, snake, size);
                if(size > 0){
                    for(int i = size; i > 0; --i){
                        snake[i] = snake[i-1];
                    }
                }

                snake[0].y--;
                if(snake[0].y < 0){
                    printf("You hit the border: game over\n");
                    for(int i = 0; i < 20; ++i){
                        delay();
                    }
                    end = 1;
                }
                if(map[snake[0].x][snake[0].y] == SNAKE){ //death by eating own tail
                    printf("You ate your own tail: game over\n");
                    for(int i = 0; i < 20; ++i){
                        delay();
                    }
                    end = 1;
                }
                
                for(int i = 0; i<SIZE; ++i){
                    for(int j = 0; j<SIZE; ++j){
                        if(map[i][j] != FOOD)
                            map[i][j] = ' ';
                    }
                }

                
                if(map[snake[0].x][snake[0].y] == FOOD){
                    eaten = 1;
                    size++;
                    snake[size] = tmp;
                    map[snake[size].x][snake[size].y] = SNAKE;
                }
                for(int i = 0; i<size+1; ++i){
                    map[snake[i].x][snake[i].y] = SNAKE;
                }
                break;
            case 's':
                //down(map, snake, size);
                if(size > 0){
                    for(int i = size; i > 0; --i){
                        snake[i] = snake[i-1];
                    }
                }

                snake[0].x++;
                if(snake[0].x > SIZE-1){
                    printf("You hit the border: game over\n");
                    for(int i = 0; i < 20; ++i){
                        delay();
                    }
                    end = 1;
                }
                if(map[snake[0].x][snake[0].y] == SNAKE){ //death by eating own tail
                    printf("You ate your own tail: game over\n");
                    for(int i = 0; i < 20; ++i){
                        delay();
                    }
                    end = 1;
                }
                
                for(int i = 0; i<SIZE; ++i){
                    for(int j = 0; j<SIZE; ++j){
                        if(map[i][j] != FOOD)
                            map[i][j] = ' ';
                    }
                }

                if(map[snake[0].x][snake[0].y] == FOOD){
                    eaten = 1;
                    size++;
                    snake[size] = tmp;
                    map[snake[size].x][snake[size].y] = SNAKE;
                }
                for(int i = 0; i<size+1; ++i){
                    map[snake[i].x][snake[i].y] = SNAKE;
                }
                break;
            case 'd':
                //right(map, snake, size);
                if(size > 0){
                    for(int i = size; i > 0; --i){
                        snake[i] = snake[i-1];
                    }
                }

                snake[0].y++;
                if(snake[0].y > SIZE-1){
                    printf("You hit the border: game over\n");
                    for(int i = 0; i < 20; ++i){
                        delay();
                    }
                    end = 1;
                }
                if(map[snake[0].x][snake[0].y] == SNAKE){ //death by eating own tail
                    printf("You ate your own tail: game over\n");
                    for(int i = 0; i < 20; ++i){
                        delay();
                    }
                    end = 1;
                }
                
                
                for(int i = 0; i<SIZE; ++i){
                    for(int j = 0; j<SIZE; ++j){
                        if(map[i][j] != FOOD)
                            map[i][j] = ' ';
                    }
                }

                
                if(map[snake[0].x][snake[0].y] == FOOD){
                    eaten = 1;
                    size++;
                    snake[size] = tmp;
                    map[snake[size].x][snake[size].y] = SNAKE;
                }
                for(int i = 0; i<size+1; ++i){
                    map[snake[i].x][snake[i].y] = SNAKE;
                }
                break;
        }
        delay();
        system("clear");
    }

    return 0;
}

void delay(){
    for(int i = 0; i<=1000; ++i){
        for(int j = 0; j<=32767; ++j){
            ;
        }
    }
}

