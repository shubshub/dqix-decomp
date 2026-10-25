#include <globaldefs.h>
#include "World/ZoneLifecycle.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Resource/GameResources.h"
#include "World/Zone3D.h"

struct HeadNode02046b24;
struct EntryList0217208;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
void ForEachElement02015518(void* a, char* list);
void GameObject_EnableControl(void* obj);
extern "C" void func_02013e18(Zone3D* self);
extern "C" void func_02017208(struct EntryList0217208* self);
extern "C" void Zone3D_UpdateChests(Zone3D* self);
extern "C" void func_020a84e0();
extern "C" void func_0201ba68(void*);
extern "C" void func_0201bdac(unsigned char*);

// USA: func_02015438
extern "C" ARM void func_02015438(Zone3D* arg0) {
#if defined(jpn)
    enum { Enum_02015438_1788 = 0x4ec };
#else
    enum { Enum_02015438_1788 = 0x6fc };
#endif
    GameState* var0 = GameState::GetInstance();
    if (*(int*)&arg0->unk_428[0] == 0)
        return;

    if (arg0->unknown_424_ != 0) {
        func_02013e18(arg0);
        return;
    }

    char* var1 = (char*)arg0->firstBMDJStruct_41c_;
    while (var1 != 0) {
        func_02015518(arg0, var1);
        var1 = *(char**)(var1 + 0x54);
    }

    unsigned char n = self->unk_830[0];
    if (n != 0) {
        n--;
        self->unk_830[0] = n;
        if ((self->unk_830[0] & 0xff) == 0) {
            void* actor = battle->GetProtagonist();
            if (actor != 0) {
                if (GetHeadNodeIdOrMinusOne(
                        *(struct HeadNode02046b24***)((char*)GetGameResources() + 0x3000 + headOffset)) != 4) {
                    GameObject_EnableControl(actor);
                }
            }
            arg0->unk_830[0] = 0;
        }
    }

    func_02017208((struct EntryList0217208*)self);
    Zone3D_UpdateChests(self);
    LightingManager::GetInstance()->RecomputeAdvancedLighting();
    func_020a84e0();
    func_0201ba68(arg0);
    func_0201bdac((unsigned char*)arg0);
    func_0201bfd4(arg0);
}
