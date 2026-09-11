#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// Author: Maxim Keene
string toLowerCase(string text)

{ 
	for (char& character : text)
	{
		character = static_cast<char>(tolower(static_cast<unsigned char>(character)));
	}

	return text;
}

// Author: Maxim Keene
vector <string> loadDictionary(const string& dictionaryFileName)

{
	vector<string> dictionaryWords;
	ifstream dictionatyFile(dictionaryFileName);

	if (!dictionatyFile)
	{
		cerr << "Error: Could not open the dictionary file."
			<< dictionaryFileName << endl;
			return dictionaryWords;
	}

	string word;

	while (dictionatyFile >> word)
	{
		dictionaryWords.push_back(toLowerCase(word));
	}

	dictionatyFile.close();
	return dictionaryWords;
}

// Author: Maxim Keene
bool isDictionaryWord(const vector<string>& dictionaryWords, const string& word)
{
	return binary_search(dictionaryWords.begin(), dictionaryWords.end(), word);
}

