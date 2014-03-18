#include "sucrose/boot/config.h"

#include <new>

#include "fg/util/export.h"
#include "fg/boot/config.h"

FgBootConfig * fgBootConfigNew(
)
{
    return new( std::nothrow )FgBootConfig;
}

void fgBootConfigFree(
    FgBootConfig *  _this
)
{
    delete _this;
}
