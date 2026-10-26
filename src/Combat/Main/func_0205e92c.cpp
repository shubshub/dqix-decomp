#include <globaldefs.h>

struct Obj_0205e8ec;
extern "C" void func_0205e8ec(struct Obj_0205e8ec*);
extern "C" void SoundPlayer_Reset(void*);

// USA: func_0205e92c
extern "C" ARM void func_0205e92c(void* obj) {
    func_0205e8ec((struct Obj_0205e8ec*)obj);
    SoundPlayer_Reset(obj);
}
