#include <globaldefs.h>

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void NameText_Clear(void* buf);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" void* MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* g);
extern "C" void MessageSystem_FormatText(void* a, int b, int c, void* d, int e, int f, int g);

struct Struct_ov000_02171a74 {
    char pad0[4];
    void* field4;
    char pad1[0x28 - 8];
    int field28;
    char pad2[0x4c - 0x2c];
    int field4c;
};

// USA: func_ov000_02171a74
extern "C" ARM int func_ov000_02171a74(struct Struct_ov000_02171a74* obj
#if !defined(jpn)
    , int param
#endif
) {
#if !defined(jpn)
    if (obj->field4 == 0) {
        return -1;
    }
#endif
    int flags = obj->field28;
    int key = -1;
    if (flags & 1) {
        key = 4;
    } else if (flags & 8) {
        key = 2;
    } else if (flags & 0x10) {
        key = 3;
    } else if (flags & 0x80000) {
        key = 0x26;
    }
#if !defined(jpn)
    if (key < 0) {
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
    return key;
}
