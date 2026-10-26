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
    char pad0[0x138];
    int unknown_138_[0xd];
    unsigned short levels[0xd];
    char unknown_186_[Enum_ov003_021592d8_2384 - 0x186];
    int vocation;
};

struct Struct_ov003_021592d8_2 {
    char pad0[4];
    short id;
#if defined(jpn)
    char pad6[0x134 - 6];
    char* name;
#endif
};

struct MessageWork021592d8 {
    char pad0[0x10];
    void* unknown_10_;
};

struct Struct_ov003_021592d8_4 {
    int unknown_0_;
    char pad4[0x54 - 4];
};

struct Struct_ov003_021592d8_5 {
    char data[0xc];
};

struct Container020e0310;
struct Obj02046574;
struct StoreStruct;

struct Struct_ov003_021592d8_6 {
    char pad0[0x64];
    char messages[0x18];
};

extern "C" struct MessageWork021592d8* MessageSystem_GetInstance();
extern "C" struct Struct_ov003_021592d8* func_02053c6c(unsigned char* obj);
extern "C" void func_02046380(void* obj);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
extern "C" void* ResourceScriptEntry_Init(void* obj);
extern "C" int ResourceScriptEntry_LoadLevel(void* output, void* resource, unsigned int size, int selection, int extra);
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" void MessageSystem_FormatText(void* messages, int a, const char* input, char* output, int b, int c, int d);

extern char data_ov003_0217fe18[];
extern unsigned char g_fileLoadBuffer[0x30000];

// USA: func_ov003_021592d8
extern "C" ARM void func_ov003_021592d8(struct Struct_ov003_021592d8_6* self, struct Struct_ov003_021592d8_2* combatant,
                                        char* out) {
    if (out == NULL || combatant == NULL) {
        return;
    }
    struct MessageWork021592d8* work = MessageSystem_GetInstance();
    struct Struct_ov003_021592d8* data = func_02053c6c((unsigned char*)combatant);
    int vocation = data->vocation;
    func_02046380(work);
#if defined(jpn)
    MessageSystem_SetStringArgument((struct Obj02046574*)work, 0, combatant->name);
#else
    struct Struct_ov003_021592d8_5 unit;
    NameText_InitFromPartyMember(&unit, combatant->id);
    work->unknown_10_ = &unit;
#endif
    int key;
    if (data->levels[vocation] == 99) {
        MessageSystem_SetStringArgument((struct Obj02046574*)work, 1,
                               (char*)KeyTable_Get((struct Container020e0310*)self->messages,
                                                            (short)(data->vocation + 0x1e)));
        key = 0x3fe;
    } else {
        char path[0x28];
        unsigned int size;
        sprintf(path, data_ov003_0217fe18, data->vocation);
        BackgroundLoader::AddLockGlobal();
        void* file = LoadFileIntoMemory(path, g_fileLoadBuffer, &size);
        struct Struct_ov003_021592d8_4 next;
        ResourceScriptEntry_Init(&next);
        if (file != NULL) {
            ResourceScriptEntry_LoadLevel(&next, file, size, data->levels[vocation] + 1, 0);
        }
        struct Struct_ov003_021592d8_4* entry = &next;
        int remaining = 0;
        if (entry != NULL) {
            remaining = entry->unknown_0_ - data->unknown_138_[vocation];
        }
        if (remaining > 0) {
            func_020465c0((struct StoreStruct*)work, 0, remaining);
            func_020465f0((unsigned char*)work, 0, 0);
            key = 0x3fd;
        } else {
            key = 0x3ff;
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
