#include <globaldefs.h>
#include "Resource/GameResources.h"

struct EffectParam020708c8;

int MessageSystem_GetInstance();
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
extern "C" void* func_020704fc(void);
void SetScaledEffectParam020708c8(struct EffectParam020708c8* obj, unsigned int value);
struct GameResources;
void SetBrightness(GameResources*, int, int);

#if defined(jpn)
enum { effectCounterOffset = 0x17ee };
#else
enum { effectCounterOffset = 0x19be };
#endif

// USA: func_ov001_02154da0  (semantic: ReinitCombatEffectsAndCounters_02154da0)
extern "C" ARM void func_ov001_02154da0() {
    char* obj = (char*)MessageSystem_GetInstance();
    MessageSystem_Reset(obj);
    MessageSystem_Stop(obj);
    *(unsigned char*)(obj + effectCounterOffset) = 0;
    SetScaledEffectParam020708c8((struct EffectParam020708c8*)func_020704fc(), 0);
    SetBrightness(GetGameResources(), -16, 0);
}
