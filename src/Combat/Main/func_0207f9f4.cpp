#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct StreamHeader;
struct List020727d8;
struct PacRecord;

void ResetListHeader020727d8(List020727d8* list);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a, int b, int c);
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
char* MessageSystem_GetInstance();
void InitStreamAndRun0207f524(void* a, void* b, StreamHeader* c, int d);
struct EntryArray0207efdc;
void LoadEntryArrayFromStream0207ef74(EntryArray0207efdc*, SafeAllocator*, StreamHeader*, int);

struct Struct_0207f9f4 {
    void* unknown_0_;
    char unknown_4_[8];
    char unknown_c_[8];
    SafeAllocator* unknown_14_;
    int unknown_18_;
    int unknown_1c_;
#ifndef jpn
    int unknown_20_[3];
#endif
};

// USA: func_0207f9f4
extern "C" ARM int func_0207f9f4(Struct_0207f9f4* arg0) {
    if (arg0->unknown_1c_ < 0) {
#ifdef jpn
        return -1;
#else
        int* var0 = arg0->unknown_20_;
        if (var0[0] < 0) {
            if (var0[1] < 0) {
                if (var0[2] < 0) {
                    return -1;
                }
            }
        }

        BackgroundLoader* var1 = BackgroundLoader::GetInstance();
        int var2 = 1;
        for (int var3 = 0; var3 < 3; var3++) {
            if (var1->GetTaskStatus(var0[var3]) == 0) {
                var2 = 0;
            }
        }

        if (var2 != 0) {
            void* var4;
            unsigned int var5;
            var1->GetLoadedFileByID(var0[0], &var4, &var5);
            arg0->unknown_0_ = arg0->unknown_14_->Allocate(8);
            func_020727d8((Struct_020727d8*)arg0->unknown_0_);
            if (var4 != 0) {
                func_020728ac(arg0->unknown_0_, arg0->unknown_14_, var4, var5, 0, 0, 0);
            }
            var1->GetLoadedFileByID(var0[1], &var4, &var5);
            if (var4 != 0) {
                func_0207f524(arg0->unknown_4_, arg0->unknown_14_, (Struct_02013fb4*)var4, var5);
            }
            var1->GetLoadedFileByID(var0[2], &var4, &var5);
            if (var4 != 0) {
                func_0207ef74((Struct_0207ed1c*)arg0->unknown_c_, (SafeAllocator*)arg0->unknown_14_, (Struct_02013fb4*)var4, var5);
            }

            for (int var6 = 0; var6 < 3; var6++) {
                var1->RemoveTask(*var0);
                *var0 = -1;
                var0++;
            }
    #ifdef jpn
        self->field18 = *(int*)(MessageSystem_GetInstance() + 0x28);
#else
        self->field18 = *(int*)(MessageSystem_GetInstance() + 0x5c);
#endif
            return 0;
        }
        return 1;
#endif
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(self->field1c) != 0) {
        void* out;
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->field1c, &file, &size);
        int n = Pac_CountFiles((PacRecord*)file);
        void* recs[3];
        int outs[3];
        for (int i = 0; i < n; i++) {
            recs[i] = Pac_GetFile((PacRecord*)file, i, &out, &outs[i]);
        }
        arg0->unknown_0_ = arg0->unknown_14_->Allocate(8);
        func_020727d8((Struct_020727d8*)arg0->unknown_0_);
        func_020728ac(arg0->unknown_0_, arg0->unknown_14_, var12[0], var13[0], 0, 0, 0);
        func_0207f524(arg0->unknown_4_, arg0->unknown_14_, (Struct_02013fb4*)var12[1], var13[1]);
        func_0207ef74((Struct_0207ed1c*)arg0->unknown_c_, (SafeAllocator*)arg0->unknown_14_, (Struct_02013fb4*)var12[2], var13[2]);
        var7->RemoveTask(arg0->unknown_1c_);
        arg0->unknown_1c_ = -1;
#ifdef jpn
        self->field18 = *(int*)(MessageSystem_GetInstance() + 0x28);
#else
        self->field18 = *(int*)(MessageSystem_GetInstance() + 0x5c);
#endif
        return 0;
    }
    return 1;
}
