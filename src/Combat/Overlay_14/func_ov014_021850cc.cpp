#include <globaldefs.h>

#if defined(jpn)
#define func_ov014_021850cc func_ov014_021861cc
#endif
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

struct Struct_ov014_02184f78 {
    Struct_ov014_02184f78* unknown_0_;
    const char* unknown_4_;
    const char* name_;
    short unknown_c_;
    char unknown_e_[4];
    signed char unknown_12_;
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 6;
    char unk_14[6];
    short unknown_1a_;
    char unk_1c[4];
};

struct MonsterRecord {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 1;
    unsigned int unknown_1_3_ : 7;
    unsigned int unknown_2_2_ : 7;
    unsigned int unknown_3_1_ : 7;
};

struct Struct_ov014_021850cc_3 {
    char unk_0[8];
    short unknown_8_[2];
    unsigned char unknown_c_;
    char unk_d[3];
    float position_[3];
    float unknown_1c_;
    float scale_[3];
    const char** animations_;
};

struct Struct_ov014_021850cc {
    unsigned int unknown_0_;
    char unk_4[2];
    unsigned short count_;
};

struct Struct_02000c9c_52 {
    char unk_0[0x10];
};

struct Struct_ov014_021850cc_2 {
    unsigned int unknown_0_;
    short unknown_4_;
    unsigned short count_;
};

struct Struct_ov014_02188bfc {
    char unk_0[0x20];
};

struct Struct_ov014_02184dcc {
    void** unknown_0_;
    void* spriteRenderer_;
    void* sprites_;
    Struct_02000c9c_52 unknown_c_;
    Struct_ov014_02188bfc unknown_1c_;
    SafeAllocator* allocators_;
    Object3D* model_;
    void* camera_;
    Struct_ov014_02184f78* unknown_48_;
    Struct_ov014_02184f78* unknown_4c_;
    MonsterRecord* unknown_50_;
    MonsterRecord* unknown_54_;
    void* layout_;
    void* texts_;
    char* unknown_60_[2];
    char* description_;
    int unknown_6c_;
    int unknown_70_;
    int unknown_74_;
    int unknown_78_;
    unsigned char state_;
    unsigned char unknown_7d_;
    unsigned char unknown_7e_;
    unsigned char unknown_7f_;
    unsigned char page_;
    unsigned char flags_;
    unsigned char unknown_82_0_ : 1;
    unsigned char unknown_82_1_ : 1;
    unsigned char unknown_82_2_ : 1;
    unsigned char unknown_82_3_ : 1;
    unsigned char unknown_82_4_ : 4;
    short unknown_84_;
    short unknown_86_[5];
    unsigned char unknown_90_[3];
    unsigned char unknown_93_;
    unsigned char unknown_94_;
    short* unknown_98_;
    Struct_ov014_021850cc_2 unknown_9c_;
};

struct Struct_ov014_021845d4;
struct Struct_02097238;
struct Struct_02097054_5;
struct Struct020dfc40;
struct Foo0207df50;
struct Struct_203dafc;

extern char data_ov014_021895d5[];
extern char data_ov014_021895ed[];
extern char data_ov014_02189603[];
extern char data_ov014_02189615[];
extern char data_ov014_0218962c[];
extern char data_ov014_0218963f[];
extern char data_ov014_02189652[];
extern char data_ov014_02189661[];
extern char data_ov014_02189668[];
extern char data_ov014_02189680[];
extern char data_ov014_02189686[];
extern char data_ov014_0218968c[];

extern "C" bool func_ov014_02188bfc(Struct_ov014_02188bfc* arg0, SafeAllocator* allocator, short arg2);
extern "C" bool func_ov014_02188c34(Struct_ov014_02188bfc* arg0);
extern "C" void func_ov014_021845d4(Struct_ov014_021845d4* best);
extern "C" void func_02096fb0(void* table);
extern "C" void func_02097054(Struct_02000c9c_52* table, SafeAllocator* allocator, void* file, unsigned int size, short arg4);
extern "C" Struct_ov014_021850cc* func_02097238(Struct_02097238* table);
extern "C" Struct_ov014_021850cc_3* func_02097224(Struct_02097054_5* table, int arg1);
extern "C" void func_020e526c(void* reader);
extern "C" void func_020e56fc(void* reader, int file, int size);
extern "C" const char** func_020e5294(void* reader, int id);
extern "C" void func_020e4864(const char* input, char* output, int, int, int, int);
extern "C" void* KeyTable_Construct(void* text);
extern "C" void KeyTable_Reset(Struct020dfc40* text);
extern "C" void func_020e046c(char* output, void* file, unsigned int size, short arg3);
extern "C" void VramState_Rewind(Foo0207df50* p);
extern "C" void VramState_Restore(char* p);
extern "C" void VramState_Save(char* p);
extern "C" void func_0203dafc(Struct_203dafc* info);
extern "C" void func_ov014_02184c08(unsigned char* screen);

