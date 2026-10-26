#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0216052c_40 = 0x20 };
enum { Enum_ov003_0216052c_804 = 0x20c };
enum { Enum_ov003_0216052c_808 = 0x210 };
enum { Enum_ov003_0216052c_1124 = 0x28c };
#else
enum { Enum_ov003_0216052c_40 = 0x28 };
enum { Enum_ov003_0216052c_804 = 0x324 };
enum { Enum_ov003_0216052c_808 = 0x328 };
enum { Enum_ov003_0216052c_1124 = 0x464 };
#endif

struct Struct_0207fdcc_2;

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
int HasElementByByte0xc4_020811d0(struct Obj2081* obj, int key);
void UpdateOffsetsFromEntry02080a6c(void* param0, int id, short param2, short* param3, short* param4, short* param5, short* param6);
void SetEntryFields_021604f4(char* obj, int valA, int valB, short index, unsigned char flag);

struct Struct_ov003_0216052c {
    short unknown_0_[3];
};

struct Struct_ov003_0217f3ec {
    char unknown_0_[Enum_ov003_0216052c_40];
    struct Struct_ov003_0216052c unknown_28_;
};

extern struct Struct_ov003_0217f3ec data_ov003_0217f3ec;
extern short data_ov003_0217f448[3][2];

struct Struct_ov003_0216052c_2 {
    char unknown_0_[Enum_ov003_0216052c_804];
    struct Struct_0207fdcc_2* unknown_324_;
    char unknown_328_[Enum_ov003_0216052c_1124 - Enum_ov003_0216052c_808];
    unsigned int unknown_464_;
};

// USA: func_ov003_0216052c
extern "C" ARM void func_ov003_0216052c(struct Struct_ov003_0216052c_2* arg0) {
    if (arg0->unknown_324_ == NULL) {
        return;
    }
    if (LinkSession_IsActive((int*)LinkSession_GetInstance()) != 0) {
        return;
    }
    struct Struct_0207fdcc_2* var0 = arg0->unknown_324_;
    if (!(arg0->unknown_464_ & 0x10000)) {
        return;
    }
    struct Struct_ov003_0216052c var1 = data_ov003_0217f3ec.unknown_28_;
    for (int var2 = 0; var2 < 3; var2++) {
        short var3 = var1.unknown_0_[var2];
        if (func_020811d0(var0, var3)) {
            unsigned char var4 = 1;
            for (unsigned char var5 = 0; var5 < 2; var5++) {
                short var6 = data_ov003_0217f448[var2][var5];
                if (var6 >= 0) {
                    short var7, var8, var9, var10;
                    func_02080a6c(var0, var3, var6, &var7, &var8, &var9, &var10);
#if !defined(jpn)
                    var10 = (16 - var10) >> 1;
#endif
                    short var11 = var7 + var9 + 6;
#if defined(jpn)
                    short var12 = var8 - 3;
#else
                    short var12 = var8 - var10 + 1;
#endif
                    func_ov003_021604f4((char*)arg0, var11, var12, 0, var4++);
                }
            }
            return;
        }
    }
}
