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

FgBool fgBootConfigSetMainFile(
    FgBootConfig *      _this
    , const FgUtf32 *   _MAIN_FILE
)
{
    //TODO
    return false;
}
