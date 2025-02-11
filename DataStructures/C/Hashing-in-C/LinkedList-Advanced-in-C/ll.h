#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

// TBD: Comments and Documentation

typedef struct LinkedListNode_t {
    void* data;
    struct LinkedListNode_t* next;
} LinkedListNode_t;

// Nomenclauture used (to avoid collisions): <data_type>_<method_name>

LinkedListNode_t* ll_new_node(void* data);
void ll_free(LinkedListNode_t* head, void (*dellocator)(void*));
void ll_print(LinkedListNode_t* head, void (*printer)(void*));
LinkedListNode_t* ll_copy(LinkedListNode_t* head, void* (*copy_data)(void*));
LinkedListNode_t* ll_from_array(void** array, size_t length, void* (*copy_data)(void*));
void** ll_to_array(LinkedListNode_t* head, size_t* out_length);
size_t ll_find(LinkedListNode_t* node, void* target, int (*cmp)(void*, void*));
size_t ll_length(LinkedListNode_t* node);
LinkedListNode_t* ll_index(LinkedListNode_t* node, size_t index);
LinkedListNode_t* ll_tail(LinkedListNode_t* node);
LinkedListNode_t* ll_insert_head(LinkedListNode_t* head, void* data);
LinkedListNode_t* ll_insert_tail(LinkedListNode_t* head, void* data);
LinkedListNode_t* ll_insert_index(LinkedListNode_t* head, void* data, size_t index);
LinkedListNode_t* ll_insert_ll_index(LinkedListNode_t* head, LinkedListNode_t* new_list, size_t index);
LinkedListNode_t* ll_append(LinkedListNode_t* head, LinkedListNode_t* new_list);
LinkedListNode_t* ll_remove_index(LinkedListNode_t* head, size_t index, void (*dellocator)(void*));
LinkedListNode_t* ll_remove_range(LinkedListNode_t* head, size_t start, size_t end, void (*dellocator)(void*));
LinkedListNode_t* ll_delete(LinkedListNode_t* head, void* target, int (*cmp)(void*, void*), void (*dellocator)(void*));

#endif  // LINKEDLIST_H