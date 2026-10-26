#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Container020dffc8 {
    unsigned int count : 12;
    unsigned int unknown_1_4_ : 19;
    unsigned int unknown_3_7_ : 1;
    void* elements;
    void* strings;
};

extern "C" int KeyTable_Load(Container020dffc8* dest, SafeAllocator* allocator, void* fileData, unsigned int size);

#if defined(jpn)
extern const char data_020f143c[];
#endif
extern const char data_020f1368[];
extern const char data_020f1382[];

struct Struct_02092f80 {
    SafeAllocator allocator;
    Container020dffc8 container;
    unsigned char unknown20[0xc];
    int taskId;
    unsigned char pad2c[0x34 - 0x30];
    unsigned char unknown_34_;
    unsigned char unknown_35_;
    unsigned char unknown_36_;
    unsigned char unknown_37_;
};

// USA: func_02092f80
extern "C" ARM void func_02092f80(Struct_02092f80* obj) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char state = obj->unknown_35_;

    if (state == 0) {
#if defined(jpn)
        obj->taskId = loader->QueueLoadFile(data_020f143c, NULL);
#else
        obj->taskId = loader->QueueLoadFileInGP2(data_020f1368, data_020f1382, NULL);
#endif
        obj->unknown_35_++;
    } else if (state == 1) {
        if (loader->GetTaskStatus(obj->taskId)) {
            void* fileData;
            unsigned int fileSize;
            loader->GetLoadedFileByID(obj->taskId, &fileData, &fileSize);
            obj->allocator.Reset();
            KeyTable_Load(&obj->container, &obj->allocator, fileData, fileSize);
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            obj->unknown_35_++;
        }
    } else if (state == 2) {
        obj->unknown_34_ = 3;
        obj->unknown_35_ = 0;
        if (obj->unknown_37_ & 0x1) obj->unknown_34_ = 1;
        if (!(obj->unknown_37_ & 0x8)) obj->unknown_37_ |= 0x4;
        obj->unknown_36_ = 0;
    }
}
