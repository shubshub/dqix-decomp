#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
extern "C" void* func_020e08f0(int arg0, unsigned int* arg1);
#endif

struct Struct_0205c570;
struct SePlayer;
struct Entry_0205d6a0;
struct Struct_0205d81c;
struct Struct_0205def8;
struct Struct_ov000_021735d0_2;
struct Struct_ov000_021735d0_3;

struct Struct_ov000_0217d674 {
    char unknown_0_[0x10];
    unsigned char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x24 - 0x19];
    unsigned char unknown_24_;
#if defined(jpn)
    char unknown_25_[0xc7 - 0x25];
#else
    char unknown1_25_[0x87 - 0x25];
#endif
    unsigned char unknown_87_;
};

struct Struct_ov000_02178d28_2 {
    char unknown_0_[0x26];
    char unknown_26_[0x66 - 0x26];
    short unknown_66_;
    char unknown_68_[0x70 - 0x68];
    signed char unknown_70_[0x17c - 0x70];
    int unknown_17c_;
    char unknown_180_[0x188 - 0x180];
    char unknown_188_[0x240 - 0x188];
    unsigned char unknown_240_;
    char unknown_241_[0x956 - 0x241];
    unsigned char unknown_956_;
#if defined(jpn)
    char unknown_957_[0x1f98 - 0x957];
#else
    char unknown1_957_[0x1d60 - 0x957];
#endif
    unsigned char unknown_1d60_[8];
    signed char unknown_1d68_;
    char unknown_1d69_[2];
    signed char unknown_1d6b_;
    char unknown_1d6c_[2];
    signed char unknown_1d6e_;
    unsigned char unknown_1d6f_;
    char unknown_1d70_[2];
    unsigned short unknown_1d72_;
};

extern struct SePlayer g_sePlayer;
extern const char* data_020f2a34;
extern const char* data_020f2a2c;

int GetActiveScaledSum0205d794(Struct_0205c570*);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
int CheckFlagsOrField_0217c5f4_0217c5f4(void*);
void SetElementStateIfLess0217a9d0(int, int, int, Struct_0205d81c*);
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
int HasAnyFlags_021719f8_021719f8(int*);
int GetNthSetBit0218158c(void* menu, int index);
void ZeroInit020de848(void* obj);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020de9a4(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
extern "C" int func_0207c984(void* party, int id, int bits, void* a, void* b);
extern "C" int func_ov000_0217c594(MenuState* menu, int limit);
extern "C" ElemNode* func_ov000_02161318(MenuState* menu, int id);
extern "C" void func_ov000_02175258(MenuState* menu);
extern "C" void func_ov000_02176634(MenuState* menu, void* entry, int mode, int arg1, int arg2);
extern "C" void func_ov000_0217c638(MenuState* menu, int arg1, int arg2);

// USA: func_ov000_0217d87c
extern "C" ARM void func_ov000_0217d87c(Struct_ov000_02178d28_2* arg0, int arg1, int arg2) {
    arg0->unknown_1d72_ |= 0x100;
    signed char var0 = arg0->unknown_1d6e_;
    int var1 = func_0205d794((Struct_0205c570*)arg0->unknown_188_);
    arg0->unknown_1d6e_ = var1;
    int var2 = arg0->unknown_70_[arg0->unknown_1d6b_];
    if (var0 != var1) {
        return;
    }
    if (func_ov000_0217c594(arg0, 5) != 0) {
        arg0->unknown_956_ = 0;
        GameState* var3 = GameState::GetInstance();
        unsigned char* var4 = (unsigned char*)func_02010828(var3);
        int var5 = func_ov000_0218158c(arg0, arg0->unknown_1d6e_);
        if (func_0207c984(var4 + 0x1d4, var2, var5 & 0xff, arg0->unknown_26_, &arg0->unknown_66_) != 0) {
            return;
        }
        menu->mode = 6;
        SePlayer_Play(&g_sePlayer, 1, 0);
        BackgroundLoader::AddLockGlobal();
#if defined(jpn)
        ((SafeAllocator*)((char*)arg0 + 0x1bf8))->Reset();
#else
        ((SafeAllocator*)((char*)arg0 + 0x1af8))->Reset();
#endif
        func_020de848((char*)arg0 + 0x100);
        unsigned int var6;
#if defined(jpn)
        void* var7 = func_020e08f0(0, &var6);
#else
        void* var7 = ExtractFileFromGP2(data_020f2a34, data_020f2a2c, &var6);
#endif
        if (var7 != NULL) {
#if defined(jpn)
            func_020de9a4((char*)arg0 + 0x100, arg0->unknown_26_ + 0x1bd2, var7, var6, arg0->unknown_26_, arg0->unknown_66_);
#else
            func_020de9a4((char*)arg0 + 0x100, arg0->unknown_26_ + 0x1ad2, var7, var6, arg0->unknown_26_, arg0->unknown_66_);
#endif
        }
        BackgroundLoader::RemoveLockGlobal();
        arg0->unknown_1d6f_ = 0;
        arg0->unknown_1d68_ = arg0->unknown_1d68_ + 1;
        arg0->unknown_1d60_[arg0->unknown_1d68_] = 7;
        func_ov000_02176634(arg0, func_ov000_0217f8c0((Struct_ov000_021735d0_3*)arg0), 7, arg1, arg2);
        func_ov000_0217a9d0(7, arg0->unknown_66_, 4, (Struct_0205d81c*)arg0->unknown_188_);
    } else if (func_ov000_0217c5f4(arg0) != 0) {
        arg0->unknown_956_ = 0;
        Struct_ov000_0217d674* var8 = func_ov000_02161318(arg0, var2);
        if (var8 == NULL) {
            return;
        }
        if (func_ov000_021719f8((int*)var8) != 0) {
            var8->unknown_10_[var8->unknown_18_] = 100;
            var8->unknown_24_ &= ~4;
        }
        GameState* var9 = GameState::GetInstance();
        unsigned char var10 = ((unsigned char*)func_02010828(var9))[0xf7c];
        for (unsigned char var11 = 0; var11 < var10; var11++) {
            int var12 = arg0->unknown_70_[var11];
            Struct_ov000_0217d674* var13 = func_ov000_02161318(arg0, var12);
            if (var13 == NULL) {
                continue;
            }
            if (func_ov000_021719f8((int*)var13) != 0) {
                continue;
            }
            if (var13->unknown_87_ != 0) {
                arg0->unknown_17c_ = var12;
                break;
            }
        }
        func_ov000_02175258(arg0);
        func_0205d6a0((Struct_0205d6a0*)arg0->unknown_188_, 0);
        arg0->unknown_1d60_[arg0->unknown_1d68_] = 0;
        arg0->unknown_1d68_ = arg0->unknown_1d68_ - 1;
        func_ov000_0217c638(arg0, arg1, arg2);
        func_0205def8((Struct_0205def8*)arg0->unknown_188_, 1, 1);
        func_0205def8((Struct_0205def8*)arg0->unknown_188_, 1, 2);
        func_0205def8((Struct_0205def8*)arg0->unknown_188_, 1, 5);
    }
}
