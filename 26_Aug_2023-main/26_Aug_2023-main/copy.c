#include <stdio.h>

int main() {
    // Enter CoDe
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size],copy[size];
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
    printf("\nCopied Matrix\n");
    for(int i=0;i<size;i++)
    {
        copy[i]=arr[i];
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",copy[i]);
    }
                            
    return 0;
}