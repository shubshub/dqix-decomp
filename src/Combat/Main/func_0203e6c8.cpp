#include <globaldefs.h>

struct Struct_0203e6c8 {
    unsigned short* arr;      // 0x0
    unsigned short capacity;  // 0x4
    unsigned short count;     // 0x6
    unsigned short size;      // 0x8
    unsigned short mask;      // 0xa
};

// USA: func_0203e6c8
extern "C" ARM int func_0203e6c8(Struct_0203e6c8* s, unsigned int key) {
    unsigned int k;
    int pos, span;
    if (!(key & 0x8000)) return 0;
    pos = 0;
    span = s->size;
    k = (unsigned short)(key & s->mask);
    for (; span > 0; ) {
        int var3;
        span >>= 1;
        var3 = pos + span;
        if ((unsigned int)var3 < s->count) {
            unsigned short v = s->arr[var3];
            int c;
            if (k == v) c = 0;
            else if (k < v) c = -1;
            else c = 1;
            if (c == 0) return var3;
            if (c >= 0) pos += span;
        }
    }
    {
        unsigned short* p;
        unsigned int count = s->count;
        if (count >= s->capacity) return -1;
        p = &s->arr[count];
        while (count > (unsigned int)(pos + 1)) {
            *p = p[-1];
            p--;
            count--;
        }
        *p = k;
        s->count++;
        if (s->size < s->count) {
            volatile unsigned short* var8 = &s->size;
            *var8 = *var8 << 1;
        }
        return pos + 1;
    }
}
