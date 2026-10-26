#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov023_021f2e6c {
    unsigned int id : 9;
    unsigned int pad : 5;
    unsigned int b14 : 1;
    unsigned int unknown_1_7_ : 1;
    unsigned int unknown_2_0_ : 1;
    unsigned int rest : 15;
};
struct Struct_ov023_021f2e6c_3 {
    Struct_ov023_021f2e6c bits;
    char pad[0xc];
};
struct Struct_ov023_021f2e6c_4 {
    unsigned char count;
    char pad[3];
    Struct_ov023_021f2e6c_3 entries[1];
};
struct Struct_ov023_021f2e6c_5 {
    char pad[4];
    short ids[8];
    short count;
};
struct Struct_ov023_021f2e6c_6 {
    char pad[0x6c];
    int unknown_6c_;
    int unknown_70_[4];
    char pad2[0x84 - 0x80];
    int f84;
    int unknown_88_;
    int unknown_8c_;
};
struct Struct_ov023_021f2e6c_7 { int w[3]; };
struct Struct_ov023_021f2e6c_8 { char* a; char* b; int c; };
struct Struct_ov023_021f2e6c_9 { int w[0x15]; };

extern "C" Struct_ov023_021f2e6c_4* func_02094d6c(void);
extern "C" unsigned char* MessageSystem_GetInstance(void);
extern "C" void func_ov023_021d8b6c(void* p);
extern "C" void func_ov023_021d8af8(void* p);
extern "C" void func_ov000_0215fa84(void* obj, short* a, short* b, short* c);
struct Struct_0205faf4_7;
extern "C" void* func_02096134(Struct_0205faf4_7*, int);
extern "C" void func_02046380(unsigned char* st);
struct TableA68;
extern "C" char* func_02072a68(TableA68*, int);
extern "C" void NameText_Clear(void* p);
extern "C" unsigned char* func_0200fea4(GameState* gs, int id);
extern "C" Struct_ov023_021f2e6c_7 func_ov023_021ed804(Struct_ov023_021f2e6c_7 t, void* p);
extern "C" void func_ov023_021edf38(Struct_ov023_021f2e6c_7* dst, const Struct_ov023_021f2e6c_7& src);
extern "C" void __clear(void* dst, int n);
extern "C" void func_020dcf7c(int count, void* buf);
extern "C" void func_0209c6d8(void* actor, int arg);
#if !defined(jpn)
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif
extern "C" void func_ov000_0215fa70(void* obj, short a, short b, short c);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int func_ov023_021ed92c(void);
struct Struct_ov023_021eeaac_2;
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2*);
struct Struct_020d784c;
extern "C" void func_020d784c(Struct_020d784c*);
extern "C" int func_ov023_021f4fc8(void);
struct StreamHeader;
extern "C" void func_020d7870(void*, void*, StreamHeader*, int, unsigned char);
struct Struct_020deb08;
extern "C" short func_020deb08(Struct_020deb08*);
extern "C" void func_020de868(void* p);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020dea64(void* a, void* b, void* c, int d, void* e, int flag);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void func_0209e3dc(char*, int);
extern "C" void func_0209fd64(Struct_ov023_021f2e6c_6* mgr, SafeAllocator* alloc, void* data, unsigned int len);
extern "C" void func_0209e46c(char*);
struct Struct_0209fe10;
extern "C" void func_0209fe10(Struct_0209fe10*, int);
struct Struct_0209fe18;
extern "C" void func_0209fe18(Struct_0209fe18*);
struct Struct_020d794c;
extern "C" char* func_020d794c(Struct_020d794c*, int);
struct Struct_ov023_021f2e6c_2;
extern "C" int func_ov023_021f3a8c(Struct_ov023_021f2e6c_2*);
struct StoreStruct;
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" unsigned char* func_ov000_02162d88(void* self, unsigned short key);
extern "C" void func_02048614(unsigned char* obj);
extern "C" void func_02049c88(unsigned char* obj, int v);
struct Struct_02048850;
struct Struct_02048850_2;
extern "C" void func_02048850(Struct_02048850*, Struct_02048850_2*);
extern "C" void func_02048588(unsigned char* src, unsigned char* dst);
struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_02049f28(unsigned char* obj);
extern "C" void* func_ov000_02160f14(void* self);
extern "C" void func_ov000_0216d370(void* cam, int a, int b, int c);
extern "C" void func_ov000_0216d530(void* cam, int v);
extern "C" void Camera_SetTarget(struct Camera*, int, int, int);
extern "C" void Camera_SetOrbit(void* cam, int a, int b, int c);
extern "C" void func_ov000_02163b90(void* self, int v);
extern "C" void func_02049f3c(unsigned char* obj);
extern "C" Struct_ov023_021f2e6c_9* func_0202ed64(void* cam);
extern "C" void func_ov000_0216d2d0(void* cam);
struct Struct_0202ed0c_2;
struct Struct_0202ed0c;
extern "C" void func_0202ed0c(Struct_0202ed0c_2*, Struct_0202ed0c*);

