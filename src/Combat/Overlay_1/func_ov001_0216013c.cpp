#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(int id);

struct Struct_0203cec4;
extern "C" void func_0203cec4(struct Struct_0203cec4* obj, int enable);
struct Struct_0203fc5c;
extern "C" int func_0203fc5c(struct Struct_0203fc5c* obj, float value);

struct Struct_ov001_0216013c {
    int type;
    char pad[0x8];
    void* obj;
};
struct Struct_ov001_02165880_40 {
    void* unused0;
    struct Struct_ov001_0216013c* rows;
};
extern struct Struct_ov001_02165880_40 data_ov001_02165880;
extern int data_ov001_02165769;

struct Struct_ov001_0216013c_2 {
    char pad[0x14];
    void* field14;
};

// USA: func_ov001_0216013c
extern "C" ARM int func_ov001_0216013c(int id) {
    id = func_ov017_021d60f4(id);
    int type = data_ov001_02165880.rows[id].type;

    if (type == 2 || type == 6) {
        void* obj = 0;
        if (data_ov001_02165880.rows != 0) {
            obj = data_ov001_02165880.rows[id].obj;
        }
        if (obj == 0) {
            return 0;
        }
        if (((struct Struct_ov001_0216013c_2*)obj)->field14 != 0) {
            func_0203cec4((struct Struct_0203cec4*)((struct Struct_ov001_0216013c_2*)obj)->field14, 0);
        }
        if (((struct Struct_ov001_0216013c_2*)obj)->field14 != 0) {
            func_0203fc5c((struct Struct_0203fc5c*)((struct Struct_ov001_0216013c_2*)obj)->field14, 1.0f);
        }
    } else if (type == 1 || type == 0 || (unsigned int)(type - 4) <= 1) {
        void* obj2 = 0;
        if (data_ov001_02165880.rows != 0) {
            obj2 = data_ov001_02165880.rows[id].obj;
        }
        if (obj2 == 0) {
            return 0;
        }
        ((Object3D*)obj2)->SetAnimationByName((char const*)&data_ov001_02165769, 0);
    }

    return 1;
}
