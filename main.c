#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Function prototypes
void encolar(int cola[], int *frente, int *final, int elemento);
void desencolar(int cola[], int *frente, int *final);
void mostrarCola(int cola[], int frente, int final);

int main() {
    int cola[MAX];       // Queue array
    int frente = -1;     // Index of the front element
    int final = -1;      // Index of the rear element
    int opcion, elemento;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue (insert)\n");
        printf("2. Dequeue (remove)\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &elemento);
                encolar(cola, &frente, &final, elemento);
                mostrarCola(cola, frente, final);
                break;

            case 2:
                desencolar(cola, &frente, &final);
                mostrarCola(cola, frente, final);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}

// Function to enqueue an element
void encolar(int cola[], int *frente, int *final, int elemento) {
    // Check if the queue is full
    if (*final == MAX - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (*frente == -1) {
            *frente = 0; // First element inserted
        }
        *final = *final + 1;
        cola[*final] = elemento;
        printf("Enqueued: %d\n", elemento);
    }
}

// Function to dequeue an element
void desencolar(int cola[], int *frente, int *final) {
    // Check if the queue is empty
    if (*frente == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("Dequeued: %d\n", cola[*frente]);

        // If the queue has only one element
        if (*frente == *final) {
            *frente = *final = -1;
        } else {
            *frente = *frente + 1;
        }
    }
}

// Function to display the current content of the queue
void mostrarCola(int cola[], int frente, int final) {
    if (frente == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Current queue: ");
        for (int i = frente; i <= final; i++) {
            printf("%d ", cola[i]);
        }
        printf("\n");
    }
}
