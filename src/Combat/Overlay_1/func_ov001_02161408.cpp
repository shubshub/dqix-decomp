#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void* obj);
struct Struct_02040668;
extern "C" void func_02040668(struct Struct_02040668* obj);
struct Struct_020406b0;
extern "C" void func_020406b0(struct Struct_020406b0* obj);

struct Struct_ov001_02161408 { int type; int val; int pad2; void* child; };
struct Struct_ov001_02165880_44 { char pad[4]; Struct_ov001_02161408* table; };
extern struct Struct_ov001_02165880_44 data_ov001_02165880;

// USA: func_ov001_02161408
extern "C" ARM int func_ov001_02161408(void* self) {
    int idx = func_ov017_021d60f4(self);
    int flag = func_ov017_021d60f4((char*)self + 0x8);
    switch (data_ov001_02165880.table[idx].type) {
        case 0:
        case 1:
        case 4:
        case 5: {
            void* child = data_ov001_02165880.table[idx].child;
            if (child == 0) return 0;
            if (flag != 0) {
                ((Object3D*)((unsigned char*)child))->DisableFlag(1);
            } else {
                ((Object3D*)((unsigned char*)child))->EnableFlag(1);
            }
            break;
        }
        case 6: {
            void* c = data_ov001_02165880.table[idx].child;
            if (c == 0 || *(void**)((char*)c + 0x18) == 0) return 0;
            void* var4 = *(void**)((char*)c + 0x18);
            if (flag != 0) {
                ((Object3D*)((unsigned char*)var4))->DisableFlag(1);
                func_02040668((struct Struct_02040668*)data_ov001_02165880.table[idx].child);
            } else {
                ((Object3D*)((unsigned char*)var4))->EnableFlag(1);
                func_020406b0((struct Struct_020406b0*)data_ov001_02165880.table[idx].child);
            }
            break;
        }
        case 2: {
            void* child = data_ov001_02165880.table[idx].child;
            if (child == 0) return 0;
            if (flag != 0) {
                func_02040668((struct Struct_02040668*)child);
            } else {
                func_020406b0((struct Struct_020406b0*)child);
            }
            break;
        }
        default:
            break;
    }
    return 1;
}
