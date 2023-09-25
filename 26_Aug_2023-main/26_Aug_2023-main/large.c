#include <stdio.h>
void large(int arr[],int size)
{   
    int x=arr[0],count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>x)
        {
            x = arr[i];
        }
    }
    for(int i=0;i<size;i++)
    {
        if(x==arr[i])
        {
            count++;
        }
    }printf("\nThe largest element is %d and it occurs %d times",x,count);
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
    printf("\n Matrix\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }large(arr,size);                   
                            
    return 0;
}