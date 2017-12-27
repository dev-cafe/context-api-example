from .cffi_helpers import get_lib_handle
import os
import sys


def get_env(v):
    _v = os.getenv(v)
    if _v is None:
        sys.stderr.write('ERROR: variable {0} is undefined\n'.format(v))
        sys.exit(1)
    return _v


build_dir = os.path.join(get_env('PROJECT_BUILD_DIR'), 'lib')
include_dir = get_env('PROJECT_INCLUDE_DIR')

c_lib = get_lib_handle(['-DACCOUNT_API=', '-DACCOUNT_NOINCLUDE'],
                       'account.h',
                       'c_account',
                       build_dir,
                       include_dir)

f_lib = get_lib_handle(['-DACCOUNT_API=', '-DACCOUNT_NOINCLUDE'],
                       'account.h',
                       'fortran_account',
                       build_dir,
                       include_dir)
