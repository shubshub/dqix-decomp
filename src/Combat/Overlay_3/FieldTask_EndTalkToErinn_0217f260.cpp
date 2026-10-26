#include <globaldefs.h>

struct Obj0217f260 { char pad0; unsigned char field1; };

extern "C" void func_ov003_0217f118(void*);

// Overlay 3, originally InitField1_0217f260 (USA/EUR 0x0217f260, JPN 0x0217df64)
extern "C" ARM void FieldTask_EndTalkToErinn(struct Obj0217f260* obj) {
    func_ov003_0217f118(obj);
    obj->field1 = 1;
}
