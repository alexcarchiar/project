//Lab08 ex 3
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 6

//protos
int scan_time(char *time);
int precedes(char *time1, char *time2);
int to_int(char *time);

int main(){
    
    char time1[MAX+1], time2[MAX+1], final[100];
    int flag_1, flag_2;
    int int_time1, int_time2, interval;
    printf("Input format: hh:mm\n");
    printf("Insert first time\n");
    flag_1 = scan_time(time1);
    if(flag_1 != 5)
        printf("Invalid input\n");
    printf("Insert second time\n");
    flag_2 = scan_time(time2);
    if(flag_2 != 5)
        printf("Invalid input\n");
    if(flag_1 == 5 && flag_2 == 5 && precedes(time1, time2)){
        int_time1 = to_int(time1);
        int_time2 = to_int(time2);
        interval = int_time2 - int_time1;
        sprintf(final, "%d minutes", interval);
        printf("%s", final);
        
    }
    
    
    
    return 0;
}

int scan_time(char *time){
    
    int flag = 0; //used to check if the input is correct, 0 means invalid, 5 means valid
    scanf("%s", time);
    if(time[0] == '1' || time[0] == '2' || time[0] == '0')
        ++flag;
    if(isdigit(time[1])){
        if(time[0] == '2' && (time[1]<= '4' && time[1]>= '0')){
            ++flag;
        } else if(time[0] == '1' || time[0] == '0'){
            ++flag;
        }
    }
    if(time[2] == ':')
        ++flag;
    if(time[3] >= '0' && time[3] <= '6')
        ++flag;
    if(isdigit(time[4]))
        ++flag;
    
    return flag;
}

int precedes(char *time1, char *time2){
    int flag = 0; //0 means time1 does not precede time2
    
    if(time1[0] < time2[0]){
        flag = 1;
    } else if(time1[1] < time2[1]){
        flag = 1;
    } else if(time1[3] < time2[3]){
        flag = 1;
    } else if(time1[4] < time2[4]){
        flag = 1;
    }
    
    return flag;
    
}

int to_int(char *time){
    
    int int_time = 0;
    int_time = time[4] + (10*time[3]) + (60 * time[1]) + (10 * 60 * time[0]);
    
    return int_time;
}
