#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
int minimumdistance(int dist[], bool set1[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 1; v <= n; v++) {
        if (!set1[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


void prints(int dist[], int n) {
 
    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}


void dijalgorithm( int n,int graph[][n], int src) {
    int dist[n];     
    bool set1[n];  
    
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX, set1[i] = false;
   
    dist[src] = 0;
 
    for (int count = 1; count <= n - 1; count++) {
      
        int u = minimumdistance(dist, set1, n);
        
        set1[u] = true;
        
        for (int v = 1; v <=n; v++) {
            if (!set1[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
   
    prints(dist, n);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = 0;
        }
    }
    int b, c;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b);
        while (getchar() != '\n') {
            scanf("%d", &c);
            arr[b][c] = 1; 
        }
    }
   
    int d, e;
    for (int i = 1; i <=n; i++) {
        scanf("%d", &e);
        for (int j = 1; j <=n; j++) {
            if (arr[e][j] == 1) {
                scanf("%d", &d);
                arr[e][j] = d;
            }
            
        }
    }
    int f;
    scanf("%d", &f); 
    dijalgorithm(n,arr, f); 
    return 0;
}
