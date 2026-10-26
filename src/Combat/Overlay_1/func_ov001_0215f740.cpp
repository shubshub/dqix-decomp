#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void*);

#include "Combat/EntryGetterTypes.h"
#include "World/Object3D.h"
struct Struct_0203dce4_2 { char pad[0xc]; struct Struct_0203dce4* entries[0x20]; };
extern "C" void* func_0203cf4c(void);
extern "C" struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2* list, int id);
extern "C" int func_02040528(int* obj);
extern "C" void* func_0203d004(void*);
extern const char data_ov001_021657d4[];

struct Struct_0204027c_2;
extern "C" int func_02040404(struct Struct_0204027c_2* container, const char* name);
struct Struct_0204039c;
extern "C" void func_0204039c(struct Struct_0204039c* obj, int index);

struct Struct_0203d028_10;
extern "C" void func_0204128c(struct Struct_0203d028_10* obj);
extern "C" void func_02040504(int* obj);

struct Struct_0203dd10;
extern "C" void func_0203dd10(Struct_0203dd10* obj, unsigned int index, int value);

struct Struct_ov001_0215f740 { int a; int b; int c; int d; };
extern "C" void func_ov001_0215acb4(Struct_ov001_0215f740* p);

struct Struct_ov001_02165880_38 { char pad0[4]; Struct_ov001_0215f740* table; };
extern Struct_ov001_02165880_38 data_ov001_02165880;

// USA: func_ov001_0215f740
extern "C" ARM int func_ov001_0215f740(void* self) {
    int id = func_ov017_021d60f4(self);
    if (id >= 0x20) {
        return 0;
    }
    struct Struct_0203dce4_2* list = (struct Struct_0203dce4_2*)func_0203cf4c();
    struct Struct_0203dce4* entry = func_0203dce4(list, id);
    if (entry == NULL) {
        return 0;
    }
    if (*(int*)((char*)entry + 0x14) != 0) {
        int field = func_02040528(&entry->flags);
        struct Struct_0204027c_2* c = (struct Struct_0204027c_2*)func_0203d004(list);
        char buf[0x10];
#if defined(jpn)
        sprintf(buf, data_ov001_021657d4, field + 16);
#else
        sprintf(buf, data_ov001_021657d4, field + 4);
#endif
        int idx = func_02040404(c, buf);
        func_0204039c((struct Struct_0204039c*)c, idx);
    } else {
        if (entry->unknown_18_ != 0) {
            ((Object3D*)((unsigned char*)entry->unknown_18_))->Destroy();
            func_0204128c((struct Struct_0203d028_10*)entry->unknown_18_);
        }
    }
    func_02040504(&entry->flags);
    func_0203dd10((Struct_0203dd10*)list, id, 0);

    if (data_ov001_02165880.table != NULL) {
        for (int i = 0; i < 0x20; i++) {
            if (data_ov001_02165880.table[i].a == 2 || data_ov001_02165880.table[i].a == 6) {
                if (data_ov001_02165880.table[i].b == id) {
                    func_ov001_0215acb4(&data_ov001_02165880.table[i]);
                }
            }
        }
    }
    return 1;
}
