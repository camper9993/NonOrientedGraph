//
//  graph.h
//  ruth
//
//  Created by Алексей on 23/05/2019.
//  Copyright © 2019 Алексей. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>

typedef struct graph {
    int ** a;
    int size;
    char *names;
}graph;

void add(struct graph * lol, char name);
void createPath(struct graph *lol, char name1, char name2,int weight);
void buildGraph(char *a, char *b);
void changePath(struct graph *lol, char name1, char name2, int weight);
void delete(struct graph *lol, char name);
void deleteGraph (struct graph *lol);
#endif /* graph_h */
