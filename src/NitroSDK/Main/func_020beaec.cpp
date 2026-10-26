#include <globaldefs.h>

struct Obj020bda58;
struct Struct_020bf484;
typedef void (*Type_020bbf84)(void* mem, unsigned int size, unsigned int data1, unsigned int data2);
extern "C" void* func_020bd6ac(int index);
extern "C" void* func_020bda58(struct Obj020bda58* heap, unsigned int size, Type_020bbf84 callback, int data1, int data2);
extern "C" void func_020bf484(int arg0, void* unused1, struct Struct_020bf484* obj);
extern "C" void func_020bf1a0(void* player);

struct Struct_020beaec {
    unsigned char unknown_0_;
    unsigned char unknown_1_[16];
    unsigned char padding[7];
};

struct Struct_02110a4c_2 {
    char pad0[0x124];
    unsigned char unknown_124_;
    unsigned char reserved;
    unsigned char unknown_126_[6];
    void* buffer;
    unsigned int unknown_130_;
    char pad1[0x174 - 0x134];
};

extern struct Struct_02110a4c_2 data_02110a4c[4];

// USA: func_020beaec
extern "C" ARM int func_020beaec(struct Obj020bda58* heap)
{
    int var0;
    const struct Struct_020beaec* var1;
    struct Struct_02110a4c_2* player;
    void* buffer;
    unsigned int var4;
    int i;

    for (var0 = 0; var0 < 4; ++var0) {
        player = &data_02110a4c[var0];

        var1 = (const struct Struct_020beaec*)func_020bd6ac(var0);
        if (var1 == NULL)
            continue;

        player->unknown_124_ = var1->unknown_0_;
        for (i = 0; i < var1->unknown_0_; i++) {
            player->unknown_126_[i] = var1->unknown_1_[i];
        }

        if (heap != NULL) {
            var4 = 512 * 4 * player->unknown_124_;
            buffer = func_020bda58(heap, var4, (Type_020bbf84)func_020bf484, (int)player, 0);
            if (buffer == NULL)
                return 0;

            func_020bf1a0(player);

            player->buffer = buffer;
            player->unknown_130_ = var4;
        }
    }

    return 1;
}
