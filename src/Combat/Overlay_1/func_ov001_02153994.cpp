#include <globaldefs.h>

extern "C" void func_ov017_021d4ccc(void* p);
extern "C" void func_ov001_0215a9b4(void);
extern "C" void func_ov001_0215a954(void);

struct Struct_02153994 { char pad[0x3c]; int flag; };
extern struct Struct_02153994 data_ov001_02165828;

// USA: func_ov001_02153994
extern "C" ARM int func_ov001_02153994(void) {
    func_ov017_021d4ccc(&data_ov001_02165828);
    if (data_ov001_02165828.flag == 0) {
        func_ov001_0215a9b4();
    }
    if (data_ov001_02165828.flag == 0) return 0;
    func_ov001_0215a954();
    return 1;
}
