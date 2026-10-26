#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionSelfShift = 0x84, Enum_ov003_0217a764_54 = 0x2a };
#else
enum { kRegionSelfShift = 0, Enum_ov003_0217a764_54 = 0x36 };
#endif

struct Struct_0207fdcc_2;
struct Struct_0207fdf0_2;
struct SePlayer;
struct Struct_02081f20_2;
struct ItemTable;
struct Struct_ov003_02178910;
struct Element020de650;

struct Struct_ov003_0217a764 {
    char pad[8];
    unsigned int unknown_8_0_ : 12;
    unsigned int kind_ : 2;
};

struct GameState;
extern "C" void* GameState_GetParty(GameState*);
extern "C" void func_ov003_0217a220(unsigned char* obj);

extern "C" short func_02080468(void* obj, int id);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void func_0207fdf0(struct Struct_0207fdf0_2* obj, int key);
extern "C" ARM int func_ov003_02175d78(char* obj);

extern "C" void func_ov003_02177820(char* self);
extern "C" void func_ov003_02177938(void* self);
extern "C" void func_ov003_021748c4(unsigned char* self);
extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);
extern "C" int func_ov003_021764f4(unsigned char* self);
extern "C" void func_ov003_02176468(unsigned char* self);
extern "C" int func_ov003_02175df4(void* self);
extern "C" int func_ov003_02179da8(void* obj, int flag);
extern "C" void func_ov023_021dcae0(struct Struct_ov003_02178910* obj, int val);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_0217a764
extern "C" ARM void func_ov003_0217a764(unsigned char* self) {
    void* battle = GameState::GetInstance();
    GameState_GetParty((GameState*)battle);
    struct Struct_0207fdcc_2* var1 = *(struct Struct_0207fdcc_2**)(self + (0x89c - kRegionSelfShift));
    int state = *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift));

    if (state == 0) {
        int id = 0x11;
        switch (*(int*)(self + (0x1000 + 0x30 - kRegionSelfShift))) {
        case 2: id = 0x12; break;
        case 3: id = 0x13; break;
        case 4: id = 0x14; break;
        }
        func_ov003_02177820((char*)self);
        func_ov003_02177938(self);
        *(short*)((char*)var1 + Enum_ov003_0217a764_54) = *(short*)(self + (0x1000 + 0x10 - kRegionSelfShift));
        func_02080c68(var1, id, 1);
        *(short*)(self + (0xf00 + 0xfc - kRegionSelfShift)) = *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift));
        *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x15;
        if (*(short*)(self + (0x1000 + 0xe - kRegionSelfShift)) < 0) {
            *(short*)(self + (0x1000 + 0xe - kRegionSelfShift)) = func_02080468(var1, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        }
        *(short*)((char*)var1 + Enum_ov003_0217a764_54) = *(short*)(self + (0x1000 + 0xe - kRegionSelfShift));
        func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        func_ov003_0217a220(self);
        func_ov003_021748c4(self);
        return;
    }

    if (state == 1) {
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 0xe - kRegionSelfShift);
        func_ov003_0217a220(self);
        func_ov023_021dcae0((struct Struct_ov003_02178910*)(self + 0x3c), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
        if (func_ov003_021765b4(self) != 0) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            void* elem = (void*)ItemTable_Find((struct ItemTable*)(self + (0x874 - kRegionSelfShift)), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
            *(void**)(self + 8) = elem;
            if (elem == 0) return;
            int var5 = func_ov003_02179da8(elem, 0);
            if (var5 == 2) {
                func_0207fdf0((struct Struct_0207fdf0_2*)var1, 0);
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1c;
                *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 1;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
                return;
            }
            func_0207fdf0((struct Struct_0207fdf0_2*)var1, 0);
            int kind = ((struct Struct_ov003_0217a764*)*(void**)(self + 8))->kind_;
            short var7 = -1;
            unsigned char var8 = 0;
            switch (kind) {
            case 0:
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                var7 = 0x12;
                break;
            case 1:
                var7 = 0xd;
                var8 = 4;
                break;
            case 2:
                var7 = 0x11;
                var8 = 2;
                break;
            }
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = var7;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = var8;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
#if !defined(jpn)
            if (((struct Struct_ov003_0217a764*)*(void**)(self + 8))->kind_ == 0) {
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) &= ~0x2000;
            }
#endif
            return;
        }
        if (func_ov003_021766e8(self) == 0) return;
        func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 4;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
        return;
    }

    if (state == 2) {
        func_ov003_02176468(self);
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 3;
        return;
    }

    if (state == 3) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x10;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 4;
        } else {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x30;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        }
        return;
    }

    if (state == 4) {
        func_ov003_02176468(self);
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 5;
        return;
    }

    if (state == 5) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;
            func_ov003_02175d78((char*)self);
            func_ov003_02175df4(self);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0xe;
            *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 4;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        } else {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x30;
            *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 5;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        }
        return;
    }
}
