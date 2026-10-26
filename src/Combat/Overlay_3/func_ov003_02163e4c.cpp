#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02163e4c_1188 = 0x2cc };
enum { Enum_ov003_02163e4c_1024 = 0x200 };
enum { Enum_ov003_02163e4c_130 = 0xaa };
enum { Enum_ov003_02163e4c_1187 = 0x2cb };
enum { Enum_ov003_02163e4c_132 = 0xac };
enum { Enum_ov003_02163e4c_134 = 0xae };
enum { Enum_ov003_02163e4c_128 = 0xa8 };
enum { Enum_ov003_02163e4c_1124 = 0x28c };
#else
enum { Enum_ov003_02163e4c_1188 = 0x4a4 };
enum { Enum_ov003_02163e4c_1024 = 0x400 };
enum { Enum_ov003_02163e4c_130 = 0x82 };
enum { Enum_ov003_02163e4c_1187 = 0x4a3 };
enum { Enum_ov003_02163e4c_132 = 0x84 };
enum { Enum_ov003_02163e4c_134 = 0x86 };
enum { Enum_ov003_02163e4c_128 = 0x80 };
enum { Enum_ov003_02163e4c_1124 = 0x464 };
#endif

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_ov017_021b6bb8(int combatantId);
extern "C" int func_ov017_021b6d60(int a, void* buf);
extern "C" void Party_AddMemberRecord(void* map, void* buf, int c, int d);

// USA: func_ov003_02163e4c
extern "C" ARM void func_ov003_02163e4c(char* obj) {
    unsigned char step = obj[Enum_ov003_02163e4c_1188];
    if (step == 0) {
        char buf[0x23c];
        GameState* bs = GameState::GetInstance();
        void* map = GameState_GetParty(bs);
        short id = *(short*)(obj + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_130);
        GameObject* c = bs->GetPartyMemberByIndex(id);
        if (c == NULL) {
            obj[Enum_ov003_02163e4c_1187] = 0x10;
            return;
        }
        unsigned char* field150 = (unsigned char*)func_02053c6c((unsigned char*)c);
        if (field150 == NULL) {
            obj[Enum_ov003_02163e4c_1187] = 0x10;
            return;
        }
        *(short*)(obj + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_132) = 0xd;
        short v54 = *(short*)(field150 + 0x400 + 0x54);
        if (v54 > 0) {
            *(short*)(obj + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_134) = 0xe;
        }
        func_ov017_021b6bb8(*(short*)(obj + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_130));
        func_ov017_021b6d60(*(short*)(obj + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_130), buf);
        Party_AddMemberRecord(map, buf, 0, 0);
        short var8 = (buf[0] << 26) >> 26;
        *(short*)(obj + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_128) = var8;
        obj[Enum_ov003_02163e4c_1188] = (unsigned char)obj[Enum_ov003_02163e4c_1188] + 1;
        *(int*)(obj + Enum_ov003_02163e4c_1124) |= 8;
        return;
    }
    if (step != 1) return;
    *(short*)(obj + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_132) = 2;
    *(int*)(obj + Enum_ov003_02163e4c_1124) |= 8;
    obj[Enum_ov003_02163e4c_1187] = 1;
    obj[Enum_ov003_02163e4c_1188] = 0;
}
