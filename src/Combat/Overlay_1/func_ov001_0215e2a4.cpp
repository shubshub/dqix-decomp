#include <globaldefs.h>
#if defined(jpn)
enum{Enum_ov001_0215e2a4_2104=0x708,Enum_ov001_0215e2a4_2456=0x868};
#else
enum{Enum_ov001_0215e2a4_2104=0x838,Enum_ov001_0215e2a4_2456=0x998};
#endif

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
#if defined(jpn)
extern "C" void func_0204500c(void*, int, int);
#else
extern "C" void func_0204500c(void*, int, int, int);
#endif
extern "C" int MessageSystem_GetInstance();
struct Struct_ov001_021658d8;
extern "C" void* func_ov001_02153884(struct Struct_ov001_021658d8* t, int key);

extern Struct_ov001_021658d8 data_ov001_021658d8;

struct Struct_ov001_0215e2a4 { char pad0[4]; int val; };
struct Struct_ov001_0215e2a4_2 { int type; };

// USA: func_ov001_0215e2a4
extern "C" ARM int func_ov001_0215e2a4(Struct_ov001_0215e2a4_2* self, int mode) {
    char* g = (char*)MessageSystem_GetInstance();
    int type = self->type;
    switch (type) {
    case 0: {
        int idx = func_ov017_021d60f4(self);
        Struct_ov001_0215e2a4* entry = (Struct_ov001_0215e2a4*)func_ov001_02153884(&data_ov001_021658d8, idx);
        if (entry == NULL) return 0;
        *(int*)(g + 0x1000 + Enum_ov001_0215e2a4_2104) = -1;
        int flag = 1;
        if (mode >= 2) {
            int r = func_ov017_021d60f4((char*)self + 0x8);
            if (r & 1) flag = 0;
        }
#if defined(jpn)
        func_0204500c(g, entry->val, flag);
#else
        func_0204500c(g, entry->val, flag, 0xe3);
#endif
        *(int*)(g + Enum_ov001_0215e2a4_2456) = 1;
        break;
    }
    case 2: {
        void* extra = func_ov017_021d612c(self);
        *(int*)(g + 0x1000 + Enum_ov001_0215e2a4_2104) = -1;
#if defined(jpn)
        func_0204500c(g, (int)extra, 1);
#else
        func_0204500c(g, (int)extra, 1, 0xe3);
#endif
        *(int*)(g + Enum_ov001_0215e2a4_2456) = 1;
        break;
    }
    }
    return 1;
}
