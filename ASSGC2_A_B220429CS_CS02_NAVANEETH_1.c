#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node 
{
  int data;
  struct node *right;
  struct node *left;
  int ht;
};
struct node *createnode(int key)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->right = NULL;
    temp->left = NULL;
  temp->data = key;
  int ht = 1;
  return temp;
}

int height(struct node *root)
{
  if (root == NULL)
    return 0;

  int lheight = height(root->left) + 1;
  int rheight = height(root->right) + 1;

  return (lheight > rheight) ? lheight : rheight;
}

int balance(struct node *root)
{
  if (root == NULL)
    return 0;
  return height(root->left) - height(root->right);
}

struct node * lr(struct node *root)
{
  struct node *x = root->right;
  root->right = x->left;
  x->left = root;
  root->ht = height(root);
  x->ht = height(x);
  return x;
}

struct node * rr(struct node *root)
{
  
  struct node *x = root->left;
  root->left = x->right;
  x->right = root;
  root->ht = height(root);
  x->ht = height(x);
  return x;
}

struct node *insert(struct node *root, int a,int *count1,int *count2)
{
 
  if (root == NULL)
  {
    struct node * temp = createnode(a);
    return temp;
  }
  else
  { 
    if (a > root->data)
    {
      root->right = insert(root->right, a,count1,count2);
    }
    else
    {
      root->left = insert(root->left, a,count1,count2);
    }
    root->ht = height(root);
     int bal = balance(root);
    
    if (bal > 1 && a < root->left->data)

    {
      (*count1)++;
      return rr(root);
    }
    if (bal < -1 && a > root->right->data)

    {
       (*count2)++;
      return lr(root);
    }
    if (bal > 1 && a > root->left->data)

    {
      (*count1)++;
      (*count2)++;
      root->left=lr(root->left);
      return rr(root);
    }
    if (bal < -1 && a < root->right->data)

     {  (*count2)++;
        (*count1)++;
       root->right=rr(root->right);
      return lr(root);
    }
  }
  return root;
}

void preorder(struct node*root)
{if(root!=NULL){
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
  }
}

int search(struct node *root, int a)
{
  if (root != NULL)
  {
    int arr[100];
    int i = 0;
    while (root != NULL && root->data != a)
    {
      arr[i++] = root->data;

      if (root->data > a)
      {
        root = root->left;
      }
      else
      {
        root = root->right;
      }
    }

    if (root == NULL)
    {
      printf("-1");
    }
    else
    {
      arr[i] = a;
      for (int j = 0; j <= i; j++)
      {
        printf("%d ", arr[j]);
      }
    }
  }
  else
  {
    printf("-1");
  }
}

    
int main()
{
  struct node *root = NULL ;
   char c[2];
  int a;
  int count1=0;
  int count2=0;
  while (1)
  {
    scanf("%s", c);
    c[1] = '\0';
    if (strcmp("e", c) == 0)
    {
      break;
    }
    else if (strcmp("i", c) == 0)
    {
      scanf("%d", &a);
      root=insert(root, a,&count2,&count1);
    }
      else if (strcmp("p", c) == 0)
    {
   preorder(root);
    printf("\n");
    }
       else if (strcmp("x", c) == 0)
    {
   scanf("%d", &a);
      search(root, a);
      printf("\n");
    }
    else if(strcmp("s",c)==0)
    {
      printf("%d %d\n",count1,count2);
      
    }
  }
  return 1;
}