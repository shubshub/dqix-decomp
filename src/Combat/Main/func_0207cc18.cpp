#include <globaldefs.h>


struct Save0207cc18 { char pad[0x8c]; unsigned char bits[1]; };
struct Struct_0207cc18_2 {
    char pad[8];
    unsigned int type:4, unknown_8_4_:28;
    unsigned int unknown_c_0_:12, key:11, unknown_e_7_:9;
};
struct Struct_0206e424_4;
struct Struct_0207cc18_3;
struct Struct_0207cc18_4 { char data[0xb0]; };
static inline int inline_0207cc18(unsigned char type) { return type <= 7; }
static inline int inline_0207cc18_2(unsigned char type) { return type >= 8 && type <= 9; }
extern "C" Save0207cc18* Scenario_GetInstance(void*);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" int func_020ac4c0(void*);
extern "C" void func_020a04c8(Struct_0206e424_4*, unsigned int);
extern "C" void func_020a0494(Struct_0207cc18_3*, unsigned int);
extern "C" int func_020ac494(void*);
// USA: func_0207cc18
extern "C" ARM void func_0207cc18(void* obj, Struct_0207cc18_2* entry) {
    if (entry) {
        Save0207cc18* save = Scenario_GetInstance(obj);
        int key = (unsigned short)entry->key;
        if (key > 0) {
            int index = key + 0xc76;
            if (!Scenario_TestFlag((int)save, save->bits, index)) {
                Scenario_SetFlag(save, save->bits, index, 1);
                Struct_0207cc18_4 block;
                func_020ac4c0(&block);
                unsigned char type = entry->type;
                if (inline_0207cc18(type))
                    func_020a04c8((Struct_0206e424_4*)&block, 1);
                else if (inline_0207cc18_2(type))
                    func_020a0494((Struct_0207cc18_3*)&block, 1);
                func_020ac494(&block);
            }
        }
    }
}
