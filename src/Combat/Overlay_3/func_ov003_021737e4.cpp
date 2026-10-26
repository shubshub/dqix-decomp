#include <globaldefs.h>
#if defined(jpn)
#include "std_library_functions.h"
#endif
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/BGBases.h"
#include "NitroSDK/Memory.h"
#include "Resource/GameResources.h"

struct TableA68 {
    struct Struct_02072a68* entries;
    short count;
};
struct PacRecord;

struct Struct_ov003_021737e4 {
    void* unk_0;
    void* background_;
    void* pixels_;
    char unk_c[0xa8 - 0xc];
    short width_;
    short height_;
    char unk_ac[0xb4 - 0xac];
    short unknown_b4_;
    short unknown_b6_;
    char unk_b8[0xe0 - 0xb8];
};

#if defined(jpn)
struct Struct_ov003_021737e4_2 {
    unsigned char unk_0;
    unsigned char unknown_1_;
    char unknown_2_[0x40];
    char unknown_42_[0x80];
    char unknown_c2_[0xc4 - 0xc2];
    short unknown_c4_;
    short unknown_c6_;
    char unknown_c8_[0xd0 - 0xc8];
    unsigned char slot_;
    char unknown_d1_[0xd4 - 0xd1];
    char unknown_d4_[0xe9 - 0xd4];
    unsigned char unknown_e9_;
    unsigned char unknown_ea_;
    unsigned char unknown_eb_;
    char unknown_ec_[0xf8 - 0xec];
    int task_;
};

extern "C" void func_020a620c(void* obj);
extern "C" int Pac_CountFiles(PacRecord* pac);
extern "C" void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void WindowPane_Init(void* canvas);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void __clear(void*, unsigned int);
extern "C" void func_02041f50(char*, char*);
extern "C" int func_02042798(const char*, int, int);
extern "C" void func_02050678(Struct_ov003_021737e4*, short, short, const char*, int, unsigned char, short*, short*);

extern char data_ov003_02180a76[];
extern char data_ov003_0217ec90[];
extern char data_ov003_0217ec99[];
extern char data_ov003_0217eca2[];
extern char data_ov003_0217ecbc[];
extern char data_ov003_0217ecc3[];
extern char data_ov003_0217ebff[];

