#include <globaldefs.h>

struct HeadNode020469f8 {
    char unk0[2];
    unsigned char inList;
    unsigned char unknown_3_;
    struct HeadNode020469f8* next;
};

struct HeadList020469f8 {
    struct HeadNode020469f8* head;
    struct HeadNode020469f8* tail;
};

// USA: func_020469f8
extern "C" ARM void func_020469f8(struct HeadList020469f8* list, struct HeadNode020469f8* node) {
    if (list->head != NULL && list->tail != NULL) {
        list->head->unknown_3_ = 0;
        node->next = list->head;
        list->head = node;
    } else {
        list->head = node;
        list->tail = node;
        node->next = NULL;
    }
    node->inList = 1;
}
