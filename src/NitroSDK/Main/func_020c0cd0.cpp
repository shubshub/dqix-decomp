#include <globaldefs.h>

#define DIGEST_BLOCK_SIZE 64

struct Struct_020c0cd0
{
    int digestSize;
    int unknown_4_;
    void* context;
    void* digest;
    void (*reset)(void* context);
    void (*unknown_14_)(void* context, const void* input, unsigned long length);
    void (*unknown_18_)(void* context, void* digest);
};

// USA: func_020c0cd0
extern "C" ARM void func_020c0cd0(void* digest, const void* input, int length, const void* key, int arg4, Struct_020c0cd0* arg5)
{
    unsigned char var0[DIGEST_BLOCK_SIZE];
    unsigned char var1[DIGEST_BLOCK_SIZE];
    unsigned char var2[DIGEST_BLOCK_SIZE];
    const unsigned char* var3;
    int i;

    if (digest == NULL || input == NULL || length == 0 || key == NULL || arg4 == 0 || arg5 == NULL)
        return;

    if (arg4 > arg5->unknown_4_)
    {
        arg5->reset(arg5->context);
        arg5->unknown_14_(arg5->context, key, arg4);
        arg5->unknown_18_(arg5->context, var0);
        key = var0;
        arg4 = arg5->digestSize;
    }
    var3 = (const unsigned char*)key;

    for (i = 0; i < arg4; i++)
        var1[i] = var3[i] ^ 0x36;
    for (; i < arg5->unknown_4_; i++)
        var1[i] = 0x36;
    arg5->reset(arg5->context);
    arg5->unknown_14_(arg5->context, var1, arg5->unknown_4_);
    arg5->unknown_14_(arg5->context, input, length);
    arg5->unknown_18_(arg5->context, arg5->digest);

    for (i = 0; i < arg4; i++)
        var2[i] = var3[i] ^ 0x5c;
    for (; i < arg5->unknown_4_; i++)
        var2[i] = 0x5c;
    arg5->reset(arg5->context);
    arg5->unknown_14_(arg5->context, var2, arg5->unknown_4_);
    arg5->unknown_14_(arg5->context, arg5->digest, arg5->digestSize);
    arg5->unknown_18_(arg5->context, digest);
}
