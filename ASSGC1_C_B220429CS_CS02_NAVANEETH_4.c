#include <stdio.h>
#include <string.h>
#include <math.h>
void initial(int hash[], int m)
{
  for (int i = 0; i < m; i++)
  {
    hash[i] = -1;
  }
}
int max_prime(int a)
{
  int count = 0;
  for (int i = a - 1; i >= 2; i--)
  {
    int k = i;
    count = 0;
    for (int j = k - 1; j >= 2; j--)
    {
      if (i % j == 0)
      {
        count = 1;
      }
    }
    if (count == 0)
    {

      return i;
    }
  }
}
void probe(int A[], int m, int hash[], int c)
{
  int count = 0;
  for (int i = 0; i < c; i++)
  {
    if (hash[A[i] % m] == A[i])
    {
      continue;
    }
    if (hash[A[i] % m] == -1)
    {
      hash[A[i] % m] = A[i];
      printf("%d ", A[i] % m);
    }

    else
    {
      for (int j = ((A[i] % m) + 1) % m; j != A[i] % m; j = (j + 1) % m)
      {
        count++;

        if (hash[j] == -1 || hash[A[i] % m] == A[i])
        {
          hash[j] = A[i];
          printf("%d ", j);
          break;
        }
      }
    }
  }
  printf("\n%d\n", count);
}
void quad(int A[], int m, int hash[], int c)
{
  int count = 0;
  for (int i = 0; i < c; i++)
  {
    if (hash[A[i] % m] == A[i])
    {
      continue;
    }
    if (hash[A[i] % m] == -1)
    {
      hash[A[i] % m] = A[i];
      printf("%d ", A[i] % m);
    }

    else
    {
      for (int j = 1;; j++)
      {
        count++;
        int ind = (A[i] % m + j * j) % m;

        if (hash[ind] == -1 || hash[ind] == A[i])
        {
          hash[ind] = A[i];
          printf("%d ", ind);
          break;
        }
      }
    }
  }
  printf("\n%d\n", count);
}

void doub(int A[], int m, int k, int hash[], int c)
{
  int count = 0;
  for (int i = 0; i < c; i++)
  {
    if (hash[A[i] % m] == A[i])
    {
      continue;
    }
    if (hash[A[i] % m] == -1)
    {
      hash[A[i] % m] = A[i];
      printf("%d ", A[i] % m);
    }

    else
    {
      int a = A[i] % m;
      int b = k - A[i] % k;
      for (int j = 1;; j++)
      {
        int ind = (a + j * b) % m;
        count++;

        if (hash[ind] == -1 || hash[ind] == A[i])
        {
          hash[j] = A[i];
          printf("%d ", ind);
          break;
        }
      }
    }
  }
  printf("\n%d\n", count);
}
int main()
{
  int a;
  scanf("%d", &a);
  int arr[a];
  initial(arr, a);
  int c = 0;
  for (int i = 0; i < a; i++)
  {

    scanf("%d", &arr[i]);
    c++;
    if (getchar() == '\n')
    {
      break;
    }
  }

  int hash1[a];
  initial(hash1, a);
  probe(arr, a, hash1, c);
  initial(hash1, a);
  quad(arr, a, hash1, c);
  initial(hash1, a);
  int k = max_prime(a);
  doub(arr, a, k, hash1, c);
  return 1;
}