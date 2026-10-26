#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_021785d4_4068 = 0xf60 };
enum { Enum_ov003_021785d4_4096 = 0xf7c };
enum { Enum_ov003_021785d4_2204 = 0x818 };
enum { Enum_ov003_021785d4_4088 = 0xf74 };
#else
enum { Enum_ov003_021785d4_4068 = 0xfe4 };
enum { Enum_ov003_021785d4_4096 = 0x1000 };
enum { Enum_ov003_021785d4_2204 = 0x89c };
enum { Enum_ov003_021785d4_4088 = 0xff8 };
#endif


extern "C" short func_02080468(void* obj, int id);
extern "C" void func_ov003_02178548(void* self);
extern "C" void func_ov003_021767ec(void* self);
extern "C" void func_ov003_021769ec(void* self);
extern "C" void func_ov003_02176ed4(void* self);
extern "C" void func_ov003_02176f94(void* self);

// USA: func_ov003_021785d4
extern "C" ARM void func_ov003_021785d4(char* obj) {
    int flags = *(int*)(obj + Enum_ov003_021785d4_4068);
    int delta = 0;
    if (flags & 0x10) {
        delta = 1;
    } else if (flags & 0x20) {
        delta -= 1;
    }

    *(short*)(obj + Enum_ov003_021785d4_4096 + 0x14) = *(short*)(obj + Enum_ov003_021785d4_4096 + 0x14) + delta;
    if (*(short*)(obj + Enum_ov003_021785d4_4096 + 0x16) <= *(short*)(obj + Enum_ov003_021785d4_4096 + 0x14)) {
        *(short*)(obj + Enum_ov003_021785d4_4096 + 0x14) = 0;
    }
    if (*(short*)(obj + Enum_ov003_021785d4_4096 + 0x14) < 0) {
        *(short*)(obj + Enum_ov003_021785d4_4096 + 0x14) = *(short*)(obj + Enum_ov003_021785d4_4096 + 0x16) - 1;
    }

    if (delta != 0) {
        void* var2 = *(void**)(obj + Enum_ov003_021785d4_2204);
        short id = func_02080468(var2, 3);
        *(short*)(*(void**)(obj + Enum_ov003_021785d4_4088)) = id;
        func_ov003_02178548(obj);
        func_ov003_021767ec(obj);
        func_ov003_021769ec(obj);
        func_ov003_02176ed4(obj);
        func_ov003_02176f94(obj);
    }

    func_ov003_02178548(obj);
    if (*(short*)(obj + Enum_ov003_021785d4_4096) == *(short*)(*(void**)(obj + Enum_ov003_021785d4_4088))) {
        return;
    }
    func_ov003_021767ec(obj);
    func_ov003_021769ec(obj);
    func_ov003_02176ed4(obj);
    func_ov003_02176f94(obj);
}
