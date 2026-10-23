#if defined(jpn)
#define func_ov008_02188d74 func_ov008_02189a9c
#endif

#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_0201099c_3;
struct Struct_02043368_2;
struct Struct_02020cb8_4;
struct Struct_02020aec;

struct Struct_ov006_021580b8
{
    char unknown_0_[0x28];
};

struct Struct_ov008_02188d74
{
    char unknown_0_[0x3c];
    void* unknown_3c_;
    Struct_ov006_021580b8* unknown_40_;
    char unknown_44_[4];
    unsigned int unknown_48_;
    short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned char unknown_50_;
    char unknown_51_[3];

    void inline_ov008_02188d74(Struct_ov006_021580b8* arg0, short arg1)
    {
        unknown_40_ = arg0;
        unknown_4c_ = arg1;
    }
};

const char* KeyTable_Get(Container020e0310* texts, int id);
void SpriteContext_Init(char* renderer);
void Sprite_Init(Struct0205a198* sprite);
int Pac_CountFiles(ActiveEntry02046900* archive);
void* Pac_GetFile(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void SpriteContext_LoadFile(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);

struct Struct_ov008_021842a0_2
{
    char unknown_0_[0x50];
    SafeAllocator unknown_50_;
    char unknown_64_[0xa0 - 0x50 - sizeof(SafeAllocator)];
    char unknown_a0_[0x18];
    char unknown_b8_[0x73c - 0xb8];
    Struct_ov008_02188d74* unknown_73c_;
    Struct_ov006_021580b8* unknown_740_;
    char unknown_744_[0xb12 - 0x744];
    unsigned char unknown_b12_;
    char unknown_b13_[0xb20 - 0xb13];
    int unknown_b20_;
};

// USA: func_ov008_02188d74
extern "C" ARM int func_ov008_02188d74(Struct_ov008_021842a0_2* arg0)
{
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    unsigned char var1 = arg0->unknown_b12_;
    if (var1 == 0)
    {
        self->iconRenderer_ = NULL;
        self->iconSprite_ = NULL;
        self->iconAllocator_.Reset();
        self->iconRenderer_ = (SpriteRenderer*)self->iconAllocator_.Allocate(sizeof(SpriteRenderer));
        self->iconSprite_ = (Sprite*)self->iconAllocator_.Allocate(sizeof(Sprite));
        SpriteContext_Init((char*)self->iconRenderer_);
        self->iconRenderer_->unk_50 = 1;
        SpriteRenderer* renderer = self->iconRenderer_;
        renderer->SetSprites(self->iconSprite_, 1);
        for (int i = 0; i < 1; i++)
            Sprite_Init((Struct0205a198*)&self->iconSprite_[i]);
        self->task_ = loader->QueueLoadFile(KeyTable_Get((Container020e0310*)&self->texts_, LOW_REGION(4, 7)), NULL);
        self->loadStep_++;
    }
    if (var1 == 1 && var0->GetTaskStatus(arg0->unknown_b20_))
    {
        char name[4];
        void* archive;
        unsigned int archiveSize;
        loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
        int count = Pac_CountFiles((ActiveEntry02046900*)archive);
        for (int i = 0; i < count; i++)
        {
            unsigned int size;
            void* file = Pac_GetFile((Rec020467f0*)archive, i, (void**)name, (int*)&size);
            if (file != NULL)
                SpriteContext_LoadFile(self->iconRenderer_, file, size, &self->iconAllocator_);
        }
        var0->RemoveTask(arg0->unknown_b20_);
        arg0->unknown_b20_ = -1;
        arg0->unknown_b12_ = 0;
        return 1;
    }
    return 0;
}
