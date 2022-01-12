/*
Topic	: Spanning trees
Date	: 11/11/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<stdlib.h>

#define N 5
int graph[N][N];

void initGraph();
void addEdge(int src, int dest, int weight);
void display();
void prims();

int main()
{
	initGraph();
	addEdge(0, 1, 3);
	addEdge(0, 2, 5);
	addEdge(1, 3, 5);
	addEdge(1, 2, 4);
	addEdge(2, 3, 8);
	addEdge(2, 4, 6);
	addEdge(3, 4, 7);
	
	display();
	prims();
	
	return 0;
}

void initGraph()
{
	int i,j;
	for(i = 0 ; i < N ; i++)
		for(j = 0 ; j < N ; j++)
			graph[i][j] = 0;
}

void addEdge(int src, int dest, int weight)//adding undirected graph
{
	graph[src][dest] = weight;
	graph[dest][src] = weight;
}

void display()
{
	int i,j;
	printf("Graph is :: \n");
	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < N ; j++)
			printf("%d\t", graph[i][j]);	
		printf("\n");
	}
	printf("\n");
}

void prims()
{
	int minVert, min;
	int primsTree[N]; // storing parent of each index node
	int visited[N];   // visited this vertex or not
	int weights[N];   // 
	
	for(int i = 0 ; i < N ; i++)
	{
		weights[i] = INT_MAX;
		visited[i] = 0;
	}
	
	weights[0] = 0;
	primsTree[0] = -1; // 0th node is starting node, so its parent is -1
	
	for(int i = 0 ; i < N ; i++)//maybe?
	{
		//lets get the min vertex;
		min = INT_MAX;
		for(int j = 0 ; j < N ; j++)
		{
			if(weights[j] < min && visited[j] == 0)
			{
				min = weights[j];
				minVert = j;
			}
		}
		visited[minVert] =  1;
		printf("min = %d \n", minVert);
		
		for(int j = 0 ; j < N ; j++)
		{
			// if, j is adj node of min
			// and if j is not added to the tree yet
			// and weight of min - j is less,
			// parent of j = min, and update weight
			if(graph[minVert][j] != 0 && visited[j] == 0 && graph[minVert][j] < weights[j])
			{
				primsTree[j] = minVert;
				weights[j] = graph[minVert][j];
			}
		}
	}
	
	for(int i = 0 ; i < N ; i++)
	{
		printf(" %d -> %d [weight = ]\n", i, primsTree[i]);
	}
	// select a vertex among all 
		// check for cycle
	// repeat
}
