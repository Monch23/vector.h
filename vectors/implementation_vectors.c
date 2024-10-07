#include "vector.h"
#include <stdlib.h>

void resize(int **changer, int cap, int size) {
	int *tmp = (int*)malloc(cap * sizeof(int));

	for (int i = 0; i < size; ++i) {
		tmp[i] = (*changer)[i];
	}
	free(*changer);
	*changer = tmp;
}

void vector_init(Vector *this) {
	this->capacity = 0;
	this->size = 0;
	this->data = NULL;
}

void vector_init_size(Vector *this, size_t n) {
	this->capacity = n;
	this->size = 0;
	this->data = (int*)malloc(n * sizeof(int));
}

void vector_init_fill(Vector *this, size_t n, int value) {
	this->capacity = 2 * n;
	this->size = n;

	this->data = (int*)malloc((2 * n) * sizeof(int));
	
	for (int i = 0; i < n; ++i) {
		this->data[i] = value;
	}
}

void vector_copy(Vector *this, const Vector *other) {
	if (other->data == NULL) {
		vector_init(this);
		return;
	}

	this->capacity = other->capacity;
	this->size = other->size;

	for (int i = 0; i < other->size; ++i) {
		this->data[i] = other->data[i];
	}
	
	return;
}

void vector_destroy(Vector *this) {
	this->capacity = 0;
	this->size = 0;
	free(this->data);
	this->data = NULL;
}

Vector *vector_assign(Vector *dest, const Vector *src) {
	if (dest->data == src->data) {
		return NULL;
	}
	if (dest->data == NULL || src->data == NULL) {
		return NULL;
	}
	dest->capacity = src->capacity;
	dest->size = src->size;

	free(dest->data);
	dest->data = (int*)calloc(src->capacity, sizeof(int));
	
	for (int i = 0; i < src->size; ++i) {
		dest->data[i] = src->data[i];
	}

	return dest;
}

int *vector_at(Vector *vec, size_t index) {
	if (vec->size == 0 || index > vec->size) {
		return NULL;
	}

	return &vec->data[index];
}

int *vector_front(Vector *vec) {
	if (vec->size == 0) {
		return NULL;
	}
	
	return &vec->data[0];
}

int *vector_back(Vector *vec) {
	if (vec->size == 0) {
		return NULL;
	}

	return &vec->data[vec->size - 1];
}

int vector_empty(const Vector *vec) {
	return !(vec->size);
}

size_t vector_size(const Vector *vec) {
	return (vec->size);
}

size_t vector_capacity(const Vector *vec) {
	return (!(vec->capacity)) ? 0 : vec->capacity;
}

void vector_reserve(Vector *vec, size_t new_cap) {
	if (vec->data == NULL || new_cap > vec->capacity) {
		vec->data = (int*)realloc(vec->data, new_cap * sizeof(int));
		vec->capacity = new_cap;
		return;
	}
	
	return;
}

void vector_clear(Vector *vec) {
	if (vec->data == NULL) {
		return;
	}
	vec->size = 0;
	return;
}

void vector_push_back(Vector *vec, int value) {
	if (vec->size < vec->capacity) {
		vec->data[vec->size++] = value;
		return;
	} else if (vec->size == vec->capacity) {
		vec->capacity *= 2;
		resize(&vec->data, vec->capacity, vec->size);
		vec->data[vec->size++] = value;
		return;
	} else {
		vector_init_size(vec, 1);
		vec->data[vec->size++] = value;
	}
	
	return;
}

void vector_pop_back(Vector *vec) {
	if (vec->size == 0) {
		return;
	}
	
	resize(&vec->data, vec->capacity, vec->size - 1);
	vec->size -= 1;
}
