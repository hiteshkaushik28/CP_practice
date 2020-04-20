#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct AdjListNode{
    int dest;
    struct AdjListNode *next;
};

struct AdjList{
    struct AdjListNode *head;
};

struct Graph{
    int V;
    struct AdjList* array;
};

struct AdjListNode *newAdjListNode(int dest){
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int v){
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    G->V = v;
    struct AdjList *arr = (struct AdjList *)malloc(sizeof(struct AdjList)*G->V);
    G->array = arr;
    for(int i=0;i<G->V;i++)
        G->array[i].head = NULL;
    return G; 
}

void addEdge(struct Graph *g, int src, int dest){
    struct AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = g->array[src].head;
    g->array[src].head = newNode;

    struct AdjListNode *newNode2 = newAdjListNode(src);
    newNode2->next = g->array[dest].head;
    g->array[dest].head = newNode2;
}

void printGraph(struct Graph *g){
    for(int i=0;i<g->V;i++){
        struct AdjListNode *temp = g->array[i].head;
        cout<<i<<endl;
        while(temp){
            cout<<temp->dest<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main() 
{ 
    // create the graph given in above fugure 
    int V = 5; 
    struct Graph* graph = createGraph(V); 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
  
    // print the adjacency list representation of the above graph 
    printGraph(graph); 
  
    return 0; 
} 