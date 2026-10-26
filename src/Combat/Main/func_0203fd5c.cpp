#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int NNS_GfdAllocFrmPlttVram(unsigned int size, int a, int b);

extern unsigned short data_020e7a0c[];

struct Struct_0203fd5c {
    unsigned short a;
    unsigned short b;
    unsigned short width;
    unsigned short height;
    int size;
    char* data;
};

struct Struct_0203fd5c_2 {
    unsigned short a;
    unsigned short b;
    unsigned short itemCount;
    Struct_0203fd5c* items;
    unsigned int unknown_c_;
    char* data;
};

struct Struct_0203fd5c_3 {
    char* name;
    unsigned int count;
    void* listA;
    void* listB;
    void* unknown_10_;
};

struct Struct_0203fd5c_4 {
    int loaded;
    unsigned short type;
    unsigned short groupCount;
    Struct_0203fd5c_2* groups;
    int tableCount;
    unsigned short* table;
    unsigned int tableShift;
    unsigned int unknown_18_;
    Struct_0203fd5c_3* entries;
    unsigned int unknown_20_;
    unsigned int unknown_24_;
};

// USA: func_0203fd5c
extern "C" ARM void func_0203fd5c(Struct_0203fd5c_4* hdr, char* path, SafeAllocator* alloc, char* src) {
    char* end = path + strlen(path);
    if (end[-1] == 'r') {
        int off = 0;
        Struct_0203fd5c_2* group;
        Struct_0203fd5c* item;
        unsigned int j;
        int i;
        unsigned int k;
        unsigned int count;
        int tableCount;
        unsigned int pos;
        char name[0x1e];

        memcpy(&hdr->groupCount, src + off, 2);
        memcpy(&hdr->type, src + (off + 2), 2);
        off += 4;
        hdr->groups = (Struct_0203fd5c_2*)alloc->Allocate(hdr->groupCount * sizeof(Struct_0203fd5c_2));
        i = 0;
        hdr->unknown_20_ = 0;
        hdr->unknown_24_ = 0;
        group = hdr->groups;
        for (; i < hdr->groupCount; i++, group++) {
            memcpy(&group->a, src + off, 2);
            memcpy(&group->b, src + (off + 2), 2);
            memcpy(&count, src + (off + 4), 4);
            off += 8;
            group->itemCount = count;
            if (hdr->unknown_20_ < count)
                hdr->unknown_20_ = count;
            group->items = (Struct_0203fd5c*)alloc->Allocate(count * sizeof(Struct_0203fd5c));
            j = 0;
            group->unknown_c_ = 0;
            item = group->items;
            for (; j < count; j++, item++) {
                memcpy(&item->a, src + off, 2);
                memcpy(&item->b, src + (off + 2), 2);
                memcpy(&item->width, src + (off + 4), 2);
                memcpy(&item->height, src + (off + 6), 2);
                off += 8;
                int size = data_020e7a0c[item->width] * data_020e7a0c[item->height];
                if (hdr->type == 3)
                    item->size = size / 2;
                else
                    item->size = size;
                item->data = src + off;
                off += item->size;
                group->unknown_c_ += item->size;
            }
            if (hdr->unknown_24_ < group->unknown_c_)
                hdr->unknown_24_ = group->unknown_c_;
            group->data = (char*)alloc->Allocate(group->unknown_c_);
            j = 0;
            pos = 0;
            item = group->items;
            for (; j < count; j++, item++) {
                char* old = item->data;
                item->data = group->data + pos;
                memcpy(item->data, old, item->size);
                pos += item->size;
            }
        }

        memcpy(&tableCount, src + off, 4);
        off += 4;
        hdr->tableCount = tableCount;
        if (hdr->tableCount <= 0x10)
            hdr->tableCount = 0x10;
        else if (hdr->tableCount <= 0x100)
            hdr->tableCount = 0x100;
        hdr->tableShift = (unsigned short)NNS_GfdAllocFrmPlttVram(hdr->tableCount * 2, 0, 0) << 3;
        hdr->table = (unsigned short*)alloc->Allocate(hdr->tableCount * 2);
        memcpy(hdr->table, src + off, hdr->tableCount * 2);
        off += tableCount * 2;
        memcpy(&hdr->unknown_18_, src + (off + 0x1e), 4);
        off += 0x22;
        hdr->entries = (Struct_0203fd5c_3*)alloc->Allocate(hdr->unknown_18_ * sizeof(Struct_0203fd5c_3));
        for (j = 0; j < hdr->unknown_18_; j++) {
            Struct_0203fd5c_3* entry = &hdr->entries[j];
            memcpy(name, src + off, 0x1e);
            off += 0x1e;
            int len = strlen(name) + 1;
            if (len % 4 != 0)
                len = (len / 4 + 1) * 4;
            char* str = (char*)alloc->Allocate(len);
            entry->name = str;
            strcpy(str, name);
        }
        for (k = 0; k < hdr->unknown_18_; k++) {
            Struct_0203fd5c_3* entry = &hdr->entries[k];
            memcpy(&entry->count, src + off, 4);
            unsigned int n = entry->count;
            unsigned int bytes = n * 4;
            off += 4;
            entry->listA = alloc->Allocate(bytes);
            entry->listB = alloc->Allocate(bytes);
            entry->unknown_10_ = alloc->Allocate(bytes);
            memcpy(entry->listA, src + off, bytes);
            off += n * 4;
            memcpy(entry->listB, src + off, bytes);
            off += n * 4;
            memcpy(entry->unknown_10_, src + off, bytes);
            off += n * 4;
        }
        hdr->loaded = 1;
    }
}
