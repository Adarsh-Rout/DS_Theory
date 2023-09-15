// WRITE A PROGRAM TO DELETE A NODE FROM END OF SINGLY LINK LIST.
#include <stdio.h>
#include <malloc.h>

struct node
{
  int data;
  struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *delete_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_node(struct node *, int);
struct node *delete_even(struct node *);

void main()
{
  int option;

  do
  {
    printf("\n****MAIN MENU****");
    printf("\n 1. create link list");
    printf("\n 2. Display link list");
    printf("\n 3. Delete_even data");
    printf("\n Enter your option: ");
    scanf("%d", &option);

    switch (option)
    {

    case 1:

      start = create_ll(start);
      printf("\n link list created");
      break;
    case 2:
      start = display(start);
      break;
    case 3:
      start = delete_even(start);
      break;
    }

  } while (option != 4);
}

// create the link list
struct node *create_ll(struct node *start)
{

  struct node *new_node, *ptr;
  int num;
  printf("\n Enter -1 to end");
  printf("\n Enter the data :");
  scanf("%d", &num);

  while (num != -1)
  {

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL)
    {
      new_node->next = NULL;
      start = new_node;
    }
    else
    {

      ptr = start;

      while (ptr->next != NULL)
        ptr = ptr->next;

      ptr->next = new_node;
      new_node->next = NULL;
    }
    printf("\n Enter the data :");
    scanf("%d", &num);
  }
  return start;
}

// display the link list
struct node *display(struct node *start)
{
  struct node *ptr;
  ptr = start;

  while (ptr != NULL)
  {

    printf("\t %d", ptr->data);
    ptr = ptr->next;
  }
  return start;
}

// delete end node
struct node *delete_end(struct node *start)
{

  struct node *ptr, *preptr;

  ptr = start;

  while (ptr->next != NULL)
  {

    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = NULL;
  free(ptr);

  return start;
}

// delete begin node
struct node *delete_beg(struct node *start)
{

  struct node *ptr;

  ptr = start;
  start = start->next;
  free(ptr);

  return start;
}

// delete the given data node

struct node *delete_node(struct node *start, int val)
{
  struct node *ptr, *preptr;
  ptr = start;

  if (ptr->data == val)
  {
    start = delete_beg(start);
    return start;
  }
  else
  {
    while (ptr->data != val)
    {
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
  }
}

// delete the even data node
struct node *delete_even(struct node *start)
{
  struct node *ptr = start;
  struct node *preptr = start;


  // Traverse the list and delete even nodes
  while (ptr != NULL)
  {
    preptr = ptr;
    ptr = ptr->next;
    if (start->data % 2 == 0)
    {
      start = delete_beg(start);
    }
    else
    {
      if (preptr->data % 2 == 0)
      {
        start = delete_node(start, preptr->data);
      }
    }
  }

  return start;
}
