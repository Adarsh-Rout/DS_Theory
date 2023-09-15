#include <stdio.h>
#include <malloc.h>

// structure declaration
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

// function declaration
node *start = NULL;
node *create_dll(node *);
node *display(node *);
node *insert_beg(node *);
node *insert_end(node *);
node *delete_beg(node *);
node *delete_end(node *);

// function call menu
int main()
{
    // Enter CoDe
    int num;
    do
    {

        printf("***MAIN MENU***\n");
        printf("1. Create circular double link list\n");
        printf("2. display the link list\n");
        printf("3. Insert node at start\n");
        printf("4. Insert node at end\n");
        printf("5. Delete node at start\n");
        printf("6. Delete node at end\n");
        printf("Enter your option: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            start = create_dll(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
            break;
        default:
            break;
        }
    } while (num != 7);
    return 0;
}

// create doubly circular link list

node *create_dll(node *start)
{
    int num;
    node *ptr, *new_node;
    printf("\n Enter data element: ");
    scanf("%d", &num);

    while (num != -1)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->data = num;

        if (start == NULL)
        {
            start = new_node;
            new_node->next = start;
            new_node->prev = start;
        }
        else
        {
            ptr = start;

            while (ptr->next != start)
                ptr = ptr->next;

            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = start;
        }
        printf("\nEnter data element: ");
        scanf("%d", &num);
    }
    return start;
}

// display doubly circular link list

node *display(node *start)
{
    node *ptr = start;
    while (ptr->next != start)
    {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d \n", ptr->data);
    return start;
}

// insert a new node at the beginning of the double circular linked list
node *insert_beg(node *start)
{
    node *new_node, *ptr = start;
    int num;

    printf("\n Enter data for new node: ");
    scanf("%d", &num);

    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = start;
    start = new_node;

    return start;
}

// insert a new node at the end of the double circular link list
node *insert_end(node *start)
{
    node *new_node, *ptr = start;
    int num;

    printf("\n Enter data for last new node: ");
    scanf("%d", &num);

    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = start;

    return start;
}

// delete a node at the beginning of the circular link list
node *delete_beg(node *start)
{
    node *ptr = start, *ptr1 = start;
    while (ptr1->next != start)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = start->next;
    start->next->prev = ptr1;
    start = start->next;
    free(ptr);

    return start;
}

// delete a node at the end of the circular link list
node *delete_end(node *start)
{
    node *ptr = start,*ptr1;
    while(ptr->next != start)
    {
        ptr1 = ptr;
        ptr = ptr->next;
        
    }
    ptr1->next = start;
    start->prev = ptr1;

    free(ptr);
    return start;
}