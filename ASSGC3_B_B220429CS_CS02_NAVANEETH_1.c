#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
int a;
int minKey(int key[a], bool mstSet[a])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < a; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void primMST(int graph[a][a], int startVertex) {
    int parent[a];
    int key[a];
    bool mstSet[a];

    for (int i = 0; i < a; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[startVertex] = 0;
    parent[startVertex] = -1;


int count=0;
    while (true && count<a-1) {
        int u = minKey(key, mstSet);
        if (u == INT_MAX) 
            break;
        mstSet[u] = true;

        for (int v = 0; v < a; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }

        
        int minIndex = minKey(key, mstSet);
        if (parent[minIndex] != -1) {
            count++;
            printf("%d %d ", parent[minIndex], minIndex);
        }
    }
}


int min(int key[a], bool mstSet[a])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < a; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}
int printwt(int parent[a], int graph[a][a] )
{
	int sum=0;
	for (int i = 1; i < a; i++)
	sum=sum+graph[i][parent[i]];
	printf("%d",sum);
}


void weight(int graph[a][a]){
	int parent[a];
	int key[a];
	bool mstSet[a];
	for (int i = 0; i < a; i++)
		key[i] = INT_MAX, mstSet[i] = false;


	key[0] = 0;


	parent[0] = -1;


	for (int count = 0; count < a - 1; count++) {
		
	
		int u = min(key, mstSet);

	
		mstSet[u] = true;


		for (int v = 0; v < a; v++)

	
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}


	printwt(parent, graph);
}
int main()
{

scanf("%d",&a);
int arr[a][a];
for(int i=0;i<a;i++)
{
    for(int j=0;j<a;j++)
    {
        scanf("%d",&arr[i][j]);
    }
}
char c[5];
    while(1){
        scanf("%s",c);
        c[strlen(c)]=='\0';
    if(strcmp("x",c)==0)
    break;
    else if(c[0]=='s'&&c[1]=='('&&c[strlen(c)-1]==')')
    {   
      int j = 2;
      char b[10];
      int k = 0;
      while (c[j] != ')') {
      b[k++] = c[j++];
          
      }
b[k] = '\0';

int d = atoi(b);
primMST(arr,d);
    }
	
	else if(strcmp("t",c)==0){
    weight(arr);
        
    }
    }
	return 0;
}
