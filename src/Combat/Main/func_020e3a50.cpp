#include <globaldefs.h>

struct TagValueEntry020e385c {
    unsigned int val;
    unsigned char tag;
};
struct Struct_020e3a50 {
    unsigned int val;
    unsigned char tag;
    unsigned char unknown_5_;
    unsigned char flags6;
};

extern "C" struct TagValueEntry020e385c* func_020e385c(struct TagValueEntry020e385c* entries, int tag, int val);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void*);
extern "C" void func_ov017_021cebcc(int, int, int);

// USA: func_020e3a50
extern "C" ARM void func_020e3a50(struct TagValueEntry020e385c* table, int bit, int tag, int val) {
    if (LinkSession_IsGuest(LinkSession_GetInstance())) {
        func_ov017_021cebcc(1, tag & 0xff, val);
        return;
    }
    struct Struct_020e3a50* entry = (struct Struct_020e3a50*)func_020e385c(table, tag, val);
    if (entry == NULL) return;
    if (!(entry->unknown_5_ & (1 << bit))) return;
    entry->flags6 |= (1 << bit);
    func_ov017_021cebcc(3, tag & 0xff, val);
}
