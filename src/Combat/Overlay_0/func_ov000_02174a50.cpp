#include <globaldefs.h>

struct State0xc0cc;
void CachedTextLabel_Reset(struct State0xc0cc* obj);
extern "C" void func_ov000_0216fe9c(void* obj);
extern "C" void func_ov000_021710ac(void* obj, int combatantId, int flag);
extern "C" void func_ov000_02174b14(void* obj);
extern int data_ov000_02183ff0;

struct Struct_ov000_02174a50 {
    char unknown_0_[0x4c];
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x488 - 0x50];
#else
    char unknown1_50_[0x448 - 0x50];
#endif
};

// USA: func_ov000_02174a50
extern "C" ARM void func_ov000_02174a50(void* arg0, int arg1) {
    int var0 = (arg1 >= 0 && arg1 <= 3) ? 1 : 0;
    if (!var0) {
        return;
    }
    struct Entry02174a50* table = (struct Entry02174a50*)((char*)obj + 0x958);
    for (int i = 0; i < 4; i++) {
        signed char e = *(signed char*)((char*)obj + i + 0x6c);
        struct Entry02174a50* entry = table + e;
        if (combatantId == entry->field4c) {
            CachedTextLabel_Reset((struct State0xc0cc*)((char*)entry + 0x50));
#if defined(jpn)
            enum { Enum_ov000_02174a50_104 = 0x88 };
#else
            enum { Enum_ov000_02174a50_104 = 0x68 };
#endif
            CachedTextLabel_Reset((struct State0xc0cc*)((char*)entry + stateOffset));
            func_ov000_0216fe9c((char*)entry + 0x8);
            func_ov000_021710ac(entry, -1, 0);
            data_ov000_02183ff0 -= 1;
            func_ov000_02174b14(arg0);
            if (data_ov000_02183ff0 <= 0) {
                data_ov000_02183ff0 = 1;
            }
            return;
        }
    }
}
