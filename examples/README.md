# example of using `noiseinjekt` lib

## build example
```bash
g++ -g -c -o example.o example.cpp
g++ -g -c -o TestService.o TestService.cpp
g++ -g -c -o TestServiceFactory.o TestServiceFactory.cpp
g++ example.o TestService.o TestServiceFactory.o -o example -lnoiseinjekt
./example
```
