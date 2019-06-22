//
//  graph.c
//  ruth
//
//  Created by Алексей on 23/05/2019.
//  Copyright © 2019 Алексей. All rights reserved.
//

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>



void add(struct graph * lol, char name) {
    if (lol -> size != 0) {
        lol -> names = (char*)realloc(lol -> names, (lol -> size + 1) * sizeof(char));
        lol -> names[lol -> size] = name;
        lol -> a = (int**)realloc(lol -> a, (lol -> size + 1) * sizeof(int*));
        lol -> a[lol -> size] = (int *)calloc(lol -> size + 1, sizeof(int));
        for (int i = 0; i < lol -> size; i++)
        {
            lol -> a[i] = (int *)realloc(lol -> a[i], (lol -> size + 1) * sizeof(int*));
        }
    }
    else {
        lol -> names = (char*)calloc(1,sizeof(char));
        lol -> names[lol -> size] = name;
        lol -> a = (int**)calloc(1, sizeof(int*));
        lol -> a[0] = (int*)calloc(1, sizeof(int));
    }
    lol -> size++;
}

void createPath(struct graph *lol, char name1, char name2,int weight) {
    int a = 0;
    int b =0;
    for (int i = 0; i < lol -> size;i++) {
        if (lol -> names[i] == name1) {
            a = i;
        }
        if (lol -> names[i] == name2) {
            b = i;
        }
    }
    lol -> a[a][b] = weight;
    lol -> a[b][a] = weight;
}

void changePath(struct graph *lol, char name1, char name2, int weight) {
    createPath(lol, name1, name2, weight);
}

void delete(struct graph *lol, char name) {
    int a = 0;
    for (int i = 0; i < lol -> size;i++) {
        if (lol -> names[i] == name) {
            a = i;
        }
    }
    if (a == (lol -> size - 1)) {
        lol -> names = (char*)realloc(lol -> names, (lol -> size - 1)*sizeof(char));
        free(lol -> a[lol -> size - 1]);
        lol -> a = (int**)realloc(lol -> a, (lol -> size - 1) * sizeof(int*));
    }
    else {
        for (int i = 0;i < lol -> size - 1;i++) {
            for (int j = 0;j < lol -> size - 1;j++) {
                if (i >= a) {
                    lol -> names[i] = lol -> names[i + 1];
                if (i >= a && j >= a) {
                    lol -> a[i][j] = lol -> a[i + 1][j + 1];
                }
                if (i >= a && j < a) {
                    lol -> a[i][j] = lol -> a[i + 1][j];
                }
                if (i < a && j >= a) {
                    lol -> a[i][j] = lol -> a[i][j + 1];
                }
                if (i < a && j < a) {
                    lol -> a[i][j] = lol -> a[i][j];
                }
            }
            }
        }
    }
    free(lol -> a[lol -> size]);
    lol -> a = (int **) realloc (lol -> a, (lol -> size - 1) * sizeof(int*));
    lol -> names = (char *) realloc (lol -> names, (lol -> size - 1) * sizeof(char));
    lol -> size--;
}

void deleteGraph (struct graph * lol) {
    for (int i = 0; i < lol -> size; ++i) {
        free(lol -> a[i]);
    }
    free(lol -> a);
    free(lol -> names);
}

void buildGraph(char *a, char *b) {
    int weight;
    struct graph kek;
    kek.size = 0;
    FILE *test = fopen(a, "r");
    FILE *out = fopen(b, "w");
    FILE *testout = fopen("output_test.txt", "w");
    if (test == NULL)
    {
        return;
    }
    char param[30];
    while (fscanf(test, "%s", param) != EOF ) {
        if (param[0] == 'a') {
            add(&kek, param[4]);
        }
        if (param[0] == 'c' && param[1] == 'r') {
            if (kek.size != 0) {
                char vert1 = param[12];
                char vert2 = param[17];
                fscanf(test, "%d", &weight);
                createPath(&kek, vert1, vert2, weight);
            }
        }
        if (param[0] == 'c' && param[1] == 'h') {
            if (kek.size != 0) {
                char vert1 = param[12];
                char vert2 = param[17];
                fscanf(test, "%d", &weight);
                createPath(&kek, vert1, vert2, weight);
            }
        }
        if (param[0] == 'd') {
            char name = param[7];
            delete(&kek, name);
        }
    }
    
    fprintf(out, "\t");
    for (int i = 0; i < kek.size; i++) {
        fprintf(out, "%c\t",kek.names[i]);
        
    }
    fprintf(out, "\n");
    for (int i = 0; i < kek.size; i++) {
        for (int j = 0; j < kek.size; j++) {
            if (j == 0) {
                fprintf(out, "%c\t", kek.names[i]);
            }
            
            if (j != (kek.size - 1)) {
                fprintf(out, "%d\t",kek.a[i][j]);
            }
            else
                fprintf(out, "%d\n",kek.a[i][j]);
        }
    }
    for (int i = 0; i < kek.size; i++) {
        for (int j = 0; j < kek.size; j++) {
            if (j != (kek.size - 1)) {
                fprintf(testout, "%d ",kek.a[i][j]);
            }
            else
                fprintf(testout, "%d\n",kek.a[i][j]);
        }
    }
    for (int i = 0; i < kek.size; ++i) {
        free(kek.a[i]);
    }
    deleteGraph(&kek);
    fclose(out);
    fclose(testout);
}

