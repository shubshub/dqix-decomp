#include <globaldefs.h>

extern "C" void* GlobalFlags_GetInstance(void);

struct FlagWord02046708;
extern "C" int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);

// One loader per display mode; each runs one load step a frame and clears modeLoading when it is done
extern "C" {
    void MapDisplay_LoadLocalMap(void* obj); // 0: the field map (minimap.gp2 <map>.bmmp, obj_mm.pac)
    void MapDisplay_LoadTreasureMap(void* obj); // 1: a treasure map (tmap_base.pac, the active map image, obj_mm_tmap_f.pac)
    void func_020e081c(void* obj); // 2: tmap_base.pac and tmuo_<LG>.pac
    void MapDisplay_LoadGrottoMap(void* obj); // 3: a grotto (obj_mm_tmap.pac, tf.gp2)
    void MapDisplay_LoadWorldMap(void* obj); // 4: the world map zones 10000 and 10100 (obj_mm_w.pac, w_offset.bin)
}

struct Obj020214f0 {
#if defined(jpn)
    char pad[0x915];
#else
    char pad[0x9c1];
#endif
    unsigned char mode;        // MapDisplay_SetMode sets it
    unsigned char pad2;
    unsigned char modeLoading; // set with mode, cleared by the mode's loader at its last step
};

// Main, originally HandleStateDispatch020214f0 (USA 0x020214f0, EUR 0x02021500, JPN 0x020210e4)
extern "C" ARM void MapDisplay_RunModeLoader(struct Obj020214f0* obj) {
    if (obj->modeLoading == 0) {
        return;
    }
    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 0x41)) {
        return;
    }

    switch (obj->mode) {
    case 0:
        MapDisplay_LoadLocalMap(obj);
        break;
    case 1:
        MapDisplay_LoadTreasureMap(obj);
        break;
    case 2:
        func_020e081c(obj);
        break;
    case 3:
        MapDisplay_LoadGrottoMap(obj);
        break;
    case 4:
        MapDisplay_LoadWorldMap(obj);
        break;
    }
}
