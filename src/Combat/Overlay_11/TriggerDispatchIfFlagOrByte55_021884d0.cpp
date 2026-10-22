#include <globaldefs.h>
#include "Input/Input.h"

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
struct Obj02184c68;
extern "C" void func_ov011_02184c68(struct Obj02184c68* obj, void* val);

extern int g_sePlayer;

// USA: func_ov011_021884d0  (semantic: TriggerDispatchIfFlagOrByte55_021884d0)
extern "C" ARM int func_ov011_021884d0(struct Obj02184c68* obj) {
    int state = 0;
    if (g_keyManager.TestKeysPressed(0x7f3) || g_touchInput.pressed_) {
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        state = 1;
    }
    func_ov011_02184c68(obj, (void*)state);
    return 1;
}
