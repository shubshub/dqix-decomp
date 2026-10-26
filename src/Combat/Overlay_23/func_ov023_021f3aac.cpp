#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>

#define GUIDE_WINDOW_MESSAGE_WINDOW 4

struct Struct_0209fee4;
struct Struct_0209ff64;
struct Struct_0209ff6c;
struct Struct_ov023_021f1868_10;
struct Struct_020a13c4;
struct Struct_020a15bc;
struct Struct020dfc40;
struct Container020e0310;
struct Struct_ov023_021f1868_11;

struct Struct_ov023_021f3aac_5 {
    unsigned char female_ : 1;
};

struct Struct_ov023_021f3aac_6 {
    char unk_0[0x49c];
    Struct_ov023_021f3aac_5 appearance_;
};

struct Struct_ov023_021f3aac_7 {
#if defined(jpn)
    char unk_0[0x144];
#else
    char unk_0[0x150];
#endif

    Struct_ov023_021f3aac_6* unknown_150_;
};

struct GameState {
    static GameState* GetInstance();
    Struct_ov023_021f3aac_7* GetProtagonist();
};

struct Struct_ov023_021f3aac_8 {
    char unk_0[0x68];
    short count_;
    short unknown_6a_[1];
};

struct Struct_ov023_021f3aac_9 {
#if defined(jpn)
    char unk_0[0x15c];
#else
    char unk_0[0x244];
#endif

};

struct Struct_ov023_021f3aac {
    char unk_0[0x438];
    unsigned short flags_;
};

struct Struct_ov023_021f3aac_2 {
    char unk_0[0x18];
};

struct Struct_ov023_021f3aac_3 {
    int step_;
    int task_;
};

struct Struct_ov023_021f3aac_4 {
    char unk_0[0x30];
    SafeAllocator allocator_;
#if defined(jpn)
    char unknown_44_[0xe28 - 0x44];
#else
    char unknown1_44_[0xeac - 0x44];
#endif

    int unknown_eac_;
#if defined(jpn)
    char unknown_e2c_[0x371c - 0xe2c];
#else
    char unknown_eb0_[0x3760 - 0xeb0];
#endif

#if defined(jpn)
    char menu_[0x1bf8];
#else
    char menu_[0x1af8];
#endif

    SafeAllocator menuAllocator_;
#if defined(jpn)
    char unknown_5328_[0x5778 - 0x5328];
#else
    char unknown_526c_[0x5588 - 0x526c];
#endif

    void* unknown_5588_;
    char unknown_558c_[0x55c4 - 0x558c];
    Struct_ov023_021f3aac_8* titles_;
    void* unknown_55c8_;
    Struct_ov023_021f3aac* unknown_55cc_;
    Struct_ov023_021f3aac_9* pages_;
    unsigned char unknown_55d4_;
    unsigned char unknown_55d5_;
    char unknown_55d6_[0x77d1 - 0x55d6];
    unsigned char busy_;
};

extern "C" Struct_ov023_021f3aac_3* _ZZ21inline_ov023_021f4c04vE1s;
#if defined(jpn)
extern const char data_ov023_021fd533[];
extern "C" void func_020e1fc4(Struct_ov023_021f3aac_2*, SafeAllocator*, const char*, short*, unsigned short, int, int);
#endif
extern const char data_ov023_021fe316[];
extern const char data_ov023_021fe2a0[];
extern const char data_ov023_021fe2b7[];

extern "C" char* MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* messages);
extern "C" void func_ov023_021d8b6c(void* window);
extern "C" void func_0209fe9c(char* arg0);
extern "C" void func_0209fee4(Struct_0209fee4* arg0, SafeAllocator* allocator, int file, int size);
extern "C" void func_0209ff64(Struct_0209ff64* arg0, int value);
extern "C" void func_0209ff6c(Struct_0209ff6c* arg0);
extern "C" int func_ov023_021f21f4(Struct_ov023_021f1868_10* arg0);
extern "C" void func_020a13c4(Struct_020a13c4* table);
extern "C" void func_020a13e4(void* table, void* allocator, int a, unsigned short b, unsigned char c);
extern "C" void* KeyTable_Construct(void* texts);
extern "C" void KeyTable_Reset(Struct020dfc40* texts);
extern "C" void* func_020a15bc(Struct_020a15bc* table, int id);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void func_ov023_021f222c(Struct_ov023_021f1868_11* page);
extern "C" void func_ov023_021f2304(void* page, char* title);
extern "C" void func_ov023_021f2348(void* arg0, int value);