#if defined(jpn)
extern "C" int KeyTable_LoadInPlace(void* reader, void* file, int size);
extern "C" char* func_020e207c(void* reader, char* output, int itemID);
#endif

// USA: func_ov014_021850cc
extern "C" ARM void func_ov014_021850cc(Struct_ov014_02184dcc* self) {
    if (!(self->flags_ & 1))
        return;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->unknown_7f_ == 0) {
#if !defined(jpn)
        char archive[0x40] = {};
#endif
        char file[0x40] = {};
        if (self->unknown_82_2_)
            self->unknown_86_[0] = loader->QueueLoadFile(data_ov014_021895d5, NULL);
        self->allocators_[1].Reset();
        func_ov014_02188bfc(&self->unknown_1c_, &self->allocators_[1], self->unknown_48_->unknown_1a_);
#if defined(jpn)
        self->unknown_86_[1] = loader->QueueLoadFile(data_ov014_021895ed, NULL);
        sprintf(file, data_ov014_02189615, self->page_ + 1);
        self->unknown_86_[2] = loader->QueueLoadFile(file, NULL);
        self->unknown_86_[3] = loader->QueueLoadFile(data_ov014_0218963f, NULL);
#else
        self->unknown_86_[1] = loader->QueueLoadFileInGP2(data_ov014_021895ed, data_ov014_02189603, NULL);
        sprintf(archive, data_ov014_02189615, self->page_ + 1);
        sprintf(file, data_ov014_0218962c, self->page_ + 1);
        self->unknown_86_[2] = loader->QueueLoadFileInGP2(archive, file, NULL);
        self->unknown_86_[3] = loader->QueueLoadFileInGP2(data_ov014_0218963f, data_ov014_02189652, NULL);
#endif
        if (self->unknown_82_2_ && self->unknown_48_ != NULL && self->unknown_50_ != NULL && self->unknown_48_->unknown_13_1_ && self->unknown_48_->unknown_4_ != NULL) {
            sprintf(file, data_ov014_02189661, self->unknown_48_->unknown_4_);
            self->unknown_86_[4] = loader->QueueLoadFileInGP2(data_ov014_02189668, file, NULL);
        }
        self->unknown_7f_++;
    } else if (self->unknown_7f_ == 1) {
        if (self->unknown_82_2_) {
            if (loader->GetTaskStatus(self->unknown_86_[0])) {
                void* file;
                unsigned int size;
                loader->GetLoadedFileByID(self->unknown_86_[0], &file, &size);
                if (file != NULL) {
                    short* variant = self->unknown_98_;
                    func_ov014_021845d4((Struct_ov014_021845d4*)&self->unknown_9c_);
                    SafeAllocator* allocator = &self->allocators_[0];
                    for (; *variant != 0; variant++) {
                        allocator->Reset();
                        short var7 = *variant;
                        func_02096fb0(&self->unknown_c_);
                        func_02097054(&self->unknown_c_, allocator, file, size, var7);
                        Struct_ov014_021850cc* count = func_02097238((Struct_02097238*)&self->unknown_c_);
                        if (self->unknown_9c_.unknown_4_ < 0
                            || (count != NULL && (count->unknown_0_ > self->unknown_9c_.unknown_0_ || count->count_ > self->unknown_9c_.count_))) {
                            self->unknown_9c_.unknown_4_ = var7;
                            self->unknown_9c_.unknown_0_ = count->unknown_0_;
                            self->unknown_9c_.count_ = count->count_;
                        }
                    }
                    allocator->Reset();
                    short var9 = self->unknown_48_->unknown_c_;
                    func_02096fb0(&self->unknown_c_);
                    func_02097054(&self->unknown_c_, allocator, file, size, var9);
                    func_02097238((Struct_02097238*)&self->unknown_c_);
                }
                loader->RemoveTask(self->unknown_86_[0]);
                self->unknown_86_[0] = -1;
                self->unknown_7f_++;
            }
        } else {
            self->unknown_7f_++;
        }
    }

    if (self->unknown_7f_ == 2) {
        if (func_ov014_02188c34(&self->unknown_1c_))
            self->unknown_7f_++;
    }

    if (self->unknown_7f_ == 3 && loader->GetTaskStatus(self->unknown_86_[1])) {
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->unknown_86_[1], &file, &size);
        if (file != NULL) {
            Struct_ov014_021850cc_3* info = func_02097224((Struct_02097054_5*)&self->unknown_c_, self->unknown_48_->unknown_c_);
            if (info != NULL) {
#if defined(jpn)
                char reader[0x18];
                KeyTable_Construct(reader);
                KeyTable_Reset((Struct020dfc40*)reader);
                KeyTable_LoadInPlace(reader, file, size);
                func_020e207c(reader, self->unknown_60_[0], info->unknown_8_[0]);
                func_020e207c(reader, self->unknown_60_[1], info->unknown_8_[1]);
#else
                char reader[0xc];
                func_020e526c(reader);
                func_020e56fc(reader, (int)file, size);
                const char** name = func_020e5294(reader, info->unknown_8_[0]);
                if (name != NULL) {
                    memset(self->unknown_60_[0], 0, 0x48);
                    func_020e4864(*name, self->unknown_60_[0], 1, 0, 0, 0);
                }
                name = func_020e5294(reader, info->unknown_8_[1]);
                if (name != NULL) {
                    memset(self->unknown_60_[1], 0, 0x48);
                    func_020e4864(*name, self->unknown_60_[1], 1, 0, 0, 0);
                }
#endif
            }
        }
        loader->RemoveTask(self->unknown_86_[1]);
        self->unknown_86_[1] = -1;
        self->unknown_7f_++;
    }

    if (self->unknown_7f_ == 4 && loader->GetTaskStatus(self->unknown_86_[2])) {
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->unknown_86_[2], &file, &size);
        if (file != NULL) {
            char text[0x18];
            KeyTable_Construct(text);
            KeyTable_Reset((Struct020dfc40*)text);
            func_020e046c(self->description_, file, size, self->unknown_48_->unknown_1a_);
        }
        loader->RemoveTask(self->unknown_86_[2]);
        self->unknown_86_[2] = -1;
        self->unknown_7f_++;
    }

    if (self->unknown_7f_ == 6) {
        if (!(self->flags_ & 8) && self->unknown_86_[4] == -1) {
            self->unknown_7f_ = 0;
            self->flags_ &= ~9;
        }
        self->unknown_7f_++;
    }

    if (self->unknown_7f_ == 7) {
        if (self->unknown_82_2_) {
            if (loader->GetTaskStatus(self->unknown_86_[4])) {
                self->flags_ &= ~4;
                self->unknown_7f_++;
            }
        } else {
            self->unknown_7f_++;
        }
    } else if (self->unknown_7f_ == 8) {
        if (self->unknown_82_2_) {
            SafeAllocator* allocator = &self->allocators_[2];
            allocator->Reset();
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->unknown_86_[4], &file, &size);
            if (file != NULL) {
                GameResources* resources = GetGameResources();
                const void* found;
                unsigned int var24;
                if (FindFilesInNarcBySubstring(file, data_ov014_02189680, &found, &var24, 1)) {
                    unsigned int characterSize;
                    void* character = DecompressLZ77FileIntoAllocatedSpace(*allocator, found, characterSize);
                    if (FindFilesInNarcBySubstring(file, data_ov014_02189686, &found, &var24, 1)) {
                        unsigned int motionSize;
                        void* motion = DecompressLZ77FileIntoAllocatedSpace(*allocator, found, motionSize);
                        const void* actions;
                        unsigned int var30;
                        if (FindFilesInNarcBySubstring(file, data_ov014_0218968c, &actions, &var30, 1)) {
                            self->model_->Initialize();
                            self->model_->unknown_2_ = self->unknown_48_->unknown_c_;
                            self->model_->EnableFlag(4);
                            VramState_Rewind((Foo0207df50*)resources->vramStates_);
                            VramState_Restore(resources->vramStates_);
                            ObjectArchiveLoadInfo loadInfo;
                            func_0203dafc((Struct_203dafc*)&loadInfo);
                            loadInfo.fileData = character;
                            loadInfo.allocator = allocator;
                            loadInfo.fileSize = characterSize;
                            self->model_->LoadFromCCHROrCMOTArchive(&loadInfo, NULL);
                            VramState_Save(resources->vramStates_);
                            func_0203dafc((Struct_203dafc*)&loadInfo);
                            loadInfo.allocator = allocator;
                            loadInfo.fileData = motion;
                            loadInfo.fileSize = motionSize;
                            self->model_->LoadFromCCHROrCMOTArchive(&loadInfo, NULL);
                            func_ov014_02184c08((unsigned char*)self);
                            self->unknown_74_ = 0;
                            Struct_ov014_021850cc_3* info = func_02097224((Struct_02097054_5*)&self->unknown_c_, self->unknown_48_->unknown_c_);
                            if (info != NULL)
                                self->model_->SetAnimationByName(info->animations_[0], 0);
                            self->flags_ |= 4;
                        }
                    }
                }
            }
            loader->RemoveTask(self->unknown_86_[4]);
            self->unknown_86_[4] = -1;
        }
        self->unknown_7f_ = 0;
        self->flags_ &= ~9;
        if (self->unknown_82_3_)
            self->unknown_82_3_ = false;
        self->unknown_94_ = self->unknown_93_;
        self->unknown_93_ = false;
    }
}
