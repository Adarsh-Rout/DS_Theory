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
    int size1,size2;

    printf("Enter the number of elements for array %d: ",1);
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter the number of elements for array %d: ",2);
    scanf("%d", &size2);
    int arr2[size2];

    printf("Enter the elements for array 1:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the elements for array 2:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Apply Bubble Sort
    bubbleSort(arr1, size1);
    bubbleSort(arr2, size2);

    printf("\nSorted array1:\n");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\nSorted array2:\n");
    for (int i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }
    int arr3[size1+size2];
    for(int i=0;i<size1+size2;i++)
    {   
        if(i<size1)
        {
            arr3[i] = arr1[i];
        }
        else
        {
            arr3[i] = arr2[i-size1];
        }
    }
    int size3 = size1+size2;
    bubbleSort(arr3, size3);
    printf("\nFinal Sorted array:\n");
    for (int i = 0; i < size3; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}
