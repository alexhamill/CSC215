strcat(s, t) 
char *s, *t; 
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0'){ 
        i++;
    }
    while((s[i++] = t[j++]) != '\0'){
        ;
    } /* copy t */

}