#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Struct_02057de0 {
    unsigned char unknown_0_[0x1ec];
    struct Struct_02057de0* unknown_1ec_;
};

struct Struct_02057de0_2 {
    struct Struct_02057de0* unknown_0_;
    int unknown_4_;
};

int CreateAndRegisterNode02057de0(NodeList02057de0* list, int a1, SafeAllocator* alloc, int a2, int a3);
int CollectEntriesMatchingField0xd802058680(char* base, int value, void** out, int limit);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);

struct Struct_020dbdc0;
extern "C" void func_020dbf70(struct Struct_020dbdc0* arg0);

extern "C" int func_02057924(void);

struct Struct_020dbd9c {
    SafeAllocator* unknown_0_;
    char* unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    unsigned char unknown_14_;
};

// USA: func_020dbdc0
extern "C" ARM void func_020dbdc0(Struct_020dbd9c* arg0) {
    if (arg0->unknown_c_ >= 0) {
        BackgroundLoader* var0 = BackgroundLoader::GetInstance();
        if (var0->GetTaskStatus(arg0->unknown_c_) != 0) {
            Struct_02057de0_2* var1 = (Struct_02057de0_2*)func_02057924();
            void* var2 = NULL;
            unsigned int var3 = 0;
            var0->GetLoadedFileByID(arg0->unknown_c_, &var2, &var3);
            void* var4 = arg0->unknown_0_->Allocate(var3);
            if (var4 == NULL) {
                func_020dbf70((struct Struct_020dbdc0*)arg0);
                return;
            }
            memcpy(buf, fileData, fileLen);
            VramState_Restore(self->f4);
            CreateAndRegisterNode02057de0(list, self->f8, self->f0, (int)buf, (int)fileLen);
            VramState_Save(self->f4);
            ReleaseHandle020dbf70((struct Obj020dbf70*)self);
            self->f10 = 2;
        }
    }
    if (arg0->unknown_14_ != 0) {
        char* var5 = (char*)func_02057924();
        if (var5 != NULL) {
            int var6 = func_02058680(var5, arg0->unknown_8_, NULL, 0);
            if (var6 <= 0) {
                arg0->unknown_14_ = 0;
            }
        }
    }
}
