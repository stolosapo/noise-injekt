#include <iostream>
#include "TestService.h"

using namespace std;

TestService::TestService(): Service()
{

}

TestService::~TestService()
{

}

void TestService::test()
{
    cout << "This is a Service Test" << endl;
}