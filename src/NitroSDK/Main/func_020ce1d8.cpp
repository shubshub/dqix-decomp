#include <globaldefs.h>

unsigned int GetIRQInterruptState(void);
int GetProcessorMode(void);
void HandleCommandReceivedFromArm7(void);

struct Struct_021117ec_3 { unsigned char pad[0x1c]; int field1c; };
extern Struct_021117ec_3 data_021117ec;
extern int data_02111808;

// USA: func_020ce1d8
extern "C" ARM void func_020ce1d8(void) {
    int* var0 = &data_02111808;
    if (data_021117ec.field1c == 0) return;
    volatile unsigned short* var1 = (volatile unsigned short*)0x4000208;
    do {
        if (GetIRQInterruptState() == 0x80 || *var1 == 0 || GetProcessorMode() == 0x12) {
            HandleCommandReceivedFromArm7();
        }
    } while (*var0 != 0);
}