extern "C" int* _ZZ21inline_ov023_021f4c04vE1s;
extern char g_bgmPlayer;
extern char data_ov023_021fe2ca;
extern char data_ov023_021fe2e5;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern char data_ov023_021fd862;
extern char data_ov023_021fe2f7;

#if defined(jpn)
extern char data_ov023_021fd54e[];
extern char data_ov023_021fd578[];
extern char data_ov023_021fd5a2[];
struct Struct_0206f01c_2;
extern "C" void* func_0206f4f0(Struct_0206f01c_2*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020de968(int,char*);
extern "C" void func_0204500c(void*,char*,int);
extern "C" int func_020e052c(void*,void*,const char*,void*,short,unsigned char);
#endif
// USA: func_ov023_021f2e6c
extern "C" ARM int func_ov023_021f2e6c(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x5778, regionalOffset1=0x5780, regionalOffset2=0x5784, regionalOffset3=0x57ac, regionalOffset4=0x577c, regionalOffset5=0x218, regionalOffset6=0x17e2, Enum_ov023_021f2e6c_2456=0x868, Enum_ov023_021f2e6c_3756=0xe28, regionalOffset9=0x57b0, Enum_ov023_021f2e6c_552=0x2e4, Enum_ov023_021f2e6c_3784=0xe44, Enum_ov023_021f2e6c_21946=0x57aa, Enum_ov023_021f2e6c_21950=0x57ae, Enum_ov023_021f2e6c_21912=0x5788, Enum_ov023_021f2e6c_21944=0x57a8};
#else
 enum {regionalOffset0=0x5588, regionalOffset1=0x5590, regionalOffset2=0x5594, regionalOffset3=0x55bc, regionalOffset4=0x558c, regionalOffset5=0x29c, regionalOffset6=0x19b2, Enum_ov023_021f2e6c_2456=0x998, Enum_ov023_021f2e6c_3756=0xeac, regionalOffset9=0x55c0, Enum_ov023_021f2e6c_552=0x228, Enum_ov023_021f2e6c_3784=0xec8, Enum_ov023_021f2e6c_21946=0x55ba, Enum_ov023_021f2e6c_21950=0x55be, Enum_ov023_021f2e6c_21912=0x5598, Enum_ov023_021f2e6c_21944=0x55b8};
#endif
    unsigned char* st;
    int* g = _ZZ21inline_ov023_021f4c04vE1s;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Struct_ov023_021f2e6c_4* tbl = func_02094d6c();
    st = MessageSystem_GetInstance();
    Struct_ov023_021f2e6c_3* var4;
    int state = g[0];
    if (state == 0) {
        if (*(void**)(self + regionalOffset0) != 0) {
            func_ov023_021d8b6c(*(void**)(self + regionalOffset0));
            func_ov023_021d8af8(*(void**)(self + regionalOffset0));
            *(void**)(self + regionalOffset0) = 0;
        }
        *(void**)(self + regionalOffset1) = 0;
        *(void**)(self + regionalOffset2) = 0;
        *(short*)(self + regionalOffset3) = 0;
        *(short*)(self + regionalOffset4) = -1;
        ((SafeAllocator*)(self + 0x30))->Reset();
        if (*(short*)(*(char**)(self + regionalOffset5) + 0x8e4a) > 0) {
            short kind = 0;
            short count = 0;
            short target = 0;
            func_ov000_0215fa84(*(void**)(self + regionalOffset5), &kind, &target, &count);
            void* entry = func_02096134((Struct_0205faf4_7*)tbl, *(short*)(*(char**)(self + regionalOffset5) + 0x8e4a));
            if (count != 0 && entry != 0) {
                func_02046380(st);
#if defined(jpn)
                char* msg = data_ov023_021fd54e;
                if (kind == 0x12) msg = data_ov023_021fd578;
                void* name = func_0206f4f0((Struct_0206f01c_2*)(*(char**)(self + 0x21c) + 0x678), target);
                if (name != 0) MessageSystem_SetStringArgument((Obj02046574*)st, 0, *(char**)name);
                char rawName[0x40];
                __clear(rawName,0x40);
                func_020de968(count,rawName);
                MessageSystem_SetStringArgument((Obj02046574*)st, 1, rawName);
#else
                int key = 0x29;
                if (kind == 0x12) {
                    key = 0x2a;
                }
                char* msg = func_02072a68((TableA68*)(self + 0x5904), key);
                Struct_ov023_021f2e6c_7 words;
                NameText_Clear(&words);
                GameState* gs = GameState::GetInstance();
                for (int i = 0xc0; i <= 0xc7; i++) {
                    unsigned char* c = func_0200fea4(gs, i);
                    if (c != 0) {
                        void* p = *(void**)(c + 0x144);
                        if (target == *(short*)((char*)p + 8)) {
                            func_ov023_021edf38(&words, func_ov023_021ed804(words, p));
                            *(Struct_ov023_021f2e6c_7**)(st + 0x20) = &words;
                            break;
                        }
                    }
                }
                char bufA[0x80];
                char var21[0x80];
                Struct_ov023_021f2e6c_8 bufs;
                __clear(bufA, 0x80);
                __clear(var21, 0x80);
                NameText_Clear(&bufs);
                bufs.a = bufA;
                bufs.b = var21;
                func_020dcf7c(count, &bufs);
                *(Struct_ov023_021f2e6c_8**)(st + 0x18) = &bufs;

#endif
                func_0209c6d8(&g_bgmPlayer, 0x3e);
#if defined(jpn)
                func_0204500c(st, msg, 1);
#else
                func_0204500c(st, msg, 1, 0xe3);
#endif

                st[regionalOffset6] = 0;
                *(int*)(st + Enum_ov023_021f2e6c_2456) = 1;
                func_ov000_0215fa70(*(void**)(self + regionalOffset5), kind, 0, 0);
                g[0] = 10;
                return *(int*)(self + Enum_ov023_021f2e6c_3756);
            }
        }
        if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0) {
            return 0xf;
        }
        if (func_ov023_021ed92c() != 0 && *(short*)(*(char**)(self + regionalOffset5) + 0x8e4a) == 0) {
            return 0xf;
        }
        int count = tbl->count;
        Struct_ov023_021f2e6c_3* entries = tbl->entries;
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (entries[i].bits.unknown_2_0_ && !entries[i].bits.unknown_1_7_) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)g);
            return 0xf;
        }
        *(Struct_ov023_021f2e6c_5**)(self + regionalOffset2) = (Struct_ov023_021f2e6c_5*)((SafeAllocator*)(self + 0x30))->Allocate(0x18);
        *(Struct_ov023_021f2e6c_6**)(self + regionalOffset1) = (Struct_ov023_021f2e6c_6*)((SafeAllocator*)(self + 0x30))->Allocate(0x8a0);
        func_020d784c((Struct_020d784c*)(*(Struct_ov023_021f2e6c_5**)(self + regionalOffset2)));
        *(SafeAllocator**)(self + regionalOffset9) = (SafeAllocator*)((SafeAllocator*)(self + 0x30))->Allocate(0x14);
        (*(SafeAllocator**)(self + regionalOffset9))->CreateTypeA(((SafeAllocator*)(self + 0x30))->Allocate(0xf000), 0xf000);
        FontBankLoader* h = FontBankLoader_GetInstance();
        func_02094b40(h);
        func_02094b30(h, 0x210, 1);
        g[0] = 1;
    } else if (state == 10) {
        if (func_ov023_021f4fc8() != 0) {
            g[0] = 0;
        }
    } else if (state == 11) {
#if defined(jpn)
        g[2] = loader->QueueLoadFile(data_ov023_021fd5a2, 0);
#else
        g[2] = loader->QueueLoadFileInGP2(&data_ov023_021fe2ca, &data_ov023_021fe2e5, 0);
#endif

        g[0]++;
        return *(int*)(self + Enum_ov023_021f2e6c_3756);
    } else if (state == 12) {
        if (loader->GetTaskStatus(g[2]) != 0) {
            unsigned int length;
            void* data;
            loader->GetLoadedFileByID(g[2], &data, &length);
            func_020d784c((Struct_020d784c*)(*(Struct_ov023_021f2e6c_5**)(self + regionalOffset2)));
            int count;
            Struct_ov023_021f2e6c_3* entries = tbl->entries;
            count = tbl->count;
            for (int i = 0; i < count; i++) {
                if (entries[i].bits.unknown_2_0_ && !entries[i].bits.unknown_1_7_) {
                    int id = entries[i].bits.id;
                    Struct_ov023_021f2e6c_5* list = *(Struct_ov023_021f2e6c_5**)(self + regionalOffset2);
                    list->ids[list->count++] = id;
                }
            }
            func_020d7870(*(void**)(self + regionalOffset2), self + 0x30, (StreamHeader*)data, length, 0);
            loader->RemoveTask(g[2]);
            g[2] = -1;
            g[0] = 4;
            *(short*)(self + regionalOffset3) = 1;
        }
    } else if (state == 1) {
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
            char* heap;
#if defined(jpn)
            char* sub = self + 0x3ec;
#else
            char* sub = self + 0x830;
#endif

#if defined(jpn)
            if (func_020deb08((Struct_020deb08*)(sub + 0x3400)) <= 0) {
#else
            if (func_020deb08((Struct_020deb08*)(sub + 0x3000)) <= 0) {
#endif

#if defined(jpn)
                func_020de868(sub + 0x3400);
#else
                func_020de868(sub + 0x3000);
#endif

                heap = self + Enum_ov023_021f2e6c_552;
                ((SafeAllocator*)(heap + 0x5000))->Reset();
#if defined(jpn)
                func_020e052c(sub + 0x3400, heap + 0x5000, g_itemDataArchive, &data_ov023_021fd862, 3, 1);
#else
                BackgroundLoader::AddLockGlobal();
                unsigned int size;
                void* file = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &size);
                if (file != 0) {
                    func_020dea64(sub + 0x3000, heap + 0x5000, file, size, &data_ov023_021fd862, 3);

                }
                BackgroundLoader::RemoveLockGlobal();
#endif

            }
            g[0] = 2;
        }
    } else if (state == 2) {
        var4 = tbl->entries;
        int count = tbl->count;
        int found = 0;
        for (short i = *(short*)(self + regionalOffset4) + 1; i < count; i++) {
            if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0 || func_ov023_021ed92c() != 0) {
                if (*(short*)(*(char**)(self + regionalOffset5) + 0x8e4a) != var4[i].bits.id) {
                    continue;
                }
            }
            if (var4[i].bits.unknown_2_0_ && !var4[i].bits.unknown_1_7_) {
                *(short*)(self + regionalOffset4) = i;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)g);
            return 0xf;
        }
        char name[0x40];
        sprintf(name, &data_ov023_021fe2f7, var4[*(short*)(self + regionalOffset4)].bits.id / 50 + 1);
        g[1] = loader->QueueLoadFile(name, 0);
        g[0] = 3;
    } else if (state == 3) {
        if (loader->GetTaskStatus(g[1]) != 0) {
            unsigned int length;
            void* data = 0;
            loader->GetLoadedFileByID(g[1], &data, &length);
            if (data == 0) {
                func_ov023_021eefac((Struct_ov023_021eeaac_2*)g);
                return 0xf;
            }
            void* copy;
            var4 = tbl->entries;
            (*(SafeAllocator**)(self + regionalOffset9))->Reset();
            copy = (*(SafeAllocator**)(self + regionalOffset9))->Allocate(length);
            memcpy(copy, data, length);
            loader->RemoveTask(g[1]);
            g[1] = -1;
            func_0209e3dc((char*)(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1)), (int)(*(void**)(self + regionalOffset5)));
            func_0209fd64(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1), *(SafeAllocator**)(self + regionalOffset9), copy, length);
            func_0209e46c((char*)(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1)));
            func_0209fe10((Struct_0209fe10*)(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1)), var4[*(short*)(self + regionalOffset4)].bits.id);
            g[0] = 4;
        }
    } else if (state == 4) {
        if (*(short*)(self + regionalOffset3) == 1) {
            *(short*)(self + regionalOffset3) = 2;
        } else {
            func_0209fe18((Struct_0209fe18*)(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1)));
        }
        char* msg = 0;
        int key = (*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))->unknown_6c_;
        if (key > 0) {
            if (*(short*)(self + regionalOffset3) == 2) {
                msg = func_020d794c((Struct_020d794c*)(*(Struct_ov023_021f2e6c_5**)(self + regionalOffset2)), (short)key);
            } else {
                g[0] = 11;
                return *(int*)(self + Enum_ov023_021f2e6c_3756);
            }
        }
        if (func_ov023_021f3a8c((Struct_ov023_021f2e6c_2*)(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))) != 0 || msg != 0) {
            Struct_ov023_021f2e6c_3* entries = tbl->entries;
            if (func_ov023_021f3a8c((Struct_ov023_021f2e6c_2*)(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))) != 0) {
                if (entries[*(short*)(self + regionalOffset4)].bits.b14) {
                    entries[*(short*)(self + regionalOffset4)].bits.unknown_1_7_ = 1;
                }
            }
            if (msg != 0) {
                func_02046380(st);
                for (int i = 0; i < 4; i++) {
                    func_020465c0((StoreStruct*)st, i, (*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))->unknown_70_[i]);
                }
