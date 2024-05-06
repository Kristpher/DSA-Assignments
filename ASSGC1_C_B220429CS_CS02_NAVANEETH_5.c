#include <stdio.h>
void hash(int a, int b, int arr[], int new[])
{
  int count = 0;
  int n = 0;
  int j = 0;
  for (int i = 0; i < a; i++)
  {
    new[arr[i]]++;

    count++;
    if (new[arr[i]] > 1)
    {
      n++;
    }
    if (count == b)
    {
      printf("%d ", b - n);

      j++;

      count--;
      if (new[arr[i - b + 1]] > 1)
        n--;
    }
    if (i >= b - 1)
      new[arr[i - b + 1]]--;
  }
}

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  int arr[a];
  for (int i = 0; i < a; i++)
  {
    scanf("%d", &arr[i]);
  }
  int new[100000];
  for (int i = 0; i < a; i++)
  {
    if (new[arr[i]] != 0)
      new[arr[i]] = 0;
  }
  hash(a, b, arr, new);
  return 1;
}