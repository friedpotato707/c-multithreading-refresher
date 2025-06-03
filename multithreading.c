#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * child_function(void* args) {
    printf("Child thread %d is runnning. \n", *(int *) args);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};
    
    // Creating child threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, child_function, &thread_ids[i]);
    }
    
    // Joining child threads back to the main thread
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All child threads have finished execution.\n");
    return EXIT_SUCCESS;
}
