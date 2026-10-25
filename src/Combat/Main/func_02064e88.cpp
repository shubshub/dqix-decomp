#include <globaldefs.h>

#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_02064e88_2112 = 0x860 };
extern "C" char* strcpy(char*, const char*);
#else
enum { Enum_02064e88_2112 = 0x840 };
#endif

struct Struct_02064e88;

struct Struct_02064e88_2 {
    unsigned char unknown_0_[0xc];
    unsigned int unknown_c_0_ : 4;
    unsigned int unknown_c_4_ : 20;
    unsigned int unknown_f_0_ : 6;
    unsigned int unknown_f_6_ : 1;
    unsigned int unknown_f_7_ : 1;
    unsigned char unknown_10_[0x2e - 0x10];
    unsigned char unknown_2e_0_ : 1;
    unsigned char unknown_2e_1_ : 7;
    unsigned char unknown_2f_[0xe8 - 0x2f];
};

struct Struct_02064e88_3 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
#if defined(jpn)
    char unknown_4_[0xc];
#endif
    char unknown1_4_[0xc];
    struct Struct_02064e88_3* unknown_10_;
};

extern "C" unsigned short* Zone3D_GetInstance(void);
int GetTableValueMod100_02098284(int, int);
int LookupTable020982a4(int, int);
void ClearField0xcBits24To29(struct Elem020984b0*);
int CollectEntriesByType020984dc(struct Entry020984dc*, int, struct Entry020984dc**);
void* FindNodeByByteId_0206db20(void*, int);
extern "C" void __clear(void* buf, int size);
extern "C" void Font_DecodeText(struct Entry020984dc* entry, void* buf, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);

extern char data_020f0618[];
extern char data_020f061e[];
extern char data_020f0624[];
extern char data_020f062a[];
extern char data_020f0630[];
extern char data_020f0636[];
extern char data_020f063c[];
extern char data_020f0642[];
extern char data_020f0648[];
extern char data_020f064e[];
extern char data_020f0654[];
extern char data_020f065a[];
extern char data_020f0660[];
extern char data_020f0666[];
extern char data_020f066c[];
extern char data_020f0672[];
extern char data_020f0678[];
extern char data_020f067e[];
extern char data_020f0684[];
extern char data_020f068a[];
extern char data_020f0690[];
extern char data_020f0696[];
extern char data_020f069c[];
extern char data_020f06a2[];
extern char data_020f06a8[];
extern char data_020f06ae[];
extern char data_020f06b4[];
extern char data_020f06ba[];

// USA: func_02064e88
extern "C" ARM int func_02064e88(struct Struct_02064e88_3** arg0, void* arg1, SafeAllocator* arg2) {
    unsigned short* var0;
    int var1;
    int var2;
    int var3;
    int var4;
    int var5;
    struct Struct_02064e88_3* var6;
    struct Struct_02064e88_2* var7[10];
#if !defined(jpn)
    char var8[0x30];
#endif

    global = Zone3D_GetInstance();
    zone = *global;
    base = LookupTable020982a4((int)((char*)global + kResourceOffset),
                               GetTableValueMod100_02098284((int)((char*)global + kResourceOffset), zone));
    ClearField0xcBits24To29((struct Elem020984b0*)((char*)global + kResourceOffset));
    count = CollectEntriesByType020984dc((struct Entry020984dc*)((char*)global + kResourceOffset),
                                         GetTableValueMod100_02098284((int)((char*)global + kResourceOffset), zone), entries);
    for (i = 0; i < count; i++) {
        id = i + 1 + base;
        if (FindNodeByByteId_0206db20(nodeDb, id) == 0) {
            continue;
        }
        var6 = (struct Struct_02064e88_3*)arg2->Allocate(sizeof(Struct_02064e88_3));
        if (var6 == 0) {
            break;
        }
        var6->unknown_0_ = var5;
        var6->unknown_2_ = var7[var4]->unknown_f_6_ ? 4 : 0;
#if defined(jpn)
        strcpy(var6->unknown_4_, (const char*)var7[var4]);
#else
        __clear(buf, 0x30);
        Font_DecodeText(entries[i], buf, 1);
#endif
        if (var7[var4]->unknown_2e_0_ == 0) {
            switch (var7[var4]->unknown_c_0_) {
            case 0: sprintf(var6->unknown1_4_, data_020f0618); break;
            case 1: sprintf(var6->unknown1_4_, data_020f061e); break;
            case 2: sprintf(var6->unknown1_4_, data_020f0624); break;
            case 3: sprintf(var6->unknown1_4_, data_020f062a); break;
            case 4: sprintf(var6->unknown1_4_, data_020f0630); break;
            case 5: sprintf(var6->unknown1_4_, data_020f0636); break;
            case 6: sprintf(var6->unknown1_4_, data_020f063c); break;
            case 7: sprintf(var6->unknown1_4_, data_020f0642); break;
            case 8: sprintf(var6->unknown1_4_, data_020f0648); break;
            case 9: sprintf(var6->unknown1_4_, data_020f064e); break;
            case 10: sprintf(var6->unknown1_4_, data_020f0654); break;
            case 11: sprintf(var6->unknown1_4_, data_020f065a); break;
            case 12: sprintf(var6->unknown1_4_, data_020f0660); break;
            default: sprintf(var6->unknown1_4_, data_020f0666); break;
            }
        } else {
            switch (var7[var4]->unknown_c_0_) {
            case 0: sprintf(var6->unknown1_4_, data_020f066c); break;
            case 1: sprintf(var6->unknown1_4_, data_020f0672); break;
            case 2: sprintf(var6->unknown1_4_, data_020f0678); break;
            case 3: sprintf(var6->unknown1_4_, data_020f067e); break;
            case 4: sprintf(var6->unknown1_4_, data_020f0684); break;
            case 5: sprintf(var6->unknown1_4_, data_020f068a); break;
            case 6: sprintf(var6->unknown1_4_, data_020f0690); break;
            case 7: sprintf(var6->unknown1_4_, data_020f0696); break;
            case 8: sprintf(var6->unknown1_4_, data_020f069c); break;
            case 9: sprintf(var6->unknown1_4_, data_020f06a2); break;
            case 10: sprintf(var6->unknown1_4_, data_020f06a8); break;
            case 11: sprintf(var6->unknown1_4_, data_020f06ae); break;
            case 12: sprintf(var6->unknown1_4_, data_020f06b4); break;
            default: sprintf(var6->unknown1_4_, data_020f06ba); break;
            }
        }
        var6->unknown_3_ = var7[var4]->unknown_2e_0_ == 0 ? 0 : 2;
        var7[var4]->unknown_f_0_ = var5;
        var6->unknown_10_ = *arg0;
        *arg0 = var6;
    }
    return var3;
}
