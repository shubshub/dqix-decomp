#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Combat/ScriptElementList.h"
#include "Resource/CharacterCreationUI.h"
#include "std_library_functions.h"


struct Struct_0208b9a0;
struct StreamHeader;
struct PacRecord;
struct Struct_0208bf78_5;
struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct Struct_0205faf4_7;
struct HeadNode02046b24;
struct BackgroundGraphics;

struct Struct_0208bf78_6 {
    unsigned int year : 7;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 6;
};

struct Struct_02065990_3 {
    unsigned char unknown_0_[0x178];
    Struct_0208bf78_6 unknown_178_[204];
    unsigned char unknown_4a8_[0x20];
};

struct Struct_0208bf78_7 {
    unsigned int unknown_0_0_ : 16;
    unsigned int unknown_2_0_ : 1;
    unsigned int unknown_2_1_ : 15;
    unsigned short unknown_4_[2];
    unsigned short unknown_8_;
    unsigned short stats[3];
};

struct StoreStruct {
    unsigned char unknown_0_[0x60];
    char* buffer;
};

struct Struct_0208bf78 {
    unsigned char unknown_0_[0x1c];
    short width;
    short height;
    unsigned char unknown_20_[8];
    short unknown_28_;
    short unknown_2a_;
    unsigned char unknown_2c_[0x28];
};

struct TextWindow0208bf78 {
    unsigned char unknown_0_[8];
    char* text;
    unsigned char unknown_c_[0x80];
    Struct_0208bf78 layout;
};

struct Struct_0208bf78_3 {
    unsigned char unknown_0_[0x1c];
    unsigned char mode : 4;
    unsigned char layer : 4;
    unsigned char unknown_1d_[3];
};

struct Struct_02000c9c_25 {
    unsigned char unknown_0_[0x28];
    SafeAllocator scriptAllocator;
    SafeAllocator* inline_0208bf78() { return &scriptAllocator; }
};

struct Struct_0208bf78_4 {
    Struct_02000c9c_25* arena;
    Container020e0310 strings;
    unsigned char unknown_c_[0x10];
    Struct_0208d550 elements;
    unsigned char unknown_2c_[0x90];
    int taskId;
    unsigned char unknown_c0_[0x12];
    short target;
    unsigned char unknown_d4_;
    unsigned char state;
    unsigned char unknown_d6_;
    unsigned char unknown_d7_[3];
    unsigned short flags;
    unsigned char unknown_dc_;
    unsigned char unknown_dd_;
    unsigned char unknown_de_;
    unsigned char unknown_df_;
};

