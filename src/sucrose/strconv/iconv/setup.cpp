#include "sucrose/util/setup.h"
#include "sucrose/strconv/iconv/setup.h"

namespace sucrose {
    void initialize(
    )
    {
        initializeStrconv();
    }

    void finalize(
    )
    {
    }
}
