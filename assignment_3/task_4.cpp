#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	string word1;
	string word2;
	string word3;

	cout << "Write 3 words, followed by enter between each word" << endl;
	cin >> word1;
	cin >> word2;
	cin >> word3;

	string sentence = word1 + " " + word2 + " " + word3 + ".";

	int word1_length = word1.length();
	int word2_length = word2.length();
	int word3_length = word3.length();
	int sentence_length = sentence.length();

	cout << "word 1 length: " << word1_length << endl
		<< "word 2 length: " << word2_length << endl
		<< "word 3 length: " << word3_length << endl
		<< "sentence length: " << sentence_length << endl;

	string sentence2 = sentence;

	for (size_t i = 0; i < 3; i++) {
		sentence2[10 + i] = 'x';
	}

	cout << "Sentence 1: " << sentence << endl;
	cout << "Sentence 2: " << sentence2 << endl;

	string sentence_start = sentence.substr(0, 5);

	cout << "Sentence 1: " << sentence << endl;
	cout << "Sentence start: " << sentence_start << endl;

	size_t found = sentence.find("hallo");
	if (found != string::npos) {
		cout << "Found hallo in string" << endl;
	} else {
		cout << "Didn't find hello in string" << endl;
	}


	vector<size_t> positions;
	string to_search = "er";

	size_t pos = sentence.find(to_search);

	while (pos != string::npos) {
		positions.push_back(pos);
		pos = sentence.find(to_search, pos + to_search.size());
	}

	cout << to_search << " finnses paa posisjon: " << endl;
	for (size_t i = 0; i < positions.size(); i++) {
			cout << positions[i] << endl;
	}



	return 0;
}
