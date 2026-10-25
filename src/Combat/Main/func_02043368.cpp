#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct0205a198;
struct ClearTarget0205a234;
struct PacRecord;

void SpriteContext_Init(char* p);
void Sprite_Init(struct Struct0205a198* p);
void ClearField0And40205a234(struct ClearTarget0205a234* p);
int Pac_CountFiles(struct PacRecord* entry);
void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* outLength);
extern "C" void SpriteContext_LoadFile(void* a, void* b, int c, void* d);

extern char data_020f007f;
extern char data_020f0093;

struct Struct_02043368_3 {
    char unknown_0_[0x3c];
    struct Struct_02043368* unknown_3c_;
    void* unknown_40_;
    char unknown_44_[8];
    unsigned short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
};

struct Struct_02043368_4 {
#if defined(jpn)
    char unknown_0_[0x220];
#else
    char unknown1_0_[0x2d0];
#endif
    int unknown_2d0_;
    SafeAllocator* unknown_2d4_;
    struct Struct_02043368_3* unknown_2d8_;
    char* unknown_2dc_;
    struct Struct_02043368* unknown_2e0_;
    unsigned short unknown_2e4_;
    char unknown_2e6_[1];
    unsigned char unknown_2e7_;
};

// USA: func_02043368
extern "C" ARM void func_02043368(struct Struct_02043368_4* arg0) {
    if (arg0->unknown_2d4_ == 0) {
        return;
    }
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();

    if (arg0->unknown_2e7_ == 0) {
        if (arg0->unknown_2d8_ != 0) {
            return;
        }
        GrottoStruct* var1 = GameState::GetInstance()->GetGrottoStruct();
        if (var1 != 0 && var1->unknown_0[0] != 0 && var1->unknown_0[2] == 0) {
            return;
        }
#if defined(jpn)
        arg0->unknown_2d0_ = var0->QueueLoadFile(&data_020f0093, 0);
#else
        arg0->unknown_2d0_ = var0->QueueLoadFileInGP2(&data_020f007f, &data_020f0093, 0);
#endif
        arg0->unknown_2e7_++;
        return;
    }

    if (arg0->unknown_2e7_ == 1) {
        if (var0->GetTaskStatus(arg0->unknown_2d0_) == 0) {
            return;
        }
        arg0->unknown_2d4_->Reset();
        arg0->unknown_2d8_ = (struct Struct_02043368_3*)arg0->unknown_2d4_->Allocate(0x54);
        arg0->unknown_2dc_ = (char*)arg0->unknown_2d4_->Allocate(0xf0);
        arg0->unknown_2e0_ = (struct Struct_02043368*)arg0->unknown_2d4_->Allocate(8);

        if (self->table != 0 && self->tableEntries != 0 && self->clearTarget != 0) {
            SpriteContext_Init((char*)self->table);
            for (unsigned short i = 0; i < 6; i++) {
                Sprite_Init((struct Struct0205a198*)(self->tableEntries + i * 0x28));
            }
            func_0205a234(arg0->unknown_2e0_);
            arg0->unknown_2d8_->unknown_50_ = 0;
            {
                struct Struct_02043368_3* var3 = arg0->unknown_2d8_;
                var3->unknown_40_ = arg0->unknown_2dc_;
                var3->unknown_4c_ = 6;
            }
            arg0->unknown_2d8_->unknown_3c_ = arg0->unknown_2e0_;
            arg0->unknown_2e4_ = 0;

            void* rec;
            void* found;
            unsigned int foundLen;
            int recLen;
            loader->GetLoadedFileByID(self->taskId, &found, &foundLen);
            int count = Pac_CountFiles((struct PacRecord*)found);
            for (int i = 0; i < count; i++) {
                void* r = Pac_GetFile((struct PacRecord*)found, i, &rec, &recLen);
                SpriteContext_LoadFile(self->table, r, recLen, self->allocator);
            }
        }

        var0->RemoveTask(arg0->unknown_2d0_);
        arg0->unknown_2d0_ = -1;
        arg0->unknown_2e7_++;
        return;
    }

    if (arg0->unknown_2e7_ == 2) {
        if (arg0->unknown_2d8_ != 0 && arg0->unknown_2e0_ != 0) {
            return;
        }
        arg0->unknown_2d8_ = 0;
        arg0->unknown_2dc_ = 0;
        arg0->unknown_2e0_ = 0;
        arg0->unknown_2e4_ = 0;
        arg0->unknown_2d0_ = -1;
        arg0->unknown_2e7_ = 0;
    }
}
