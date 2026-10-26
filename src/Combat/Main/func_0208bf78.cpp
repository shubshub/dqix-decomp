#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Combat/ScriptElementList.h"
#include "Resource/CharacterCreationUI.h"
#include "std_library_functions.h"


struct StreamHeader0208d82c;
struct StreamHeader;
struct PacRecord;
struct List0208d994;
struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct FindEntryById02096134Table;
struct HeadNode02046b24;
struct BackgroundGraphics;

struct Struct_0208bf78_6 {
    unsigned int unknown_0_0_ : 7;
    unsigned int unknown_0_7_ : 4;
    unsigned int unknown_1_3_ : 5;
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
    unsigned short unknown_a_[3];
};

struct Struct_020465c0 {
    unsigned char unknown_0_[0x60];
    char* unknown_60_;
};

struct Struct_0208bf78 {
    unsigned char unknown_0_[0x1c];
    short unknown_1c_;
    short unknown_1e_;
    unsigned char unknown_20_[8];
    short unknown_28_;
    short unknown_2a_;
    unsigned char unknown_2c_[0x28];
};

struct Struct_0208bf78_2 {
    unsigned char unknown_0_[8];
    char* unknown_8_;
    unsigned char unknown_c_[0x80];
    Struct_0208bf78 unknown_8c_;
};

struct Struct_0208bf78_3 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_[3];
};

struct Struct_02000c9c_25 {
    unsigned char unknown_0_[0x28];
    SafeAllocator unknown_28_;
    SafeAllocator* inline_0208bf78() { return &unknown_28_; }
};

struct Struct_0208bf78_4 {
    Struct_02000c9c_25* unknown_0_;
    Struct_0201099c_3 unknown_4_;
    unsigned char unknown_c_[0x10];
    Struct_0208d550 unknown_1c_;
    unsigned char unknown_2c_[0x90];
    int unknown_bc_;
    unsigned char unknown_c0_[0x12];
    short unknown_d2_;
    unsigned char unknown_d4_;
    unsigned char unknown_d5_;
    unsigned char unknown_d6_;
    unsigned char unknown_d7_[3];
    unsigned short unknown_da_;
    unsigned char unknown_dc_;
    unsigned char unknown_dd_;
    unsigned char unknown_de_;
    unsigned char unknown_df_;
};

