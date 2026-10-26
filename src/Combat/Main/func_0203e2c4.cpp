#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0203e2c4_32376 = 0x7c38 };
#else
enum { Enum_0203e2c4_32376 = 0x7e78 };
#endif

#include "Combat/EntryGetterTypes.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_0203e0a0_2 {
    short x;
    short y;
    short z;
    short value;
    unsigned short key : 9;
    unsigned short disabled : 1;
    unsigned short unknown_9_2_ : 5;
    unsigned short mode : 1;
};

struct Struct_0203e0a0_3 {
    unsigned char unknown0[0xc];
    Struct_0203dce4 *entries[32];
    unsigned int count;
    unsigned char unknown_90_[0xe];
    Struct_0203e0a0_2 unknown_9e_[32];
    unsigned short id;
    unsigned short unknown_1e0_;
    unsigned short unknown_1e2_;
    unsigned int unknown_1e4_;
};

struct Struct_0203e0a0_4 {
    unsigned char unknown0[0xc];
    unsigned int status;
    Struct_0203e0a0_4 *next;
};

struct Struct_0203e0a0_5 {
    unsigned char unknown0[0xa];
    unsigned char unknown_a_0_ : 3;
    unsigned char mode : 3;
    unsigned char unknown_a_6_ : 2;
    unsigned char unknownB[0x29];
    Struct_0203e0a0_4 *first;
};

struct Struct_0203e2c4 {
    short x;
    short y;
    short z;
    unsigned char key;
};

struct Obj02033874;
struct Struct_0203e2c4_2;
struct Struct_0203d028_15;

extern "C" void *func_0203df78(void *receiver, int key);
extern "C" void GameObject_SnapFacing(struct Obj02033874 *obj, int value);
extern "C" void func_02040b2c(struct Struct_0203e2c4_2 *obj, int value);
extern "C" void func_02040774(struct Struct_0203d028_15 *node, int x, int y, int z);

// USA: func_0203e2c4
extern "C" ARM void func_0203e2c4(void *receiver, unsigned short id) {
    Struct_0203e0a0_3 *self = static_cast<Struct_0203e0a0_3 *>(receiver);
    if (self->id == id) {
        Struct_0203e0a0_2 *var1 = self->unknown_9e_;
        for (int index = 0; index < self->unknown_1e0_; ++var1, ++index) {
            Struct_0203dce4 **slot = self->entries;
            for (unsigned int slotIndex = 0; slotIndex < self->count; ++slot, ++slotIndex) {
                Struct_0203dce4 *entry = *slot;
                unsigned short *key = (unsigned short *) func_02040528(&entry->flags);
                void *info = func_02040538((Struct_0203e0a0 *) entry);
                if (key == NULL || info == NULL) {
                    continue;
                }
                if (*key != var1->key) {
                    continue;
                }
                Vector3i position;
                position.x = var1->x << 4;
                position.y = var1->y << 4;
                position.z = var1->z << 4;
                short value = var1->value;
                if (entry->child14 != NULL) {
                    *(Vector3i *) ((char*)entry->child14 + 4) = position;
                } else if (entry->unknown_18_ != NULL) {
                    *(Vector3i *) ((char*)entry->unknown_18_ + 0x44) = position;
                } else if (entry->child1c != NULL) {
                    *(Vector3i *) ((char*)entry->child1c + 0x44) = position;
                    GameObject_SnapFacing((struct Obj02033874 *) entry->child1c, value);
                }
                func_02040b2c((struct Struct_0203e2c4_2 *) entry, value);
                func_02040af0(entry, value);
                if (var1->disabled) {
                    entry->flags |= 0x8000;
                }
                Struct_0203e0a0_5 *nodes = (Struct_0203e0a0_5 *) func_02040538((Struct_0203e0a0 *) entry);
                if (nodes != NULL) {
                    Struct_0203e0a0_4 *node = nodes->first;
                    while (node != NULL) {
                        if (var1->unknown_9_2_ == 0) {
                            node->status = 1;
                        } else {
                            node->status = 0;
                        }
                        var1->unknown_9_2_--;
                        node = node->next;
                        if (node == nodes->first) {
                            break;
                        }
                    }
                }
                if (var1->mode) {
                    nodes->mode = 3;
                }
                if (self->unknown_1e4_ & (1U << slotIndex)) {
                    entry->flags |= 0x40000;
                }
                break;
            }
        }
    }
    self->id = 0;
    self->unknown_1e4_ = 0;
    GameState *gameState = GameState::GetInstance();
    Struct_0203e2c4 *pending = (Struct_0203e2c4 *) ((char *) gameState + Enum_0203e2c4_32376);
    if (pending->key != 0xff) {
        struct Struct_0203d028_15 *node = (struct Struct_0203d028_15 *) func_0203df78(self, pending->key);
        if (node != NULL) {
            func_02040774(node, pending->x << 4, pending->y << 4, pending->z << 4);
        }
        pending->key = 0xff;
    }
}
