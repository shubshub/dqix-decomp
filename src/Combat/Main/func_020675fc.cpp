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
struct Struct_0203de84_2;
struct Struct_02015ef4_2;
struct Struct_0203de84 { unsigned int unknown_0_[3]; };
struct Struct_02015ef4 { unsigned int unknown_0_[3]; };
union Struct_020675fc {
    Struct_0203de84 unknown_0_;
    Struct_02015ef4 unknown1_0_;
};
struct Struct_020675fc_2 {
    unsigned char unknown_0_[Enum_020675fc_2456];
    int unknown_998_;
    unsigned char unknown_99c_[0xe9c];
    int unknown_1838_;
    unsigned char unknown_183c_[Enum_020675fc_288];
    unsigned char unknown_195c_;
    unsigned char unknown_195d_[Enum_020675fc_90];
    unsigned char unknown_19b7_;
};
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c();
Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
void SelectVec3FromSources020406f8(Vec3_020406f8*, Node020406f8*);
int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
extern unsigned char data_020e7e08[];

// USA: func_020675fc
extern "C" ARM void func_020675fc(Owner020675fc* owner) {
    if (!owner->active) return;
    Entry_203dce4* entry = GetEntryUnlessFlag0x8000_0203dce4(GetGlobalPtr021075f4_0203cf4c(), owner->entryId);
    if (entry && owner->enabled) {
        GameResources* resources = GetGameResources();
        void* view = GameState::GetInstance()->GetCamera();
        int x;
        int y;
        Vec3copy0202ec84 copied;
        VectorBuffer020675fc vector;
        SelectVec3FromSources020406f8(&vector.selected, (Node020406f8*)entry);
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
        RenderFlaggedIndexedEntry((StructAt020473c8*)output, 1);
    }
}
