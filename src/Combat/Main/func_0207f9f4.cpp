#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct StreamHeader;
struct Struct_020727d8;
struct PacRecord;

extern "C" void func_020727d8(Struct_020727d8* list);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a, int b, int c);
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" char* MessageSystem_GetInstance();
extern "C" void func_0207f524(void* a, void* b, StreamHeader* c, int d);
struct Struct_0207ed1c;
extern "C" void func_0207ef74(Struct_0207ed1c*, SafeAllocator*, StreamHeader*, int);

struct Struct_0207f9f4 {
    void* field0;
    char sub4[8];
    char unknown_c_[8];
    SafeAllocator* field14;
    int field18;
    int field1c;
#ifndef jpn
    int field20[3];
#endif
};

// USA: func_0207f9f4
extern "C" ARM int func_0207f9f4(Struct_0207f9f4* self) {
    if (self->field1c < 0) {
#ifdef jpn
        return -1;
#else
        int* ids = self->field20;
        if (ids[0] < 0) {
            if (ids[1] < 0) {
                if (ids[2] < 0) {
                    return -1;
                }
            }
        }

        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        int var2 = 1;
        for (int i = 0; i < 3; i++) {
            if (loader->GetTaskStatus(ids[i]) == 0) {
                var2 = 0;
            }
        }

        if (var2 != 0) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(ids[0], &file, &size);
            self->field0 = self->field14->Allocate(8);
            func_020727d8((Struct_020727d8*)self->field0);
            if (file != 0) {
                func_020728ac(self->field0, self->field14, file, size, 0, 0, 0);
            }
            loader->GetLoadedFileByID(ids[1], &file, &size);
            if (file != 0) {
                func_0207f524(self->sub4, self->field14, (StreamHeader*)file, size);
            }
            loader->GetLoadedFileByID(ids[2], &file, &size);
            if (file != 0) {
                func_0207ef74((Struct_0207ed1c*)self->unknown_c_, (SafeAllocator*)self->field14, (StreamHeader*)file, size);
            }

            for (int j = 0; j < 3; j++) {
                loader->RemoveTask(*ids);
                *ids = -1;
                ids++;
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
        self->field0 = self->field14->Allocate(8);
        func_020727d8((Struct_020727d8*)self->field0);
        func_020728ac(self->field0, self->field14, recs[0], outs[0], 0, 0, 0);
        func_0207f524(self->sub4, self->field14, (StreamHeader*)recs[1], outs[1]);
        func_0207ef74((Struct_0207ed1c*)self->unknown_c_, (SafeAllocator*)self->field14, (StreamHeader*)recs[2], outs[2]);
        loader->RemoveTask(self->field1c);
        self->field1c = -1;
#ifdef jpn
        self->field18 = *(int*)(MessageSystem_GetInstance() + 0x28);
#else
        self->field18 = *(int*)(MessageSystem_GetInstance() + 0x5c);
#endif
        return 0;
    }
    return 1;
}
