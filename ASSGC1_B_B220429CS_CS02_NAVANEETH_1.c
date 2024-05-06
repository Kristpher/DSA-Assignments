#include <stdio.h>
#include <stdlib.h>
#include<string.h>


struct node {
    int key;
    struct node* left;
    struct node* right;
    struct node* p ;
};

struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;
    temp->p=NULL;
    return temp;
}


struct node* tree(int* pre,  int* in,int n1) {
    if (n1 == 0 ) {
        return NULL;
    }

    
    int root = pre[0];
    struct node* rootNode = createnode(root);

    
    int i;
    for (i = 0; i < n1; i++) {
        if (in[i] ==root) {
            break;
        }
    }

    
    rootNode->left = tree(pre + 1,in, i );
    rootNode->right = tree(pre + 1 + i,  
                            in + i + 1,n1 - 1 - i);

    return rootNode;
}


void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int height(struct node* root)
{
    if (root == NULL)
        return 0;
    else {
         
        
        int lefth = height(root->left);
        int righth = height(root->right);
 
       
        if (lefth > righth)
            return (lefth + 1);
        else
            return (righth + 1);
    }
}
 
void zigzag(struct node* root, int level,int a)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1) {
        if(a!=0)
        {
        zigzag(root->left, level - 1,a);
        zigzag(root->right, level - 1,a);
       }
       else
       {
        zigzag(root->right, level - 1,a);
       zigzag(root->left, level - 1,a);
       }      
}
} 

void zigzagOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        zigzag(root, i,i%2);
}


void level(struct node* root, int l,int *max)
{  if (root == NULL)
    {
        return;
    }

    if (l == 1)
    {
        if (*max < root->key)
        {
            *max = root->key;
        }
    }
   
     if (l > 1) {
       
        {
        level(root->left, l - 1,max);
        level(root->right, l - 1,max);
       }
         
           
}
} 

void level_max(struct node* root)
{
    int h = height(root);
    int i;
   
    for (i = 1; i <= h; i++)
    {   
        int currmax=0;
        level(root, i,&currmax);
        printf("%d ",currmax);
    }
    
}



int dia_check(struct node* root, int *maxim) {
    if (root == NULL) {
        return 0;
    }

    int left = dia_check(root->left,maxim);
    int right = dia_check(root->right, maxim);

    if (left + right >* maxim) {
        (*maxim) = left + right;
    }

    return (left > right) ? left + 1 : right + 1;
}


int Diameter(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    int maxim=0 ;
    
    dia_check(root, &maxim);

    return maxim;
}

void leftl(struct node *root,int *sum){

if(root!=NULL)
{   if(root->left!=NULL )
{
  root->left->p=root;
 
}
  if(root->right!=NULL )
{
  root->right->p=root;
 
}
if(root->left==NULL &&root->right==NULL&&root==root->p->left)
{
  *sum=*sum+root->key;
}
    
    leftl(root->left,sum);
    leftl(root->right,sum);
}
else
return;
}

int main()
{
  struct node * root=NULL;
  char c[2];
  int a;
  scanf("%d",&a);
  int pre[a];
  int in[a];
  for(int i=0;i<a;i++)
  {
    scanf("%d",&in[i]);
    c[1]='\0';
  }
    for(int i=0;i<a;i++)
  {
    scanf("%d",&pre[i]);
  }
  root=tree(pre,in,a);
  while(1)
  {
    scanf("%s",c);
    if(strcmp("e",c)==0)
    {
      break;
    }
    else if(strcmp("p",c)==0)
    {
      postorder(root);
      printf("\n");
    }
    else if(strcmp("z",c)==0)
    {
    zigzagOrder(root);
     printf("\n");
    }
     else if(strcmp("m",c)==0)
    {
       
   level_max(root);
    printf("\n");
    }
      else if(strcmp("d",c)==0)
    {
   printf("%d\n",Diameter(root)+1);
    }
    else if(strcmp("s",c)==0)
    {
    int sum=0;
  
  leftl(root,&sum);
  printf("%d ",sum);
  printf("\n");

  }
  
}
}