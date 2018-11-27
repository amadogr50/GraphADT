#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void printVertex(Type t) {
  char c = *((char *) t);
  printf("%c", c);
}

Bool comparatorVertex(Type v1, Type v2) {
  char c1 = *((char *) v1);
  char c2 = *((char *) v2);
  return (c1 == c2);
}


int main(void) {
  char v1 = 'A';
  char v2 = 'B';
  char v3 = 'C';
  Graph g = graph_create(printVertex, NULL, comparatorVertex);

  graph_addVertex(g, &v1);
  graph_addVertex(g, &v2);
  graph_addVertex(g, &v3);

  graph_addEdge(g, &v1, &v2, 2.0);
  graph_addEdge(g, &v1, &v3, 2.0);
  graph_addEdge(g, &v2, &v3, 5.5);

  graph_printer(g);

  graph_deleteEdge(g, &v1, &v2);

  graph_printer(g);

  return 0;
}