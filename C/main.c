#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>

int main() {
    const uint64_t count = 20000000; 
    
    uint64_t capacity = count * 2;
    uint64_t* values = (uint64_t*)malloc(capacity * sizeof(uint64_t));
    if (values == NULL) {
        fprintf(stderr, "allocation failed\n");
        return 1;
    }
    uint64_t size = 0;

    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    for (uint64_t i = 0; i < count; i++) {
        values[size++] = i;
    }

    for (uint64_t i = count; i > 0; i--) {
        values[size++] = i;
    }

    QueryPerformanceCounter(&end);

    double ms = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

    printf("time exec in milliseconds: %.3f\n", ms);

    volatile uint64_t antiTrapaca = values[0] + values[size - 1];
    (void)antiTrapaca;
    free(values); 

    return 0;
}