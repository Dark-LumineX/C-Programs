#include <stdio.h>
#include <conio.h>

void main()
{
    char a[20];
    int i=0,s=0;
    printf("Enter the code words:");
    scanf("%s",&a);
    while(a[i]!='\0')
    {
        printf("\nThe code for the character %c is %d", a[i],a[i]);
        s=s+a[i];
        i++;
    }
    printf("\nThe sum of values are %d",s);
    getch();
}
