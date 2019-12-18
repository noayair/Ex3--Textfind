#include "txtfind.h"
#include <stdio.h>

//txtfind
int main(){
    char s[WORD];
    char ch;
    getword(s);
    scanf(" %c",&ch);
    if(ch == 'a'){
        print_lines(s);
    }
    if(ch == 'b'){
        print_similar_words(s);
    }
    return 0;
}