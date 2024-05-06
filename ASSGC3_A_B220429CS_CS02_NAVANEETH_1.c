#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000
struct node
{
  int data;
  int color;
  struct node *next;
};

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

struct node *createnode(int key)
{
  struct node *temp =(struct node*) malloc(sizeof(struct node));
  temp->next = NULL;
  temp->color = 0;
  temp->data = key;
  return temp;
}
void graph2(struct node *arr[],int a)
{
      arr[a-1]=createnode(a);
}
struct node *graph(struct node *arr[], int a, int b)
{
  struct node *temp = createnode(b);
  if (arr[a-1]==NULL )
  {
   
    arr[a-1]=createnode(a);
   
    arr[a-1]->next = temp;
  }
  else
  {
    struct node *ptr=arr[a-1];
 
    while (ptr->next!=NULL)
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
void noc2(struct node *arr[], int c, int n)
{

  struct node *ptr = arr[(c)];
  
  while (ptr->next != NULL )
  {
   
    ptr->color = 1;
    ptr = ptr->next;
    arr[(ptr->data)-1]->color=1;
    
  }
}
int noc1(struct node *arr[], int n, int *ind)
{
  int count = 0;
   
  while (*ind < n) {
        if (arr[*ind] != NULL && arr[*ind]->color == 0) 
    {
      count++;
     
      int c = (*ind);
      noc2(arr, c, n);
    }
     if (arr[*ind] != NULL && arr[(*ind)]->color == 1)
    {
       
      int c = (*ind);
      noc2(arr, c, n);
    }
    (*ind)++;
  }
  return count;
}


int size2(struct node *arr[], int c, int n, int new[], int *m)
{
    struct node *ptr = arr[c];
    if(arr[(ptr->data)-1]->color==0)
    new[*m]++;
   
    while (ptr != NULL) {
        if (ptr->color == 0) {
            ptr->color = 1;
            size2(arr, (ptr->data )- 1, n, new, m);
        }
        ptr = ptr->next;
    }
}

void size_of_list(struct node *arr[], int n, int *ind, int new[], int *k)
{
    int m = 0;
    while (*ind < n) {
        if (arr[*ind] != NULL && arr[*ind]->color == 0) {
            int c = *ind;
            size2(arr, c, n, new, &m);
            (m)++;
        }
        (*ind)++;
    }
    (*k)=m-1;
}

void DFS(struct node* arr[], int u, int disc[], int low[], int parent, int* bridgeCount) {
    static int time = 0;
    disc[u] = low[u] = ++time;
    arr[u]->color = 1;

    struct node* current = arr[u]->next;
    while (current != NULL) {
        int v = current->data - 1;
        if (disc[v] == -1) {
            DFS(arr, v, disc, low, u, bridgeCount);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            if (low[v] > disc[u]) {
                (*bridgeCount)++;
            }
        } else if (v != parent) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
        current = current->next;
    }
}

int bridge(struct node* arr[], int n) {
    int disc[MAX_NODES];
    int low[MAX_NODES];
    int bridgeCount = 0;

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            DFS(arr, i, disc, low, -1, &bridgeCount);
        }
    }

    return bridgeCount;
}




void DFS2(struct node* arr[], int u, int disc[], int low[], int parent, bool articulation[]) {
    static int time = 0;
    disc[u] = low[u] = ++time;
    arr[u]->color = 1;

    int children = 0;
    struct node* current = arr[u]->next;
    while (current != NULL) {
        int v = current->data - 1;
        if (disc[v] == -1) {
            children++;
            DFS2(arr, v, disc, low, u, articulation);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            if (parent != -1 && low[v] >= disc[u]) {
                articulation[u] = true;
            }
        } else if (v != parent) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
        current = current->next;
    }

    if (parent == -1 && children > 1) {
        articulation[u] = true;
    }
}

int articulation(struct node* arr[], int n, bool articulation[]) {
    int disc[MAX_NODES];
    int low[MAX_NODES];

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
        articulation[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            DFS2(arr, i, disc, low, -1, articulation);
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (articulation[i]) {
            count++;
        }
    }

    return count;
}

int main()
{
  int n;
  int index = -1;
  scanf("%d", &n);
  struct node *arr[n];
  for(int i=0;i<n;i++)
  {
      arr[i]=NULL;
  }

  char c[2];
  int a,  b, d;
  int l=0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &b);
    while (getchar() != '\n')
    {
    l=1;
    scanf("%d", &a);
   
      graph(arr, b, a);
    }
    if(l==0)
    {
        graph2(arr,b);
    }
  }
 

 
 while (1)
  {
    scanf("%s", c);
    if (strcmp("t", c) == 0)
    {
      break;
    }
     else  if (strcmp("n", c) == 0)
    { int ind=0;
      initial(arr,n);
      int ans=noc1(arr,n,&ind);
      printf("%d\n",ans);
    }
   
         else  if (strcmp("s", c) == 0)
    { int ind=0;
       initial(arr,n);
        int new[n];
        for(int i=0;i<n;i++)
        {
            new[i]=0;
        }
        int k=-1;
        size_of_list(arr,n,&ind,new,&k);
        for(int i=0;i<=k;i++){
            for(int j=i+1;j<=k;j++)
            {   if(new[i]>new[j])
                swap(&new[i],&new[j]);
            }
        }
        for(int i =0;i<=k;i++)
        {
            printf("%d ",new[i]);
           
        }
         printf("\n");
    }
         else  if (strcmp("b", c) == 0)
    { int ind=0;
     
      initial(arr,n);
     int ans= bridge(arr,n);
          if(ans==0)
            printf("%d\n",-1);
            else
            printf("%d\n", ans);
    }
   else if (strcmp("a", c) == 0) {
            bool articulationPoints[n];
            initial(arr, n);
            int ans = articulation(arr, n, articulationPoints);
            if(ans==0)
            printf("%d\n",-1);
            else
            printf("%d\n", ans);
        }
  }
  return 0;
}