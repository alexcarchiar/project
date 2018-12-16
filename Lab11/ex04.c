//Lab11 ex04
//basically the same as ex03 Lab09, but with parameters
/*
This is a program that gets an input from a file and gets names of train stations
and departure/arrival times.
In each line, the file contains the
following information (each field is no longer than 20 characters and has
no spaces):
<departure_station> <departure_time> <arrival_station> <arrival_time>
The user inputs a station and the program tells how many trains are from and to
that specific station.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//definitions
#define LEN_FIELD 20
#define LEN_TIME 5
#define MAX_LINE 4096
struct _LINES{ //defining an object to store all the information in a convinient way
    char departure_station[LEN_FIELD+1];
    char departure_time[LEN_TIME+1];
    char arrival_station[LEN_FIELD+1];
    char arrival_time[LEN_TIME+1];
};
typedef struct _LINES LINE;
//protos
int get_input(LINE *lin, char *path);
void tolower_string(char *string);

int main(int argc, char **argv){ //first parameter is the name of the file, the second is the name of the station
    
    if(argc < 3){
        printf("Error: too few arguments\n");
        exit(-1);
    } else if(argc > 3){
        printf("Error: too many arguments\n");
        exit(1);
    }
    
    LINE lines[MAX_LINE+1]; //array to store lines
    printf("Trenitalia by alexcarchiar\n");
    int number_of_lines = get_input(lines, argv[1]); //function to get input from files
    
    

    char input_station[LEN_FIELD+1];
    char station[LEN_FIELD+1]; //this is used to preserve the uppercases of the user input
    printf("Which station do you want to check?\n");
    scanf("%s", input_station);
    strcpy(station, input_station);
    
    
    tolower_string(input_station); //converting all names to lower char to avoid the upper/lowercase problem
    for(int i = 0; i<number_of_lines; ++i){
        tolower_string(lines[i].departure_station);
        tolower_string(lines[i].arrival_station);
    }
    
    //after checking if the train station is included
    int counter_trains_to_input = 0;
    int counter_trains_from_input = 0;
    for(int i = 0; i<number_of_lines; ++i){
        if(strcmp(input_station, lines[i].arrival_station) == 0){
            counter_trains_to_input++;
        }
        if(strcmp(input_station, lines[i].departure_station) == 0){
            counter_trains_from_input++;
        }
    }
    printf("There are %d trains from %s and %d trains to %s\n", counter_trains_from_input, station, counter_trains_to_input, station);
    
    return 0;
}

int get_input(LINE *lin, char *path){
    
    char reader[MAX_LINE+1][LEN_FIELD*5+5+LEN_TIME+2];
    FILE *input = fopen(path, "r");
    
    int actual_number_of_lines = 0;
    for(int i = 0; i<MAX_LINE; ++i){ //storing the file in a matrix and counting the lines
        fgets(reader[i], LEN_FIELD*5+5+LEN_TIME+2, input);
        //fscanf(input, "%s", reader[i]);
        if(reader[i][0] != '\0'){
            actual_number_of_lines++;
        }
    }
    fclose(input);
    for(int i = 0; i<actual_number_of_lines+1; ++i){
        int number_of_spaces = 0; //the number of spaces is the separator in the file of the various fields
        //have to add indexes for all fields because they are strings in the LINE object; I have to seperate the content of the lines of the files as well as add the various '\0' add the end of each string to print it
        int index_departure_station = 0;
        int index_departure_time = 0;
        int index_arrival_station = 0;
        int index_arrival_time = 0;
        for(int j = 0; j<LEN_FIELD*5+5+LEN_TIME+2; ++j){
            if(reader[i][0] == '\n'){
                lin[i].arrival_station[0] = lin[i].arrival_time[0] = lin[i].departure_station[0] = lin[i].departure_time[0] = '\0';
            }
            if(number_of_spaces == 0){
                if(reader[i][j] != ' '){
                    lin[i].departure_station[index_departure_station] = reader[i][j];
                    ++index_departure_station;
                } else {
                    number_of_spaces++;
                    lin[i].departure_station[index_departure_station] = '\0';
                }
            } else if(number_of_spaces == 1){
                if(reader[i][j] != ' '){
                    lin[i].departure_time[index_departure_time] = reader[i][j];
                    ++index_departure_time;
                } else {
                    lin[i].departure_time[index_departure_time] = '\0';
                    number_of_spaces++;
                    }
            }else if(number_of_spaces == 2){
                if(reader[i][j] != ' '){
                    lin[i].arrival_station[index_arrival_station] = reader[i][j];
                    ++index_arrival_station;
                } else{
                    lin[i].arrival_station[index_arrival_station] = '\0';
                    number_of_spaces++;
                }
            } else if(number_of_spaces == 3){
                if(reader[i][j] != '\n'){
                    lin[i].arrival_time[index_arrival_time] = reader[i][j];
                    ++index_arrival_time;
                } else{
                    lin[i].arrival_time[index_arrival_time] = '\0';
                }
            }
            
        }
    }
    for(int i = actual_number_of_lines; i<MAX_LINE; ++i){
        lin[i].arrival_station[0] = lin[i].arrival_time[0] = lin[i].departure_station[0] = lin[i].departure_time[0] = '\0';
    }
    
    return actual_number_of_lines;
}

void tolower_string(char *string){
    for(int i = 0; i<LEN_FIELD+1; ++i){
        string[i] = tolower(string[i]);
    }
    
    return;
}
