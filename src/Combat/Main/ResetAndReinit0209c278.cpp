#include <globaldefs.h>
void InitActorContext0209c20c(struct Actor0209c20c*);

void SoundPlayer_Reset(void*);

// USA: func_0209c278
ARM void ResetAndReinit0209c278(void* obj) {
    InitActorContext0209c20c((struct Actor0209c20c*)(obj));
    SoundPlayer_Reset(obj);
}
