//
// Created by lukas on 16.02.20.
// emcc -g0 -Os -s SIDE_MODULE=1 -s STRICT=1 -s WASM=1 -o main/test.c.wasm main/test.c && xxd -i main/test.c.wasm > main/test.wasm.h
//
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <emscripten.h>

#define WASM_EXPORT __attribute__((used)) __attribute__((visibility ("default")))


typedef uint32_t Int;

typedef struct Node Node;

struct Node {
    Int payload; // ignored; just for plausability.
    Node* next;
};

//typedef struct node {
//    int val;
//    struct node * next;
//} node_t;



//void random_shuffle(Node **list, uint32_t N) {
//    for (uint32_t i = 0; i < N - 1; ++i) {
//        uint32_t swap_ix = i + rand() % (N - i);
//        Node *tmp = list[swap_ix];
//        list[swap_ix] = list[i];
//        list[i] = tmp;
//    }
//}

WASM_EXPORT
uint32_t run(Int N) {
    // Allocate all the memory continuously so we aren't affected by the particulars of the system allocator:
    Node* memory = (Node*)malloc(N * sizeof(Node));

    // Initialize the node pointers:
    Node** nodes = (Node**)malloc(N * sizeof(Node*));
    for (Int i=0; i<N; ++i) {
        nodes[i] = &memory[i];
    }

    // Randomize so emulate a list that has been shuffled around a bit.
    // This is so that each memory acces is a *random* memory access.
    // This is the worst case scenario for a linked list, which is exactly what we want to measure.
    // Without the random_shuffle we get O(N) because it enables the pre-fetcher to do its job.
    // Without a prefetcher, a random memory access in N bytes of RAM costs O(N^0.5) due to the Bekenstein bound.
    // This means we get O(N^1.5) complexity of a linked list traversal.
//    random_shuffle(nodes, N);

    // Link up the nodes:
    for (Int i=0; i<N-1; ++i) {
//        nodes[i]->next = nodes[i+1];
    }
//    nodes[N - 1]->next = NULL;

//    Node *start_node = nodes[0];
//
//    free(nodes); // Free up unused memory before meassuring:
//
//    for (uint32_t it = 0; it < 10; ++it) {
//        // Run through all the nodes:
//        Node *node = start_node;
//        while (node) {
//            node = node->next;
//        }
//    }

//    node_t * head = NULL;
//    head = (node_t *) malloc(sizeof(node_t));
//    head->val = 1;
//    head->next = (node_t *) malloc(sizeof(node_t));
//    head->next->val = 2;
//    head->next->next = NULL;
//    node_t * current = head;

//    while (current != NULL) {
//        printf("%d\n", current->val);
//        current = current->next;
//    }

    return N;
}
