#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

// Structure for the priority queue
typedef struct
{
    int heap[MAX_SIZE];
    int size;
} PriorityQueue;

// Function prototypes
void init(PriorityQueue *pq);
void swap(int *a, int *b);
void heapify_up(PriorityQueue *pq, int index);
void heapify_down(PriorityQueue *pq, int index);
void enqueue(PriorityQueue *pq, int value);
int dequeue(PriorityQueue *pq);
int peek(PriorityQueue *pq);
int is_empty(PriorityQueue *pq);
int is_full(PriorityQueue *pq);

// Initialize the priority queue
void init(PriorityQueue *pq)
{
    pq->size = 0;
}

// Swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (used after inserting an element)
void heapify_up(PriorityQueue *pq, int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && pq->heap[index] < pq->heap[parent])
    {
        swap(&pq->heap[index], &pq->heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Heapify down (used after removing the root)
void heapify_down(PriorityQueue *pq, int index)
{
    int min_index = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    if (left_child < pq->size && pq->heap[left_child] < pq->heap[min_index])
    {
        min_index = left_child;
    }

    if (right_child < pq->size && pq->heap[right_child] < pq->heap[min_index])
    {
        min_index = right_child;
    }

    if (min_index != index)
    {
        swap(&pq->heap[index], &pq->heap[min_index]);
        heapify_down(pq, min_index);
    }
}

// Insert an element into the priority queue
void enqueue(PriorityQueue *pq, int value)
{
    if (is_full(pq))
    {
        printf("Priority queue is full. Cannot enqueue.\n");
        return;
    }

    pq->heap[pq->size] = value;
    heapify_up(pq, pq->size);
    pq->size++;
}

// Remove and return the element with the highest priority (lowest value)
int dequeue(PriorityQueue *pq)
{
    if (is_empty(pq))
    {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return INT_MIN;
    }

    int min = pq->heap[0];
    pq->size--;
    pq->heap[0] = pq->heap[pq->size];
    heapify_down(pq, 0);

    return min;
}

// Return the element with the highest priority without removing it
int peek(PriorityQueue *pq)
{
    if (is_empty(pq))
    {
        printf("Priority queue is empty.\n");
        return INT_MIN;
    }
    return pq->heap[0];
}

// Check if the priority queue is empty
int is_empty(PriorityQueue *pq)
{
    return pq->size == 0;
}

// Check if the priority queue is full
int is_full(PriorityQueue *pq)
{
    return pq->size == MAX_SIZE;
}

// Main function to test the priority queue
int main()
{
    PriorityQueue pq;
    init(&pq);

    enqueue(&pq, 5);
    enqueue(&pq, 2);
    enqueue(&pq, 8);
    enqueue(&pq, 1);
    enqueue(&pq, 10);

    printf("Peek: %d\n", peek(&pq));

    while (!is_empty(&pq))
    {
        printf("%d ", dequeue(&pq));
    }
    printf("\n");

    return 0;
}