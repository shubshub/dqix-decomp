#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" int func_020981e4(int a, int id);
struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void func_020dbebc(void* a);
struct Struct_020dbd9c;
extern "C" void func_020dbd9c(struct Struct_020dbd9c* p);
struct Struct_020dbf18;
extern "C" int func_020dbf18(struct Struct_020dbf18* task, int name, int alloc, int tables, int count);

extern const char data_ov017_021d7383[];

struct BattleResources0218d510 {
#if defined(jpn)
    unsigned char pad0[0x27c];
#else
    unsigned char pad0[0x2cc];
#endif
#if defined(jpn)
    unsigned char pairTables[0x41e8 - 0x27c];
#else
    unsigned char pairTables[0x4498 - 0x2cc];
#endif
    struct Struct_020dbf18* task;
};

static inline struct Foo0207df50* inline_ov017_0218d510(unsigned char* pairTables, int inRange) {
    return (struct Foo0207df50*)(inRange ? pairTables + 0x930 : pairTables + 0xc40);
}

// Overlay 17, originally func_ov017_0218d510 (USA/EUR 0x0218d510, JPN 0x0218e0f0)
extern "C" ARM int GameResources_LoadSpecialItemEffect(struct BattleResources0218d510* self, SafeAllocator* alloc) {
#if defined(jpn)
 enum {regionalOffset0=0x430};
#else
 enum {regionalOffset0=0x420};
#endif
    if (alloc == NULL) {
        return -1;
    }
    unsigned short* run = Zone3D_GetInstance();
    int inRange = func_020981e4((int)(run + regionalOffset0), *run);
    struct Foo0207df50* table = inline_ov017_0218d510(self->pairTables, inRange);
    VramState_Rewind(table);
    if (self->task != NULL) {
        func_020dbebc(self->task);
    }
    struct Struct_020dbf18* task = self->task = (struct Struct_020dbf18*)alloc->Allocate(0x18);
    func_020dbd9c((struct Struct_020dbd9c*)task);
    func_020dbf18(task, (int)data_ov017_021d7383, (int)alloc, (int)table, 0x17);
    return 0;
}
