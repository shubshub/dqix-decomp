#include <globaldefs.h>
#include "Graphics/Window.h"
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Combat/MapDisplay.h>

struct Struct_ov017_021a5cbc { unsigned char unknown_0_[2]; };
struct Struct_ov017_021a5ad0 {
    char unknown_0_[0x18];
    int unknown_18_;
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};
struct Struct_ov017_021a5cbc_2 { short unknown_0_[5]; };
struct Struct_ov017_021a5cbc_3 {
    char unknown_0_[0x98];
    Struct_ov017_021a5ad0* unknown_98_;
    char unknown_9c_[4];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
    unsigned char unknown_b2_;
    char unknown_b3_[2];
    unsigned char unknown_b5_;
};
struct BackgroundGraphics;
struct PacRecord;
struct Struct_0205cf78;
struct Struct0200fb08;
#if defined(jpn)
enum { Enum_ov017_021a5cbc_1280 = 0x400 };
#define data_ov017_021d76e8 data_ov017_021d7b28
#define data_ov017_021d7719 data_ov017_021d7b54
extern const char data_ov017_021d7b3b[];
#else
enum { Enum_ov017_021a5cbc_1280 = 0x500 };
#endif
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(Node0x20_021a5ad0*, unsigned char);
void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void ColorEffect_ConfigureAlphaBlend(void*, int, int, int, int);
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_LoadFile(Node0x20_021a5ad0*, void*, SafeAllocator*, int);
void Sprite_Init(Struct0205a198*);
void SpriteContext_Init(char*);
extern "C" int SpriteContext_LoadFile(MapEntryList*, void*, int, SafeAllocator*);
void FillFieldWithEncoded_021a5ad0(Node0x20_021a5ad0*, int, int);
extern "C" void Background_FillRect(Node0x20_021a5ad0*, int, int, int, int, int, int);
void Background_UploadMap(BackgroundGraphics*, void*);
void ClearAndEncodeField14_021a5b08(Node0x20_021a5ad0*, int);
void WindowPane_AllocateBuffer(WindowPane*, SafeAllocator*, int, unsigned int);
void Window_SetPanes(Struct_0205cf78*, WindowPane*, unsigned char);
int GameState_GetLanguage(Struct0200fb08*);
extern "C" void Window_OpenPane(Config021a5cbc*, const char*, int, unsigned char, unsigned char, unsigned char, void*
#if !defined(jpn)
    , unsigned char
#endif
);
extern "C" void Window_Update(Config021a5cbc*, unsigned int);
extern const unsigned char data_ov017_021d6a8c[];
extern const char data_ov017_021d76e8[];
extern const char data_ov017_021d76fb[];
extern const char data_ov017_021d770c[];
extern const short data_ov017_021d6a94[];
extern const char data_ov017_021d7719[];
#define REG_DISPLAY_CONTROL (*(volatile unsigned int*)0x04000000)
#define REG_BACKGROUND_1 (*(volatile unsigned short*)0x0400000a)
#define REG_BACKGROUND_2 (*(volatile unsigned short*)0x0400000c)
#define REG_BACKGROUND_0 (*(volatile unsigned short*)0x04000008)
#define REG_BACKGROUND_3 (*(volatile unsigned short*)0x0400000e)

// USA: func_ov017_021a5cbc
extern "C" ARM void func_ov017_021a5cbc(GameResources* self) {
    if ((*reinterpret_cast<void**>(self->unknown_4094 + 0x120)) || !(*reinterpret_cast<int*>(self->unknown_4094 + 0x12c))) return;
    if ((*reinterpret_cast<int*>(self->unknown_4094 + 0x124)) == 0) {
        self->allocator_array_38[16].Reset();
        Pair021a5cbc priorities = *(const Pair021a5cbc*)(data_ov017_021d6a8c + 2);
        Pair021a5cbc styles = *(const Pair021a5cbc*)data_ov017_021d6a8c;
        for (int i = 0; i < 2; ++i) {
            Node0x20_021a5ad0* node = &reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094)[i];
            Background_SetMapSize((unsigned char*)node, 0);
            node->low = 0;
            node->high = priorities.values[i];
            Background_SetPriority(node, styles.values[i]);
            Background_SetScroll((BackgroundGraphics*)node, 0, 0);
        }
        REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x100;
        REG_BACKGROUND_1 = (REG_BACKGROUND_1 & 0x43) | 0x1d00;
        REG_BACKGROUND_2 = (REG_BACKGROUND_2 & 0x43) | 0x1e00;
        ColorEffect_ConfigureAlphaBlend((void*)0x04000050, 2, 1, 9, 7);
        (*reinterpret_cast<int*>(self->unknown_4094 + 0x128)) = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d76e8, 0);
        ++(*reinterpret_cast<int*>(self->unknown_4094 + 0x124));
    } else if ((*reinterpret_cast<int*>(self->unknown_4094 + 0x124)) == 1) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (!loader->GetTaskStatus((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)))) return;
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)), &file, &length);
        int count = Pac_CountFiles((PacRecord*)file);
        void* entries[4];
        int sizes[4];
        for (int i = 0; i < count; ++i) entries[i] = Pac_GetFile((PacRecord*)file, i, &record, &sizes[i]);
        for (int i = 0; i < count; ++i) {
            if (entries[i]) Background_LoadFile(reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094 + sizeof(Node0x20_021a5ad0)), entries[i], &self->allocator_array_38[16], sizes[i]);
        }
        loader->RemoveTask((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)));
        (*reinterpret_cast<int*>(self->unknown_4094 + 0x128)) = -1;
        for (int i = 0; i < 7; ++i) Sprite_Init(&reinterpret_cast<Struct0205a198*>(self->unknown_41c8)[i]);
        SpriteContext_Init((char*)static_cast<MapEntryList*>(self->unknown_ptr_41c4));
        static_cast<MapEntryList*>(self->unknown_ptr_41c4)->active = 0;
        MapEntryList* script = static_cast<MapEntryList*>(self->unknown_ptr_41c4);
        script->records = reinterpret_cast<Struct0205a198*>(self->unknown_41c8);
        script->count = 7;
        #if defined(jpn)
        (*reinterpret_cast<int*>(arg0->unknown_4094 + 0x128)) = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d7b3b, 0);
