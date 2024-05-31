#include <string>
#include <stdexcept>
using namespace std;

class SimilarityChecker {
public:
	int similarityCheck(string str1, string str2) {
		if (str1 == str2)
			return 100;

		int result = calculateCharacterNumberScore(str1, str2);
		result += calculateSameAlphabetScore(str1, str2);

		return result;
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

	int calculateSameAlphabetScore(std::string& str1, std::string& str2)
	{
		// 0 : is not exist, 1 : exist at str1, 2 : exist at str2
		int isCheckedCharacter[26] = { 0, };
		int sameCnt = 0;
		int totalCnt = 0;

		checkFirstStr(str1, isCheckedCharacter, totalCnt);
		checkSencondStr(str2, isCheckedCharacter, totalCnt, sameCnt);

		return (sameCnt * 40) / totalCnt;
	}

	void checkSencondStr(std::string& str2, int  isCheckedCharacter[26], int& totalCnt, int& sameCnt)
	{
		for (const char& ch : str2) {
			int index = ch - 'A';
			checkValidAlphabet(index);

			if (isCheckedCharacter[index] == 2)
				continue;

			if (isCheckedCharacter[index] == 0) totalCnt++;
			else	sameCnt++;

			isCheckedCharacter[index] = 2;
		}
	}

	void checkFirstStr(std::string& str1, int  isCheckedCharacter[26], int& totalCnt)
	{
		for (const char& ch : str1) {
			int index = ch - 'A';
			checkValidAlphabet(index);
			if (isCheckedCharacter[index] == 0) {
				isCheckedCharacter[index]++;
				totalCnt++;
			}
		}
	}

	void checkValidAlphabet(int index)
	{
		if (index < 0 || index >25)
			throw std::invalid_argument(" 입력 값은 Alphabet 대문자만 가능합니다. ");
	}

private:
	int biggerNumber(int a, int b) { if (a > b)return a; else return b; }
	int smallNumber(int a, int b) { if (a <  b)return a; else return b; }
};
