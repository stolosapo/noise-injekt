#ifndef TestServiceFacory_h__
#define TestServiceFacory_h__

#include <noiseinjekt/Service.h>

class TestServiceFactory: public NoiseInjekt::ServiceFactory
{
public:
    TestServiceFactory();
    virtual ~TestServiceFactory();
    virtual NoiseInjekt::Service* create();
};

#endif // TestServiceFacory_h__
