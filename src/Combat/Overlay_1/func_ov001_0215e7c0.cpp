#include <globaldefs.h>
#include "Graphics/Background.h"
#include "Filesystem/BackgroundLoader.h"
#include "Combat/MapDisplay.h"

extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void Background_SetMapSize(unsigned char* obj, int value);

extern "C" void Background_SetPriority(void*, int);

extern "C" int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);

extern "C" void WindowPane_Init(void*);

struct Struct_0204fbf8_2 {
    char pad0[0x4];
    struct BackgroundGraphics* field4;
    void* field8;
    char pad1[0xa0 - 0xc];
    int unknown_a0_;
    int unknown_a4_;
    short unknown_a8_;
    short unknown_aa_;
    char pad2[0xb4 - 0xac];
    short fieldB4;
    short fieldB6;
    char pad3[0xc4 - 0xb8];
    unsigned char fieldC4;
    unsigned char unknown_c5_;
    char pad4[0xe0 - 0xc6];
};
extern "C" void func_0204fbf8(struct Struct_0204fbf8_2* obj);

extern int g_fileLoadBuffer;

extern "C" int func_ov017_021d60f4(void*);

struct Struct_ov001_02153884 { int key; int val; };
struct Struct_ov001_021658d8 { struct Struct_ov001_02153884* pairs; int count; };
extern "C" void* func_ov001_02153884(struct Struct_ov001_021658d8* t, int key);
extern struct Struct_ov001_021658d8 data_ov001_021658d8;

extern "C" void func_0204f160(unsigned char* obj, int value, int b);

#if defined(jpn)
extern "C" void func_02050678(void* obj, short b, int c, void* field18, int nibble, int arg5, short* arg6, short* arg7);
#else
extern "C" void func_0204f41c(void* obj, short b, int c, void* field18, int nibble, int arg5, short* arg6, short* arg7, int zero);
#endif

// USA: func_ov001_0215e7c0
extern "C" ARM int func_ov001_0215e7c0(void* combatant) {
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    struct BackgroundGraphics list;
    Background_Init(&list);
    list.subScreen_ = 1;
    list.bgNumber_ = 0;
    Background_SetMapSize((unsigned char*)&list, 0);
    Background_SetPriority(&list, 0);
    Background_SetScroll((struct BackgroundGraphics*)&list, 0, 0);

    struct Struct_0204fbf8_2 obj;
    WindowPane_Init(&obj);
    obj.field4 = &list;
    obj.field8 = &g_fileLoadBuffer;
    obj.unknown_a8_ = 0x20;
    obj.unknown_aa_ = 0x18;
    obj.unknown_a4_ = 0x6000;
    obj.fieldB4 = 0xc;
    obj.fieldB6 = 0x10;
    unsigned char var2 = obj.unknown_c5_;
    obj.unknown_a0_ = 0x60;
    obj.unknown_c5_ = var2 | 0x10;

    int key = func_ov017_021d60f4(combatant);
    struct Struct_ov001_02153884* entry = (struct Struct_ov001_02153884*)func_ov001_02153884(&data_ov001_021658d8, key);
    if (entry == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }

    func_0204f160((unsigned char*)&obj, 0x60, 0);

    short fieldA;
    short fieldC;
#if defined(jpn)
    func_02050678(&obj, 0, 0, (void*)entry->val, 0xc, 0xf, &fieldA, &fieldC);
#else
    func_0204f41c(&obj, 0, 0, (void*)entry->val, 0xc, 0xf, &fieldA, &fieldC, 0);
#endif

    func_0204fbf8(&obj);
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
