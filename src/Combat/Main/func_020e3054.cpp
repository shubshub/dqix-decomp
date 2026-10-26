#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

struct Struct_0208ab34_2 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};

// USA: func_020e3054
extern "C" ARM struct Struct_0208ab34_2* func_020e3054(struct Struct_0208ab34_2* list, int key) {
    int i;
    if (!LinkSession_IsActive((int*)LinkSession_GetInstance())) return NULL;
    for (i = 0; i < 8; i++) {
        if (list->f1 == key) return list;
        list++;
    }
    return NULL;
}
