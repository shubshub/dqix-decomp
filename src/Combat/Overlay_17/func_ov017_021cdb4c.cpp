#include <globaldefs.h>



struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4*);
extern "C" void* Scenario_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
void SetOrClearBit2_0201bf84(unsigned char* obj, int set);

struct Struct_ov017_021cdb4c {
    char unknown_0_[4];
    signed char unknown_4_;
    unsigned char unknown_5_;
    unsigned short unknown_6_;
    int unknown_8_;
};

// USA: func_ov017_021cdb4c
extern "C" ARM void func_ov017_021cdb4c(void* arg0, struct Struct_ov017_021cdb4c* arg1, int arg2, int arg3, struct Struct_0202c1a4* arg4) {
    if (arg1->unknown_4_ >= 0 && arg1->unknown_4_ != func_0202c1a4(arg4)) {
        return;
    }

    unsigned char* base = (unsigned char*)Scenario_GetInstance();
    unsigned char* other = (unsigned char*)Zone3D_GetInstance();

    switch (arg1->unknown_5_) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    case 1:
        Scenario_SetFlag(base, base + 0x8c, obj->field6 + 0x212, obj->field8);
        break;
    case 8:
        Scenario_SetFlag(base, base + 0x8c, obj->field6 + 0x79e, obj->field8);
        break;
    case 7:
        Scenario_SetFlag(base, base + 0x8c, obj->field6 + 0x33e, obj->field8);
        SetOrClearBit2_0201bf84(other, 1);
        break;
    default:
        break;
    }
}
