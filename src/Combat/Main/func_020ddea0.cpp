#include <globaldefs.h>

struct Struct_020de0ec;
extern "C" void func_020de0ec(struct Struct_020de0ec* obj);

struct Struct_020ddea0_2;
extern "C" void func_020ddfb4(struct Struct_020ddea0_2* obj);

extern "C" int fix32_Divide(unsigned int arg0, unsigned int arg1);

extern "C" void* OamManager_GetInstance(void);
extern "C" void* OamManager_GetSubOamBuffer(void* obj);
extern "C" void* OamManager_GetMainOamBuffer(void* obj);

struct Struct_020ddea0 {
    unsigned short field0;
    unsigned short field2;
    unsigned char state;
    unsigned char pad5[3];
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
};

struct Elem8_020ddea0 {
    unsigned int word0;
    unsigned short unknown_4_;
    short half6;
};

// USA: func_020ddea0
extern "C" ARM void func_020ddea0(Struct_020ddea0* obj, unsigned short threshold, unsigned int idx, unsigned int arg3, unsigned char flag1, unsigned char flag2) {
    if (obj->state == 0) {
        if (obj->field2 <= threshold) return;
        if (threshold < obj->field0) return;
        obj->state = 2;
        func_020de0ec((struct Struct_020de0ec*)obj);
        return;
    }

    if (threshold >= obj->field2) {
        obj->state = 4;
    }
    func_020ddfb4((struct Struct_020ddea0_2*)obj);

    void* p1 = OamManager_GetInstance();
    Elem8_020ddea0* arr = (Elem8_020ddea0*)OamManager_GetSubOamBuffer(p1);
    if (flag1 == 0) {
        arr = (Elem8_020ddea0*)OamManager_GetMainOamBuffer(p1);
    }

    unsigned int var2 = obj->field8 + obj->field10;
    int var3 = obj->fieldc + obj->field14;
    int var4 = obj->field18;
    if (obj->field18 <= 1) {
        var4 = 0xa;
        var3 = 0xc0;
        var2 = 0x100;
    }

    int var5 = fix32_Divide(0x1000, var4);

    arr[idx].word0 = (var3 & 0xff) | ((idx >> 2) << 0x19) | 0x40000000 | ((var2 << 0x17) >> 7) | 0x300;
    arr[idx].unknown_4_ = arg3 | (flag2 << 0xc);
    Elem8_020ddea0* e = (Elem8_020ddea0*)((char*)arr + idx * 8);
    e->unknown_4_ &= ~0xc00;
    e->half6 = (short)(var5 >> 4);
    *(unsigned short*)((char*)e + 0xe) = 0;
    *(unsigned short*)((char*)e + 0x16) = 0;
    *(short*)((char*)e + 0x1e) = (short)(var5 >> 4);
}
