#include <globaldefs.h>
#include <NitroSDK/ProcessorContext.h>

struct Struct_ov031_0224f670_13 {
    char unknown0[0xc];
    void (*unknown_c_)(void*);
    char unknown10[0x54 - 0x10];
    void* buffer;
};
extern Struct_ov031_0224f670_13 data_ov031_0224f670;
extern "C" int func_ov031_0221f7fc();
extern "C" void* func_ov031_0221fa20();

// USA: func_ov031_0221fb38
extern "C" THUMB int func_ov031_0221fb38() {
    int var0 = 1;
    if (func_ov031_0221f7fc() != 0) {
        do {
            SleepCurrentContext(10);
            void* event = func_ov031_0221fa20();
            if (event != NULL) do {
                switch ((unsigned int)event) {
                case 4: case 5: break;
                case 20: var0 = 0; break;
                default: var0 = 0; break;
                }
                event = func_ov031_0221fa20();
            } while (event != NULL);
        } while (var0 != 0);
    }
    if (data_ov031_0224f670.buffer != NULL) {
        data_ov031_0224f670.unknown_c_(data_ov031_0224f670.buffer);
        data_ov031_0224f670.buffer = NULL;
    }
    return 1;
}
