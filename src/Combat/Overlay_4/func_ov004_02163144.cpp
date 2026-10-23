#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"



struct Struct_020534ac;

struct ActiveEntry02046900;
int Pac_CountFiles(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
void Background_Init(struct List0204af64* obj);

void Background_FlushFile(void* obj, char* str);

struct SelfTag0204b3a0;
void Background_UploadFile(struct SelfTag0204b3a0* self, char* str);


struct Struct_ov004_02163144 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_[3];
};

#if defined(jpn)
struct Struct_ov004_021707e8_9 { char unknown_0_[0x10]; int unknown_20_; char unknown_14_[0xc]; int unknown_24_; };
#else
struct Struct_ov004_021707e8_9 { char unknown_0_[0x20]; int unknown_20_; int unknown_24_; };
#endif
extern Struct_ov004_021707e8_9 data_ov004_021707e8;
extern char data_ov004_02170542;

// USA: func_ov004_02163144
extern "C" ARM int func_ov004_02163144() {
    int var0 = 1;
    int var1 = (int)BackgroundLoader::GetInstance();

    if (data_ov004_021707e8.unknown_24_ == 0) {
        *(int*)0x4001010 = 0;
        *(int*)0x4001014 = 0;
        data_ov004_021707e8.unknown_20_ = ((BackgroundLoader*)(var1))->QueueLoadFile((const char*)((int)&data_ov004_02170542), (SafeAllocator*)(0));
        data_ov004_021707e8.unknown_24_ = data_ov004_021707e8.unknown_24_ + 1;
    } else if (data_ov004_021707e8.unknown_24_ == 1) {
        if (((BackgroundLoader*)(var1))->GetTaskStatus((int)(data_ov004_021707e8.unknown_20_))) {
            int var2;
            int var3;
            int var4;
            void* var5;
            Struct_ov004_02163144 var6;

            ((BackgroundLoader*)((struct List0202fec8*)data4))->GetLoadedFileByID((int)(data_ov004_021707e8.handle), (void**)(&recListHead), (unsigned int*)(&val2Ignored));
            int count = Pac_CountFiles((struct ActiveEntry02046900*)recListHead);
            Background_Init((struct List0204af64*)&s);
            s.lo = 1;
            s.hi = 1;
            for (int i = 0; i < count; i++) {
                void* rec = Pac_GetFile((struct Rec020467f0*)recListHead, i, &dummyPtr, &dummyOut44);
                if (rec) {
                    Background_FlushFile(&s, (char*)rec);
                    Background_UploadFile((struct SelfTag0204b3a0*)&s, (char*)rec);
                }
            }
            ((BackgroundLoader*)(var1))->RemoveTask((int)(data_ov004_021707e8.unknown_20_));
            data_ov004_021707e8.unknown_20_ = -1;
            var0 = 0;
        }
    }
    return var0;
}
