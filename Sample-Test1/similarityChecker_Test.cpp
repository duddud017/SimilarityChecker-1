#include "pch.h"
#include <string>
#include "../StringGame/similarityChecker.cpp"
using namespace std;

class SimilarityCheckerFixture : public testing::Test {
	SimilarityChecker checker;
public:
	void checkScore(string str1, string str2, int expectedScroe) {
		int actualScore = checker.similarityCheck(str1, str2);
		EXPECT_EQ(expectedScroe, actualScore);
	}

	void assertIllegalArgument(string str1, string str2) {
		try {
			int actualScore = checker.similarityCheck(str1, str2);
			FAIL();
		}
		catch (std::exception e) {
			std::cout << e.what() << std::endl;
		}
	}
};

TEST_F(SimilarityCheckerFixture, SameStringChecker) {
	checkScore("ACCTET", "ACCTET", 100);
}


TEST_F(SimilarityCheckerFixture, EverySameAlphaBet) {
	checkScore("TVB", "VBT", 100);
}

TEST_F(SimilarityCheckerFixture, EveryDifferentCharacter) {
	checkScore("ACF", "DGN", 60);
}

TEST_F(SimilarityCheckerFixture, SomeSameAlphaBet) {
	checkScore("ACCTTT", "TDC", 20);
}

TEST_F(SimilarityCheckerFixture, SomeSameAlphaBet2) {
	checkScore("ACCTTT", "TDCT", 50);
}

TEST_F(SimilarityCheckerFixture, InvalidAlphaBet1) {
	assertIllegalArgument("ACCTTT", "cDC");
}

TEST_F(SimilarityCheckerFixture, InvalidAlphaBet2) {
	assertIllegalArgument("cCTTT", "CVE");
}

TEST_F(SimilarityCheckerFixture, SameStringChecker2) {
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
    checkScore("BA", "BBBAA", 40);
}

TEST_F(SimilarityCheckerFixture, LengthChecker5) {
    checkScore("DDD", "BBBAA", 20);
}

