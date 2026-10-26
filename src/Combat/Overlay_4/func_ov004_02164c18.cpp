#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "NitroSDK/Memory.h"

#if defined(jpn)
enum { Enum_ov004_02164c18_6388 = 0x19f4 };
#else
enum { Enum_ov004_02164c18_6388 = 0x18f4 };
#endif

struct Struct_ov004_02164c18 {
    TreasureMapMetadata unknown_0_[99];
    char unknown_ad4_[Enum_ov004_02164c18_6388 - 99 * 0x1c];
    unsigned char count;
    char unknown_18f5_;
    short page;
    short pageCount;
};

struct Struct_ov004_02164c18_2 {
    char pad[0x5c];
    short page;
    short pageCount;
};

extern "C" void Zone3D_GetInstance(GameState* state);
extern "C" int func_ov004_021634dc(void* a);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" struct Struct_ov004_02164c18_2* func_ov023_021f6880(void* list, int id);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void func_ov023_021f9ba8(void* obj, unsigned short v);
extern "C" void func_ov004_021636b0(void* a1, void* a2);
extern "C" int func_ov004_02163530(void* a);
extern "C" void func_ov004_02164084(void* a);

extern struct Struct_ov004_02164c18* data_ov004_02171010;
extern char data_ov004_02170598[];

// USA: func_ov004_02164c18
extern "C" ARM int func_ov004_02164c18(void* a) {
    if (data_ov004_02171010->count == 0) {
        return 0;
    }
    Zone3D_GetInstance(GameState::GetInstance());
    int index = func_ov004_021634dc(a);
    if (data_ov004_02171010->unknown_0_[index].GetInitialByteUnknownBit()) {
        return 0;
    }

    int i;
    for (i = index; i < data_ov004_02171010->count - 1; i++) {
        VectorizedInvertedMemcpy(&data_ov004_02171010->unknown_0_[i + 1], &data_ov004_02171010->unknown_0_[i], sizeof(TreasureMapMetadata));
    }
    int j;
    for (j = data_ov004_02171010->count - 1; j < 99; j++) {
        VectorizedMemset(&data_ov004_02171010->unknown_0_[j], 0, sizeof(TreasureMapMetadata));
    }

    if (index + 1 == data_ov004_02171010->count && index != 0) {
        struct Struct_ov004_02164c18_2* node = func_ov023_021f6880(func_ov011_021849c8(a), 0xa);
        if (node == 0) {
            return 0;
        }
        if (func_ov023_021f6f10(node) != 7) {
            return 0;
        }
        data_ov004_02171010->page = (index - 1) / 8;
        short slot = (index - 1) % 8;
        short pageCount = data_ov004_02171010->pageCount;
        short page = data_ov004_02171010->page;
        node->page = page;
        node->pageCount = pageCount;
        func_ov023_021f9ba8(node, slot);
    }

    data_ov004_02171010->count--;
    if (data_ov004_02171010->count == 0) {
        func_ov004_021636b0(a, data_ov004_02170598);
    }
    func_ov004_02163530(a);
    func_ov004_02164084(a);
    return 0;
}
