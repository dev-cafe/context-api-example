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
$ ACCOUNT_LIBRARY_DIR=$PWD/build/lib ACCOUNT_INCLUDE_DIR=$PWD/account PYTHONPATH=$PWD pytest -vv test/test.py
```
