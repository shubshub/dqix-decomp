#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(struct Random* arg0, short* buf, int count, int flag);
extern "C" int func_020493a4(unsigned char* obj);
extern "C" void func_02049390(unsigned char* obj, unsigned char value);
extern "C" void func_02049bd4(unsigned char* obj, int* src);
extern "C" void func_02049c60(unsigned char* obj, int* src);
extern "C" void __clear(void* dst, int count);

struct Struct_02048cf0 { int x; int y; };
extern "C" struct Struct_02048cf0 func_ov000_0216f74c(int* in);

extern unsigned char data_ov000_02183118[][8];
struct Struct_ov000_021830cc { unsigned int v[3]; };
extern struct Struct_ov000_021830cc data_ov000_021830cc;

// USA: func_ov000_02167cd4
extern "C" ARM void func_ov000_02167cd4(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    battle->GetResources();
#if defined(jpn)
    struct Random* var1 = *(struct Random**)(obj + 0x218);
#else
    struct Random* var1 = *(struct Random**)(obj + 0x29c);
#endif
    short ids[8];
    int count = func_ov000_0215eb1c(var1, ids, 8, 0);
    int i = 0;
    while (i < count) {
        GameObject* c = battle->GetCombatantByIndex(ids[i]);
        if (c != 0) {
            int tmp = data_ov000_02183118[count - 1][i];
            if (func_020493a4((unsigned char*)c) != 0xff) {
                tmp = func_020493a4((unsigned char*)c);
            }
            struct Struct_02048cf0 pos = func_ov000_0216f74c(&tmp);
            struct Struct_ov000_021830cc fields = data_ov000_021830cc;
            fields.v[0] = pos.x;
            fields.v[2] = pos.y;
            int var9[3];
            __clear(var9, 0xc);
            func_02049390((unsigned char*)c, (unsigned char)(tmp & 0xff));
            func_02049bd4((unsigned char*)c, (int*)&fields);
            func_02049c60((unsigned char*)c, var9);
        }
        i++;
    }
}
