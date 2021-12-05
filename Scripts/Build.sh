#!/bin/sh

mkdir Build
cd Build
cmake .. && make -j || echo "You errored out. Sorry"
cd ..
./Build/bin/PostageStampProblemInterface
