#include "sucrose/boot/default/config.h"
#include "fg4cpp/def/common/primitives.h"

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
    _this->mainFileBuffer.assign(
        _MAIN_FILE->ptr
        , _MAIN_FILE->length
    );
    auto &  mainFile = fg::toFgpp( _this->mainFile );
    mainFile.assign( _this->mainFileBuffer );

    return true;
}

FgBool fgBootConfigSetMainType(
    FgBootConfig *      _this
    , const FgUtf32 *   _MAIN_TYPE
)
{
    _this->mainTypeBuffer.assign(
        _MAIN_TYPE->ptr
        , _MAIN_TYPE->length
    );
    auto &  mainType = fg::toFgpp( _this->mainType );
    mainType.assign( _this->mainTypeBuffer );

    return true;
}

FgBool fgBootConfigSetMain(
    FgBootConfig *      _this
    , const FgUtf32 *   _MAIN
)
{
    //TODO
    return false;
}
