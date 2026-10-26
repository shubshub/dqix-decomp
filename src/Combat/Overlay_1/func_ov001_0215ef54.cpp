#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" int func_ov001_0215ad2c(int x);

struct Struct_ov001_0215e1cc;

extern const char data_ov001_02165745[];
extern SafeAllocator* data_ov001_021658b8[8];

// USA: func_ov001_0215ef54
extern "C" ARM int func_ov001_0215ef54(char* obj, int count) {
    void* var0 = obj;
    obj += 0x8;
    void* field4 = func_ov017_021d612c(var0);
    GameState* battle = GameState::GetInstance();
    if (battle == 0) return 0;

    char buf[0x20];
    sprintf(buf, data_ov001_02165745, field4);

    SafeAllocator* alloc = data_ov001_021658b8[0];
    void* var5 = alloc->Allocate(0xac);
    if (var5 == 0) return 0;
    ((Model3D*)((unsigned char*)var5))->Clear();

    int out1;
    int out2;
    ((BackgroundLoader*)((Struct_ov001_0215e1cc*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 != 0) {
        ((Model3D*)var5)->CopyAndProcessRawFile(&alloc->allocUnion, (void*)out1, out2, Model3D::TextureStagingMode_Normal);
    } else {
        ((Model3D*)var5)->LoadFromFile(buf, &alloc->allocUnion, Model3D::TextureStagingMode_Normal);
    }

    for (int i = 1; i < count; i++) {
        int t = func_ov017_021d60f4(obj);
        obj += 0x8;
        int idx = func_ov001_0215ad2c(t);
        GameObject* combatant = battle->GetGameObjectByIndex(idx);
        if (combatant != 0 && combatant->obj3D_.pModel_ != 0) {
            ((Model3D*)(combatant->obj3D_.pModel_))->ApplyTexturesFromModel((Model3D*)var5);
        }
    }
    return 1;
}
