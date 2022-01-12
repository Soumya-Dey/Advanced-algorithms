#include <stdio.h>

#define MAX 9999999
#define V 7

// adjacency matrix
int G[V][V] = {
  {0, 0, 15, 46, 40, 0, 0},
  {0, 0, 0, 0, 17, 40, 29},
  {15, 0, 0, 0, 53, 0, 0},
  {46, 0, 0, 0, 0, 11, 3},
  {40, 17, 53, 0, 0, 0, 31},  
  {0, 40, 0, 11, 0, 0, 8},  
  {0, 29, 0, 3, 31, 8, 0},  
};

int main() {
  int i, noEdge = 0, selected[V];
  int row, col;

  for(i = 0; i < V; i++) selected[i] = 0;
  // selecting 0th vertex
  selected[0] = 1;

  printf("Edge    | Weight\n");
  while (noEdge < V - 1) {
    int min = MAX;
    row = 0;
    col = 0;

    for (int i = 0; i < V; i++){
      if (selected[i]){
        for (int j = 0; j < V; j++){
          // not selected and there is an edge
          if (!selected[j] && G[i][j]){
            if (min > G[i][j]) {
              min = G[i][j];
              row = i;
              col = j;
            }
          }
        }
      }
    }

    printf("%d --- %d | %d\n", row, col, G[row][col]);
    selected[col] = 1;
    noEdge++;
  }

  return 0;
}