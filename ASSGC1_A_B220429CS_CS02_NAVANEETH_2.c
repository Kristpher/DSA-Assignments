#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    int key;
    struct node *next;
};
struct node* createnode(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->key=data;
    temp->next=NULL;
    return temp;
}
struct node *insert(struct node *head,int data)
{
    struct node *temp=createnode(data);
    struct node *ptr=head;
    if(head==NULL)
   {
        return temp;
   }
   else
   {
       while(ptr->next!=NULL)
     {
       ptr=ptr->next;  
     }
       ptr->next=temp;
   return head;
   }
   
   
}

struct node *delete(struct node * head,int i)
{
    struct node*ptr=head;
    struct node *temp=NULL;
    if(head==NULL)
    {
        return 0;
    }
    else
    {   
        if(i==1)
    { if(head->next==NULL)
     {
       int a=ptr->key;
       printf("%d\n",a);
       free(ptr);
       head=NULL;
       return head;
     }
     else{
        int a=ptr->key;
        head=head->next;
        free(ptr);
        printf("%d\n",a);
        return head;
     }
    }
    
    else
    {
        for(int j=1;j<i-1;j++)
        {
          if(ptr->next==NULL)
          {
           
            break;
          }
            ptr=ptr->next;
        }
         if(ptr->next!=NULL)
         {
        if(ptr->next->next==NULL)
        {
            temp=ptr->next;
            int a=ptr->next->key;
            ptr->next=NULL;
            printf("%d\n",a);
            free(temp);
            return head;
        }
      
        else{
        int a=ptr->next->key;
        temp=ptr->next;
        ptr->next=ptr->next->next;
        free(temp);
        printf("%d\n",a);
        return head;
        }
         }
          printf("%d\n",-1);
         return head;
    }
}
}

struct node *dupe(struct node *head)
{
    struct node *temp=head;
    int arr[1000]={0};
    while(temp!=NULL)
    {
        arr[temp->key]++;
        temp=temp->next;
    }
    struct node*newHead=NULL;
   temp=head;
    while(temp!=NULL)
    {
        if(arr[temp->key]==1)
        {
            newHead=insert(newHead,temp->key);
        
        }
        else if(arr[temp->key]>1)
        {
            newHead=insert(newHead,temp->key);
            arr[temp->key]=0;
        }
        temp=temp->next;
    }
    return newHead;
}
struct node *display(struct node * head)
{   struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->key);
        ptr=ptr->next;
        
    }
    printf("\n");
}

struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *temp = NULL;

    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    head = prev;
    return head;
}

void pal(struct node * head)
{
  struct node *newHead=NULL; 
  struct node*new=head;
  while(new!=NULL)
  {
  newHead=insert(newHead,new->key);
  new=new->next;
  }
   
   newHead=reverse(newHead);
  
   struct node *ptr=head;
   struct node *temp=newHead;
   int count=1;
   while(ptr!=NULL )
   {   if(ptr->key!=temp->key)
       {
           count=0;
           break;
       }
       else
       {
       ptr=ptr->next;
       temp=temp->next;
       
       }
       
   }
   if (count==0)
   {
       printf("N\n");
   }
   else if(count==1)
   {
       printf("Y\n");
   }
   
  
}

int main()
{
    struct node * head=NULL;
    int a,b;
    char c[2];
    while(1)
    {
        scanf("%c",c);
        c[1]='\0';
        if(strcmp(c,"e")==0)
        break;
        else if(strcmp(c,"a")==0)
        {   scanf("%d",&a);
            head=insert(head,a);
        }
        else if(strcmp(c,"r")==0)
        {   if(head==NULL)
            {
                printf("%d\n",-1);
            }
            else{
            scanf("%d",&a);
            head=delete(head,a);
            }
        }
           else if(strcmp(c,"d")==0)
        {    if(head==NULL)
            {
                printf("%d\n",-1);
            }
            else{
            head=dupe(head);
            display(head);
            }
        }
         else if(strcmp(c,"s")==0)
        {   
            if(head==NULL)
            {
                printf("%d\n",-1);
            }
            else{
            display(head);
            }
        }
        else if(strcmp(c,"p")==0)
        { if(head==NULL)
            {
                printf("%d\n",-1);
            }
            else{
            pal(head);
                }
        }
       
       
    }
return 0;
}
