#include <stdio.h>
#include<stdlib.h>
struct Book
{
    char name[100];
    int price;
};
int main() {
    // Enter CoDe
    struct Book dsb[5];
    struct Book *ptr;
    struct Book *crntbook;
    
    ptr = (struct Book*)malloc(2*sizeof(struct Book));
    for(int i=0;i<2;i++)
    {
        ptr = &dsb[i];
        printf("Enter book name %d: ",i+1);
        scanf("%s",ptr->name);
        printf("\n");
        printf("Enter price for that book: ");
        scanf("%d",&ptr->price);
        ptr++;
    }
    ptr = crntbook;
    for(int i=0;i<2;i++)
    {
        ptr = &dsb[i];
        printf("Book Name : %s & Price: %d\n\n",ptr->name,ptr->price);
    }

    free(ptr);
                              
    return 0;
}