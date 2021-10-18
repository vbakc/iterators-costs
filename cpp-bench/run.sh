#!/bin/bash

mkdir -p build && pushd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --target bench
popd
