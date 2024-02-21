#include "vector.h"
#include <stdio.h>

int main(void)
{
    Vector* myVector = create_vector();
    for (int i = 1; i <= 9; i++)
    {
        push(myVector, i);
    }
    print_vector(myVector);
    printf("Pop!\n");
    int pop_result = pop(myVector);
    printf("Length %d\n", length(myVector));
    printf("Popped value=%d\n", pop_result);
    print_vector(myVector);
    prepend(myVector, 9);
    print_vector(myVector);
    return 0;
}
