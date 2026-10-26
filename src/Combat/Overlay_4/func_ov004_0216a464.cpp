#include <globaldefs.h>
#if defined(jpn)
enum{Enum_ov004_0216a464_400=0x10,Enum_ov004_0216a464_2456=0x868};
#else
enum{Enum_ov004_0216a464_400=0x190,Enum_ov004_0216a464_2456=0x998};
#endif
#if defined(jpn)
#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov004_02168b08 func_ov004_02169040
#define func_ov023_021f65d4 func_ov004_02168eac
#endif

#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov023_021f6524(void* ctx, int value);
struct TableA68;
extern "C" TableA68* func_ov004_02168b08(void* a, int key);
extern "C" int MessageSystem_GetInstance(void);
extern "C" int func_ov023_021f9bc8(char* obj);
extern "C" void func_ov004_0216950c(void* obj);
extern "C" void func_ov004_0216920c(void* obj);
extern "C" void __clear(void* buf, int n);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" void func_02046380(void* global);
extern "C" void Font_DecodeText(void* a, void* b, int flag);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
#if defined(jpn)
extern "C" void func_0204500c(void*, void*, int);
#else
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);
#endif
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
struct Struct_ov004_02158dcc;
extern "C" void func_ov011_021849e0(struct Struct_ov004_02158dcc* obj, unsigned short val);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct TableA68 { struct Struct_02072a68* entries; short count; };
extern void* data_ov004_02171030;

struct Struct_ov004_0216a464 {
    unsigned char unknown_0_[6];
    char name[11];
    unsigned char unknown_11_;
    unsigned short unknown_12_0_ : 14;
    unsigned short used : 1;
    unsigned short unknown_13_7_ : 1;
    unsigned char unknown14[0x18];
};
struct Struct_ov004_0216a464_2 {
    unsigned char count;
    unsigned char unknown_1_[3];
    Struct_ov004_0216a464 entries[16];
};

// USA: func_ov004_0216a464
extern "C" ARM int func_ov004_0216a464(void* a) {
    if (!*(void**)((char*)data_ov004_02171030 + Enum_ov004_0216a464_400)) return 0;

    void* node = func_ov023_021f6524(a, 0x64);
    TableA68* var1 = func_ov004_02168b08(a, 3);
    int g = MessageSystem_GetInstance();
    func_ov023_021f9bc8((char*)node);
    func_ov004_0216950c(a);

    GameResources* resources = GetGameResources();
    node = resources->fieldTasks_[34];
    Struct_ov004_0216a464_2* table = *(Struct_ov004_0216a464_2**)((char*)data_ov004_02171030 + Enum_ov004_0216a464_400);

    Struct_ov004_0216a464* entry = table->entries;
    int idx;
    for (idx = 0; idx < 16; entry++, idx++) {
        if (!entry->used) {
            memcpy(entry, (char*)node + 0x28, sizeof(*entry));
            Struct_ov004_0216a464_2* var7 = *(Struct_ov004_0216a464_2**)((char*)data_ov004_02171030 + Enum_ov004_0216a464_400);
            ++var7->count;
            break;
        }
    }

    func_ov004_0216920c(a);

#if !defined(jpn)
    char buf[0x30];
    __clear(buf, 0x30);
#endif

    void* var9 = func_02072a68(var1, 0xd);
    func_02046380((void*)g);
#if defined(jpn)
    MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, (char*)node+0x2e);
    func_0204500c((void*)g, var9, 0);
#else
    Font_DecodeText((char*)node + 0x2e, buf, 1);
    MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, buf);
    func_0204500c((void*)g, var9, 0, 0xe3);
#endif
    *(int*)((char*)g + Enum_ov004_0216a464_2456) = 1;

    func_ov023_021f65d4(a, 0x1e, 8);
    func_ov023_021f65d4(a, 0x1f, 8);
    func_ov023_021f65d4(a, 2, 8);
    func_ov011_021849e0((struct Struct_ov004_02158dcc*)a, 0x66);
    func_ov011_021848a0(a, 0x68);
    return 0;
}
