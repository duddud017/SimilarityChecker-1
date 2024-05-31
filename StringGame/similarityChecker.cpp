#include <string>
using namespace std;

class SimilarityChecker {
public:
	int similarityCheck(string str1, string str2) {
		if (str1 == str2)
			return 100;

		return calculateCharacterNumberScore(str1, str2);
	}

	int calculateCharacterNumberScore(std::string& str1, std::string& str2)
	{
		int result = 0;

		if (str1.size() == str2.size())
			return 60;

		int shortLength = smallNumber((int)str1.size(), (int)str2.size());
		int longLength = biggerNumber((int)str1.size(), (int)str2.size());

		if (checkInvalidStringNumber(longLength, shortLength))
			return 0;

		result = (((2 * shortLength) - longLength) * 60) / shortLength;
		return result;
	}

	bool checkInvalidStringNumber(int longLength, int shortLength)
	{
		return longLength > (shortLength * 2);
	}

private:
	int biggerNumber(int a, int b) { if (a > b)return a; else return b; }
	int smallNumber(int a, int b) { if (a <  b)return a; else return b; }
};