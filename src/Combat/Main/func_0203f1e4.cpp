#include <globaldefs.h>

struct Struct_0203f0fc;
extern "C" ARM int func_0203f0fc(struct Struct_0203f0fc* obj, const char* name);
extern "C" int func_0203f138(struct Struct_0203f0fc* obj, int entry);

struct Struct_0203ca24_2 {
    char pad[0x28];
    short field28;
};

// USA: func_0203f1e4
extern "C" ARM void func_0203f1e4(struct Struct_0203ca24_2* obj, const char* name) {
    if (obj->field28 < 0) {
        return;
    }
    func_0203f138((struct Struct_0203f0fc*)obj,
                  func_0203f0fc((struct Struct_0203f0fc*)obj, name));
}
