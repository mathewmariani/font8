#!/bin/bash

echo "starting to do stuff"

# build and run font8
make font8
./font8 res/font8.png fonts/font8.h

# build and run render
make render
./render 65
