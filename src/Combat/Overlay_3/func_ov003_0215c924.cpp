#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0215c924_956 = 0x3d4 };
enum { Enum_ov003_0215c924_1012 = 0x40c };
enum { Enum_ov003_0215c924_1013 = 0x40d };
enum { Enum_ov003_0215c924_152 = 0xb0 };
enum { Enum_ov003_0215c924_156 = 0xb4 };
enum { Enum_ov003_0215c924_954 = 0x3d2 };
#else
enum { Enum_ov003_0215c924_956 = 0x3bc };
enum { Enum_ov003_0215c924_1012 = 0x3f4 };
enum { Enum_ov003_0215c924_1013 = 0x3f5 };
enum { Enum_ov003_0215c924_152 = 0x98 };
enum { Enum_ov003_0215c924_156 = 0x9c };
enum { Enum_ov003_0215c924_954 = 0x3ba };
#endif

extern "C" void func_ov003_0215dc20(void* arg0);

struct Struct_ov003_0215c924;
extern "C" int func_ov003_0215e27c(struct Struct_ov003_0215c924* arg0, int arg1);

struct Struct_ov003_0215c924_2;
extern "C" void func_ov003_0215e3fc(struct Struct_ov003_0215c924_2* arg0);

struct Struct_0205d81c;
struct Elem_0205d81c;
extern struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
extern int WindowPane_IsReady(unsigned char* obj);
extern void TouchGrid_SetTouchedCell(void* obj, int value);
extern "C" int Window_Update(void* p, int val);

typedef void (*Type_ov003_0215c924)(void*, int);
struct Struct_ov003_0217fe94 {
    Type_ov003_0215c924 unknown_0_;
    int unknown_4_;
};
extern struct Struct_ov003_0217fe94 data_ov003_0217fe94[];

// USA: func_ov003_0215c924
extern "C" ARM int func_ov003_0215c924(unsigned char* arg0, int arg1) {
    if (arg0[Enum_ov003_0215c924_956] == 5) {
        return 1;
    }

    func_ov003_0215dc20(arg0);

    if (func_ov003_0215e27c((struct Struct_ov003_0215c924*)arg0, arg1) != 0) {
        return 0;
    }

    if (arg0[Enum_ov003_0215c924_1012] != 0 && arg0[Enum_ov003_0215c924_1013] == 0) {
        func_ov003_0215e3fc((struct Struct_ov003_0215c924_2*)arg0);
        return 0;
    }

    if (self[kRegionValue3BC_3D4] != 0) {
        struct Elem_0205d81c* elem = Window_GetActivePane((struct Struct_0205d81c*)(self + kRegionValue98_B0));
        if (elem != 0 && WindowPane_IsReady((unsigned char*)elem) != 0 && (*((unsigned char*)elem + 0xc5) & 2) == 0) {
            TouchGrid_SetTouchedCell(self + kRegionValue9C_B4, -1);
        }
        self[kRegionValue3BA_3D2] = (unsigned char)Window_Update(self + kRegionValue98_B0, amount);
    }

    unsigned char var1 = arg0[Enum_ov003_0215c924_956];
    if (data_ov003_0217fe94[var1].unknown_0_ != 0) {
        struct Struct_ov003_0217fe94* var2 = &data_ov003_0217fe94[var1];
        void* var3 = arg0 + (var2->unknown_4_ >> 1);
        Type_ov003_0215c924 var4;
        if (var2->unknown_4_ & 1) {
            var4 = *(Type_ov003_0215c924*)(*(int*)var3 + (int)var2->unknown_0_);
        } else {
            var4 = var2->unknown_0_;
        }
        var4(var3, arg1);
    }
    return 0;
}
