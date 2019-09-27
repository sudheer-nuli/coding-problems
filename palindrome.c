#include<stdio.h>
#include<string.h>
int main()
{
int i;
int j;
char x[100];
printf("enter the string:");
gets(x);
j=strlen(x);

for(i=0;x[i] == x[j-i-1]&&i<j;i++);
if(i == j)
{
    printf("given string is palindrome.");
}
else{
    printf("given string is not a palindrome.");
}
return 0;
}
