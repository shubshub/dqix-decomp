#include <globaldefs.h>

struct Struct_021117ec_2 {
    unsigned char pad[0x1c];
    int lock;
};
extern struct Struct_021117ec_2 data_021117ec;
extern int data_02111808;
int GetProcessorMode(void);
void HandleCommandReceivedFromArm7(void);

// USA: func_020ce148
extern "C" ARM void func_020ce148(void) {
    struct Struct_021117ec_2* var0 = &data_021117ec;
    int* counter = &data_02111808;
    if (var0->lock == 0) {
        return;
    }
    do {
        if (GetProcessorMode() == 0x12) {
            HandleCommandReceivedFromArm7();
        }
    } while (*counter != 0);
}
