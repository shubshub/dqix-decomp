#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" float _ffltu(unsigned int v);
extern "C" float _fdiv(float a, float b);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float v);

// USA: func_ov002_02153be0
extern "C" ARM int func_ov002_02153be0(void* obj, unsigned char* req, int combatantId) {
    int result = 0;
    unsigned int kind = *(unsigned int*)(req + 0x18);
    if (((kind << 14) >> 30) == 1) {
        GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
        if (combatant == 0) {
            return 0;
        }

        if (*(unsigned int*)(req + 0x10) & 0x8000) {
            unsigned int var3 = *(unsigned int*)((char*)combatant->baseStats_ + 0x3c);
            unsigned int cap = (unsigned short)((var3 << 2) >> 22);
            unsigned int var5 = *(unsigned int*)(req + 4);

            if (cap <= ((var5 << 10) >> 22)) {
                unsigned int var6 = *(unsigned int*)(req + 0x14);
                result = (var6 << 18) >> 25;
            } else if (cap >= (var5 >> 22)) {
                unsigned int var7 = *(unsigned int*)(req + 0x14);
                result = (var7 << 11) >> 25;
            } else {
                unsigned int var8 = *(unsigned int*)(req + 0x14);
                int b0 = (var8 << 11) >> 25;
                int a0 = (var8 << 18) >> 25;
                float t = _fdiv(_ffltu(b0 - a0), _ffltu((var5 >> 22) - ((var5 << 10) >> 22)));
                result = _ffix(_fmul(t, _ffltu(cap - ((var5 << 10) >> 22)))) + a0;
            }
        }
    }
    return result;
}
