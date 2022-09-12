#include<stdio.h>
  
void main()
{
    char text[100];
    char *p;
    p=text;
    scanf("%s",text);
    while (*p!='\0')
    {
        if (*p >= 65 && *p <= 90)
        {
            *p+=32;
            printf("%c",*p);
        }
        else if (*p >= 97 && *p <= 122)
        {
            *p-=32;
            printf("%c",*p);
        }
        p++;
    }
}