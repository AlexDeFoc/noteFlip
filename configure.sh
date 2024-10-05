#!/bin/bash

cmake -DCMAKE_C_FLAGS="-w" -S . -B build -G "Unix Makefiles"
