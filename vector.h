//Vector implementation using array

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1

typedef int ret_t;
typedef int data_t;
typedef int bool;
typedef struct dynamic_array {
    int *a;
    size_t N;
}vector_t;

vector_t* create_vector();
ret_t push_back(vector_t* p_vec, data_t new_data);
void show_vector(vector_t* p_vec);
//ret_t destroy_vector(vector_t* p_vec);


void* xcalloc(size_t nr_elements, size_t size_per_element);