void ForwardInitStreamHeader0208d854(StreamHeader0208d82c*);
GetTableByteOrFFData* GetGlobal02109418_02094d6c();
unsigned char GetTableByteOrFF_020965ac(GetTableByteOrFFData*, unsigned char);
int RunBufferedScript02095870(void*, StreamHeader*, int, int, unsigned char*);
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
int GetElementField4ByKey0208d9e8(List0208d994*, int);
int TestBitInByteArrayAt0x84_02096088(void*, int);
int TestBitInByteArray02096100(int, unsigned char*, int);
int KeyTable_Get(Container020e0310*, int);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
unsigned char GetEntryField0209618c(FindEntryById02096134Table*, int);
int LookupArrayFieldByCase0208da18(List0208d994*, int, int);
int GetElementField0x10ByKey_0208dac4(List0208d994*, int);
int GetElementField8ByKey0208da00(List0208d994*, int);
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
int GetElementField0x14ByKey_0208dadc(List0208d994*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);
StoreStruct* MessageSystem_GetInstance();
StatEntry0208bf78* FindEntryById02096134(FindEntryById02096134Table*, int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
void Background_Init(BackgroundGraphics*);
void Background_SetMapSize(unsigned char*, int);
void Background_SetScroll(BackgroundGraphics*, int, int);
void SetSubBg0Control0208c9cc(int, int, int, int, int);
void Background_FlushFile(void*, char*);
void Background_UploadFile(BackgroundGraphics*, char*);
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

static inline unsigned char inline_0208bf78_2(Struct_02065990_3* arg0, int arg1) {
    return func_020965ac(arg0, arg1);
}

static inline Struct_0208bf78_6 inline_0208bf78_3(Struct_02065990_3* arg0, unsigned char arg1) {
    return arg0->unknown_178_[arg1];
}

static inline bool HasStatus0208bf78(unsigned char id, int status) {
    return GetPackedNibbleField(Scenario_GetInstance(), id) == status;
}

static inline bool inline_0208bf78_5(Struct_0205faf4_3* arg0, unsigned char arg1, int arg2) {
    return func_0206e120(arg0, arg1) == arg2;
}

// USA: func_0208bf78
extern "C" ARM void func_0208bf78(Struct_0208bf78_4* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_d6_ == 0) {
        func_0208d854((Struct_0208b9a0*)&arg0->unknown_1c_);
        arg0->unknown_bc_ = var0->QueueLoadFileInGP2(data_020f1120, data_020f113b, 0);
        arg0->unknown_d6_++;
    } else if (arg0->unknown_d6_ == 1) {
        if (!var0->GetTaskStatus(arg0->unknown_bc_)) return;
        SafeAllocator* var1 = arg0->unknown_0_->inline_0208bf78();
        var1->Reset();
        void* var2 = 0;
        unsigned int var3 = 0;
        var0->GetLoadedFileByID(arg0->unknown_bc_, &var2, &var3);
        if (var1 && var2 && var3) {
            func_0208d860(&arg0->unknown_1c_, var1, var2, var3, &arg0->unknown_d2_, 1, 0xfff);
        }
        var0->RemoveTask(arg0->unknown_bc_);
        arg0->unknown_bc_ = -1;
        arg0->unknown_d6_++;
        if (!arg0->unknown_dc_) arg0->unknown_d6_ = 4;
    } else if (arg0->unknown_d6_ == 2) {
        arg0->unknown_bc_ = var0->QueueLoadFile(data_020f114d, 0);
        arg0->unknown_d6_++;
    } else if (arg0->unknown_d6_ == 3) {
        if (!var0->GetTaskStatus(arg0->unknown_bc_)) return;
        void* var4;
        unsigned int var5;
        var0->GetLoadedFileByID(arg0->unknown_bc_, &var4, &var5);
        if (var4) {
            Struct_02065990_3* var6 = func_02094d6c();
            unsigned char var7 = 0;
            func_02095870(var6, (Struct_02013fb4*)var4, var5, inline_0208bf78_2(var6, arg0->unknown_d2_), &var7);
            arg0->unknown_dd_ = var7;
        }
        var0->RemoveTask(arg0->unknown_bc_);
        arg0->unknown_bc_ = -1;
        arg0->unknown_d6_++;
    } else if (arg0->unknown_d6_ == 4) {
        if (arg0->unknown_d2_ == 9999) {
            arg0->unknown_bc_ = var0->QueueLoadFile(data_020f116b, 0);
        } else {
            arg0->unknown_bc_ = var0->QueueLoadFile(data_020f117f, 0);
        }
        view->loadState++;
    } else if (view->loadState == 5) {
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
        window.layout.firstFont = 0xc;
        window.layout.lastFont = 0x10;
        view->flags &= ~8;
        if (view->target != 9999) {
            Scenario_GetInstance();
            GetTableByteOrFFData* table = GetGlobal02109418_02094d6c();
            short target = view->target;
            char number[8] = {0};
            sprintf(number, data_020f1192, target);
            func_0204f41c(&window, 0x18, 0x14, number, 0xc, 0xf, &width, &height, 0);
            int text = GetElementField4ByKey0208d9e8((List0208d994*)&view->elements, target);
            bool unknown = 0;
            if (view->revealed && !TestBitInByteArrayAt0x84_02096088(table, GetMonsterIndex0208bf78(table, target))) {
                if (!TestBitInByteArray02096100((int)table, table->defeated, GetMonsterIndex0208bf78(table, target))) unknown = 1;
            }
            if (unknown) text = KeyTable_Get(&view->strings, 3);
            int kind = 0;
            func_0204f41c(&window, 0x30, 0x14, (const char*)text, 0xc, 0xf, &width, &height, kind);
            if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 2)) {
                text = LookupArrayFieldByCase0208da18((List0208d994*)&view->elements, target,
                                                      GetEntryField0209618c((FindEntryById02096134Table*)table, GetMonsterIndex0208bf78(table, target)));
                kind = 1;
                if (TestBitInByteArrayAt0x84_02096088(table, GetMonsterIndex0208bf78(table, target))) view->flags |= 8;
            } else if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 3)) {
                view->flags |= 8;
                text = GetElementField0x10ByKey_0208dac4((List0208d994*)&view->elements, target);
                kind = 2;
            } else if (view->showDefeated && TestBitInByteArrayAt0x84_02096088(table, GetMonsterIndex0208bf78(table, target))) {
                view->flags |= 8;
                text = GetElementField0x10ByKey_0208dac4((List0208d994*)&view->elements, target);
                kind = 2;
            } else {
                unsigned char id = GetMonsterIndex0208bf78(table, target);
                PackedNibbleArray0206e120* status = Scenario_GetInstance();
                bool seen = IsStatus0208bf78(status, id, 0) || IsStatus0208bf78(status, id, 1);
                if (seen) {
                    text = GetElementField8ByKey0208da00((List0208d994*)&view->elements, target);
                    if (view->flags & 0x40) kind = 1;
                    if (view->revealed) {
                        if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 0)) {
                            text = KeyTable_Get(&view->strings, 4);
                        } else if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 1)) {
                            GameResources* resources = GameState::GetInstance()->GetResources();
                            if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) == 0x2d) {
                                text = GetElementField0x14ByKey_0208dadc((List0208d994*)&view->elements, target);
                            }
                        }
                    }
                } else {
                    PackedNibbleArray0206e260* flags = (PackedNibbleArray0206e260*)Scenario_GetInstance();
                    if (GetPackedNibbleFlag0x4(flags, GetMonsterIndex0208bf78(table, target))) {
                        text = GetElementField8ByKey0208da00((List0208d994*)&view->elements, target);
                    }
                }
            }
            StoreStruct* formatter = MessageSystem_GetInstance();
            char* buffer = formatter->buffer;
            memset(buffer, 0, 0x960);
            StatEntry0208bf78* entry = FindEntryById02096134((FindEntryById02096134Table*)table, GetMonsterIndex0208bf78(table, target));
            if (entry) {
                func_02046380(formatter);
                if (entry->hasResists) {
                    for (int i = 0; i < 3; i++) {
                        int value = entry->stats[i];
                        if (value > 99) value = 99;
                        StoreInArray0x8b0_020465c0(formatter, i, value);
                    }
                }
                for (int var35 = 0; var35 < 2; var35++) {
                    int var36 = var32->unknown_4_[var35];
                    if (var36 > 99) var36 = 99;
                    func_020465c0(var30, var35 + 3, var36);
                }
            }
            MessageSystem_FormatText(formatter, 0xc, (const char*)text, buffer, 0xe0, 0, 1);
            func_0204f41c(&window, 0x10, 0x28, buffer, 0xc, 0xf, &width, &height, 0);
            window.layout.firstFont = 0xa;
            window.layout.lastFont = 0x10;
            func_0204f41c(&window, 0, 0, (const char*)KeyTable_Get(&view->strings, kind), 0xa, 0xe, &width, &height, 0);
            window.layout.firstFont = 8;
            window.layout.lastFont = 0x10;
            if (kind) {
                SaveDate0208bf78 date = GetSaveDate0208bf78(table, GetMonsterIndex0208bf78(table, target));
                char text2[0x100] = {0};
                sprintf(text2, data_020f1197, date.day, KeyTable_Get(&view->strings, (short)(date.month + 4)), date.year + 2000);
                func_0204f41c(&window, 0xc6 - Font_GetTextWidth(text2, 0), 0xa8, text2, 8, 0xf, &width, &height, 0);
                func_0208d42c(view, &window, 0xd7, 0xa8, date.hour, 0xf, 2, 1, 1);
                func_0208d42c(view, &window, 0xda, 0xa8, date.minute, 0xf, 2, 0, 1);
            }
        }
        RecordList0208bf78 list;
        Background_Init((BackgroundGraphics*)&list);
        Background_SetMapSize((unsigned char*)&list, 0);
        list.mode = 1;
        list.layer = 0;
        Background_SetPriority(&list, 0);
        Background_SetScroll((BackgroundGraphics*)&list, 0, 0);
        SetSubBg0Control0208c9cc(0, 0, 15, 0, 0);
        for (int i = 0; i < count; i++) {
            Background_FlushFile(&list, (char*)records[i]);
            Background_UploadFile((BackgroundGraphics*)&list, (char*)records[i]);
        }
        var0->RemoveTask(arg0->unknown_bc_);
        arg0->unknown_bc_ = -1;
        arg0->unknown_da_ &= ~0x20;
        arg0->unknown_d6_ = 0;
    }
}
