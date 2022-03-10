#include <stdio.h>
#include <string.h>
#include <limits.h>

#define HEAP_SIZE 1000

int parent(int i)
{
    return ((i-1)/2); 
}

int left(int i)
{
    return ((2*i) + 1);
}

int right (int i)
{
    return ((2*i) + 2);
}

void swap (int * a, int *b)
{
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int getMin(int a, int b, int c)
{
    return (a<b) ? ((a<c) ? a : c) : ((b<c) ? b : c); 
}

typedef struct minHeap
{
    int arr[HEAP_SIZE]; // can be dynamically allocated too
    int size;
    int capacity;
}minHeap_t; 

void init_heap(minHeap_t* h, int size)
{
    h->size = 0;
    h->capacity = HEAP_SIZE; 
    memset(h->arr, 0, HEAP_SIZE);
}

void heapify(minHeap_t* h, int i)
{
    if(!h) return;

    if(h->size == 0) return; 

    if(i == h->size) return;
   
    int l = left(i);
    int r = right(i); 

    int m = getMin(h->arr[i], h->arr[l], h->arr[r]); 

    if(m == h->arr[i]) return; 

    else if((l < h->size) && (m == h->arr[l]))
    {
        swap(&h->arr[i], &h->arr[l]); 
        heapify(h, l);
    }

    else if(r < h->size)
    {
        swap(&h->arr[i], &h->arr[r]); 
        heapify(h, r);
    }
}

void heapInsert(minHeap_t* h, int key)
{
    if(!h) return; 

    if(h->size == h->capacity) return;

    h->arr[h->size++] = key;
    
    int i = h->size - 1;

    while((i!=0) && (h->arr[i] < h->arr[parent(i)]))
    {
        swap(&h->arr[i] , &h->arr[parent(i)]);
        i=parent(i); 
    }
}

void decreaseKey(minHeap_t* h, int i, int value)
{
    if(!h) return;
    
    h->arr[i] = value;

    while((i!=0) && (h->arr[i] < h->arr[parent(i)]))
    {
        swap(&h->arr[i] , &h->arr[parent(i)]);
        i=parent(i);
    }
}

int extractMin(minHeap_t* h)
{
    if(h->size == 0) return -1;
    
    if(h->size == 1) 
    {
        return h->arr[0];
        h->size--;
    }
    
    int ret = h->arr[0];
    h->arr[0] = h->arr[h->size-1]; 
    h->size--; 
    heapify(h, 0);
    return ret;
}

void deleteKey(minHeap_t* h, int i)
{
    decreaseKey(h, i, INT_MIN);
    extractMin(h);
}

int main(void)
{
    minHeap_t h; 
    
    init_heap(&h, 7);
    
    heapInsert(&h, 3);
    heapInsert(&h, 2);
    heapInsert(&h, 1);
    heapInsert(&h, 6);
    heapInsert(&h, 15);
    heapInsert(&h, 7);
    heapInsert(&h, 5);

    decreaseKey(&h, 4, 4);

    for(int i = 0; i<7; i++)
    {
        printf("%d ", extractMin(&h));
    }

    return 0;
}
