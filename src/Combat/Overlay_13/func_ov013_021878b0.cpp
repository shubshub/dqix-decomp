#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_021878b0 func_ov013_021888c0
#endif
#include "Filesystem/BackgroundLoader.h"

struct Struct_020534ac;
struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* entry);
extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

extern "C" void WindowPane_Init(void* obj);
extern "C" void func_ov013_02187a58(void* obj, void* buf);
extern "C" void Background_LoadFile(void* list, void* payload, int a3, int a4);

struct BackgroundGraphics;
extern "C" void* Background_GetScreen(struct BackgroundGraphics* list, unsigned int index);
struct Struct_0204ae44;
extern "C" void func_0204ae44(struct Struct_0204ae44* obj, int palette);
struct Struct_0204b988;
extern "C" void func_0204b988(struct Struct_0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);
extern "C" void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);

extern const char data_ov013_02187eaf[];

struct Struct_ov013_021878b0 {
    char unknown0[0x28];
#if defined(jpn)
    char entryList[0x20];
#else
    char entryList[0x28];
    short* iconX;
    short* iconY;
    unsigned char* unknown_58_;
#endif
    int loadTask;
    char unknown_60_[6];
    unsigned char unknown_66_;
    signed char partyIndex;
    unsigned char unknown_68_;
    unsigned char flags;
#if !defined(jpn)
    signed char unknown_6a_;
#endif
};

struct Struct_ov013_021878b0_2 {
    char pad0[0x8];
    void* field8;
    char pad10[0xa8 - 0xc];
    unsigned short unknown_a8_;
    unsigned short unknown_aa_;
    char padAC[0xb4 - 0xac];
    unsigned short unknown_b4_;
    unsigned short unknown_b6_;
    char unknown_b8_[0xe0 - 0xb8];
};

// USA: func_ov013_021878b0
extern "C" ARM void func_ov013_021878b0(Struct_ov013_021878b0* window) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char var1 = window->unknown_66_;

    if (var1 == 0) {
#if !defined(jpn)
        for (int i = 0; i < 10; i++) {
            window->iconX[i] = -1;
            window->iconY[i] = -1;
            window->unknown_58_[i] = 2;
        }
        window->unknown_6a_ = -1;
#endif
        loader->FreeAllocations();
        window->loadTask = loader->QueueLoadFile(data_ov013_02187eaf, NULL);
        window->unknown_66_++;
    } else if (var1 == 1) {
        if (loader->GetTaskStatus(window->loadTask) != 0) {
            void* recOut;
            void* file;
            unsigned int fileSize;
            int field44;
            loader->GetLoadedFileByID(window->loadTask, &file, &fileSize);
            Pac_CountFiles((struct PacRecord*)file);
            void* end = Pac_GetFile((struct PacRecord*)file, 0, &recOut, &field44);
            if (end != 0) {
                Struct_ov013_021878b0_2 buf;
                WindowPane_Init(&buf);
                buf.field8 = (char*)end + 0x10;
                buf.unknown_b4_ = 0xa;
                buf.unknown_b6_ = 0xb;
                buf.unknown_a8_ = 0x20;
                buf.unknown_aa_ = 0x18;
                func_ov013_02187a58(window, &buf);
                Background_LoadFile(window->entryList, end, 0, field44);
            }
            loader->RemoveTask(window->loadTask);
            window->loadTask = -1;
            void* e = Background_GetScreen((struct BackgroundGraphics*)window->entryList, 0);
            if (e != 0) {
                func_0204ae44((struct Struct_0204ae44*)e, window->partyIndex);
            }
            func_0204b988((struct Struct_0204b988*)window->entryList, 0, 0, 0, 0xffff);
            Background_UploadMap((struct BackgroundGraphics*)window->entryList, 0);
            window->unknown_66_ = 0;
            window->flags &= ~1;
        }
    }
}
