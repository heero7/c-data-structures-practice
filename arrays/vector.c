#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define INIT_CAP 8

void grow(Vector* v);

Vector* create_vector(void)
{
    int* m_result = malloc(sizeof(int) * INIT_CAP);
    if (m_result == NULL)
    {
        // todo: What is a good way to error in C?
        printf("[Vector] Trouble creating memory for Vector\n");
        return NULL;
    }

    Vector* v;
    v->cap = INIT_CAP;
    v->size = 0;
    v->vector = m_result;

    return v;
}

void push(Vector* v, int value)
{
    // Why can't you do this?
    // This doesn't work, but why? I think I know.
    //  Questions:
    //      How does moving by + 1 move exactly where we want to go? Answered.
    //      Does this change if I allocated for a char? (or for a struct)? Answered.
    //      How does the compiler know what data type is stored and how much to move?
    //  Answer:
    //      When incrementing/decrementing the increment will increase by the data type that is stored there.
    //      Example int* pointer = 0x1000. Where 0x1000 has the value 123. If you do pointer++, the address would be
    //      0x1004.
    if (v->size + 1 > v->cap)
    {
        grow(v);
    }
    int* location = v->vector;
    location += v->size; 

    (*location) = value; 

    v->size++;
}

void prepend(Vector *v, int value)
{
    if (v->size + 1 > v->cap)
    {
        grow(v);
    }

    int* list = v->vector;
    for (int i = v->size; i > 0; i--)
    {
        v->vector[i] = v->vector[i-1];
    }
    v->vector[0] = value;
    v->size++;
}

int pop(Vector *v)
{
    int* head = v->vector;
    head += v->size - 1;    // Tail / end of array
                            // You've done this twice now (as of 2/19/24). 
                            // Vector.size starts at 0 (which is a valid index). Size - 1 are where the values are at.
    int value = (*head);
    (*head) = 0x0;          // todo: should decide on what is a bad value. (use 0x0 / NULL)
    v->size--;
    return value;
}

int capacity(Vector *v)
{
    return v->cap;
}

int length(Vector *v)
{
    return v->size;
}

void print_vector(Vector *v)
{
    int* list = v->vector;
    for (int i = 0; i < v->cap; i++)
    { 
        printf("[%d] ", list[i]);
    }
    printf("\n");
}

void grow(Vector* v)
{
    printf("[Vector] vector is growing! from %d to %d\n", v->cap, v->cap * 2);
    // allocate memory for double the cap.
    int* m_result = malloc(sizeof(int) * v->cap * 2);
    if (m_result == NULL)
    {
        printf("[Vector] trouble growing array\n");
    }
    // change this vector's cap
    v->cap *= 2;
    // place all old stuff, in the new spots
    int* head = v->vector;
    for (int i = 0; i < v->size; i++)
    {
        m_result[i] = v->vector[i];
    }
    // free the memory
    // printf("[Vector] Old head value=%d\n", (*v->vector));
    free(v->vector);
    // garbage / nothing values should be in Vector
    // see for yourself
    // printf("[Vector] Current head value=%d\n", (*v->vector));
    v->vector = m_result;
}
