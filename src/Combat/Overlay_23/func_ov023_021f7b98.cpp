#include <globaldefs.h>
#include "Graphics/Background.h"

extern "C" void Background_Init(struct BackgroundGraphics* obj);

struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* entry);

extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

extern "C" void Background_FlushFile(void* obj, char* str);

extern "C" void Background_UploadFile(struct BackgroundGraphics* self, char* str);

// The copy goes through byte-returning accessors (as the original's member functions did); direct field copies
// compile differently.
static inline unsigned char GetSubScreen(struct BackgroundGraphics* layer) { return layer->subScreen_; }
static inline unsigned char GetBgNumber(struct BackgroundGraphics* layer) { return layer->bgNumber_; }
static inline void SetSubScreen(struct BackgroundGraphics* layer, unsigned char value) { layer->subScreen_ = value; }
static inline void SetBgNumber(struct BackgroundGraphics* layer, unsigned char value) { layer->bgNumber_ = value; }

struct Obj021f7b98 {
#if defined(jpn)
    char pad0[0x24];
#else
    char pad0[0x28];
#endif
    struct BackgroundGraphics list;
};

// USA: func_ov023_021f7b98
extern "C" ARM void func_ov023_021f7b98(struct Obj021f7b98* self, void* keyObj, int useTag, struct PacRecord* entry, unsigned int entryLength) {
    int size;
    void* rp;
    struct BackgroundGraphics list;

    if (entry == 0 || entryLength == 0) {
        return;
    }
    int count = Pac_CountFiles((struct PacRecord*)entry);
    for (int i = 0; i < count; i++) {
        char* rec = (char*)Pac_GetFile(entry, i, &rp, &size);
        if (rec) {
            Background_Init(&list);
            SetSubScreen(&list, GetSubScreen(&self->list));
            SetBgNumber(&list, GetBgNumber(&self->list));
            if (useTag) {
                Background_FlushFile(&list, rec);
            } else {
                Background_UploadFile(&list, rec);
            }
        }
    }
}
