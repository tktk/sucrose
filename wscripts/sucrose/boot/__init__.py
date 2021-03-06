# -*- coding: utf-8 -*-

from wscripts.builder import buildShlib
from ..builder import getTargetName, getPackageString

MODULE_NAME = 'boot'
_TARGET = getTargetName( MODULE_NAME )

def build( _context ):
    buildShlib(
        _context,
        _TARGET,
        getPackageString(
            MODULE_NAME,
            _context.env.MY_BOOT_IMPL,
        ),
    )
