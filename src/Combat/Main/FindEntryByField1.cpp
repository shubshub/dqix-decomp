#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);

struct Entry020e3054 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};

// USA: func_020e3054
ARM struct Entry020e3054* FindEntryByField1(struct Entry020e3054* list, int key) {
    int i;
    if (!LinkSession_IsActive((int*)LinkSession_GetInstance())) return NULL;
    for (i = 0; i < 8; i++) {
        if (list->f1 == key) return list;
        list++;
    }
    return NULL;
}
