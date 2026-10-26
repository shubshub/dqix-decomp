#include <globaldefs.h>

extern "C" int LinkSession_IsActive(int*);

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4*);

extern "C" int func_02076ccc(void*, int);

extern "C" void* LinkSession_GetInstance(void* obj);
extern "C" unsigned short func_02078e60(void* obj, char* out);

struct Struct_02078d84 {
    char pad1[0x138];
    unsigned char field138;
    char pad2[0x13];
    unsigned int unknown_14c_;
    char pad3[0x14];
    unsigned short unknown_164_;
};

// USA: func_02078d84
extern "C" ARM void func_02078d84(struct Struct_02078d84* obj) {
    void* s = LinkSession_GetInstance(obj);
    if (LinkSession_IsActive((int*)s) != 0) {
        if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)s) != 0) {
            return;
        }
    }
    if (obj->unknown_14c_ <= 0xbb8) {
        return;
    }
    char var1 = 0;
    switch (obj->field138) {
    case 0:
        func_02076ccc(obj, 1);
        return;
    case 1:
    case 3:
    case 4:
    case 5:
#if !defined(jpn)
        if (func_02076ccc(obj, 2) != 0) {
            return;
        }
        obj->unknown_164_ = func_02078e60(obj, &var1);
#endif
        func_02076ccc(obj, 2);
        return;
    case 2:
        obj->unknown_164_ = func_02078e60(obj, &var1);
        func_02076ccc(obj, 3);
        return;
    }
}
