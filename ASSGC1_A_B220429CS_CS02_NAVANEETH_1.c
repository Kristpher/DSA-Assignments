#include<stdio.h>
#include<string.h>
void push(char stack[],char a,int *top)
{
    (*top)++;
    stack[*top]=a;
}


void pop(char stack[],int *top)
{
    (*top)--;
}


int check_duplicate(char arr[],int n)
{   int top=-1;
    char stack[n];
    for(int i=0;i<n;i++)
    {
    if(arr[i]=='+'||arr[i]=='-'||arr[i]=='/'||arr[i]=='*'||arr[i]=='%'||arr[i]=='(')
     {
       push(stack,arr[i],&top);
       
    }
   
     if(arr[i]==')' && stack[top]!='(')
    {  while(stack[top]!='(')
        {
        pop(stack,&top);
        }
        pop(stack,&top);
    }
   }   
   
   while(top!=-1 && stack[top]!='(')
   {
       pop(stack,&top);
   }
    
    if(top==-1)
    {
        return 0;
    }
    else
    return 1;
   
   
   
}    
   

int main()
{
int n;
        scanf("%d\n",&n);
        char arr[n];
       
        for(int i=0;i<n;i++)
        {
        scanf("%c",&arr[i]);
        }
       
        printf("%d ",check_duplicate(arr,n));
       
return 0;
}