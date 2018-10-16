#!/bin/bash
cd ../couManager&&make
cd ../stuManager&&make
ar -rsv ../RELEASE/libstucou.a ../RELEASE/Link.o ../RELEASE/Course.o
cd ..
make


