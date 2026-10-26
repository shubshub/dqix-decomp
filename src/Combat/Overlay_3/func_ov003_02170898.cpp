#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue840_860 = 0x860 };
#else
enum { kRegionValue840_860 = 0x840 };
#endif

extern "C" void* Zone3D_GetInstance(void);

struct Elem020985ec {
    unsigned char pad0[0x10];
    unsigned int key;
    unsigned char pad1[0xd4];
};

struct Struct_ov003_02170898 {
    unsigned char pad[0x1b38];
    int count;
};

// USA: func_ov003_02170898
extern "C" ARM void func_ov003_02170898(unsigned char* self) {
    struct Elem020985ec* arr = (struct Elem020985ec*)((char*)Zone3D_GetInstance() + kRegionValue840_860);
    int count = (*(struct Struct_ov003_02170898**)(self + 0x170))->count;

    int i;
    for (i = 0; i < 0x1e; i++) {
        *(int*)(self + i * 4 + 0xf4) = 0;
    }

    int n;
    int j = 0;
    for (n = 0; n < 0x1e; n++) {
        struct Elem020985ec* e = &arr[n];
        if ((e->key >> 2) != 0) {
            *(struct Elem020985ec**)(self + j * 4 + 0xf4) = e;
            j++;
        }
    }

    int var6 = (count - 1) / 8 + 1;
    self[4] = var6;
    if (self[0] > self[4]) self[0] = self[4];

    if (self[0] == self[4]) {
        int var7 = count % 8;
        if (var7 != 0) {
            self[5] = (unsigned char)var7;
            return;
        }
    }
    self[5] = 8;
}
