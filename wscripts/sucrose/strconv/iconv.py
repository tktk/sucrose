# -*- coding: utf-8 -*-

from wscripts import common
from . import MODULE_NAME

_IMPL_NAME = 'iconv'

def setup(
    _context,
    _sources,
    _libraries,
    _useModules,
):
    _sources[ common.SOURCE_DIR ] = {
        common.SUCROSE : {
            MODULE_NAME : {
                _IMPL_NAME : {
                    'setup.cpp',
                    'iconv.cpp',
                    'tostring.cpp',
                    'toutf8.cpp',
                    'toutf16.cpp',
                    'toutf32.cpp',
                },
            },
        },
    }
