#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
  struct node *parent;
  int color;
};
struct node *createnode(int key)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->left = NULL;
  temp->right = NULL;
  temp->data = key;
  temp->color = 1;
  temp->parent = NULL;
  return temp;
}

struct node *beg(struct node *root, int key)
{
  if (root == NULL)
  {
    struct node *temp = createnode(key);
    return temp;
  }
  if (root->data > key)
  {
    root->left = beg(root->left, key);
    root->left->parent = root;
  }
  else
  {
    root->right = beg(root->right, key);
    root->right->parent = root;
  }
  return root;
}

struct node *lr(struct node *ptr, struct node *root)
{
  struct node *r = ptr->right;
  ptr->right = r->left;
 
   if (ptr->right )
  {
    ptr->right->parent = ptr;
    r->parent = ptr->parent;
  }
 
  if (!ptr->parent)
  {
    root = r;
  }
 
  else if (ptr == ptr->parent->left)
  {
    ptr->parent->left = r;
  }
  else
  {
    ptr->parent->right = r;
  }
    r->left = ptr;
    ptr->parent = r;

  return root;
}

struct node *rr(struct node *ptr, struct node *root)
{
  struct node *r = ptr->left;
  ptr->left = r->right;
  
    if (ptr->left)
  {
    ptr->left->parent = ptr;
    r->parent = ptr->parent;
  }
  
  if (!ptr->parent)
  {
    root = r;
  }

  else if (ptr == ptr->parent->left)
  {
    ptr->parent->left = r;
  }
  else
  {
    ptr->parent->right = r;
  }
    r->right = ptr;
    ptr->parent = r;
 
  return root;
}

struct node *search(struct node *root, int key)
{
  if (root != NULL)
  {
    struct node *ptr = root;
    while (ptr != NULL && key != ptr->data)
    {
      if (ptr->data < key)
        ptr = ptr->right;
      else
        ptr = ptr->left;
    }
    if (ptr != NULL)
    {
      return ptr;
    }
    
  }
}

struct node *rb(struct node *root, int key)
{
  struct node *temp = search(root, key);
  struct node *par = NULL;
  struct node *uncle = NULL;
  struct node *grandpa = NULL;
  while (temp != root && temp->parent->color == 1 && temp->color != 0)
  {
    par = temp->parent;
    grandpa = temp->parent->parent;

    if (grandpa->left == par)
    {
      uncle = grandpa->right;
      if (uncle != NULL && uncle->color == 1)
      {
        uncle->color = 0;
        grandpa->color = 1;
        par->color = 0;
        temp = grandpa;
      }
      else
      {
        if (temp == par->right)
        {
          root = lr(par, root);
          temp = par;
          par = temp->parent;
        }
        root = rr(grandpa, root);
        int c = par->color;
        par->color = grandpa->color;
        grandpa->color = c;
        temp = par;
      }
    }
    else
    {
      struct node *uncle = grandpa->left;

      if ((uncle != NULL) && (uncle->color == 1))
      {
        grandpa->color = 1;
        par->color = 0;
        uncle->color = 0;
        temp = grandpa;
      }
      else
      {

        if (temp == par->left)
        {
          root = rr(par, root);
          temp = par;
          par = temp->parent;
        }

        root = lr(grandpa, root);
        int c = par->color;
        par->color = grandpa->color;
        grandpa->color = c;
        temp = par;
      }
    }
  }
  return root;
}

void preorder(struct node *root)
{
    if(root==NULL)
    printf("()");
  if (root != NULL)
  {
    printf("(");
    printf("%d ", root->data);
    if (root->color == 0)
    {
      printf("B");
    }
    else
    {
      printf("R");
    }
    preorder(root->left);
    preorder(root->right);
    printf(")");
  }
}

int main()
{
  struct node *root = NULL;
  int key;
  while (1)
  {
      scanf("%d", &key);
      root = beg(root, key);
      root->color = 0;
      root = rb(root, key);
      root->color = 0;
      preorder(root);
    
  }

  return 1;
}