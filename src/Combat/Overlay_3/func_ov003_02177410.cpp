#include <globaldefs.h>
#if defined(jpn)
extern const char* data_ov003_0217ece0;
enum { Enum_ov003_02177410_13=0xc };
enum { Enum_ov003_02177410_336 = 0x144 };
enum { kRegion89c = 0x818 };
enum { Enum_ov003_02177410_2208 = 0x81c };
enum { Enum_ov003_02177410_4163 = 0xfbf };
#else
enum { Enum_ov003_02177410_13=0xd };
enum { Enum_ov003_02177410_336 = 0x150 };
enum { kRegion89c = 0x89c };
enum { Enum_ov003_02177410_2208 = 0x8a0 };
enum { Enum_ov003_02177410_4163 = 0x1043 };
#endif
#include "GameState/GameState.h"

struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c68(void* obj, int id, int value);
struct Struct_02081214;
extern "C" void* func_02081214(struct Struct_02081214* arg0, int key);
extern "C" void func_0208077c(void* obj, int id, short value);
struct Struct_02080cc0;
extern "C" void func_02080cc0(struct Struct_02080cc0* obj, int id, int value);
struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c* obj, int id, int value);
extern "C" void func_020805f4(void* obj, int value);
extern "C" void func_020813ec(void* obj, int key);

struct Struct_ov003_0217faa4 {
    unsigned char index[8];
};
extern Struct_ov003_0217faa4 data_ov003_0217faa4;

struct Struct_ov003_02177410 {
    char pad0[4];
    int value;
    unsigned int kind : 4;
    unsigned int pad8 : 28;
    char unknown_c_[0x18 - 0xc];
    short count;
    char pad1a[0x20 - 0x1a];
};

struct Struct_ov003_02177410_2 {
    char pad0[0x194];
    Struct_ov003_02177410 slots[8];
};

struct Struct_ov003_02177410_3 {
    char pad0[Enum_ov003_02177410_336];
    Struct_ov003_02177410_2* status;
};

struct Struct_ov003_02177410_4 {
    char pad0[kRegion89c];
    struct Struct_0207fdcc_2* unknown_89c_;
    char unknown_8a0_[Enum_ov003_02177410_4163 - Enum_ov003_02177410_2208];
    signed char combatantId;
};

// USA: func_ov003_02177410
extern "C" ARM void func_ov003_02177410(Struct_ov003_02177410_4* self) {
    GameState* battle = GameState::GetInstance();
    struct Struct_0207fdcc_2* var1 = self->unknown_89c_;
    func_02080c20(var1, 0xe);
    func_02080c68(var1, 0xe, 0);

    Struct_ov003_02177410_3* combatant = (Struct_ov003_02177410_3*)func_0200ff1c(battle, self->combatantId);
    if (combatant == NULL) {
        return;
    }

    Struct_ov003_0217faa4 list = data_ov003_0217faa4;
#if !defined(jpn)
    int var4 = (int)func_02081214((struct Struct_02081214*)var1, 0x14);
#endif
    for (short i = 0; i < 8; i++) {
        short id = i + 0x68;
#if defined(jpn)
        int value = (int)data_ov003_0217ece0;
#else
        int value = var4;
#endif
        int nibble = 3;
        unsigned char index = list.index[i];
        if (index != 0xff) {
            Struct_ov003_02177410* slot = &combatant->status->slots[index];
            if (slot == NULL) {
                continue;
            }
            if (slot->count > 0 && slot->kind != 0xb) {
                value = slot->value;
                nibble = 0xf;
            }
        }
        func_0208077c(var1, id, Enum_ov003_02177410_13);
        func_02080cc0((struct Struct_02080cc0*)var1, id, nibble);
        func_02080f8c((struct Container02080f8c*)var1, id, value);
#if !defined(jpn)
        func_020805f4(var1, id);
#endif
    }

    func_020813ec(var1, 0xe);
}
