#include<stdio.h>
int main()
{
    int q=1;
    char c;
    while((c = getchar()) != EOF)
    {
        if(c == '"'){printf("%s",q ? "¡°" : "¡±"); q = !q;}
        else printf("%c",c);
    }
    return 0;
}
