#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020675fc_2456 = 0x868, Enum_020675fc_288 = 0x7e, Enum_020675fc_90 = 0x5c };
#else
enum { Enum_020675fc_2456 = 0x998, Enum_020675fc_288 = 0x120, Enum_020675fc_90 = 0x5a };
#endif

#include <GameState/GameState.h>
#include <Combat/EntryGetterTypes.h>
#include "Resource/GameResources.h"

struct Struct_0203dce4_2;
struct Node020406f8;
struct StructAt020473c8;
struct Struct_0203de84 { unsigned int v[3]; };
struct Vec3copy0202ec84 { unsigned int v[3]; };
union Struct_020675fc {
    Struct_0203de84 selected;
    Vec3copy0202ec84 copied;
};
struct Struct_020675fc_2 {
    unsigned char padding[Enum_020675fc_2456];
    int active;
    unsigned char unknown_99c_[0xe9c];
    int entryId;
    unsigned char unknown_183c_[Enum_020675fc_288];
    unsigned char index;
    unsigned char unknown_195d_[Enum_020675fc_90];
    unsigned char enabled;
};
extern "C" Struct_0203dce4_2* func_0203cf4c();
extern "C" Struct_0203dce4* func_0203dce4(Struct_0203dce4_2*, int);
extern "C" void func_020406f8(Struct_0203de84*, Node020406f8*);
extern "C" int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" void func_020473c8(StructAt020473c8*, int);
extern unsigned char data_020e7e08[];

// USA: func_020675fc
extern "C" ARM void func_020675fc(Struct_020675fc_2* owner) {
    if (!owner->active) return;
    Struct_0203dce4* entry = func_0203dce4(func_0203cf4c(), owner->entryId);
    if (entry && owner->enabled) {
        GameResources* resources = GetGameResources();
        void* view = GameState::GetInstance()->GetCamera();
        int x;
        int y;
        Vec3copy0202ec84 copied;
        Struct_020675fc vector;
        func_020406f8(&vector.selected, (Node020406f8*)entry);
        copied = vector.copied;
        Camera_WorldToScreen(view, &copied, &x, &y);
        x -= 12;
        y -= 62;
        int scaledX = x << 12;
        Foo02048004* output = &resources->substruct_array_2b90[data_020e7e08[owner->index]];
        int scaledY = y << 12;
        output->position.x = scaledX;
        output->position.y = scaledY;
        output->position.z = 0;
        func_020473c8((StructAt020473c8*)output, 1);
    }
}
