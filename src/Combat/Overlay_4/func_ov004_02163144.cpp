#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"



struct Struct_020534ac;

struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* entry);

extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

struct BackgroundGraphics;
extern "C" void Background_Init(struct BackgroundGraphics* obj);

extern "C" void Background_FlushFile(void* obj, char* str);

extern "C" void Background_UploadFile(struct BackgroundGraphics* self, char* str);


struct Struct_ov004_02163144 {
    unsigned char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char unknown_1d_[3];
};

#if defined(jpn)
struct Struct_ov004_021707e8_9 { char pad0[0x10]; int handle; char unknown_14_[0xc]; int state; };
#else
struct Struct_ov004_021707e8_9 { char pad0[0x20]; int handle; int state; };
#endif
extern Struct_ov004_021707e8_9 data_ov004_021707e8;
extern char data_ov004_02170542;

// USA: func_ov004_02163144
extern "C" ARM int func_ov004_02163144() {
    int ret = 1;
    int data4 = (int)BackgroundLoader::GetInstance();

    if (data_ov004_021707e8.state == 0) {
        *(int*)0x4001010 = 0;
        *(int*)0x4001014 = 0;
        data_ov004_021707e8.handle = ((BackgroundLoader*)(data4))->QueueLoadFile((const char*)((int)&data_ov004_02170542), (SafeAllocator*)(0));
        data_ov004_021707e8.state = data_ov004_021707e8.state + 1;
    } else if (data_ov004_021707e8.state == 1) {
        if (((BackgroundLoader*)(data4))->GetTaskStatus((int)(data_ov004_021707e8.handle))) {
            int recListHead;
            int var3;
            int dummyOut44;
            void* dummyPtr;
            Struct_ov004_02163144 s;

            ((BackgroundLoader*)((struct Struct_020534ac*)data4))->GetLoadedFileByID((int)(data_ov004_021707e8.handle), (void**)(&recListHead), (unsigned int*)(&var3));
            int count = Pac_CountFiles((struct PacRecord*)recListHead);
            Background_Init((struct BackgroundGraphics*)&s);
            s.lo = 1;
            s.hi = 1;
            for (int i = 0; i < count; i++) {
                void* rec = Pac_GetFile((struct PacRecord*)recListHead, i, &dummyPtr, &dummyOut44);
                if (rec) {
                    Background_FlushFile(&s, (char*)rec);
                    Background_UploadFile((struct BackgroundGraphics*)&s, (char*)rec);
                }
            }
            ((BackgroundLoader*)(data4))->RemoveTask((int)(data_ov004_021707e8.handle));
            data_ov004_021707e8.handle = -1;
            ret = 0;
        }
    }
    return ret;
}
