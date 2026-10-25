#include <globaldefs.h>

struct Struct_0201099c_3;

int IsField0x118Equal2_ov000_0217542c(void* obj);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_Append(char* dst, const char* src);
int FormatCombatLogSuffix02041dd0(char* buf, int index);
#if defined(jpn)
extern "C" void func_0203bdf4(char* arg0, int arg1);
#define func_0203c248 func_0203bdf4
#else
extern "C" void func_0203c248(char* arg0, int arg1);
#endif
int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" void __clear(void* buf, int n);

struct Struct_ov000_02179a70_3 {
    char unknown_0_[0x4c];
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x88 - 0x50];
    char unknown_68_[0x488 - 0x88];
#else
    char unknown1_50_[0x68 - 0x50];
    char unknown_68_[0x448 - 0x68];
#endif
};

extern "C" int func_ov000_02170c7c(struct Struct_ov000_02179a70_3* arg0);

struct Struct_ov000_02179a70 {
    char unknown_0_[0x74];
    signed char unknown_74_[4];
    signed char unknown_78_;
    char unknown_79_[0xb8 - 0x79];
    char unknown_b8_[0x958 - 0xb8];
    struct Struct_ov000_02179a70_3 unknown_958_[1];
};

struct Struct_ov000_02179a70_2 {
    char unknown_0_[0x21];
    signed char unknown_21_;
};

// USA: func_ov000_02179a70
extern "C" ARM void func_ov000_02179a70(struct Struct_ov000_02179a70* arg0, struct Struct_ov000_02179a70_2* arg1, int arg2, char* arg3) {
    if (arg1 == NULL) return;

    signed char var0 = arg1->unknown_21_;
    int var1 = 0;

    if (IsField0x118Equal2_ov000_0217542c(party)) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    struct Member02179a70* m;
    for (int i = 0; i < party->count; i++) {
        m = &party->members[party->order[i]];
        if (m->field_0x4c >= 0) {
            if (n != 0) {
                Text_Append(dst, (const char*)KeyTable_Get((struct Container020e0310*)party->strings, 0));
            }
            func_02041dd0(arg3, func_ov000_02170c7c(var2));
#if defined(jpn)
            char var4[0x20];
#else
            char var4[0x80];
#endif
            __clear(name, sizeof(name));
            InvokeGlobalEntry0203c248(m->name, (int)name);
            Text_AppendNTag(dst, n, name);
            n++;
        }
    }
}
