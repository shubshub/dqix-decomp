#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_020696bc(int p1, int* out, int count);
int MessageSystem_GetInstance(void);

struct Ctx02069a4c { void* dst; };

struct Table02069a4c {
    char pad0[0x194e];
    signed char slotA[4];
    signed char slotB[4];
    signed char counter;
};

// USA: func_02069a4c
ARM int WriteHistoryEntry02069a4c(struct Ctx02069a4c* ctx, int p1) {
    int buf[3];
    struct Table02069a4c* t;
    int a, b;

    func_020696bc(p1, &buf[1], 2);

    t = (struct Table02069a4c*)MessageSystem_GetInstance();
    b = buf[2];

    t->counter = t->counter % 4;
    a = buf[1];
    t->slotA[t->counter] = (signed char)a;
    t->slotB[t->counter] = (signed char)b;
    t->counter = t->counter + 1;

    {
        void* d = ctx->dst;
        *(unsigned short*)&buf[0] = 0xff1c;
        memcpy(d, &buf[0], 2);
    }

    return 2;
}
