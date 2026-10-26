#include <globaldefs.h>


extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

struct Struct_020a8304_3 { unsigned char byte0; unsigned char unknown_1_; char pad[0x2c - 2]; };
struct Struct_020a8304 {
    struct Struct_020a8304_3* arr;
    char pad4[2];
    unsigned short count;
};

// USA: func_020a8458
extern "C" ARM struct Struct_020a8304_3* func_020a8458(struct Struct_020a8304* obj) {
    void* ctx = Scenario_GetInstance();
    unsigned char var1 = 0xff;
    int var2 = 0;
    for (int i = 0; i < obj->count; i++) {
        struct Struct_020a8304_3* e = (struct Struct_020a8304_3*)((char*)obj->arr + i * 0x2c);
        if (e->unknown_1_ == 0xff) {
            if (e->byte0 < var1) {
                if (Scenario_TestFlag((int)ctx, (unsigned char*)ctx + 0x8c, e->byte0 + 0x200)) {
                    var1 = e->byte0;
                    var2 = i & 0xff;
                }
            }
        }
    }
    return (var1 != 0xff) ? (struct Struct_020a8304_3*)((char*)obj->arr + var2 * 0x2c) : 0;
}
