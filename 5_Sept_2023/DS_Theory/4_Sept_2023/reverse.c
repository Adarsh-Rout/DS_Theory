#include <stdio.h>
#include <malloc.h>
typedef struct NODE{
    int data;
    struct NODE *next;
}node;
node *start = NULL;
node * create_LL(node *);
node * display_LL(node *);
node * rev(node *);


int main() {
    // Enter CoDe
    int option;

    do
    {
        /* code */
        printf("\nMAIN MENU\n");
        printf("1.Create Linked List\n");
        printf("2.Display Linked List\n");
        printf("3.Reverse Linked List\n");
        printf("Enter Operation: ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            /* code */
            start = create_LL(start);
            printf("Linked List created Successfully\n");
            break;
        case 2:
            printf("Linked List\n");
            start=display_LL(start);
            break;
        case 3:
            printf("Reversed Linked List\n");
            start = rev(start);
            printf("Linked List has been reversed\n");
            break;
        default:
            printf("\nInvalid Input !!!");
            break;
        }
    } while (option < 4);
                        
                            
    return 0;
}
node * create_LL(node *start)
{
    node* new_node,*ptr;
    int num;
    printf("\nEnter -1 to stop creating\n");
    printf("\nEnter data element: ");
    scanf("%d",&num);

    while(num!=-1)
    {
        new_node=(node*)malloc(sizeof(node));
        new_node->data=num;
        if(start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }ptr->next=new_node;
            new_node->next=NULL;

        }
            printf("\n Enter data element: ");
            scanf("%d",&num);

    }
    return start;
}
node * display_LL(node*start)
{
    node * ptr;
    ptr = start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
        if(ptr!=NULL)
        {
            printf("-> ");
        }
    }
    return start;
}
node * rev(node*start)
{
    node * current = start;
    node * previous = NULL;
    node * next = NULL;
    
    while(current!=NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }return previous;
}