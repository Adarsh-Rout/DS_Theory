#include <stdio.h>
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    // Enter CoDe
    int size,x,index;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    printf("Enter the element you want to insert: ");
    scanf("%d",&x);
    printf("Enter the index where you want to insert: ");
    scanf("%d",&index);
    
    int arr[size+1];
    for(int i=0;i<size;i++)                        
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nOriginal Matrix\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }printf("\n");
    bubbleSort(arr,size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    
    for(int i=size+1;i>index;i--)
    {
        arr[i]=arr[i-1];
    }arr[index]=x;
    
    printf("\n");
    for(int i=0;i<size+1;i++)
    {
        printf("%d ",arr[i]);
    }
                            
    return 0;
}