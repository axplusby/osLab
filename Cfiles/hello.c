#include "myheader.h"
#include<stdio.h>
void main(){
    printf("hello World!\n");
    for(int i = 1; i <= 5; i++){
        printf("%d\n", i*5);
    }

    
    int check = 100;
    printf("Address of ptr: %p\n", (void*)&check);
    int * ptr = &check;
    printf("%p\n", ptr);


    int a, b;
    printf("Enter Two Integer : ");
    scanf("%d%d",&a, &b);
    int sum = add(a,b);
    printf("The sum of %d and %d is : %d\n", a, b, sum);
}
