#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>

typedef struct {
	size_t capacity;
	size_t size;
	int *data;
} Vector;

void vector_init(Vector *this);
void vector_init_size(Vector *this, size_t n);
void vector_init_fill(Vector *this, size_t n, int value);
void vector_copy(Vector *this, const Vector* other);
void vector_destroy(Vector *this);
Vector *vector_assign(Vector *dest, const Vector *src);
int *vector_at(Vector *v, size_t index);
int *vector_front(Vector *vec);
int *vector_back(Vector *vec);
int vector_empty(const Vector *vec);
size_t vector_size(const Vector *vec);
size_t vector_capacity(const Vector *vec);
void vector_reserve(Vector *vec, size_t new_cap);
void vector_clear(Vector *vec);
void vector_push_back(Vector *vec, int value);
void vector_pop_back(Vector *vec);
void vector_insert(Vector *vec, size_t pos, int value);
#endif // VECTOR_H
