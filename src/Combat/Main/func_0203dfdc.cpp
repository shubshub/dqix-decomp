#include <globaldefs.h>
extern "C" unsigned short* func_02040528(int*);

struct Struct_0203dfdc { char pad0[0xc]; void* items[0x20]; };

// USA: func_0203dfdc
extern "C" ARM int func_0203dfdc(void* base, int key) {
    int i;
    for (i = 0; i < 0x20; i++) {
        void* p = ((struct Struct_0203dfdc*)base)->items[i];
        if (p == NULL) continue;
        if (*(int*)p & 0x8000) continue;
        {
            unsigned short* q = func_02040528((int*)(p));
            if (q == NULL) continue;
            if (*q == key) return i;
        }
    }
    return -1;
}
