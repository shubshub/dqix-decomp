#include <globaldefs.h>

struct TagValueEntry020e385c {
    unsigned int val;
    unsigned char tag;
};
struct Struct_020e3814 {
    int f0;
    unsigned char f4;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
};

extern "C" struct TagValueEntry020e385c* func_020e385c(struct TagValueEntry020e385c* entries, int tag, int val);
extern "C" void func_020e3840(struct Struct_020e3814* s);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_ov017_021cebcc(int, int, int);

// USA: func_020e3994
extern "C" ARM void func_020e3994(struct TagValueEntry020e385c* table, int tag, int val) {
    struct TagValueEntry020e385c* entry = func_020e385c(table, tag, val);
    if (entry == NULL) return;
    func_020e3840((struct Struct_020e3814*)entry);
    if (!LinkSession_IsHostOrSolo(LinkSession_GetInstance())) return;
    func_ov017_021cebcc(3, tag & 0xff, val);
}
