#include <iostream>
#include "TestServiceFactory.h"
#include "TestService.h"

using namespace std;

TestServiceFactory::TestServiceFactory(): ServiceFactory()
{

}

TestServiceFactory::~TestServiceFactory()
{

}

NoiseInjekt::Service* TestServiceFactory::create()
{
    return (NoiseInjekt::Service*) new TestService;
}