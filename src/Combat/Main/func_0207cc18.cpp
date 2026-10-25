#include <globaldefs.h>


struct Save0207cc18 { char pad[0x8c]; unsigned char bits[1]; };
struct Entry0207cc18 {
    char pad[8];
    unsigned int type:4, unused8:28;
    unsigned int unusedc:12, key:11, unusedc23:9;
};
struct S_a04c8;
struct S_a0494;
struct BattleBlock0207cc18 { char data[0xb0]; };
static inline int IsType0207cc18(unsigned char type) { return type <= 7; }
static inline int IsTypeRange0207cc18(unsigned char type) { return type >= 8 && type <= 9; }
extern "C" Save0207cc18* Scenario_GetInstance(void*);
int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
int LoadBattleBlock020ac4c0(void*);
void AddClamped11BitFieldAt0x14_020a04c8(S_a04c8*, unsigned int);
void AddClamped9BitFieldMidAt0x14_020a0494(S_a0494*, unsigned int);
int CopyInBattleField0x7540_020ac494(void*);
// USA: func_0207cc18
extern "C" ARM void func_0207cc18(void* obj, Entry0207cc18* entry) {
    if (entry) {
        Save0207cc18* save = Scenario_GetInstance(obj);
        int key = (unsigned short)entry->key;
        if (key > 0) {
            int index = key + 0xc76;
            if (!Scenario_TestFlag((int)save, save->bits, index)) {
                Scenario_SetFlag(save, save->bits, index, 1);
                BattleBlock0207cc18 block;
                LoadBattleBlock020ac4c0(&block);
                unsigned char type = entry->type;
                if (IsType0207cc18(type))
                    AddClamped11BitFieldAt0x14_020a04c8((S_a04c8*)&block, 1);
                else if (IsTypeRange0207cc18(type))
                    AddClamped9BitFieldMidAt0x14_020a0494((S_a0494*)&block, 1);
                CopyInBattleField0x7540_020ac494(&block);
            }
        }
    }
}
