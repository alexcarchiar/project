/* Build a program that reads from a file some lines with this format
 * <subject> <prof name> <prof surname> <period> <credits> <% pass rate>
 * It is able to do some statistics
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//definitions
#define MAX_ROW 80
#define MAX_LEN_FIELD 20
#define MAX_PERIOD 4
struct _LINE {
    char subject[MAX_LEN_FIELD];
    char prof_name[MAX_LEN_FIELD];
    char prof_surname[MAX_LEN_FIELD];
    int period;
    int credits;
    int pass_rate;
};
typedef struct _LINE line;

//protos
int get_input(line *lines, char *path);
void find_max(line *lines, int num);
void find_difficult(line *lines, int num, int period);
int sum_of_credits(char *last_name, line *lines, int num);
float average_pass_rate(char *last_name, line *lines, int num);

int main(int argc, char **argv){
    
    if(argc != 2){
        fprintf(stderr, "The program only needs the path of the file to work\n");
        exit(1);
    }
    
    line lines[MAX_ROW];
    int num_of_lines = get_input(lines, argv[1]);
    
    printf("Subjects with most number of credits:\n");
    find_max(lines, num_of_lines);
    printf("Most difficult subjects for each period: \n");
    for(int i = 1; i<5; ++i){
        printf("Period %d:\n", i);
        find_difficult(lines, num_of_lines, i);
    }
    printf("Insert the last name of a professor\n");
    char last_name[MAX_LEN_FIELD+1];
    scanf("%s", last_name);
    printf("Sum of credits of subjects taught by %s: %d\n", last_name, sum_of_credits(last_name, lines, num_of_lines));
    printf("Average pass rate: %g", average_pass_rate(last_name, lines, num_of_lines));
    
    return 0;
}

int get_input(line *lines, char *path){
    
    int line_counter;
    char reader[6*MAX_LEN_FIELD+1];
    FILE *fin = fopen(path, "r");
    if(fin == NULL){
        fprintf(stderr, "File not found\n");
        exit(2);
    }
    
    int end_of_input = 0; //flag that allows us to understand when the program is done reading the file
    for(int i = 0; i<MAX_ROW && end_of_input == 0; ++i){
        if(fgets(reader, 6*MAX_LEN_FIELD+1, fin)!=NULL){ //REMEMBER TO WRITE NULL
            line_counter = i;
            sscanf(reader, "%s %s %s %d %d %d", lines[i].subject, lines[i].prof_name, lines[i].prof_surname, &lines[i].period, &lines[i].credits, &lines[i].pass_rate);
        }
    }
    
    fclose(fin);
    return line_counter;
}

void find_max(line *lines, int num){
    int max = 0;
    for(int i = 0; i<num+1; ++i){
        if(max < lines[i].credits){
            max = lines[i].credits;
        }
    }
    
    for(int i = 0; i<num+1; ++i){
        if(max == lines[i].credits){
            printf("%s\n", lines[i].subject);
        }
    }
    
    
    
    return;
}

void find_difficult(line *lines, int num, int period){
    
    int min = 100;
    for(int i = 0; i<num+1; ++i){
        if(min > lines[i].pass_rate && lines[i].period == period){
            min = lines[i].pass_rate;
        }
    }
    
    for(int i = 0; i<num+1; ++i){
        if(min == lines[i].pass_rate && lines[i].period == period){
            printf("%s\n", lines[i].subject);
        }
    }
    
    return;
}

int sum_of_credits(char *last_name, line *lines, int num){
    
    int sum = 0;
    
    for(int i = 0; i < num + 1; ++i){
        if(strcmp(last_name, lines[i].prof_surname) == 0){
            sum += lines[i].credits;
        }
    }
    
    return sum;
}

float average_pass_rate(char *last_name, line *lines, int num){
    
    float average = 0.0;
    int counter = 0;
    
    for(int i = 0; i< num + 1; ++i){
        if(strcmp(last_name, lines[i].prof_surname) == 0){
            average += (float)lines[i].pass_rate;
            counter++;
        }
    }
    
    average /= counter;
    
    return average;
}
