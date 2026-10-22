#include <globaldefs.h>

void* GetNodeIfType1_02168aa0(void* a, int id);
void SetByte38_021fb274(void* obj, int val);
struct Fields021849e0;
void SetFieldConditional_021849e0(struct Fields021849e0* obj, unsigned short val);
extern "C" void func_ov004_0216920c(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

#if defined(jpn)
struct Data02171030 { char pad[0x20]; unsigned char field1a0; };
#else
struct Data02171030 { char pad[0x1a0]; unsigned char field1a0; };
#endif
extern Data02171030* data_ov004_02171030;
extern struct SePlayer g_sePlayer;

// USA: func_ov004_0216986c  (semantic: NotifyNodeAndDispatch_0216986c)
extern "C" ARM int func_ov004_0216986c(void* a) {
    void* node = GetNodeIfType1_02168aa0(a, 0x1e);
    if (!node) {
        return 0;
    }
    SetByte38_021fb274(node, 2);
    SetFieldConditional_021849e0((struct Fields021849e0*)a, 0x64);
    func_ov004_0216920c(a);
    func_ov011_021848a0(a, 0x46);
    if (data_ov004_02171030->field1a0 == 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
    }
    data_ov004_02171030->field1a0 = 1;
    return 0;
}
