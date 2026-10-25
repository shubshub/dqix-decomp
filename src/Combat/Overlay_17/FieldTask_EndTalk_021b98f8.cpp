#include <globaldefs.h>

extern "C" void func_ov017_021b8d80(void*);

// Overlay 17, originally TailCall_021b8d80_021b98f8 (USA/EUR 0x021b98f8, JPN 0x021b9df4)
ARM void FieldTask_EndTalk(void* self) {
    func_ov017_021b8d80(self);
}