// USA: func_ov003_021737e4
extern "C" ARM void func_ov003_021737e4(Struct_ov003_021737e4_2* self) {
    GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_020a620c(self->unknown_d4_);
    if (self->unknown_eb_ == 0) {
        self->task_ = loader->QueueLoadFile(data_ov003_02180a76, NULL);
        self->unknown_eb_ = 1;
    } else if (self->unknown_eb_ == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) {
            return;
        }
        void* name;
        void* file;
        unsigned int size;
        void* records[3];
        int sizes[3];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count = Pac_CountFiles((PacRecord*)file);
        for (int i = 0; i < count; i++) {
            records[i] = Pac_GetFile((PacRecord*)file, i, &name, &sizes[i]);
        }
        void* tiles = self->unknown_1_ ? records[1] : records[0];
        Struct_ov003_021737e4 canvas;
        WindowPane_Init(&canvas);
        canvas.pixels_ = (char*)tiles + 0x10;
        canvas.width_ = 0x20;
        canvas.height_ = 8;
        canvas.unknown_b4_ = 0xc;
        canvas.unknown_b6_ = 0xc;
        Zone3D_GetInstance();
        char title[0x100];
        char var11[0x100];
        char line[0x100];
        short width;
        short height;
        int x;
        __clear(title, sizeof(title));
        __clear(var11, sizeof(var11));
        __clear(line, sizeof(line));
        if (self->unknown_1_ != 0) {
            sprintf(line, data_ov003_0217ec90, self->unknown_2_);
            int y = 4;
            if (strstr(self->unknown_2_, data_ov003_0217ec99)) {
                sprintf(title, data_ov003_0217eca2);
                func_02041f50(title, var11);
                x = func_02042798(title, 0x100, 0xc);
                func_02050678(&canvas, x + 1, 0x16, var11, 0xc, 0xe, &width, &height);
                func_02050678(&canvas, x, 0x16, title, 0xc, 0xf, &width, &height);
                y = 0xf;
            } else if (strstr(self->unknown_2_, data_ov003_0217ecbc)) {
                sprintf(title, data_ov003_0217ecc3);
                func_02041f50(title, var11);
                x = func_02042798(title, 0x100, 0xc);
                func_02050678(&canvas, x + 1, 0x16, var11, 0xc, 0xe, &width, &height);
                func_02050678(&canvas, x, 0x16, title, 0xc, 0xf, &width, &height);
                y = 0xf;
            }
            x = func_02042798(line, 0x100, 0xd);
            func_02050678(&canvas, x + 1, y + 0x16, line, 0xc, 0xe, &width, &height);
            func_02050678(&canvas, x, y + 0x16, line, 0xc, 0xf, &width, &height);
        } else {
            sprintf(title, data_ov003_0217ebff, self->unknown_42_);
            func_02041f50(title, var11);
            sprintf(line, data_ov003_0217ec90, self->unknown_2_);
            x = func_02042798(title, 0x100, 0xc);
            func_02050678(&canvas, x + 1, 0x16, var11, 0xc, 0xe, &width, &height);
            func_02050678(&canvas, x, 0x16, title, 0xc, 0xf, &width, &height);
            x = func_02042798(line, 0x100, 0xc);
            func_02050678(&canvas, x + 1, 0x25, line, 0xc, 0xe, &width, &height);
            func_02050678(&canvas, x, 0x25, line, 0xc, 0xf, &width, &height);
        }
        int offset = (self->slot_ - 1) * 0x2000 + 0x1000;
        CleanInvalidateCacheRange((char*)tiles + 0x10, 0x2000);
        LoadToSubBG0CharacterData((char*)tiles + 0x10, offset, 0x2000);
        int palette;
        if (self->unknown_1_) {
            palette = 3;
        } else {
            palette = 2;
        }
        unsigned short* screen = (unsigned short*)GetSubBG0ScreenBase();
        for (int i = 0; i < 0x100; i++) {
            *(screen + i + (self->slot_ - 1) * 0x100) =
                (unsigned short)(i + 0x80 + (self->slot_ - 1) * 0x100) | (unsigned short)(palette << 12);
        }
        self->unknown_c6_ = (self->slot_ << 6) - 0xc0;
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->unknown_eb_ = 2;
    } else if (self->unknown_eb_ == 2) {
        if (self->unknown_c4_ < self->unknown_c6_) {
            self->unknown_c4_ += (int)(0.4f * (self->unknown_c6_ - self->unknown_c4_)) + 1;
            *(volatile unsigned int*)0x04001010 = (self->unknown_c4_ << 16) & 0x1ff0000;
        }
        if (self->unknown_c4_ >= self->unknown_c6_) {
            self->unknown_c4_ = self->unknown_c6_;
            *(volatile unsigned int*)0x04001010 = (self->unknown_c4_ << 16) & 0x1ff0000;
            self->unknown_1_ = 0;
            VectorizedMemset(self->unknown_2_, 0, 0x40);
            VectorizedMemset(self->unknown_42_, 0, 0x80);
            self->unknown_e9_ = 2;
            self->unknown_eb_ = 0;
        }
    }
}
#else
struct Struct_ov003_021737e4_2 {
    unsigned char unk_0;
    unsigned char unknown_1_;
    short unknown_2_;
    char unknown_4_[0x40];
    char unknown_44_[0x80];
    char unknown_c4_[0xc6 - 0xc4];
    short unknown_c6_;
    short unknown_c8_;
    char unknown_ca_[0xd4 - 0xca];
    unsigned char slot_;
    char unknown_d5_[0xd8 - 0xd5];
    char unk_d8[0xed - 0xd8];
    unsigned char unknown_ed_;
    unsigned char unk_ee;
    unsigned char unknown_ef_;
    char unknown_f0_[0xf4 - 0xf0];
    int task_;
    char unknown_f8_[0x1d8 - 0xf8];
    TableA68 text_;
};

