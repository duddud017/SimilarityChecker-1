#include <string>
#include <stdexcept>
using namespace std;

class SimilarityChecker {
public:
	int similarityCheck(string str1, string str2) {
		if (str1 == str2)
			return 100;

		return calculateSameAlphabetScore(str1, str2);
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
			throw std::invalid_argument(" �Է� ���� Alphabet �빮�ڸ� �����մϴ�. ");
	}
};

