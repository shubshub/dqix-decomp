#include <globaldefs.h>

extern "C" void func_ov023_021db110(void* obj);

struct Struct_ov002_02156178;
typedef void (Struct_ov002_02156178::*Type_ov002_02156178)();
extern Type_ov002_02156178 __ptmf_null;

struct Struct_ov023_021ff9e0_5 {
#if defined(jpn)
unsigned char pad[0x18];
#else
unsigned char pad[0x1c];
#endif
unsigned int flags; };
extern struct Struct_ov023_021ff9e0_5 data_ov023_021ff9e0;

#if defined(jpn)
#define data_ov023_021fda60 data_ov023_021fcd24
#define data_ov023_021fda88 data_ov023_021fcd4c
#endif

struct Struct_ov023_021fda60 { unsigned char pad[0x40]; Type_ov002_02156178 handler; };
extern struct Struct_ov023_021fda60 data_ov023_021fda60;

extern unsigned char data_ov023_021ffa0c;

struct Struct_ov023_021fda88 { unsigned int fn; unsigned int unknown_4_; };
extern struct Struct_ov023_021fda88 data_ov023_021fda88[];

// USA: func_ov023_021dc488
extern "C" ARM int func_ov023_021dc488(void* obj) {
    func_ov023_021db110(&data_ov023_021ffa0c);
    if (!(data_ov023_021ff9e0.flags & 1)) {
        data_ov023_021fda60.handler = __ptmf_null;
        data_ov023_021ff9e0.flags |= 1;
    }
    unsigned char idx = *((unsigned char*)obj
#if defined(jpn)
 + 0x6f2
#else
 + 0x776
#endif
);
    if (data_ov023_021fda88[idx].fn == 0) return 1;
    struct Struct_ov023_021fda88* d = &data_ov023_021fda88[idx];
    void* base = (char*)obj + ((int)d->unknown_4_ >> 1);
    void* callback;
    if (d->unknown_4_ & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    ((void(*)(void*))callback)(base);
    return 0;
}
