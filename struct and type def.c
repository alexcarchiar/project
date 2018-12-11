//from lecture, struct and typedef
#include <stdio.h>

#define MAX_POINTS 10

struct _POINT {
    double x;
    double y;
};
typedef struct _POINT POINT;
//proto
void print_points(const POINT *points);
//or also:
void print_points(const POINT points[]);

void sort_points(POINT *points);
int ptcmp(struct _POINT p1, struct _POINT p2);

int main(){
  
    POINT points[MAX_POINTS];
    
    for(int i = 0; i<MAX_POINTS; ++i){
        points[i].x = (rand() % 1000)/ 1000.0 - 0.5;
        points[i].y = (rand() % 1000)/ 1000.0 - 0.5;
    }
    print_points(points);
    sort_points(points);
    printf("---------\n");
    print_points(points);
    
    return 0;
}

void print_points(const POINT *points){
    for(int i = 0; i<MAX_POINTS; ++i)
        printf("(%g, %g)\n", points[i].x, points[i].y);
}

int ptcmp(POINT p1, struct _POINT p2){
    double d1 = p1.x*p1.x + p1.y * p1.y;
    double d2 = p2.x * p2.x + p2.y * p2.y;
    if(d1 > d2){
        return 1;
    } else if (d1 < d2){
        return -1;
    } else
        return 0;
}

void sort_points(POINT *points){
    for(int t1 = 0; t1 < MAX_POINTS; ++t1){
        int min = t1;
        for(int t2 = t1; t2 < MAX_POINTS; ++t2){
            if(ptcmp(points[t2], points[min]) > 0){
                min = t2;
            }
        }
        struct _POINT tmp = points[t1];
        points[t1] = points[min];
        points[min] = tmp;
    }
}



/*
 //proto
 void print_points(const struct _POINT *points);
 //or also:
 void print_points(const struct _POINT points[]);
 
 void sort_points(struct _POINT *points);
 int ptcmp(struct _POINT p1, struct _POINT p2);
 
 int main(){
 
 struct _POINT points[MAX_POINTS];
 
 for(int i = 0; i<MAX_POINTS; ++i){
 points[i].x = (rand() % 1000)/ 1000.0 - 0.5;
 points[i].y = (rand() % 1000)/ 1000.0 - 0.5;
 }
 print_points(points);
 sort_points(points);
 printf("---------\n");
 print_points(points);
 
 return 0;
 }
 
 void print_points(const struct _POINT *points){
 for(int i = 0; i<MAX_POINTS; ++i)
 printf("(%g, %g)\n", points[i].x, points[i].y);
 }
 
 int ptcmp(struct _POINT p1, struct _POINT p2){
 double d1 = p1.x*p1.x + p1.y * p1.y;
 double d2 = p2.x * p2.x + p2.y * p2.y;
 if(d1 > d2){
 return 1;
 } else if (d1 < d2){
 return -1;
 } else
 return 0;
 }
 
 void sort_points(struct _POINT *points){
 for(int t1 = 0; t1 < MAX_POINTS; ++t1){
 int min = t1;
 for(int t2 = t1; t2 < MAX_POINTS; ++t2){
 if(ptcmp(points[t2], points[min]) > 0){
 min = t2;
 }
 }
 struct _POINT tmp = points[t1];
 points[t1] = points[min];
 points[min] = tmp;
 }
 }
*/
