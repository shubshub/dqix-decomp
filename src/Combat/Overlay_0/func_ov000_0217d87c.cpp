#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
extern "C" void* func_020e08f0(int index, unsigned int* size);
#endif

struct Struct_0205c570;
struct SePlayer;
struct Entry_0205d6a0;
struct Struct_0205d81c;
struct Struct_0205def8;
struct TableEntry0217f8c0;
struct Struct0217f8c0;

struct Struct_ov000_0217d674 {
    char pad0[0x10];
    unsigned char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x24 - 0x19];
    unsigned char flags;
#if defined(jpn)
    char unknown_25_[0xc7 - 0x25];
#else
    char unknown1_25_[0x87 - 0x25];
#endif
    unsigned char unknown_87_;
};

struct Struct_ov000_02178d28_2 {
    char pad0[0x26];
    char field26[0x66 - 0x26];
    short field66;
    char pad68[0x70 - 0x68];
    signed char members[0x17c - 0x70];
    int unknown_17c_;
    char unknown_180_[0x188 - 0x180];
    char elements[0x240 - 0x188];
    unsigned char mode;
    char unknown_241_[0x956 - 0x241];
    unsigned char unknown_956_;
#if defined(jpn)
    char unknown_957_[0x1f98 - 0x957];
#else
    char unknown1_957_[0x1d60 - 0x957];
#endif
    unsigned char unknown_1d60_[8];
    signed char depth;
    char unknown_1d69_[2];
    signed char selection;
    char unknown_1d6c_[2];
    signed char activeSum;
    unsigned char unknown_1d6f_;
    char unknown_1d70_[2];
    unsigned short flags;
};

extern struct SePlayer g_sePlayer;
extern const char* data_020f2a34;
extern const char* data_020f2a2c;

extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" struct TableEntry0217f8c0* func_ov000_0217f8c0(Struct0217f8c0*);
extern "C" int func_ov000_0217c5f4(void*);
extern "C" void func_ov000_0217a9d0(int, int, int, Struct_0205d81c*);
extern "C" void func_0205def8(Struct_0205def8*, int, int);
extern "C" int func_ov000_021719f8(int*);
extern "C" int func_ov000_0218158c(void* menu, int index);
extern "C" void ItemTable_Init(void* obj);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" int ItemTable_LoadIds(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
extern "C" int func_0207c984(void* party, int id, int bits, void* a, void* b);
extern "C" int func_ov000_0217c594(Struct_ov000_02178d28_2* menu, int limit);
extern "C" Struct_ov000_0217d674* func_ov000_02161318(Struct_ov000_02178d28_2* menu, int id);
extern "C" void func_ov000_02175258(Struct_ov000_02178d28_2* menu);
extern "C" void func_ov000_02176634(Struct_ov000_02178d28_2* menu, void* entry, int mode, int arg3, int arg4);
extern "C" void func_ov000_0217c638(Struct_ov000_02178d28_2* menu, int arg1, int arg2);

// USA: func_ov000_0217d87c
extern "C" ARM void func_ov000_0217d87c(Struct_ov000_02178d28_2* menu, int arg1, int arg2) {
    menu->flags |= 0x100;
    signed char prev = menu->activeSum;
    int sum = Window_GetSelectedIndex((Struct_0205c570*)menu->elements);
    menu->activeSum = sum;
    int id = menu->members[menu->selection];
    if (prev != sum) {
        return;
    }
    if (func_ov000_0217c594(menu, 5) != 0) {
        menu->unknown_956_ = 0;
        GameState* gs = GameState::GetInstance();
        unsigned char* party = (unsigned char*)GameState_GetParty(gs);
        int bits = func_ov000_0218158c(menu, menu->activeSum);
        if (func_0207c984(party + 0x1d4, id, bits & 0xff, menu->field26, &menu->field66) != 0) {
            return;
        }
        menu->mode = 6;
        SePlayer_Play(&g_sePlayer, 1, 0);
        BackgroundLoader::AddLockGlobal();
#if defined(jpn)
        ((SafeAllocator*)((char*)menu + 0x1bf8))->Reset();
#else
        ((SafeAllocator*)((char*)menu + 0x1af8))->Reset();
#endif
        ItemTable_Init((char*)menu + 0x100);
        unsigned int size;
#if defined(jpn)
        void* data = func_020e08f0(0, &size);
#else
        void* data = ExtractFileFromGP2(data_020f2a34, data_020f2a2c, &size);
#endif
        if (data != NULL) {
#if defined(jpn)
            ItemTable_LoadIds((char*)menu + 0x100, menu->field26 + 0x1bd2, data, size, menu->field26, menu->field66);
#else
            ItemTable_LoadIds((char*)menu + 0x100, menu->field26 + 0x1ad2, data, size, menu->field26, menu->field66);
#endif
        }
        BackgroundLoader::RemoveLockGlobal();
        menu->unknown_1d6f_ = 0;
        menu->depth = menu->depth + 1;
        menu->unknown_1d60_[menu->depth] = 7;
        func_ov000_02176634(menu, func_ov000_0217f8c0((Struct0217f8c0*)menu), 7, arg1, arg2);
        func_ov000_0217a9d0(7, menu->field66, 4, (Struct_0205d81c*)menu->elements);
    } else if (func_ov000_0217c5f4(menu) != 0) {
        menu->unknown_956_ = 0;
        Struct_ov000_0217d674* node = func_ov000_02161318(menu, id);
        if (node == NULL) {
            return;
        }
        if (func_ov000_021719f8((int*)node) != 0) {
            node->unknown_10_[node->unknown_18_] = 100;
            node->flags &= ~4;
        }
        GameState* gs = GameState::GetInstance();
        unsigned char count = ((unsigned char*)GameState_GetParty(gs))[0xf7c];
        for (unsigned char i = 0; i < count; i++) {
            int memberId = menu->members[i];
            Struct_ov000_0217d674* other = func_ov000_02161318(menu, memberId);
            if (other == NULL) {
                continue;
            }
            if (func_ov000_021719f8((int*)other) != 0) {
                continue;
            }
            if (other->unknown_87_ != 0) {
                menu->unknown_17c_ = memberId;
                break;
            }
        }
        func_ov000_02175258(menu);
        Window_ClosePane((Entry_0205d6a0*)menu->elements, 0);
        menu->unknown_1d60_[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        func_ov000_0217c638(menu, arg1, arg2);
        func_0205def8((Struct_0205def8*)menu->elements, 1, 1);
        func_0205def8((Struct_0205def8*)menu->elements, 1, 2);
        func_0205def8((Struct_0205def8*)menu->elements, 1, 5);
    }
}
