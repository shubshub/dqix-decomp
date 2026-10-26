#include <globaldefs.h>
#if defined(jpn)
enum { kRegion12c0 = 0x1150 };
enum { Enum_ov003_0216d53c_1040 = 0x428 };
enum { Enum_ov003_0216d53c_3868 = 0xda0 };
#else
enum { kRegion12c0 = 0x12c0 };
enum { Enum_ov003_0216d53c_1040 = 0x410 };
enum { Enum_ov003_0216d53c_3868 = 0xf1c };
#endif


extern "C" int MessageSystem_GetInstance();
extern "C" void func_0204359c(void* obj, int count);
extern "C" void func_020439b0(void* obj, int flag);

struct Obj0205d2bc;
extern "C" void Window_TransferLayers(Obj0205d2bc* obj);

extern "C" void func_ov003_02170280(void* obj);
extern "C" void func_ov003_0215ca68(void* obj);
extern "C" void func_ov003_02173f04(void* obj);

struct Struct_ov003_0216d53c {
    char pad0[4];
    short field4;
    short field6;
    char pad1[kRegion12c0 - 0x8];
    void* unknown_12c0_;
};

// USA: func_ov003_0216d53c
extern "C" ARM void func_ov003_0216d53c(Struct_ov003_0216d53c* obj) {
    int g = MessageSystem_GetInstance();
    func_0204359c((void*)g, 2);
    func_020439b0((void*)g, 0);

    void* p = obj->unknown_12c0_;
    if (p) {
        if (obj->field6 == 0 || obj->field6 == 1 || obj->field4 == 2) {
            Window_TransferLayers((Obj0205d2bc*)p);
        }
    }

    if (obj->field4 == 4) {
        if (obj->field6 > 0) {
            func_ov003_02170280((char*)obj + Enum_ov003_0216d53c_1040);
            return;
        }
    }
    if (obj->field4 == 3) {
        if (obj->field6 == 1) {
            func_ov003_0215ca68((char*)obj + 0x14);
        }
        return;
    }
    if (obj->field4 == 5 && obj->field6 == 6) {
        func_ov003_02173f04((char*)obj + Enum_ov003_0216d53c_3868);
    }
    return;
}
