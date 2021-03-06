﻿#include "sucrose/strconv/iconv/iconv.h"

#include "fg/util/export.h"
#include "fg/strconv/toutf16.h"

FgBool fgToUtf16FromString(
    FgUtf16 *           _to
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

FgBool fgToUtf16FromUtf8(
    FgUtf16 *           _to
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

FgBool fgToUtf16FromUtf32(
    FgUtf16 *           _to
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
