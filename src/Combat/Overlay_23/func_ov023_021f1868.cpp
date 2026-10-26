#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>

struct GameResources;
struct ArrayContainsByteStruct;
struct TableA68 { char storage[4]; };
struct Pair0209a338;
struct Struct_0209a470;
struct StreamHeader;
struct Struct_020727d8;
struct Obj02046574;
struct StoreStruct;
struct Struct_0209fee4;
struct Struct_0209ff64;
struct Struct_0209ff6c;
struct Struct_ov023_021f1868_10;
struct Struct_020a13c4;
struct Struct_020a15bc;
struct Struct020dfc40;
struct Container020e0310;
struct Struct_ov023_021f1868_11;
struct Struct_ov023_021eeaac_2;

struct Struct_ov023_021f1868_12 {
    unsigned char female_ : 1;
};

struct Struct_ov023_021f1868_13 {
    char unk_0[0x49c];
    Struct_ov023_021f1868_12 appearance_;
};

struct Struct_ov023_021f1868_14 {
#if defined(jpn)
    char unk_0[0x144];
#else
    char unk_0[0x150];
#endif
    Struct_ov023_021f1868_13* unknown_150_;
};

struct GameState {
    static GameState* GetInstance();
    GameResources* GetResources();
    Struct_ov023_021f1868_14* GetProtagonist();
};

struct Struct_ov023_021f1868 {
    char unk_0[0x134];
    char* name_;
};

struct Struct_ov023_021f1868_2 {
    unsigned short unknown_0_0_ : 11;
    unsigned short suffix_ : 5;
    short item_;
    unsigned int prefix_ : 5;
    unsigned int unknown_4_5_ : 7;
    unsigned int unknown_5_4_ : 8;
    unsigned int type_ : 5;
    unsigned int unknown_7_1_ : 7;
};

struct MessageSystem_021f1868 {
#if defined(jpn)
    char unk_0[0x868];
    int busy_;
    char unknown_86c_[0x17e2 - 0x86c];
    unsigned char unknown_17e2_;
    char unknown_17e3_[0x17fb - 0x17e3];
    unsigned char unknown_17fb_;
#else
    char* actor_;
    char unk_4[4];
    void* item_;
    char unk_c[0x998 - 0xc];
    int busy_;
    char unknown_99c_[0x19b2 - 0x99c];
    unsigned char unknown_19b2_;
    char unknown_19b3_[0x19ca - 0x19b3];
    unsigned char unknown_19ca_;
#endif
};

struct Struct_ov023_021f1868_4 {
    char unk_0[0x68];
    short count_;
    short unknown_6a_[1];
};

struct Struct_ov023_021f1868_5 {
#if defined(jpn)
    char unk_0[0x15c];
#else
    char unk_0[0x244];
#endif
};

struct Struct_ov023_021f1868_6 {
    char unk_0[0x438];
    unsigned short flags_;
};

struct Struct_ov023_021f1868_7 {
    char unk_0[0x18];
};

struct Struct_ov023_021f1868_8 {
    int step_;
    int task_;
    char unk_8[0x18 - 0x8];
    int current_;
    char unk_1c[0x74 - 0x1c];
#if defined(jpn)
    short unknown_74_[55];
#else
    unsigned short unknown1_74_[55];
#endif
    unsigned char unknown_e2_;
    unsigned char unknown_e3_;
};

