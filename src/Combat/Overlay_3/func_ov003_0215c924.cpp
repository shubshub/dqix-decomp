#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0215c924_956 = 0x3d4 };
enum { Enum_ov003_0215c924_1012 = 0x40c };
enum { Enum_ov003_0215c924_1013 = 0x40d };
enum { kRegionValue98_B0 = 0xb0 };
enum { kRegionValue9C_B4 = 0xb4 };
enum { kRegionValue3BA_3D2 = 0x3d2 };
#else
enum { Enum_ov003_0215c924_956 = 0x3bc };
enum { Enum_ov003_0215c924_1012 = 0x3f4 };
enum { Enum_ov003_0215c924_1013 = 0x3f5 };
enum { kRegionValue98_B0 = 0x98 };
enum { kRegionValue9C_B4 = 0x9c };
enum { kRegionValue3BA_3D2 = 0x3ba };
#endif

extern "C" void func_ov003_0215dc20(void* obj);

struct Struct_ov003_0215c924;
extern "C" int func_ov003_0215e27c(struct Struct_ov003_0215c924* obj, int amount);

struct Struct_ov003_0215c924_2;
extern "C" void func_ov003_0215e3fc(struct Struct_ov003_0215c924_2* self);

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
extern "C" int WindowPane_IsReady(unsigned char* obj);
extern "C" void TouchGrid_SetTouchedCell(void* obj, int value);
extern "C" int Window_Update(void* p, int val);

typedef void (*Type_ov003_0215c924)(void*, int);
struct Struct_ov003_0217fe94 {
    Type_ov003_0215c924 fn;
    int flags;
};
extern struct Struct_ov003_0217fe94 data_ov003_0217fe94[];

// USA: func_ov003_0215c924
extern "C" ARM int func_ov003_0215c924(unsigned char* self, int amount) {
    if (self[Enum_ov003_0215c924_956] == 5) {
        return 1;
    }

    func_ov003_0215dc20(self);

    if (func_ov003_0215e27c((struct Struct_ov003_0215c924*)self, amount) != 0) {
        return 0;
    }

    if (self[Enum_ov003_0215c924_1012] != 0 && self[Enum_ov003_0215c924_1013] == 0) {
        func_ov003_0215e3fc((struct Struct_ov003_0215c924_2*)self);
        return 0;
    }

    if (self[Enum_ov003_0215c924_956] != 0) {
        struct Elem_0205d81c* elem = Window_GetActivePane((struct Struct_0205d81c*)(self + kRegionValue98_B0));
        if (elem != 0 && WindowPane_IsReady((unsigned char*)elem) != 0 && (*((unsigned char*)elem + 0xc5) & 2) == 0) {
            TouchGrid_SetTouchedCell(self + kRegionValue9C_B4, -1);
        }
        self[kRegionValue3BA_3D2] = (unsigned char)Window_Update(self + kRegionValue98_B0, amount);
    }

    unsigned char idx = self[Enum_ov003_0215c924_956];
    if (data_ov003_0217fe94[idx].fn != 0) {
        struct Struct_ov003_0217fe94* entry = &data_ov003_0217fe94[idx];
        void* obj = self + (entry->flags >> 1);
        Type_ov003_0215c924 fn;
        if (entry->flags & 1) {
            fn = *(Type_ov003_0215c924*)(*(int*)obj + (int)entry->fn);
        } else {
            fn = entry->fn;
        }
        fn(obj, amount);
    }
    return 0;
}
