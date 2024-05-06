#include <stdio.h> 
#include <stdlib.h> 
int comparator(const void* p1, const void* p2) 
{ 
	const int(*x)[3] = p1; 
	const int(*y)[3] = p2; 
	return (*x)[2] - (*y)[2]; 
} 
void makeSet(int parent[], int rank[], int n) 
{ 
	for (int i = 0; i < n; i++) { 
		parent[i] = i; 
		rank[i] = 0; 
	} 
} 
int findParent(int parent[], int component) 
{ 
	if (parent[component] == component) 
		return component; 
	return parent[component] 
		= findParent(parent, parent[component]); 
} 
void union1(int u, int v, int parent[], int rank[], int n) 
{ 
	u = findParent(parent, u); 
	v = findParent(parent, v); 
	if (rank[u] < rank[v]) { 
		parent[u] = v; 
	} 
	else if (rank[u] > rank[v]) { 
		parent[v] = u; 
	} 
	else { 
		parent[v] = u; 
		rank[u]++; 
	} 
} 
void kruskal(int n, int connect[n][3]) 
{ 
	qsort(connect, n, sizeof(connect[0]), comparator); 
	int parent[n]; 
	int rank[n]; 
	makeSet(parent, rank, n); 
	int minCost = 0;  
	for (int i = 0; i < n; i++) { 
		int e = findParent(parent, connect[i][0]); 
		int z = findParent(parent, connect[i][1]); 
		int wt = connect[i][2]; 
		if (e != z) { 
			union1(e, z, parent, rank, n); 
			minCost += wt; 
		} 
	} 
	printf("%d\n", minCost); 
} 
int main()
{
  int a;
  scanf("%d", &a);
  int arr[a][a];
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < a; j++)
    {
      arr[i][j] = 0;
    }
  }
  int b;
  int c;
  for (int i = 0; i < a; i++)
  {
    scanf("%d", &b);
    while (getchar() != '\n')
    {
      scanf("%d", &c);
      arr[b][c] = 1;
    }
  }
  int d, e;
  for (int i = 0; i < a; i++)
  {
    scanf("%d", &e);
    for (int j = 0; j < a; j++)
    {
      if (arr[e][j] == 1)
      {
        scanf("%d",&d);
        arr[e][j] = d;
      }
       
    }
   
  }
  for(int i=0;i<a;i++)
  {
      for(int j=0;j<a;j++)
      {
          if(arr[i][j]>=1)
          arr[j][i]=0;
      }
  }
   
  
  int z=a*a;
  int new1[z][3];
  int k=0;
 for(int i=0;i<a;i++)
 {
  for(int j=0;j<a;j++)
  {if(arr[i][j]>=1){
   new1[k][0]=i;
   new1[k][1]=j;
   new1[k][2]=arr[i][j];
   k++;
  }
  }
 }

  kruskal(k,new1);

  return 0;
}
