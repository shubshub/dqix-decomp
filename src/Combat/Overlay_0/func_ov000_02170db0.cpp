#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
#define data_ov000_02183ff4 data_ov000_02185118
#endif

struct Struct_ov000_02170db0_2 {
    #if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int field94c;
};

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" struct Struct_ov000_02170db0_2* func_02053c6c(unsigned char* obj);

struct Obj0203c108 {
    #if defined(jpn)
    char pad0[0x2c];
#else
    char pad0[0x10];
#endif
    int dirty;
    short idx;
};
extern "C" void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);

extern "C" void __clear(void* buf, int count);

struct Struct_ov000_02170db0_3 {
    char pad0[4];
    struct Container020e0310* container;
    char pad8[0x1c - 0x8];
    signed char kind;
    char unknown_1d_[0x26 - 0x1d];
    unsigned short unknown_26_;
    char pad28[0x2c - 0x28];
    short itemId;
    char unknown_2e_[0x4c - 0x2e];
    int combatantId;
    struct Obj0203c108 label;
};

struct Struct_ov000_02170cf8 {
    void* text;
};

struct Struct_ov000_02170db0 {
    char pad0[4];
    void* text;
    char pad8[0x18 - 0x8];
    short count;
};

extern "C" struct Struct_ov000_02170cf8* func_ov000_02170cf8(struct Struct_ov000_02170db0_3* obj, int val);
extern "C" struct Struct_ov000_02170db0* func_ov000_02171d90(struct Struct_ov000_02170db0_3* obj, int itemId);
extern "C" int func_ov000_021719f8(int* obj);
#if defined(jpn)
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170db0_3* obj);
#else
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170db0_3* obj, char* buf);
#endif
extern "C" void func_020e4864(void* src, char* dst, int a, int b, int c, int d);
extern "C" void func_0206819c(const char* src, char* dst, int flag);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_FormatText(int messages, int mode, char* input, char* output, int size, int a, int b);
extern "C" void func_ov000_0217616c(struct Struct_ov000_02170db0_3* obj);

extern char data_ov000_02183ff4[];

// USA: func_ov000_02170db0
extern "C" ARM void func_ov000_02170db0(struct Struct_ov000_02170db0_3* obj) {
    struct Struct_ov000_02170cf8* entry = func_ov000_02170cf8(obj, obj->unknown_26_);
    struct Struct_ov000_02170db0* equip = func_ov000_02171d90(obj, obj->itemId);
    GameObject* c = func_0200ff1c(GameState::GetInstance(), obj->combatantId);
    if (c == NULL) {
        return;
    }
    struct Struct_ov000_02170db0_2* ext = func_02053c6c((unsigned char*)c);
    obj->label.dirty = 1;
    if (func_ov000_021719f8((int*)obj)) {
#if defined(jpn)
        char* text = (char*)KeyTable_Get(obj->container, func_ov000_02171a74(obj));
        if (text != NULL) {
            CachedTextLabel_SetText(&obj->label, text);
        }
#else
        char buf[0x80];
        __clear(buf, sizeof(buf));
        if (func_ov000_02171a74(obj, buf) >= 0) {
            CachedTextLabel_SetText(&obj->label, buf);
        }
#endif
    } else if (ext != NULL && (signed char)ext->field94c != 5 && obj->kind != 6) {
        char* text = (char*)KeyTable_Get(obj->container, (short)((signed char)ext->field94c + 0x753e));
        if (text != NULL) {
            CachedTextLabel_SetText(&obj->label, text);
        } else {
            CachedTextLabel_SetText(&obj->label, data_ov000_02183ff4);
        }
    } else if (entry != NULL) {
#if defined(jpn)
        CachedTextLabel_SetText(&obj->label, (char*)entry->text);
#else
        char raw[0x80];
        char name[0x80];
        __clear(raw, sizeof(raw));
        __clear(name, sizeof(name));
        func_020e4864(entry->text, raw, 1, 0, 0, 0);
        func_0206819c(raw, name, 0);
        CachedTextLabel_SetText(&obj->label, name);
#endif
    } else if (equip != NULL) {
        if (equip->count > 0) {
#if defined(jpn)
            CachedTextLabel_SetText(&obj->label, (char*)equip->text);
#else
            char raw[0x80];
            char name[0x80];
            __clear(raw, sizeof(raw));
            __clear(name, sizeof(name));
            func_020e4864(equip->text, raw, 1, 0, 0, 0);
            func_0206819c(raw, name, 0);
            MessageSystem_FormatText(MessageSystem_GetInstance(), 10, name, raw, 0x100, 0, 0);
            CachedTextLabel_SetText(&obj->label, raw);
#endif
        }
    } else if (obj->kind == 6) {
        CachedTextLabel_SetText(&obj->label, (char*)KeyTable_Get(obj->container, 0x7531));
    } else {
        CachedTextLabel_SetText(&obj->label, data_ov000_02183ff4);
    }
    func_ov000_0217616c(obj);
}
