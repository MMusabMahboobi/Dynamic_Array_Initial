//
// Created by mmahb on 2026-06-16.
//

#include <stdlib.h>

typedef struct {
    int* data; //points to the array location
    int size; //the amount of data in the array
    int capacity; //the total amount of data that can be stored in the array; will double whenever it is reached
} Dyn_Array;

Dyn_Array create_array(int capacity) {
    Dyn_Array new_array;
    new_array.data = malloc(capacity * sizeof(int));
    new_array.size = 0;
    new_array.capacity = capacity;
    return new_array;
}

Dyn_Array push_array(Dyn_Array array, int newItem) {
    //if adding newItem goes over capacity
    if (array.size + 1 > array.capacity) {
        array.capacity *= 2;
        array.data = realloc(array.data, array.capacity * sizeof(int));
    }

    //add newItem and increase size
    array.data[array.size] = newItem;
    array.size++;
    return array;
}

Dyn_Array pop_Array(Dyn_Array array) {
    //delete last item
    if (array.size > 0) {
        array.size--;
    }
    return array;
}

void destroy_array(Dyn_Array array) {
    free(array.data);
}
