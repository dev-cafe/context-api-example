from .cffi_helpers import get_lib_handle
import os
import sys


def get_env(v):
    _v = os.getenv(v)
    if _v is None:
        sys.stderr.write('ERROR: variable {0} is undefined\n'.format(v))
        sys.exit(1)
    return _v


_library_dir = os.path.join(get_env('ACCOUNT_BUILD_DIR'), 'lib')
_this_path = os.path.dirname(os.path.realpath(__file__))
_include_dir = _this_path

c_lib = get_lib_handle(['-DACCOUNT_API=', '-DACCOUNT_NOINCLUDE'],
                       'account.h',
                       'c_account',
                       _library_dir,
                       _include_dir)

f_lib = get_lib_handle(['-DACCOUNT_API=', '-DACCOUNT_NOINCLUDE'],
                       'account.h',
                       'fortran_account',
                       _library_dir,
                       _include_dir)
