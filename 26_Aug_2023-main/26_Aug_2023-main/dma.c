#include <stdio.h>
#include <stdlib.h>
int main()
{
int rows, columns, **list;
printf("\n Enter the no of rows:");
scanf("%d", &rows);
printf("\n Enter the no of columns:");
scanf("%d", &columns);
if (rows < 1 || columns <1)
{
printf("Incorrect Value");

}
list = (int **) malloc(rows * sizeof(int *));
if (!list)
{
printf("Insufficient Memory");

}
for (int i=0; i<rows; ++i)
{
list[i] = (int *) malloc(columns * sizeof(int));
}
if (!list)
{
printf("Insufficient Memory");

}
/* Allow the users to enter values and then display it*/
for(int i=0; i<rows; i++)
{
    for(int j=0; j<columns; j++)
    {
        printf("Enter the element for index [%d][%d]: ",i+1,j+1);
        scanf("%d",&list[i][j]);
    }
}
/* print the values */
printf("\n Desired Matrix \n");
for(int i=0; i<rows; i++)
{
    for(int j=0; j<columns; j++)
    {
        printf(" %d ",list[i][j]);  
    }printf("\n");
}
free(list);
return 0;
}