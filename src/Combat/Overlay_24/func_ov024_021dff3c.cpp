#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_0208869c(unsigned char* obj);
struct Struct_020886dc;
struct Struct_02088724;
struct Struct_0208876c;
struct Struct_020887b4;
extern "C" void func_020886dc(struct Struct_020886dc* obj);
extern "C" void func_02088724(struct Struct_02088724* obj);
extern "C" void func_0208876c(struct Struct_0208876c* obj);
extern "C" void func_020887b4(struct Struct_020887b4* obj);
extern "C" void func_020887fc(unsigned char* obj);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021dff3c_4 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Struct_ov024_021dff3c { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dff3c_2 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021dff3c_3 {
    char pad[0x20];
    struct Struct_ov024_021dff3c_4 f20;
    struct Struct_ov024_021dff3c_4 f24;
    char pad28[0x30 - 0x28];
    short state;
};

// USA: func_ov024_021dff3c
extern "C" ARM void* func_ov024_021dff3c(struct Struct_ov024_021dff3c_2* obj, int unused, int id, struct Struct_ov024_021dff3c_3* range, int arg4, int arg5, unsigned char arg6) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return 0;
    unsigned short sel;
    if (range->state > 0) {
        if (func_0208869c((unsigned char*)c->currentStats_) && arg6 != 0) {
            sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
            switch (range->state) {
                case 1:
                    func_020886dc((struct Struct_020886dc*)c->currentStats_);
                    break;
                case 2:
                    func_02088724((struct Struct_02088724*)c->currentStats_);
                    break;
                case 3:
                    func_0208876c((struct Struct_0208876c*)c->currentStats_);
                    break;
                case 4:
                    func_020887b4((struct Struct_020887b4*)c->currentStats_);
                    break;
                case 5:
                    func_020887fc((unsigned char*)c->currentStats_);
                    break;
            }
        } else {
            sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
        }
    } else {
        sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
    }
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return 0;
    func_ov000_0215a88c(obj->unknown_10_, entry, sel);
    struct Struct_ov024_021dff3c* var3 = (struct Struct_ov024_021dff3c*)((char*)obj->unknown_c_ + 0x1c);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var3->flag != 0);
    return entry;
}
