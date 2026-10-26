#include <globaldefs.h>

struct Struct_020becd4_2 {
    unsigned char unknown_0[0xc4];
    unsigned short unknown_c4_;
    unsigned char unknown_c6_[6];
    unsigned int unknown_cc_;
};

struct Struct_020becd4 {
    Struct_020becd4_2* player;
};

static inline bool inline_020becd4(const Struct_020becd4* handle)
{
    return handle->player != NULL;
}

// USA: func_020becd4
extern "C" ARM unsigned int func_020becd4(void* object)
{
    Struct_020becd4* handle = (Struct_020becd4*)object;
    Struct_020becd4_2* player;
    unsigned long long length;
    if (!inline_020becd4(handle))
        return 0;
    player = handle->player;
    length = player->unknown_cc_;
    length *= 1000;
    length /= (unsigned int)player->unknown_c4_;
    return (unsigned int)length;
}
