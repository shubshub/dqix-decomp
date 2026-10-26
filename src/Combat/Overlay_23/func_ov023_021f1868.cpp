#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>

struct GameResources;
struct Struct_02048150;
struct Struct_02072a68_2 { char unknown_0_[4]; };
struct Struct_0200f3a4_8;
struct Struct_0209a470;
struct Struct_02013fb4;
struct Struct_020727d8;
struct Struct_02046574_2;
struct Struct_020465c0;
struct Struct_0209fee4;
struct Struct_0209ff64;
struct Struct_0209ff6c;
struct Struct_ov023_021f1868_10;
struct Struct_020a13c4;
struct Struct_020a15bc;
struct Struct_0201099c_14;
struct Struct_0201099c_3;
struct Struct_ov023_021f1868_11;
struct Struct_ov023_021eeaac_2;

struct Struct_ov023_021f1868_12 {
    unsigned char unknown_0_0_ : 1;
};

struct Struct_ov023_021f1868_13 {
    char unknown_0_[0x49c];
    Struct_ov023_021f1868_12 unknown_49c_;
};

struct Struct_ov023_021f1868_14 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov023_021f1868_13* unknown_150_;
};

struct GameState {
    static GameState* GetInstance();
    GameResources* GetResources();
    GameObject_021f1868* GetProtagonist();
};

struct Struct_ov023_021f1868 {
    char unknown_0_[0x134];
    char* unknown_134_;
};

struct Struct_ov023_021f1868_2 {
    unsigned short unknown_0_0_ : 11;
    unsigned short unknown_1_3_ : 5;
    short unknown_2_;
    unsigned int unknown_4_0_ : 5;
    unsigned int unknown_4_5_ : 7;
    unsigned int unknown_5_4_ : 8;
    unsigned int unknown_6_4_ : 5;
    unsigned int unknown_7_1_ : 7;
};

struct Struct_ov023_021f1868_3 {
#if defined(jpn)
    char unknown_0_[0x868];
    int unknown_868_;
    char unknown_86c_[0x17e2 - 0x86c];
    unsigned char unknown_17e2_;
    char unknown_17e3_[0x17fb - 0x17e3];
    unsigned char unknown_17fb_;
#else
    char* unknown1_0_;
    char unknown_4_[4];
    void* unknown_8_;
    char unknown_c_[0x998 - 0xc];
    int unknown_998_;
    char unknown_99c_[0x19b2 - 0x99c];
    unsigned char unknown_19b2_;
    char unknown_19b3_[0x19ca - 0x19b3];
    unsigned char unknown_19ca_;
#endif
};

struct Struct_ov023_021f1868_4 {
    char unknown_0_[0x68];
    short unknown_68_;
    short unknown_6a_[1];
};

struct Struct_ov023_021f1868_5 {
#if defined(jpn)
    char unknown_0_[0x15c];
#else
    char unknown1_0_[0x244];
#endif
};

struct Struct_ov023_021f1868_6 {
    char unknown_0_[0x438];
    unsigned short unknown_438_;
};

struct Struct_ov023_021f1868_7 {
    char unknown_0_[0x18];
};

struct Struct_ov023_021f1868_8 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x18 - 0x8];
    int unknown_18_;
    char unknown_1c_[0x74 - 0x1c];
#if defined(jpn)
    short unknown_74_[55];
#else
    unsigned short unknown1_74_[55];
#endif
    unsigned char unknown_e2_;
    unsigned char unknown_e3_;
};

