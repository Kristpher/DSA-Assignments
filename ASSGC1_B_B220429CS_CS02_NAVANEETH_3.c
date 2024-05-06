#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
    struct node *p;
};

struct node* createnode(int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->key = data;
    temp->left =NULL;
    temp->right = NULL;
    temp->p=NULL;
    return temp;
}

struct node *tree(char *arr, int *index)
{
    if (arr[*index] == '\0')
        return NULL;

    char new_arr[10];
    int arrin = 0;
    while (arr[*index] != '(' && arr[*index] != ')' && arr[*index] != '\0')
    {
        new_arr[arrin] = arr[(*index)];
        arrin++;
        (*index)++;
    }
    new_arr[arrin] = '\0';
    if(arrin!=0){
    struct node *el = createnode(atoi(new_arr));
    if (arr[*index] == '(')
    {
        (*index)++;
        el->left = tree(arr, index);
        (*index)++;

        if (arr[*index] == '(')
        {
            (*index)++;
            el->right = tree(arr, index);
            (*index)++;
        }
    }

    return el;}
}

void print_range(struct node *root,int k1,int k2)
{if(root!=NULL)
{
  print_range(root->left,k1,k2);
  if(root->key<=k2 && root->key>=k1)
  {
    printf("%d ",root->key);
  }
  print_range(root->right,k1,k2);
}
}

void parent(struct node *root)
{   if(root!=NULL)

{  if(root->left!=NULL)
    {
        root->left->p=root;
    }
    if(root->right!=NULL)
    {
        root->right->p=root;
    }
    parent(root->left);
    parent(root->right);
}
}
 
 struct node* sea(struct node *root,int a)
 {
     if(a>root->key)
     {
         sea(root->right,a);
     }
     else if(a<root->key)
     {
        sea(root->left,a); 
     }
     else if(a==root->key)
     {
         return root;
     }
 }
    

void ancestors(struct node*root,int a)
{  if(root!=NULL)
  {
    struct node *temp=root;
    parent(temp);
    struct node *child=NULL;
    child=sea(root,a);
    while(child->p!=NULL)
    {   
        printf("%d ", child->key);
        child=child->p;
    }
    printf("%d ", child->key);
  } 
  else
  return;
}

int main() {
char arr[100];   
scanf("%s",arr);    
arr[strlen(arr)]='\0';
int index=0;
struct node* root = tree(arr,&index);
char c[2];
c[2]='\0';
int a,b;
while(1)
  {
    scanf("%s",c);
    if(strcmp("e",c)==0)
    {
      break;
    }
    else if(strcmp("p",c)==0)
    {
      scanf("%d %d",&a,&b);
      print_range(root,a,b);
      printf("\n");
    }
      else if(strcmp("a",c)==0)
    {
      scanf("%d",&a);
      ancestors(root,a);
      printf("\n");
    }
  }
   return 0;
}