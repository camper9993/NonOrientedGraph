#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "graph.h"

void test() {
    buildGraph("test2.txt", "output_test.txt");
    FILE *out2 = fopen("output_test.txt", "r");
    int a[4][4] =
    {
        0,7,1,2,
        7,0,0,89,
        1,0,0,6,
        2,89,6,0
    };
    int q = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int iter = 0;
    while (fscanf(out2, "%d%d%d%d", &q,&b,&c,&d) != EOF ) {
        if (!(q == a[iter][0] && b == a[iter][1] && c == a[iter][2] && d == a[iter][3])) {
            printf("Test not passed!");
        }
        iter++;
    }
    printf("Test passed\n");
}
