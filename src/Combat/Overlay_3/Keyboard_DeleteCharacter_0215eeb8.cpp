#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int size);
extern "C" int Font_EncodeText(void* a, void* b, int flag);
extern "C" void Font_DecodeText(void* a, void* b, int flag);

struct Obj0215eeb8 {
    char pad0[8];
    void* field8;
    char padc[4];
    int field10;
    char pad14[0x1f - 0x14];
    unsigned char field1f;
};

// Overlay 3, originally func_ov003_0215eeb8 (USA/EUR 0x0215eeb8; JPN not identified)
extern "C" ARM int Keyboard_DeleteCharacter(struct Obj0215eeb8* obj) {
    void* target = obj->field8;
    unsigned char flag = obj->field1f;
    char buf[0x100];
    int result;

    __clear(buf, 0x100);
    int len = Font_EncodeText(target, buf, flag);
    if (len == 0) {
        result = 9;
    } else {
        buf[len - 1] = 0;
        memset(target, 0, obj->field10);
        Font_DecodeText(buf, target, flag);
        result = 8;
    }
    return result;
}
