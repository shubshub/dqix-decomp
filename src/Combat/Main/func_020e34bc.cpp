#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);

extern "C" int LinkSession_IsActive(int* obj);

struct Struct_0208ab34_2 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};
extern "C" struct Struct_0208ab34_2* func_020e3054(struct Struct_0208ab34_2* list, int key);

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Struct_0208ab34 {
    struct Struct_0208ab34_2 entries[8];
    unsigned char flags[8];
};

#pragma optimize_for_size off
// USA: func_020e34bc
extern "C" ARM int func_020e34bc(struct Struct_0208ab34* obj, int key) {
    unsigned char* p;
    int i;
    void* cur;
    struct Struct_0208ab34_2* entry;
    signed char val;

    cur = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)cur)) return 1;

    i = 0;
    for (p = obj->flags; i < 8; p++) {
        if (*p == key) return 2;
        i++;
    }

    entry = func_020e3054(obj->entries, key);
    if (entry != NULL) {
        val = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)cur);
        if (entry->f0 == val) return entry->f2;
        return 3;
    }
    return 0;
}
