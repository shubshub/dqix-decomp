#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Combat/WorkRecord.h>
#include <std_library_functions.h>

#if defined(jpn)
#define data_ov001_021657ad data_ov001_02166d71
#define data_ov001_021657be data_ov001_02166d82
#define data_ov001_021657ce data_ov001_02166d92
#define data_ov001_021657d1 data_ov001_02166d95
#endif

struct Struct_0203e03c;
struct Struct_0203dd10;
struct Struct_0203d028_19;
struct Struct_ov001_0215f3fc_3
{
    int type;
    int value;
};
struct Struct_0203d028_14
{
    void* context;
    char unknown_4_[0x4c];
    unsigned int flags;
};
struct Struct_ov001_0215f3fc_4
{
    char unknown_0_[8];
    void* descriptor;
    Struct_0206bf2c* record;
    char unknown_10_[4];
    Struct_0203d028_14* motion;
    char unknown_18_[8];
};
struct Struct_ov001_0215f3fc_5
{
    unsigned short field_0x0;
    unsigned char type;
    unsigned char unknown_3_;
#if defined(jpn)
    char unknown1_4_[0xc];
#endif
    char name[16];
};
struct Struct_ov001_0215f3fc
{
    char data[0x70];
};
struct StreamResources0215f3fc
{
#if defined(jpn)
    char unknown_0_[0x27c];
#else
    char unknown1_0_[0x2cc];
#endif
    Struct_ov001_0215f3fc records[33];
};
extern "C" void* func_0203cf4c();
extern "C" const char* func_ov017_021d612c(void*);
extern "C" int func_0203e03c(Struct_0203e03c*);
extern "C" void func_ov017_021d6134(void*, int);
extern "C" unsigned int func_ov001_0215a750(const char*, void**);
extern "C" int func_ov017_021d60f4(Struct_ov001_0215f3fc_3*);
extern "C" void func_020404c0(int*);
extern "C" void NpcWalker_Init(void*);
extern "C" void* func_0203d004(void*);
extern "C" void func_02040530(int*, int);
extern "C" void func_02040520(int*, int);
extern "C" void func_0203f02c(Struct_0203d028_14*, int, int, char*, int, int);
extern "C" void func_0203f138(Struct_0203d028_14*, int);
extern "C" void func_020408c8(Struct_0203d028_19*, short, short, short);
extern "C" void func_0203dd10(Struct_0203dd10*, unsigned int, int);
extern const char data_ov001_021657ad[];
extern const char data_ov001_021657b2[];
extern const char data_ov001_021657be[];
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_021657ce[];
extern const char data_ov001_021657d1[];

// USA: func_ov001_0215f3fc
extern "C" ARM int func_ov001_0215f3fc(Struct_ov001_0215f3fc_3* arguments, int count)
{
    GameState* game = GameState::GetInstance();
    void* list = func_0203cf4c();
    StreamResources0215f3fc* resources = (StreamResources0215f3fc*)game->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!resources)
    {
        return 0;
    }
    const char* name = func_ov017_021d612c(arguments++);
    int slot = func_0203e03c((Struct_0203e03c*)list);
    if (slot == -1)
    {
        return 0;
    }
    func_ov017_021d6134(arguments++, slot);
    if (slot >= 32)
    {
        return 0;
    }
    char filename[80];
    if (strstr(name, data_ov001_021657ad))
    {
        sprintf(filename, data_ov001_021657b2, name);
    }
    else
    {
        sprintf(filename, data_ov001_021657be, name);
    }
    void* file;
    unsigned int length;
    int locked = 0;
    loader->GetLoadedFileByName(filename, &file, &length);
    if (!file)
    {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (!func_ov001_0215a750(filename, &file))
        {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    int var10 = 0;
    if (count >= 3)
    {
        var10 = func_ov017_021d60f4(arguments++);
    }
    SafeAllocator* allocator = data_ov001_021658b8[var10];
    int recordIndex = 27;
    if (count >= 4)
    {
        recordIndex = func_ov017_021d60f4(arguments);
    }
    Struct_ov001_0215f3fc_4* entry = (Struct_ov001_0215f3fc_4*)allocator->Allocate(0x20);
    if (!entry)
    {
        if (locked)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    func_020404c0((int*)entry);
    Struct_0206bf2c* record = (Struct_0206bf2c*)allocator->Allocate(0x78);
    if (!record)
    {
        if (locked)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    func_0206bf2c(record);
#if defined(jpn)
    enum { regionalOffset0 = 0x20 };
#else
    enum { regionalOffset0 = 0x14 };
#endif
    Struct_ov001_0215f3fc_5* descriptor = (Struct_ov001_0215f3fc_5*)allocator->Allocate(regionalOffset0);
    if (!descriptor)
    {
        if (locked)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    memset(descriptor, 0, regionalOffset0);
    entry->motion = (Struct_0203d028_14*)allocator->Allocate(0x9c);
    if (!entry->motion)
    {
        if (locked)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    NpcWalker_Init(entry->motion);
    void* context = func_0203d004(list);
    if (entry->motion)
    {
        entry->motion->context = context;
    }
    descriptor->type = 3;
    if (strstr(name, data_ov001_021657ad))
    {
        int nameLength = 5;
        if (strstr(name, data_ov001_021657ce))
        {
            nameLength = 7;
            entry->motion->flags |= 8;
        }
        memcpy(descriptor->name, name, nameLength);
        descriptor->name[nameLength] = 0;
    }
    else
    {
        sprintf(descriptor->name, data_ov001_021657d1, name);
    }
    func_02040530((int*)entry, (int)record);
    func_02040520((int*)entry, (int)descriptor);
    Struct_ov001_0215f3fc* var18 = resources->records;
    char* recordData = var18[recordIndex].data;
    unsigned int var20 = length;
    void* var21 = file;
    if (entry->motion)
    {
        func_0203f02c(entry->motion, (int)(filename + 9), (int)allocator,
            recordData, (int)var21, var20);
    }
    if (entry->motion)
    {
        func_0203f138(entry->motion, 1);
    }
    if (locked)
    {
        BackgroundLoader::RemoveLockGlobal();
    }
    func_020408c8((Struct_0203d028_19*)entry, 0x8f, 0x8f, 0x8f);
    func_0203dd10((Struct_0203dd10*)list, slot, (int)entry);
    return 1;
}
