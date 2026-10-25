#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

#if defined(jpn)
struct Struct_02046574 { char unknown_0_[0x40]; };
struct Struct_02046574_2 {
    char unknown_0_[0x37c];
    Struct_02046574 unknown_37c_[16];
};
struct Struct_020943dc {
    char unknown_0_[0xc];
    short unknown_c_;
    char unknown_e_[0x100 - 0xe];
    int unknown_100_;
    int unknown_104_;
    char unknown_108_[0x30];
    unsigned char unknown_138_0_ : 7;
    unsigned char unknown_138_7_ : 1;
    char unknown_139_;
    unsigned char unknown_13a_;
    char unknown_13b_[2];
    unsigned char unknown_13d_;
};
Obj02046574* MessageSystem_GetInstance();
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020e046c(char*, void*, unsigned int, int);
extern "C" void func_020474a8(Struct_02046574_2*, int, char*, char*);
extern const char data_020f146e[];

extern "C" ARM int func_020943dc(Struct_020943dc* arg0) {
    if (!(arg0->unknown_13d_ & 1)) return 0;
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_138_0_ == 0) {
        if (arg0->unknown_100_ >= 0) {
            var0->RemoveTask(arg0->unknown_100_);
            arg0->unknown_100_ = -1;
        }
        state->taskId = loader->QueueLoadFile(data_020f146e, 0);
        ++state->phase;
    } else if (state->phase == 1) {
        if (loader->GetTaskStatus(state->taskId)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(state->taskId, &file, &size);
            if (file) {
                char message[0x40] = {};
                func_020e046c(message, file, size, state->messageId);
                Obj02046574* formatter = MessageSystem_GetInstance();
                char* previousName = formatter->names[0].text;
                char savedName[0x40] = {};
                if (previousName) memcpy(savedName, previousName, strlen(previousName));
                MessageSystem_SetStringArgument(formatter, 0, state->name);
                memset(state->text, 0, sizeof(state->text));
                func_020474a8(formatter, 10, message, state->text);
                state->text[0x2f] = 0;
                state->position = 0;
                if (previousName) MessageSystem_SetStringArgument(formatter, 0, savedName);
            }
            var0->RemoveTask(arg0->unknown_100_);
            arg0->unknown_100_ = -1;
            arg0->unknown_13d_ &= ~1;
            arg0->unknown_138_0_ = 0;
            arg0->unknown_13a_ = 0;
        }
    }
    return 1;
}
#else
struct Struct_02046574 { char unknown_0_[0x40]; };
struct Struct_02046574_2 {
    char unknown_0_[0x4ac];
    Struct_02046574 unknown_4ac_[16];
};
struct Struct_020943dc {
    char unknown_0_[0x30];
    short unknown_30_;
    char unknown_32_[0x340 - 0x32];
    int unknown_340_;
    int unknown_344_;
    char unknown_348_[0x80];
    unsigned char unknown_3c8_0_ : 7;
    unsigned char unknown_3c8_7_ : 1;
    char unknown_3c9_;
    unsigned char unknown_3ca_;
    char unknown_3cb_[2];
    unsigned char unknown_3cd_;
};
Obj02046574* MessageSystem_GetInstance();
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020e046c(char*, void*, unsigned int, int);
extern "C" void MessageSystem_FormatText(Obj02046574*, int, char*, char*, int, int, int);
extern const char data_020f13aa[];
extern const char data_020f13c5[];

// USA: func_020943dc
extern "C" ARM int func_020943dc(Struct_020943dc* arg0) {
    if (!(arg0->unknown_3cd_ & 1)) return 0;
    BackgroundLoader* var7 = BackgroundLoader::GetInstance();
    if (arg0->unknown_3c8_0_ == 0) {
        if (arg0->unknown_340_ >= 0) {
            var7->RemoveTask(arg0->unknown_340_);
            arg0->unknown_340_ = -1;
        }
        state->taskId = loader->QueueLoadFileInGP2(data_020f13aa, data_020f13c5, 0);
        ++state->phase;
    } else if (state->phase == 1) {
        if (loader->GetTaskStatus(state->taskId)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(state->taskId, &file, &size);
            if (file) {
                char message[0x40] = {};
                func_020e046c(message, file, size, state->messageId);
                Obj02046574* formatter = MessageSystem_GetInstance();
                char* previousName = formatter->names[0].text;
                char savedName[0x40] = {};
                if (previousName) memcpy(savedName, previousName, strlen(previousName));
                MessageSystem_SetStringArgument(formatter, 0, state->name);
                memset(state->text, 0, sizeof(state->text));
                MessageSystem_FormatText(formatter, 10, message, state->text, 0x100, 0, 0);
                state->text[0x7f] = 0;
                state->position = 0;
                if (previousName) MessageSystem_SetStringArgument(formatter, 0, savedName);
            }
            var7->RemoveTask(arg0->unknown_340_);
            arg0->unknown_340_ = -1;
            arg0->unknown_3cd_ &= ~1;
            arg0->unknown_3c8_0_ = 0;
            arg0->unknown_3ca_ = 0;
        }
    }
    return 1;
}
#endif
