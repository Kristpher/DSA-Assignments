#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
  int data;
  struct node *next;
};

struct node *createnode(int key)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->next = NULL;
  temp->data = key;
  return temp;
}

void insert(int tab, struct node *arr[], int a)
{
  struct node *ptr = NULL;
  if (arr[a % tab]->data == -1)
  {
    arr[a % tab]->data = a;
  }
  else if (arr[a % tab]->data != -1)
  {
    if (a == arr[a % tab]->data)
    {
      printf("-1\n");
      return;
    }

    else if (a > arr[a % tab]->data)
    {
      struct node *temp = createnode(a);
      if (arr[a % tab]->next == NULL)
      {
        arr[a % tab]->next = temp;
      }
      else
      {
        struct node *ptr2 = NULL;
        ptr = arr[a % tab];
        while (ptr->data < a && ptr->next != NULL)
        {
          ptr2 = ptr;
          ptr = ptr->next;
        }
        if (ptr->data == a)
        {
          printf("-1");
          return;
        }
        if (ptr->next == NULL && ptr->data < a)
        {
          ptr->next = temp;
        }
        else
        {
          temp->next = ptr;
          ptr2->next = temp;
        }
      }
    }
    else if (a < arr[a % tab]->data)
    {
      
    
        struct node *temp = createnode(a);
        temp->next = arr[a % tab];
        arr[a % tab] = temp;
      
    }
  }
}
struct node *search(int tab, struct node *arr[], int a)
{
  struct node *ptr = arr[a % tab];
  struct node *ptr2 = NULL;
  if (a == ptr->data)
  {
    printf("%d %d", a % tab, 1);
    return arr[a % tab];
  }
  else
  {
    int count = 1;
    while (ptr->next != NULL && ptr->data != a)
    {
      count++;
      ptr2 = ptr;
      ptr = ptr->next;
    }
    if (ptr->next == NULL && ptr->data != a)
    {
      printf("-1");
      return 0;
    }
    printf("%d %d", a % tab, count);
    return ptr2;
  }
}

struct node *delete(int tab, struct node *arr[], int a)
{
  struct node *temp = search(tab, arr, a);
  if (temp != 0)
  {

    if (temp->data == arr[a % tab]->data)
    {
      if (temp->next == NULL)
      {
        temp->data = -1;
        return 0;
      }

      struct node *ptr = temp->next;
      temp->data = ptr->data;
      temp->next = ptr->next;
      free(ptr);
    }
    else
    {
      struct node *temp2 = temp->next;

      if (temp2->next == NULL)
      {
        temp->next = NULL;
        free(temp2);
      }

      else
      {
        temp->next = temp2->next;
        free(temp2);
      }
    }
  }
}

void update(int tab, struct node *arr[], int a, int b)
{
  struct node *link=arr[b%tab];
   while(link!=NULL)
   {if(b==link->data)
   {
    printf("-1");
    return;
   }
    link=link->next;
    
   }
    struct node *temp = search(tab, arr, a);
    if (temp != 0)
    {struct node *temp2 = temp->next;

      if (temp->data == arr[a % tab]->data &&temp->data==a )
      {
        if (temp->next == NULL)
        {
          temp->data = -1;
          
        }
       else{
        struct node *ptr = temp->next;
        temp->data = ptr->data;
        temp->next = ptr->next;
        free(ptr);
       }
      }
      else
      {
        
        if (temp2->next == NULL)
        {
          temp->next = NULL;
          free(temp2);
        }

        else
        {
          temp->next = temp2->next;
          free(temp2);
        }
      }

      insert(tab, arr, b);
      return;
    }
  
}
struct node *print_elements(int tab, int index, struct node *arr[])
{
  if (arr[index]->data != -1)
  {
    struct node *ptr = arr[index];
    while (ptr != NULL)
    {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    }
  }
  else
    printf("-1");
}

int main()
{
  int tab;
  scanf("%d ", &tab);
  char c[2];
  struct node *arr[tab];
  for (int i = 0; i < tab; i++)
  {
    arr[i] = createnode(-1);
  }
  c[1] = '\0';
  int a, b;
  while (1)
  {
    scanf("%s", c);
    if (strcmp("e", c) == 0)

    {
      break;
    }

    else if (strcmp("i", c) == 0)

    {

      scanf("%d", &a);
      insert(tab, arr, a);
      
    }
    else if (strcmp("s", c) == 0)

    {
      scanf("%d", &a);
      search(tab, arr, a);
      printf("\n");
    }
    else if (strcmp("d", c) == 0)

    {
      scanf("%d", &a);
      delete (tab, arr, a);
      printf("\n");
    }
    else if (strcmp("u", c) == 0)

    {
      scanf("%d%d", &a, &b);
      update(tab, arr, a, b);
      printf("\n");
    }
    else if (strcmp("p", c) == 0)

    {
      scanf("%d", &a);
      print_elements(tab, a, arr);
      printf("\n");
    }
  }
}