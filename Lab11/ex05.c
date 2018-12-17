#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*I consider that the format is:
 * <name> <score>
 * <name2> <score2>
 * ...
 * When there is an EOF, I simply set all the other to 0.
 */

//definitions
#define MAX_ATHLETES 100
#define EMPTY_SCORE -1
struct _ATHLETE{
    char name[4096];
    int score;
};
typedef struct _ATHLETE Athlete;

//protos
int get_input(Athlete *athletes);
void sort_alphabetically(Athlete *atheletes, int counter);
int find_max(Athlete *athletes, int counter);


int main(){
 
    Athlete athletes[MAX_ATHLETES];
    int pos[3];
    int num_of_athletes = get_input(athletes);
    
    sort_alphabetically(athletes, num_of_athletes);

    //displaying athletes and writing file
    FILE *fout = fopen("/Users/alexcarchiar/Desktop/contest_ord.txt", "w");
    if(fout == NULL){
        fprintf(stderr, "Couldn't find the file\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i<=num_of_athletes; ++i){
        printf("%s %d\n", athletes[i].name, athletes[i].score);
        fprintf(fout, "%s %d\n", athletes[i].name, athletes[i].score);
    }
    fclose(fout);

    //finding and printing the best three positions (only names, as required)
    printf("The best three positions are:\n");
    for(int i = 0; i<3; ++i){
        pos[i] = find_max(athletes, num_of_athletes);
        printf("%s\n", athletes[pos[i]].name);
    }

    return 0;
}

int get_input(Athlete *athletes){
    
    int counter = 0;
    
    FILE *fin = fopen("/Users/alexcarchiar/Desktop/contest.txt", "r");
    
    int end_of_input = 0;
    char reader[4096], _reader[4096];
    
    for(int i = 0; i<MAX_ATHLETES && end_of_input == 0; ++i){
        fgets(reader, 4096, fin);
        reader[0] = toupper(reader[0]);
        if(reader[0] == EOF || strcmp(reader, _reader) == 0){
            end_of_input++;
        }else{
            sscanf(reader, "%s %d", athletes[i].name, &athletes[i].score);
            strcpy(_reader, reader);
            counter = i;
        }
        
    }
    
    
    fclose(fin);
    return counter;
}

void sort_alphabetically(Athlete *atheletes, int counter){
    
    Athlete temp;
    for(int i = 0; i<=counter-1; ++i){
        for(int j =i+1; j<=counter; ++j){
            if(strcmp(atheletes[i].name, atheletes[j].name) > 0){
                temp = atheletes[i];
                atheletes[i] = atheletes[j];
                atheletes[j] = temp;
            }
        }
    }
    
    return;
}

int  find_max(Athlete *athletes, int counter){

    int pos;
    int max = -1;
    
    for(int i = 0; i<=counter; ++i){
        if(max < athletes[i].score){
            pos = i;
            max = athletes[i].score;
        }
    }
    athletes[pos].score = EMPTY_SCORE;

    return pos;
}
