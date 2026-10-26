#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0217a14c_4068 = 0xf60 };
enum { Enum_ov003_0217a14c_4096 = 0xf7c };
enum { Enum_ov003_0217a14c_4088 = 0xf74 };
#else
enum { Enum_ov003_0217a14c_4068 = 0xfe4 };
enum { Enum_ov003_0217a14c_4096 = 0x1000 };
enum { Enum_ov003_0217a14c_4088 = 0xff8 };
#endif


extern "C" void func_ov003_02179ff0(void* obj);
extern "C" void func_ov003_02177dd4(void* obj);
extern "C" void func_ov003_021769ec(void* obj);

// USA: func_ov003_0217a14c
extern "C" ARM void func_ov003_0217a14c(void* p) {
    char* obj = (char*)p;
    int flags = *(int*)(obj + Enum_ov003_0217a14c_4068);
    int delta = 0;
    if (flags & 0x10) {
        delta = 1;
    } else if (flags & 0x20) {
        delta -= 1;
    }

    *(short*)(obj + Enum_ov003_0217a14c_4096 + 0x14) = *(short*)(obj + Enum_ov003_0217a14c_4096 + 0x14) + delta;
    if (*(short*)(obj + Enum_ov003_0217a14c_4096 + 0x16) <= *(short*)(obj + Enum_ov003_0217a14c_4096 + 0x14)) {
        *(short*)(obj + Enum_ov003_0217a14c_4096 + 0x14) = 0;
    }
    if (*(short*)(obj + Enum_ov003_0217a14c_4096 + 0x14) < 0) {
        *(short*)(obj + Enum_ov003_0217a14c_4096 + 0x14) = *(short*)(obj + Enum_ov003_0217a14c_4096 + 0x16) - 1;
    }

    if (delta != 0) {
        func_ov003_02179ff0(obj);
        func_ov003_02177dd4(obj);
        if (*(short*)(obj + Enum_ov003_0217a14c_4096 + 0xc) == 0x77) {
            func_ov003_021769ec(obj);
        }
    }
    func_ov003_02179ff0(obj);

    if (*(short*)(obj + Enum_ov003_0217a14c_4096) == **(short**)(obj + Enum_ov003_0217a14c_4088)) return;
    func_ov003_02177dd4(obj);
    if (*(short*)(obj + Enum_ov003_0217a14c_4096 + 0xc) != 0x77) return;
    func_ov003_021769ec(obj);
}
