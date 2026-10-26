#if defined(jpn)
enum {regionalOffset0=0x568, regionalOffset1=0x120, regionalOffset2=0x11c, regionalOffset3=0x228, regionalOffset4=0x22c, regionalOffset5=0x230};
#else
enum {regionalOffset0=0x630, regionalOffset1=0x124, regionalOffset2=0x120, regionalOffset3=0x2d8, regionalOffset4=0x2dc, regionalOffset5=0x2e0};
#endif
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4*, unsigned int);
extern "C" void func_ov005_02154198(void*);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_02017d68(void* obj);
extern "C" void CharacterModel_Destroy(void* obj);
extern "C" void SpriteContext_Destroy(void* obj);
extern "C" int MessageSystem_GetInstance(void);
struct CombatSlots02045cac;
extern "C" void MessageSystem_ResetGlyphs(struct CombatSlots02045cac*);
extern "C" void MessageSystem_Reset(char*);
extern "C" void MessageSystem_Stop(int);

// USA: func_ov023_021e2f38
extern "C" ARM void func_ov023_021e2f38(void* obj) {
    char* o = (char*)obj;

    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0xf);

    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(o + regionalOffset0) > 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(o + regionalOffset0)));
        *(int*)(o + regionalOffset0) = -1;
    }

    FontBankLoader* g = FontBankLoader_GetInstance();
    func_02094b40(g);
    FontBankLoader_CancelLoads(g);

    if (*(void**)(o + 0x0) != 0) {
        func_ov005_02154198(*(void**)(o + 0x0));
        *(void**)(o + 0x0) = 0;
        func_02017d68(Zone3D_GetInstance());
    }

    CharacterModel_Destroy(*(void**)(o + regionalOffset1));
    if (*(void**)(o + regionalOffset2) != 0) {
        CharacterModel_Destroy(*(void**)(o + regionalOffset2));
    }
    if (*(void**)(o + 0xc8) != 0) {
        SpriteContext_Destroy(*(void**)(o + 0xc8));
    }

    ((SafeAllocator*)(o + 0x90))->Destroy();
    ((SafeAllocator*)(o + 0x7c))->Destroy();
    ((SafeAllocator*)(o + 0x68))->Destroy();
    ((SafeAllocator*)(o + 0x54))->Destroy();
    ((SafeAllocator*)(o + 0x40))->Destroy();
    ((SafeAllocator*)(o + 0x2c))->Destroy();

    *(int*)(o + 0xc0) = 0;
    *(int*)(o + 0xc4) = 0;

    int gg = MessageSystem_GetInstance();
    MessageSystem_ResetGlyphs((struct CombatSlots02045cac*)gg);
    MessageSystem_Reset((char*)gg);
    MessageSystem_Stop(gg);

    *(int*)((char*)gg + regionalOffset3) = 0;
    *(int*)((char*)gg + regionalOffset4) = 0;
    *(int*)((char*)gg + regionalOffset5) = 0;
}
