#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);

extern "C" void* func_0207d78c(void);

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
extern "C" Entry0207d9bc* func_0207d9bc(Entry0207d9bc* arr, unsigned short key);
extern "C" int func_0207d978(Entry0207d9bc* arr, unsigned short key);
extern "C" int func_0207da30(unsigned char* arr, int id, int offset);

extern "C" GameObject* func_ov017_021a278c(void* unused, int val);

extern "C" void func_ov017_021c5e28(int id, int val);

extern "C" void func_0207d7f4(Entry0207d9bc* arr, unsigned short key, int a, unsigned char b, int c, unsigned short d, int e);
extern "C" void func_0207dcf0(int a);

struct Struct_ov017_021c5f54 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned char fieldA;
};

// USA: func_ov017_021c5f54
extern "C" ARM void func_ov017_021c5f54(int a, Struct_ov017_021c5f54* info, int unused, void* combatant, SearchStruct0202c1a4* search) {
    Entry0207d9bc* arr;
    if (LinkSession_GetOwnSlot(search) != 0)
        return;
    arr = (Entry0207d9bc*)func_0207d78c();
    if (info->field9 == 0 && info->fieldA == 0
        && func_ov017_021a278c(combatant, info->field4) == NULL
        && func_0207d9bc(arr, info->field4) == NULL) {
        ((void(*)(int, unsigned short))func_ov017_021c5e28)(a, info->field4);
        return;
    }
    if (func_0207d978(arr, info->field4))
        return;
    if (func_0207da30((unsigned char*)arr, info->field4, a))
        return;
    func_0207d7f4(arr, info->field4, a, info->field8, -1, info->field6, 0);
    func_0207dcf0(info->field4);
}
