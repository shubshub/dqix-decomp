#include <globaldefs.h>

void SoundPlayer_Reset(void* obj);
struct Obj_0205e88c;
void SePlayer_Init(struct Obj_0205e88c*);

// Main, originally ResetObjectState0205e8d4 (USA 0x0205e8d4, EUR 0x0205e8e4, JPN 0x0205fbc0)
ARM void SePlayer_Reset(void* obj) {
    SoundPlayer_Reset(obj);
    SePlayer_Init((struct Obj_0205e88c*)obj);
}
