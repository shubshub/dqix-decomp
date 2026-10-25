#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_0208baec_2 { unsigned char unknown_0_[0xc]; int unknown_c_, unknown_10_, unknown_14_, unknown_18_; unsigned short unknown_1c_; unsigned short unknown_1e_; unsigned short unknown_20_; unsigned char unknown_22_; unsigned char unknown_23_[5]; };

struct Struct_0208cfcc { char unknown_0_[0x3c]; SafeAllocator unknown_3c_; };
struct Struct_0208cfcc_2 { char unknown_0_[0x40]; Struct_0208baec_2* unknown_40_; char unknown_44_[8]; unsigned short unknown_4c_; char unknown_4e_[2]; unsigned char unknown_50_; char unknown_51_[3]; };
struct Struct_02065990_2 {
    Struct_0208cfcc* unknown_0_;
    char unknown_4_[0x5c];
    Struct_0208cfcc_2 unknown_60_;
    Struct_0208baec_2* unknown_b4_;
    char unknown_b8_[8];
    int unknown_c0_;
    int unknown_c4_;
    int unknown_c8_;
    float unknown_cc_;
    unsigned short unknown_d0_;
    short unknown_d2_;
    unsigned char unknown_d4_;
    unsigned char unknown_d5_;
    unsigned char unknown_d6_;
    unsigned char unknown_d7_;
    unsigned char unknown_d8_;
    signed char unknown_d9_;
    unsigned short unknown_da_;
};
struct PacRecord;
#if defined(jpn)
extern char data_020f12cc[];
#endif
extern char data_020f11eb[];
extern char data_020f11fe[];
extern char g_sePlayer[];
void SetSubBrightness(GameResources*, int, int);
void SetFieldD20208bf28(Obj0208bf28*, int, unsigned char);
int Pac_CountFiles(PacRecord*);
void SpriteContext_Init(char*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void SpriteContext_LoadFile(TransitionList0208cfcc*, void*, int, SafeAllocator*);
void WrapAddByteField0x22_0205aed0(void*, char*, unsigned int, int);
void SetBitfieldStoreBytes0205af38(int, char*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
void SePlayer_LoadExtraArchiveA(void*, int, int);
void DispatchIfField0xc4NonNeg_0205eb90(void*, int, int);
void SePlayer_UnloadExtraArchiveA(void*);

static inline int inline_0208cfcc(Struct_02065990_2* arg0) { return (arg0->unknown_da_ & 0x100) == 0; }

// USA: func_0208cfcc
extern "C" ARM void func_0208cfcc(Struct_02065990_2* arg0) {
    Struct_0208cfcc* var0;
    BackgroundLoader* var1;
    GameResources* var2 = GetGameResources();
    var1 = BackgroundLoader::GetInstance();
    if (arg0->unknown_d5_ == 0) {
        int var3 = inline_0208cfcc(arg0) == 0;
        unsigned int var4 = 300;
        if (var3) var4 = 150;
        if (arg0->unknown_d0_ < var4) arg0->unknown_d0_ += GameState::GetInstance()->GetTickCount();
        else if (var3) {
            SetSubBrightness(var2, -4, 4);
#if defined(jpn)
            arg0->unknown_c0_ = var1->QueueLoadFile(data_020f12cc, 0);
#else
            arg0->unknown_c0_ = var1->QueueLoadFileInGP2(data_020f11eb, data_020f11fe, 0);
#endif
            arg0->unknown_d5_++;
        } else {
            func_0208bf28(arg0, arg0->unknown_d2_, 0);
            arg0->unknown_da_ |= 4;
            arg0->unknown_c8_ = 0;
            arg0->unknown_d7_ = 0;
            arg0->unknown_d5_ = 2;
        }
    } else if (obj->state == 1) {
        if (loader->GetTaskStatus(obj->task)) {
            owner = obj->owner;
            owner->allocator.Reset();
            void* record;
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(obj->task, &file, &length);
            int count = Pac_CountFiles((PacRecord*)file);
            SpriteContext_Init((char*)&obj->list);
            obj->list.active = 1;
            obj->list.entries = obj->entries;
            obj->list.type = 3;
            for (int i = 0; i < count; i++) {
                int size;
                void* entry = Pac_GetFile((PacRecord*)file, i, &record, &size);
                SpriteContext_LoadFile(&obj->list, entry, size, &owner->allocator);
            }
            func_0205aed0(&arg0->unknown_60_, (char*)arg0->unknown_b4_, 3, 64);
            var1->RemoveTask(arg0->unknown_c0_);
            arg0->unknown_c0_ = -1;
            arg0->unknown_da_ |= 4;
            arg0->unknown_c8_ = 0;
            arg0->unknown_d7_ = 0;
            arg0->unknown_d5_++;
        }
    } else if (arg0->unknown_d5_ == 2) {
        if (!IsSubBrightnessTransitionActive(GetGameResources())) {
            func_0205af38((int)&arg0->unknown_60_, (char*)&arg0->unknown_b4_[0], 1, 1);
            func_0205af38((int)&arg0->unknown_60_, (char*)&arg0->unknown_b4_[1], 1, 1);
            arg0->unknown_d8_ = 0;
            arg0->unknown_cc_ = 0;
            arg0->unknown_da_ &= ~1;
            arg0->unknown_d5_++;
        }
    } else if (arg0->unknown_d5_ == 3) {
        arg0->unknown_da_ |= 8;
        if (arg0->unknown_cc_ < 1.0f) arg0->unknown_cc_ += 0.2f;
        else {
            obj->blend = 1.0f;
            SePlayer_LoadExtraArchiveA(g_sePlayer, 110, 110);
            DispatchIfField0xc4NonNeg_0205eb90(g_sePlayer, 0, 0);
            obj->state++;
            obj->delay = 30;
        }
    } else if (arg0->unknown_d5_ == 4) {
        arg0->unknown_da_ |= 128;
        arg0->unknown_d5_++;
    } else if (arg0->unknown_d5_ == 5) {
        if (!(arg0->unknown_da_ & 128)) {
            arg0->unknown_cc_ += 0.2f;
            if (1.0f < arg0->unknown_cc_) {
                arg0->unknown_cc_ = 1.0f;
                arg0->unknown_d5_++;
            }
        }
    } else if (obj->state == 6 && obj->delay == 0) {
        SePlayer_UnloadExtraArchiveA(g_sePlayer);
        obj->complete = 1;
        obj->state = 0;
    }
}
