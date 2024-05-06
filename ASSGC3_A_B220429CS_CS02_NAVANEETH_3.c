#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    int color;
    struct node *next;
};

struct node *createnode(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->color = 0;
    temp->data = key;
    return temp;
}
void graph2(struct node *arr[],int a)
{
     arr[a] = createnode(a);
}
struct node *graph(struct node *arr[], int a, int b)
{
    struct node *temp = createnode(b);
    if (arr[a] == NULL)
    {

        arr[a] = createnode(a);

        arr[a]->next = temp;
    }
    else
    {
        struct node *ptr = arr[a];

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void initial(struct node *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        struct node *ptr = arr[i];
        while (ptr != NULL)
        {
            ptr->color = 0;
            ptr = ptr->next;
        }
    }
}



void paths(struct node *arr[], int *n, int a, int b, int *c, int new[])
{
    if (a == b)
    {   
        for (int i = 0; i < *c; i++)
        {
            printf("%d ", new[i]);
        }
        (*n)=1;
        printf("\n");
        return;
    }

    
    arr[a]->color = 1;

    struct node *temp = arr[a]->next;

    while (temp != NULL)
    {
        if (arr[temp->data]->color == 0)
        {
            new[(*c)++] = temp->data; 
            paths(arr, n, temp->data, b, c, new);
            (*c)--; 
        }
        temp = temp->next;
    }

    
    arr[a]->color = 0;
}


bool DFS(struct node* arr[], int u, int parent) {
    arr[u]->color = 1;

    struct node* temp = arr[u]->next;
    while (temp != NULL) {
        int v = temp->data;
        if (arr[v]->color == 0) {
            if (DFS(arr, v, u))
                return true;
        } else if (v != parent) {
            return true; 
        }
        temp = temp->next;
    }
    return false;
}

int cyclecheck(struct node *arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != NULL && arr[i]->color == 0) {
            if (DFS(arr, i, -1))
                return 0; 
        }
    }
    return 1; 
}

void noc2(struct node *arr[], int c, int n)
{

  struct node *ptr = arr[(c)];
  while (ptr->next != NULL )
  {
    ptr->color = 1;
    ptr = ptr->next;
    arr[(ptr->data)]->color=1;
    
  }
}
int connected(struct node *arr[], int n, int *ind)
{
  int count = 0;
   
  while (*ind < n) {
        if (arr[*ind] != NULL && arr[*ind]->color == 0) 
    {
      count++;
     
      int c = (*ind);
      noc2(arr, c, n);
    }
     if (arr[(*ind)]->color == 1)
    {
      int c = (*ind);
      noc2(arr, c, n);
    }
    (*ind)++;
  }
  
  if(count==1)
  return 1;
  else if(count>1)
  return 0;
}


void check(struct node *arr[],int n)
{int ind=0;
int b=0,a=0;
     a=cyclecheck(arr,n);
     
     initial(arr,n);
    if(a==1)
     b=connected(arr,n,&ind);
    
    if(a==1 && b==1)
    printf("1\n");
    else
    printf("-1\n");
}



int main()
{
    int n;
    int index = -1;
    scanf("%d", &n);
    struct node *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = NULL;
    }
    
    char c[2];
    int a, b, d;
    int l=0;
    for (int i = 0; i < n; i++)
    {   l=0;
        scanf("%d", &b);
        
        
        while (getchar() != '\n')
        {
            l=1;
            scanf("%d", &a);

            graph(arr, b, a);
        }
        if(l==0)
        graph2(arr,b);
        
    }

    while (1)
    {
        scanf("%s", c);
        c[1]='\0';
        if (strcmp("x", c) == 0)
        {
            break;
        }

         else if (strcmp("t", c) == 0)
        {
            initial(arr,n);
            check(arr,n);
           
        }
        
        else if (strcmp("a", c) == 0)
        {
            int new[n];
            int d = 1;
            int k=0; 
            scanf("%d%d",&a,&b);
            new[0] = a;
            paths(arr, &k, a, b, &d, new);
            if(k==0)
            printf("-1\n");
        }
    }
    return 0;
}
 