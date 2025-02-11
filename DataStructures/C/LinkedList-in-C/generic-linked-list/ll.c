#include "ll.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
    Inner functions, not to be used externally.
*/

void __ll_split(LinkedListNode_t* source, LinkedListNode_t** front, LinkedListNode_t** back);
LinkedListNode_t* __ll_merge(LinkedListNode_t* a, LinkedListNode_t* b, int (*cmp)(void*, void*));
LinkedListNode_t* __ll_merge_sort(LinkedListNode_t* head, int (*cmp)(void*, void*));

LinkedListNode_t* ll_new_node(void* data) {
    LinkedListNode_t* node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

    if (!node) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

void ll_free(LinkedListNode_t* head, void (*deallocator)(void*)) {
    if (!head || !deallocator) return;

    LinkedListNode_t* curr = head;

    while (curr) {
        LinkedListNode_t* temp = curr;
        curr = curr->next;

        deallocator(temp->data);
        free(temp);
    }
}

void ll_print(LinkedListNode_t* head, void (*printer)(void*)) {
    LinkedListNode_t* node = head;

    printf("[");

    while (node) {
        if (printer) {
            printer(node->data);
        } else {
            printf("<@%p>", node->data);
        }

        if ((node = node->next)) {
            printf(", ");
        }
    }

    printf("]");
}

bool ll_is_empty(LinkedListNode_t* head) {
    return head != NULL;
}

bool ll_is_circular(LinkedListNode_t* head) {
    if (!head) return 0;

    LinkedListNode_t* slow = head;
    LinkedListNode_t* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = slow->next->next;

        if (slow == fast) return true;
    }

    return false;
}

LinkedListNode_t* ll_copy(LinkedListNode_t* head, void* (*copy_data)(void*)) {
    if (!head || !copy_data) return NULL;

    LinkedListNode_t* curr = head;
    LinkedListNode_t* new_head = NULL;
    LinkedListNode_t* new_tail = NULL;

    while (curr) {
        LinkedListNode_t* new_node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

        if (!new_node) return NULL;

        new_node->data = copy_data(curr->data);
        new_node->next = NULL;

        if (!new_head) {
            new_head = new_tail = new_node;
        } else {
            new_tail->next = new_node;
            new_tail = new_node;
        }

        curr = curr->next;
    }

    return new_head;
}

