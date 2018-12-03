//Lab06 ex3
#include <stdio.h>

#define N 10

int main(){
    
    int v1[N], repeated_values[N], times_repeated[N], not_in_sequence;
    printf("Give number which is not in the sequence:\n");
    scanf("%d", &not_in_sequence);
    printf("Give the sequence values:\n");
    for(int i = 0; i<N; ++i){
        printf("Value index %d\n", i);
        scanf("%d", &v1[i]);
    }
    for(int i = 0; i<N; ++i){
        repeated_values[i] = not_in_sequence;
        times_repeated[i] = 0;
    }
    for(int i = 0; i<N; ++i){
        int n = 0;
        for(int j = 0; j<N; j++){
            if(v1[i] == v1[j]){
                ++n;
            }
        }
        if(n > 0){
            int flag = 0;
            for(int j = 0; j<N; ++j){
                if(v1[i] == repeated_values[j])
                    flag++;
            }
            if(flag == 0){
                repeated_values[i] = v1[i];
                times_repeated[i] = n;
            }
        }
    }
    printf("Repeated values     |   Number of times:\n");
    for(int i = 0; i<N; ++i){
        if(times_repeated[i] > 1){
            printf("     %d             |            %d\n", repeated_values[i], times_repeated[i]);
        }
    }
    
    
    return 0;
}
