#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);
extern "C" int func_020882f8(unsigned char* stats);

struct Struct_ov024_021e9018 { char pad[0x10]; void* unknown_10_; };
struct Struct_ov024_021e9018_2 { unsigned short unknown_0_0_ : 2; unsigned short element : 4; unsigned short rest : 10; };

struct Struct_ov024_021fe7c4 { short key; unsigned short pad; };
struct Struct_ov024_021fe7c6 { unsigned short value; unsigned short pad; };

extern struct Struct_ov024_021fe7c4 data_ov024_021fe840[];
extern struct Struct_ov024_021fe7c6 data_ov024_021fe842[];
extern struct Struct_ov024_021fe7c4 data_ov024_021fe7c4[];
extern struct Struct_ov024_021fe7c6 data_ov024_021fe7c6[];

// USA: func_ov024_021e9018
extern "C" ARM int func_ov024_021e9018(struct Struct_ov024_021e9018* ctx, int id, short kind, int mode) {
    if (mode != 0) {
        if (kind == 5) {
            return func_ov024_021da644(id, 0x63, 0x62);
        }
        int idx = 0;
        while (data_ov024_021fe840[idx].key != -1) {
            if (kind == data_ov024_021fe840[idx].key) {
                return data_ov024_021fe842[idx].value;
            }
            idx++;
        }
    } else {
        GameObject* c = GetCombatantByID((int)ctx->unknown_10_, id);
        if (!c) return 0;
        if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c) &&
            (kind == 3 || kind == 4 || kind == 5 || kind == 8)) {
#if defined(jpn)
            return 0x1b;
#else
            return func_ov024_021da644(id, 0x26d, 0x1b);
#endif

        }
        if (func_020882f8((unsigned char*)c->currentStats_) && (unsigned short)(short)(kind - 2) <= 6) {
#if defined(jpn)
            return 0x1b;
#else
            return func_ov024_021da644(id, 0x26d, 0x1b);
#endif

        }
        struct Struct_ov024_021e9018_2* b = (struct Struct_ov024_021e9018_2*)((char*)c->currentStats_ + 0x22);
        int element = b->element;
        if (element != kind) return 0;
        if (element == 5) {
            return func_ov024_021da644(id, 0x61, 0x60);
        }
        int idx = 0;
        while (data_ov024_021fe7c4[idx].key != -1) {
            if (element == data_ov024_021fe7c4[idx].key) {
                return data_ov024_021fe7c6[idx].value;
            }
            idx++;
        }
    }
    return 0;
}
