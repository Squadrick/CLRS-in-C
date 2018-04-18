#include <stdlib.h>
#include <stdio.h>

typedef enum {UNDIRECTED = 0, DIRECTED} Edge_t;

struct AdjListNode {
	unsigned int vertex;
	int edgeWeight;
	struct AdjListNode *next;
};

struct AdjList {
	unsigned int totalMembers;
	struct AdjListNode *head;
};

typedef struct AdjListNode AdjListNode_t;
typedef struct AdjList AdjList_t;

typedef struct Graph {
	Edge_t typeOfGraph;
	unsigned int totalVertices;
	unsigned int totalEdges;
	AdjList_t *adjListArr;
} Graph_t;

AdjListNode_t *createAdjacentNode(int vertex, int weight) {
	AdjListNode_t *newNode = (AdjListNode_t*) malloc(sizeof(AdjListNode_t));
	newNode->vertex = vertex;
	newNode->next = NULL;
	newNode->edgeWeight = weight;
	return newNode;
}

Graph_t *createGraph(unsigned int totalVertices, Edge_t typeOfGraph)
{
	unsigned int i;

	Graph_t *graph = (Graph_t*)malloc(sizeof(Graph_t));

	graph->totalVertices = totalVertices;
	graph->totalEdges = 0;
	graph->typeOfGraph = typeOfGraph;

	graph->adjListArr = (AdjList_t*) malloc(totalVertices * sizeof(AdjList_t));

	for(i = 0; i < totalVertices; i++) {
		graph->adjListArr[i].head = NULL;
		graph->adjListArr[i].totalMembers = 0;
	}

	return graph;
}

void deleteGraph(Graph_t *graph) {
	unsigned int vertex;
	AdjListNode_t *iter, *temp;
	for(vertex = 0; vertex < graph->totalVertices; vertex++) {
		iter = graph->adjListArr[vertex].head;

		while(iter != NULL)
		{
			temp = iter;
			iter = iter->next;
			free(temp);
		}
	}
	free(graph->adjListArr);
	free(graph);
}

void addNodeToList(AdjList_t *list, AdjListNode_t *node) {
	node->next = list->head;
	list->head = node;
	list->totalMembers++;
}

int doesEdgeExist(Graph_t *graph, unsigned int src, unsigned int dest) {
	AdjListNode_t *srcVertexPtr = graph->adjListArr[src].head;

	while(srcVertexPtr != NULL) {
		if(srcVertexPtr->vertex == dest) 
			return 1;
		srcVertexPtr = srcVertexPtr->next;
	}

	return 0;
}

void addEdge(Graph_t *graph, unsigned int src, unsigned int dest, int weight) {
	if(src >= graph->totalVertices || dest >= graph->totalVertices)
		return;

	if(doesEdgeExist(graph, src, dest))
		return;
	
	AdjListNode_t *newNode = createAdjacentNode(dest, weight);
	
	addNodeToList(&(graph->adjListArr[src]), newNode);
	graph->totalEdges++;
	
	if(graph->typeOfGraph == UNDIRECTED) {
		newNode = createAdjacentNode(src, weight);
		
		addNodeToList(&(graph->adjListArr[dest]), newNode);
		graph->totalEdges++;
	}
}

void displayGraph(Graph_t *graph) {
	unsigned int vertex;

	for(vertex = 0; vertex < graph->totalVertices; vertex++) {
		AdjListNode_t *iter = graph->adjListArr[vertex].head;

		printf("Vertex %d is adjacent to ", vertex);

		while(iter != NULL) {
			printf("%d(%d)->", iter->vertex, iter->edgeWeight);
			iter = iter->next;
		}

		printf("NULL\n");
	}
}

void deleteEdge(Graph_t* graph, int src, int dest) {
	AdjListNode_t *iter = graph->adjListArr[src].head;

	if(iter->vertex == dest) {
		graph->adjListArr[src].head = iter->next;
		free(iter);
	}
	
	AdjListNode_t *prev = iter;
	iter = iter->next;

	while(iter != NULL) {
		if(iter->vertex == dest) {
			prev->next = iter->next;
			free(iter);
		}
		prev = iter;
		iter = iter->next;
	}
}

void deleteVertex(Graph_t* graph, int src) {
	AdjListNode_t *iter = graph->adjListArr[src].head;
	AdjListNode_t *temp;
	
	while(iter != NULL) {
		temp = iter->next;
		free(iter);
		iter = temp;
	}

	graph->adjListArr[src].head = NULL;
}

