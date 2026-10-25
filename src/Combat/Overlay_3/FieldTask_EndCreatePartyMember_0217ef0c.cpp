#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj0217ef0c { char pad0; unsigned char field1; };

extern "C" void func_ov003_0217e67c(void*);

// Overlay 3, originally InitField1_0217ef0c (USA/EUR 0x0217ef0c, JPN 0x0217dc10)
ARM void FieldTask_EndCreatePartyMember(struct Obj0217ef0c* obj) {
    func_ov003_0217e67c(obj);
    obj->field1 = 1;
}
