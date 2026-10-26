#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021cc4f8_2384 = 0x8b8 };
#else
enum { Enum_ov017_021cc4f8_2384 = 0x950 };
#endif

#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);

extern "C" void func_ov017_021c41fc(int combatantId, signed char arg1);
extern "C" ARM void func_ov017_021c4418(int combatantId, signed char arg1);
extern "C" ARM void func_ov017_021c45b4(int combatantId);
extern "C" void func_ov017_021ce704(int combatantId);
extern "C" ARM void func_ov017_021cf078(int combatantId, unsigned short slot, unsigned char flag);
extern "C" void func_ov017_021c3fb4(int combatantId, int flag);
extern "C" void func_ov017_021cc730(int combatantId, int b, int c, int d);
extern "C" ARM void func_ov017_021ccc34(int combatantId);
extern "C" void func_ov017_021ce524(short combatantId);
extern "C" void func_ov017_021ccdac(int combatantId);
extern "C" void func_ov017_021ccfd0(int combatantId);
extern "C" ARM void func_ov017_021ce32c(int id);
extern "C" ARM void func_ov017_021cee78(int id, unsigned char b);
extern "C" void func_ov017_021cff8c(int combatantId, int b);
extern "C" ARM void func_ov017_021cfed0(unsigned char a, unsigned char b);
extern "C" void func_ov017_021c9e00(int combatantId, int b, int c, int d);

struct Struct_ov017_021cc4f8 {
    unsigned char pad0[4];
    unsigned char id;
    unsigned char tag;
    unsigned char pad1[2];
    unsigned int flags;
};

// USA: func_ov017_021cc4f8
extern "C" ARM void func_ov017_021cc4f8(signed char flag, struct Struct_ov017_021cc4f8* args, GameState* bs, int unused, struct SearchStruct0202c1a4* search) {
    int id = args->id;
    signed char cur = LinkSession_GetOwnSlot(search);
    if (args->tag != cur) return;

    int var2 = 0;
    unsigned int flags = args->flags;

    if (flags & 0x2) {
        func_ov017_021c41fc(id, flag);
        func_ov017_021c4418(id, flag);
    }
    if (flags & 0x4) {
        func_ov017_021c45b4(id);
    }
    if (flags & 0x8) {
        func_ov017_021ce704(id);
        GameObject* c = func_0200ff1c(bs, id);
        if (c) {
            int f150 = func_02053c6c((unsigned char*)c);
            unsigned char slot = *(int*)((char*)f150 + Enum_ov017_021cc4f8_2384) & 0xff;
            func_ov017_021cf078(id, slot, 1);
        }
        var2 = 1;
    }
    if (flags & 0x1) {
        func_ov017_021c3fb4(id, 1);
        var2 = 1;
    }
    if (flags & 0x10) {
        func_ov017_021cc730(id, 0, 0, 1);
        func_ov017_021ccc34(id);
        func_ov017_021ce524((short)id);
    }
    if (flags & 0x40) {
        func_ov017_021ccdac(id);
    }
    if (flags & 0x20) {
        func_ov017_021ccfd0(id);
        var2 = 1;
    }
    if (flags & 0x80) {
        func_ov017_021ce32c(id);
    }
    if (flags & 0x100) {
        func_ov017_021cee78(id, 0);
    }
    if (flags & 0x800) {
        func_ov017_021cff8c(id, 0);
    }
    if (flags & 0x200) {
        func_ov017_021cfed0((unsigned char)flag, (unsigned char)id);
    }
    if (var2) {
        func_ov017_021c9e00(id, 1, 0, 1);
    }
    if (!(flags & 0x1000)) return;
    func_ov017_021c9e00(id, 1, 0, 1);
}
