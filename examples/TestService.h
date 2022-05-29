#ifndef TestService_h__
#define TestService_h__

#include <noiseinjekt/Service.h>

class TestService: public NoiseInjekt::Service
{
public:
    TestService();
    virtual ~TestService();
    void test();
};

#endif // TestService_h__
