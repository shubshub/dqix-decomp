#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_02108cec_7 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char pad3;
    short unknown_4_;
    short half6;
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
    void* field10;
    void* field14;
};
extern struct Struct_02108cec_7 data_02108cec;

struct ResetStruct;
struct StreamState;
struct StreamHeader;
struct Struct_0201f040_3;
extern int data_020f0994;

// USA: func_0206da80
extern "C" ARM int func_0206da80(int* param0, unsigned char param1, unsigned char param2, unsigned char param3, int arg4, int arg5, struct StreamHeader* arg6, int arg7) {
    char local[0x430];
    if (data_02108cec.field10 != 0) {
        *param0 = 0;
        data_02108cec.unknown_a_ = 0;
        data_02108cec.unknown_8_ = -1;
        data_02108cec.unknown_4_ = -1;
        data_02108cec.half6 = -1;
    }
    *param0 = 0;
    data_02108cec.unknown_2_ = param1;
    data_02108cec.unknown_1_ = param2;
    data_02108cec.byte0 = param3;
    data_02108cec.unknown_c_ = arg4;
    data_02108cec.field10 = param0;
    data_02108cec.field14 = (void*)arg5;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0994);
    ((Script*)((struct StreamState*)local))->Load(arg6, arg7);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();
    return 1;
}
