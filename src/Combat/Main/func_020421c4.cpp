#include <globaldefs.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

struct Struct0204a82c {
    int f0;
    short f4;
    short unknown_6_;
    short f8;
    char fa;
};

struct Struct_020421c4_2 {
    char* base;
    short index;
    char pad[4];
    unsigned char flag;
};

struct Struct_020421c4_3 {
    char pad[8];
    char* unknown_8_;
    char* unknown_c_;
};

struct Struct_020421c4_4;

struct Struct_020421c4_5 {
    char pad0[0x34];
    void* f34;
    char unknown_38_[0x10];
    void* unknown_48_;
    void* unknown_4c_;
    void* unknown_50_;
    char unknown_54_[8];
    void* unknown_5c_;
    void* f60;
    void* f64;
    char pad68[0x26c];
    void* unknown_2d4_;
};

struct Struct_02107800 {
    void* f0;
    void* f4;
    void* f8;
    void* fc;
    void* f10;
    void* f14;
    void* f18;
    struct Struct_020421c4_5* f1c;
    char pad20[4];
    void* f24;
    void* f28;
};

extern struct Struct_02107800 data_02107800;
extern SafeAllocator data_0210783c;
extern char data_020f000b;
extern char data_020f0023;
extern char data_020f003f;

extern "C" void func_02042944(void*);
extern "C" void TileHeader_Clear(struct Struct0204a82c*);
extern "C" int func_0204aa48(struct Struct_020421c4_2*);
extern "C" void func_02094a24(struct Struct_020421c4_4*);
extern "C" void func_02094a20(void*, SafeAllocator*);
extern "C" void func_02094a10(int);
extern "C" void func_02042998(struct Struct_020421c4_3*);

// USA: func_020421c4
extern "C" ARM void func_020421c4(SafeAllocator* alloc) {
    unsigned int fileLen;
    struct Struct0204a82c entry;
    GPCReadPair pair;
    unsigned int var3;
    unsigned int aligned;
    unsigned int old;
    unsigned int size;
    void* buf;
    void* p;
    struct Struct_020421c4_5* f1c;
    unsigned int off;
    unsigned char* base;
    unsigned int cap;

    p = alloc->Allocate(0x400);
    data_0210783c.CreateTypeA(p, 0x400);
    data_02107800.f1c = (struct Struct_020421c4_5*)alloc->Allocate(0x1e2c);
    data_02107800.f0 = alloc->Allocate(0xf99);
    data_02107800.f1c->f34 = alloc->Allocate(0xe0);
    data_02107800.f14 = alloc->Allocate(0x960);
    data_02107800.f8 = alloc->Allocate(0x280);
    data_02107800.f28 = alloc->Allocate(0x280);
    data_02107800.f24 = alloc->Allocate(0x960);
    data_02107800.f18 = alloc->Allocate(0x960);
    data_02107800.fc = alloc->Allocate(0x960);
    func_02042944(alloc);
    BackgroundLoader::AddLockGlobal();

    fileLen = 0;
    buf = LoadFileIntoMemory(&data_020f000b, g_fileLoadBuffer, &fileLen);
    TileHeader_Clear(&entry);
    if (buf != 0) {
        memcpy(&entry, buf, 0xc);
    }
    size = func_0204aa48((struct Struct_020421c4_2*)&entry);
    p = alloc->Allocate(size);
    data_02107800.f4 = p;
    memcpy(p, (void*)((int)g_fileLoadBuffer + 0x10), size);

    GPCReadPair* rp = &pair;
    off = 0;
    var3 = off;
    base = g_fileLoadBuffer;
    cap = 0x30000;
    ZeroInitGPCPointer(&rp->pGPCFile);
    rp->ZeroInitializeMachine();
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, &data_020f0023,
            base, var3, cap, 0, 0)) {
        old = var3;
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, base + old, var3,
            cap - old, &data_020f003f);
        cap = (var3 + 3) & ~3;
        pair.Reset();
        cap = off + (off + (off + cap));
        var3 = cap;
        memcpy((void*)0x01ff9740, base + old, cap);
    }

    BackgroundLoader::RemoveLockGlobal();
    data_0210783c.Reset();
    f1c = data_02107800.f1c;
    f1c->unknown_2d4_ = &data_0210783c;
    p = alloc->Allocate(0x68);
    func_02094a24((struct Struct_020421c4_4*)p);
    func_02094a20(p, alloc);
    func_02094a10((int)p);
    func_02042998((struct Struct_020421c4_3*)((char*)0x01ff9740 + off));
    if ((char*)0x01ff9740 + off != 0) {
        data_02107800.f10 = (void*)((char*)0x01ff9740 + off);
    }
    data_02107800.f1c->unknown_48_ = data_02107800.f14;
    data_02107800.f1c->unknown_4c_ = data_02107800.f8;
    data_02107800.f1c->unknown_50_ = data_02107800.f28;
    data_02107800.f1c->unknown_5c_ = data_02107800.f24;
    data_02107800.f1c->f60 = data_02107800.f18;
    data_02107800.f1c->f64 = data_02107800.fc;
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
