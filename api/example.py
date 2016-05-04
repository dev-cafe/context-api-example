def get_env(v):
    import sys
    import os
    _v = os.getenv(v)
    if _v is None:
        sys.stderr.write('Error: Environment variable {0} is undefined\n'.format(v))
        sys.exit(1)
    return _v


def get_library_suffix():
    import sys
    if sys.platform == "darwin":
        return 'dylib'
    else:
        return 'so'


def get_lib_handle(definitions, header, library, build_dir, include_dir):
    import os
    from subprocess import Popen, PIPE
    from cffi import FFI
    ffi = FFI()

    interface = Popen(['cc', '-E'] + definitions + [os.path.join(include_dir, header)],
                      stdout=PIPE).communicate()[0].decode("utf-8")
    ffi.cdef(interface)

    suffix = get_library_suffix()
    lib = ffi.dlopen(os.path.join(build_dir, 'lib{0}.{1}'.format(library, suffix)))
    return lib


build_dir = get_env('PROJECT_BUILD_DIR')
include_dir = get_env('PROJECT_INCLUDE_DIR')

#c_lib = get_lib_handle(['-DEXAMPLE_API=', '-DEXAMPLE_NOINCLUDE'],
#                       'example.h',
#                       'c_example',
#                       build_dir,
#                       include_dir)

f_lib = get_lib_handle(['-DEXAMPLE_API=', '-DEXAMPLE_NOINCLUDE'],
                       'example.h',
                       'f_example',
                       build_dir,
                       include_dir)
