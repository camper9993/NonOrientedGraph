
#include "graph.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
    if (strncmp(argv[1],"test",4) != 0) {
        buildGraph(argv[2],argv[3]);
    }
    if (strncmp(argv[1],"test",4) == 0) {
        test();
    }
    return 0;
}
