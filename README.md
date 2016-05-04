[![Build Status](https://travis-ci.org/bast/context-api-example.svg?branch=master)](https://travis-ci.org/bast/context-api-example/builds)
[![License](https://img.shields.io/badge/license-%20BSD--3-blue.svg)](../master/LICENSE)


# context-api-example

Shows how to implement context-aware APIs in different languages,
inspired by Armin Ronacher's
["Beautiful Native Libraries"](http://lucumr.pocoo.org/2013/8/18/beautiful-native-libraries/).


## How to build this demo

```
mkdir build
cd build
cmake ..
make
cd ..
PROJECT_BUILD_DIR=$PWD/build PROJECT_INCLUDE_DIR=$PWD/api PYTHONPATH=$PWD/api py.test test/test.py
```
