#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02176468_4096 = 0xf7c };
enum { Enum_ov003_02176468_4094 = 0xf7a };
enum { Enum_ov003_02176468_4088 = 0xf74 };
enum { Enum_ov003_02176468_2188 = 0x808 };
enum { Enum_ov003_02176468_4098 = 0xf7e };
enum { Enum_ov003_02176468_2204 = 0x818 };
enum { Enum_ov003_02176468_54 = 0x2a };
#else
enum { Enum_ov003_02176468_4096 = 0x1000 };
enum { Enum_ov003_02176468_4094 = 0xffe };
enum { Enum_ov003_02176468_4088 = 0xff8 };
enum { Enum_ov003_02176468_2188 = 0x88c };
enum { Enum_ov003_02176468_4098 = 0x1002 };
enum { Enum_ov003_02176468_2204 = 0x89c };
enum { Enum_ov003_02176468_54 = 0x36 };
#endif

struct Struct_0207fdcc_2;
extern "C" void func_02080c04(struct Struct_0207fdcc_2* arg0, int arg1);
extern "C" void func_020813ec(void* arg0, int arg1);

struct Struct_02081f20_2;
extern "C" void func_0208203c(struct Struct_02081f20_2* arg0);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

struct Struct_020e280c;
extern "C" void func_020e280c(struct Struct_020e280c* arg0, void* arg1);

// USA: func_ov003_02176468  (semantic: ResetElementFieldsAndDispatch_02176468)
extern "C" ARM void func_ov003_02176468(unsigned char* self) {
    *(short*)(self + kRegionffe) = 1;
    *(short*)(self + kRegion1000) = *(short*)(self + kRegion1002) = 2;
    *(short*)((char*)(*(struct Obj2081**)(self + kRegion89c)) + kRegion36) = *(short*)(self + kRegion1002);
    func_020813ec(*(struct Obj2081**)(self + kRegion89c), *(short*)(self + kRegionffe));
    ResetWithSub0208203c((struct Obj0208203c*)(self + kRegion88c));
    *(void**)(self + kRegionff8) = 0;
    SePlayer_Play(&g_sePlayer, 5, 0);
    if (*(void**)self == 0) {
        return;
    }
    func_02080c04(*(struct Struct_0207fdcc_2**)(arg0 + Enum_ov003_02176468_2204), *(short*)(arg0 + Enum_ov003_02176468_4094));
    func_020e280c((struct Struct_020e280c*)(*(void**)arg0), (void*)-1);
}
