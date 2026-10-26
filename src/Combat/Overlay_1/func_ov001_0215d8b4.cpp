#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
extern "C" void* func_ov001_021590c4(void* ctx);
#else
extern "C" void* func_ov001_021590c4(void* ctx);
#endif

struct Struct_ov001_02165880_30 { char pad[0x24]; void* field24; };
extern Struct_ov001_02165880_30 data_ov001_02165880;

// USA: func_ov001_0215d8b4
extern "C" ARM int func_ov001_0215d8b4(void) {
    func_ov001_021590c4(data_ov001_02165880.field24);
    return 1;
}
