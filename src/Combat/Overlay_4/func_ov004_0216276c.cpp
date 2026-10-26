#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

class Struct_ov004_0216276c_2 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void inline_ov004_0216276c_26(const Vector3i&);
    virtual Vector3i inline_ov004_0216276c_27();
    virtual void inline_ov004_0216276c_28(); virtual void v10(); virtual void inline_ov004_0216276c_30(); virtual void inline_ov004_0216276c_31();
    virtual void inline_ov004_0216276c_32(); virtual void v14(); virtual void inline_ov004_0216276c_34(); virtual void inline_ov004_0216276c_35();
    virtual void inline_ov004_0216276c_36(); virtual void v18(); virtual void inline_ov004_0216276c_38(); virtual void v20();
    virtual void inline_ov004_0216276c_40(); virtual void inline_ov004_0216276c_41(); virtual void inline_ov004_0216276c_42(); virtual void v24();
    virtual void inline_ov004_0216276c_44(); virtual void inline_ov004_0216276c_45(); virtual void inline_ov004_0216276c_46(); virtual void v28();
    virtual void inline_ov004_0216276c_48(); virtual void v30(); virtual void inline_ov004_0216276c_50(); virtual void inline_ov004_0216276c_51();
    virtual void inline_ov004_0216276c_52(); virtual void v34(); virtual void inline_ov004_0216276c_54(); virtual void inline_ov004_0216276c_55();
    virtual void inline_ov004_0216276c_56(); virtual void v38(); virtual void inline_ov004_0216276c(); virtual void v40();
    virtual void inline_ov004_0216276c_3(); virtual void inline_ov004_0216276c_4(); virtual void inline_ov004_0216276c_5(); virtual void v44();
    virtual void inline_ov004_0216276c_7(); virtual void inline_ov004_0216276c_8(); virtual void inline_ov004_0216276c_9(); virtual void v48();
    virtual void inline_ov004_0216276c_11(); virtual void v50(); virtual void inline_ov004_0216276c_13(); virtual void inline_ov004_0216276c_14();
    virtual void inline_ov004_0216276c_15(); virtual void inline_ov004_0216276c_16(int); virtual void inline_ov004_0216276c_17();
    virtual void inline_ov004_0216276c_18(int);
    char padding4[8];
    unsigned char flags;
    char unknown_d_[0x2b];
    short value;
};
struct Struct_ov004_0216276c {
    char padding[0x16c];
    unsigned short items[13];
    unsigned char levels[13];
};
struct Struct_ov004_021707e8_6 {
#if defined(jpn)
    char padding[6]; unsigned char state; char unknown_7_[0x15];
#else
    char padding[7]; unsigned char state; char unknown_8_[0x14];
#endif
    int combatant;
};
extern Struct_ov004_021707e8_6 data_ov004_021707e8;
#if defined(jpn)
extern int data_ov004_021705c4[];
extern unsigned char data_ov004_021710d5[];
#else
extern int data_ov004_0216fe5c[];
extern unsigned char data_ov004_02170845[];
#endif
extern "C" Struct_ov004_0216276c* func_02053c6c(unsigned char*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov004_0215e574(void*, int, int, int, int);
extern "C" Struct_ov004_0216276c_2* func_ov023_021f6880(void*, int);
extern "C" int func_ov004_0215eb20(void*, int);
extern "C" int func_ov004_0215e460();
extern "C" void func_ov004_0215e49c(void*, int, int);
extern "C" int func_ov004_0215e4e8(void*, short);
extern "C" Struct_ov004_0216276c_2* func_ov004_0215e47c(void*, int);

// USA: func_ov004_0216276c
extern "C" ARM int func_ov004_0216276c(void* self) {
    data_ov004_021707e8.state = 0x68;
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), data_ov004_021707e8.combatant);
    if (!combatant) return 0;
    Struct_ov004_0216276c* equipment = func_02053c6c(((unsigned char*)(combatant)));
    if (!equipment) return 0;
    void* list = func_ov011_021849c8(self);
#if !defined(jpn)
    func_ov004_0215e574(self, 12, 255, 0, 0);
#endif
    unsigned char index = 0;
    while (index < 12) {
        Struct_ov004_0216276c_2* node = func_ov023_021f6880(list, index + 0x51);
        if (!node) { ++index; continue; }
        node->flags |= 8;
        node = func_ov023_021f6880(list, index + 13);
        if (!node) { ++index; continue; }
        node->flags |= 8;
        node = func_ov023_021f6880(list, index + 25);
        if (!node) { ++index; continue; }
        node->flags |= 8;
        node = func_ov023_021f6880(list, index + 38);
        if (!node) { ++index; continue; }
        node->flags |= 8;
        ++index;
    }
    unsigned char row = 0;
#if defined(jpn)
    int* slots = data_ov004_021705c4;
    unsigned char* enabled = data_ov004_021710d5;
#else
    int* slots = data_ov004_0216fe5c;
    unsigned char* enabled = data_ov004_02170845;
#endif
    for (int index = 0; index < 12; ++index) {
        int tableIndex = index + 1;
        if (!func_ov004_0215eb20(combatant, slots[tableIndex]) || !enabled[tableIndex]) continue;
        Struct_ov004_0216276c_2* node = func_ov023_021f6880(list, row + 13);
        if (!node) continue;
        node->flags &= ~8;
        node = func_ov023_021f6880(list, row + 25);
        if (!node) continue;
        node->flags &= ~8;
        if (func_ov004_0215e460())
            func_ov004_0215e49c(self, row + 13, 4);
        else
            func_ov004_0215e49c(self, row + 13, slots[tableIndex] + 4);
        func_ov004_0215e49c(self, row + 25, 0x1f1);
        node = func_ov023_021f6880(list, row + 0x51);
        if (!node) continue;
        int slot = slots[index + 1];
        node->inline_ov004_0216276c_18(equipment->items[slot]);
        node->flags &= ~8;
        unsigned char level = equipment->levels[slot];
        if (level != 0) {
            node = func_ov023_021f6880(list, row + 38);
            if (!node) continue;
            node->flags &= ~8;
            int var13 = 13;
            var13 += row;
            int width = func_ov004_0215e4e8(self, static_cast<short>(var13));
            node = func_ov004_0215e47c(self, var13);
            if (node) {
                Vector3i position;
                const Vector3i& source = node->inline_ov004_0216276c_27();
                position = source;
                position.x += (width + 2) << 12;
#if defined(jpn)
                position.y += 0x2000;
#endif
                node = func_ov004_0215e47c(self, row + 38);
                if (node) {
                    node->inline_ov004_0216276c_26(position);
                    node->value = level + 0x1d3;
                    if (level == 10) node->inline_ov004_0216276c_16(13);
                    else node->inline_ov004_0216276c_16(5);
                }
            }
        }
        ++row;
    }
    return 0;
}
