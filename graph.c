#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/*Implementation*/

struct strEdge {
  double weight;
  struct strVectex * vector;
  struct strEdge *next, *prior;
};

typedef struct strEdge *Edge;

struct strVectex {
  Type data;
  struct strEdge *first, *last, *preFirst, *postLast;
};

typedef struct strVectex *Vertex;

struct strGraph {
	int size;
  struct strVectex *first, *last, *preFirst, *postLast;
	PrintFunc printFunc;
	DestroyFunc destroyFunc;
};

Graph graph_create(PrintFunc printer, DestroyFunc destructor)
{
  Graph g =(Graph) malloc(sizeof( struct strGraph));
  g->size = 0;

  g->first = NULL;
  g->last = NULL;
  Iterator pF = (Iterator)malloc(sizeof(struct strVectex));
  pF->data = NULL;
  pF->next = NULL;
  Iterator pL = (Iterator)malloc(sizeof(struct strVectex));
  pL->data = NULL;
  pL->next = NULL;

  g->preFirst = pF;
  g->postLast = pL;

  g->printFunc = printer;
  g->destroyFunc = destructor;
}

void graph_destroy(Graph g)
{
}

void graph_addVertex(Graph g, Type u)
{
  if (g == NULL)
    return;

  Vertex v = (Vertex) malloc(sizeof( struct strVectex ));

  if (g->size < g->limit) {


  } else {
    g->array = realloc(g->array, g->limit + 5);

  }
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

