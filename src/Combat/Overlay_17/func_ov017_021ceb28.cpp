#include <globaldefs.h>

extern "C" void* func_020e2ff8(void);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_020e321c(void*, int, int);
extern "C" void func_020e33b4(void*, int, int);

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Struct_0208ab34_2 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};
extern "C" struct Struct_0208ab34_2* func_020e3054(struct Struct_0208ab34_2* list, int key);

struct Struct_ov017_021ceb28 {
    unsigned char pad0[4];
    unsigned char field4;
    unsigned char field5;
    unsigned char pad1;
    unsigned char unknown_7_;
};

// USA: func_ov017_021ceb28
extern "C" ARM void func_ov017_021ceb28(int count, struct Struct_ov017_021ceb28* evt, int arg2, int arg3, struct SearchStruct0202c1a4* extra) {
    void* obj = func_020e2ff8();
    int inBattle = LinkSession_IsHostOrSolo(extra);
    if (inBattle != 0 && count > 0) {
        if (evt->field4 != 0) {
            func_020e321c(obj, evt->field5, evt->unknown_7_);
        } else {
            func_020e33b4(obj, evt->field5, evt->unknown_7_);
        }
        return;
    }
    if (count != 0) return;
    signed char val = LinkSession_GetOwnSlot(extra);
    if (evt->unknown_7_ != val) return;
    struct Struct_0208ab34_2* entry = func_020e3054((struct Struct_0208ab34_2*)obj, evt->field5);
    if (entry == NULL) return;
    if (evt->field4 != 0) {
        entry->f2 = 1;
    } else {
        entry->f2 = 3;
    }
}