#if defined(jpn)
                func_0204500c(st, func_020d794c((Struct_020d794c*)(*(Struct_ov023_021f2e6c_5**)(self + regionalOffset2)), (short)(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))->unknown_6c_), 1);
#else
                func_0204500c(st, func_020d794c((Struct_020d794c*)(*(Struct_ov023_021f2e6c_5**)(self + regionalOffset2)), (short)(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))->unknown_6c_), 1, 0xe3);
#endif

                st[regionalOffset6] = 0;
                *(int*)(st + Enum_ov023_021f2e6c_2456) = 1;
                int f84 = (*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))->f84;
                if (f84 > 0) {
                    unsigned char* node = func_ov000_02162d88(self, f84);
                    if (node != 0) {
                        GameState* gs = GameState::GetInstance();
                        int idx = 0xc0;
                        for (int i = 0xc0; i <= 0xc7; i++) {
                            unsigned char* c = func_0200fea4(gs, i);
                            if (c != 0 && *(int*)(c + 0x138) != 0) {
                                idx = i;
                                break;
                            }
                        }
                        unsigned char* obj = func_0200fea4(gs, idx);
                        int saved = *(int*)(obj + 0x138);
                        if (obj != 0 && saved != 0) {
                            int var59 = *(int*)(obj + 0x13c);
                            int var60 = *(int*)(obj + 0x144);
                            func_02048614(obj);
                            *(short*)(obj + 4) = idx;
                            func_02049c88(obj, var59);
                            func_02048850((Struct_02048850*)obj, (Struct_02048850_2*)var60);
                            func_02048588(node, obj);
                            *(int*)(obj + 0x138) = saved;
                            ((Object3D*)obj)->SetField06(*(unsigned short*)(self + Enum_ov023_021f2e6c_3784));
                            GameObject_ForceMotionState((Bytes02033b88*)obj, 0);
                            obj[0xc2] |= 0x20;
                            ((Object3D*)obj)->SetInheritedAlpha(0x1f);
                            ((Object3D*)obj)->MakeVisible();
                            func_02049f28(obj);
                            void* cam = func_ov000_02160f14(self);
                            func_ov000_0216d370(cam, 1, 1, 1);
                            func_ov000_0216d530(cam, idx);
                            int height = ((Object3D*)obj)->GetHeight();
                            int y = (int)(((long long)height * 0x4cc + 0x800) >> 12);
                            if (y < 0) {
                                y = 0;
                            }
                            Camera_SetTarget((struct Camera*)cam, 0, y, 0);
                            int z = (int)(((long long)height * 0x2333 + 0x800) >> 12);
                            int y2 = y + 0x800;
                            if (y2 < 0) {
                                y2 = 0;
                            }
                            Camera_SetOrbit(cam, 0, y2, z + 0x4000);
                            func_ov000_02163b90(self, 0);
                            *(short*)(self + Enum_ov023_021f2e6c_21946) = idx;
                        }
                    }
                }
                g[0]++;
            } else {
                g[0] = 6;
            }
        }
    } else if (state == 5) {
        int done = 0;
        if (func_ov023_021f4fc8() != 0 || *(unsigned char*)(self + Enum_ov023_021f2e6c_21950) != 0) {
            Struct_ov023_021f2e6c_6* mgr = *(Struct_ov023_021f2e6c_6**)(self + regionalOffset1);
            if (mgr->f84 > 0 && *(short*)(self + Enum_ov023_021f2e6c_21946) > 0) {
                if (mgr->unknown_88_ != 0) {
                    GameState* gs = GameState::GetInstance();
                    unsigned char* obj = (unsigned char*)gs->GetGameObjectByIndex(*(short*)(self + Enum_ov023_021f2e6c_21946));
                    if (obj != 0) {
                        int alpha = ((Object3D*)obj)->GetInheritedAlpha();
                        if (*(unsigned char*)(self + Enum_ov023_021f2e6c_21950) == 0 && alpha == 0x1f) {
                            ((Object3D*)obj)->TransitionInheritedAlpha(0, 500);
                            *(unsigned char*)(self + Enum_ov023_021f2e6c_21950) = 1;
                        }
                        if (alpha <= 0) {
                            ((Object3D*)obj)->MakeHidden();
                            func_02049f3c(obj);
                            *(unsigned char*)(self + Enum_ov023_021f2e6c_21950) = 0;
                            void* cam = func_ov000_02160f14(self);
                            Struct_ov023_021f2e6c_9 blk = *func_0202ed64(cam);
                            func_ov000_0216d2d0(cam);
                            func_0202ed0c((Struct_0202ed0c_2*)cam, (Struct_0202ed0c*)&blk);
                            func_02048614(obj);
                            *(short*)(self + Enum_ov023_021f2e6c_21946) = 0;
                            done = 1;
                        }
                    }
                }
            } else {
                done = 1;
            }
        }
        if (done != 0) {
            if (func_ov023_021f3a8c((Struct_ov023_021f2e6c_2*)(*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))) != 0) {
                g[0]++;
            } else {
                (*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))->unknown_6c_ = -1;
                (*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))->f84 = 0;
                g[0] = 4;
            }
        }
    } else if (state == 6) {
        int v = (*(Struct_ov023_021f2e6c_6**)(self + regionalOffset1))->unknown_8c_;
        if (v != 0) {
            *(int*)(self + Enum_ov023_021f2e6c_21912 + *(short*)(self + Enum_ov023_021f2e6c_21944) * 4) = v;
            (*(short*)(self + Enum_ov023_021f2e6c_21944))++;
        }
        g[0] = 2;
    }
    return *(int*)(self + Enum_ov023_021f2e6c_3756);
}