struct Struct_ov023_021f1868_9 {
    char unk_0[0x30];
    SafeAllocator allocator_;
#if defined(jpn)
    char unknown_44_[0xe28 - 0x44];
    int unknown_eac_;
    char unknown_e2c_[0x371c - 0xe2c];
    char menu_[0x1bf8];
    SafeAllocator menuAllocator_;
    char unknown_5328_[0x5770 - 0x5328];
    TableA68* skillTable_;
    char unknown_5774_[0x57b4 - 0x5774];
    Struct_ov023_021f1868_4* titles_;
    void* unknown_57b8_;
    Struct_ov023_021f1868_6* unknown_55cc_;
    Struct_ov023_021f1868_5* pages_;
    unsigned char unknown_55d4_;
    unsigned char unknown_55d5_;
    char unknown_57c6_[0x5af4 - 0x57c6];
    TableA68 texts_;
    char unknown_5af8_[0x79c1 - 0x5af8];
    unsigned char busy_;
#else
    char unknown1_44_[0xe98 - 0x44];
    char unknown_e98_[0xeac - 0xe98];
    int unknown_eac_;
    char unknown_eb0_[0x3760 - 0xeb0];
    char menu_[0x1af8];
    SafeAllocator menuAllocator_;
    char unknown_526c_[0x557c - 0x526c];
    TableA68* skillTable_;
    void* items_;
    char unknown_5584_[0x55c4 - 0x5584];
    Struct_ov023_021f1868_4* titles_;
    void* unknown_55c8_;
    Struct_ov023_021f1868_6* unknown_55cc_;
    Struct_ov023_021f1868_5* pages_;
    unsigned char unknown_55d4_;
    unsigned char unknown_55d5_;
    char unknown_55d6_[0x5904 - 0x55d6];
    TableA68 texts_;
    char unknown_5908_[0x77d1 - 0x5908];
    unsigned char busy_;
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
extern "C" void func_02073864(TableA68* list, SafeAllocator* allocator, const char* name, int a, int b, int c);
extern "C" void func_020e1fc4(Struct_ov023_021f1868_7* texts, SafeAllocator* allocator, const char* path, short* ids, unsigned short count, int female, int mode);
#endif

extern "C" MessageSystem_021f1868* MessageSystem_GetInstance();
extern "C" ArrayContainsByteStruct* GameState_GetParty(GameState* gameState);
extern "C" int func_02086ef0(ArrayContainsByteStruct* array, int id);
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern "C" void func_0209a338(Pair0209a338* p);
extern "C" void func_0209a470(Struct_0209a470* ctx, SafeAllocator* allocator, StreamHeader* file, int size);
extern "C" char* func_02072a68(TableA68* table, int key);
extern "C" void func_020727d8(Struct_020727d8* list);
extern "C" void func_020e526c(void* p);
extern "C" void func_0209fe9c(char* arg0);
extern "C" void func_0209fee4(Struct_0209fee4* arg0, SafeAllocator* allocator, int file, int size);
extern "C" void func_0209ff64(Struct_0209ff64* arg0, int value);
extern "C" void func_0209ff6c(Struct_0209ff6c* arg0);
extern "C" int func_ov023_021f21f4(Struct_ov023_021f1868_10* arg0);
extern "C" Struct_ov023_021f1868* func_0200ff1c(GameState* gameState, int id);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" void MessageSystem_SetStringArgument(Obj02046574* obj, int index, char* str);
extern "C" void NameText_InitFromPartyMember(void* obj, int id);
extern "C" void** func_020e5294(void* p, int key);
extern "C" void func_020465c0(StoreStruct* base, int index, int value);
extern "C" void MessageSystem_Reset(char* messages);
extern "C" void func_020a13c4(Struct_020a13c4* table);
extern "C" void func_020a13e4(void* table, void* allocator, int ids, unsigned short count, unsigned char mode);
extern "C" void* KeyTable_Construct(void* texts);
extern "C" void KeyTable_Reset(Struct020dfc40* texts);
extern "C" void* func_020a15bc(Struct_020a15bc* table, int id);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void func_ov023_021f222c(Struct_ov023_021f1868_11* page);
extern "C" void func_ov023_021f2304(void* page, char* title);
extern "C" void func_ov023_021f2348(void* arg0, int value);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2* end);

