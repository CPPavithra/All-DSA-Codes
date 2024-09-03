// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int i,j,arr[100],temp,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\n");
    printf("Enter the elements in the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting: \n");
    for(i=0;i<n;i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\n");
    printf("\n");
    printf("SELECTION SORT\n");
    for(i=0;i<n;i++)
    {
        int minIndex=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
            minIndex=j;
            }
        }
        if(minIndex!=i)
            {
                temp=arr[i];
                arr[i]=arr[minIndex];
                arr[minIndex]=temp;
            }
    }
    printf("After sorting, \n");
    for(i=0;i<n;i++)
    {
        printf("%d, ",arr[i]);
    }
    

    return 0;
}