#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4*);

struct Struct_0208ab34_2 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};

struct Struct_020e30f0 {
    char pad[0xfc0];
    int busy;
};

extern "C" Struct_0208ab34_2* func_020e3054(Struct_0208ab34_2* list, int key);
extern "C" void func_020e3428(void* a, int b);
extern "C" void func_020e3328(void* a, int b);

// USA: func_020e30f0
extern "C" ARM void func_020e30f0(Struct_0208ab34_2* list) {
    void* ctx = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)ctx)) return;

    Struct_0208ab34_2* e = list;
    int i;
    for (i = 0; i < 8; i++, e++) {
        if (e->f2 == 2 && ((Struct_020e30f0*)ctx)->busy == 0) {
            if (e->f3 <= 0x1e) {
                e->f3 = e->f3 + 1;
            } else {
                unsigned char owner = e->f0;
                unsigned char key = e->f1;
                func_020e3428(list, key);
                e->f1 = key;
                e->f0 = owner;
                e->f2 = 4;
            }
        }
    }

    unsigned char* ids = (unsigned char*)list + 0x20;
    int j;
    for (j = 0; j < 8; j++, ids++) {
        int id = *ids;
        if (id == 0) continue;
        Struct_0208ab34_2* found = func_020e3054(list, id);
        if (found != NULL) {
            unsigned char state = found->f2;
            int cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)ctx);
            if (found->f0 != cur && state == 1) state = 3;
            if (state == 1 || state == 4 || state == 5) {
                *ids = 0;
            } else if (state != 2) {
                func_020e3328(list, id);
            }
        } else {
            func_020e3328(list, id);
        }
    }
}
