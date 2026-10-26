#include <globaldefs.h>

struct Node02046a3c {
    char unk0[2];
    unsigned char inList;
    char unknown_3_;
    struct Node02046a3c* next;
};

struct List02046a3c {
    struct Node02046a3c* head;
    struct Node02046a3c* tail;
};

// USA: func_02046a3c
extern "C" ARM void func_02046a3c(struct List02046a3c* list, struct Node02046a3c* node) {
    if (list->head != NULL && list->tail != NULL) {
        node->next = list->head->next;
        list->head->next = node;
        if (node->next == NULL)
            list->tail = node;
    } else {
        list->head = node;
        list->tail = node;
        node->next = NULL;
    }
    node->inList = 1;
}