LinkedListNode_t* ll_from_array(void* array, size_t element_size, size_t length, void* (*copy_data)(void*)) {
    if (!array || length == 0 || !copy_data) return NULL;

    LinkedListNode_t* head = NULL;
    LinkedListNode_t* tail = NULL;

    for (size_t i = 0; i < length; i++) {
        LinkedListNode_t* new_node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

        if (!new_node) return NULL;

        new_node->data = copy_data(array + (i * element_size));
        new_node->next = NULL;

        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

LinkedListNode_t* ll_from_pointer_array(void** array, size_t length, void* (*copy_data)(void*)) {
    if (!array || length == 0 || !copy_data) return NULL;

    LinkedListNode_t* head = NULL;
    LinkedListNode_t* tail = NULL;

    for (size_t i = 0; i < length; i++) {
        LinkedListNode_t* new_node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

        if (!new_node) return NULL;

        new_node->data = copy_data(array[i]);
        new_node->next = NULL;

        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

void** ll_to_array(LinkedListNode_t* head, size_t* out_length) {
    if (!head || !out_length) return NULL;

    size_t length = 0;
    LinkedListNode_t* curr = head;

    while (curr) {
        length++;
        curr = curr->next;
    }

    void** array = (void**)malloc(length * sizeof(void*));

    if (!array) return NULL;

    curr = head;
    for (size_t i = 0; i < length; i++) {
        array[i] = curr->data;
        curr = curr->next;
    }

    *out_length = length;
    return array;
}

size_t ll_find(LinkedListNode_t* node, void* target, int (*cmp)(void*, void*)) {
    size_t index = -1;

    if (!cmp) return index;

    while (node) {
        index++;

        if (cmp(node->data, target) == 0) {
            break;
        }

        node = node->next;
    }

    return index;
}

size_t ll_length(LinkedListNode_t* node) {
    size_t length = 0;

    while (node) {
        length++;
        node = node->next;
    }

    return length;
}

LinkedListNode_t* ll_index(LinkedListNode_t* node, size_t index) {
    size_t curr_index = 0;

    while (node && curr_index < index) {
        node = node->next;
        curr_index++;
    }

    return node;
}

LinkedListNode_t* ll_get_tail(LinkedListNode_t* node) {
    if (!node) return NULL;

    while (node->next) {
        node = node->next;
    }

    return node;
}

LinkedListNode_t* ll_insert_head(LinkedListNode_t* head, void* data) {
    LinkedListNode_t* node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

    if (!node) return NULL;

    node->data = data;
    node->next = head;

    return node;
}

LinkedListNode_t* ll_insert_tail(LinkedListNode_t* head, void* data) {
    if (!head) return ll_new_node(data);

    LinkedListNode_t* node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

    if (!node) return NULL;

    node->data = data;
    node->next = NULL;

    LinkedListNode_t* curr = head;

    while (curr->next) {
        curr = curr->next;
    }

    curr->next = node;

    return head;
}

LinkedListNode_t* ll_insert_index(LinkedListNode_t* head, void* data, size_t index) {
    if (index == 0) return ll_insert_head(head, data);

    LinkedListNode_t* curr = head;
    size_t curr_index = 0;

    while (curr && curr_index < index - 1) {
        curr = curr->next;
        curr_index++;
    }

    if (!curr) return NULL;

    LinkedListNode_t* node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

    if (!node) return NULL;

    node->data = data;
    node->next = curr->next;
    curr->next = node;

    return head;
}

LinkedListNode_t* ll_insert_ll_index(LinkedListNode_t* head, LinkedListNode_t* new_list, size_t index) {
    if (!new_list) return head;

    if (index == 0) {
        LinkedListNode_t* last = new_list;
        while (last->next) {
            last = last->next;
        }
        last->next = head;
        return new_list;
    }

    LinkedListNode_t* curr = head;
    size_t curr_index = 0;

    while (curr && curr_index < index - 1) {
        curr = curr->next;
        curr_index++;
    }

    if (!curr) return head;

    LinkedListNode_t* last = new_list;
    while (last->next) {
        last = last->next;
    }

    last->next = curr->next;
    curr->next = new_list;

    return head;
}

LinkedListNode_t* ll_append(LinkedListNode_t* head, LinkedListNode_t* other) {
    if (!head) return other;
    if (!other) return head;

    LinkedListNode_t* curr = head;

    while (curr->next) {
        curr = curr->next;
    }

    curr->next = other;

    return head;
}

LinkedListNode_t* ll_remove(LinkedListNode_t* head, void* target, int (*cmp)(void*, void*), void (*deallocator)(void*)) {
    if (!head || !cmp || !deallocator) return head;

    LinkedListNode_t* prev = NULL;
    LinkedListNode_t* curr = head;

    if (cmp(curr->data, target) == 0) {
        head = curr->next;

        deallocator(curr->data);
        free(curr);

        return head;
    }

    while (curr && cmp(curr->data, target) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) return head;

    prev->next = curr->next;

    deallocator(curr->data);
    free(curr);

    return head;
}

LinkedListNode_t* ll_remove_index(LinkedListNode_t* head, size_t index, void (*deallocator)(void*)) {
    if (!head || !deallocator) return head;

    if (index == 0) {
        LinkedListNode_t* temp = head;
        head = head->next;

        deallocator(temp->data);
        free(temp);

        return head;
    }

    LinkedListNode_t* curr = head;
    size_t curr_index = 0;

    while (curr->next && curr_index < index - 1) {
        curr = curr->next;
        curr_index++;
    }

    if (!curr->next) return head;

    LinkedListNode_t* temp = curr->next;
    curr->next = temp->next;

    deallocator(temp->data);
    free(temp);

    return head;
}

LinkedListNode_t* ll_remove_range(LinkedListNode_t* head, size_t start, size_t end, void (*deallocator)(void*)) {
    if (!head || start > end || !deallocator) return head;

    size_t curr_index = 0;
    LinkedListNode_t* prev = NULL;
    LinkedListNode_t* curr = head;

    while (curr && curr_index < start) {
        prev = curr;
        curr = curr->next;
        curr_index++;
    }

    if (!curr) return head;

    LinkedListNode_t* range_start = prev;

    while (curr && curr_index <= end) {
        LinkedListNode_t* temp = curr;
        curr = curr->next;

        deallocator(temp->data);
        free(temp);

        curr_index++;
    }

    if (range_start) {
        range_start->next = curr;
    } else {
        head = curr;
    }

    return head;
}

LinkedListNode_t* ll_delete(LinkedListNode_t* head, void* target, int (*cmp)(void*, void*), void (*deallocator)(void*)) {
    if (!head || !cmp || !deallocator) return head;

    LinkedListNode_t* prev = NULL;
    LinkedListNode_t* curr = head;

    while (curr) {
        if (cmp(curr->data, target) == 0) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }

            deallocator(curr->data);
            free(curr);

            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

LinkedListNode_t* ll_sort(LinkedListNode_t* head, int (*cmp)(void*, void*)) {
    return __ll_merge_sort(head, cmp);
}

LinkedListNode_t* ll_reverse(LinkedListNode_t* head) {
    LinkedListNode_t* prev = NULL;
    LinkedListNode_t* curr = head;
    LinkedListNode_t* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

LinkedListNode_t* ll_map(LinkedListNode_t* head, void* (*fx)(void*)) {
    if (!head || !fx) return NULL;

    LinkedListNode_t* new_head = ll_new_node(fx(head->data));
    LinkedListNode_t* new_tail = new_head;
    LinkedListNode_t* node = head->next;

    while (node) {
        new_tail->next = ll_new_node(fx(node->data));
        new_tail = new_tail->next;
        node = node->next;
    }

    return new_head;
}

LinkedListNode_t* ll_filter(LinkedListNode_t* head, bool (*predicate)(void*), void* (*copy_element)(void*)) {
    if (!head || !predicate) return NULL;

    LinkedListNode_t* new_head = NULL;
    LinkedListNode_t* new_tail = NULL;

    for (LinkedListNode_t* node = head; node; node = node->next) {
        if (predicate(node->data)) {
            void* new_data = copy_element ? copy_element(node->data) : node->data;
            LinkedListNode_t* new_node = ll_new_node(new_data);

            if (!new_head) {
                new_head = new_node;
                new_tail = new_node;
            } else {
                new_tail->next = new_node;
                new_tail = new_tail->next;
            }
        }
    }

    return new_head;
}

void* ll_collect(LinkedListNode_t* head, void* state, void (*fx)(void*, void*)) {
    if (!head || !fx) return state;

    for (LinkedListNode_t* node = head; node; node = node->next) {
        fx(state, node->data);
    }

    return state;
}

/*
    Inner functions implementations. Not to be used externally without precautions.
*/

void __ll_split(LinkedListNode_t* source, LinkedListNode_t** front, LinkedListNode_t** back) {
    if (!source || !source->next) {
        *front = source;
        *back = NULL;
        return;
    }

    LinkedListNode_t* slow = source;
    LinkedListNode_t* fast = source->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

LinkedListNode_t* __ll_merge(LinkedListNode_t* a, LinkedListNode_t* b, int (*cmp)(void*, void*)) {
    if (!a) return b;
    if (!b) return a;

    LinkedListNode_t* result = NULL;

    if (cmp(a->data, b->data) <= 0) {
        result = a;
        result->next = __ll_merge(a->next, b, cmp);
    } else {
        result = b;
        result->next = __ll_merge(a, b->next, cmp);
    }

    return result;
}

LinkedListNode_t* __ll_merge_sort(LinkedListNode_t* head, int (*cmp)(void*, void*)) {
    if (!head || !head->next) return head;

    LinkedListNode_t* front = NULL;
    LinkedListNode_t* back = NULL;

    __ll_split(head, &front, &back);

    front = __ll_merge_sort(front, cmp);
    back = __ll_merge_sort(back, cmp);

    return __ll_merge(front, back, cmp);
}
