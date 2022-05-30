#include <iostream>
#include "TestService.h"

using namespace std;

TestService::TestService(): Service()
{
    cout << "TestService :: Initialized" << endl;
}

TestService::~TestService()
{
    cout << "TestService :: Finalized" << endl;
}

void TestService::test()
{
    cout << "This is a Service Test" << endl;
}
