#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "Filesystem/BackgroundLoader.h"

struct SafeAllocator;
int KeyTable_EndLoad(Struct020dfc40*);
extern "C" void KeyTable_Load(void* p, void* a, void* b, unsigned int c);
extern "C" void func_020e0028(void* p, void* a, void* b, unsigned int c, short* e, int f);
extern "C" int func_020dfd40(void* self, void* a, void* b);

// USA: func_020dfd40
extern "C" ARM int func_020dfd40(void* arg0, void* arg1, void* arg2) {
    Struct_0201099c_14* var0 = (Struct_0201099c_14*)arg0;
    void* var1 = BackgroundLoader::GetInstance();

    switch (p->loadStep) {
    case KeyTableLoadStep_Queue:
        if (a == 0) {
            KeyTable_EndLoad(p);
            return 1;
        }
        if (b != 0) {
            p->loadTask = ((BackgroundLoader*)loader)->QueueLoadFileInGP2((const char*)a, (const char*)b, (SafeAllocator*)0);
        } else {
            p->loadTask = ((BackgroundLoader*)loader)->QueueLoadFile((const char*)a, (SafeAllocator*)0);
        }
        p->loadStep = KeyTableLoadStep_Wait;
        return func_020dfd40(p, 0, 0);
    case KeyTableLoadStep_Wait:
        if (((BackgroundLoader*)loader)->GetTaskStatus(p->loadTask) == 0) {
            return 0;
        }
        p->loadStep = KeyTableLoadStep_Load;
        return func_020dfd40(p, 0, 0);
    case KeyTableLoadStep_Load: {
        void* data = 0;
        unsigned int size = 0;
        short idx;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(p->loadTask, &data, &size);
        if (p->singleKey < 0) {
            KeyTable_Load(p, p->allocator, data, size);
        } else {
            idx = p->singleKey;
            func_020e0028(p, p->allocator, data, size, &idx, 1);
        }
        KeyTable_EndLoad(p);
        return 1;
    }
    default:
        return 1;
    }
}
