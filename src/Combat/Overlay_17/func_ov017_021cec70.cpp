#include <globaldefs.h>

extern "C" void* func_020e3808(void);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_ov017_021cebcc(int, int, int);

struct TagValueEntry020e385c;
extern "C" void func_020e39d4(struct TagValueEntry020e385c* table, int bit, int tag, int val);
extern "C" void func_020e3a50(struct TagValueEntry020e385c* table, int bit, int tag, int val);
extern "C" void func_020e392c(struct TagValueEntry020e385c* table, int tag, int val);
extern "C" void func_020e3994(struct TagValueEntry020e385c* table, int tag, int val);

struct Struct_020e3b44 {
    unsigned int val;
    unsigned char tag;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char pad;
};
extern "C" void func_020e3b44(struct Struct_020e3b44* entries, int index, struct Struct_020e3b44 entry);

struct Struct_ov017_021cec70 {
    char pad0[4];
    unsigned char unknown_4_;
    signed char field5;
    char pad1[2];
    struct Struct_020e3b44 entry;
};

// USA: func_ov017_021cec70
extern "C" ARM void func_ov017_021cec70(int bit, struct Struct_ov017_021cec70* obj, int arg2, int arg3, void* arg4) {
    struct TagValueEntry020e385c* table = (struct TagValueEntry020e385c*)func_020e3808();
    int inBattle = LinkSession_IsHostOrSolo(arg4);
    int var2 = obj->unknown_4_;

    if (inBattle != 0) {
        switch (var2) {
        case 0:
            func_020e39d4(table, bit, obj->entry.tag, obj->entry.val);
            break;
        case 1:
            func_020e3a50(table, bit, obj->entry.tag, obj->entry.val);
            break;
        case 2:
            func_020e392c(table, obj->entry.tag, obj->entry.val);
            break;
        case 3:
            func_ov017_021cebcc(3, obj->entry.tag, obj->entry.val);
            break;
        }
    } else {
        if (var2 != 3) return;
        signed char idx = obj->field5;
        if (idx < 0) {
            func_020e3994(table, obj->entry.tag, obj->entry.val);
            return;
        }
        func_020e3b44((struct Struct_020e3b44*)table, idx, obj->entry);
    }
}
