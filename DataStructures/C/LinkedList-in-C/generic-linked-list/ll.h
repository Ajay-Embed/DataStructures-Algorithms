#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stddef.h>

// TBD: Comments and Documentation

typedef struct Node LinkedListNode_t;

struct Node {
    void* data;
    LinkedListNode_t* next;
};

// Warning: This implementation is not thread-safe, and is for educational purposes only.

// Nomenclauture used (to avoid collisions): <data_type>_<method_name>

LinkedListNode_t* ll_new_node(void* data);
void ll_free(LinkedListNode_t* head, void (*deallocator)(void*));
void ll_print(LinkedListNode_t* head, void (*printer)(void*));
bool ll_is_empty(LinkedListNode_t* head);
bool ll_is_circular(LinkedListNode_t* head);
LinkedListNode_t* ll_copy(LinkedListNode_t* head, void* (*copy_data)(void*));
LinkedListNode_t* ll_from_array(void* array, size_t element_size, size_t length, void* (*copy_data)(void*));
LinkedListNode_t* ll_from_pointer_array(void** array, size_t length, void* (*copy_data)(void*));
void** ll_to_array(LinkedListNode_t* head, size_t* out_length);
size_t ll_find(LinkedListNode_t* node, void* target, int (*cmp)(void*, void*));
size_t ll_length(LinkedListNode_t* node);
LinkedListNode_t* ll_index(LinkedListNode_t* node, size_t index);
LinkedListNode_t* ll_get_tail(LinkedListNode_t* node);
LinkedListNode_t* ll_insert_head(LinkedListNode_t* head, void* data);
LinkedListNode_t* ll_insert_tail(LinkedListNode_t* head, void* data);
LinkedListNode_t* ll_insert_index(LinkedListNode_t* head, void* data, size_t index);
LinkedListNode_t* ll_insert_ll_index(LinkedListNode_t* head, LinkedListNode_t* new_list, size_t index);
LinkedListNode_t* ll_append(LinkedListNode_t* head, LinkedListNode_t* other);
LinkedListNode_t* ll_remove(LinkedListNode_t* head, void* target, int (*cmp)(void*, void*), void (*deallocator)(void*));
LinkedListNode_t* ll_remove_index(LinkedListNode_t* head, size_t index, void (*deallocator)(void*));
LinkedListNode_t* ll_remove_range(LinkedListNode_t* head, size_t start, size_t end, void (*deallocator)(void*));
LinkedListNode_t* ll_delete(LinkedListNode_t* head, void* target, int (*cmp)(void*, void*), void (*deallocator)(void*));
LinkedListNode_t* ll_sort(LinkedListNode_t* head, int (*cmp)(void*, void*));
LinkedListNode_t* ll_reverse(LinkedListNode_t* head);
LinkedListNode_t* ll_map(LinkedListNode_t* head, void* (*fx)(void*));
LinkedListNode_t* ll_filter(LinkedListNode_t* head, bool (*predicate)(void*), void* (*copy_element)(void*));
void* ll_collect(LinkedListNode_t* head, void* state, void (*fx)(void*, void*));

#endif  // LINKEDLIST_H