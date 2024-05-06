#include <stdio.h>
#include <string.h>
void initial(int hash[], int m)
{
  for (int i = 0; i < m; i++)
  {
    hash[i] = -1;
  }
}

void insertion(int A[], int hash[], int a, int m)
{
  for (int i = 0; i < a; i++)
  {
    if (hash[A[i]%m] == A[i])
    {
      continue;
    }
    if (hash[A[i] % m] == -1)
    {
      hash[A[i] % m] = A[i];
    }

    else
    {
      for (int j = ((A[i] % m )+ 1) % m; j != A[i] % m; j = (j + 1) % m)
      {

        if (hash[j] == -1 || hash[A[i]%m] == A[i])
        {
          hash[j] = A[i];
          break;
        }
      }
    }
  }
}

void nonin(int arr[], int key, int m)
{
  for (int i = 0; i < m; i++)
  {
    if (key == arr[i])

      arr[i] = -1;
  }
}
int search(int hash[], int m, int key)
{
  for (int i = 0; i < m; i++)
  {
    if (hash[i] == key)
      return 1;
  }
  return 0;
}

void uni(int A[], int B[], int a, int b, int m)
{if(a==0 && b==0)
{
  printf("-1");
  return ;
}
  int hash1[m];
  initial(hash1, m);
  insertion(A, hash1, a, m);
  int hash2[m];
  int hash[b];
  initial(hash2, m);
  insertion(B,hash2,b,m);
  int j = 0;

 for(int i=0;i<b;i++)
 {
   if (search(hash1, m, B[i]) == 0 && search(hash2, m, B[i]) == 1)
    {
      hash[j]=B[i];
      
      nonin(hash2, B[i], m);
      j++;
    }
 
 } 
  for (int i = 0; i < a; i++)
  {
    if (search(hash1, m, A[i]) == 1)
    {
      printf("%d ", A[i]);
      nonin(hash1, A[i], m);
    }
  }

   for(int i=0;i<j;i++)
   {
    printf("%d ",hash[i]);
   }
 
}

void inter(int A[], int B[], int a, int b, int m)
{
  int hash1[m];
  initial(hash1, m);
  insertion(A, hash1, a, m);
  int hash2[m];
  initial(hash2, m);
  insertion(B, hash2, b, m);
  int count=0;
  for (int i = 0; i < a; i++)
  {
    if (search(hash1, m, A[i]) == 1 && search(hash2, m, A[i]) == 1)
    {count++;
      printf("%d ", A[i]);
      nonin(hash1,A[i],m);
    }
  }
  if(count==0)
  {
    printf("-1");
  }
}

void diff(int A[], int B[], int a, int b, int m)
{
  int hash1[m];
  initial(hash1, m);
  insertion(A, hash1, a, m);
  int hash2[m];
  initial(hash2, m);
  insertion(B, hash2, b, m);
  int count=0;
  for (int i = 0; i < a; i++)
  {
    if (search(hash1, m, A[i]) == 1 && search(hash2, m, A[i]) == 0)
    {count++;
      printf("%d ", A[i]);
      nonin(hash1,A[i],m);
    }
  }
  if (count==0)
  printf("-1");
}

int main()
{
  int a, b, m;
  scanf("%d %d", &a, &b);
  if (a >= b)
  {
    m = 2 * a;
  }
  else
  {
    m = 2 * b;
  }
  int A[a];
  int B[b];
  for (int i = 0; i < a; i++)

  {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < b; i++)

  {
    scanf("%d", &B[i]);
  }
  int arr[m];

  char c[2];
  c[1] = '\0';
  char z[2];
  char x[2];
  z[1] = '\0';
  x[1] = '\0';
  while (1)
  {
    scanf("%s", c);
    if (strcmp("e", c) == 0)
    {
      break;
    }
    else if (strcmp("u", c) == 0)
    {
      scanf("%s%s", z, x);
      if (strcmp("A", z) == 0)
      {
        uni(A, B, a, b, m);
      }
      else if (strcmp("A", x) == 0)
      {
        uni(B, A, b, a, m);
      }
      printf("\n");
    }
    else if (strcmp("i", c) == 0)
    {
      scanf("%s%s", z, x);
      if (strcmp("A", z) == 0)
      {
        inter(A, B, a, b, m);
      }
      else if (strcmp("A", x) == 0)
      {
        inter(B, A, b, a, m);
      }

      printf("\n");
    }
    else if (strcmp("s", c) == 0)
    {
      scanf("%s%s", z, x);
      if (strcmp("A", z) == 0)
      {
        diff(A, B, a, b, m);
      }
      else if (strcmp("B", z) == 0)
      {
        diff(B, A, b, a, m);
      }
      printf("\n");
    }
  }
  return 0;
} 