#include <globaldefs.h>

extern "C" int func_0209c0f4(int value, int type);
extern "C" void SoundPlayer_UnloadAll(void* obj);
extern "C" int SoundPlayer_SaveHeapState(void* obj);
extern "C" void* func_020bc068(void* obj, int);
extern "C" void SoundPlayer_RestoreHeapState(void* obj, int arg1);
extern "C" int SoundPlayer_LoadSeq(void* obj, void* arg1, int* out);
struct Obj0203aba8;
extern "C" int SoundPlayer_StartSeq(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void func_0209c2e0(void* obj, int a, int b);

struct Struct_0209c480 {
    char pad0[0xb0];
    int state;
    int field_b4;
    short field_b8;
    short field_ba;
    void* fieldBC;
    void* fieldC0;
    void* fieldC4;
    unsigned char unknown_c8_;
    unsigned char unknown_c9_;
    short unknown_ca_;
    unsigned char field_cc;
    unsigned char unknown_cd_;
    short field_ce;
};

// USA: func_0209c480
extern "C" ARM void func_0209c480(struct Struct_0209c480* obj, int arg1) {
    if (obj->state == 2) return;
    obj->state = 2;
    if (func_0209c0f4(obj->field_b8, arg1)) {
        SoundPlayer_UnloadAll(obj);
        obj->field_b4 = SoundPlayer_SaveHeapState(obj);
    } else {
        func_020bc068(&obj->fieldBC, 1);
        if (obj->field_b4 > 0) {
            SoundPlayer_RestoreHeapState(obj, obj->field_b4);
        }
    }
    if (arg1 >= 0) {
        SoundPlayer_LoadSeq(obj, (void*)arg1, 0);
        SoundPlayer_StartSeq((struct Obj0203aba8*)obj, (void*)arg1, &obj->fieldC0);
        func_0209c2e0(obj, obj->unknown_cd_, 0);
        obj->field_ba = (short)arg1;
    }
    obj->field_ce = -1;
}
