#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Input/Input.h"

int IsField0Null_02046b08(void** obj);
void CancelActionIfHeadIdMatches_02199e98(void* obj);
void* GameState_GetParty(GameState* gs);
int GetIntField0x260_02039750(void* obj);
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);
unsigned char GetByteField0x252_02039820(void* obj);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void func_ov017_021a5bac(unsigned char* base);
void InitFieldArenaListsAndCounters_021996fc(unsigned char* base);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
extern "C" void func_ov017_021999fc(unsigned char* self);

struct Struct_ov017_02199684 { unsigned char unknown_0_[0x14]; int unknown_14_; unsigned char unknown_18_[0x20 - 0x18]; };
extern "C" void func_ov017_02199684(Struct_ov017_02199684* arg0, int arg1, int arg2);
extern "C" void func_ov017_021996bc(Struct_ov017_02199684* arg0, int arg1);

struct TileMap0204bc74;
extern "C" void Background_FillRect(TileMap0204bc74* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
struct BackgroundGraphics;
void Background_UploadMap(BackgroundGraphics* obj, void* buf);

struct Struct_ov017_02199780 {
    unsigned short unknown_0_0_ : 2;
    unsigned short unknown_0_2_ : 4;
    unsigned short unknown_0_6_ : 1;
    unsigned short unknown_0_7_ : 1;
    unsigned short unknown_1_0_ : 5;
    unsigned short unknown_1_5_ : 1;
    unsigned short unknown_1_6_ : 2;
};

// USA: func_ov017_02199f08
extern "C" ARM void func_ov017_02199f08(unsigned char* arg0) {
#if defined(jpn)
    enum {Enum_ov017_02199f08_16512 = 0x3e60, Enum_ov017_02199f08_15956 = 0x3e54, Enum_ov017_02199f08_15960 = 0x3e58, Enum_ov017_02199f08_180 = 0x294, Enum_ov017_02199f08_15360 = 0x3800, Enum_ov017_02199f08_2704 = 0xa90, Enum_ov017_02199f08_1788 = 0x4ec, Enum_ov017_02199f08_396 = 0x180, Enum_ov017_02199f08_3240 = 0xa88, Enum_ov017_02199f08_3244 = 0xa8c};
#else
    enum {Enum_ov017_02199f08_16512 = 0x4080, Enum_ov017_02199f08_16500 = 0x4074, Enum_ov017_02199f08_16504 = 0x4078, Enum_ov017_02199f08_180 = 0xb4, Enum_ov017_02199f08_15360 = 0x3c00, Enum_ov017_02199f08_3248 = 0xcb0, Enum_ov017_02199f08_1788 = 0x6fc, Enum_ov017_02199f08_396 = 0x18c, Enum_ov017_02199f08_3240 = 0xca8, Enum_ov017_02199f08_3244 = 0xcac};
#endif

    struct Struct_02015438;
    if (func_02046b08((void**)*(struct Struct_02015438***)(arg0 + 0x3000 + Enum_ov017_02199f08_1788)) == 0) {
        func_ov017_02199e98(arg0);
        return;
    }

    GameState* gs = GameState::GetInstance();
    gs->GetProtagonist();
    GameObject* actor = gs->GetUnknownGameObject();
    unsigned char* party = (unsigned char*)GameState_GetParty(gs);
    int mode = GetIntField0x260_02039750(actor);

    if (var3 == -1) {
        if (func_0203402c((Struct_0203402c*)var1) == 0 &&
            *(int*)(arg0 + Enum_ov017_02199f08_16512) == 0) {
            if (g_keyManager.TestKeysPressed(2) &&
                GetByteField0x252_02039820(actor) &&
                (*(int*)((char*)actor + regionalOffset7) & 1) == 0 &&
                CheckSubstructByte0x7cPositive_020535c8((signed char*)actor) == 0 &&
                *(short*)((char*)actor + 0xac) == 0) {
                GameObject_DisableControl((Obj020397cc*)actor, 1);
                *(unsigned short*)((char*)actor + 0xb2) = 0;
                FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x400);
                func_ov017_021a5bac(self);

                volatile unsigned short* var4 = (volatile unsigned short*)0x400000a;
                volatile short var5, var6;
                {
                    unsigned short var7 = var4[0];
                    *(volatile unsigned short*)(*(Struct_ov017_02199780**)(arg0 + 0x3000 + Enum_ov017_02199f08_3240)) = var7;
                    var5 = var7;
                    var5;
                }
                {
                    unsigned short var8 = var4[1];
                    var6 = var8;
                    var6;
                    *(volatile unsigned short*)(*(Struct_ov017_02199780**)(arg0 + 0x3000 + Enum_ov017_02199f08_3244)) = var8;
                    var6;
                }
                func_ov017_021996fc(arg0);
                *(int*)(arg0 + Enum_ov017_02199f08_16512) = 1;
            }
            return;
        }
    }

    if (g_keyManager.TestKeysReleased(2) != 0 ||
        *(short*)((char*)var1 + 0xac) != 0 ||
        func_0203402c((Struct_0203402c*)var1) != 0) {
        func_ov017_02199e98(arg0);
        return;
    }

    if (var3 != -1) {
        int var9 = 0;
        while (var9 < *(unsigned char*)(var2 + 0xf7c)) {
            unsigned char* var10 = var2 + var9;
            GameObject* var11 = var0->GetPartyMemberByIndex(var10[0xf78]);
            *(unsigned short*)((char*)var11 + 0xac) = 0;
            var9++;
        }
    }

    if (TestFlags02046708((FlagWord02046708*)GlobalFlags_GetInstance(), 4) != 0) {
        CancelActionIfHeadIdMatches_02199e98(self);
        return;
    }

    func_ov017_021999fc(arg0);

    Entry_02199684* e;
    int i;
    if (g_keyManager.TestKeysHeld(2) != 0 && mode != -1) {
        FillEntriesEncoded_02199684((Entry_02199684*)(self + regionalOffset3 + regionalOffset4), 2, 0x800);
        for (i = 0; i < 2; i++) {
            e = (Entry_02199684*)(self + regionalOffset3 + regionalOffset4) + i;
            Background_FillRect((TileMap0204bc74*)e, 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((BackgroundGraphics*)e, 0);
        }
        func_ov017_021996bc((Struct_ov017_02199684*)(arg0 + Enum_ov017_02199f08_180 + Enum_ov017_02199f08_15360), 2);
    }
}
