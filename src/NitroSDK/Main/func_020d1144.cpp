#include <globaldefs.h>


extern "C" void HaltSystem(void);
extern "C" void func_020d11a8(void);

struct Struct_02112140_2 {
    int done;
    int (*callback)(void);
};
extern Struct_02112140_2 data_02112140;

// USA: func_020d1144
extern "C" ARM void func_020d1144(unsigned int context, unsigned int code, unsigned int error) {
    if ((code & 0x3f) == 0x11) {
        if (data_02112140.done != 0) return;
        data_02112140.done = 1;
        {
            int r = 1;
            if (data_02112140.callback != 0) r = data_02112140.callback();
            if (r == 0) return;
            func_020d11a8();
        }
        return;
    }
    HaltSystem();
}
