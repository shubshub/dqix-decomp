#include <globaldefs.h>

extern "C" void func_020c99c8(void* out);

struct Struct0200fb08 { unsigned char pad[5]; unsigned char field5; };

// USA: _Z21GameState_GetLanguageP14Struct0200fb08
// EUR: _Z21GameState_GetLanguageP14Struct0200fb08
// Main, originally NormalizeField5_0200fb08 (USA 0x0200fb08, EUR 0x0200fb10; JPN not identified)
ARM unsigned char GameState_GetLanguage(Struct0200fb08* obj) {
    unsigned char buf[0x54];
    unsigned char v;
    func_020c99c8(buf);
    v = buf[0];
    obj->field5 = v;
#if defined(eur)
    if (v != 2 && v != 3 && v != 4 && v != 5) obj->field5 = 1;
#else
    if (v != 2 && v != 5) obj->field5 = 1;
#endif
    return obj->field5;
}
