#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct0205a198;
struct ClearTarget0205a234;
struct PacRecord;

extern "C" void SpriteContext_Init(char* p);
extern "C" void Sprite_Init(struct Struct0205a198* p);
extern "C" void func_0205a234(struct ClearTarget0205a234* p);
extern "C" int Pac_CountFiles(struct PacRecord* entry);
extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* outLength);
extern "C" void SpriteContext_LoadFile(void* a, void* b, int c, void* d);

extern char data_020f007f;
extern char data_020f0093;

struct Struct_02043368_3 {
    char pad0[0x3c];
    struct ClearTarget0205a234* unknown_3c_;
    void* entries;
    char pad1[8];
    unsigned short unknown_4c_;
    char pad2[2];
    unsigned char unknown_50_;
};

struct Struct_02043368_4 {
#if defined(jpn)
    char pad0[0x220];
#else
    char pad0[0x2d0];
#endif
    int taskId;
    SafeAllocator* allocator;
    struct Struct_02043368_3* table;
    char* tableEntries;
    struct ClearTarget0205a234* unknown_2e0_;
    unsigned short unknown_2e4_;
    char pad1[1];
    unsigned char state;
};

// USA: func_02043368
extern "C" ARM void func_02043368(struct Struct_02043368_4* self) {
    if (self->allocator == 0) {
        return;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->state == 0) {
        if (self->table != 0) {
            return;
        }
        GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
        if (grotto != 0 && grotto->unknown_0[0] != 0 && grotto->unknown_0[2] == 0) {
            return;
        }
#if defined(jpn)
        self->taskId = loader->QueueLoadFile(&data_020f0093, 0);
#else
        self->taskId = loader->QueueLoadFileInGP2(&data_020f007f, &data_020f0093, 0);
#endif
        self->state++;
        return;
    }

    if (self->state == 1) {
        if (loader->GetTaskStatus(self->taskId) == 0) {
            return;
        }
        self->allocator->Reset();
        self->table = (struct Struct_02043368_3*)self->allocator->Allocate(0x54);
        self->tableEntries = (char*)self->allocator->Allocate(0xf0);
        self->unknown_2e0_ = (struct ClearTarget0205a234*)self->allocator->Allocate(8);

        if (self->table != 0 && self->tableEntries != 0 && self->unknown_2e0_ != 0) {
            SpriteContext_Init((char*)self->table);
            for (unsigned short i = 0; i < 6; i++) {
                Sprite_Init((struct Struct0205a198*)(self->tableEntries + i * 0x28));
            }
            func_0205a234(self->unknown_2e0_);
            self->table->unknown_50_ = 0;
            {
                struct Struct_02043368_3* table = self->table;
                table->entries = self->tableEntries;
                table->unknown_4c_ = 6;
            }
            self->table->unknown_3c_ = self->unknown_2e0_;
            self->unknown_2e4_ = 0;

            void* rec;
            void* found;
            unsigned int var6;
            int recLen;
            loader->GetLoadedFileByID(self->taskId, &found, &var6);
            int count = Pac_CountFiles((struct PacRecord*)found);
            for (int i = 0; i < count; i++) {
                void* r = Pac_GetFile((struct PacRecord*)found, i, &rec, &recLen);
                SpriteContext_LoadFile(self->table, r, recLen, self->allocator);
            }
        }

        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
        return;
    }

    if (self->state == 2) {
        if (self->table != 0 && self->unknown_2e0_ != 0) {
            return;
        }
        self->table = 0;
        self->tableEntries = 0;
        self->unknown_2e0_ = 0;
        self->unknown_2e4_ = 0;
        self->taskId = -1;
        self->state = 0;
    }
}
