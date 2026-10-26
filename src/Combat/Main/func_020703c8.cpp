#if defined(jpn)
enum { Enum_020703c8_17604 = 0x4214 };
#else
enum { Enum_020703c8_17604 = 0x44c4 };
#endif

#include <globaldefs.h>
#include "Resource/GameResources.h"


extern "C" void* Scenario_GetInstance(void);
extern "C" int* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_021d0924(int kind, unsigned char index, int flags, unsigned short packedTime);

struct Struct_0206dee8;
struct Struct_0206dec8;
extern "C" void func_0206dee8(Struct_0206dee8* arg0, unsigned char arg1, unsigned char* arg2, unsigned char* arg3, unsigned char* arg4);
extern "C" void func_0206dec8(Struct_0206dec8* arg0, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char arg4);

void ClearRegions0206e080(char* base, int index);
void ClearIndexedEntryFields0206e0d0(char* base, int index);
void ClearTwoRegions0206ebf4(char* obj);
int LinkSession_IsActive(int* obj);
void ApplySlotBytesToBattleStruct_0206df14(unsigned char* obj);

// USA: func_020703c8
extern "C" ARM void func_020703c8(int index, int hour, int minute, int second) {
    unsigned char curHour;
    unsigned char curMinute;
    unsigned char curSecond;
    void* entry = Scenario_GetInstance();
    int* state = LinkSession_GetInstance();
    char* owner = *(char**)((char*)GetGameResources() + RegionalOffset);

    func_0206dee8((Struct_0206dee8*)var3, arg0, &var0, &var1, &var2);
    if (var2 + (var0 * 10000 + var1 * 100) >= arg3 + (arg1 * 10000 + arg2 * 100)) {
        return;
    }
    if (var0 != arg1) {
        func_0206e080((char*)var3, arg0);
        func_0206ebf4(var5);
    } else if (var1 != arg2) {
        func_0206e0d0((char*)var3, arg0);
        func_0206ebf4(var5);
    }
    SetEntry3Bytes_0206dec8((EntryDEC8*)entry, index, hour, minute, second);
    if (LinkSession_IsActive(state) != 0 && LinkSession_IsHostOrSolo(state) != 0) {
        func_ov017_021d0924(2, index, 0, second | (hour << 10 | minute << 5));
    }
    func_0206df14((unsigned char*)var3);
}
