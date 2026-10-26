#include <globaldefs.h>

struct RenderSource0204bf44 {
    int type;
    int shift;
    short unknown_8_;
    short sa;
    short unknown_c_;
    short se;
    short unknown_10_;
    short unknown_12_;
    int unknown_14_;
    int pad18;
    int unknown_1c_;
    unsigned int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    int unknown_2c_;
    int unknown_30_;
    int unknown_34_;
    int unknown_38_;
};

struct RenderParams0204bf44 {
    struct RenderSource0204bf44 *src;
    char *p4;
    char *p8;
    char *pc;
    char *p10;
    char *unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    int unknown_2c_;
    int unknown_30_[6];
    int unknown_48_;
};

// Main, originally InitRenderParams0204bf44 (USA 0x0204bf44, EUR 0x0204bf54, JPN 0x0204cd64)
extern "C" ARM void TerrainMesh_Init(RenderParams0204bf44* d, void* arg1, RenderSource0204bf44* s, unsigned int) {
    d->src = s;
    d->p4 = (char*)s + d->src->unknown_24_;
    d->p8 = (char*)s + d->src->unknown_28_;
    d->pc = (char*)s + d->src->unknown_2c_;
    d->p10 = (char*)s + d->src->unknown_30_;
    if (d->src->type == 3) {
        d->unknown_14_ = (char*)s + d->src->unknown_38_;
    }
    d->unknown_24_ = d->src->unknown_8_ << d->src->shift;
    d->unknown_28_ = d->src->sa << d->src->shift;
    d->unknown_2c_ = d->src->unknown_c_ << d->src->shift;
    d->unknown_18_ = d->src->se << d->src->shift;
    d->unknown_1c_ = d->src->unknown_10_ << d->src->shift;
    d->unknown_20_ = d->src->unknown_12_ << d->src->shift;
    d->unknown_48_ = d->src->unknown_1c_ * d->src->unknown_20_ + (d->src->unknown_20_ >> 1);
}
