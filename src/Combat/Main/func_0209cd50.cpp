#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0209cd50_10120 = 0x27c8, Enum_0209cd50_10118 = 0x27c6 };
#else
enum { Enum_0209cd50_10120 = 0x2788, Enum_0209cd50_10118 = 0x2786 };
#endif

#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* GameState_GetZoneTable(void* obj);
extern "C" int _s32_div_f(int a, int b);
struct SearchTable;
struct SearchEntry;
extern "C" struct SearchEntry* ZoneTable_FindEntry(struct SearchTable* table, int key);
extern "C" int func_0209caf0(int id);
extern "C" int func_0209cc3c(void* obj, int id);

extern int data_02109be0;

struct Struct_0209cd50 {
    char pad[0xd];
    unsigned char unknown_d_0_ : 7;
    unsigned char : 1;
};

// USA: func_0209cd50
extern "C" ARM int func_0209cd50(int value) {
    int result = 0;
    GameState* battle = GameState::GetInstance();
    struct SearchTable* table = (struct SearchTable*)GameState_GetZoneTable(battle);
    void* base = Zone3D_GetInstance();
    if ((_s32_div_f(value, 100) * 100) == 0x170c) {
        if (*(unsigned char*)((char*)base + Enum_0209cd50_10120) == 0) {
            if (*(unsigned short*)((char*)base + Enum_0209cd50_10118) == 0x76c) {
                value = 0x76c;
            }
        }
    }
    struct SearchEntry* entry = ZoneTable_FindEntry(table, value);
    if (entry != 0) {
        unsigned int idx = ((struct Struct_0209cd50*)entry)->unknown_d_0_;
        result = func_0209caf0(idx);
    }
    int r = func_0209cc3c(&data_02109be0, value);
    if (r >= 0) {
        result = r;
    }
    return result;
}
