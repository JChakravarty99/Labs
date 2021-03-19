#include <stdio.h> 
#include <stdlib.h> 
  
// A structure to represent an adjacency list node 
struct AdjListNode 
{ 
    int dest; 
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
struct AdjList 
{ 
    struct AdjListNode *head;  
}; 
  
// A structure to represent a graph. A graph 
// is an array of adjacency lists. 
// Size of array will be V (number of vertices  
// in graph) 
struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  
// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest) 
{ 
    struct AdjListNode* temp = (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    temp->dest = dest; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
  
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
  
    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 
  
// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int v1, int v2) 
{ 
    struct AdjListNode* newNode = newAdjListNode(v2); 
    newNode->next = graph->array[v1].head; 
    graph->array[v1].head = newNode; 
  
    newNode = newAdjListNode(v1); 
    newNode->next = graph->array[v2].head; 
    graph->array[v2].head = newNode; 
} 
  
void printGraph(struct Graph* graph) 
{ 
    int v; 
    for (v = 0; v < graph->V; ++v) 
    { 
        struct AdjListNode* pCrawl = graph->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // create the graph given in above fugure 
    int V = 5; 
    struct Graph* graph = createGraph(V); 
    int v1, v2;
    int choice;
    do{
        printf("1.Add Edge\n2.Print Graph\n");
        scanf(" %d", &choice);
        switch(choice)
        {
            case 1: printf("Enter source and destination: ");
                    scanf(" %d %d", &v1, &v2);
                    addEdge(graph, v1, v2);
                    break;
            
            case 2: printGraph(graph);
                    break; 
        }
    }while(choice < 3 && choice > 0);
    return 0; 
} 
