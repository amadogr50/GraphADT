#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/*Implementation*/

struct strEdge {
  double weight;
  struct strVertex * vector;
  struct strEdge *next, *prior;
};

typedef struct strEdge * Edge;
typedef struct strEdge * EdgeIterator;

struct strVertex {
  Type data;
  //Elements for doing a List of Edges
  struct strEdge *first, *last, *preFirst, *postLast;
  struct strEdge *next, *prior;
};

typedef struct strVertex * Vertex;
typedef struct strVertex * VertexIterator;


struct strGraph {
	int size;
  //Elements for doing a List of Vertex
  struct strVertex *first, *last, *preFirst, *postLast;
  //Functions needed
	PrintFunc printFunc;
	DestroyFunc destroyFunc;
  CompareFunc comparator;
};

Graph graph_create(PrintFunc printer, DestroyFunc destructor, CompareFunc comparator)
{
  //Graph memory reservation
  Graph g =(Graph) malloc(sizeof( struct strGraph));

  //Initialize this way beacuse there aren't Vertexs added
  g->size = 0;
  g->first = NULL;
  g->last = NULL;

  //We create these Iterator to ease go through the Vertex List
  VertexIterator pF = (VertexIterator) malloc(sizeof(struct strVertex));
  pF->data = NULL;
  pF->preFirst = NULL;
  pF->first = NULL;
  pF->last = NULL;
  pF->postLast = NULL;
  VertexIterator pL = (VertexIterator) malloc(sizeof(struct strVertex));
  pL->data = NULL;
  pL->preFirst = NULL;
  pL->first = NULL;
  pL->last = NULL;
  pL->postLast = NULL;

  //Add Iterators to the Graph
  g->preFirst = pF;
  g->postLast = pL;


  //Add functions parameters to the Graph
  g->printFunc = printer;
  g->destroyFunc = destructor;
  g->comparator = comparator;
}

void graph_destroy(Graph g)
{
}

void graph_addVertex(Graph g, Type u)
{
  //Validates Graph
  if (g == NULL)
    return;

  //Reservate memory for the new vertex
  Vertex v = (Vertex) calloc(1, sizeof(struct strVertex));
  v->data = u; //Add data recived to the new vertex

  //Cases for adition:
  if (g->first == NULL) {
    //-Empty Vertex List
    g->first = v; //Because is empty, the new vertex is the first vertex
    g->preFirst->next = v; //And so, the vertex following the preFirst will be the new vertex
  } else {
    //-Non empty Vertex List
    g->last->next = v; //The next of the last one will be the new vertex
    v->prior = g->last; //Prior of the new vertex is the last one
  }

  //-Any case
  g->size++; //Graph has one vertex more
  g->last = v; //The last one will be the new vertex
  g->postLast->prior = v; //And so, the vertex before the postLast will be the new vertesx
}

void graph_deleteVertex(Graph g, Type v)
{

}

void graph_addEdge(Graph g, Type u, Type v, double weight)
{

}

void graph_deleteEdge(Graph g, Type u, Type v)
{

}

void BFS(Graph g, Type start)
{

}

void DFS(Graph g)
{

}

void dijkstra(Graph g, Type start)
{

}

