#include <globaldefs.h>
#if defined(jpn)
enum { kMiddlePadding = 0x184 };
#else
enum { kMiddlePadding = 0x190 };
#endif

int GameObject_IsClimbingLadder(char*);

struct Bytes02033b88;
int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);

struct Obj020397cc {
    char unknown0[0xc1];
    unsigned char unknownC1 : 2;      // bit 1 also skips the stop; set by func_ov017_02190884 and GameObject_StartGestureSequence
    char unknownC2[kMiddlePadding];
    unsigned char controlEnabled;     // +0x252: GameObject_HandleWalkInput ignores the D-pad and touch while it is 0
    unsigned char controlPending;     // +0x253: GameObject_EnableControl sets it, CopyByteField0x253To0x252 applies it
};

// Main, originally CancelPendingAction020397cc (USA 0x020397cc, EUR 0x020397dc, JPN 0x02039224)
ARM void GameObject_DisableControl(struct Obj020397cc* object, int stopWalking) {
    // GameObject_IsClimbingLadder: whether a ladder climb is active; motion state 0 stands still
    if (stopWalking && object->controlEnabled && GameObject_IsClimbingLadder((char*)(object)) == 0 && (object->unknownC1 & 2) == 0) {
        GameObject_ForceMotionState((struct Bytes02033b88*)object, 0);
    }
    object->controlPending = 0;
    object->controlEnabled = 0;
}