extern "C" void func_0208d854(Struct_0208b9a0*);
extern "C" Struct_02065990_3* func_02094d6c();
extern "C" unsigned char func_020965ac(Struct_02065990_3*, unsigned char);
extern "C" int func_02095870(void*, StreamHeader*, int, int, unsigned char*);
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" int func_0208d9e8(Struct_0208bf78_5*, int);
extern "C" int func_02096088(void*, int);
extern "C" int func_02096100(int, unsigned char*, int);
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" int func_0206e120(PackedNibbleArray0206e120*, int);
extern "C" unsigned char func_0209618c(Struct_0205faf4_7*, int);
extern "C" int func_0208da18(Struct_0208bf78_5*, int, int);
extern "C" int func_0208dac4(Struct_0208bf78_5*, int);
extern "C" int func_0208da00(Struct_0208bf78_5*, int);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" int func_0208dadc(Struct_0208bf78_5*, int);
extern "C" int func_0206e260(PackedNibbleArray0206e260*, int);
extern "C" StoreStruct* MessageSystem_GetInstance();
extern "C" Struct_0208bf78_7* func_02096134(Struct_0205faf4_7*, int);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void func_0208c9cc(int, int, int, int, int);
extern "C" void Background_FlushFile(void*, char*);
extern "C" void Background_UploadFile(BackgroundGraphics*, char*);
extern "C" void WindowPane_Init(TextWindow0208bf78*);
extern "C" PackedNibbleArray0206e120* Scenario_GetInstance();
extern "C" void func_0204f41c(TextWindow0208bf78*, short, short, const char*, int, unsigned char, short*, short*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void MessageSystem_FormatText(StoreStruct*, int, const char*, char*, int, int, int);
extern "C" int Font_GetTextWidth(char*, int);
extern "C" void func_0208d42c(void*, TextWindow0208bf78*, short, short, int, unsigned char, unsigned char, unsigned char, unsigned char);
extern "C" void Background_SetPriority(void*, int);

extern char data_020f1120[], data_020f113b[], data_020f114d[], data_020f116b[], data_020f117f[];
extern char data_020f1192[], data_020f1197[];

static inline unsigned char inline_0208bf78_2(Struct_02065990_3* table, int target) {
    return func_020965ac(table, target);
}

static inline Struct_0208bf78_6 inline_0208bf78_3(Struct_02065990_3* table, unsigned char id) {
    return table->unknown_178_[id];
}

static inline bool inline_0208bf78_4(unsigned char id, int status) {
    return func_0206e120(Scenario_GetInstance(), id) == status;
}

static inline bool inline_0208bf78_5(PackedNibbleArray0206e120* table, unsigned char id, int status) {
    return func_0206e120(table, id) == status;
}

// USA: func_0208bf78
extern "C" ARM void func_0208bf78(Struct_0208bf78_4* view) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (view->unknown_d6_ == 0) {
        func_0208d854((Struct_0208b9a0*)&view->elements);
        view->taskId = loader->QueueLoadFileInGP2(data_020f1120, data_020f113b, 0);
        view->unknown_d6_++;
    } else if (view->unknown_d6_ == 1) {
        if (!loader->GetTaskStatus(view->taskId)) return;
        SafeAllocator* allocator = view->arena->inline_0208bf78();
        allocator->Reset();
        void* file = 0;
        unsigned int length = 0;
        loader->GetLoadedFileByID(view->taskId, &file, &length);
        if (allocator && file && length) {
            func_0208d860(&view->elements, allocator, file, length, &view->target, 1, 0xfff);
        }
        loader->RemoveTask(view->taskId);
        view->taskId = -1;
        view->unknown_d6_++;
        if (!view->unknown_dc_) view->unknown_d6_ = 4;
    } else if (view->unknown_d6_ == 2) {
        view->taskId = loader->QueueLoadFile(data_020f114d, 0);
        view->unknown_d6_++;
    } else if (view->unknown_d6_ == 3) {
        if (!loader->GetTaskStatus(view->taskId)) return;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(view->taskId, &file, &length);
        if (file) {
            Struct_02065990_3* table = func_02094d6c();
            unsigned char var7 = 0;
            func_02095870(table, (StreamHeader*)file, length, inline_0208bf78_2(table, view->target), &var7);
            view->unknown_dd_ = var7;
        }
        loader->RemoveTask(view->taskId);
        view->taskId = -1;
        view->unknown_d6_++;
    } else if (view->unknown_d6_ == 4) {
        if (view->target == 9999) {
            view->taskId = loader->QueueLoadFile(data_020f116b, 0);
        } else {
            view->taskId = loader->QueueLoadFile(data_020f117f, 0);
        }
        view->unknown_d6_++;
    } else if (view->unknown_d6_ == 5) {
        if (!loader->GetTaskStatus(view->taskId)) return;
        void* records[4] = {0};
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(view->taskId, &file, &length);
        int count = Pac_CountFiles((PacRecord*)file);
        int sizes[4];
        for (int i = 0; i < count; i++) {
            records[i] = Pac_GetFile((PacRecord*)file, i, &record, &sizes[i]);
        }
        TextWindow0208bf78 window;
        short width;
        short height;
        char* data = (char*)records[0];
        WindowPane_Init(&window);
        window.text = data + 0x10;
        window.layout.width = 0x20;
        window.layout.height = 0x18;
        window.layout.unknown_28_ = 0xc;
        window.layout.unknown_2a_ = 0x10;
        view->flags &= ~8;
        if (view->target != 9999) {
            Scenario_GetInstance();
            Struct_02065990_3* table = func_02094d6c();
            short target = view->target;
            char number[8] = {0};
            sprintf(number, data_020f1192, target);
            func_0204f41c(&window, 0x18, 0x14, number, 0xc, 0xf, &width, &height, 0);
            int text = func_0208d9e8((Struct_0208bf78_5*)&view->elements, target);
            bool unknown = 0;
            if (view->unknown_dd_ && !func_02096088(table, inline_0208bf78_2(table, target))) {
                if (!func_02096100((int)table, table->unknown_4a8_, inline_0208bf78_2(table, target))) unknown = 1;
            }
            if (unknown) text = KeyTable_Get(&view->strings, 3);
            int kind = 0;
            func_0204f41c(&window, 0x30, 0x14, (const char*)text, 0xc, 0xf, &width, &height, kind);
            if (inline_0208bf78_4(inline_0208bf78_2(table, target), 2)) {
                text = func_0208da18((Struct_0208bf78_5*)&view->elements, target,
                                                      func_0209618c((Struct_0205faf4_7*)table, inline_0208bf78_2(table, target)));
                kind = 1;
                if (func_02096088(table, inline_0208bf78_2(table, target))) view->flags |= 8;
            } else if (inline_0208bf78_4(inline_0208bf78_2(table, target), 3)) {
                view->flags |= 8;
                text = func_0208dac4((Struct_0208bf78_5*)&view->elements, target);
                kind = 2;
            } else if (view->unknown_df_ && func_02096088(table, inline_0208bf78_2(table, target))) {
                view->flags |= 8;
                text = func_0208dac4((Struct_0208bf78_5*)&view->elements, target);
                kind = 2;
            } else {
                unsigned char id = inline_0208bf78_2(table, target);
                PackedNibbleArray0206e120* status = Scenario_GetInstance();
                bool seen = inline_0208bf78_5(status, id, 0) || inline_0208bf78_5(status, id, 1);
                if (seen) {
                    text = func_0208da00((Struct_0208bf78_5*)&view->elements, target);
                    if (view->flags & 0x40) kind = 1;
                    if (view->unknown_dd_) {
                        if (inline_0208bf78_4(inline_0208bf78_2(table, target), 0)) {
                            text = KeyTable_Get(&view->strings, 4);
                        } else if (inline_0208bf78_4(inline_0208bf78_2(table, target), 1)) {
                            GameResources* resources = GameState::GetInstance()->GetResources();
                            if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) == 0x2d) {
                                text = func_0208dadc((Struct_0208bf78_5*)&view->elements, target);
                            }
                        }
                    }
                } else {
                    PackedNibbleArray0206e260* flags = (PackedNibbleArray0206e260*)Scenario_GetInstance();
                    if (func_0206e260(flags, inline_0208bf78_2(table, target))) {
                        text = func_0208da00((Struct_0208bf78_5*)&view->elements, target);
                    }
                }
            }
            StoreStruct* formatter = MessageSystem_GetInstance();
            char* buffer = formatter->buffer;
            memset(buffer, 0, 0x960);
            Struct_0208bf78_7* entry = func_02096134((Struct_0205faf4_7*)table, inline_0208bf78_2(table, target));
            if (entry) {
                func_02046380(formatter);
                if (entry->unknown_2_0_) {
                    for (int i = 0; i < 3; i++) {
                        int value = entry->stats[i];
                        if (value > 99) value = 99;
                        func_020465c0(formatter, i, value);
                    }
                }
                for (int i = 0; i < 2; i++) {
                    int value = entry->unknown_4_[i];
                    if (value > 99) value = 99;
                    func_020465c0(formatter, i + 3, value);
                }
            }
            MessageSystem_FormatText(formatter, 0xc, (const char*)text, buffer, 0xe0, 0, 1);
            func_0204f41c(&window, 0x10, 0x28, buffer, 0xc, 0xf, &width, &height, 0);
            window.layout.unknown_28_ = 0xa;
            window.layout.unknown_2a_ = 0x10;
            func_0204f41c(&window, 0, 0, (const char*)KeyTable_Get(&view->strings, kind), 0xa, 0xe, &width, &height, 0);
            window.layout.unknown_28_ = 8;
            window.layout.unknown_2a_ = 0x10;
            if (kind) {
                Struct_0208bf78_6 date = inline_0208bf78_3(table, inline_0208bf78_2(table, target));
                char text2[0x100] = {0};
                sprintf(text2, data_020f1197, date.day, KeyTable_Get(&view->strings, (short)(date.month + 4)), date.year + 2000);
                func_0204f41c(&window, 0xc6 - Font_GetTextWidth(text2, 0), 0xa8, text2, 8, 0xf, &width, &height, 0);
                func_0208d42c(view, &window, 0xd7, 0xa8, date.unknown_2_0_, 0xf, 2, 1, 1);
                func_0208d42c(view, &window, 0xda, 0xa8, date.unknown_2_5_, 0xf, 2, 0, 1);
            }
        }
        Struct_0208bf78_3 list;
        Background_Init((BackgroundGraphics*)&list);
        Background_SetMapSize((unsigned char*)&list, 0);
        list.mode = 1;
        list.layer = 0;
        Background_SetPriority(&list, 0);
        Background_SetScroll((BackgroundGraphics*)&list, 0, 0);
        func_0208c9cc(0, 0, 15, 0, 0);
        for (int i = 0; i < count; i++) {
            Background_FlushFile(&list, (char*)records[i]);
            Background_UploadFile((BackgroundGraphics*)&list, (char*)records[i]);
        }
        loader->RemoveTask(view->taskId);
        view->taskId = -1;
        view->flags &= ~0x20;
        view->unknown_d6_ = 0;
    }
}
