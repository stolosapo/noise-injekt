#include <iostream>
#include "TestServiceFactory.h"
#include "TestService.h"

using namespace std;

TestServiceFactory::TestServiceFactory(): ServiceFactory()
{
    cout << "TestServiceFactory :: Initialized" << endl;
}

TestServiceFactory::~TestServiceFactory()
{
    cout << "TestServiceFactory :: Finalized" << endl;
}

NoiseInjekt::Service* TestServiceFactory::create()
{
    return (NoiseInjekt::Service*) new TestService;
}
