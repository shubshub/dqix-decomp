#include <globaldefs.h>

union Struct_0203a914 { int i; float f; };
struct Struct_ov001_021638cc { int type; Struct_0203a914 value; };

extern "C" int func_ov017_021d60f4(Struct_ov001_021638cc* a);
extern "C" void func_0205ebb4(void* obj, void* target, int arg);
extern "C" void NNS_SndHandleInit(int* field);

extern int data_ov001_02165958[16];
extern int g_sePlayer;

// USA: func_ov001_021638cc
extern "C" ARM int func_ov001_021638cc(Struct_ov001_021638cc* obj, int mode) {
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
        arg = func_ov017_021d60f4((Struct_ov001_021638cc*)((char*)obj + 8));
    }
    func_0205ebb4(&g_sePlayer, slot, arg);
    NNS_SndHandleInit(slot);
    return 1;
}
