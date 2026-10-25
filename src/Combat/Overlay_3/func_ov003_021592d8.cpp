#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_021592d8_2384 = 0x8b8 };
extern "C" void func_020474a8(void*, int, const char*, char*);
#else
enum { Enum_ov003_021592d8_2384 = 0x950 };
#endif
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

struct Struct_ov003_021592d8 {
    char unknown_0_[0x138];
    int unknown_138_[0xd];
    unsigned short unknown_16c_[0xd];
    char unknown_186_[Enum_ov003_021592d8_2384 - 0x186];
    int unknown_950_;
};

struct Struct_ov003_021592d8_2 {
    char unknown_0_[4];
    short unknown_4_;
#if defined(jpn)
    char unknown_6_[0x134 - 6];
    char* unknown_134_;
#endif
};

struct Struct_ov003_021592d8_3 {
    char unknown_0_[0x10];
    void* unknown_10_;
};

struct Struct_ov003_021592d8_4 {
    int unknown_0_;
    char unknown_4_[0x54 - 4];
};

struct Struct_ov003_021592d8_5 {
    char unknown_0_[0xc];
};

struct Struct_0201099c_3;
struct Struct_02046574_2;
struct Struct_020465c0;

struct Struct_ov003_021592d8_6 {
    char unknown_0_[0x64];
    char unknown_64_[0x18];
};

struct MessageWork021592d8* MessageSystem_GetInstance();
struct VocationData021592d8* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void func_02046380(void* obj);
void NameText_InitFromPartyMember(void* obj, int combatantId);
int KeyTable_Get(struct Container020e0310* c, int key);
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
void* ResourceScriptEntry_Init(void* obj);
extern "C" int ResourceScriptEntry_LoadLevel(void* output, void* resource, unsigned int size, int selection, int extra);
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" void MessageSystem_FormatText(void* messages, int a, const char* input, char* output, int b, int c, int d);

extern char data_ov003_0217fe18[];
extern unsigned char g_fileLoadBuffer[0x30000];

// USA: func_ov003_021592d8
extern "C" ARM void func_ov003_021592d8(struct Struct_ov003_021592d8_6* arg0, struct Struct_ov003_021592d8_2* arg1,
                                        char* arg2) {
    if (arg2 == NULL || arg1 == NULL) {
        return;
    }
    struct MessageWork021592d8* work = MessageSystem_GetInstance();
    struct VocationData021592d8* data = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    int vocation = data->vocation;
    func_02046380(work);
#if defined(jpn)
    MessageSystem_SetStringArgument((struct Obj02046574*)work, 0, combatant->name);
#else
    struct UnitObj021592d8 unit;
    NameText_InitFromPartyMember(&unit, combatant->id);
    work->subject = &unit;
#endif
    int key;
    if (data->levels[vocation] == 99) {
        MessageSystem_SetStringArgument((struct Obj02046574*)work, 1,
                               (char*)KeyTable_Get((struct Container020e0310*)self->messages,
                                                            (short)(data->vocation + 0x1e)));
        key = 0x3fe;
    } else {
        char var5[0x28];
        unsigned int var6;
        sprintf(var5, data_ov003_0217fe18, var1->unknown_950_);
        BackgroundLoader::AddLockGlobal();
        void* file = LoadFileIntoMemory(path, g_fileLoadBuffer, &size);
        struct LevelEntry021592d8 next;
        ResourceScriptEntry_Init(&next);
        if (file != NULL) {
            ResourceScriptEntry_LoadLevel(&next, file, size, data->levels[vocation] + 1, 0);
        }
        struct Struct_ov003_021592d8_4* var9 = &var8;
        int var10 = 0;
        if (var9 != NULL) {
            var10 = var9->unknown_0_ - var1->unknown_138_[var2];
        }
        if (var10 > 0) {
            func_020465c0((struct Struct_020465c0*)var0, 0, var10);
            func_020465f0((unsigned char*)var0, 0, 0);
            var4 = 0x3fd;
        } else {
            var4 = 0x3ff;
        }
        BackgroundLoader::RemoveLockGlobal();
    }
#if defined(jpn)
    func_020474a8(work, 0xc, (const char*)KeyTable_Get((struct Container020e0310*)self->messages, key), out);
#else
    MessageSystem_FormatText(work, 0xc, (const char*)KeyTable_Get((struct Container020e0310*)self->messages, key), out,
                  0xe3, 0, 1);
#endif
}
