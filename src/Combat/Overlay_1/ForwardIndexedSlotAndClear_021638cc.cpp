#include <globaldefs.h>

union Value_021638cc { int i; float f; };
struct TaggedValue_021638cc { int type; Value_021638cc value; };

extern "C" int func_ov017_021d60f4(TaggedValue_021638cc* a);
void ForwardToTargetOrDefault0205ebb4(void* obj, void* target, int arg);
void ClearField0x0_020bc078(int* field);

extern int data_ov001_02165958[16];
extern int g_sePlayer;

// USA: func_ov001_021638cc  (semantic: ForwardIndexedSlotAndClear_021638cc)
extern "C" ARM int func_ov001_021638cc(TaggedValue_021638cc* obj, int mode) {
    int idx = func_ov017_021d60f4(obj);
    if ((unsigned int)idx >= 0x10) {
        return 0;
    }
    int* slot = &data_ov001_02165958[idx];
    if (*slot == 0) {
        return 0;
    }
    int arg = 0;
    if (mode >= 2) {
        arg = func_ov017_021d60f4((TaggedValue_021638cc*)((char*)obj + 8));
    }
    ForwardToTargetOrDefault0205ebb4(&g_sePlayer, slot, arg);
    ClearField0x0_020bc078(slot);
    return 1;
}
