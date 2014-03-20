#include "sucrose/boot/default/config.h"
#include "fg4cpp/def/common/primitives.h"

#include <new>

#include "fg/util/export.h"
#include "fg/boot/config.h"

namespace {
    FgBool assign(
        FgUtf32 &           _to
        , fg::BUtf32 &      _toBuffer
        , const FgUtf32 *   _FROM
    )
    {
        _toBuffer.assign(
            _FROM->ptr
            , _FROM->length
        );
        auto &  to = fg::toFgpp( _to );
        to.assign( _toBuffer );

        return true;
    }
}

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
    return assign(
        _this->mainFile
        , _this->mainFileBuffer
        , _MAIN_FILE
    );
}

FgBool fgBootConfigSetMainType(
    FgBootConfig *      _this
    , const FgUtf32 *   _MAIN_TYPE
)
{
    return assign(
        _this->mainType
        , _this->mainTypeBuffer
        , _MAIN_TYPE
    );
}

FgBool fgBootConfigSetMain(
    FgBootConfig *      _this
    , const FgUtf32 *   _MAIN
)
{
    return assign(
        _this->main
        , _this->mainBuffer
        , _MAIN
    );
}
