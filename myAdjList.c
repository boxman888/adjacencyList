#include <stdio.h>
#include <stdlib.h>

// Defines an adjacency node
typedef struct AdjNode
{
	int pos;
	struct AdjNode *next;
}AdjNode;
// Defines a adjacency list
typedef struct AdjList
{
	//Start of each adjacency list
	struct AdjNode *root;
}AdjList;
// Defines a Graph
typedef struct Graph
{
	int V;
	struct AdjList *list;
}Graph;
// Defines a new adjacency list node
AdjNode* newAdjNode(int pos)
{
	AdjNode *newNode = (AdjNode*) malloc(sizeof(AdjNode));
	newNode -> pos = pos;
	newNode -> next = NULL;
	
	return newNode;
}
// Defines a new graph
Graph* newGraph(int V)
{
	Graph *graph = (Graph*) malloc(sizeof(Graph));
	graph -> V = V;
	graph -> list = (AdjList*) malloc(V * sizeof(AdjList));
	
	// Each adjacency root is set to NULL
	for (int v = 0; v < V;++v)
		graph -> list[v].root = NULL;

	return graph;
}
// Connects a node a with node b
void connectNodes(Graph *graph, int a, int b)
{
	// Adds a edge from a to b
	AdjNode *newNode = newAdjNode(b);
	newNode -> next = graph->list[a].root;
	graph -> list[a].root = newNode;
	
	// Adds a edge from b to a
	newNode = newAdjNode(a);
	newNode -> next = graph->list[b].root;
	graph -> list[b].root = newNode;	
}
// Prints out the graph in adjacency list form
void printGraph(Graph *graph)
{
	// Moves down the graph list
	for (int v = 0; v < graph->V;++v)
	{
		// What nodes are connected with the for loop selected node node
		struct AdjNode *pCrawl = graph -> list[v].root;
		printf("List at vertex %d:\n root ", v);
		while (pCrawl)
		{
			printf("-> %d", pCrawl->pos);
			pCrawl = pCrawl -> next;
		}
		printf("\n");
	}
}

int main()
{
	int V = 5;
	Graph *graph = newGraph(V);

	connectNodes(graph, 0, 1);
	connectNodes(graph, 0, 4);
	connectNodes(graph, 1, 2);
	connectNodes(graph, 1, 3);
	connectNodes(graph, 1, 4);
	connectNodes(graph, 2, 3);
	connectNodes(graph, 3, 4);
	
	printGraph(graph);
	return 0;
}

