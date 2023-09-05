#include <stdio.h>
#include <malloc.h>
typedef struct NODE{
    int data;
    struct NODE *next;
}node;
node *start=NULL;
node * create_LL(node *);
void pallindrome(node *);
int main() {
    // Enter CoDe
    int option;

    do
    {
        /* code */
        printf("\nMAIN MENU\n");
        printf("1.Create Linked List\n");
        printf("2.Pallindrome Check\n");
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
            pallindrome(start);
            break;
        default:
            printf("\nInvalid Input !!!");
            break;
        }
    } while (option < 3);
                        
                            
    return 0;
}
node * create_LL(node *start)
{
    node* new_node,*ptr;
    int num;
    printf("\nEnter -1 to stop\n");
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

void pallindrome(node * start)
{
    if(start==NULL||start->next==NULL)
    {
        printf("\nIts a Pallindrome\n");
    }
    else{
        node * rev_LL= rev(start);

        node * ptr1 = start;
        node * ptr2 = rev_LL;

        int flag = 1; 
        while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data != ptr2->data) {
            flag = 0; 
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next; 
    } 
    if(flag==1)
    {
        printf("\nIts a Pallindrome\n");
    }
    else
    {
        printf("\nIts not a pallindrome\n");
    }
    }
    
}
