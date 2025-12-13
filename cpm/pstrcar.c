/*
Made by: Alex Hamill
*/

#include <stdio.h>


strcat(s, t) 
char *s, *t; 
{
    int i, j;
    i = j = 0;
    while (*(s + i) != '\0'){ 
        i++;
    }
    while((*(s + i) = *(t + j)) != '\0'){
        i++;
        j++;
    }

}



int main()
{
   char str1[10];
   char str2[3];
   str1[0]='a';
   str1[1]='b';
   str1[2]='\0';
   str2[0]='c';
   str2[1]='\0';
   strcat(str1,str2);
   printf("blahblah %s",str1);



}
