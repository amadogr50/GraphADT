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
  int size;
  struct strEdge *first, *last;
  struct strVertex *next, *prior;
};

typedef struct strVertex * Vertex;
typedef struct strVertex * VertexIterator;


struct strGraph {
	int size;
  //Elements for doing a List of Vertex
  struct strVertex *first, *last;
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

  //Add functions parameters to the Graph
  g->printFunc = printer;
  g->destroyFunc = destructor;
  g->comparator = comparator;
}

void graph_destroy(Graph g)
{
  //Graph validation
  if (g == NULL)
    return;

  Vertex toDeleteVertex = g->first;
  Vertex tempVertex;

  //Loop through Vertex List
  for (int i = 0; i < g->size; i++) {
    Edge toDeleteEdge = toDeleteVertex->first;
    Edge tempEdge;

    //Loop through Edge List
    for (int i = 0; i < toDeleteVertex->size; i++) {
      tempEdge = toDeleteEdge;
      toDeleteEdge = toDeleteEdge->next;
      free(tempEdge);
    }

    //Use destroyFunc if there´s one
    if (g->destroyFunc)
      g->destroyFunc(toDeleteVertex->data);

    tempVertex = toDeleteVertex;
    toDeleteVertex = toDeleteVertex->next;
    free(tempVertex);
  }

  free(g);
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
  } else {
    //-Non empty Vertex List
    g->last->next = v; //The next of the last one will be the new vertex
    v->prior = g->last; //Prior of the new vertex is the last one
  }

  //-Any case
  g->size++; //Graph has one vertex more
  g->last = v; //The last one will be the new vertex
}

void graph_deleteVertex(Graph g, Type v)
{

}

void graph_addEdge(Graph g, Type fromVector, Type toVector, double weight)
{
  //Graph validation
  if (g == NULL)
    return;

  //Search through Vertex list until find the vectores fromVector and toVector
  Vertex search = g->first;
  Vertex from = NULL, to = NULL;
  
  while (from == NULL || to == NULL) {
    if (search == NULL) {
      //If it gets here it means one or both vecters were not inside the graph
      return;
    } else {
      if (from == NULL) {
        if (g->comparator(search->data, fromVector))
          from = search;
      }
      if (to == NULL) {
        if (g->comparator(search->data, toVector))
          to = search;
      }
    }
    search = search->next;
  }

  //Reservate memory for the new Edge
  Edge e = (Edge) calloc(1, sizeof(struct strEdge));
  e->vector = to; //Add data recived to the new Edge
  e->weight = weight; 

  //Cases for adition:
  if (from->first == NULL) {
    //-Empty Edge List
    from->first = e; //Because is empty, the new Edge is the first Edge
  } else {
    //-Non empty Edge List
    from->last->next = e; //The next of the last one will be the new Edge
    e->prior = from->last; //Prior of the new Edge is the last one
  }

  //-Any case
  from->size++; //Vertex has one Edge more
  from->last = e; //The last one will be the new Edge
}

void graph_deleteEdge(Graph g, Type fromVector, Type toVector)
{
  //Graph validation
  if (g == NULL)
    return;

  //Search through Vertex list until find the vectores fromVector and toVector
  Vertex search = g->first;
  Vertex from = NULL;
  
  while (from == NULL) {
    if (search == NULL) {
      //If it gets here it means one or both vecters were not inside the graph
      return;
    } else {
      if (g->comparator(search->data, fromVector))
        from = search;
    }
  }

  //Search for edge with vector that matches with toVector
  Edge e = from->first;
  while (!g->comparator(e->vector->data, toVector) && e != NULL) {
    e = e->next;
  }

  //Not go foward it there´s no edge with vertex->data equals to toVector
  if (e == NULL)
    return;

  //Cases for destroying the edge
  if (e->prior != NULL) {
    if (e->next != NULL) {
      e->prior->next = e->next;
      e->next->prior = e->prior;
    } else {
      e->prior->next = NULL;
      from->last = e->prior;
    }
  } else {
    if (e->next != NULL) {
      e->next->prior = NULL;
      from->first = e->next;
    } else {
      from->last = NULL;
      from->first = NULL;
    }
  }

  free(e);
  from->size--;
}

void graph_printer(Graph g) 
{
    //Graph validation
  if (g == NULL)
    return;

  Vertex current = g->first;
  for (int i = 0; i < g->size; i ++) {
    g->printFunc(current->data);
    printf(": ");
    if (current->size > 0) {
      Edge currentEdge = current->first;
      for (int j = 0; j < current->size; j++) {
        printf("(");
        g->printFunc(current->data);
        printf(" -> ");
        g->printFunc(currentEdge->vector->data);
        printf(", %f), ", currentEdge->weight);
        currentEdge = currentEdge->next;
      }
    } 
    printf("\n");
    current = current->next;
  }
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

