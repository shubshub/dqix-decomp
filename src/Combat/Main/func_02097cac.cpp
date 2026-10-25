#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/CopyRecord0200fbb4.h"

struct Struct_0208fa8c { unsigned short unknown_0_; unsigned short unknown_2_; };
struct Struct_02097cac {
    unsigned short unknown_0_;
    char unknown_2_[0x63];
    unsigned char unknown_65_;
};
struct Struct_02097cac_2 {
    char unknown_0_[0x1b3c];
    unsigned int unknown_1b3c_;
};

extern "C" void* func_0202ae18();
extern "C" ZoneState* Zone3D_GetInstance();
extern "C" int func_0202c508(void* obj);
extern "C" int func_0202c540(void* obj);
void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);
int IsIdInRange020981e4(int a, int id);
int IsIdInRange02098240(int a, int id);
int IsIdInSet02098210(int a, int id);
void UpdateRankLevel020989cc(Base020989cc* base);
void EnqueueEventTag186_021d3e3c(unsigned char tag);

#define FLAG130(obj) (*(int*)(*(void**)((char*)(obj) + 0x130)))

// USA: func_02097cac
extern "C" ARM void func_02097cac(Base020989cc* state) {
    void* search = func_0202ae18();
    GameState* gameState = GameState::GetInstance();
    ZoneState02097cac* zoneState = (ZoneState02097cac*)GetField0x3f8Address_0200fd0c(gameState);
    ZoneState* currentZone = Zone3D_GetInstance();
    int zoneId = zoneState->zoneId;
    GameObject* protagonist;
    int previousZoneId = currentZone->zoneId;

    if (!func_020981e4((int)arg0, var4) &&
        !func_020981e4((int)arg0, var6)) return;

    var5 = var1->GetProtagonist();

    if (func_02098210((int)arg0, var4) &&
        (!func_02098210((int)arg0, var6) || var2->unknown_65_ != 0)) {
        if (func_0202c508(var0) != 0 && (FLAG130(var5) & 1) == 0) {
            func_020989cc(arg0);
        }
        int var7 = arg0->unknown_1b3c_;
        func_ov017_021d3e3c(var7);
        switch (var7) {
            case 1:
            case 2: var2->unknown_0_ = 0xc3b5; break;
            case 3:
            case 4: var2->unknown_0_ = 0xc419; break;
            case 5: var2->unknown_0_ = 0xc47d; break;
            case 6: var2->unknown_0_ = 0xc4e1; break;
        }
        func_0200fcfc(var1, var2);
    } else {
        if (func_0202c540(var0) == 0 || var2->unknown_65_ == 0) return;
        int var8 = arg0->unknown_1b3c_;
        if (!func_020981e4((int)arg0, var4)) return;
        if (func_02098240((int)arg0, var4)) return;
        if (var4 == 0xc3bb) return;
        if (var4 == 0xc3bc) return;
        if (var4 == 0xc3bd) return;
        if (var4 == 0xc3be) return;
        int var9 = var2->unknown_0_ % 100;
        int var10 = var9 + 0xc350;
        switch (var8) {
            case 1:
            case 2: var2->unknown_0_ = (unsigned short)(var10 + 0x64); break;
            case 3:
            case 4: var2->unknown_0_ = (unsigned short)(var10 + 0xc8); break;
            case 5: var2->unknown_0_ = (unsigned short)(var10 + 0x12c); break;
            case 6: var2->unknown_0_ = (unsigned short)(var10 + 0x190); break;
        }
    }
}
