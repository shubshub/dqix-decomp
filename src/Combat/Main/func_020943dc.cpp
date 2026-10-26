#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

#if defined(jpn)
struct Struct_02046574 { char text[0x40]; };
struct Obj02046574 {
    char pad0[0x37c];
    Struct_02046574 names[16];
};
struct Struct_020943dc {
    char name[0xc];
    short messageId;
    char unknown_e_[0x100 - 0xe];
    int taskId;
    int position;
    char text[0x30];
    unsigned char phase : 7;
    unsigned char reserved : 1;
    char unknown_139_;
    unsigned char counter;
    char unknown_13b_[2];
    unsigned char flags;
};
extern "C" Obj02046574* MessageSystem_GetInstance();
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020e046c(char*, void*, unsigned int, int);
extern "C" void func_020474a8(Obj02046574*, int, char*, char*);
extern const char data_020f146e[];

extern "C" ARM int func_020943dc(Struct_020943dc* state) {
    if (!(state->flags & 1)) return 0;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (state->phase == 0) {
        if (state->taskId >= 0) {
            loader->RemoveTask(state->taskId);
            state->taskId = -1;
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
            loader->RemoveTask(state->taskId);
            state->taskId = -1;
            state->flags &= ~1;
            state->phase = 0;
            state->counter = 0;
        }
    }
    return 1;
}
#else
struct Struct_02046574 { char text[0x40]; };
struct Obj02046574 {
    char pad0[0x4ac];
    Struct_02046574 names[16];
};
struct Struct_020943dc {
    char name[0x30];
    short messageId;
    char unknown_32_[0x340 - 0x32];
    int taskId;
    int position;
    char text[0x80];
    unsigned char phase : 7;
    unsigned char reserved : 1;
    char unknown_3c9_;
    unsigned char counter;
    char unknown_3cb_[2];
    unsigned char flags;
};
extern "C" Obj02046574* MessageSystem_GetInstance();
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020e046c(char*, void*, unsigned int, int);
extern "C" void MessageSystem_FormatText(Obj02046574*, int, char*, char*, int, int, int);
extern const char data_020f13aa[];
extern const char data_020f13c5[];

// USA: func_020943dc
extern "C" ARM int func_020943dc(Struct_020943dc* state) {
    if (!(state->flags & 1)) return 0;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (state->phase == 0) {
        if (state->taskId >= 0) {
            loader->RemoveTask(state->taskId);
            state->taskId = -1;
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
            loader->RemoveTask(state->taskId);
            state->taskId = -1;
            state->flags &= ~1;
            state->phase = 0;
            state->counter = 0;
        }
    }
    return 1;
}
#endif
