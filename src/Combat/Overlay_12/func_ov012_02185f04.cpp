#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov012_02185f04_5000 = 0x1354, kAllocatorOffset = 0x7c, kTableOffset = 0x131c };
#else
enum { Enum_ov012_02185f04_5000 = 0x1388, kAllocatorOffset = 0x84, kTableOffset = 0x1344 };
#endif

struct Container020dffc8;
extern "C" int KeyTable_Load(Container020dffc8*, SafeAllocator*, void*, unsigned int);

// USA: func_ov012_02185f04
extern "C" ARM void func_ov012_02185f04(char* editor) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int task = *(int*)(editor + Enum_ov012_02185f04_5000);
    void* fileData;
    unsigned int fileSize;
    loader->GetLoadedFileByID(task, &fileData, &fileSize);
    ((SafeAllocator*)(editor + kAllocatorOffset))->Reset();
    KeyTable_Load((Container020dffc8*)(editor + kTableOffset), (SafeAllocator*)(editor + kAllocatorOffset), fileData, fileSize);
    loader->RemoveTask(*(int*)(editor + Enum_ov012_02185f04_5000));
    *(int*)(editor + Enum_ov012_02185f04_5000) = -1;
}
