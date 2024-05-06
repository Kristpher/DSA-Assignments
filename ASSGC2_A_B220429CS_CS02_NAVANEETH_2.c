
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
  int key;
  int val;
  struct node *right;
  struct node *left;
  int ht;
};
struct node *createnode(int data1, int data2)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->right = NULL;
  temp->left = NULL;
  temp->key = data1;
  temp->val = data2;
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

struct node *lr(struct node *root)
{
  struct node *x = root->right;
  root->right = x->left;
  x->left = root;
  root->ht = height(root);
  x->ht = height(x);
  return x;
}

struct node *rr(struct node *root)
{

  struct node *x = root->left;
  root->left = x->right;
  x->right = root;
  root->ht = height(root);
  x->ht = height(x);
  return x;
}

struct node *insert(struct node *root, int a,int b)
{

  if (root == NULL)
  {
    struct node *temp = createnode(a,b);
    return temp;
  }
  else
  {
    if (a > root->key)
    {
      root->right = insert(root->right, a,b);
    }
    else if (a < root->key)
    {
      root->left = insert(root->left, a,b);
    }
    else
    {
      root->val = b;
    }
    root->ht = height(root);
    int bal = balance(root);

    if (bal > 1 && a < root->left->key)

    {

      return rr(root);
    }
    if (bal < -1 && a > root->right->key)

    {

      return lr(root);
    }
    if (bal > 1 && a > root->left->key)

    {

      root->left = lr(root->left);
      return rr(root);
    }
    if (bal < -1 && a < root->right->key)

    {
      root->right = rr(root->right);
      return lr(root);
    }
  }
  return root;
}
void lb(struct node *root, int data,int *p)
{
if(root!=NULL)
{
    if(data<=root->key)
    {
        if((*p)>=root->key)
        (*p)=root->key;
    }
    lb(root->left,data,p);
    lb(root->right,data,p);
}
    
}
     
   
  

void search(struct node *root, int data)
{
  if (root != NULL)
  {
    while (root != NULL && data != root->key)
    {
      if(root->key<data)
      root = root->right;
      else
      root=root->left;
    }

    if (root == NULL)
    {
      printf("-1");
    }
    else
    {
      printf("%d %d", root->key, root->val);
    }
  }
  else
    printf("-1");
}

void size(struct node *root,int *count)
{
  if (root != NULL)
  {
    (*count)++;
    size(root->left,count);
    size(root->right,count);
  }
}

void inorder(struct node *root)
{
  if (root != NULL)
  {

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }

}

int main()
{
  struct node *root = NULL;
  char c[2];
  int a, b;
  int count=0;

  while (1)
  {
    scanf("%s", c);
    c[1] = '\0';
    if (strcmp("t", c) == 0)
    {
      break;
    }
    else if (strcmp("i", c) == 0)
    {
      scanf("%d%d", &a, &b);
      root = insert(root, a, b);
    }
    else if (strcmp("p", c) == 0)
    {if (root!=NULL)
      inorder(root);
     else
        printf("-1");
      printf("\n");
    }
        else if (strcmp("l", c) == 0)
    {  int p=100000000;
       int b=p;
        scanf("%d", &a);
      lb(root,a,&p);
      if (b==p)
      {
          printf("-1\n");
      }
      else{
      search(root,p);
      printf("\n");
      }
    }
      else if (strcmp("s", c) == 0)
    {
      size(root,&count);
      printf("%d\n",count);
      count=0;
    }
    else if (strcmp("f", c) == 0)
    {
      scanf("%d", &a);
      search(root, a);
      printf("\n");
    }
      else if (strcmp("e", c) == 0)
    {
    
     if(root!=NULL)
     {
      printf("0\n");
     }
     else
      printf("1\n");
      
    }
  }
  return 1;
}