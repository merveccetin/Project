#include <gtest/gtest.h>
#include <cmath>
extern "C" {
    #include "../src/math/deneme.h"  // math.h dosyasının yolu
}
class MyCodeTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

};


TEST_F(MyCodeTest, ToplamaDogruCalisir) {
    EXPECT_EQ(topla(2, 3), 5);
}

TEST_F(MyCodeTest, Cikarma)
{
    EXPECT_EQ(cikar(5,3),2);
}