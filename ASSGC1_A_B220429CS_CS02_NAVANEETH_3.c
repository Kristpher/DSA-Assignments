#include <stdio.h>
#include <string.h>
struct det
{
  char name[1000];
  int prio;
  char times[6];
};
void swap(struct det *a, struct det *b)
{
  struct det temp = *a;
  *a = *b;
  *b = temp;
}


int maxheapify(struct det arr[], int *n, int i)
{

  int largest = i;
  int r = 2 * i + 2;
  int l = 2 * i + 1;

  if ((l < (*n)) &&( arr[largest].prio < arr[l].prio||(arr[largest].prio == arr[l].prio && strcmp(arr[l].times, arr[largest].times) < 0)))
    largest = l;
  if ((r < (*n)) &&( arr[largest].prio < arr[r].prio||(arr[largest].prio == arr[r].prio && strcmp(arr[r].times, arr[largest].times) < 0)))
    largest = r; 


if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    maxheapify(arr, n, largest);
  }
  
}

int built_max_heap(struct det arr[], int *n)
{
  int i;
  for (i = ((*n) / 2) - 1; i >= 0; i--)
    maxheapify(arr, n, i);
}



void admitPatient(struct det arr[], int *a, char name[], int prio, char times[])
{   (*a)++;
    arr[(*a)-1].prio = prio;
  strcpy(arr[(*a)-1].name, name);
  strcpy(arr[(*a)-1].times, times);
  
  built_max_heap(arr, a);
}

void treatNextPatient(struct det arr[], int *a)
{
  if (*a == 0)
  {
    printf("%d\n", -1);
  }
  else
  {
     
    printf("%s %d %s\n", arr[0].name, arr[0].prio, arr[0].times);
    swap(&arr[0], &arr[(*a) - 1]);
    (*a)--;
    built_max_heap(arr, a);
  }
}

void check(struct det arr[])
{
  printf("%s %d %s\n", arr[0].name, arr[0].prio, arr[0].times);
}

void discharge(struct det arr[], char name[], char times[], int *a)
{
  for (int i = 0; i < *a; i++)
  {
    if ((strcmp(name, arr[i].name) == 0) && (strcmp(times, arr[i].times) == 0))
    {
      swap(&arr[i], &arr[(*a) - 1]);
      (*a)--;
      built_max_heap(arr, a);
      break;
    }
  }
}

void update(struct det arr[], char name[], char times[], int *a, int prio)
{
  for (int i = 0; i < *a; i++)
  {
    if ((strcmp(name, arr[i].name) == 0) && (strcmp(times, arr[i].times) == 0))
    {
      arr[i].prio = prio;
      
      built_max_heap(arr, a);
      break;
    }
  }
}

void printAll(struct det arr[], int *a)
{  if (*a == 0)
  {
    printf("%d\n", -1);
    return;
  }
    
    for (int i = (*a) - 1; i >0; i--) {
      swap(&arr[0], &arr[i]);
      maxheapify(arr, &i, 0);
    }
  for (int i =(*a)-1; i>=0 ; i--)
  {
    printf("%s %d %s\n", arr[i].name, arr[i].prio, arr[i].times);
    
    
  }built_max_heap(arr, a);
   
}

int main()
{
  char c[2];
  struct det arr[1000];
  int a = 0;
  char n[100];
  char t[100];
  int p;
  while (1)
  {
    scanf("%c", c);
    c[1] = '\0';

    if (strcmp(c, "e") == 0)
    {
      break;
    }
    else if (strcmp(c, "a") == 0)
    {
      scanf("%s %d %s", n, &p, t);
      admitPatient(arr, &a, n, p, t);
    }
    else if (strcmp(c, "t") == 0)
    {
      treatNextPatient(arr, &a);
    }
    else if (strcmp(c, "c") == 0)
    {
      check(arr);
    }
    else if (strcmp(c, "d") == 0)
    {
      scanf("%s %s", n, t);
      discharge(arr, n, t, &a);
    }
    else if (strcmp(c, "u") == 0)
    {
      scanf("%s %s %d", n, t, &p);
      update(arr, n, t, &a, p);
    }
    else if (strcmp(c, "p") == 0)
    {
      printAll(arr, &a);
    }
  }
  return 1;
}