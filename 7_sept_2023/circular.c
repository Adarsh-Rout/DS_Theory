#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}node;
node * start = NULL;
node * create(node *);
node* display(node *);
node * sort_list(node *);
node * delete_beg(node *);
node * delete_end(node *);
node * insert_beg(node *);
node * insert_end(node *);
node * insert_Middle(node *);
node * delete_Middle(node *);

int main() {
    // Enter CoDe
    int option;
    do{  
    printf("\n***MAIN MENU***");
    printf("\n 1. create a circular link list");
    printf("\n 2. display link list");    
    printf("\n 3. sort the list");  
    printf("\n 4. delete node at beginning");  
    printf("\n 5. delete node at end");  
    printf("\n 6. insert node at beginning");
    printf("\n 7. insert node at end"); 
    printf("\n 8. insert node at middle"); 
    printf("\n 9. delete node at middle");             
    printf("\n 10. exit");
    printf("\n Enter your option: "); 
    scanf("%d",&option);

    switch(option)
    {   case 1:
        start = create(start);  
        break;
        case 2:
        start = display(start);
        break;
        case 3:
        start = sort_list(start);
        break;
        case 4:
        start = delete_beg(start);
        break;
        case 5:
        start = delete_end(start);
        break;
        case 6:
        start = insert_beg(start);
        break;
        case 7:
        start = insert_End(start);
        break;
        case 8:
        start = insert_Middle(start);
        break;
        case 9:
        start = delete_Middle(start);
        break;
    }
    }while(option<10);                  
    return 0;
}

// create the link list

node * create(node * start)
{
    int num;
    node * ptr = NULL;
    node * new_node;
    
    printf("\n Enter -1 to end input");
    printf("\nEnter data element: ");
    scanf("%d",&num);
    
    
    while(num!=-1)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->data=num;
        if(start==NULL)
    {
        start = new_node;
        new_node->next=start;
    }else{
        ptr = start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }ptr->next = new_node;
        new_node->next = start;
    }
    printf("\nEnter data element: ");
    scanf("%d",&num);
    }
    return start;
}

// display the link list

node * display(node * start)
{
    node * ptr;
    ptr=start;
    if (ptr == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while(ptr->next!=start)
        {
            printf(" %d ->",ptr->data);
            ptr = ptr->next;
        }  printf(" %d\n", ptr->data);
    }printf("\n & the list goes on circulating . . .\n");

    return start;
}

// Sort the list

node * sort_list(node * start)
{
  node *ptr1,*ptr2;
  int temp;

  ptr1=start;
 
  while(ptr1->next != start)
  {

    ptr2=ptr1->next;

    while(ptr2 != start)
    {

      if(ptr1->data > ptr2->data)
      {
        temp=ptr1->data;
        ptr1->data=ptr2->data;
        ptr2->data=temp;
      }
      ptr2=ptr2->next;
    }
  ptr1=ptr1->next;
 }
 return start;
}

// Delete the beginning

node * delete_beg(node *start)
{

  node *ptr=start,*new_node=start;

     while(new_node->next!=start)
     {
        new_node = new_node->next;
     }
     start = start->next;
     new_node->next = start;
     if(ptr==new_node)
     {
        free(ptr);
        start = NULL;
     }
    else 
    {
        free(ptr);
    }
     return start;
}

// delete at end

node * delete_end(node *start)
{

  struct node *ptr,*preptr;

     ptr=start;

     while(ptr->next != start)
     {
      
       preptr=ptr;
       ptr=ptr->next;

     }
     preptr->next=start;
     free(ptr);

 return start;
}

// insert at beginning

node * insert_beg(node *start)
{
  node *ptr, *newNode;
    newNode = malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d", &newNode->data);
    if (start == NULL)
    {
        start = newNode;
        newNode->next = start;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        newNode->next = start;
        start = newNode;
        ptr->next = start;
    }
    return start;
}

// insert at end

node *insert_End(node *start)
{
    node *ptr, *newNode;
    newNode = malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d", &newNode->data);
    if (start == NULL)
    {
        start = newNode;
        newNode->next = start;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = start;
    }
    return start;
}

// insert at middle

node *insert_Middle(node *start)
{
    int pos;
    node *ptr, *prev, *newNode;
    newNode = malloc(sizeof(node));
    printf("Enter the position : ");
    scanf("%d", &pos);
    if (start == NULL)
    {
        start = newNode;
        newNode->next = start;
    }
    else
    {
        ptr = start;
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = ptr->next;
            if (ptr == start)
            {
                printf("Invalid Position\n");
                return start;
            }
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    printf("Enter the data : ");
    scanf("%d", &newNode->data);
    return start;
}

// delete at middle

node *delete_Middle(node *start)
{
    int pos;
    node *ptr, *prev;
    prev = start;
    ptr = start;
    printf("Enter the position : ");
    scanf("%d", &pos);
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            prev = ptr;
            ptr = ptr->next;
            if (ptr == start)
            {
                printf("Invalid Position\n");
                return start;
            }
        }
        if (pos == 0)
        {
            while (prev->next != start)
            {
                prev = prev->next;
            }
            start = start->next;
            prev->next = start;
        }
        prev->next = ptr->next;
    }
    if (ptr == prev)
    {
        free(ptr);
        start = NULL;
    }
    else
    {
        free(ptr);
    }
    return start;
}