#include "Unity/src/unity.h"
#include "calc.c"

void testScalarAddition() {
    double result;
    result = ScalarAddition(&result);
}

int main(void) {
    UNITY_BEGIN();
    return UNITY_END();
}