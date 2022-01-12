/*
Topic	: Kruskal Spanning Tree
Date	: 11/11/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<stdlib.h>

#define N 5

struct edge
{
	int src;
	int dest;
	int weight;
};
typedef struct edge edge;

int graph[N][N];

void initGraph();
void addEdge(int src, int dest, int weight);
void display();

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

void kruskal()
{
	int n = 0
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j++)
			if(graph[i][j])
				n++;
	
	edge e[n], p = 0;
	
	for(int i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < i ; j++)
		{
			if(graph[i][j])
			{
				e[p].src 	= i; 				// src
				e[p].dest 	= j;				// dest
				e[p].weight = graph[i][j]; 		// weight
			}
		}
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		edge t;
		t.src = e[i].src;
		t.dest = e[i].dest;
		t.weight = e[i].weight;
		
	}
}