#else
        (*reinterpret_cast<int*>(arg0->unknown_4094 + 0x128)) = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d76fb, data_ov017_021d770c, 0);
#endif
        ++(*reinterpret_cast<int*>(self->unknown_4094 + 0x124));
    } else if ((*reinterpret_cast<int*>(self->unknown_4094 + 0x124)) == 2) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (!loader->GetTaskStatus((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)))) return;
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)), &file, &length);
        int count = Pac_CountFiles((PacRecord*)file);
        int size;
        for (int i = 0; i < count; ++i) {
            void* entry = Pac_GetFile((PacRecord*)file, i, &record, &size);
            SpriteContext_LoadFile(static_cast<MapEntryList*>(self->unknown_ptr_41c4), entry, size, &self->allocator_array_38[16]);
        }
        loader->RemoveTask((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)));
        (*reinterpret_cast<int*>(self->unknown_4094 + 0x128)) = -1;
        FillFieldWithEncoded_021a5ad0(reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094), 2, 0x800);
        for (int i = 0; i < 2; ++i) {
            Node0x20_021a5ad0* node = &reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094)[i];
            Background_FillRect(node, 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((BackgroundGraphics*)node, 0);
        }
        ClearAndEncodeField14_021a5b08(reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094), 2);
        (*reinterpret_cast<void**>(self->unknown_4094 + 0x120)) = self->allocator_array_38[16].Allocate(WindowAllocationSize);
        WindowPane_AllocateBuffer(&(*reinterpret_cast<WindowPane*>(self->unknown_4094 + 0x40)), &self->allocator_array_38[16], (int)(*reinterpret_cast<void**>(self->unknown_4094 + 0x120)), 0x40);
        (*reinterpret_cast<WindowPane*>(self->unknown_4094 + 0x40)).layer_ = reinterpret_cast<BackgroundGraphics*>(self->unknown_4094 + sizeof(Node0x20_021a5ad0));
        Config021a5cbc* nodeConfig = static_cast<Config021a5cbc*>(self->unknown_ptr_array_4088[2]);
        nodeConfig->nodes = reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094);
        nodeConfig->count = 2;
        Window_SetPanes((Struct_0205cf78*)static_cast<Config021a5cbc*>(self->unknown_ptr_array_4088[2]), (WindowPane*)&(*reinterpret_cast<WindowPane*>(self->unknown_4094 + 0x40)), 1);
        REG_BACKGROUND_0 = (REG_BACKGROUND_0 & ~3) | 2;
        REG_BACKGROUND_1 = (REG_BACKGROUND_1 & ~3) | 1;
        REG_BACKGROUND_2 = REG_BACKGROUND_2 & ~3;
        REG_BACKGROUND_3 = (REG_BACKGROUND_3 & ~3) | 3;
        REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x1700;
        Struct_ov017_021a5cbc_3* var26 = static_cast<Struct_ov017_021a5cbc_3*>(arg0->unknown_ptr_array_4088[2]);
        #if defined(jpn)
        int var29 = 9;
#else
        Widths021a5cbc widths = *(const Widths021a5cbc*)data_ov017_021d6a94;
        int index = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
        int left = widths.values[index - 1];
#endif
        config->left = left;
        config->top = 2;
        config->width = 0x20 - (left + 1);
        config->height = 0x15;
        config->field_a8 = 3;
        config->field_aa = 3;
        config->field_ac = 10;
        config->field_ae = 11;
        config->flag_b1 = 0;
        config->flag_b5 = 1;
        Window_OpenPane(config, data_ov017_021d7719, 0, 0, 0, 1, 0
#if !defined(jpn)
            , 0
#endif
        );
        Window_Update(config, GameState::GetInstance()->GetTickCount());
        (*reinterpret_cast<WindowPane*>(self->unknown_4094 + 0x40)).palette_ = 0;
        ++(*reinterpret_cast<int*>(self->unknown_4094 + 0x124));
    }
}
