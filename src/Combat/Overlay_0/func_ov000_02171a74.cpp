#include <globaldefs.h>

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
void NameText_Clear(void* buf);
void NameText_InitFromPartyMember(void* obj, int combatantId);
void* MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* g);
extern "C" void MessageSystem_FormatText(void* a, int b, int c, void* d, int e, int f, int g);

struct Struct_ov000_02171a74 {
    char unknown_0_[4];
    void* unknown_4_;
    char unknown_8_[0x28 - 8];
    int unknown_28_;
    char unknown_2c_[0x4c - 0x2c];
    int unknown_4c_;
};

// USA: func_ov000_02171a74
extern "C" ARM int func_ov000_02171a74(struct Struct_ov000_02171a74* arg0
#if !defined(jpn)
    , int arg1
#endif
) {
#if !defined(jpn)
    if (arg0->unknown_4_ == 0) {
        return -1;
    }
#endif
    int var0 = arg0->unknown_28_;
    int var1 = -1;
    if (var0 & 1) {
        var1 = 4;
    } else if (var0 & 8) {
        var1 = 2;
    } else if (var0 & 0x10) {
        var1 = 3;
    } else if (var0 & 0x80000) {
        var1 = 0x26;
    }
#if !defined(jpn)
    if (var1 < 0) {
        goto end;
    }
    {
        int val = KeyTable_Get((struct Container020e0310*)obj->field4, key);
        if (val == 0) {
            goto end;
        }
        char buf[0xc];
        NameText_Clear(buf);
        NameText_InitFromPartyMember(buf, obj->field4c);
        void* g = MessageSystem_GetInstance();
        func_02046380(g);
        *(void**)g = buf;
        MessageSystem_FormatText(g, 0xa, val, (void*)param, 0x100, 0, 0);
    }
end:
#endif
    return var1;
}
