#include <globaldefs.h>

void* GetData02153660_020e3808(void);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_ov017_021cebcc(int, int, int);

struct Struct_020e385c;
extern "C" void func_020e39d4(struct Struct_020e385c* arg0, int arg1, int arg2, int arg3);
extern "C" void func_020e3a50(struct Struct_020e385c* arg0, int arg1, int arg2, int arg3);
extern "C" void func_020e392c(struct Struct_020e385c* arg0, int arg1, int arg2);
extern "C" void func_020e3994(struct Struct_020e385c* arg0, int arg1, int arg2);

struct Struct_020e3b44 {
    unsigned int unknown_0_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
};
extern "C" void func_020e3b44(struct Struct_020e3b44* arg0, int arg1, struct Struct_020e3b44 arg2);

struct Struct_ov017_021cec70 {
    char unknown_0_[4];
    unsigned char unknown_4_;
    signed char unknown_5_;
    char unknown_6_[2];
    struct Struct_020e3b44 unknown_8_;
};

// USA: func_ov017_021cec70
extern "C" ARM void func_ov017_021cec70(int bit, struct Obj021cec70* obj, int unused2, int unused3, void* arg4) {
    struct TagValueEntry020e385c* table = (struct TagValueEntry020e385c*)GetData02153660_020e3808();
    int inBattle = LinkSession_IsHostOrSolo(arg4);
    int caseSel = obj->caseSel;

    if (var1 != 0) {
        switch (var2) {
        case 0:
            func_020e39d4(var0, arg0, arg1->unknown_8_.unknown_4_, arg1->unknown_8_.unknown_0_);
            break;
        case 1:
            func_020e3a50(var0, arg0, arg1->unknown_8_.unknown_4_, arg1->unknown_8_.unknown_0_);
            break;
        case 2:
            func_020e392c(var0, arg1->unknown_8_.unknown_4_, arg1->unknown_8_.unknown_0_);
            break;
        case 3:
            func_ov017_021cebcc(3, arg1->unknown_8_.unknown_4_, arg1->unknown_8_.unknown_0_);
            break;
        }
    } else {
        if (var2 != 3) return;
        signed char var3 = arg1->unknown_5_;
        if (var3 < 0) {
            func_020e3994(var0, arg1->unknown_8_.unknown_4_, arg1->unknown_8_.unknown_0_);
            return;
        }
        func_020e3b44((struct Struct_020e3b44*)var0, var3, arg1->unknown_8_);
    }
}
