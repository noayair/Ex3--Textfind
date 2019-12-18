#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

int Getline(char s[]){
    int i = 0;
    char ch = getchar();
    while(ch != '\n' && ch != EOF){
    s[i] = ch;
    i++;
    ch = getchar();
    }
    s[i] = '\0';
    if(ch == EOF){
        return-1;
    }else{
    return i;
    }
}

int getword(char w[]){
    int j = 0;
    char ch = getchar();
    //w[0]=ch;
    while(ch != ' ' && ch != '\t' && ch != '\n' && ch != EOF){
        w[j] = ch;
        j++;
        ch = getchar();
    }
    w[j] = '\0';
    if(ch == EOF){
        return -1;
    }else{
        return j;
    }
}

int substring(char* str1,char*str2){
    int size_str1 = strlen(str1);
    int size_str2 = strlen(str2);
    for(int i = 0; i < size_str1; i++){
        int j = 0;
        for(j = 0; j < size_str1; j++){
            if(str1[i+j] != str2[j]){
                break;
            }
            if(j == size_str2-1){
                return 1;
            }
        }
    }
     return 0;
}

int similar(char* s,char* t,int n){
    int size_s = strlen(s);
    int size_t = strlen(t);
    if(size_s < size_t){
        return 0;
    }
    int j = 0;
    int i = 0;
    int counter = 0;
    while(j < size_t-1){
        if(s[i+j] != t[j]){
            counter++;
            i++;
        }else{
            j++;
        }
        if(counter > n){
            return 0;
        }
    }
    if(i+j != size_s-1){
        if(j+n == size_s-1){
            return 1;
        }
        return 0;
    }
    return 1;
}

void print_lines(char* str){
char s [LINE];
char* p = s;
int i = 0;
while(i!= EOF){
    i = Getline(s);
    if (substring(p,str) == 1){
        printf("%s \n" , s);
    }
}
}


void print_similar_words(char* str){
    char c [WORD];
    char* p1 = c;
    int j = 0;
    while(j != EOF){
        j = getword(c);
        if (similar(p1,str,1) == 1){
            printf("%s\n",c);
        }
    }
}