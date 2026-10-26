#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov000_0216fd38;
struct Struct_ov000_0216fdf8;
struct Struct_ov000_0216fd80;
struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Struct_ov000_0215feb4;
struct Struct_ov000_02160094;
struct Struct_ov000_0215feb4;
struct Struct_ov000_021600f8 {
    Struct_ov000_0215feb4* unknown_0_[3];
    short unknown_c_;
    short ids[3];
    unsigned char codes[3];
    unsigned char unknown_17_;
    unsigned char unknown_18_[3];
    unsigned char unknown_1b_[5];
    Struct_ov000_021600f8* next;
};
struct Struct_ov025_021e9fc4;
extern "C" void* func_ov000_02160130();
extern "C" void* func_ov000_02160f20(void*);
extern "C" int func_ov000_0216fd38(Struct_ov000_0216fd38*);
extern "C" void func_ov000_0216fdf8(Struct_ov000_0216fdf8*, int);
extern "C" void func_ov000_0216fd80(Struct_ov000_0216fd80*, int);
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" Struct_ov000_0215feb4* func_ov000_0215feb4(char*, int, int);
extern "C" void* func_ov000_0215fe2c(void*, int);
extern "C" void* func_ov000_0215fff4(void*, int, int);
extern "C" void func_ov025_021ed324(void*, const char*);
extern "C" char* func_020e046c(char*, void*, void*, int);
extern "C" void func_ov025_021ed634(Struct_ov025_021e9fc4*);

static inline unsigned char* inline_ov025_021e9fc4(Struct_ov000_021600f8* node) { return node->codes; }

// USA: func_ov025_021e9fc4
// KEEP-NAME: func_ov025_021e9fc4
extern "C" ARM void func_ov025_021e9fc4(char* self) {
    if ((*(unsigned char*)(self + 0x87c)) == 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if ((*(int*)(self + 0x880)) >= 0) {
            if (loader->GetTaskStatus((*(int*)(self + 0x880))) != 0) {
                void* file = 0;
                unsigned int size = 0;
                loader->GetLoadedFileByID((*(int*)(self + 0x880)), &file, &size);
                if (file != 0) {
                    func_020e046c((self + 0x83c), file, (void*)size, (short)(*(int*)(self + 0x884)));
                }
                func_ov025_021ed324((self + 0x5e8), (self + 0x83c));
#if !defined(jpn)
                *(short*)(self + 0x794) = (*(int*)(self + 0x884));
#endif
                loader->RemoveTask((*(int*)(self + 0x880)));
                (*(int*)(self + 0x880)) = -1;
                (*(unsigned char*)(self + 0x87c)) = 1;
            }
        } else (*(unsigned char*)(self + 0x87c)) = 1;
    }
    if (*(unsigned char*)(self + 0x839) != 0) {
        if ((*(unsigned char*)(self + 0x87c)) != 0) func_ov025_021ed634((Struct_ov025_021e9fc4*)(self + 0x5e8));
    } else if (((int*)(self + 0x10))[(unsigned char)self[0x30]] != 0 &&
               func_ov000_0216fd38((Struct_ov000_0216fd38*)(self + 0x798)) != 0) {
        unsigned char* slot = (unsigned char*)func_ov000_02160f20(func_ov000_02160130());
        func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[0]);
        func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[1]);
        func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[2]);
        func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[3]);
        func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[4]);
        func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[5]);
        func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), ((short*)(slot + 0x18))[6]);
        func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), 0x7e);
        func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), 0x7f);
        if ((unsigned short)((short*)(slot + 0x18))[0] == 0xfa) func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), 0x1e0);
        for (int index = 0; index < slot[8]; index++) {
            Struct_ov000_02160094* node = func_ov000_02160094((Struct_ov000_0215440c_2*)slot, index);
            if (node == 0) continue;
            for (int group = 0; group < 6; group++) {
                for (int item = 0; item < *((unsigned char*)node + 0x26 + group); item++) {
                    Struct_ov000_0215feb4* link = func_ov000_0215feb4((char*)node, item, (unsigned char)group);
                    if (link == 0) continue;
                    for (int child = 0; child < *((unsigned char*)link + 0x1f); child++) {
                        short* value = (short*)func_ov000_0215fe2c(link, child);
                        if (value != 0) func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), *value);
                    }
                }
            }
        }
        for (int index = 0; index < slot[9]; index++) {
            Struct_ov000_021600f8* node = func_ov000_021600f8((Struct_ov000_0215440c*)slot, index);
            if (node == 0) continue;
            unsigned char* codes;
            for (int code = 1; code < node->unknown_17_; code++) {
                codes = inline_ov025_021e9fc4(node);
                int type = codes[code];
                if (type == 3) func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), 0x1b8);
                else if (type == 1) {
                    int value = 0xaa;
                    int id = node->ids[code - 1];
                    int var18 = 0;
                    if (id >= 0) var18 = id <= 3;
                    if (var18) value = 0xa9;
                    func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), (short)value);
                } else if (!(type != 8 && type != 7 && type != 6)) func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), 0x7e);
                else if (!(type != 4 && type != 5)) func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), 0x142);
                else if (type == 10) func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), 0x143);
                else if (type == 2) {
                    int value = 0x29;
                    int id = node->ids[code - 1];
                    int var21 = 0;
                    if (id >= 0) var21 = id <= 3;
                    if (var21) value = 0x28;
                    func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), (short)value);
                }
            }
            for (int group = 0; group < 3; group++) {
                for (int item = 0; item < node->unknown_18_[group]; item++) {
                    Struct_ov000_0215feb4* link = (Struct_ov000_0215feb4*)func_ov000_0215fff4(node, item, (unsigned char)group);
                    if (link == 0) continue;
                    for (int child = 0; child < *((unsigned char*)link + 0x1f); child++) {
                        short* value = (short*)func_ov000_0215fe2c(link, child);
                        if (value != 0) func_ov000_0216fdf8((Struct_ov000_0216fdf8*)(self + 0x798), *value);
                    }
                }
            }
        }
        func_ov000_0216fd80((Struct_ov000_0216fd80*)(self + 0x798), ((int*)(self + 0x10))[(unsigned char)self[0x30]]);
    }
}
