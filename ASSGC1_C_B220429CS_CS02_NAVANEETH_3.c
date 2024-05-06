#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
  char name[100];
  char roll[100];
  int age;

  struct node *next;
};
int inde(char name[], int age)
{
  int sum = 0;
  for (int i = 0; i < strlen(name); i++)
  {
    sum = sum + name[i];
  }
  return (sum + age) % 4;
}

struct node *createnode(char name1[], char roll1[], char age1)
{
  struct node *temp = malloc(sizeof(struct node));
  strcpy(temp->name, name1);
  strcpy(temp->roll, roll1);
  temp->age = age1;
  temp->next = NULL;
  return temp;
}

void insert(struct node *arr[], char name1[], char roll1[], int age1)
{
  int ind = inde(name1, age1);

  if (arr[ind] == NULL)
  {
    arr[ind] = createnode(name1, roll1, age1);
  }
  else
  {
    struct node *temp = createnode(name1, roll1, age1);
    struct node *ptr = arr[ind];
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

void func1(struct node *arr[], int k)
{
  struct node *ptr = arr[k];
  int count = 0;
  while (ptr != NULL)
  {
    count++;
    ptr = ptr->next;
  }
  printf("%d ", count);
  ptr = arr[k];
  while (ptr != NULL)
  {

    printf("%s ", ptr->name);
    ptr = ptr->next;
  }
}

void toup(char c[])
{
  for (int i = 0; i < 2; i++)
  {
    if (c[i] > 96)
    {
      c[i] = c[i] - 32;
    }
  }
}

void funct2(struct node *arr[], int m, char c[])
{
  struct node *ptr = arr[m];
  char new[3];

  int count = 0;
  while (ptr != NULL)
  {
    int j = 0;
    for (int i = strlen(ptr->roll) - 2; i < strlen(ptr->roll); i++)
    {
      new[j] = ptr->roll[i];

      j++;
    }
    toup(c);
    if (strcmp(new, c) == 0)
    {
      count++;
      printf("%s", ptr->name);
    }

    ptr = ptr->next;
  }
  if (count == 0)
  {
    printf("-1");
  }
}

int main()
{
  int a;
  scanf("%d", &a);
  char name[100];
  char roll[100];
  int age;
  struct node *arr[4];
  for (int i = 0; i < 4; i++)
  {
    arr[i] = NULL;
  }
  for (int i = 0; i < a; i++)
  {
    scanf("%s", name);
    name[strlen(name)] = '\0';
    scanf("%s", roll);
    roll[strlen(roll)] = '\0';
    scanf("%d", &age);
    insert(arr, name, roll, age);
  }
  char c[2];

  int k;
  char ch1[3];

  while (1)
  {
    scanf("%s", c);
    c[1] = '\0';
    if (strcmp("e", c) == 0)
    {
      break;
    }
    else if (strcmp("c", c) == 0)
    {
      scanf("%d", &k);
      func1(arr, k);
      printf("\n");
    }
    else if (strcmp("0", c) == 0 || strcmp("1", c) == 0 || strcmp("2", c) == 0 || strcmp("3", c) == 0)
    {
      scanf("%s", ch1);
      ch1[2] = '\0';
      int m = atoi(c);
      funct2(arr, m, ch1);
      printf("\n");
    }
  }

  return 0;
}