struct Struct_ov023_021f1868_9 {
    char unknown_0_[0x30];
    SafeAllocator unknown_30_;
#if defined(jpn)
    char unknown_44_[0xe28 - 0x44];
    int unknown_eac_;
    char unknown_e2c_[0x371c - 0xe2c];
    char unknown_371c_[0x1bf8];
    SafeAllocator unknown_5314_;
    char unknown_5328_[0x5770 - 0x5328];
    Struct_02072a68_2* unknown_5770_;
    char unknown_5774_[0x57b4 - 0x5774];
    Struct_ov023_021f1868_4* unknown_57b4_;
    void* unknown_57b8_;
    Struct_ov023_021f1868_6* unknown_55cc_;
    Struct_ov023_021f1868_5* unknown_55d0_;
    unsigned char unknown_55d4_;
    unsigned char unknown_55d5_;
    char unknown_57c6_[0x5af4 - 0x57c6];
    Struct_02072a68_2 unknown_5af4_;
    char unknown_5af8_[0x79c1 - 0x5af8];
    unsigned char unknown_77d1_;
#else
    char unknown1_44_[0xe98 - 0x44];
    char unknown_e98_[0xeac - 0xe98];
    int unknown_eac_;
    char unknown_eb0_[0x3760 - 0xeb0];
    char unknown_3760_[0x1af8];
    SafeAllocator unknown_5258_;
    char unknown_526c_[0x557c - 0x526c];
    Struct_02072a68_2* unknown_557c_;
    void* unknown_5580_;
    char unknown_5584_[0x55c4 - 0x5584];
    Struct_ov023_021f1868_4* unknown_55c4_;
    void* unknown_55c8_;
    Struct_ov023_021f1868_6* unknown_55cc_;
    Struct_ov023_021f1868_5* unknown_55d0_;
    unsigned char unknown_55d4_;
    unsigned char unknown_55d5_;
    char unknown_55d6_[0x5904 - 0x55d6];
    Struct_02072a68_2 unknown_5904_;
    char unknown_5908_[0x77d1 - 0x5908];
    unsigned char unknown_77d1_;
#endif
};

extern "C" Struct_ov023_021f1868_8* _ZZ21inline_ov023_021f4c04vE1s;
extern const char data_ov023_021fe200[];
extern const char data_ov023_021fe25e[];
extern const char data_ov023_021fe273[];
extern const char data_ov023_021fe284[];
extern const char data_ov023_021fe2a0[];
extern const char data_ov023_021fe2b7[];
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#if defined(jpn)
extern const char data_ov023_021fd517[];
extern const char data_ov023_021fd533[];
extern "C" void func_02073864(Struct_02072a68_2* arg0, SafeAllocator* arg1, const char* arg2, int arg3, int arg4, int arg5);
extern "C" void func_020e1fc4(Struct_ov023_021f1868_7* arg0, SafeAllocator* arg1, const char* arg2, short* arg3, unsigned short arg4, int arg5, int arg6);
#endif

MessageSystem_021f1868* MessageSystem_GetInstance();
ArrayContainsByteStruct* GameState_GetParty(GameState* gameState);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct* array, int id);
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
void ClearFirstTwoWords0209a338(Pair0209a338* p);
void SetupAndRunBufferedScript0209a470(Ctx0209a470* ctx, SafeAllocator* allocator, StreamHeader* file, int size);
char* FindEntryByKey_02072a68(TableA68* table, int key);
void ResetListHeader020727d8(List020727d8* list);
void Zero4Bytes_020e526c(void* p);
void Reset0209fe9c(char* titles);
void InitManagerAndAllocateBuffers0209fee4(Obj0209fee4* titles, SafeAllocator* allocator, int file, int size);
void SetIntAt0x60(IntField0x60_0209ff64* titles, int value);
void PollOv017Task0209ff6c(TaskState0209ff6c* titles);
int AreFields60And64AllOnes_021f21f4(Fields60_021f21f4* titles);
Member_021f1868* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int id);
int Text_Append(char* dst, const char* src);
void MessageSystem_SetStringArgument(Obj02046574* obj, int index, char* str);
void NameText_InitFromPartyMember(void* obj, int id);
void** CallFunc020e52a0_020e5294(void* p, int key);
void StoreInArray0x8b0_020465c0(StoreStruct* base, int index, int value);
void MessageSystem_Reset(char* messages);
void ClearStruct020a13c4(S020a13c4* table);
void SetupGlobalAndRunScript020a13e4(void* table, void* allocator, int ids, unsigned short count, unsigned char mode);
void* KeyTable_Construct(void* texts);
void KeyTable_Reset(Struct020dfc40* texts);
void* FindElementByField020a15bc(Array020a15bc* table, int id);
const char* KeyTable_Get(Container020e0310* texts, int id);
void InitObj_021f222c(Obj_021f222c* page);
void FormatLabelIntoBufC_021f2304(void* page, char* title);
void SetOrClearBit10At400_38_021f2348(void* guide, int value);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2* arg0);

