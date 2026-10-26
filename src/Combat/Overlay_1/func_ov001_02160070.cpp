#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" float func_ov017_021d6110(void*);

struct Struct_0203cec4;
struct Struct_0203fc5c;
extern "C" void func_0203cec4(struct Struct_0203cec4* obj, int enable);
extern "C" ARM int func_0203fc5c(struct Struct_0203fc5c* obj, float value);

struct Struct_ov001_02165880_39 { void* unused0; char* base; };
extern Struct_ov001_02165880_39 data_ov001_02165880;
extern int data_ov001_021657db;

struct Struct_ov001_02160070 { int word0; char pad[8]; void* fieldC; };
struct Struct_ov001_02160070_2 { char pad[0x14]; void* field14; };

// USA: func_ov001_02160070
extern "C" ARM int func_ov001_02160070(char* obj) {
    int idx = func_ov017_021d60f4(obj);
    float f = func_ov017_021d6110(obj + 8);
    Struct_ov001_02160070* table = (Struct_ov001_02160070*)data_ov001_02165880.base;
    int type = table[idx].word0;
    if (type == 2 || type == 6) {
        Struct_ov001_02160070_2* member = 0;
        if (table) member = (Struct_ov001_02160070_2*)table[idx].fieldC;
        if (member == NULL) return 0;
        if (member->field14 != NULL) func_0203cec4((struct Struct_0203cec4*)member->field14, 1);
        if (member->field14 != NULL) func_0203fc5c((struct Struct_0203fc5c*)member->field14, f);
    } else if (type == 1 || type == 0 || type == 4 || type == 5) {
        void* member2 = 0;
        if (table) member2 = table[idx].fieldC;
        if (member2 == NULL) return 0;
        ((Object3D*)member2)->SetAnimationByName((char const*)&data_ov001_021657db, 0);
    }
    return 1;
}
