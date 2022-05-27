#ifndef ServiceFactory_h__
#define ServiceFactory_h__

#include <string>

#include "Service.h"

using namespace std;

class ServiceFactory
{
private:
    string implementationSelection;

public:
    ServiceFactory();
    ServiceFactory(string implementationSelection);
    virtual ~ServiceFactory();

    virtual Service* create() = 0;

};

#endif // ServiceFactory_h__