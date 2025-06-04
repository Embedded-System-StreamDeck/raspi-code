#!/bin/bash
# ARM64 ve eski sistemler için derleme scripti
set -e
mkdir -p build
cd build
cmake ..
make -j$(nproc)
