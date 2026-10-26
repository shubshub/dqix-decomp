#include <globaldefs.h>
#if defined(jpn)
extern "C" int func_02069430(void*, unsigned short);
extern "C" int func_02069444(void*, unsigned short);
extern "C" int func_020694a0(void*, unsigned short);
extern "C" void func_0206cb14(void*, int, unsigned short);
#endif

struct Struct_0204500c_4;
extern "C" void func_0206b198(struct Struct_0204500c_4* obj, unsigned short idx);
extern "C" ARM bool func_02044494(void* obj, void* src);
extern "C" int func_02044420(void* obj, void* src);

#if defined(jpn)
struct Struct_0206b104 {
 char pad0[0x18]; unsigned short* arr; int unknown_1c_; int unknown_20_; int unknown_24_;
 char pad28[0x10]; int count; int unknown_70_; union { int unknown_74_; int idx; }; int unknown_78_;
};
#else
struct Struct_0206b104 {
    char pad0[0x4c];
    unsigned short* arr;
    char unknown_50_[0x54 - 0x50];
    int unknown_54_;
    int unknown_58_;
    char unknown_5c_[0x6c - 0x5c];
    int count;
    int unknown_70_;
    int unknown_74_;
    int unknown_78_;
    char unknown_7c_[0x88 - 0x7c];
    int idx;
};

#endif
// USA: func_0206b104
extern "C" ARM void func_0206b104(struct Struct_0206b104* obj) {
#if defined(jpn)
    if ((obj->unknown_20_ == 0) | (obj->unknown_24_ == 0)) return;
#else
    if (obj->unknown_54_ == 0 || obj->unknown_58_ == 0) return;
#endif
    if (obj->count == 0) return;
    unsigned short* p;
    unsigned int i = obj->idx;
    for (; i < obj->count; i++) {
        p = obj->arr + i;
        #if defined(jpn)
        if (func_02069430(obj, *p)) {
#else
        if (func_02044494(obj, p)) {
#endif
            #if defined(jpn)
            i += func_02069444(obj, *p);
#else
            i += func_02044420(obj, p);
#endif
        } else {
#if defined(jpn)
            func_0206cb14(obj, 12, *p);
            func_0206cb14(obj, 6, *p);
#else
            func_0206b198((struct Struct_0204500c_4*)obj, *p);
#endif
        }
    }
    obj->count = 0;
    obj->unknown_70_ = 0;
    obj->unknown_74_ = 0;
    obj->unknown_78_ = 0;
}
