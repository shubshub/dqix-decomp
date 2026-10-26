#include <globaldefs.h>

extern "C" int rand(void);

struct Struct_02028460_3 { int x; int y; int z; };
extern "C" extern int Vector3fix_Distance(struct Struct_02028460_3* a, struct Struct_02028460_3* b);

struct Npc {
    char pad[0x14];
    void* walker;   // its NpcWalker
    void* model;    // its 3D-model mover (NpcModel_WalkTo)
};
extern "C" int Npc_WalkTo(struct Npc* obj, int arg);

struct Struct_0204117c {
    int x, y, z;
    int f0xc;
    struct Struct_0204117c* next;
};

struct Struct_0204117c_2 {
    unsigned char pad0[0x1f];
    unsigned char unknown_1f_;
    unsigned char pad20[0x22 - 0x20];
    unsigned char unknown_22_;
    unsigned char unknown_23_[0x34 - 0x23];
    struct Struct_0204117c* listHead;
};

struct Struct_02040c2c_5 {
    unsigned char pad0[0xc];
    struct Struct_0204117c_2* cont;
};

// USA: func_0204117c
extern "C" ARM void func_0204117c(struct Struct_02040c2c_5* obj, struct Struct_02028460_3* arg1) {
    struct Struct_0204117c* node = obj->cont->listHead;
    while (node != NULL) {
        if (node->f0xc != 0) {
            if (Vector3fix_Distance((struct Struct_02028460_3*)node, arg1) != 0) {
                Npc_WalkTo((struct Npc*)obj, (int)node);
                goto epilogue;
            }
            break;
        } else {
            node = node->next;
        }
    }
    node->f0xc = 0;
    node = node->next;
    if (obj->cont->unknown_1f_ == 9) {
        int var1 = rand() % obj->cont->unknown_22_;
        int i;
        for (i = 0; i < var1; i++) {
            node = node->next;
        }
    }
    {
        struct Struct_02028460_3 localBuf;
        localBuf.x = node->x;
        localBuf.y = node->y;
        localBuf.z = node->z;
        node->f0xc = 1;
        Npc_WalkTo((struct Npc*)obj, (int)&localBuf);
    }
epilogue:;
}
