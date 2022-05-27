#!/bin/sh

g++ -g -c -o main.o main.cpp
g++ -g -c -o MainTestSuite.o MainTestSuite.cpp
g++ -g -c -o Service.o ../src/Service.cpp
g++ -g -c -o ServiceFactory.o ../src/ServiceFactory.cpp

g++ main.o \
    MainTestSuite.o \
    -o tester -lnoisetest

./tester
