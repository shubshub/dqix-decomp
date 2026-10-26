#include <globaldefs.h>

int IsMissingFromTable0209c0f4(int value, int type);
void SoundPlayer_UnloadAll(void* obj);
int SoundPlayer_SaveHeapState(void* obj);
void* CallFunc020bc594OnField0_020bc068(void* obj, int);
void SoundPlayer_RestoreHeapState(void* obj, int arg2);
int SoundPlayer_LoadSeq(void* obj, void* arg1, int* out);
struct Obj0203aba8;
int SoundPlayer_StartSeq(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void func_0209c2e0(void* obj, int a, int b);

struct Actor0209c480 {
    char pad0[0xb0];
    int state;
    int field_b4;
    short field_b8;
    short field_ba;
    void* fieldBC;
    void* fieldC0;
    void* fieldC4;
    unsigned char field_c8;
    unsigned char field_c9;
    short field_ca;
    unsigned char field_cc;
    unsigned char field_cd;
    short field_ce;
};

// USA: func_0209c480  (semantic: SetStateAndDispatch0209c480)
extern "C" ARM void func_0209c480(struct Actor0209c480* obj, int arg1) {
    if (obj->state == 2) return;
    obj->state = 2;
    if (IsMissingFromTable0209c0f4(obj->field_b8, arg1)) {
        SoundPlayer_UnloadAll(obj);
        obj->field_b4 = SoundPlayer_SaveHeapState(obj);
    } else {
        CallFunc020bc594OnField0_020bc068(&obj->fieldBC, 1);
        if (obj->field_b4 > 0) {
            SoundPlayer_RestoreHeapState(obj, obj->field_b4);
        }
    }
    if (arg1 >= 0) {
        SoundPlayer_LoadSeq(obj, (void*)arg1, 0);
        SoundPlayer_StartSeq((struct Obj0203aba8*)obj, (void*)arg1, &obj->fieldC0);
        func_0209c2e0(obj, obj->field_cd, 0);
        obj->field_ba = (short)arg1;
    }
    obj->field_ce = -1;
}
