#include <tau/tau.h>
#include "resistor_temp.h"
#include "resistor.h"

TAU_MAIN()

TEST(TestSuiteName, TestName) {
    resistor r1(1e3);
    CHECK(r1.get_voltage(1e-3) == 1.0);
    CHECK(r1.get_curr(1.0) == 1e-3);
}

/*
Test(resistor, basics)
{
    resistor r1(1e3);
    CHECK(r1.get_voltage(1e3) == 1.0);
    CHECK(r1.get_curr(1.0) == 1e-3);

}

TEST(resitor_temp, basics)
{
    resistor_temp r_cu(4.3e-3, 1e3, 20.0);
    CHECK(r_cu.get_voltage(1e-3) == 1.0);
    CHECK()

}

*/
