#include <stdio.h>
void reverse(int arr[],int size)
{   int arr2[size];
    for(int i=0;i<size/2;i++)
    {
        int x = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = x;
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main() {
    // Enter CoDe
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)                        
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nOriginal Matrix\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nReversed Matrix\n");
    reverse(arr,size);
    return 0;
}