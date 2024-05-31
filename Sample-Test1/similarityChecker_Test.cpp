#include "pch.h"
#include <string>
#include "../StringGame/similarityChecker.cpp"
using namespace std;

class SimilarityCheckerFixture : public testing::Test {
public:
    void checkScore(string str1, string str2, int expectedScroe) {
        SimilarityChecker checker;
        int actualScore = checker.similarityCheck(str1, str2);
        EXPECT_EQ(expectedScroe, actualScore);
    }
};

TEST_F(SimilarityCheckerFixture, SameStringChecker) {
    checkScore("ACCTET", "ACCTET", 100);
}

TEST_F(SimilarityCheckerFixture, LengthChecker1) {
    checkScore("DDD", "BBB", 60);
}

TEST_F(SimilarityCheckerFixture, LengthChecker2) {
    checkScore("DDD", "BBBAAAA", 0);
}

TEST_F(SimilarityCheckerFixture, LengthChecker3) {
    checkScore("DDDDDD", "BBBAA", 48);
}

TEST_F(SimilarityCheckerFixture, LengthChecker4) {
    checkScore("BA", "BBBAA", 0);
}

TEST_F(SimilarityCheckerFixture, LengthChecker5) {
    checkScore("DDD", "BBBAA", 20);
}