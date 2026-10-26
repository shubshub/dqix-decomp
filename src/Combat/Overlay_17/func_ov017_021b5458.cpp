#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void __clear(void* buf, int size);
extern "C" void func_020a8e88(void* p);
extern "C" void func_020a8fd0(void* obj, void* arg, void* file, unsigned int size, short* ids, int count);
extern "C" void func_ov017_021b5648(void* obj);

struct Struct_ov017_021b5458_2 {
    unsigned int id : 12;
    int unk4;
};

struct Struct_ov017_021b5458_3 {
    unsigned int id : 12;
};

struct Struct_0209ad40_3 {
    unsigned char unk0[2];
    unsigned char countA;
    unsigned char countB;
    struct Struct_ov017_021b5458_2 unknown_4_[6];
    struct Struct_ov017_021b5458_3 unknown_34_[6];
};

extern "C" struct Struct_0209ad40_3* func_0209b9c0(struct Struct_0209ad40_3* base, int i);

struct Struct_ov017_021b5458_4 {
    char pad0[0x10];
    void* field10;
#if defined(jpn)
    char unknown_14_[0x120 - 0x14];
#else
    char unknown1_14_[0x124 - 0x14];
#endif

    struct Struct_0209ad40_3 rows[6];
    char unknown_2ec_[0x30c - 0x2ec];
    unsigned char unknown_30c_[0xc];
};

struct Struct_ov017_021b5458 {
    char pad0[8];
    struct Struct_ov017_021b5458_4* sub;
    int key;
};

// USA: func_ov017_021b5458
extern "C" ARM void func_ov017_021b5458(struct Struct_ov017_021b5458* obj) {
    struct Struct_ov017_021b5458_4* sub;
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    LinkSession_GetInstance();
    if (!loader->GetTaskStatus(obj->key)) {
        return;
    }

    if (loader->GetDetailedTaskStatus(obj->key) == 2) {
        unsigned int size;
        void* file;
        loader->GetLoadedFileByID(obj->key, &file, &size);
        if (file != 0) {
            short ids[64];
            __clear(ids, 0x80);
            short count = 0;
            sub = obj->sub;
            for (int i = 0; i < 6; i++) {
                struct Struct_0209ad40_3* row = func_0209b9c0(sub->rows, i);
                if (row == 0) {
                    continue;
                }
                for (int j = 0; j < row->countA; j++) {
                    unsigned int id = row->unknown_4_[j].id;
                    int unique = 1;
                    for (int k = 0; k < count; k++) {
                        if (id == ids[k]) {
                            unique = 0;
                            break;
                        }
                    }
                    if (unique) {
                        ids[count++] = id;
                    }
                }
                for (int j = 0; j < row->countB; j++) {
                    unsigned int id = row->unknown_34_[j].id;
                    int unique = 1;
                    for (int k = 0; k < count; k++) {
                        if (id == ids[k]) {
                            unique = 0;
                            break;
                        }
                    }
                    if (unique) {
                        ids[count++] = id;
                    }
                }
            }
            sub = obj->sub;
            func_020a8e88(sub->unknown_30c_);
            func_020a8fd0(sub->unknown_30c_, obj->sub->field10, file, size, ids, count);
        }
    }

    loader->RemoveTask(obj->key);
    obj->key = -1;
    func_ov017_021b5648(obj);
}
