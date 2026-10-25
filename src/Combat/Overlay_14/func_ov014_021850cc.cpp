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
    const char* unknown_8_;
    short unknown_c_;
    char unknown_e_[4];
    signed char unknown_12_;
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 6;
    char unknown_14_[6];
    short unknown_1a_;
    char unknown_1c_[4];
};

struct Struct_020a95a4_5 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 1;
    unsigned int unknown_1_3_ : 7;
    unsigned int unknown_2_2_ : 7;
    unsigned int unknown_3_1_ : 7;
};

struct Struct_ov014_021850cc_3 {
    char unknown_0_[8];
    short unknown_8_[2];
    unsigned char unknown_c_;
    char unknown_d_[3];
    float unknown_10_[3];
    float unknown_1c_;
    float unknown_20_[3];
    const char** unknown_2c_;
};

struct Struct_ov014_021850cc {
    unsigned int unknown_0_;
    char unknown_4_[2];
    unsigned short unknown_6_;
};

struct Struct_02000c9c_52 {
    char unknown_0_[0x10];
};

struct Struct_ov014_021850cc_2 {
    unsigned int unknown_0_;
    short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_ov014_02188bfc {
    char unknown_0_[0x20];
};

struct Struct_ov014_02184dcc {
    void** unknown_0_;
    void* unknown_4_;
    void* unknown_8_;
    Struct_02000c9c_52 unknown_c_;
    Struct_ov014_02188bfc unknown_1c_;
    SafeAllocator* unknown_3c_;
    Object3D* unknown_40_;
    void* unknown_44_;
    Struct_ov014_02184f78* unknown_48_;
    Struct_ov014_02184f78* unknown_4c_;
    Struct_020a95a4_5* unknown_50_;
    Struct_020a95a4_5* unknown_54_;
    void* unknown_58_;
    void* unknown_5c_;
    char* unknown_60_[2];
    char* unknown_68_;
    int unknown_6c_;
    int unknown_70_;
    int unknown_74_;
    int unknown_78_;
    unsigned char unknown_7c_;
    unsigned char unknown_7d_;
    unsigned char unknown_7e_;
    unsigned char unknown_7f_;
    unsigned char unknown_80_;
    unsigned char unknown_81_;
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
struct Struct_0201099c_14;
struct Struct_0203d028;
struct Struct_0203d028_11;

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

extern "C" bool func_ov014_02188bfc(HabitatTable* habitats, SafeAllocator* allocator, short monsterID);
extern "C" bool func_ov014_02188c34(HabitatTable* habitats);
void ResetFields_021845d4(ResetFieldsStruct021845d4* best);
void Clear0x10Bytes02096fb0(void* table);
extern "C" void func_02097054(MonsterInfoTable* table, SafeAllocator* allocator, void* file, unsigned int size, short monsterID);
MonsterRecordCount* GetHandleField8(HandleField8_02097238* table);
MonsterInfo* BinarySearchByField4_02097224(BinarySearch020971a8Container* table, int monsterID);
void Zero4Bytes_020e526c(void* reader);
void TryInvoke020e53bc_020e56fc(void* reader, int file, int size);
const char** CallFunc020e52a0_020e5294(void* reader, int id);
extern "C" void func_020e4864(const char* input, char* output, int, int, int, int);
void* ResetAndReturnSelf020dfc2c(void* text);
void KeyTable_Reset(Struct020dfc40* text);
extern "C" void func_020e046c(char* output, void* file, unsigned int size, short infoID);
void VramState_Rewind(Foo0207df50* p);
void VramState_Restore(char* p);
void VramState_Save(char* p);
void ClearEightWords_0203dafc(Struct_203dafc* info);
void ComputeAndStoreVecs02184c08(unsigned char* screen);

#if defined(jpn)
int KeyTable_LoadInPlace(void* reader, void* file, int size);
extern "C" char* func_020e207c(void* reader, char* output, int itemID);
#endif

// USA: func_ov014_021850cc
extern "C" ARM void func_ov014_021850cc(Struct_ov014_02184dcc* arg0) {
    if (!(arg0->unknown_81_ & 1))
        return;

    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_7f_ == 0) {
#if !defined(jpn)
        char var1[0x40] = {};
#endif
        char var2[0x40] = {};
        if (arg0->unknown_82_2_)
            arg0->unknown_86_[0] = var0->QueueLoadFile(data_ov014_021895d5, NULL);
        arg0->unknown_3c_[1].Reset();
        func_ov014_02188bfc(&arg0->unknown_1c_, &arg0->unknown_3c_[1], arg0->unknown_48_->unknown_1a_);
#if defined(jpn)
        arg0->unknown_86_[1] = var0->QueueLoadFile(data_ov014_021895ed, NULL);
        sprintf(var2, data_ov014_02189615, arg0->unknown_80_ + 1);
        arg0->unknown_86_[2] = var0->QueueLoadFile(var2, NULL);
        arg0->unknown_86_[3] = var0->QueueLoadFile(data_ov014_0218963f, NULL);
#else
        arg0->unknown_86_[1] = var0->QueueLoadFileInGP2(data_ov014_021895ed, data_ov014_02189603, NULL);
        sprintf(var1, data_ov014_02189615, arg0->unknown_80_ + 1);
        sprintf(var2, data_ov014_0218962c, arg0->unknown_80_ + 1);
        arg0->unknown_86_[2] = var0->QueueLoadFileInGP2(var1, var2, NULL);
        arg0->unknown_86_[3] = var0->QueueLoadFileInGP2(data_ov014_0218963f, data_ov014_02189652, NULL);
#endif
        if (arg0->unknown_82_2_ && arg0->unknown_48_ != NULL && arg0->unknown_50_ != NULL && arg0->unknown_48_->unknown_13_1_ && arg0->unknown_48_->unknown_4_ != NULL) {
            sprintf(var2, data_ov014_02189661, arg0->unknown_48_->unknown_4_);
            arg0->unknown_86_[4] = var0->QueueLoadFileInGP2(data_ov014_02189668, var2, NULL);
        }
        arg0->unknown_7f_++;
    } else if (arg0->unknown_7f_ == 1) {
        if (arg0->unknown_82_2_) {
            if (var0->GetTaskStatus(arg0->unknown_86_[0])) {
                void* var3;
                unsigned int var4;
                var0->GetLoadedFileByID(arg0->unknown_86_[0], &var3, &var4);
                if (var3 != NULL) {
                    short* var5 = arg0->unknown_98_;
                    func_ov014_021845d4((Struct_ov014_021845d4*)&arg0->unknown_9c_);
                    SafeAllocator* var6 = &arg0->unknown_3c_[0];
                    for (; *var5 != 0; var5++) {
                        var6->Reset();
                        short var7 = *var5;
                        func_02096fb0(&arg0->unknown_c_);
                        func_02097054(&arg0->unknown_c_, var6, var3, var4, var7);
                        Struct_ov014_021850cc* var8 = func_02097238((Struct_02097238*)&arg0->unknown_c_);
                        if (arg0->unknown_9c_.unknown_4_ < 0
                            || (var8 != NULL && (var8->unknown_0_ > arg0->unknown_9c_.unknown_0_ || var8->unknown_6_ > arg0->unknown_9c_.unknown_6_))) {
                            arg0->unknown_9c_.unknown_4_ = var7;
                            arg0->unknown_9c_.unknown_0_ = var8->unknown_0_;
                            arg0->unknown_9c_.unknown_6_ = var8->unknown_6_;
                        }
                    }
                    var6->Reset();
                    short var9 = arg0->unknown_48_->unknown_c_;
                    func_02096fb0(&arg0->unknown_c_);
                    func_02097054(&arg0->unknown_c_, var6, var3, var4, var9);
                    func_02097238((Struct_02097238*)&arg0->unknown_c_);
                }
                var0->RemoveTask(arg0->unknown_86_[0]);
                arg0->unknown_86_[0] = -1;
                arg0->unknown_7f_++;
            }
        } else {
            arg0->unknown_7f_++;
        }
    }

