#ifndef GRAPH_H_
#define GRAPH_H_

typedef enum {FALSE, TRUE} Bool;
typedef struct strGraph * Graph;
typedef void *  Type;
typedef void (*PrintFunc) (Type);
typedef void (*DestroyFunc) (Type);

Graph graph_create(PrintFunc printer, DestroyFunc destructor);
void graph_destroy(Graph g);
void graph_addVertex(Graph g, Type u);
void graph_deleteVertex(Graph g, Type v);
void graph_addEdge(Graph g, Type u, Type v, double weight);
void graph_deleteEdge(Graph g, Type u, Type v);

void BFS(Graph g, Type start);
void DFS(Graph g);
void dijkstra(Graph g, Type start);


#endif