#include <globaldefs.h>
#include "std_library_functions.h"


extern "C" void* Scenario_GetInstance(void* obj);
extern "C" void func_02064b98(unsigned char* table, int arg1);

// USA: func_ov017_021cdccc
extern "C" ARM void func_ov017_021cdccc(void* obj, int pos, void* data) {
    unsigned char* buf = (unsigned char*)Scenario_GetInstance(obj);
    int end = pos + 0xe;
    int len = 0xe;
    int var3 = 0;
    if ((unsigned int)end > 0xfd) {
        len = 0xfd - pos;
        var3 = 1;
    } else if (end == 0xfd) {
        var3 = 1;
    }
    if (len < 0) return;

    void* dst = memcpy(buf + pos, data, len);
    if (!var3) return;

    func_02064b98((unsigned char*)Scenario_GetInstance(dst), 0xc3b5);
}