extern "C" {
void __clear(void* arg0, unsigned long arg1);
void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);
void func_020728ac(void* arg0, void* arg1, void* arg2, int arg3, int arg4, int arg5, int arg6);
void func_020e5604(void* arg0, SafeAllocator* arg1, void* arg2, int arg3);
Struct_ov023_021f1868_2* func_0209a594(void* arg0, int arg1);
void func_02046380(Struct_ov023_021f1868_3* arg0);
void func_020e4864(void* arg0, char* arg1, int arg2, int arg3, int arg4, int arg5);
#if defined(jpn)
void func_0204500c(Struct_ov023_021f1868_3* arg0, char* arg1, int arg2);
#else
void func_0204500c(Struct_ov023_021f1868_3* arg0, char* arg1, int arg2, int arg3);
#endif
int func_ov023_021f4fc8();
int func_ov023_021ed724(void* arg0, short* arg1, int arg2);
void func_020e0028(Struct_ov023_021f1868_7* arg0, SafeAllocator* arg1, void* arg2, unsigned int arg3, short* arg4, unsigned short arg5);
void func_ov023_021f229c(Struct_ov023_021f1868_5* arg0, void* arg1);
void func_ov023_021eb138(Struct_ov023_021f1868_6* arg0, int arg1);
void func_ov023_021eb080(Struct_ov023_021f1868_6* arg0, SafeAllocator* arg1);
void func_ov023_021eb564(Struct_ov023_021f1868_6* arg0, Struct_ov023_021f1868_5* arg1, int arg2);
void func_ov023_021eb26c(Struct_ov023_021f1868_6* arg0);
}

static inline int inline_ov023_021f1868(Struct_ov023_021f1868_6* arg0) { return (arg0->unknown_438_ & 4) ? 1 : 0; }

