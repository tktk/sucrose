#ifndef SUCROSE_STRCONV_ICONV_ICONV_H
#define SUCROSE_STRCONV_ICONV_ICONV_H

#include "fg/def/common/primitives.h"

namespace sucrose {
    extern const FgStringChar * ENCODE_STRING;
    extern const FgStringChar * ENCODE_UTF8;
    extern const FgStringChar * ENCODE_UTF16;
    extern const FgStringChar * ENCODE_UTF32;

    void initializeIconv(
    );

    FgBool iconv(
        void *
        , const void *
        , FgSize
        , FgSize
        , FgSize
        , FgSize
        , FgSize &
        , FgSize &
        , const FgStringChar *
        , const FgStringChar *
    );

    template< typename T >
    FgSize getSize(
        const T &   _STRING
    )
    {
        return _STRING.length * sizeof( *( _STRING.ptr ) );
    }

    template< typename T >
    const FgStringChar * getEncode(
        const T &
    );

    template<>
    inline const FgStringChar * getEncode(
        const FgString &
    )
    {
        return ENCODE_STRING;
    }

    template<>
    inline const FgStringChar * getEncode(
        const FgUtf8 &
    )
    {
        return ENCODE_UTF8;
    }

    template<>
    inline const FgStringChar * getEncode(
        const FgUtf16 &
    )
    {
        return ENCODE_UTF16;
    }

    template<>
    inline const FgStringChar * getEncode(
        const FgUtf32 &
    )
    {
        return ENCODE_UTF32;
    }

    template<
        typename TO_T
        , typename FROM_T
    >
    FgBool iconv(
        TO_T &              _to
        , const FROM_T &    _FROM
        , FgSize &          _outputLength
        , FgSize &          _inputLength
    )
    {
        return iconv(
            _to.ptr
            , _FROM.ptr
            , _to.length
            , _FROM.length
            , sizeof( *( _to.ptr ) )
            , sizeof( *( _FROM.ptr ) )
            , _outputLength
            , _inputLength
            , getEncode( _to )
            , getEncode( _FROM )
        );
    }
}

#endif  // SUCROSE_STRCONV_ICONV_ICONV_H
