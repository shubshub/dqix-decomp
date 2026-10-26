#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Struct_02057de0 {
    unsigned char pad[0x1ec];
    struct Struct_02057de0* next;
};

struct Struct_02057de0_2 {
    struct Struct_02057de0* head;
    int count;
};

extern "C" int func_02057de0(Struct_02057de0_2* list, int a1, SafeAllocator* alloc, int a2, int a3);
extern "C" int func_02058680(char* base, int value, void** out, int limit);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);

struct Struct_020dbdc0;
extern "C" void func_020dbf70(struct Struct_020dbdc0* o);

extern "C" int func_02057924(void);

struct Struct_020dbd9c {
    SafeAllocator* f0;
    char* f4;
    int f8;
    int fc;
    int f10;
    unsigned char f14;
};

// USA: func_020dbdc0
extern "C" ARM void func_020dbdc0(Struct_020dbd9c* self) {
    if (self->fc >= 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->fc) != 0) {
            Struct_02057de0_2* list = (Struct_02057de0_2*)func_02057924();
            void* fileData = NULL;
            unsigned int fileLen = 0;
            loader->GetLoadedFileByID(self->fc, &fileData, &fileLen);
            void* buf = self->f0->Allocate(fileLen);
            if (buf == NULL) {
                func_020dbf70((struct Struct_020dbdc0*)self);
                return;
            }
            memcpy(buf, fileData, fileLen);
            VramState_Restore(self->f4);
            func_02057de0(list, self->f8, self->f0, (int)buf, (int)fileLen);
            VramState_Save(self->f4);
            func_020dbf70((struct Struct_020dbdc0*)self);
            self->f10 = 2;
        }
    }
    if (self->f14 != 0) {
        char* base = (char*)func_02057924();
        if (base != NULL) {
            int count = func_02058680(base, self->f8, NULL, 0);
            if (count <= 0) {
                self->f14 = 0;
            }
        }
    }
}
