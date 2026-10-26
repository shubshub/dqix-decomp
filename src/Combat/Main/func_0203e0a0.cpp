#include <globaldefs.h>

#include "Combat/EntryGetterTypes.h"
#include "NitroSDK/Matrix.h"

extern "C" void *__clear(void *dst, int count);

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

// USA: func_0203e0a0
extern "C" ARM void func_0203e0a0(void *receiver, unsigned short id) {
    Struct_0203e0a0_3 *self = static_cast<Struct_0203e0a0_3 *>(receiver);
    self->id                   = id;
    self->unknown_1e0_          = 0;
    Struct_0203dce4 **slot       = self->entries;
    Struct_0203e0a0_2 *var2    = self->unknown_9e_;
    unsigned int index         = 0;
    for (; index < self->count; ++slot, ++var2, ++index) {
        Struct_0203dce4 *entry = *slot;
        if (entry != NULL) {
            Vector3i position;
            __clear(&position, sizeof(position));
            short value = 0;
            if (((unsigned char*)entry->child14) != NULL) {
                position = *(Vector3i *) (((unsigned char*)entry->child14) + 4);
                value    = (short) func_0203cdd0(((Struct_0203cdd0*)entry->child14));
            } else if (((unsigned char*)entry->unknown_18_) != NULL) {
                position = *(Vector3i *) (((unsigned char*)entry->unknown_18_) + 0x44);
                value    = (short) *(int *) (((unsigned char*)entry->unknown_18_) + 0x54);
            } else if (((unsigned char*)entry->child1c) != NULL) {
                position = *(Vector3i *) (((unsigned char*)entry->child1c) + 0x44);
                value    = (short) *(int *) (((unsigned char*)entry->child1c) + 0x54);
            }
            int x               = position.x;
            int z               = position.z;
            int y               = position.y;
            var2->x         = (short) (x >> 4);
            var2->y         = (short) (y >> 4);
            var2->z         = (short) (z >> 4);
            var2->value     = value;
            unsigned short *key = (unsigned short *) func_02040528(&entry->flags);
            if (key != NULL) {
                var2->key = *key;
            }
            var2->disabled     = (entry->flags & 0x8000) != 0;
            var2->unknown_9_2_    = 0;
            Struct_0203e0a0_5 *info = (Struct_0203e0a0_5 *) func_02040538((Struct_0203e0a0 *) entry);
            if (info != NULL) {
                Struct_0203e0a0_4 *node = info->first;
                while (node != NULL) {
                    if (node->status != 0) {
                        break;
                    }
                    ++var2->unknown_9_2_;
                    node = node->next;
                    if (node == info->first) {
                        break;
                    }
                }
            }
            var2->mode = info->mode == 3;
            if (entry->flags & 0x40000) {
                self->unknown_1e4_ |= 1U << index;
            }
            ++self->unknown_1e0_;
        }
    }
}
