#include <globaldefs.h>
#include "Graphics/Background.h"

void Background_Init(struct BackgroundGraphics* obj);

struct PacRecord;
int Pac_CountFiles(struct PacRecord* entry);

void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

void Background_FlushFile(void* obj, char* str);

void Background_UploadFile(struct BackgroundGraphics* self, char* str);

// The copy goes through byte-returning accessors (as the original's member functions did); direct field copies
// compile differently.
static inline unsigned char GetSubScreen(struct BackgroundGraphics* layer) { return layer->subScreen_; }
static inline unsigned char GetBgNumber(struct BackgroundGraphics* layer) { return layer->bgNumber_; }
static inline void SetSubScreen(struct BackgroundGraphics* layer, unsigned char value) { layer->subScreen_ = value; }
static inline void SetBgNumber(struct BackgroundGraphics* layer, unsigned char value) { layer->bgNumber_ = value; }

struct Struct_ov023_021f7b98 {
#if defined(jpn)
    char unknown1_0_[0x24];
#else
    char unknown_0_[0x28];
#endif
    struct BackgroundGraphics list;
};

// USA: func_ov023_021f7b98
extern "C" ARM void func_ov023_021f7b98(struct Obj021f7b98* self, void* keyObj, int useTag, struct PacRecord* entry, unsigned int entryLength) {
    int size;
    void* rp;
    struct BackgroundGraphics list;

    if (arg3 == 0 || arg4 == 0) {
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
