#include "isort.h"
#include <stdio.h>

int main(){
    int arr[NUM] = {0};
    int i = 0;
    for(i = 0; i < NUM; i++){
        scanf("%d" ,arr+i);
    }
    insertion_sort(arr,NUM);
    int j = 0;
    for(j = 0; j < NUM; j++){
        printf("%d,", *(arr+j));
    }
    return 0;
}