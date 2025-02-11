#include "ll.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

LinkedListNode_t* ll_new_node(void* data) {
    LinkedListNode_t* node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

    if (!node) {
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void ll_free(LinkedListNode_t* head, void (*dellocator)(void*)) {
    if (!head || !dellocator) {
        return;
    }

    LinkedListNode_t* curr = head;
    while (curr) {
        LinkedListNode_t* temp = curr;
        curr = curr->next;

        dellocator(temp->data);
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

LinkedListNode_t* ll_copy(LinkedListNode_t* head, void* (*copy_data)(void*)) {
    if (!head || !copy_data) {
        return NULL;
    }

    LinkedListNode_t* new_head = NULL;
    LinkedListNode_t* new_tail = NULL;
    LinkedListNode_t* curr = head;

    while (curr) {
        LinkedListNode_t* new_node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

        if (!new_node) {
            return NULL;
        }

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

LinkedListNode_t* ll_from_array(void** array, size_t length, void* (*copy_data)(void*)) {
    if (!array || length == 0 || !copy_data) {
        return NULL;
    }

    LinkedListNode_t* head = NULL;
    LinkedListNode_t* tail = NULL;

    for (size_t i = 0; i < length; i++) {
        LinkedListNode_t* new_node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

        if (!new_node) {
            return NULL;
        }

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
    if (!head || !out_length) {
        return NULL;
    }

    size_t length = 0;
    LinkedListNode_t* curr = head;

    while (curr) {
        length++;
        curr = curr->next;
    }

    void** array = (void**)malloc(length * sizeof(void*));

    if (!array) {
        return NULL;
    }

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

    if (!cmp) {
        return index;
    }

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

LinkedListNode_t* ll_tail(LinkedListNode_t* node) {
    if (!node) {
        return NULL;
    }

    while (node->next) {
        node = node->next;
    }

    return node;
}

LinkedListNode_t* ll_insert_head(LinkedListNode_t* head, void* data) {
    LinkedListNode_t* node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

    if (!node) {
        return NULL;
    }

    node->data = data;
    node->next = head;

    return node;
}

LinkedListNode_t* ll_insert_tail(LinkedListNode_t* head, void* data) {
    if (!head) {
        return ll_new_node(data);
    }

    LinkedListNode_t* node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

    if (!node) {
        return NULL;
    }

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
    if (index == 0) {
        return ll_insert_head(head, data);
    }

    LinkedListNode_t* curr = head;
    size_t curr_index = 0;

    while (curr && curr_index < index - 1) {
        curr = curr->next;
        curr_index++;
    }

    if (!curr) {
        return NULL;
    }

    LinkedListNode_t* node = (LinkedListNode_t*)malloc(sizeof(LinkedListNode_t));

    if (!node) {
        return NULL;
    }

    node->data = data;
    node->next = curr->next;
    curr->next = node;

    return head;
}

LinkedListNode_t* ll_insert_ll_index(LinkedListNode_t* head, LinkedListNode_t* new_list, size_t index) {
    if (!new_list) {
        return head;
    }

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

    if (!curr) {
        return head;
    }

    LinkedListNode_t* last = new_list;
    while (last->next) {
        last = last->next;
    }

    last->next = curr->next;
    curr->next = new_list;

    return head;
}

LinkedListNode_t* ll_append(LinkedListNode_t* head, LinkedListNode_t* new_list) {
    if (!head) {
        return new_list;
    }
    if (!new_list) {
        return head;
    }

    LinkedListNode_t* curr = head;

    while (curr->next) {
        curr = curr->next;
    }

    curr->next = new_list;

    return head;
}

LinkedListNode_t* ll_remove_index(LinkedListNode_t* head, size_t index, void (*dellocator)(void*)) {
    if (!head || !dellocator) {
        return head;
    }

    if (index == 0) {
        LinkedListNode_t* temp = head;
        head = head->next;
        dellocator(temp->data);
        free(temp);
        return head;
    }

    LinkedListNode_t* curr = head;
    size_t curr_index = 0;

    while (curr->next && curr_index < index - 1) {
        curr = curr->next;
        curr_index++;
    }

    if (!curr->next) {
        return head;
    }

    LinkedListNode_t* temp = curr->next;
    curr->next = temp->next;
    dellocator(temp->data);
    free(temp);

    return head;
}

LinkedListNode_t* ll_remove_range(LinkedListNode_t* head, size_t start, size_t end, void (*dellocator)(void*)) {
    if (!head || start > end || !dellocator) {
        return head;
    }

    LinkedListNode_t* curr = head;
    LinkedListNode_t* prev = NULL;
    size_t curr_index = 0;

    while (curr && curr_index < start) {
        prev = curr;
        curr = curr->next;
        curr_index++;
    }

    if (!curr) {
        return head;
    }

    LinkedListNode_t* range_start = prev;

    while (curr && curr_index <= end) {
        LinkedListNode_t* temp = curr;
        curr = curr->next;
        dellocator(temp->data);
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

LinkedListNode_t* ll_delete(LinkedListNode_t* head, void* target, int (*cmp)(void*, void*), void (*dellocator)(void*)) {
    if (!head || !cmp || !dellocator) {
        return head;
    }

    LinkedListNode_t* curr = head;
    LinkedListNode_t* prev = NULL;

    while (curr) {
        if (cmp(curr->data, target) == 0) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }

            dellocator(curr->data);
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}
