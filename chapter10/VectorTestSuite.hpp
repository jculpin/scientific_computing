// VectorTestSuite.hpp

#include <cxxtest/TestSuite.h>
#include "Vector.hpp"
#include "Exception.hpp" 

class MyTestSuite1 : public CxxTest::TestSuite
{
public:
    void testVectors(void)
    {
        int vector_size = 3;
        Vector v1(vector_size);    
        v1[0] = 2.3;
        v1[1] = 4.5;
        v1[2] = 5.5;
        Vector v2(vector_size);
        v2(1) = 9.87;
        v2(2) = 23.12;
        v2(3) = 98.11;
        TS_ASSERT_EQUALS(v1[0], 2.3);
        TS_ASSERT_EQUALS(v1[1], 4.5);
        TS_ASSERT_EQUALS(v1[2], 5.5);
        TS_ASSERT_EQUALS(v1(1), 2.3);
        TS_ASSERT_EQUALS(v1(2), 4.5);
        TS_ASSERT_EQUALS(v1(3), 5.5);
        
        TS_ASSERT_EQUALS(v2[0], 9.87);
        TS_ASSERT_EQUALS(v2[1], 23.12);
        TS_ASSERT_EQUALS(v2[2], 98.11);
        TS_ASSERT_EQUALS(v2(1), 9.87);
        TS_ASSERT_EQUALS(v2(2), 23.12);
        TS_ASSERT_EQUALS(v2(3), 98.11);
        
        TS_ASSERT_THROWS_ANYTHING(v1[4]);
        TS_ASSERT_THROWS_EQUALS(v1[5], const Exception& e, e.getType(), "index");
    }
};