    if (arg0->unknown_7f_ == 2) {
        if (func_ov014_02188c34(&arg0->unknown_1c_))
            arg0->unknown_7f_++;
    }

    if (arg0->unknown_7f_ == 3 && var0->GetTaskStatus(arg0->unknown_86_[1])) {
        void* var10;
        unsigned int var11;
        var0->GetLoadedFileByID(arg0->unknown_86_[1], &var10, &var11);
        if (var10 != NULL) {
            Struct_ov014_021850cc_3* var12 = func_02097224((Struct_02097054_5*)&arg0->unknown_c_, arg0->unknown_48_->unknown_c_);
            if (var12 != NULL) {
#if defined(jpn)
                char reader[0x18];
                ResetAndReturnSelf020dfc2c(reader);
                KeyTable_Reset((Struct020dfc40*)reader);
                KeyTable_LoadInPlace(reader, file, size);
                func_020e207c(reader, self->dropNames_[0], info->dropItemIDs_[0]);
                func_020e207c(reader, self->dropNames_[1], info->dropItemIDs_[1]);
#else
                char var14[0xc];
                func_020e526c(var14);
                func_020e56fc(var14, (int)var10, var11);
                const char** var15 = func_020e5294(var14, var12->unknown_8_[0]);
                if (var15 != NULL) {
                    memset(arg0->unknown_60_[0], 0, 0x48);
                    func_020e4864(*var15, arg0->unknown_60_[0], 1, 0, 0, 0);
                }
                var15 = func_020e5294(var14, var12->unknown_8_[1]);
                if (var15 != NULL) {
                    memset(arg0->unknown_60_[1], 0, 0x48);
                    func_020e4864(*var15, arg0->unknown_60_[1], 1, 0, 0, 0);
                }
#endif
            }
        }
        var0->RemoveTask(arg0->unknown_86_[1]);
        arg0->unknown_86_[1] = -1;
        arg0->unknown_7f_++;
    }

