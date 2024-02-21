/*
 * Vector, allows for a dynamic array that changes the size of the list underneath the hood.
 * Note: The array will change during updates (push(), pop(), remove_at(), etc)
 * Note: The array will be just integers not other types.
 * */
typedef struct Vector
{
    int* vector;    // Points to the first address of the contigous part of memory
    int cap;        // This holds the capacity of the array
    int size;       // The number of elements in the array
} Vector;


Vector* create_vector(void);
void push(Vector* v, int value);
void prepend(Vector* v, int value);
int pop(Vector* v);
int capacity(Vector* v);
int length(Vector* v);
void print_vector(Vector* v);
