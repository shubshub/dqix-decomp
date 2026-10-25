#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_021878b0 func_ov013_021888c0
#endif
#include "Filesystem/BackgroundLoader.h"

struct List0202fec8;
struct PacRecord;
int Pac_CountFiles(struct PacRecord* entry);
void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

extern "C" void WindowPane_Init(void* obj);
extern "C" void func_ov013_02187a58(void* obj, void* buf);
extern "C" void Background_LoadFile(void* list, void* payload, int a3, int a4);

struct BackgroundGraphics;
void* Background_GetScreen(struct BackgroundGraphics* list, unsigned int index);
struct Tilemap0204ae44;
void FillTilemapPalette0204ae44(struct Tilemap0204ae44* obj, int palette);
struct Obj0204b988;
void DispatchIndexedEntry0204b988(struct Obj0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);
void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);

extern const char data_ov013_02187eaf[];

struct Struct_ov013_021878b0 {
    char unknown_0_[0x28];
#if defined(jpn)
    char unknown_28_[0x20];
#else
    char unknown_28_[0x28];
    short* unknown_50_;
    short* unknown_54_;
    unsigned char* unknown_58_;
#endif
    int unknown_5c_;
    char unknown_60_[6];
    unsigned char unknown_66_;
    signed char unknown_67_;
    unsigned char unknown_68_;
    unsigned char unknown_69_;
#if !defined(jpn)
    signed char unknown_6a_;
#endif
};

struct Struct_ov013_021878b0_2 {
    char unknown_0_[0x8];
    void* unknown_8_;
    char unknown_c_[0xa8 - 0xc];
    unsigned short unknown_a8_;
    unsigned short unknown_aa_;
    char unknown_ac_[0xb4 - 0xac];
    unsigned short unknown_b4_;
    unsigned short unknown_b6_;
    char unknown_b8_[0xe0 - 0xb8];
};

// USA: func_ov013_021878b0
extern "C" ARM void func_ov013_021878b0(Struct_ov013_021878b0* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    unsigned char var1 = arg0->unknown_66_;

    if (var1 == 0) {
#if !defined(jpn)
        for (int var2 = 0; var2 < 10; var2++) {
            arg0->unknown_50_[var2] = -1;
            arg0->unknown_54_[var2] = -1;
            arg0->unknown_58_[var2] = 2;
        }
        arg0->unknown_6a_ = -1;
#endif
        loader->MaybeFreeAllocations();
        window->loadTask = loader->QueueLoadFile(data_ov013_02187eaf, NULL);
        window->loadState++;
    } else if (loadState == 1) {
        if (loader->GetTaskStatus(window->loadTask) != 0) {
            void* recOut;
            void* file;
            unsigned int fileSize;
            int field44;
            loader->GetLoadedFileByID(window->loadTask, &file, &fileSize);
            Pac_CountFiles((struct PacRecord*)file);
            void* end = Pac_GetFile((struct PacRecord*)file, 0, &recOut, &field44);
            if (end != 0) {
                LocalBuf021878b0 buf;
                WindowPane_Init(&buf);
                buf.field8 = (char*)end + 0x10;
                buf.halfB4 = 0xa;
                buf.halfB6 = 0xb;
                buf.halfA8 = 0x20;
                buf.halfAA = 0x18;
                func_ov013_02187a58(window, &buf);
                Background_LoadFile(window->entryList, end, 0, field44);
            }
            loader->RemoveTask(window->loadTask);
            window->loadTask = -1;
            void* e = Background_GetScreen((struct BackgroundGraphics*)window->entryList, 0);
            if (e != 0) {
                FillTilemapPalette0204ae44((struct Tilemap0204ae44*)e, window->partyIndex);
            }
            DispatchIndexedEntry0204b988((struct Obj0204b988*)window->entryList, 0, 0, 0, 0xffff);
            Background_UploadMap((struct BackgroundGraphics*)window->entryList, 0);
            window->loadState = 0;
            window->flags &= ~1;
        }
    }
}
