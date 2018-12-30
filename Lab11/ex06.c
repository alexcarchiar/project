/* Program to manage an exam
 * just need to read the file to know all commands
 * the program must be able to work with files
 * format of every line:
 * <Surname_Name> <StudentID> <Score>
 * the list is ordered by <Surname_Name>
 * <Surname_Name> only contains alpha and it can contain spaces
 * <StudentID> only contains digits
 * <score> only contains digits, in reality it is an int that goes from 0 to 30
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//definitions
#define MAX_STUDENTS 4096
#define MAX_SCORE 30
#define MIN_SCORE 0
#define MAX_ID 999999
#define MAX_SURNAME_NAME 40
#define SIZE_ID 6
#define SIZE_SCORE 2
struct _LINE {
    char Surname_Name[MAX_SURNAME_NAME];
    int student_id;
    int score;
};
typedef struct _LINE Line;

//protos
void save(Line *lines, char *reader, int num_students);
int load(Line *lines, char *reader);
void print_all(Line *lines, int num_students);
int insert_student(Line *lines, char *reader, int num_students);
void swap(Line *first, Line *second);
int search_ID(Line *lines, char *reader, int num_students);
int search_surname(Line *lines, char *reader, int num_students);
int delete_student(Line *lines, int index, int num_students);

int main(){
    
    Line lines[MAX_STUDENTS];
    //initializing the array
    for(int i = 0; i<MAX_STUDENTS; ++i){
        strcpy(lines[i].Surname_Name, "");
    }
    printf("Exam management program. Follow the instructions below to correctly use the program.\n");
    //Now, to make the commands, I add the 'Q' command to allow us to quit
    char reader[SIZE_ID+1+SIZE_SCORE+1+MAX_SURNAME_NAME+1+2];
    int index_searched;
    int num_students = 0; //flag to know if the database is empty
    int end = 0; //flag used for the while condition
    while(end == 0){
        //I prefer to seperate the printfs of the commands in order to have a more readable
        //For the purpose of this exercise, we assume that the user will always give correct input
        printf("Available commands, press:\n");
        printf("Press 'I' and enter a student's surname, ID and score, all seperated by spaces to insert a student.\n");
        printf("Press 'D' and enter a student's surname or ID after the space to delete a student");
        printf("Press 'V' and enter a student's name or ID after the space to view a student's data.\n");
        printf("Press 'P' to print the current database.\n");
        printf("Press 'L' and enter a file name after the space to load a previous database.\n");
        printf("Press 'S' and enter a file name after a space to save the current database.\n");
        printf("Press 'Q' to quit.\n");
        fgets(reader, SIZE_ID+1+SIZE_SCORE+1+MAX_SURNAME_NAME+1+2, stdin);
        switch(reader[0]){
            case 'i':
            case 'I':
                num_students = insert_student(lines, &reader[2], num_students);
                break;
            case 'v':
            case 'V':
                if(isalpha(reader[2])){
                    index_searched = search_surname(lines, &reader[2], num_students);
                } else{
                    index_searched = search_ID(lines, &reader[2], num_students);
                }
                if(index_searched == -1){
                    fprintf(stderr, "Student not found. Try again.\n");
                } else{
                    printf("Student data:\n%s %d %d\n", lines[index_searched].Surname_Name, lines[index_searched].student_id, lines[index_searched].score);
                }
                break;
            case 'd':
            case 'D':
                if(isalpha(reader[2])){
                    index_searched = search_surname(lines, &reader[2], num_students);
                } else{
                    index_searched = search_ID(lines, &reader[2], num_students);
                }
                num_students = delete_student(lines, index_searched, num_students);
                break;
            case 'p':
            case 'P':
                print_all(lines, num_students);
                break;
            case 'q':
            case 'Q':
                printf("Goodbye!\n");
                end++; //increment to end the while
                break;
            case 's':
            case 'S':
                save(lines, &reader[2], num_students);
                break;
            case 'l':
            case 'L':
                num_students = load(lines, &reader[2]);
                break;
            default:
                printf("Entered a wrong input. Please try again.\n");
        }
    }
    
    
    
    return 0;
}

void save(Line *lines, char *reader, int num_students){
    
    if(num_students == 0){
        fprintf(stderr, "The database is empty: there's no point in saving it.\n");
        return;
    }
    
    FILE *fout = fopen(reader, "w");
    if(fout == NULL){
        fprintf(stderr, "Couldn't save the file. Try again with a different path.\n");
        return;
    }
    
    fprintf(fout, "%d\n", num_students); //prints the number of students in the database to the file to optimize the program
    for(int i = 0; i< MAX_STUDENTS; ++i){
        fprintf(fout, "%s %d %d\n", lines[i].Surname_Name, lines[i].student_id, lines[i].score);
    }
    
    fclose(fout);
    
    return;
}

int load(Line *lines, char *reader){
    
    int num_students;
    FILE *fin = fopen(reader, "r");
    if(fin == NULL){
        fprintf(stderr, "The file was not found. Try again.\n");
        exit(-1);
    }
    
    char input[SIZE_ID+1+SIZE_SCORE+1+MAX_SURNAME_NAME+1];
    fgets(input, SIZE_ID+1+SIZE_SCORE+1+MAX_SURNAME_NAME+1, fin);
    num_students = atoi(input);
    
    
    char string_ID[SIZE_ID+1], string_score[SIZE_SCORE+1];
    for(int i = 0; i<num_students; ++i){
        fgets(input, SIZE_ID+1+SIZE_SCORE+1+MAX_SURNAME_NAME+1, fin);
        printf("Input: %s\n", input);
        sscanf(input, "%s %s %s", lines[i].Surname_Name, string_ID, string_score);
        lines[i].student_id = atoi(string_ID);
        lines[i].score = atoi(string_score);
    }
    
    fclose(fin);
    return num_students;
}

void print_all(Line *lines, int num_students){
    
    if(num_students == 0){
        printf("The database is empty. Please insert data before printing.\n");
    } else{
        printf("The database is:\n");
        for(int i = 0; i<num_students; ++i){
            printf("%s %6d %2d\n", lines[i].Surname_Name, lines[i].student_id, lines[i].score);
        }
    }
    
    return;
    
}

int insert_student(Line *lines, char *reader, int num_students){
    
    //Getting the data in the correct format
    Line student;
    char string_ID[SIZE_ID+1], string_score[SIZE_SCORE+1];
    sscanf(reader, "%s %s %s", student.Surname_Name, string_ID, string_score);
    student.student_id = atoi(string_ID);
    student.score = atoi(string_score);
    if(student.student_id > MAX_ID || student.score < MIN_SCORE || student.score > MAX_SCORE){
        fprintf(stderr, "Wrong input. Check the score and the ID.\n");
        return num_students;
    }
    
    //finding the right place in the array
    int end = 0; //flag
    for(int i = 0; i < num_students+1 && end == 0; ++i){
        if(strcmp(lines[i].Surname_Name, "") == 0){
            swap(&lines[i], &student);
        } else{
            if(lines[i].Surname_Name[0] < student.Surname_Name[0]){
                ;//do nothing, the new student comes after
            } else if(lines[i].Surname_Name[0] == student.Surname_Name[0]){
                if(strcmp(lines[i].Surname_Name, student.Surname_Name) < 0){
                    ;//do nothing, the new student comes after
                } else if(strcmp(lines[i].Surname_Name, student.Surname_Name) == 0){
                    if(lines[i].student_id < student.student_id){
                        ;//do nothing, the new student comes after
                    } else if(lines[i].student_id == student.student_id){
                        fprintf(stderr, "You inserted this student before\n");
                        end++;
                    } else {
                        swap(&lines[i], &student);
                    }
                } else if(strcmp(lines[i].Surname_Name, student.Surname_Name) > 0){
                    swap(&lines[i], &student);
                }
            } else if(lines[i].Surname_Name[0] > student.Surname_Name[0]){
                swap(&lines[i], &student);
            }
        }
    }
    num_students++;
    
    return num_students;
    
}

void swap(Line *first, Line *second){
    Line temp;
    temp.score = first->score;
    temp.student_id = first->student_id;
    strcpy(temp.Surname_Name, first->Surname_Name);
    first->score = second->score;
    first->student_id = second->student_id;
    strcpy(first->Surname_Name, second->Surname_Name);
    second->score = temp.score;
    second->student_id = temp.student_id;
    strcpy(second->Surname_Name, temp.Surname_Name);
    
    return;
}

int search_surname(Line *lines, char *reader, int num_students){
    
    int found = -1; //flag to know whether the student is found
    for(int i = 0; i<num_students && found == -1; ++i){
        int different = 0;
        if(lines[i].Surname_Name[0] == reader[0]){ //checks if the first letter is the same
            for(int j = 1; j< MAX_SURNAME_NAME+1 && different == 0; ++j){ //compares all other letters
                if(isalpha(lines[i].Surname_Name[j])){
                    if(lines[i].Surname_Name[j] != reader[j]){ //if one letter is different, then the strings are different
                        different++;
                    }
                }
            }
            if(different == 0){
                found = i;
            }
        }
    }
    
    return found;
}

int search_ID(Line *lines, char *reader, int num_students){
    
    int id = atoi(reader);
    int found = -1; //flag to know whether the student is found
    for(int i = 0; i<num_students && found == -1; ++i){
        if(lines[i].student_id == id){
            found = i;
        }
    }
    
    return found;
    
}

int delete_student(Line *lines, int index, int num_students){
    
    strcpy(lines[index].Surname_Name, ""); //copies an empty string. We don't really care about the other
    //variables because we rearrange the array
    for(int i = index; i < num_students; ++i){
        swap(&lines[i], &lines[i+1]);
    }
    
    num_students--;
    
    return num_students;
}
