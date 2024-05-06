#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_NODES 100

struct node
{
  int data;
  struct node *next;
};

struct Graph
{
  struct node *head[MAX_NODES];
};

int visited[MAX_NODES], inStack[MAX_NODES], count = 0, flag = 0;

void initialize(struct Graph *graph)
{
  for (int i = 0; i < MAX_NODES; ++i)
  {
    visited[i] = 0;
    inStack[i] = 0;
    graph->head[i] = NULL;
  }
}

void addEdge(struct Graph *graph, int src, int data)
{

  struct node *newNode = (struct node *)malloc(sizeof(struct node *));
  newNode->data = data;
  newNode->next = graph->head[src];
  graph->head[src] = newNode;
}

void BFS(int v, struct Graph *graph)
{
  int queue[MAX_NODES];
  int front = 0, rear = 0;
  queue[rear++] = v;
  visited[v] = 1;

  while (front < rear)
  {
    int current = queue[front++];
    struct node *temp = graph->head[current];
    while (temp != NULL)
    {
      if (!visited[temp->data])
      {
        queue[rear++] = temp->data;
        visited[temp->data] = 1;
      }
      else if (visited[temp->data] && temp->data != v)
      {
        flag = 1;
      }
      temp = temp->next;
    }
  }
}

int isPath(int src, int des, struct Graph *graph)
{
  for (int i = 0; i < MAX_NODES; ++i)
  {
    visited[i] = 0;
  }
  BFS(src, graph);
  return visited[des];
}

bool bfs22(int v, struct Graph *graph)
{
  visited[v] = 1;
  inStack[v] = 1;

  struct node *temp = graph->head[v];
  while (temp != NULL)
  {
    int neighbor = temp->data;
    if (!visited[neighbor])
    {
      if (bfs22(neighbor, graph))
      {
        return true;
      }
    }
    else if (inStack[neighbor])
    {
      return true;
    }
    temp = temp->next;
  }

  inStack[v] = 0;
  return false;
}

bool hasCycle(int V, struct Graph *graph)
{
  for (int i = 1; i <= V; ++i)
  {
    if (!visited[i])
    {
      if (bfs22(i, graph))
      {
        return true;
      }
    }
  }
  return false;
}

void findSCC(int n, struct Graph *graph)
{
  int is_scc[MAX_NODES] = {0};
  for (int i = 1; i <= n; ++i)
  {
    if (!is_scc[i])
    {
      int scc[MAX_NODES], scc_count = 0;
      scc[scc_count++] = i;

      for (int j = i + 1; j <= n; ++j)
      {
        if (!is_scc[j] && isPath(i, j, graph) && isPath(j, i, graph))
        {
          is_scc[j] = 1;
          scc[scc_count++] = j;
        }
      }
      count++;
    }
  }
}

int main()
{
  int V;
  scanf("%d", &V);
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  initialize(graph);

  int arr[1000][2];
  for (int i = 0; i < 1000; i++)
    arr[i][0] = -1, arr[i][1] = -1;
  int k = 0;
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      int a;
      scanf("%d", &a);
      if (a)
      {
        arr[k][0] = i + 1;
        arr[k][1] = j + 1;
        addEdge(graph, arr[k][0], arr[k][1]);
        k++;
      }
    }
  }
  char c[2];
  while (1)
  {
    scanf("%s", c);
    c[1] = '\0';
    if (strcmp("x", c) == 0)
      break;
    else if (strcmp("t", c) == 0)
    {
      if (hasCycle(V, graph))
      {
        printf("-1\n");
      }
      else
      {
        printf("1\n");
      }
    }
    else if (strcmp("c", c) == 0)
    {
      findSCC(V, graph);
      printf("%d\n", count);
    }
  }
    return 0;
  }
