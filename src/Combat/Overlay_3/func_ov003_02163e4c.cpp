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

int GetFieldAt0x150_02053c6c(unsigned char* obj);
void AddPositiveField150EntriesToMap_021b6bb8(int combatantId);
extern "C" int func_ov017_021b6d60(int a, void* buf);
extern "C" void Party_AddMemberRecord(void* map, void* buf, int c, int d);

// USA: func_ov003_02163e4c  (semantic: AdvanceTargetSearchStep_02163e4c)
extern "C" ARM void func_ov003_02163e4c(char* obj) {
    unsigned char step = obj[kRegionValue4A4_2CC];
    if (step == 0) {
        char buf[0x23c];
        GameState* bs = GameState::GetInstance();
        void* map = GameState_GetParty(bs);
        short id = *(short*)(obj + kRegionValue400_200 + kRegionValue82_AA);
        GameObject* c = bs->GetPartyMemberByIndex(id);
        if (c == NULL) {
            obj[kRegionValue4A3_2CB] = 0x10;
            return;
        }
        unsigned char* var6 = (unsigned char*)func_02053c6c((unsigned char*)var5);
        if (var6 == NULL) {
            arg0[Enum_ov003_02163e4c_1187] = 0x10;
            return;
        }
        *(short*)(arg0 + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_132) = 0xd;
        short var7 = *(short*)(var6 + 0x400 + 0x54);
        if (var7 > 0) {
            *(short*)(arg0 + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_134) = 0xe;
        }
        AddPositiveField150EntriesToMap_021b6bb8(*(short*)(obj + kRegionValue400_200 + kRegionValue82_AA));
        func_ov017_021b6d60(*(short*)(obj + kRegionValue400_200 + kRegionValue82_AA), buf);
        Party_AddMemberRecord(map, buf, 0, 0);
        short sv = (buf[0] << 26) >> 26;
        *(short*)(obj + kRegionValue400_200 + kRegionValue80_A8) = sv;
        obj[kRegionValue4A4_2CC] = (unsigned char)obj[kRegionValue4A4_2CC] + 1;
        *(int*)(obj + kRegionValue464_28C) |= 8;
        return;
    }
    if (var0 != 1) return;
    *(short*)(arg0 + Enum_ov003_02163e4c_1024 + Enum_ov003_02163e4c_132) = 2;
    *(int*)(arg0 + Enum_ov003_02163e4c_1124) |= 8;
    arg0[Enum_ov003_02163e4c_1187] = 1;
    arg0[Enum_ov003_02163e4c_1188] = 0;
}
