// Circular Header Link List

#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *start = NULL;
node *create_ll(node *,node *);
node * display(node *);
int main()
{
    // Enter CoDe
    int num;
    node * header = malloc(sizeof(node));;
    do
    {

        printf("***MAIN MENU***\n");
        printf("1. Create header link list\n");
        printf("2. display the link list\n");
        printf("Enter your option: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            start = create_ll(start,header);
            break;
        case 2:
            header = display(header);
            break;
        default:
            break;
        }
    } while (num != 3);
    return 0;
}
node *create_ll(node *start,node *header)
{
    int num,count=0;
    node *new_node, *ptr;

    printf("\nEnter data element: ");
    scanf("%d", &num);
    
    while (num != -1)
    {
        new_node = malloc(sizeof(node));
        

        new_node->data = num;
        
        if (start == NULL)
        {
            start = new_node;
            new_node->next = start;
            
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("\nEnter data element: ");
        scanf("%d", &num);
        if(num%2==0)
        {
            count++;
        }
    }header->data=count+1;
    header->next=start;

    return header;
}
node * display(node * header)
{
    node * ptr = header->next;
    printf("Header link list contains %d nodes with even data\n",header->data);
    while(ptr->next!=header->next)
    {   
        printf(" %d -> ",ptr->data);
        ptr = ptr->next;
    }printf(" %d\n",ptr->data);
    return header;
}