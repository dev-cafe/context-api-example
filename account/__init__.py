from .cffi_helpers import get_lib_handle
import os
import sys


def get_env(v):
    _v = os.getenv(v)
    if _v is None:
        sys.stderr.write('ERROR: variable {0} is undefined\n'.format(v))
        sys.exit(1)
    return _v


_this_path = os.path.dirname(os.path.realpath(__file__))

_library_dir = os.getenv('ACCOUNT_LIBRARY_DIR')
if _library_dir is None:
    _library_dir = os.path.join(_this_path, 'lib')

_include_dir = os.getenv('ACCOUNT_INCLUDE_DIR')
if _include_dir is None:
    _include_dir = os.path.join(_this_path, 'include')

c_lib = get_lib_handle(['-DACCOUNT_API=', '-DACCOUNT_NOINCLUDE'],
                       'account.h',
                       'account_cpp_implementation',
                       _library_dir,
                       _include_dir)

f_lib = get_lib_handle(['-DACCOUNT_API=', '-DACCOUNT_NOINCLUDE'],
                       'account.h',
                       'account_fortran_implementation',
                       _library_dir,
                       _include_dir)
