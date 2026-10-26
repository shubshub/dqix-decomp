#include <globaldefs.h>
#include "World/Object3D.h"
#include "Filesystem/FileIO.h"
#if defined(jpn)
#define data_020e8d54 data_020e8e70
#endif

struct Struct_02000c9c_26 {
    unsigned char storage[0xac];
};

struct Struct_0208f588 {
    int unused0;
    void* data;
    unsigned int size;
    void* allocator;
    int flag;
    int unknown_14_;
    int pad18;
    int unknown_1c_;
};

struct Struct_0208f588_2 {
    unsigned char pad0[0xc];
    unsigned char mode : 4;
    unsigned char high : 4;
};

struct Context02012fe4 {
    unsigned char pad0[8];
    struct Struct_0208f588_2* flags;
};

struct Struct_0208f588_4 {
    void* data;
    unsigned int size;
    struct Struct_02000c9c_26 object;
    unsigned char loaded;
    unsigned char unknown_b5_;
};

struct Struct_020e8d54 {
    char text[0x28];
};

extern const struct Struct_020e8d54 data_020e8d54;

extern "C" struct Context02012fe4* Zone3D_GetInstance(void);
struct ObjectArchiveLoadInfo;

extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);

// USA: func_0208f588
extern "C" ARM int func_0208f588(struct Struct_0208f588_4* self, SafeAllocator* allocator, char* pairObj) {
    unsigned int size;
    struct Struct_020e8d54 path;
    struct Struct_0208f588 info;
    void* data;

    self->loaded = 0;
    ((Object3D*)&self->object)->Destroy();
    ((Object3D*)&self->object)->Initialize();
    if (Zone3D_GetInstance()->flags->mode != 0) {
        return 0;
    }

    path = data_020e8d54;
    data = LoadFileIntoNewAllocation(path.text, *allocator, &size);
    if (data == 0) {
        return 0;
    }
    unsigned int length = size;
    self->data = data;
    self->size = length;
    self->loaded = 1;
    self->unknown_b5_ = 1;

    info.unused0 = 0;
    info.data = 0;
    info.size = 0;
    info.flag = 0;
    info.unknown_14_ = 0;
    info.pad18 = 0;
    info.unknown_1c_ = 0;
    info.allocator = allocator;
    info.data = self->data;
    info.size = self->size;

    VramState_Restore(pairObj);
    ((Object3D*)&self->object)->Initialize();
    ((Object3D*)&self->object)->LoadFromCHRArchive((ObjectArchiveLoadInfo*)&info);
    ((Object3D*)&self->object)->MakeHidden();
    VramState_Save(pairObj);
    return 1;
}
