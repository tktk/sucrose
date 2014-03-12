#include "fg/strconv/toutf8.h"
#include "sucrose/strconv/iconv/iconv.h"

#include "fg/util/export.h"
#include "fg/strconv/tostring.h"

FgSize fgGetMaxStringCharCount(
)
{
    return FG_MAX_UTF8_CHAR_COUNT;
}

FgBool fgToStringFromUtf8(
    FgString *          _to
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

FgBool fgToStringFromUtf16(
    FgString *          _to
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

FgBool fgToStringFromUtf32(
    FgString *          _to
    , const FgUtf32 *   _FROM
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
