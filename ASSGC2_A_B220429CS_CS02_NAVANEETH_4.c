#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct node
{
  int key;
  struct node *left;
  struct node *right;
  struct node *p;
  int color;
};


struct node *createnode(int data)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->key = data;
  temp->left = NULL;
  temp->right = NULL;
  temp->p = NULL;
  temp->color = 0;
  return temp;
}


struct node *tree(char* s){
    int i=0,top=-1;
    struct node* stack[100];
    while(i<strlen(s)){
        if(s[i]=='('&&s[i+2]==')')
        stack[++top]=NULL;
        int num=0;
        if(s[i]>='0'&&s[i]<='9'){
            while(s[i]>='0'&&s[i]<='9'){
                num=num*10+(s[i]-'0');
                i++;
            }
            stack[++top]=createnode(num);
        }
        if(s[i]=='R')
        stack[top]->color=1;
        if(s[i]=='B')
        stack[top]->color=0;
        if(s[i]==')'&&s[i-2]==')'){
            struct node* t1=stack[top--];
            struct node* t2=stack[top--];
            stack[top]->left=t2;
            stack[top]->right=t1;
            if(t1!=NULL)
            t1->p=stack[top];
            if(t2!=NULL)
            t2->p=stack[top];
        }
        i++;
    }
    return stack[0];
}




int red(struct node *root, int *c)
{
  if(root!=NULL){
  if (root->color == 1 && root->p->color == 1)
  {
    *c = 0;
  }
  red(root->left, c);
  red(root->right, c);
}
}

int black(struct node *root)
{
  if (root->color == 0)
    return 1;
  else
    return 0;
}


int path(struct node *root, int arr[], int *i)
{ if(root!=NULL){
  if (root->left == NULL && root->right == NULL)
  {
    arr[(*i)++] = root->key;
    printf("%d \n ",root->key);
  }
  path(root->left, arr, i);
  path(root->right, arr, i);
}
}


struct node *search(struct node *root, int a)
{
  if (root != NULL)
  {
    struct node *ptr = root;
    while (ptr != NULL && a != ptr->key)
    {
      if (ptr->key < a)
        ptr = ptr->right;
      else if(ptr->key>a)
        ptr = ptr->left;
    }
    if (ptr != NULL)
    {
      return ptr;
    }
  }
}


int count(struct node *temp,int *co)
{
  struct node *ptr = temp;
  int c = 0;
  while (ptr->p != NULL)
  {
    if (ptr->color == 0)
    {
      c++;
    }
    ptr = ptr->p;
  }
  if((*co)==-1)
  {
    *co=c;
   
  }
  return c;
}


int num(int arr[], int i, struct node *root)
{
  int new[i];
  int co=-1;
  int a = 1;
  for (int j = 0; j < i; j++)
  {
    struct node *temp = search(root, arr[j]);
      int b=count(temp,&co);
      if(b!=co)
      {
        a=0;
        return a;
      }
  }

  
  return a;
}


struct node *check(struct node *root)
{
  int c = 1;
  int i = 0;
  int arr[100];
  red(root, &c);
  int b = black(root);
  path(root, arr, &i);
  int d = num(arr, i, root);
  if (c == 1 && b == 1 && d == 1)
  {
    printf("1");
  }
  else
    printf("0");
}



int main()
{
  char a[1000];
  fgets(a,1000,stdin);
  struct node *root = NULL;
  root = tree(a);
 check(root);
  return 1;
}