extern "C" {
void __clear(void* buffer, unsigned long size);
void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* size);
void func_020728ac(void* list, void* allocator, void* file, int size, int a, int b, int c);
void func_020e5604(void* items, SafeAllocator* allocator, void* file, int size);
Struct_ov023_021f1868_2* func_0209a594(void* script, int id);
void func_02046380(MessageSystem_021f1868* messages);
void func_020e4864(void* src, char* dst, int a, int b, int c, int d);
#if defined(jpn)
void func_0204500c(MessageSystem_021f1868* messages, char* text, int a);
#else
void func_0204500c(MessageSystem_021f1868* messages, char* text, int a, int b);
#endif
int func_ov023_021f4fc8();
int func_ov023_021ed724(void* table, short* ids, int count);
void func_020e0028(Struct_ov023_021f1868_7* texts, SafeAllocator* allocator, void* file, unsigned int size, short* ids, unsigned short count);
void func_ov023_021f229c(Struct_ov023_021f1868_5* page, void* entry);
void func_ov023_021eb138(Struct_ov023_021f1868_6* arg0, int type);
void func_ov023_021eb080(Struct_ov023_021f1868_6* arg0, SafeAllocator* allocator);
void func_ov023_021eb564(Struct_ov023_021f1868_6* arg0, Struct_ov023_021f1868_5* pages, int count);
void func_ov023_021eb26c(Struct_ov023_021f1868_6* arg0);
}

static inline int inline_ov023_021f1868(Struct_ov023_021f1868_6* arg0) { return (arg0->flags_ & 4) ? 1 : 0; }

