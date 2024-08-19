#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Vector {
    int capacity;
    int size;
    int * vec;
} typedef Vector;


void init(Vector * vec) {
    vec -> vec = malloc(vec ->capacity * sizeof(int));
}

// void push_back (Vector * vec, int val) {
//     if (vec -> capacity == vec -> size) {
//         vec -> capacity *= 2;
//         vec -> vec = realloc(vec->vec, vec->capacity * sizeof(int));
//     }
//     vec -> vec[vec->size] = val;
//     vec -> size++;
// }














void push_back (Vector * vec, int val){
    if (vec -> capacity == vec -> size){
        vec -> capacity *= 2;
        vec -> vec = realloc(vec -> vec, vec -> capacity * sizeof(int));
    }
    vec -> vec[vec -> size] = val;
    vec -> size++;
}


void pop_back (Vector * vec) {
    vec ->size--;
}

int main () {
    Vector vec = {
        .size = 0,
        .capacity = 1,
        .vec = NULL 
    };

    while(1);
    init(&vec);
    push_back(&vec, 4);

    printf("%d \n", vec.vec[0]);

}