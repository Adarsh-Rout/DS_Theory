#include <stdio.h>
void transpose(int *array, int m, int n){

    int n_array[m*n];
    for (int i = 0; i < m; ++i )
    {
       for (int j = 0; j < n; ++j )
       {
          // Index in the original matrix.
          int index1 = i*n+j;

          // Index in the transpose matrix.
          int index2 = j*m+i;

          n_array[index2] = array[index1];
       }
    }

    for (int i=0; i<m*n; i++) {
        array[i] = n_array[i];
    }
    for(int i=0;i<m*n;i++)
    {
        printf("%d ",array[i]);
    }
}
int main() {
    // Enter CoDe
    int size,m,n;
    
    printf("Enter the number of rows: ");
    scanf("%d",&m);
    printf("Enter the number of columns: ");
    scanf("%d",&n);
    size = m*n;
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
    }printf("\nTransposed Matrix\n");
    transpose(arr,m,n);                   
                            
    return 0;
}