extern "C" void func_020a620c(void* obj);
extern "C" int Pac_CountFiles(PacRecord* pac);
extern "C" void* Pac_GetFile(PacRecord* pac, int index, void** outName, int* outSize);
extern "C" void WindowPane_Init(void* canvas);
extern "C" void* Zone3D_GetInstance(void);
extern "C" char* func_02072a68(TableA68* table, int key);
extern "C" void func_ov003_02172618(void* canvas, int y, char** labels);

extern char data_ov003_02180a76[];

// USA: func_ov003_021737e4
extern "C" ARM void func_ov003_021737e4(Struct_ov003_021737e4_2* self) {
    GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_020a620c(self->unk_d8);
    if (self->unknown_ef_ == 0) {
        self->task_ = loader->QueueLoadFile(data_ov003_02180a76, NULL);
        self->unknown_ef_ = 1;
    } else if (self->unknown_ef_ == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) {
            return;
        }
        void* name;
        void* file;
        unsigned int size;
        void* records[3];
        int sizes[3];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count = Pac_CountFiles((PacRecord*)file);
        for (int i = 0; i < count; i++) {
            records[i] = Pac_GetFile((PacRecord*)file, i, &name, &sizes[i]);
        }
        void* tiles = self->unknown_1_ ? records[1] : records[0];
        Struct_ov003_021737e4 canvas;
        WindowPane_Init(&canvas);
        canvas.pixels_ = (char*)tiles + 0x10;
        canvas.width_ = 0x20;
        canvas.height_ = 8;
        canvas.unknown_b4_ = 0xc;
        canvas.unknown_b6_ = 0xc;
        Zone3D_GetInstance();
        if (self->unknown_1_ != 0) {
            char* labels[2] = {0};
            labels[1] = self->unknown_4_;
            int y = 4;
            if (self->unknown_2_ == 1) {
                labels[0] = func_02072a68(&self->text_, 0xc8);
                y = 0xf;
            } else if (self->unknown_2_ == 2) {
                labels[0] = func_02072a68(&self->text_, 0xc9);
                y = 0xf;
            }
            func_ov003_02172618(&canvas, y, labels);
        } else {
            char* labels[2] = {self->unknown_44_, self->unknown_4_};
            func_ov003_02172618(&canvas, 0xf, labels);
        }
        int offset = (self->slot_ - 1) * 0x2000 + 0x1000;
        CleanInvalidateCacheRange((char*)tiles + 0x10, 0x2000);
        LoadToSubBG0CharacterData((char*)tiles + 0x10, offset, 0x2000);
        int palette = 2;
        if (self->unknown_1_) {
            palette = 3;
        }
        unsigned short* screen = (unsigned short*)GetSubBG0ScreenBase();
        for (int i = 0; i < 0x100; i++) {
            *(screen + i + (self->slot_ - 1) * 0x100) =
                (unsigned short)(i + 0x80 + (self->slot_ - 1) * 0x100) | (unsigned short)(palette << 12);
        }
        self->unknown_c8_ = (self->slot_ << 6) - 0xc0;
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->unknown_ef_ = 2;
    } else if (self->unknown_ef_ == 2) {
        if (self->unknown_c6_ < self->unknown_c8_) {
            self->unknown_c6_ += (int)(0.4f * (self->unknown_c8_ - self->unknown_c6_)) + 1;
            *(volatile unsigned int*)0x04001010 = (self->unknown_c6_ << 16) & 0x1ff0000;
        }
        if (self->unknown_c6_ >= self->unknown_c8_) {
            self->unknown_c6_ = self->unknown_c8_;
            *(volatile unsigned int*)0x04001010 = (self->unknown_c6_ << 16) & 0x1ff0000;
            self->unknown_1_ = 0;
            self->unknown_2_ = -1;
            VectorizedMemset(self->unknown_4_, 0, 0x40);
            VectorizedMemset(self->unknown_44_, 0, 0x80);
            self->unknown_ed_ = 2;
            self->unknown_ef_ = 0;
        }
    }
}
#endif
