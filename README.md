[![Build Status](https://travis-ci.org/bast/context-api-example.svg?branch=master)](https://travis-ci.org/bast/context-api-example/builds)
[![License](https://img.shields.io/badge/license-%20MPL--v2.0-blue.svg)](../master/LICENSE)


# context-api-example

Shows how to implement and use context-aware APIs in C++, Fortran, and Python.
Inspired by Armin Ronacher's
["Beautiful Native Libraries"](http://lucumr.pocoo.org/2013/8/18/beautiful-native-libraries/).

Comments, contributions, and improvements are most welcome!


## How to build and run this demo

### Install Python dependencies

```shell
$ virtualenv venv
$ source venv/bin/activate
$ pip install -r requirements.txt
```

### Configure and build the compiled code

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Test the C++/Fortran interfaces

```shell
$ make test
```

### Test the Python interface

```shell
$ PROJECT_BUILD_DIR=$PWD/build PROJECT_INCLUDE_DIR=$PWD/api PYTHONPATH=$PWD/api pytest -vv test/test.py
```


## File description

```
.
|-- CMakeLists.txt
|-- LICENSE
|-- README.md
|-- api
|   |-- cffi_helpers.py  (CFFI boilerplate code)
|   |-- example.h        (C interface)
|   `-- example.py       (Python interface)
|-- requirements.txt
|-- account
|   |-- account.cpp      (C++ library)
|   |-- account.f90      (Fortran library)
|   `-- account.h        (C++ library)
`-- test
    |-- test.cpp         (C++ client)
    |-- test.f90         (Fortran client)
    `-- test.py          (Python client)
```
