# -*- coding: utf-8 -*-

from .. import common
from ..builder import getTargetName as getTargetNameCommon
from ..builder import getPackageString as getPackageStringCommon

def getTargetName(
    _moduleName,
):
    return getTargetNameCommon(
        common.FG,
        _moduleName,
    )

def getPackageString(
    *_args
):
    return getPackageStringCommon(
        common.SUCROSE,
        _args
    )
