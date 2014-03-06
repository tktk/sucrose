#ifndef SUCROSE_STRING_ICONV_SETUP_H
#define SUCROSE_STRING_ICONV_SETUP_H

#include "sucrose/strconv/iconv/iconv.h"

namespace sucrose {
    inline void initializeStrconv(
    )
    {
        initializeIconv();
    }
}

#endif  // SUCROSE_STRING_ICONV_SETUP_H
