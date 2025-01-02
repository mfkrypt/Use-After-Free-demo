#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void uaf() {
    
    char *ptr = malloc(10 * sizeof(char));  // Allocate 10 bytes memory to ptr
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }



    for (int i = 0; i < 9; i++){    // Fill with some 'A's
        ptr[i] = 'A';
    }
    ptr[9] = '\0';




    printf("Before memory is freed: %s\n", ptr);
    free(ptr);
    // ptr = NULL    // Not using this line will cause UAF vulnerability     
    printf("Memory is freed :)\n");
    printf("Dangling pointer value: %s\n", ptr);



    char *new_ptr = malloc(10 * sizeof (char));     // Allocate another 10 bytes to a new pointer
    for (int i = 0; i < 10; i++) {
        new_ptr[i] = 'B';                       // Fill the new memory with 'B's
    }
    new_ptr[9] = '\0';


    printf("New allocation of new pointer: %s\n", new_ptr);
    printf("Current value of dangling pointer: %s\n", ptr);

    // In conclusion, a dangling pointer can still access the memory location that has been freed. 
    // If new memory is allocated at the same location, the dangling pointer may access or modify the 
    // newly allocated memory.

    // Setting the pointer to NULL ensures it doesn't point to invalid memory

}



int main() {

    uaf();

    return 0;
}
