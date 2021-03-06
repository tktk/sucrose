﻿#include "sucrose/strconv/iconv/iconv.h"

#include "fg/util/export.h"
#include "fg/strconv/toutf8.h"

FgBool fgToUtf8FromString(
    FgUtf8 *            _to
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

FgBool fgToUtf8FromUtf16(
    FgUtf8 *            _to
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

FgBool fgToUtf8FromUtf32(
    FgUtf8 *            _to
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
