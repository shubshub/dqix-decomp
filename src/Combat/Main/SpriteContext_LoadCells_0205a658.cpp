#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct Struct_0205a658 { unsigned short y, x, attributes; };
struct Struct0205a198 {
    unsigned short count, flags;
    Struct_0205a658* cells;
    Struct_0205a658* copy;
    char unknown_c_[0x12];
    unsigned short index;
    char unknown_20_[2];
    unsigned char firstCell;
    char unknown_23_[5];
};
struct Struct_0205a658_2 {
    unsigned short count, unknown_2_;
    int unknown_4_, unknown_8_;
};
struct CellScript0205a658 {
    char unknown_0_[0x38];
    int unknown_38_;
    int unknown_3c_;
    Struct0205a198* records;
    int unknown_44_;
    unsigned int capacity;
    unsigned short recordCount, unknown_4e_;
};
extern "C" int func_020b00a4(void*, void**);
extern "C" void* func_020b00e0(Struct_0205a658_2*, unsigned int);
extern "C" void Sprite_Init(Struct0205a198*);

// Main, originally func_0205a658 (USA 0x0205a658, EUR 0x0205a668, JPN 0x0205b9f4)
extern "C" ARM int SpriteContext_LoadCells(CellScript0205a658* self, void* data, unsigned int length, SafeAllocator* allocator) {
    void* buffer = data;
    Struct_0205a658_2* header;
    if (!buffer) buffer = 0;
    else if (!length) buffer = 0;
    else {
        memcpy(buffer, data, length);
        if (!func_020b00a4(buffer, (void**)&header)) buffer = 0;
    }
    if (!buffer) return 1;
    if (allocator && !self->records) {
        self->recordCount = header->count;
        self->records = (Struct0205a198*)allocator->Allocate(self->recordCount * sizeof(Struct0205a198));
        for (unsigned short i = 0; i < self->recordCount; ++i) Sprite_Init(&self->records[i]);
    }
    Struct0205a198* records;
    unsigned short recordCount = self->recordCount;
    unsigned short count;
    records = self->records;
    if (records && recordCount && allocator) {
        Struct0205a198* record;
        Struct0205a198* entry;
        unsigned short i;
        count = header->count;
        unsigned short total = 0;
        for (i = 0; i < count; ++i) {
            if (recordCount <= i) break;
            entry = (Struct0205a198*)func_020b00e0(header, i);
            if (!entry) break;
            unsigned short cellCount = entry->count;
            record = &records[i];
            record->index = i;
            record->firstCell = total;
            record->count = entry->count;
            record->flags = entry->flags;
            record->cells = entry->cells;
            Struct_0205a658* allocated = (Struct_0205a658*)allocator->Allocate(cellCount * sizeof(Struct_0205a658));
            record->copy = allocated;
            record->cells = allocated;
            for (unsigned short j = 0; j < entry->count; ++j) {
                Struct_0205a658* from = &entry->cells[j];
                Struct_0205a658* to = &record->copy[j];
                to->y = from->y;
                to->x = from->x;
                to->attributes = from->attributes;
            }
            total += entry->count;
        }
    }
    self->unknown_4e_ = header->count;
    self->unknown_38_ = header->unknown_8_;
    int mode;
    Struct0205a198* last = (Struct0205a198*)func_020b00e0(header, (unsigned short)(header->count - 1));
    if (!last) return 1;
    struct { int unknown_0_; Struct_0205a658* cell; } var17;
    var17.unknown_0_ = self->unknown_38_;
    var17.cell = &last->cells[last->count - 1];
    mode = var17.unknown_0_;
    Struct_0205a658* cell = var17.cell;
    unsigned int attributes = cell->attributes;
    int x = cell->x;
    int y = cell->y;
    unsigned int minimum = mode + 5;
    unsigned int tiles = (attributes & 0x3ff) << minimum;
    unsigned int size = (x & 0xc000) >> 14;
    unsigned int shape = (y & 0xc000) >> 14;
    unsigned int shift = 5;
    switch (shape) {
    case 0:
        switch (size) {
        case 0: shift = 5; break;
        case 1: shift = 7; break;
        case 2: shift = 9; break;
        case 3: shift = 11; break;
        }
        break;
    case 1:
        switch (size) {
        case 0: shift = 6; break;
        case 1: shift = 7; break;
        case 2: shift = 8; break;
        case 3: shift = 10; break;
        }
        break;
    case 2:
        switch (size) {
        case 0: shift = 6; break;
        case 1: shift = 7; break;
        case 2: shift = 8; break;
        case 3: shift = 10; break;
        }
        break;
    }
    if (minimum < shift) minimum = shift;
    self->capacity = tiles + (1 << minimum);
    return 0;
}
