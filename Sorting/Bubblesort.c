// Online C compiler to run C program online
#include <stdio.h>
int main() {
    int arr[100],i,n,j,temp;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("Array before sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\n");
    printf("BUBBLE SORT");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\n");
    printf("Array after sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d, ",arr[i]);
    }

    return 0;
}