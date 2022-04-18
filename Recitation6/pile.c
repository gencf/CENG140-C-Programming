#include <stdio.h>
#include <stdlib.h>

char* pile(char* str1, char* str2) {
    int i = 0, j1 = 0, j2 = 0, end1 = 0, end2 = 0;
    char *ptr = (char*) calloc(i+1, sizeof(char));

    while (!(end1 == 1 && end2 == 1)){
        while(!end1){  
            if(str1[j1] == '\0'){
                end1 = 1;
                break;
            }

            else if(str1[j1] == ' ') {
                j1++;
                continue;
            }

            else {
                ptr[i++] = str1[j1++];
                ptr = (char*) realloc(ptr, (i+1) * sizeof(char));
                break;
            }          
        }   

        while(!end2){ 
            if(str2[j2] == '\0'){
                end2 = 1;
                break;
            }

            else if(str2[j2] == ' ') {
                j2++;
                continue;
            }

            else {
                ptr[i++] = str2[j2++];
                ptr = (char*) realloc(ptr, (i+1) * sizeof(char));
                break;
            }          
        }    

    }

    return ptr;

}