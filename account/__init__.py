from .cffi_helpers import get_lib_handle
import os
import sys


def get_env(v):
    _v = os.getenv(v)
    if _v is None:
        sys.stderr.write('ERROR: variable {0} is undefined\n'.format(v))
        sys.exit(1)
    return _v


build_dir = get_env('PROJECT_BUILD_DIR')
include_dir = get_env('PROJECT_INCLUDE_DIR')

c_lib = get_lib_handle(['-DEXAMPLE_API=', '-DEXAMPLE_NOINCLUDE'],
                       'example.h',
                       'c_example',
                       build_dir,
                       include_dir)

f_lib = get_lib_handle(['-DEXAMPLE_API=', '-DEXAMPLE_NOINCLUDE'],
                       'example.h',
                       'f_example',
                       build_dir,
                       include_dir)
