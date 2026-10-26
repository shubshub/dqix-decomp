#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0224e204;
extern "C" void func_020c7de4(Struct_ov031_0224e204* arg0, int arg1, int arg2);
bool IsContextInactive(ProcessorContext* context);
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
extern "C" void func_ov031_0224599c(void);

extern ProcessorContext data_ov031_02291f80;
extern int data_ov031_0224c954;
extern int data_ov031_02291f60;
extern int data_ov031_02291f44;
extern int data_ov031_02291f24;
extern int data_ov031_02292040;
extern int data_ov032_02292500;

// USA: func_ov031_0224587c
extern "C" ARM void func_ov031_0224587c(void* arg0) {
    if (data_ov031_02291f80.uniqueID != 0) {
        if (!IsContextInactive(&data_ov031_02291f80)) {
            return;
        }
    }
    *(int*)((char*)&data_ov031_0224c954 + 4) = (int)arg0;
    func_020c7de4((Struct_ov031_0224e204*)&data_ov031_02291f60, (int)&data_ov031_02291f44, 3);
    *(int*)((char*)&data_ov031_02291f24 + 0x1c) = 0;
    *(int*)((char*)&data_ov031_02291f24 + 0x18) = 0;
    MIi_CpuClearFast(0, &data_ov031_02292040, 0xc0);
    PopulateContext(&data_ov031_02291f80, (unsigned int)func_ov031_0224599c, 0, (unsigned int)&data_ov032_02292500, 0x400, 0x18);
    *(int*)((char*)&data_ov031_02291f24 + 4) = 0;
    MarkContextReadyAndSwitch(&data_ov031_02291f80);
}
