#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02169b04;

struct Struct_ov000_0215440c {
    char pad0[9];
    unsigned char count;
};

struct Struct_ov000_021600f8 {
    char pad0[0x18];
    unsigned char unknown_18_;
};

struct Struct_ov025_021e9b2c {
    char pad0[8];
    void* entry;
};

struct Struct_ov025_021e9778_3 {
    struct Struct_ov000_02169b04* keys;
    char pad4[0x1c4 - 0x4];
    unsigned int flags;
    char unknown_1c8_[0x53c - 0x1c8];
    unsigned char active;
    char unknown_53d_[0x5c8 - 0x53d];
    unsigned short targetIndex;
};

extern unsigned int data_ov025_021ef9a4;

extern "C" void* func_ov000_02160130(void);
extern "C" Struct_ov000_0215440c* func_ov000_02160f20(void* work);
extern "C" void func_ov025_021df9b0(void* fields);
struct Struct_ov000_02163a7c;
extern "C" void func_ov000_02163a7c(Struct_ov000_02163a7c*);
extern "C" void* func_ov000_02169b04(struct Struct_ov000_02169b04* list, int key);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" Struct_ov025_021e9b2c* func_ov000_0215fff4(void* node, int index, int depth);
extern "C" short func_ov000_0215ffa0(void* node);
extern "C" void func_ov025_021eb6fc(Struct_ov025_021e9778_3* self, int arg);
extern "C" void func_ov025_021ea474(Struct_ov025_021e9778_3* self);
extern "C" void func_ov025_021eb7fc(Struct_ov025_021e9778_3* self);
extern "C" void func_ov025_021e9d14(Struct_ov025_021e9778_3* self);
extern "C" void func_ov025_021ea958(Struct_ov025_021e9778_3* self, bool isParty, int a, int b);

// USA: func_ov025_021e9b2c
extern "C" ARM void func_ov025_021e9b2c(Struct_ov025_021e9778_3* self) {
#if defined(jpn)
 enum { regionalOffset = 0x5ca0 };
#else
 enum { regionalOffset = 0x5ab0 };
#endif
    GameState::GetInstance();
    void* work = func_ov000_02160130();
    Struct_ov000_0215440c* slot = func_ov000_02160f20(work);
    if (data_ov025_021ef9a4 & 8) {
        func_ov025_021eb6fc(self, 0);
        func_ov025_021ea474(self);
        func_ov025_021eb7fc(self);
        func_ov025_021df9b0((char*)work + regionalOffset);
        func_ov000_02163a7c((Struct_ov000_02163a7c*)work);
    }
    if (self->flags & 0x10) {
        self->flags &= ~0x10;
        if (!(data_ov025_021ef9a4 & 0x20)) {
            data_ov025_021ef9a4 |= 0x20;
            if (!((self->keys != NULL && func_ov000_02169b04(self->keys, 0x69) != NULL) ||
                  func_ov000_02169b04(self->keys, 0x89) != NULL)) {
                func_ov025_021e9d14(self);
            }
            int var2 = 1;
            for (int i = 0; i < slot->count; i++) {
                Struct_ov000_021600f8* node = func_ov000_021600f8(slot, i);
                if (node == NULL) {
                    continue;
                }
                for (int j = 0; j < node->unknown_18_; j++) {
                    Struct_ov025_021e9b2c* d = func_ov000_0215fff4(node, j, 0);
                    if (d != NULL && d->entry != NULL) {
                        var2 = 0;
                        break;
                    }
                }
            }
            if (var2) {
                bool isParty = true;
                Struct_ov000_021600f8* first = func_ov000_021600f8(slot, 0);
                if (first != NULL) {
                    int index = func_ov000_0215ffa0(first);
                    isParty = (index >= 0 && index <= 3) ? 1 : 0;
                }
                func_ov025_021ea958(self, isParty, 1, -1);
            } else {
                self->active = 0;
            }
        }
    }
    if (self->targetIndex >= 0xff) {
        return;
    }
    if (self->active == 0) {
        return;
    }
    func_ov025_021ea958(self, (self->targetIndex <= 3) ? 1 : 0, 1, -1);
}
