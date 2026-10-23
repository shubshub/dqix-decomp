#include <globaldefs.h>

void VramState_Restore(char* obj);
void VramState_Save(char* obj);
extern "C" void func_020553ec(void* obj, int a, int b, int c, int d);

struct Obj020555a0 {
    int field0;
    int field4;
    char* field8;
    int fieldc;
    int field10;
};

// USA: func_020555a0
ARM void MaybeSwapPairTables020555a0(struct Obj020555a0* obj) {
    if (obj->field4 != 0 && obj->fieldc != 0 && obj->field10 != 0 && obj->field8 != 0) {
        VramState_Restore(obj->field8);
        func_020553ec(obj, obj->field0, obj->field4, obj->fieldc, obj->field10);
        VramState_Save(obj->field8);
    }
    obj->field8 = 0;
    obj->fieldc = 0;
    obj->field10 = 0;
}
