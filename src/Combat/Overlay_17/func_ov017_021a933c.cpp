#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { Enum_ov017_021a933c_632 = 0x208, Enum_ov017_021a933c_6578 = 0x17e2, Enum_ov017_021a933c_2460 = 0x86c };
#else
enum { Enum_ov017_021a933c_632 = 0x278, Enum_ov017_021a933c_6578 = 0x19b2, Enum_ov017_021a933c_2460 = 0x99c };
#endif

struct Struct_ov017_021a933c {
    char unknown0[0x14];
    int unknown_14_;
    char unknown18[Enum_ov017_021a933c_632 - 0x18];
    Container020e0310 messages;
};

struct MessageSelectionController {
    char unknown0[Enum_ov017_021a933c_2460];
    int mode;
    char unknown_9a0_[Enum_ov017_021a933c_6578 - Enum_ov017_021a933c_2460 - sizeof(int)];
    unsigned char unknown_19b2_;
};

extern "C" MessageSelectionController* MessageSystem_GetInstance(void);
extern "C" int KeyTable_Get(struct Container020e0310*, int);
#if !defined(jpn)
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#endif

// USA: func_ov017_021a933c
extern "C" ARM void func_ov017_021a933c(Struct_ov017_021a933c* selection, int key) {
    MessageSelectionController* controller = MessageSystem_GetInstance();
    if (key <= 0xc7 && key >= 0x64) {
        if (selection->unknown_14_ == 1) key += 0x64;
    }
#if defined(jpn)
    func_0204500c(controller, (const char*)KeyTable_Get(&selection->messages, (short)key), 0);
#else
    func_0204500c(controller, (const char*)KeyTable_Get(&selection->messages, (short)key), 0, 0xe3);
#endif

    if (key <= 0x12b && key >= 0x64) {
        controller->unknown_19b2_ = 1;
    } else {
        controller->unknown_19b2_ = 0;
    }
    if (key > 0x12b || key < 0x64) return;
    if (selection->unknown_14_ == 0) {
        controller->mode = 2;
    } else {
        controller->mode = 1;
    }
}
