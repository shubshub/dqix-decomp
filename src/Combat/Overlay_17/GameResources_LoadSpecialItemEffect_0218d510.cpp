#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" unsigned short* Zone3D_GetInstance(void);
int IsIdInRange020981e4(int a, int id);
struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);
void ResetTask020dbebc(void* a);
struct Struct020dbd9c;
void InitStruct020dbd9c(struct Struct020dbd9c* p);
struct BattleTask020dbf18;
int BeginTask020dbf18(struct BattleTask020dbf18* task, int name, int alloc, int tables, int count);

extern const char data_ov017_021d7383[];

struct Struct_ov017_0218d510 {
#if defined(jpn)
    unsigned char unknown_0_[0x27c];
#else
    unsigned char unknown1_0_[0x2cc];
#endif
#if defined(jpn)
    unsigned char unknown_2cc_[0x41e8 - 0x27c];
#else
    unsigned char unknown_2cc_[0x4498 - 0x2cc];
#endif
    struct Struct_020dbf18* unknown_4498_;
};

static inline struct Struct_0203d028* inline_ov017_0218d510(unsigned char* arg0, int arg1) {
    return (struct Struct_0203d028*)(arg1 ? arg0 + 0x930 : arg0 + 0xc40);
}

// Overlay 17, originally func_ov017_0218d510 (USA/EUR 0x0218d510, JPN 0x0218e0f0)
extern "C" ARM int GameResources_LoadSpecialItemEffect(struct BattleResources0218d510* self, SafeAllocator* alloc) {
#if defined(jpn)
 enum {Enum_ov017_0218d510_1056=0x430};
#else
 enum {Enum_ov017_0218d510_1056=0x420};
#endif
    if (arg1 == NULL) {
        return -1;
    }
    unsigned short* run = Zone3D_GetInstance();
    int inRange = IsIdInRange020981e4((int)(run + regionalOffset0), *run);
    struct Foo0207df50* table = SelectPairTable(self->pairTables, inRange);
    VramState_Rewind(table);
    if (self->task != NULL) {
        ResetTask020dbebc(self->task);
    }
    struct Struct_020dbf18* var3 = arg0->unknown_4498_ = (struct Struct_020dbf18*)arg1->Allocate(0x18);
    func_020dbd9c((struct Struct_020dbd9c*)var3);
    func_020dbf18(var3, (int)data_ov017_021d7383, (int)arg1, (int)var2, 0x17);
    return 0;
}
