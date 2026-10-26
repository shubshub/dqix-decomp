#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"

struct Struct_ov000_021676a8 {
    char pad0[0x8e20];
    int unknown_8e20_;
};

struct Struct_ov000_021676a8_2 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    Struct_ov000_021676a8* unknown_29c_;
};

extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
extern "C" int func_ov000_0215fc60(char* self);
extern "C" int func_020493a4(unsigned char* obj);
extern "C" void func_02049390(unsigned char* obj, unsigned char value);
extern "C" void func_02049bd4(unsigned char* obj, int* src);
extern "C" void func_02049c60(unsigned char* obj, int* src);

struct Struct_ov000_021830c0 { unsigned int v[3]; };
extern unsigned char data_ov000_02183108[][4];
extern struct Struct_ov000_021830c0 data_ov000_021830fc;
extern struct Struct_ov000_021830c0 data_ov000_021830c0;

static inline Struct_02048cf0 inline_02048e2c_2(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_ov000_021676a8
extern "C" ARM void func_ov000_021676a8(Struct_ov000_021676a8_2* obj) {
    GameState* battle = GameState::GetInstance();
    battle->GetResources();
    Struct_ov000_021676a8* var1 = obj->unknown_29c_;
    short ids[4];
    int count = func_ov000_0215e9fc(var1, ids, 4, 0);
    if (func_ov000_0215fc60((char*)var1) != 0) {
        count = 1;
    }
    int i;
    for (i = 0; i < count; i++) {
        GameObject* c = battle->GetCombatantByIndex(ids[i]);
        if (c != 0) {
            int cell = data_ov000_02183108[count - 1][i];
            if (func_020493a4((unsigned char*)c) != 0xff && obj->unknown_29c_->unknown_8e20_ != 0) {
                cell = func_020493a4((unsigned char*)c);
            }
            Struct_02048cf0 pos = inline_02048e2c_2(cell);
            struct Struct_ov000_021830c0 fields = data_ov000_021830fc;
            struct Struct_ov000_021830c0 field14 = data_ov000_021830c0;
            fields.v[0] = pos.x;
            fields.v[2] = pos.y;
            func_02049390((unsigned char*)c, (unsigned char)(cell & 0xff));
            func_02049bd4((unsigned char*)c, (int*)&fields);
            func_02049c60((unsigned char*)c, (int*)&field14);
        }
    }
}
