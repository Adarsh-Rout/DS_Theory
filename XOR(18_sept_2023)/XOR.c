#include <stdio.h>
#include <malloc.h>

// Making structure for the Linked List
typedef struct node
{
    int data;
    struct node *npx;
} node;

node *start = NULL;
node *create(node *);
void display(node *);

// Main Function
void main()
{
    int option;
    do
    {
        printf("\n***MAIN MENU***");
        printf("\n1. Create XOR Linked List");
        printf("\n2. Display XOR Linked List");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            start = create(start);
            break;
        case 2:
            display(start);
            break;
        default:
            break;
        }
    } while (option != 3);
}

// Creating the XOR Linked List
node *create(node *start)
{
    int num;
    node *ptr = start;
    node *new_node;
    printf("\nEnter Data Element: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = malloc(sizeof(node));
        new_node->data = num;

        if (start == NULL)
        {

            new_node->npx = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->npx != NULL)
            {
                ptr = ptr->npx;
            }
            ptr->npx = new_node;
            new_node->npx = NULL;
        }
        printf("\nEnter data element: ");
        scanf("%d", &num);
    }
    return start;
}

// display XOR Linked List
void display(node *start)
{
    node *current = start;
    node *prev = NULL;

    if (current == NULL)
    {
        printf("\nEmpty Linked List\nNothing to display\n");
        return;
    }
    else
    {
        printf("\n So the XOR Linked List\n");
        while (current != NULL)
        {
            printf("%d ", current->data);
            unsigned temp = ((unsigned int)prev ^ (unsigned int)current->npx);
            current = (node *)temp;
            prev = current;

            if (current == NULL)
            {
                break; // Reached the end of the list
            }
            prev = (node *)((unsigned int)prev ^ (unsigned int)temp);
        }
        printf(" %d\n", prev->data);
    }
}