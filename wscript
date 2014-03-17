# -*- coding: utf-8 -*-

from wscripts import common
from wscripts import cmdoption
from wscripts import sucrose

import os.path

APPNAME = 'sucrose'
VERSION = '0.2.0'

out = common.BUILD_DIR

def _generateFlags(
    common = [],
    debug = [],
    release = [],
):
    return {
        BUILD : common + OPTIONS
        for BUILD, OPTIONS in {
            cmdoption.BUILD_DEBUG : debug,
            cmdoption.BUILD_RELEASE : release,
        }.items()
    }

_CXXFLAGS_BASES = {
    cmdoption.COMPILER_TYPE_CLANG : _generateFlags(
        common = [
            '-Wall',
            '-fno-rtti',
            '-fvisibility=hidden',
            '-std=c++11',
        ],
        debug = [
            '-O0',
            '-g',
        ],
        release = [
            '-O2',
        ],
    ),
    cmdoption.COMPILER_TYPE_MSVC : _generateFlags(
        common = [
            '/Wall',
            '/nologo',
            '/EHs',
        ],
        debug = [
            '/MDd',
            '/Od',
        ],
        release = [
            '/MD',
            '/O2',
            '/Oi',
            '/GL',
        ],
    ),
}

_LINKFLAGS_BASES = {
    cmdoption.LINKER_TYPE_LD : _generateFlags(
        debug = [
            '-rdynamic',
        ],
    ),
    cmdoption.LINKER_TYPE_MSVC : _generateFlags(
        common = [
            '/NOLOGO',
            '/DYNAMICBASE',
            '/NXCOMPAT',
        ],
        release = [
            '/OPT:REF',
            '/OPT:ICF',
            '/LTCG',
        ],
    ),
}

_DEFINES = {
    cmdoption.COMPILER_TYPE_CLANG : _generateFlags(
        common = [
            'COMPILER_TYPE_CLANG',
        ],
        debug = [
            'DEBUG',
        ],
    ),
    cmdoption.COMPILER_TYPE_MSVC : _generateFlags(
        common = [
            'COMPILER_TYPE_MSVC',
        ],
        debug = [
            'DEBUG',
        ],
    ),
}

def options( _context ):
    for KEY, OPTION in cmdoption.OPTIONS.items():
        _context.add_option(
            _optionKey( KEY ),
            type = OPTION[ cmdoption.TYPE ],
            default = OPTION[ cmdoption.DEFAULT ],
        )

    _context.load( 'compiler_cxx' )

def _optionKey(
    _KEY
):
    return '--' + _KEY

def configure( _context ):
    _configureBuild( _context )
    _configureCompiler( _context )
    _configureLinker( _context )
    _configureCxxflags( _context )
    _configureLinkflags( _context )
    _configureIncludes( _context )
    _configureDefines( _context )
    _configureImpls( _context )

    _context.load( 'compiler_cxx' )

def _configureBuild( _context ):
    BUILD = _context.options.build

    _context.msg(
        cmdoption.BUILD,
        BUILD,
    )

    if BUILD == cmdoption.BUILD_DEBUG:
        return
    if BUILD == cmdoption.BUILD_RELEASE:
        return

    _context.fatal( '非対応のビルドタイプ' )

def _configureCompiler( _context ):
    COMPILER_TYPE = _context.options.compilertype

    _context.msg(
        cmdoption.COMPILER_TYPE,
        COMPILER_TYPE,
    )

    _context.env.MY_COMPILER_TYPE = COMPILER_TYPE

def _configureLinker( _context ):
    LINKER_TYPE = _context.options.linkertype

    _context.msg(
        cmdoption.LINKER_TYPE,
        LINKER_TYPE,
    )

    _context.env.MY_LINKER_TYPE = LINKER_TYPE

def _configureCxxflags( _context ):
    CXXFLAGS = _configureFlags(
        _context,
        _context.env.MY_COMPILER_TYPE,
        _CXXFLAGS_BASES,
    )

    _context.msg(
        'cxxflags',
        CXXFLAGS,
    )

    _context.env.MY_CXXFLAGS = CXXFLAGS

def _configureLinkflags( _context ):
    LINKFLAGS = _configureFlags(
        _context,
        _context.env.MY_LINKER_TYPE,
        _LINKFLAGS_BASES,
    )

    _context.msg(
        'linkflags',
        LINKFLAGS,
    )

    _context.env.MY_LINKFLAGS = LINKFLAGS

def _configureFlags(
    _context,
    _FLAGS_BASE,
    _FLAGS_BASES,
):
    flags = None
    if _FLAGS_BASE in _FLAGS_BASES:
        flags = _FLAGS_BASES[ _FLAGS_BASE ][ _context.options.build ]

    return flags

def _configureIncludes( _context ):
    FG_HEADERS = _context.options.fgheaders

    _context.msg(
        cmdoption.FG_HEADERS,
        FG_HEADERS,
    )

    FGPP_HEADERS = _context.options.fgppheaders

    _context.msg(
        cmdoption.FGPP_HEADERS,
        FGPP_HEADERS,
    )

    FG4CPP_HEADERS = _context.options.fg4cppheaders

    _context.msg(
        cmdoption.FG4CPP_HEADERS,
        FG4CPP_HEADERS,
    )

    INCLUDES = [
        os.path.abspath( i )
        for i in [
            common.INCLUDE_DIR,
            FG_HEADERS,
            FGPP_HEADERS,
            FG4CPP_HEADERS,
        ]
    ]

    _context.msg(
        'includes',
        INCLUDES,
    )

    _context.env.MY_INCLUDES = INCLUDES

def _configureDefines( _context ):
    defines = None
    COMPILER_TYPE = _context.env.MY_COMPILER_TYPE
    if COMPILER_TYPE in _DEFINES:
        defines = _DEFINES[ COMPILER_TYPE ][ _context.options.build ]

    _context.msg(
        'defines',
        defines,
    )

    _context.env.MY_DEFINES = defines

def _configureImpls( _context ):
    _configureStrconvImpl( _context )
    _configureBootImpl( _context )

def _configureStrconvImpl( _context ):
    STRCONV_IMPL = _context.options.strconvimpl

    _context.msg(
        cmdoption.STRCONV_IMPL,
        STRCONV_IMPL,
    )

    _context.env.MY_STRCONV_IMPL = STRCONV_IMPL

def _configureBootImpl( _context ):
    BOOT_IMPL = _context.options.bootimpl

    _context.msg(
        cmdoption.BOOT_IMPL,
        BOOT_IMPL,
    )

    _context.env.MY_BOOT_IMPL = BOOT_IMPL

def build( _context ):
    sucrose.build( _context )