// USA: func_ov023_021f1868
extern "C" ARM int func_ov023_021f1868(Struct_ov023_021f1868_9* self)
{
#if defined(jpn)
    GameState* gameState = GameState::GetInstance();
    Struct_ov023_021f1868_8* end = _ZZ21inline_ov023_021f4c04vE1s;
    MessageSystem_021f1868* messages = MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int id = end->current_;
    int inParty = func_02086ef0(GameState_GetParty(gameState), id);
    if (end->step_ == 0)
    {
        self->busy_ = 1;
        self->allocator_.Reset();
        self->skillTable_ = (TableA68*)self->allocator_.Allocate(8);
        func_020727d8((Struct_020727d8*)self->skillTable_);
        func_02073864(self->skillTable_, &self->allocator_, func_02072a68(&self->texts_, 0x21), 0, 0, 0);
        self->titles_ = NULL;
        end->task_ = loader->QueueLoadFile(data_ov023_021fd517, NULL);
        end->step_++;
    }
    if (end->step_ == 1)
    {
        if (loader->GetTaskStatus(end->task_))
        {
            unsigned int size;
            void* file;
            loader->GetLoadedFileByID(end->task_, &file, &size);
            self->titles_ = (Struct_ov023_021f1868_4*)self->allocator_.Allocate(0xd0);
            func_0209fe9c((char*)self->titles_);
            func_0209fee4((Struct_0209fee4*)self->titles_, &self->allocator_, (int)file, size);
            func_0209ff64((Struct_0209ff64*)self->titles_, 100);
            do
            {
                func_0209ff6c((Struct_0209ff6c*)self->titles_);
            } while (!func_ov023_021f21f4((Struct_ov023_021f1868_10*)self->titles_));
            loader->RemoveTask(end->task_);
            end->task_ = -1;
            end->step_++;
        }
    }
    else if (end->step_ == 2)
    {
        while (end->unknown_e3_ < end->unknown_e2_)
        {
            char* name = func_02072a68(self->skillTable_, end->unknown_74_[end->unknown_e3_]);
            if (name != NULL)
            {
                Struct_ov023_021f1868* member = func_0200ff1c(gameState, id);
                if (member != NULL)
                {
                    char text[0x80];
                    __clear(text, sizeof(text));
                    Text_Append(text, name);
                    Text_Append(text, func_02072a68(&self->texts_, 0x22));
                    func_02046380(messages);
                    MessageSystem_SetStringArgument((Obj02046574*)messages, 0, member->name_);
                    if (inParty)
                    {
                        func_0204500c(messages, text, 1);
                        messages->unknown_17e2_ = 0;
                        messages->busy_ = 1;
                    }
                    end->unknown_e3_++;
                    end->step_++;
                    return self->unknown_eac_;
                }
            }
            end->unknown_e3_++;
        }
        end->step_ = 4;
    }
    else if (end->step_ == 3)
    {
        if (end->unknown_e2_ <= end->unknown_e3_)
        {
            if (self->titles_->count_ > 0)
                messages->unknown_17fb_ = 0;
        }
        if (func_ov023_021f4fc8())
        {
            if (end->unknown_e2_ <= end->unknown_e3_)
                end->step_++;
            else
                end->step_ = 2;
        }
    }
    else if (end->step_ == 4)
    {
        short* ids;
        int i;
        int count = self->titles_->count_;
        if (count > 0)
        {
            MessageSystem_Reset((char*)messages);
            SafeAllocator* var12 = &self->menuAllocator_;
            var12->Reset();
            count = self->titles_->count_;
            ids = (short*)var12->Allocate(count * 2);
            for (int k = 0; k < count; k++)
                ids[k] = self->titles_->unknown_6a_[k];
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->titles_ = NULL;
            self->unknown_57b8_ = self->allocator_.Allocate(0x14);
            func_020a13c4((Struct_020a13c4*)self->unknown_57b8_);
            func_020a13e4(self->unknown_57b8_, &self->allocator_, (int)ids, (unsigned short)count, 4);
            self->unknown_55d5_ = func_ov023_021ed724(self->unknown_57b8_, ids, count) & 1 ? 1 : 0;
            Struct_ov023_021f1868_14* hero = gameState->GetProtagonist();
            Struct_ov023_021f1868_7 names;
            KeyTable_Construct(&names);
            KeyTable_Reset((Struct020dfc40*)&names);
            func_020e1fc4(&names, &self->allocator_, data_ov023_021fd533, ids, (unsigned short)count, hero->unknown_150_->appearance_.female_, 1);
            self->pages_ = (Struct_ov023_021f1868_5*)self->allocator_.Allocate(count * sizeof(Struct_ov023_021f1868_5));
            for (i = 0; i < count; i++)
            {
                void* entry = func_020a15bc((Struct_020a15bc*)self->unknown_57b8_, ids[i]);
                if (entry == NULL)
                    continue;
                const char* title = KeyTable_Get((Container020e0310*)&names, ids[i]);
                if (title == NULL)
                    continue;
                func_ov023_021f222c((Struct_ov023_021f1868_11*)&self->pages_[i]);
                func_ov023_021f229c(&self->pages_[i], entry);
                func_ov023_021f2304(&self->pages_[i], (char*)title);
            }
            self->unknown_57b8_ = NULL;
            self->unknown_55d4_ = count;
            var12->Reset();
            end->step_++;
        }
        else if (count == 0)
        {
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->titles_ = NULL;
            self->busy_ = 0;
            FontBankLoader* music = FontBankLoader_GetInstance();
            func_02094b40(music);
            func_02094b34(music, 0x65, 500, 0, 0);
            end->step_ = 8;
        }
    }
#else
    GameState* gameState = GameState::GetInstance();
    Struct_ov023_021f1868_8* end = _ZZ21inline_ov023_021f4c04vE1s;
    MessageSystem_021f1868* messages = MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int id = end->current_;
    int inParty = func_02086ef0(GameState_GetParty(gameState), id);
    if (end->step_ == 0)
    {
        self->busy_ = 1;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        self->allocator_.Reset();
        unsigned int size;
        void* file = LoadFileIntoMemory(data_ov023_021fe200, g_fileLoadBuffer, &size);
        func_0209a338((Pair0209a338*)self->unknown_e98_);
        if (file != NULL)
            func_0209a470((Struct_0209a470*)self->unknown_e98_, &self->allocator_, (StreamHeader*)file, size);
        file = ExtractFileFromGP2(func_02072a68(&self->texts_, 0x2b), func_02072a68(&self->texts_, 0x21), &size);
        self->skillTable_ = (TableA68*)self->allocator_.Allocate(8);
        func_020727d8((Struct_020727d8*)self->skillTable_);
        if (file != NULL)
            func_020728ac(self->skillTable_, &self->allocator_, file, size, 0, 0, 0);
        file = ExtractFileFromGP2(data_ov023_021fe25e, data_ov023_021fe273, &size);
        self->items_ = self->allocator_.Allocate(0xc);
        func_020e526c(self->items_);
        if (file != NULL)
            func_020e5604(self->items_, &self->allocator_, file, size);
        BackgroundLoader::RemoveLockGlobal();
        self->titles_ = NULL;
        end->task_ = loader->QueueLoadFile(data_ov023_021fe284, NULL);
        end->step_++;
    }
    if (end->step_ == 1)
    {
        if (loader->GetTaskStatus(end->task_))
        {
            unsigned int size;
            void* file;
            loader->GetLoadedFileByID(end->task_, &file, &size);
            self->titles_ = (Struct_ov023_021f1868_4*)self->allocator_.Allocate(0xd0);
            func_0209fe9c((char*)self->titles_);
            func_0209fee4((Struct_0209fee4*)self->titles_, &self->allocator_, (int)file, size);
            func_0209ff64((Struct_0209ff64*)self->titles_, 100);
            do
            {
                func_0209ff6c((Struct_0209ff6c*)self->titles_);
            } while (!func_ov023_021f21f4((Struct_ov023_021f1868_10*)self->titles_));
            loader->RemoveTask(end->task_);
            end->task_ = -1;
            end->step_++;
        }
    }
    else if (end->step_ == 2)
    {
        while (end->unknown_e3_ < end->unknown_e2_)
        {
            Struct_ov023_021f1868_2* skill = func_0209a594(self->unknown_e98_, end->unknown1_74_[end->unknown_e3_]);
            char* name = NULL;
            if (skill != NULL)
                name = func_02072a68(self->skillTable_, skill->type_);
            if (name != NULL)
            {
                Struct_ov023_021f1868* member = func_0200ff1c(GameState::GetInstance(), id);
                if (member != NULL)
                {
                    char text[0x200];
                    char actorName[12];
                    char item[0x80];
                    __clear(text, sizeof(text));
                    Text_Append(text, name);
                    Text_Append(text, func_02072a68(&self->texts_, 0x22));
                    func_02046380(messages);
                    MessageSystem_SetStringArgument((Obj02046574*)messages, 0, member->name_);
                    NameText_InitFromPartyMember(actorName, id);
                    messages->actor_ = actorName;
                    if (skill->type_ == 1)
                    {
                        void** entry = func_020e5294(self->items_, skill->item_);
                        messages->item_ = entry;
                        __clear(item, sizeof(item));
                        func_020e4864(*entry, item, 1, 0, 0, 0);
                        MessageSystem_SetStringArgument((Obj02046574*)messages, 1, item);
                    }
                    else
                    {
                        MessageSystem_SetStringArgument((Obj02046574*)messages, 1, func_02072a68(self->skillTable_, (short)(skill->prefix_ + 100)));
                    }
                    int slot = 2;
                    if (skill->type_ == 4 || skill->type_ == 0x10)
                        slot = 1;
                    MessageSystem_SetStringArgument((Obj02046574*)messages, slot, func_02072a68(self->skillTable_, (short)(skill->suffix_ + 200)));
                    func_020465c0((StoreStruct*)messages, 0, skill->unknown_5_4_);
                    if (inParty)
                    {
                        func_0204500c(messages, text, 1, 0xe3);
                        messages->unknown_19b2_ = 0;
                        messages->busy_ = 1;
                    }
                    end->unknown_e3_++;
                    end->step_++;
                    return self->unknown_eac_;
                }
            }
            end->unknown_e3_++;
        }
        end->step_ = 4;
    }
    else if (end->step_ == 3)
    {
        if (end->unknown_e2_ <= end->unknown_e3_)
        {
            if (self->titles_->count_ > 0)
                messages->unknown_19ca_ = 0;
        }
        if (func_ov023_021f4fc8())
        {
            if (end->unknown_e2_ <= end->unknown_e3_)
                end->step_++;
            else
                end->step_ = 2;
        }
    }
    else if (end->step_ == 4)
    {
        int count = self->titles_->count_;
        if (count > 0)
        {
            MessageSystem_Reset((char*)messages);
            char* menu = self->menu_; SafeAllocator* var39 = (SafeAllocator*)(menu + 0x1af8);
            var39->Reset();
            count = self->titles_->count_;
            short* ids = (short*)var39->Allocate(count * 2);
            for (int k = 0; k < count; k++)
                ids[k] = self->titles_->unknown_6a_[k];
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->items_ = NULL;
            self->titles_ = NULL;
            self->unknown_55c8_ = self->allocator_.Allocate(0x14);
            func_020a13c4((Struct_020a13c4*)self->unknown_55c8_);
            func_020a13e4(self->unknown_55c8_, &self->allocator_, (int)ids, (unsigned short)count, 4);
            self->unknown_55d5_ = func_ov023_021ed724(self->unknown_55c8_, ids, count) & 1 ? 1 : 0;
            Struct_ov023_021f1868_14* hero = gameState->GetProtagonist();
            Struct_ov023_021f1868_7 names;
            KeyTable_Construct(&names);
            KeyTable_Reset((Struct020dfc40*)&names);
            BackgroundLoader::AddLockGlobal();
            unsigned int size = 0;
            char gp2[0x40];
            __clear(gp2, sizeof(gp2));
            char inner[0x20];
            __clear(inner, sizeof(inner));
            Struct_ov023_021f1868_13* var47 = hero->unknown_150_;
            sprintf(gp2, data_ov023_021fe2a0, var47->appearance_.female_);
            sprintf(inner, data_ov023_021fe2b7, hero->unknown_150_->appearance_.female_);
            void* file = ExtractFileFromGP2(gp2, inner, &size);
            if (file != NULL)
                func_020e0028(&names, &self->allocator_, file, size, ids, (unsigned short)count);
            BackgroundLoader::RemoveLockGlobal();
            self->pages_ = (Struct_ov023_021f1868_5*)self->allocator_.Allocate(count * sizeof(Struct_ov023_021f1868_5));
            for (int i = 0; i < count; i++)
            {
                void* entry = func_020a15bc((Struct_020a15bc*)self->unknown_55c8_, ids[i]);
                if (entry == NULL)
                    continue;
                const char* title = KeyTable_Get((Container020e0310*)&names, ids[i]);
                if (title == NULL)
                    continue;
                func_ov023_021f222c((Struct_ov023_021f1868_11*)&self->pages_[i]);
                func_ov023_021f229c(&self->pages_[i], entry);
                func_ov023_021f2304(&self->pages_[i], (char*)title);
            }
            self->unknown_55c8_ = NULL;
            self->unknown_55d4_ = count;
            var39->Reset();
            end->step_++;
        }
        else if (count == 0)
        {
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->items_ = NULL;
            self->titles_ = NULL;
            self->busy_ = 0;
            FontBankLoader* music = FontBankLoader_GetInstance();
            func_02094b40(music);
            func_02094b34(music, 0x65, 500, 0, 0);
            end->step_ = 8;
        }
    }
#endif
    else if (end->step_ == 5)
    {
        self->unknown_55cc_ = (Struct_ov023_021f1868_6*)self->allocator_.Allocate(0x44c);
        func_ov023_021eb138(self->unknown_55cc_, 7);
        self->unknown_55cc_->flags_ |= 8;
        func_ov023_021eb080(self->unknown_55cc_, &self->allocator_);
        func_ov023_021eb564(self->unknown_55cc_, self->pages_, self->unknown_55d4_);
        func_ov023_021f2348(self->unknown_55cc_, self->unknown_55d5_);
        end->step_++;
    }
    else if (end->step_ == 6)
    {
#if defined(jpn)
        if (self->unknown_55cc_->flags_ & 4)
            end->step_++;
#else
        if (inline_ov023_021f1868(self->unknown_55cc_))
            end->step_++;
#endif
    }
    else if (end->step_ == 7)
    {
        func_ov023_021eb26c(self->unknown_55cc_);
        self->allocator_.Reset();
        self->unknown_55cc_ = NULL;
        self->pages_ = NULL;
        self->unknown_55d4_ = 0;
        self->unknown_55d5_ = 0;
        self->busy_ = 0;
        SetMainBrightness(gameState->GetResources(), 0, 0xf);
        FontBankLoader* music = FontBankLoader_GetInstance();
        func_02094b40(music);
        func_02094b34(music, 0x65, 500, 0, 0);
        end->step_++;
    }
    else if (end->step_ == 8)
    {
        if (func_02094b4c(FontBankLoader_GetInstance()))
            end->step_++;
    }
    else if (end->step_ == 9)
    {
        if (!IsBrightnessTransitionActive(gameState->GetResources()))
        {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)end);
            return 7;
        }
    }
    return self->unknown_eac_;
}
