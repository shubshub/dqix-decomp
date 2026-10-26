#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"

extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);
extern "C" int func_020493a4(unsigned char* obj);
extern "C" void func_02049bd4(unsigned char* obj, int* src);

struct Struct_ov000_021830f0 { unsigned int v[3]; };
extern struct Struct_ov000_021830f0 data_ov000_021830f0;

static inline Struct_02048cf0 inline_02048e2c_2(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_ov000_02168144
extern "C" ARM void func_ov000_02168144(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    short ids[12];
#if defined(jpn)
    enum { Enum_ov000_02168144_668 = 0x218 };
#else
    enum { Enum_ov000_02168144_668 = 0x29c };
#endif
    int count = func_ov000_02153e40(*(void**)(obj + Enum_ov000_02168144_668), ids, 0xc, 0);
    int i;
    for (i = 0; i < count; i++) {
        GameObject* c = battle->GetCombatantByIndex(ids[i]);
        if (c != 0) {
            Struct_02048cf0 pos = inline_02048e2c_2(func_020493a4((unsigned char*)c));
            struct Struct_ov000_021830f0 fields = data_ov000_021830f0;
            fields.v[0] = pos.x;
            fields.v[2] = pos.y;
            func_02049bd4((unsigned char*)c, (int*)&fields);
        }
    }
}
