#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

struct Struct_020e30a4 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};

// USA: func_020e30a4
extern "C" ARM struct Struct_020e30a4* func_020e30a4(struct Struct_020e30a4* list) {
    int i;
    if (!LinkSession_IsActive((int*)LinkSession_GetInstance())) return NULL;
    for (i = 0; i < 8; i++) {
        if (list->f2 == 0) return list;
        list++;
    }
    return NULL;
}