extern "C" {
void __clear(void* buffer, unsigned long size);
void func_ov023_021f1818(void* menu, int hidden);
void func_ov023_021d8af8(void* window);
int func_ov023_021ed724(void* arg0, short* ids, int count);
void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* size);
void func_020e0028(Struct_ov023_021f3aac_2* texts, SafeAllocator* allocator, void* file, unsigned int size, short* ids, unsigned short count);
void func_ov023_021f229c(Struct_ov023_021f3aac_9* page, void* entry);
void func_ov023_021eb138(Struct_ov023_021f3aac* arg0, int type);
void func_ov023_021eb080(Struct_ov023_021f3aac* arg0, SafeAllocator* allocator);
void func_ov023_021eb564(Struct_ov023_021f3aac* arg0, Struct_ov023_021f3aac_9* pages, int count);
void func_ov023_021eb26c(Struct_ov023_021f3aac* arg0);
}

// USA: func_ov023_021f3aac
extern "C" ARM int func_ov023_021f3aac(Struct_ov023_021f3aac_4* self)
{
    Struct_ov023_021f3aac_3* end = _ZZ21inline_ov023_021f4c04vE1s;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int step = end->step_;
    if (step == 0)
    {
        MessageSystem_Reset(MessageSystem_GetInstance());
        if (self->unknown_5588_ != NULL)
        {
            func_ov023_021f1818(self->menu_, 1);
            func_ov023_021d8b6c(self->unknown_5588_);
            func_ov023_021d8af8(self->unknown_5588_);
            self->unknown_5588_ = NULL;
        }
        self->busy_ = 1;
        self->titles_ = NULL;
        end->task_ = loader->QueueLoadFile(data_ov023_021fe316, NULL);
        end->step_++;
    }
    else if (step == 1)
    {
        BackgroundLoader* var3 = BackgroundLoader::GetInstance();
        if (var3->GetTaskStatus(end->task_))
        {
            unsigned int size;
            void* file;
            var3->GetLoadedFileByID(end->task_, &file, &size);
            self->allocator_.Reset();
            void* copy = self->allocator_.Allocate(size);
            memcpy(copy, file, size);
            self->titles_ = (Struct_ov023_021f3aac_8*)self->allocator_.Allocate(0xd0);
            func_0209fe9c((char*)self->titles_);
            func_0209fee4((Struct_0209fee4*)self->titles_, &self->allocator_, (int)copy, size);
            var3->RemoveTask(end->task_);
            end->task_ = -1;
            func_0209ff64((Struct_0209ff64*)self->titles_, 100);
            end->step_++;
        }
    }
    else if (step == 2)
    {
        func_0209ff6c((Struct_0209ff6c*)self->titles_);
        if (func_ov023_021f21f4((Struct_ov023_021f1868_10*)self->titles_))
            end->step_++;
    }
    else if (step == 3)
    {
        short* ids;
#if defined(jpn)
        Struct_ov023_021f3aac_9* var8;
#endif
        int i;
        int count = self->titles_->count_;
        if (count > 0)
        {
            SafeAllocator* var11 = &self->menuAllocator_;
            var11->Reset();
            count = self->titles_->count_;
            ids = (short*)var11->Allocate(count * 2);
            for (int k = 0; k < count; k++)
                ids[k] = self->titles_->unknown_6a_[k];
            self->allocator_.Reset();
            self->titles_ = NULL;
            self->unknown_55c8_ = self->allocator_.Allocate(0x14);
            func_020a13c4((Struct_020a13c4*)self->unknown_55c8_);
            func_020a13e4(self->unknown_55c8_, &self->allocator_, 0, 0, 2);
            self->unknown_55d5_ = func_ov023_021ed724(self->unknown_55c8_, ids, count) & 1 ? 1 : 0;
            Struct_ov023_021f3aac_7* hero = GameState::GetInstance()->GetProtagonist();
            Struct_ov023_021f3aac_2 names;
            KeyTable_Construct(&names);
            KeyTable_Reset((Struct020dfc40*)&names);
#if defined(jpn)
            func_020e1fc4(&names, &self->allocator_, data_ov023_021fd533, ids, (unsigned short)count, hero->unknown_150_->appearance_.female_, 1);
            var8 = (Struct_ov023_021f3aac_9*)var11->Allocate(count * sizeof(void*));
            for (i = 0; i < count; i++)
            {
                void* entry = func_020a15bc((Struct_020a15bc*)self->unknown_55c8_, ids[i]);
                if (entry == NULL)
                    continue;
                const char* title = KeyTable_Get((Container020e0310*)&names, ids[i]);
                if (title == NULL)
                    continue;
                func_ov023_021f222c((Struct_ov023_021f1868_11*)&var8[i]);
                func_ov023_021f229c(&var8[i], entry);
                func_ov023_021f2304(&var8[i], (char*)title);
            }
            self->allocator_.Reset();
            self->unknown_55c8_ = NULL;
            self->pages_ = (Struct_ov023_021f3aac_9*)self->allocator_.Allocate(count * sizeof(Struct_ov023_021f3aac_9));
            for (i = 0; i < count; i++)
            {
                func_ov023_021f222c((Struct_ov023_021f1868_11*)&self->pages_[i]);
                func_ov023_021f229c(&self->pages_[i], &var8[i]);
                func_ov023_021f2304(&self->pages_[i], (char*)&var8[i] + 0xc);
            }

#else
            BackgroundLoader::AddLockGlobal();
            unsigned int size = 0;
            char gp2[0x40];
            __clear(gp2, sizeof(gp2));
            char inner[0x20];
            __clear(inner, sizeof(inner));
            sprintf(gp2, data_ov023_021fe2a0, hero->unknown_150_->appearance_.female_);
            sprintf(inner, data_ov023_021fe2b7, hero->unknown_150_->appearance_.female_);
            void* file = ExtractFileFromGP2(gp2, inner, &size);
            if (file != NULL)
                func_020e0028(&names, &self->allocator_, file, size, ids, (unsigned short)count);
            BackgroundLoader::RemoveLockGlobal();
            self->pages_ = (Struct_ov023_021f3aac_9*)self->allocator_.Allocate(count * sizeof(Struct_ov023_021f3aac_9));
            for (i = 0; i < count; i++)
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

#endif
            self->unknown_55d4_ = count;
            var11->Reset();
            end->step_++;
        }
        else if (count == 0)
        {
            self->allocator_.Reset();
            self->titles_ = NULL;
            self->busy_ = 0;
            return 0x10;
        }
    }
    else if (step == 4)
    {
        self->unknown_55cc_ = (Struct_ov023_021f3aac*)self->allocator_.Allocate(0x44c);
        func_ov023_021eb138(self->unknown_55cc_, 2);
        func_ov023_021eb080(self->unknown_55cc_, &self->allocator_);
        func_ov023_021eb564(self->unknown_55cc_, self->pages_, self->unknown_55d4_);
        func_ov023_021f2348(self->unknown_55cc_, self->unknown_55d5_);
        end->step_++;
    }
    else if (step == 5)
    {
        if (self->unknown_55cc_->flags_ & GUIDE_WINDOW_MESSAGE_WINDOW)
            end->step_ = step + 1;
    }
    else if (step == 6)
    {
        func_ov023_021eb26c(self->unknown_55cc_);
        self->allocator_.Reset();
        self->unknown_55cc_ = NULL;
        self->pages_ = NULL;
        self->unknown_55d4_ = 0;
        self->unknown_55d5_ = 0;
        self->busy_ = 0;
        return 0x10;
    }
    return self->unknown_eac_;
}
