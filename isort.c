#include "isort.h"
#include <stdio.h>
void shift_element(int* arr,int i){
    int size = (sizeof(arr)/4)-1;
    for(int j = size; j > 0; j-- ){
        *(arr+j) = *(arr+j-1);
    }
}
void insertion_sort(int* arr,int len){
    int i = 0;
    int key = 0;
    int j = 0;
    for (i = 1; i < len; i++){
        key = *(arr+i);
        j = i-1;
        while(j >= 0 && *(arr+j) > key){
            shift_element(arr+j , 1);
            j = j-1;
        }
        *(arr+j+1) = key;
    }
}