    if (self->loadStep_ == 4 && loader->GetTaskStatus(self->taskIDs_[2])) {
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskIDs_[2], &file, &size);
        if (file != NULL) {
            char text[0x18];
            ResetAndReturnSelf020dfc2c(text);
            KeyTable_Reset((Struct020dfc40*)text);
            func_020e046c(self->description_, file, size, self->monster_->number_);
        }
        var0->RemoveTask(arg0->unknown_86_[2]);
        arg0->unknown_86_[2] = -1;
        arg0->unknown_7f_++;
    }

    if (arg0->unknown_7f_ == 6) {
        if (!(arg0->unknown_81_ & 8) && arg0->unknown_86_[4] == -1) {
            arg0->unknown_7f_ = 0;
            arg0->unknown_81_ &= ~9;
        }
        arg0->unknown_7f_++;
    }

    if (arg0->unknown_7f_ == 7) {
        if (arg0->unknown_82_2_) {
            if (var0->GetTaskStatus(arg0->unknown_86_[4])) {
                arg0->unknown_81_ &= ~4;
                arg0->unknown_7f_++;
            }
        } else {
            arg0->unknown_7f_++;
        }
    } else if (self->loadStep_ == 8) {
        if (self->loadModel_) {
            SafeAllocator* allocator = &self->allocators_[2];
            allocator->Reset();
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->taskIDs_[4], &file, &size);
            if (file != NULL) {
                GameResources* resources = GetGameResources();
                const void* found;
                unsigned int foundSize;
                if (FindFilesInNarcBySubstring(file, data_ov014_02189680, &found, &foundSize, 1)) {
                    unsigned int characterSize;
                    void* character = DecompressLZ77FileIntoAllocatedSpace(*allocator, found, characterSize);
                    if (FindFilesInNarcBySubstring(file, data_ov014_02189686, &found, &foundSize, 1)) {
                        unsigned int motionSize;
                        void* motion = DecompressLZ77FileIntoAllocatedSpace(*allocator, found, motionSize);
                        const void* actions;
                        unsigned int actionsSize;
                        if (FindFilesInNarcBySubstring(file, data_ov014_0218968c, &actions, &actionsSize, 1)) {
                            self->model_->Initialize();
                            self->model_->unknown_2_ = self->monster_->monsterID_;
                            self->model_->EnableFlag(4);
                            VramState_Rewind((Foo0207df50*)resources->vramStates_);
                            VramState_Restore(resources->vramStates_);
                            ObjectArchiveLoadInfo loadInfo;
                            ClearEightWords_0203dafc((Struct_203dafc*)&loadInfo);
                            loadInfo.fileData = character;
                            loadInfo.allocator = allocator;
                            loadInfo.fileSize = characterSize;
                            self->model_->LoadFromCCHROrCMOTArchive(&loadInfo, NULL);
                            VramState_Save(resources->vramStates_);
                            ClearEightWords_0203dafc((Struct_203dafc*)&loadInfo);
                            loadInfo.allocator = allocator;
                            loadInfo.fileData = motion;
                            loadInfo.fileSize = motionSize;
                            self->model_->LoadFromCCHROrCMOTArchive(&loadInfo, NULL);
                            ComputeAndStoreVecs02184c08((unsigned char*)self);
                            self->animationIndex_ = 0;
                            MonsterInfo* info = BinarySearchByField4_02097224((BinarySearch020971a8Container*)&self->infos_, self->monster_->monsterID_);
                            if (info != NULL)
                                self->model_->SetAnimationByName(info->animations_[0], 0);
                            self->flags_ |= 4;
                        }
                    }
                }
            }
            var0->RemoveTask(arg0->unknown_86_[4]);
            arg0->unknown_86_[4] = -1;
        }
        arg0->unknown_7f_ = 0;
        arg0->unknown_81_ &= ~9;
        if (arg0->unknown_82_3_)
            arg0->unknown_82_3_ = false;
        arg0->unknown_94_ = arg0->unknown_93_;
        arg0->unknown_93_ = false;
    }
}
