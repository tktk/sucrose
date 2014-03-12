#include "sucrose/strconv/iconv/iconv.h"

#include "fg/util/export.h"
#include "fg/strconv/toutf32.h"

FgBool fgToUtf32FromString(
    FgUtf32 *           _to
    , const FgString *  _FROM
    , FgSize *          _outputLength
    , FgSize *          _inputLength
)
{
    return sucrose::iconv(
        *_to
        , *_FROM
        , *_outputLength
        , *_inputLength
    );
}

FgBool fgToUtf32FromUtf8(
    FgUtf32 *           _to
    , const FgUtf8 *    _FROM
    , FgSize *          _outputLength
    , FgSize *          _inputLength
)
{
    return sucrose::iconv(
        *_to
        , *_FROM
        , *_outputLength
        , *_inputLength
    );
}

FgBool fgToUtf32FromUtf16(
    FgUtf32 *           _to
    , const FgUtf16 *   _FROM
    , FgSize *          _outputLength
    , FgSize *          _inputLength
)
{
    return sucrose::iconv(
        *_to
        , *_FROM
        , *_outputLength
        , *_inputLength
    );
}
