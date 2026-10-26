#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

extern "C" void SprSprite_Unload(struct Foo02048004* obj);

struct Struct_ov000_021820fc { unsigned char a; unsigned char b; short c; short d; };
extern "C" void func_ov000_021820fc(struct Struct_ov000_021820fc* obj);

// USA: func_ov000_021823a4
extern "C" ARM void func_ov000_021823a4(char* p) {
    int i;
    for (i = 0; i < 13; i++) {
        SprSprite_Unload((struct Foo02048004*)(p + i * 0x88));
    }
    func_ov000_021820fc((struct Struct_ov000_021820fc*)(p + 0x6e8));
}
