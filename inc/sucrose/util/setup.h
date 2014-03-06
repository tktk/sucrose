#ifndef SUCROSE_UTIL_SETUP_H
#define SUCROSE_UTIL_SETUP_H

namespace sucrose {
    inline void initialize(
    );

    inline void finalize(
    );
}

#if defined COMPILER_TYPE_CLANG // COMPILER_TYPE
extern "C" __attribute__( ( constructor ) ) void constructor(
)
{
    sucrose::initialize();
}

extern "C" __attribute__( ( destructor ) ) void destructor(
)
{
    sucrose::finalize();
}
#elif defined COMPILER_TYPE_MSVC    // COMPILER_TYPE
#include <windows.h>

BOOL WINAPI DllMain(
    HINSTANCE
    , DWORD     _reason
    , LPVOID
)
{
    switch( _reason ) {
    case DLL_PROCESS_ATTACH:
        sucrose::initialize();
        break;

    case DLL_PROCESS_DETACH:
        sucrose::finalize();
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    default:
        return FALSE;
        break;
    }

    return TRUE;
}
#else   // COMPILER_TYPE
#   error 未対応のコンパイラ
#endif  // COMPILER_TYPE

#endif  // SUCROSE_UTIL_SETUP_H