// USA: func_ov023_021f1868
extern "C" ARM int func_ov023_021f1868(Struct_ov023_021f1868_9* arg0)
{
#if defined(jpn)
    GameState* gameState = GameState::GetInstance();
    BattleEnd_021f1868* end = _ZZ17GetGlobal021ffefcvE1s;
    MessageSystem_021f1868* messages = MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int id = end->current_;
    int inParty = ArrayContainsByte_02086ef0(GameState_GetParty(gameState), id);
    if (end->step_ == 0)
    {
        arg0->unknown_77d1_ = 1;
        arg0->unknown_30_.Reset();
        arg0->unknown_5770_ = (Struct_02072a68_2*)arg0->unknown_30_.Allocate(8);
        func_020727d8((Struct_020727d8*)arg0->unknown_5770_);
        func_02073864(arg0->unknown_5770_, &arg0->unknown_30_, func_02072a68(&arg0->unknown_5af4_, 0x21), 0, 0, 0);
        arg0->unknown_57b4_ = NULL;
        var20->unknown_4_ = var1->QueueLoadFile(data_ov023_021fd517, NULL);
        var20->unknown_0_++;
    }
    if (var20->unknown_0_ == 1)
    {
        if (var1->GetTaskStatus(var20->unknown_4_))
        {
            unsigned int var4;
            void* var5;
            var1->GetLoadedFileByID(var20->unknown_4_, &var5, &var4);
            arg0->unknown_57b4_ = (Struct_ov023_021f1868_4*)arg0->unknown_30_.Allocate(0xd0);
            func_0209fe9c((char*)arg0->unknown_57b4_);
            func_0209fee4((Struct_0209fee4*)arg0->unknown_57b4_, &arg0->unknown_30_, (int)var5, var4);
            func_0209ff64((Struct_0209ff64*)arg0->unknown_57b4_, 100);
            do
            {
                func_0209ff6c((Struct_0209ff6c*)arg0->unknown_57b4_);
            } while (!func_ov023_021f21f4((Struct_ov023_021f1868_10*)arg0->unknown_57b4_));
            var1->RemoveTask(var20->unknown_4_);
            var20->unknown_4_ = -1;
            var20->unknown_0_++;
        }
    }
    else if (var20->unknown_0_ == 2)
    {
        while (var20->unknown_e3_ < var20->unknown_e2_)
        {
            char* var6 = func_02072a68(arg0->unknown_5770_, var20->unknown_74_[var20->unknown_e3_]);
            if (var6 != NULL)
            {
                Struct_ov023_021f1868* var7 = func_0200ff1c(var19, var2);
                if (var7 != NULL)
                {
                    char text[0x80];
                    __clear(text, sizeof(text));
                    Text_Append(text, name);
                    Text_Append(text, FindEntryByKey_02072a68(&self->texts_, 0x22));
                    func_02046380(messages);
                    MessageSystem_SetStringArgument((Obj02046574*)messages, 0, member->name_);
                    if (inParty)
                    {
                        func_0204500c(var0, var8, 1);
                        var0->unknown_17e2_ = 0;
                        var0->unknown_868_ = 1;
                    }
                    var20->unknown_e3_++;
                    var20->unknown_0_++;
                    return arg0->unknown_eac_;
                }
            }
            var20->unknown_e3_++;
        }
        var20->unknown_0_ = 4;
    }
    else if (var20->unknown_0_ == 3)
    {
        if (var20->unknown_e2_ <= var20->unknown_e3_)
        {
            if (arg0->unknown_57b4_->unknown_68_ > 0)
                var0->unknown_17fb_ = 0;
        }
        if (func_ov023_021f4fc8())
        {
            if (var20->unknown_e2_ <= var20->unknown_e3_)
                var20->unknown_0_++;
            else
                var20->unknown_0_ = 2;
        }
    }
    else if (var20->unknown_0_ == 4)
    {
        short* var9;
        int var10;
        int var11 = arg0->unknown_57b4_->unknown_68_;
        if (var11 > 0)
        {
            MessageSystem_Reset((char*)messages);
            SafeAllocator* idAllocator = &self->menuAllocator_;
            idAllocator->Reset();
            count = self->titles_->count_;
            ids = (short*)idAllocator->Allocate(count * 2);
            for (int k = 0; k < count; k++)
                ids[k] = self->titles_->ids_[k];
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->titles_ = NULL;
            self->titleTable_ = self->allocator_.Allocate(0x14);
            ClearStruct020a13c4((S020a13c4*)self->titleTable_);
            SetupGlobalAndRunScript020a13e4(self->titleTable_, &self->allocator_, (int)ids, (unsigned short)count, 4);
            self->firstGuide_ = func_ov023_021ed724(self->titleTable_, ids, count) & 1 ? 1 : 0;
            GameObject_021f1868* hero = gameState->GetProtagonist();
            TextTable_021f1868 names;
            KeyTable_Construct(&names);
            KeyTable_Reset((Struct020dfc40*)&names);
            func_020e1fc4(&names, &self->allocator_, data_ov023_021fd533, ids, (unsigned short)count, hero->partyData_->appearance_.female_, 1);
            self->pages_ = (GuidePage_021f1868*)self->allocator_.Allocate(count * sizeof(GuidePage_021f1868));
            for (i = 0; i < count; i++)
            {
                void* var16 = func_020a15bc((Struct_020a15bc*)arg0->unknown_57b8_, var9[var10]);
                if (var16 == NULL)
                    continue;
                const char* title = KeyTable_Get((Container020e0310*)&names, ids[i]);
                if (title == NULL)
                    continue;
                func_ov023_021f222c((Struct_ov023_021f1868_11*)&arg0->unknown_55d0_[var10]);
                func_ov023_021f229c(&arg0->unknown_55d0_[var10], var16);
                func_ov023_021f2304(&arg0->unknown_55d0_[var10], (char*)var17);
            }
            arg0->unknown_57b8_ = NULL;
            arg0->unknown_55d4_ = var11;
            var12->Reset();
            var20->unknown_0_++;
        }
        else if (var11 == 0)
        {
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->titles_ = NULL;
            self->busy_ = 0;
            FontBankLoader* music = FontBankLoader_GetInstance();
            BlankFunction02094b40(music);
            BlankFunction02094b34(music, 0x65, 500, 0, 0);
            end->step_ = 8;
        }
    }
#else
    GameState* gameState = GameState::GetInstance();
    BattleEnd_021f1868* end = _ZZ17GetGlobal021ffefcvE1s;
    MessageSystem_021f1868* messages = MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int id = end->current_;
    int inParty = ArrayContainsByte_02086ef0(GameState_GetParty(gameState), id);
    if (end->step_ == 0)
    {
        arg0->unknown_77d1_ = 1;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        self->allocator_.Reset();
        unsigned int size;
        void* file = LoadFileIntoMemory(data_ov023_021fe200, g_fileLoadBuffer, &size);
        ClearFirstTwoWords0209a338((Pair0209a338*)self->script_);
        if (file != NULL)
            SetupAndRunBufferedScript0209a470((Ctx0209a470*)self->script_, &self->allocator_, (StreamHeader*)file, size);
        file = ExtractFileFromGP2(FindEntryByKey_02072a68(&self->texts_, 0x2b), FindEntryByKey_02072a68(&self->texts_, 0x21), &size);
        self->skillTable_ = (TableA68*)self->allocator_.Allocate(8);
        ResetListHeader020727d8((List020727d8*)self->skillTable_);
        if (file != NULL)
            func_020728ac(self->skillTable_, &self->allocator_, file, size, 0, 0, 0);
        file = ExtractFileFromGP2(data_ov023_021fe25e, data_ov023_021fe273, &size);
        self->items_ = self->allocator_.Allocate(0xc);
        Zero4Bytes_020e526c(self->items_);
        if (file != NULL)
            func_020e5604(self->items_, &self->allocator_, file, size);
        BackgroundLoader::RemoveLockGlobal();
        arg0->unknown_55c4_ = NULL;
        var20->unknown_4_ = var22->QueueLoadFile(data_ov023_021fe284, NULL);
        var20->unknown_0_++;
    }
    if (var20->unknown_0_ == 1)
    {
        if (var22->GetTaskStatus(var20->unknown_4_))
        {
            unsigned int var27;
            void* var28;
            var22->GetLoadedFileByID(var20->unknown_4_, &var28, &var27);
            arg0->unknown_55c4_ = (Struct_ov023_021f1868_4*)arg0->unknown_30_.Allocate(0xd0);
            func_0209fe9c((char*)arg0->unknown_55c4_);
            func_0209fee4((Struct_0209fee4*)arg0->unknown_55c4_, &arg0->unknown_30_, (int)var28, var27);
            func_0209ff64((Struct_0209ff64*)arg0->unknown_55c4_, 100);
            do
            {
                func_0209ff6c((Struct_0209ff6c*)arg0->unknown_55c4_);
            } while (!func_ov023_021f21f4((Struct_ov023_021f1868_10*)arg0->unknown_55c4_));
            var22->RemoveTask(var20->unknown_4_);
            var20->unknown_4_ = -1;
            var20->unknown_0_++;
        }
    }
    else if (var20->unknown_0_ == 2)
    {
        while (var20->unknown_e3_ < var20->unknown_e2_)
        {
            Struct_ov023_021f1868_2* var29 = func_0209a594(arg0->unknown_e98_, var20->unknown1_74_[var20->unknown_e3_]);
            char* var30 = NULL;
            if (var29 != NULL)
                var30 = func_02072a68(arg0->unknown_557c_, var29->unknown_6_4_);
            if (var30 != NULL)
            {
                Struct_ov023_021f1868* var31 = func_0200ff1c(GameState::GetInstance(), var23);
                if (var31 != NULL)
                {
                    char text[0x200];
                    char actorName[12];
                    char item[0x80];
                    __clear(text, sizeof(text));
                    Text_Append(text, name);
                    Text_Append(text, FindEntryByKey_02072a68(&self->texts_, 0x22));
                    func_02046380(messages);
                    MessageSystem_SetStringArgument((Obj02046574*)messages, 0, member->name_);
                    NameText_InitFromPartyMember(actorName, id);
                    messages->actor_ = actorName;
                    if (skill->type_ == 1)
                    {
                        void** entry = CallFunc020e52a0_020e5294(self->items_, skill->item_);
                        messages->item_ = entry;
                        __clear(item, sizeof(item));
                        func_020e4864(*entry, item, 1, 0, 0, 0);
                        MessageSystem_SetStringArgument((Obj02046574*)messages, 1, item);
                    }
                    else
                    {
                        MessageSystem_SetStringArgument((Obj02046574*)messages, 1, FindEntryByKey_02072a68(self->skillTable_, (short)(skill->prefix_ + 100)));
                    }
                    int slot = 2;
                    if (skill->type_ == 4 || skill->type_ == 0x10)
                        slot = 1;
                    MessageSystem_SetStringArgument((Obj02046574*)messages, slot, FindEntryByKey_02072a68(self->skillTable_, (short)(skill->suffix_ + 200)));
                    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, skill->value_);
                    if (inParty)
                    {
                        func_0204500c(var21, var32, 1, 0xe3);
                        var21->unknown_19b2_ = 0;
                        var21->unknown_998_ = 1;
                    }
                    var20->unknown_e3_++;
                    var20->unknown_0_++;
                    return arg0->unknown_eac_;
                }
            }
            var20->unknown_e3_++;
        }
        var20->unknown_0_ = 4;
    }
    else if (var20->unknown_0_ == 3)
    {
        if (var20->unknown_e2_ <= var20->unknown_e3_)
        {
            if (arg0->unknown_55c4_->unknown_68_ > 0)
                var21->unknown_19ca_ = 0;
        }
        if (func_ov023_021f4fc8())
        {
            if (var20->unknown_e2_ <= var20->unknown_e3_)
                var20->unknown_0_++;
            else
                var20->unknown_0_ = 2;
        }
    }
    else if (var20->unknown_0_ == 4)
    {
        int var37 = arg0->unknown_55c4_->unknown_68_;
        if (var37 > 0)
        {
            MessageSystem_Reset((char*)messages);
            char* menu = self->menu_; SafeAllocator* idAllocator = (SafeAllocator*)(menu + 0x1af8);
            idAllocator->Reset();
            count = self->titles_->count_;
            short* ids = (short*)idAllocator->Allocate(count * 2);
            for (int k = 0; k < count; k++)
                ids[k] = self->titles_->ids_[k];
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->items_ = NULL;
            self->titles_ = NULL;
            self->titleTable_ = self->allocator_.Allocate(0x14);
            ClearStruct020a13c4((S020a13c4*)self->titleTable_);
            SetupGlobalAndRunScript020a13e4(self->titleTable_, &self->allocator_, (int)ids, (unsigned short)count, 4);
            self->firstGuide_ = func_ov023_021ed724(self->titleTable_, ids, count) & 1 ? 1 : 0;
            GameObject_021f1868* hero = gameState->GetProtagonist();
            TextTable_021f1868 names;
            KeyTable_Construct(&names);
            KeyTable_Reset((Struct020dfc40*)&names);
            BackgroundLoader::AddLockGlobal();
            unsigned int var44 = 0;
            char var45[0x40];
            __clear(var45, sizeof(var45));
            char var46[0x20];
            __clear(var46, sizeof(var46));
            Struct_ov023_021f1868_13* var47 = var42->unknown_150_;
            sprintf(var45, data_ov023_021fe2a0, var47->unknown_49c_.unknown_0_0_);
            sprintf(var46, data_ov023_021fe2b7, var42->unknown_150_->unknown_49c_.unknown_0_0_);
            void* var48 = ExtractFileFromGP2(var45, var46, &var44);
            if (var48 != NULL)
                func_020e0028(&var43, &arg0->unknown_30_, var48, var44, var40, (unsigned short)var37);
            BackgroundLoader::RemoveLockGlobal();
            arg0->unknown_55d0_ = (Struct_ov023_021f1868_5*)arg0->unknown_30_.Allocate(var37 * sizeof(Struct_ov023_021f1868_5));
            for (int var49 = 0; var49 < var37; var49++)
            {
                void* var50 = func_020a15bc((Struct_020a15bc*)arg0->unknown_55c8_, var40[var49]);
                if (var50 == NULL)
                    continue;
                const char* title = KeyTable_Get((Container020e0310*)&names, ids[i]);
                if (title == NULL)
                    continue;
                func_ov023_021f222c((Struct_ov023_021f1868_11*)&arg0->unknown_55d0_[var49]);
                func_ov023_021f229c(&arg0->unknown_55d0_[var49], var50);
                func_ov023_021f2304(&arg0->unknown_55d0_[var49], (char*)var51);
            }
            arg0->unknown_55c8_ = NULL;
            arg0->unknown_55d4_ = var37;
            var39->Reset();
            var20->unknown_0_++;
        }
        else if (var37 == 0)
        {
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->items_ = NULL;
            self->titles_ = NULL;
            self->busy_ = 0;
            FontBankLoader* music = FontBankLoader_GetInstance();
            BlankFunction02094b40(music);
            BlankFunction02094b34(music, 0x65, 500, 0, 0);
            end->step_ = 8;
        }
    }
