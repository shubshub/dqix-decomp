#include <globaldefs.h>

extern "C" int func_ov017_0219bddc(unsigned char* out, int flag);
extern "C" void func_ov017_0219bf04(int val, void* obj);

// USA: func_ov017_0219bed0
extern "C" ARM int func_ov017_0219bed0(void* obj) {
    unsigned char local = 0;
    int result = func_ov017_0219bddc(&local, 0);
    if (result) {
        func_ov017_0219bf04(local, obj);
    }
    return result;
}
