#include <globaldefs.h>

struct Obj_0205e8ec;
void RefreshDisplayState0205e8ec(struct Obj_0205e8ec*);
void SoundPlayer_Reset(void*);

// USA: func_0205e92c
ARM void ShutdownAndReinit0205e92c(void* obj) {
    RefreshDisplayState0205e8ec((struct Obj_0205e8ec*)obj);
    SoundPlayer_Reset(obj);
}
