#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_0208baec_2 { unsigned char field_0[0xc]; int x, y, width, height; unsigned short value; unsigned short unknown_1e_; unsigned short style; unsigned char flags; unsigned char unknown_23_[5]; };

struct Struct_0208cfcc { char padding[0x3c]; SafeAllocator allocator; };
struct TransitionList0208cfcc { char padding[0x40]; Struct_0208baec_2* entries; char unknown_44_[8]; unsigned short type; char unknown_4e_[2]; unsigned char active; char unknown_51_[3]; };
struct Struct_02065990_2 {
    Struct_0208cfcc* owner;
    char unknown_4_[0x5c];
    TransitionList0208cfcc list;
    Struct_0208baec_2* entries;
    char unknown_b8_[8];
    int task;
    int field_c4;
    int counter;
    float unknown_cc_;
    unsigned short timer;
    short value;
    unsigned char unknown_d4_;
    unsigned char state;
    unsigned char unknown_d6_;
    unsigned char unknown_d7_;
    unsigned char unknown_d8_;
    signed char delay;
    unsigned short flags;
};
struct PacRecord;
#if defined(jpn)
extern char data_020f12cc[];
#endif
extern char data_020f11eb[];
extern char data_020f11fe[];
extern char g_sePlayer[];
void SetSubBrightness(GameResources*, int, int);
extern "C" void func_0208bf28(Struct_02065990_2*, int, unsigned char);
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void SpriteContext_Init(char*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void SpriteContext_LoadFile(TransitionList0208cfcc*, void*, int, SafeAllocator*);
extern "C" void func_0205aed0(void*, char*, unsigned int, int);
extern "C" void func_0205af38(int, char*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" void SePlayer_LoadExtraArchiveA(void*, int, int);
extern "C" void func_0205eb90(void*, int, int);
extern "C" void SePlayer_UnloadExtraArchiveA(void*);

static inline int inline_0208cfcc(Struct_02065990_2* obj) { return (obj->flags & 0x100) == 0; }

// USA: func_0208cfcc
extern "C" ARM void func_0208cfcc(Struct_02065990_2* obj) {
    Struct_0208cfcc* owner;
    BackgroundLoader* loader;
    GameResources* resources = GetGameResources();
    loader = BackgroundLoader::GetInstance();
    if (obj->state == 0) {
        int var3 = inline_0208cfcc(obj) == 0;
        unsigned int limit = 300;
        if (var3) limit = 150;
        if (obj->timer < limit) obj->timer += GameState::GetInstance()->GetTickCount();
        else if (var3) {
            SetSubBrightness(resources, -4, 4);
#if defined(jpn)
            obj->task = loader->QueueLoadFile(data_020f12cc, 0);
#else
            obj->task = loader->QueueLoadFileInGP2(data_020f11eb, data_020f11fe, 0);
#endif
            obj->state++;
        } else {
            func_0208bf28(obj, obj->value, 0);
            obj->flags |= 4;
            obj->counter = 0;
            obj->unknown_d7_ = 0;
            obj->state = 2;
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
            func_0205aed0(&obj->list, (char*)obj->entries, 3, 64);
            loader->RemoveTask(obj->task);
            obj->task = -1;
            obj->flags |= 4;
            obj->counter = 0;
            obj->unknown_d7_ = 0;
            obj->state++;
        }
    } else if (obj->state == 2) {
        if (!IsSubBrightnessTransitionActive(GetGameResources())) {
            func_0205af38((int)&obj->list, (char*)&obj->entries[0], 1, 1);
            func_0205af38((int)&obj->list, (char*)&obj->entries[1], 1, 1);
            obj->unknown_d8_ = 0;
            obj->unknown_cc_ = 0;
            obj->flags &= ~1;
            obj->state++;
        }
    } else if (obj->state == 3) {
        obj->flags |= 8;
        if (obj->unknown_cc_ < 1.0f) obj->unknown_cc_ += 0.2f;
        else {
            obj->unknown_cc_ = 1.0f;
            SePlayer_LoadExtraArchiveA(g_sePlayer, 110, 110);
            func_0205eb90(g_sePlayer, 0, 0);
            obj->state++;
            obj->delay = 30;
        }
    } else if (obj->state == 4) {
        obj->flags |= 128;
        obj->state++;
    } else if (obj->state == 5) {
        if (!(obj->flags & 128)) {
            obj->unknown_cc_ += 0.2f;
            if (1.0f < obj->unknown_cc_) {
                obj->unknown_cc_ = 1.0f;
                obj->state++;
            }
        }
    } else if (obj->state == 6 && obj->delay == 0) {
        SePlayer_UnloadExtraArchiveA(g_sePlayer);
        obj->unknown_d4_ = 1;
        obj->state = 0;
    }
}
