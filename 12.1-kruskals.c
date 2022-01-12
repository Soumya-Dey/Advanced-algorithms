#include <stdio.h>
#include <stdlib.h>

#define V 7

// adjacency matrix
int cost[V][V] = {
  {999, 999, 15, 46, 40, 999, 999},
  {999, 999, 999, 999, 17, 40, 29},
  {15, 999, 999, 999, 53, 999, 999},
  {46, 999, 999, 999, 999, 11, 3},
  {40, 17, 53, 999, 999, 999, 31},  
  {999, 40, 999, 11, 999, 999, 8},  
  {999, 29, 999, 3, 31, 8, 999},  
};
 
int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, parent[V];
 
int find(int);
int uni(int, int);
 
int main(){
  printf("The edges of Minimum Cost Spanning Tree are\n");
  while (ne < V-1){
    for (i = 1, min = 999; i <= V-1; i++){
      for (j = 1; j <= V-1; j++){
        if (cost[i][j] < min){
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }
 
    u = find(u);
    v = find(v);
 
    if (uni(u, v)){
      printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
      mincost += min;
    }
 
    cost[a][b] = cost[b][a] = 999;
  }
 
  printf("\nMinimum cost = %d\n", mincost);

  return 0;
}
 
int find(int i){
  while (parent[i])
    i = parent[i];
  return i;
}
 
int uni(int i, int j){
  if (i != j){
    parent[j] = i;
    return 1;
  }
 
  return 0;
}