# !/bin/bash
set -e

rm -fr `pwd`/build/*
cd `pwd`/build &&
    cmake .. &&
    make
cd ..
cp -r `pwd`/src/include `pwd`/lib