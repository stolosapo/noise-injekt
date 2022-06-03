# noiseinjekt
A simple C++ library that implements dependecy injection.

![GitHub release (latest by date)](https://img.shields.io/github/v/release/stolosapo/noise-injekt)

![Build](https://github.com/stolosapo/noise-injekt/actions/workflows/makefile.yml/badge.svg) 

### Prepare compilation
```bash
./autogen.sh
```

### Installation
```bash
./configure
make
sudo make install
sudo ldconfig /usr/local/lib
```

### Uninstallation
```bash
sudo make uninstall
```

### Run
```bash
noiseinjekt
```

## Clean all untracked files
```bash
git clean -xdf
```

### Use Library
If everything installed fine then pass `-lnoiseinjekt` parameter in linker, when build your application.
Then use it in your app like in `example/`.


## How to use in the code

### Step 1: Prepare the wanted `service`.

The object that we want to inject has to implement `Service` interface.
The `Service` interface can be included from `<noiseinjekt/Service.h>`.

Then we must create a factory class that creates a new instance of the 
wanted class. The factory must implement the `ServiceFactory` interface. 
Again this interface can be included from `<noiseinjekt/Service.h>`.

see `examples/TestServiceFactory.h` and `examples/TestService.h` for example. 
The class `TestService` extends `Service`. 
Also the `TestServiceFactory` extends `ServiceFactory`.

### Step 2: Register `service`.

Then we must register the new `service` to tha `globalAppContext`.

Then first we have to create a method that has the specific signature:
```c++
void funcExample(int argc, char* argv[])
{
    NoiseInjekt::registerGlobalService<TestServiceFactory>(SINGLETON, "TestService", new TestServiceFactory);
}
```
inside that function we have to register our new `service` calling the following
```c++
NoiseInjekt::registerGlobalService<TestServiceFactory>(SINGLETON, "TestService", new TestServiceFactory);
```
this can be included from `<noiseinjekt/GlobalAppContext.h>`.

The method `registerGlobalService` is a template method and takes as type 
the factory class of `service` that we want to inject.
as first param takes the `InjectionScope` of the service.
the scopes can be one of: `SINGLETON`, `REQUEST`, `START_UP`.
as second param takes the name of the service. With this name we can 
access again the wanted `service`. 
As thrird param takes a new pointer to the factory that creates 
the wanted service.

> No need to worry about this new pointer to the factory, because is gonna be
> disposed when `GlobalAppContext` destroyed, that is in the end of program.


`globalAppContext` is the context of the whole application. This context
initialized first of everything in the `main` and contains all `services`.

In order to register the wanted service we must add it in the 
`GlobalAppContextRegistration.cpp` file in the `src/lib/di/` folder.

### Step 3: Injection

After all these we can inject the wanted `service`.

in the file that we want out `service` we must include `<noiseinjekt/GlobalAppContext.h>`. 
Then we can call the `NoiseInjekt::inject< T >` method.

This method is a template method. As type takes the wanted `service` type.
As parameter takes the name of the wanted `service`, as we register in Step 2.
And returns a pointer the wanted `service`.

like this:
```c++
TestService* srv = NoiseInjekt::inject<TestService>("TestService");
```

# `InjectionScope`

There are three injection scopes for the application.

### `SINGLETON`
This means that the first time that a wanted `service` will be injected,
then it will be initialized with the `ServiceFactory`. All the rest
of the times that will be injected the same reference of the `service`
will be returned.

### `REQUEST`
This means that every time that a `service` will be injected,
every time a new instance of this `service` will be created.

### `START_UP`
This means that the `service` will be intantiated on the start up of the 
application and inject method will return the same reference of this `service`.
