#include <globaldefs.h>
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_0206cc50(void*, unsigned short*);
extern "C" int func_02069408(void*, unsigned short);
extern "C" int func_020694a0(void*, unsigned short);

// JPN: func_0206cdcc
extern "C" ARM void func_0206cdcc(void* context, int* outA, int* outB) {
    MessageSystem* self = static_cast<MessageSystem*>(context);
    unsigned short* buffer = static_cast<unsigned short*>(self->unknown_1c_);
    int start = self->unknown1_40_;
    int limit = self->unknown_78_;
    int center;
    int line;
    unsigned short* cursor = buffer + start;
    unsigned short* end = buffer + limit;
    center = self->unknown_860_;
    line = 0;
    outA[line] = center - (func_0206cc50(self, cursor) >> 1);
    outB[line] = 0;
    cursor++;
    line++;
    while (cursor != end) {
        if (func_02069408(self, *cursor)) return;
        if (func_020694a0(self, *cursor)) {
            cursor++;
            outA[line] = center - (func_0206cc50(self, cursor) >> 1);
            outB[line] = 0;
            line++;
        }
        cursor++;
    }
}
#else

extern "C" int func_0206b37c(void* obj, void* p);
extern "C" int func_0206ac6c(void* obj, void* p);
extern "C" bool func_02067a9c(void* obj, void* p);
extern "C" int func_02067ad8(int unused, void* p);
extern "C" int func_0206abf8(void* a, void* p);

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unknown_5_6_ : 2;
    char pad6[2];
};

extern "C" struct Entry0204254c* Font_FindCharacter(int key, int tableIdx);

// USA: func_0206b528
extern "C" ARM int func_0206b528(unsigned char* obj, int* outA, int* outB) {
    unsigned char* buf = *(unsigned char**)(obj + 0x50);
    int start = *(int*)(obj + 0x84);
    int base = *(int*)(obj + 0x990);
    int i;
    unsigned char* p = buf + start;

    outA[0] = base - (func_0206b37c(obj, p) >> 1);
    outB[0] = 0;
    i = 1;

    for (;;) {
        signed char c = *(signed char*)p;
        if (c == 0) return c;
        if (func_0206ac6c(obj, p)) {
            bool var6 = func_02067a9c(obj, p);
            if (var6) return var6;
            if (func_02067ad8((int)obj, p)) {
                p += 2;
                outA[i] = base - (func_0206b37c(obj, p) >> 1);
                outB[i] = 0;
                i++;
            } else {
                p = (p + 2) + func_0206abf8(obj, p) * 2;
                goto again;
            }
        } else {
            int var7 = 1;
            struct Entry0204254c* e = Font_FindCharacter((int)p, (obj + 0x1000)[0x9dc]);
            if (e) var7 = e->field5;
            p += var7;
        }
    again: ;
    }
}

#endif