#endif
    else if (var20->unknown_0_ == 5)
    {
        arg0->unknown_55cc_ = (Struct_ov023_021f1868_6*)arg0->unknown_30_.Allocate(0x44c);
        func_ov023_021eb138(arg0->unknown_55cc_, 7);
        arg0->unknown_55cc_->unknown_438_ |= 8;
        func_ov023_021eb080(arg0->unknown_55cc_, &arg0->unknown_30_);
        func_ov023_021eb564(arg0->unknown_55cc_, arg0->unknown_55d0_, arg0->unknown_55d4_);
        func_ov023_021f2348(arg0->unknown_55cc_, arg0->unknown_55d5_);
        var20->unknown_0_++;
    }
    else if (var20->unknown_0_ == 6)
    {
#if defined(jpn)
        if (arg0->unknown_55cc_->unknown_438_ & 4)
            var20->unknown_0_++;
#else
        if (inline_ov023_021f1868(arg0->unknown_55cc_))
            var20->unknown_0_++;
#endif
    }
    else if (var20->unknown_0_ == 7)
    {
        func_ov023_021eb26c(self->guide_);
        self->allocator_.Reset();
        self->guide_ = NULL;
        self->pages_ = NULL;
        self->pageCount_ = 0;
        self->firstGuide_ = 0;
        self->busy_ = 0;
        SetMainBrightness(gameState->GetResources(), 0, 0xf);
        FontBankLoader* music = FontBankLoader_GetInstance();
        BlankFunction02094b40(music);
        BlankFunction02094b34(music, 0x65, 500, 0, 0);
        end->step_++;
    }
    else if (var20->unknown_0_ == 8)
    {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()))
            end->step_++;
    }
    else if (var20->unknown_0_ == 9)
    {
        if (!IsBrightnessTransitionActive(gameState->GetResources()))
        {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)var20);
            return 7;
        }
    }
    return arg0->unknown_eac_;
}
