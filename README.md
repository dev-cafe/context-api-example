[![Build Status](https://travis-ci.org/bast/context-api-example.svg?branch=master)](https://travis-ci.org/bast/context-api-example/builds)
[![License](https://img.shields.io/badge/license-%20BSD--3-blue.svg)](../master/LICENSE)


# context-api-example

Shows how to implement and use context-aware APIs in C++, Fortran, and Python.
Inspired by Armin Ronacher's
["Beautiful Native Libraries"](http://lucumr.pocoo.org/2013/8/18/beautiful-native-libraries/).


## How to build and run this demo

```
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
mkdir build
cd build
cmake ..
make
cd ..
PROJECT_BUILD_DIR=$PWD/build PROJECT_INCLUDE_DIR=$PWD/api PYTHONPATH=$PWD/api py.test test/test.py
```


## File description

```
.
|-- api
|   |-- example.h   (C interface)
|   `-- example.py  (Python interface)
|-- src
|   |-- bank.cpp    (C++ library)
|   |-- bank.f90    (Fortran library)
|   `-- bank.h
`-- test
    |-- test.cpp    (C++ client)
    |-- test.f90    (Fortran client)
    `-- test.py     (Python client; automatically tested)
```
