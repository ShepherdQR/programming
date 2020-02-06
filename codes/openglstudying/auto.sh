#!/bin/bash
mkdir b2
cd b2
cmake ..
make -j8
ls
./main