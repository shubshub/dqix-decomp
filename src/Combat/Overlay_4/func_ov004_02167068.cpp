#include <globaldefs.h>
#include "Resource/QuestScript.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Combat/ScriptElementList.h"

struct StreamHeader;
struct Struct_02095e90;
struct Struct_02095ee0;
struct Struct_0208becc { unsigned char field_0[0x100]; };
struct Struct_ov004_02167068 { unsigned char field_0[0x34]; Struct_0208becc object; };
struct Struct_ov004_02167068_2 {
    unsigned int field_0;
    unsigned int unknown_4_;
    unsigned int field_8;
    Struct_0208d550 stream;
    SafeAllocator allocator;
    SafeAllocator unknown_30_;
    int task;
    short unknown_48_;
    short count1;
    short unknown_4c_;
    short script;
    unsigned char step : 6;
    unsigned char unknown_50_6_ : 1;
    unsigned char unknown_50_7_ : 1;
};
extern void* data_ov004_0217101c[2];
#if defined(jpn)
enum { Enum_ov004_02167068_0 = 1 };
extern char data_ov004_02170e60[];
extern char data_ov004_02170e7d[];
#else
enum { Enum_ov004_02167068_0 = 0 };
extern char data_ov004_021705a5[];
extern char data_ov004_021705c0[];
extern char data_ov004_021705d2[];
#endif
extern "C" int* func_02094d6c();
extern "C" int func_020957f4(void*, StreamHeader*, int);
extern "C" int func_02095e90(Struct_02095e90*, SafeAllocator*);
extern "C" int func_02095ee0(Struct_02095ee0*);
extern "C" void func_ov004_02166198();
extern "C" void func_ov011_021848a0(void*, int);
extern "C" int func_ov004_02166b40(void*);
extern "C" short func_ov004_021666bc(void*, char*);
extern "C" void* func_ov004_02165e70(void*, int);
extern "C" void func_0208becc(Struct_0208becc*, int, unsigned char);

// USA: func_ov004_02167068
extern "C" ARM int func_ov004_02167068(void* self) {
    Struct_ov004_02167068_2* state = (Struct_ov004_02167068_2*)data_ov004_0217101c[Enum_ov004_02167068_0];
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* global = func_02094d6c();
    int result = 1;
    if (state->step == 0) {
#if defined(jpn)
        state->task = loader->QueueLoadFile(data_ov004_02170e60, 0);
#else
        state->task = loader->QueueLoadFileInGP2(data_ov004_021705a5, data_ov004_021705c0, 0);
#endif
        state->step = 1;
    } else if (state->step == 1) {
        if (loader->GetTaskStatus(state->task)) {
            void* buffer;
            unsigned int size;
            loader->GetLoadedFileByID(state->task, &buffer, &size);
            if (buffer) {
                state->script = func_020957f4(global, (StreamHeader*)buffer, size);
                func_0208d860(&state->stream, &state->allocator, buffer, size, NULL, 0, 1);
            }
            loader->RemoveTask(state->task);
            state->task = -1;
            state->step = 2;
        }
    } else if (state->step == 2) {
        func_02095e90((Struct_02095e90*)global, &state->allocator);
        state->step = 3;
    } else if (state->step == 3) {
        if (func_02095ee0((Struct_02095ee0*)global) != 1) return result;
#if defined(jpn)
        state->task = loader->QueueLoadFile(data_ov004_02170e7d, 0);
#else
        state->task = loader->QueueLoadFile(data_ov004_021705d2, 0);
#endif
        state->step = 4;
    } else if (state->step == 4) {
        if (loader->GetTaskStatus(state->task)) {
            void* buffer;
            unsigned int size;
            loader->GetLoadedFileByID(state->task, &buffer, &size);
            if (buffer) func_0209576c((Struct_020956b8*)global, &state->allocator, buffer, size, 0);
            loader->RemoveTask(state->task);
            state->task = -1;
            state->step = 5;
        }
    } else if (state->step == 5) {
        func_ov004_02166198();
        state->step = 6;
    } else {
        state->step = 0;
        result = 0;
        char flag = 0;
        if (state->unknown_48_ == 0 && state->count1 == 0) {
            func_ov011_021848a0(self, 0x65);
        } else if (state->count1 == 0) {
            func_ov004_02166b40(self);
            func_ov004_021666bc(self, &flag);
        } else {
            func_ov011_021848a0(self, 0x12c);
        }
        unsigned char value = flag;
        Struct_ov004_02167068* node = (Struct_ov004_02167068*)func_ov004_02165e70(self, 7);
        if (node) func_0208becc(&node->object, 0x270f, value);
    }
    return result;
}
