#include "pch.h"
#include "../StringGame/similarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;

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
	checkScore("TVB", "VBT", 40);
}

TEST_F(SimilarityCheckerFixture, EveryDifferentCharacter) {
	checkScore("ACF", "DGN", 0);
}

TEST_F(SimilarityCheckerFixture, SomeSameAlphaBet) {
	checkScore("ACCTTT", "TDC", 20);
}

TEST_F(SimilarityCheckerFixture, SomeSameAlphaBet2) {
	checkScore("ACCTTT", "TDCT", 20);
}

TEST_F(SimilarityCheckerFixture, InvalidAlphaBet1) {
	assertIllegalArgument("ACCTTT", "cDC");
}

TEST_F(SimilarityCheckerFixture, InvalidAlphaBet2) {
	assertIllegalArgument("cCTTT", "CVE");
}