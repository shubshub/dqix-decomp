#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Struct_ov000_021820fc { unsigned char a; unsigned char b; short c; short d; };
extern "C" void func_ov000_021820fc(struct Struct_ov000_021820fc* obj);

struct Struct_ov000_02161e30_6 {
    Foo02048004 resources[13];
    Struct_ov000_021820fc state;
};

// USA: func_ov000_02182114
extern "C" ARM void func_ov000_02182114(char* storage)
{
    Struct_ov000_02161e30_6* battle = (Struct_ov000_02161e30_6*)storage;
    int i;
    for (i = 0; i < 13; i++) {
        SprSprite_Init(&battle->resources[i]);
    }
    func_ov000_021820fc(&battle->state);
}
