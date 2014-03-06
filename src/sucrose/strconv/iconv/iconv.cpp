#include "fg/def/common/primitives.h"

#include <iconv.h>
#include <locale.h>
#include <langinfo.h>

#include "sucrose/strconv/iconv/iconv.h"

namespace {
    class IconvDescriptorDeleter
    {
    private:
        iconv_t &   iconv_;

    public:
        IconvDescriptorDeleter(
            iconv_t &   _iconv
        )
            : iconv_( _iconv )
        {
        }

        ~IconvDescriptorDeleter(
        )
        {
            iconv_close( this->iconv_ );
        }
    };
}

namespace sucrose {
    const FgStringChar *    ENCODE_STRING;
    const FgStringChar *    ENCODE_UTF8 = "UTF-8";
    const FgStringChar *    ENCODE_UTF16 = "UTF-16LE";
    const FgStringChar *    ENCODE_UTF32 = "UTF-32LE";

    void initializeIconv(
    )
    {
        setlocale( LC_CTYPE, "" );

        ENCODE_STRING = nl_langinfo( CODESET );
    }

    FgBool iconv(
        void *                  _to
        , const void *          _FROM
        , FgSize                _toLength
        , FgSize                _fromLength
        , FgSize                _toCharSize
        , FgSize                _fromCharSize
        , FgSize &              _outputLength
        , FgSize &              _inputLength
        , const FgStringChar *  _TO_ENCODE
        , const FgStringChar *  _FROM_ENCODE
    )
    {
        auto    descriptor = iconv_open(
            _TO_ENCODE
            , _FROM_ENCODE
        );
        if( descriptor == reinterpret_cast< iconv_t >( -1 ) ) {
            return false;
        }
        IconvDescriptorDeleter  deleter( descriptor );

        auto    to = static_cast< FgByte * >( _to );
        auto    from = static_cast< FgByte * >( const_cast< void * >( _FROM ) );

        auto    toSize = _toLength * _toCharSize;
        auto    fromSize = _fromLength * _fromCharSize;

        const auto  RESULT = ::iconv(
            descriptor
            , &from
            , &fromSize
            , &to
            , &toSize
        ) != -1;

        _outputLength = _toLength - toSize / _toCharSize;
        _inputLength = _fromLength - fromSize / _fromCharSize;

        if( fromSize > 0 ) {
            return false;
        }

        return RESULT;
    }
}
