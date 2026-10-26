#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02174550_4174 = 0xfca };
enum { Enum_ov003_02174550_4175 = 0xfcb };
enum { Enum_ov003_02174550_4159 = 0xfbb };
enum { Enum_ov003_02174550_4088 = 0xf74 };
enum { Enum_ov003_02174550_2188 = 0x808 };
enum { Enum_ov003_02174550_4166 = 0xfc2 };
enum { Enum_ov003_02174550_4158 = 0xfba };
enum { kRegion89c = 0x818 };
#else
enum { Enum_ov003_02174550_4174 = 0x104e };
enum { Enum_ov003_02174550_4175 = 0x104f };
enum { Enum_ov003_02174550_4159 = 0x103f };
enum { Enum_ov003_02174550_4088 = 0xff8 };
enum { Enum_ov003_02174550_2188 = 0x88c };
enum { Enum_ov003_02174550_4166 = 0x1046 };
enum { Enum_ov003_02174550_4158 = 0x103e };
enum { kRegion89c = 0x89c };
#endif


struct Struct_02081f20_2;
struct Struct_0207fe44;
struct Struct_020e28dc;
struct Struct_020e25e8;

extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);
extern "C" void func_0207fe44(struct Struct_0207fe44* obj);
extern "C" void func_ov003_021749c0(char* base);
extern "C" int func_020e28dc(struct Struct_020e28dc* o);
extern "C" void func_020e25e8(struct Struct_020e25e8* obj);
extern "C" void func_ov003_02175cb0(char* base, int flag);

// USA: func_ov003_02174550
extern "C" ARM void func_ov003_02174550(char* base) {
    if (*(unsigned char*)(base + Enum_ov003_02174550_4174) != 0) return;
    *(unsigned char*)(base + Enum_ov003_02174550_4174) = 1;

    MessageSystem_Reset((char*)MessageSystem_GetInstance());
    func_0208203c((struct Struct_02081f20_2*)(base + Enum_ov003_02174550_2188));

    *(int*)(base + Enum_ov003_02174550_4088) = 0;
    func_0207fe44(*(struct Struct_0207fe44**)(base + kRegion89c));

    *(unsigned char*)(base + Enum_ov003_02174550_4158) = 9;
    *(unsigned char*)(base + Enum_ov003_02174550_4159) = 0;
    if (*(unsigned short*)(base + Enum_ov003_02174550_4166) & 0x80) {
        func_ov003_021749c0(base);
    }

    if (*(struct Struct_020e28dc**)base != NULL && func_020e28dc(*(struct Struct_020e28dc**)base)) {
        func_020e25e8((struct Struct_020e25e8*)(*(void**)base));
    }

    if (*(unsigned char*)(base + Enum_ov003_02174550_4175) != 0) {
        func_ov003_02175cb0(base, 1);
    }
}
