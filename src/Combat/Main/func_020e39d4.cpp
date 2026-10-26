#include <globaldefs.h>

struct TagValueEntry020e385c {
    unsigned int val;
    unsigned char tag;
};
struct Struct_020e39d4 {
    unsigned int val;
    unsigned char tag;
    unsigned char field5;
    unsigned char field6;
};
struct SearchStruct;

extern "C" struct TagValueEntry020e385c* func_020e385c(struct TagValueEntry020e385c* entries, int tag, int val);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(struct SearchStruct* obj);
extern "C" void func_ov017_021cebcc(int, int, int);

// USA: func_020e39d4
extern "C" ARM void func_020e39d4(struct TagValueEntry020e385c* table, int bit, int tag, int val) {
    if (LinkSession_IsGuest((struct SearchStruct*)LinkSession_GetInstance())) {
        func_ov017_021cebcc(0, tag & 0xff, val);
        return;
    }
    struct Struct_020e39d4* entry = (struct Struct_020e39d4*)func_020e385c(table, tag, val);
    if (entry == NULL) return;
    if (entry->field5 != 0 && entry->field5 == entry->field6) return;
    entry->field5 |= (1 << bit);
}
