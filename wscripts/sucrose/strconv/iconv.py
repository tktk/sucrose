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
                    'tostring.cpp',
                    'toutf8.cpp',
                },
            },
        },
    }
