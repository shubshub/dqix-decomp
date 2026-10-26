#include <globaldefs.h>

void NNS_SndHandleInit(int* field);

struct Data0215a79c { char pad[0xe0]; int fieldE0; int fieldE4; int fieldE8; int fieldEC; char pad2[0x4b4 - 0xf0]; int field4B4; int field4B8; };
extern struct Data0215a79c data_ov001_021658b8;
extern int data_ov001_021659a8[0xe9];
extern int data_ov001_02165958[0x10];

// USA: func_ov001_0215a79c
ARM void ResetGlobalStateArrays_0215a79c(void) {
    data_ov001_021658b8.fieldE8 = 0;
    data_ov001_021658b8.fieldEC = 0;
    data_ov001_021658b8.fieldE0 = 0;
    for (int i = 0; i < 0xe9; i++) {
        data_ov001_021659a8[i] = 0;
    }
    data_ov001_021658b8.fieldE4 = 0;
    for (int i = 0; i < 0x10; i++) {
        NNS_SndHandleInit(&data_ov001_02165958[i]);
    }
    data_ov001_021658b8.field4B4 = 0;
    data_ov001_021658b8.field4B8 = 0;
}
