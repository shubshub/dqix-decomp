#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);
extern "C" void* func_ov023_021fad18(void* obj);
extern "C" int func_ov023_021f6c90(void* list, int arg1, int flag);
extern "C" void* func_ov023_021fa854(char* obj, unsigned int idx);
extern "C" ARM void func_ov023_021f6bec(void* obj, int arg1, unsigned int arg2, unsigned int count);

struct Struct_ov023_021fad84 {
    char pad0[4];
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned short f8;
    unsigned short fa;
    char unknown_c_[4];
    unsigned int f10;
    char unknown_14_[8];
    unsigned int f1c;
    unsigned short f20;
    unsigned short f22;
    unsigned short f24;
    unsigned short unknown_26_;
    unsigned int f28;
    unsigned int unknown_2c_;
    unsigned short unknown_30_;
    unsigned short unknown_32_;
    unsigned short f34;
    unsigned short unknown_36_;
    char unknown_38_;
    char unknown_39_;
#if defined(jpn)
    unsigned short unknown_3a_;
#else
    unsigned char unknown1_3a_;
    char unknown_3b_[1];
#endif

    unsigned short f3c;
    unsigned short unknown_3e_;
    unsigned short f40;
    unsigned short unknown_42_;
#if defined(jpn)
    int unknown_44_;
    int f46;
#else
    unsigned short unknown1_44_;
    unsigned short f46;
#endif

    unsigned short unknown1_48_;
    unsigned char unknown_4a_;
#if defined(jpn)

#else
    unsigned char unknown_4b_;
#endif

};

// USA: func_ov023_021fad84
extern "C" ARM int func_ov023_021fad84(struct Struct_ov023_021fad84* obj, void* ctx, int arg2, int arg3, int arg4, int arg5) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 1;
    obj->unknown_6_ = arg2;
    obj->f8 = arg3;
    obj->fa = 0;
    obj->f10 = 0;
    obj->f1c = 2;
    obj->f20 = arg4;
#if defined(jpn)
    obj->unknown_44_ = -1;
    obj->f46 = -1;
#else
    obj->unknown1_3a_ = 1;
    obj->unknown1_44_ = 0;
    obj->f46 = 0;
#endif


    void* list = func_ov011_021849c8(ctx);
    void* node = func_ov023_021f6880(list, obj->f20);
    if (node == NULL) {
        return 0;
    }

    void* p = func_ov023_021fad18(node);
    unsigned char b = *(unsigned char*)((char*)p + 0x50);
    *(unsigned short*)((char*)obj + 0x22) = arg5;
    void* entry = func_ov023_021fa854((char*)p, *(unsigned short*)((char*)obj + 0x22));
    unsigned short var5 = *(unsigned short*)entry;

    int r = func_ov023_021f6c90(list, b, var5);
    *(unsigned short*)((char*)obj + 0x24) = r;
    func_ov023_021f6bec(list, b, *(unsigned short*)((char*)obj + 0x24), var5);

    obj->unknown_26_ = 0;
    obj->f28 = 0;
    obj->unknown_2c_ = 0;
    obj->unknown_30_ = obj->unknown_32_ = obj->f34 = obj->unknown_36_ = 0;
    obj->unknown_38_ = -1;
    obj->unknown_39_ = -1;
#if defined(jpn)
    obj->unknown_3a_ = 0;
    obj->f3c = 0;
#else
    obj->f3c = 0;
#endif

    obj->unknown_3e_ = 0;
    obj->f40 = 0;
#if defined(jpn)

#else
    obj->unknown_42_ = 0;
#endif

    obj->unknown1_48_ = 0;
    obj->unknown_4a_ = 0;
#if defined(jpn)

#else
    obj->unknown_4b_ = 0;
#endif

    return 1;
}
