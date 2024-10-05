// Online C compiler to run C program online
#include <stdio.h>
void move(int n, char source, char dest, char space)
{
    if(n==1)
    {
        printf("Move from %c to %c\n",source,dest);
    }
    else
    {
        move(n-1,source,space,dest);
        move(1,source,dest,space);
        move(n-1,space,dest,source);
    }
}
int main() {
    int n;
    printf("Enter the number of rings: ");
    scanf("%d",&n);
    move(n,'A','B','C');
    return 0;
}