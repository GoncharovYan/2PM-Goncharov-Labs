#include <iostream>
#include <map>
using namespace std;

int main()
{
	int QueCount; //Count of questions
	cin >> QueCount;

	map<int, bool> Ans;
	int tmp;
	for (int i = 0; i < QueCount; i++) { //Writing the correct answers to the tree
		cin >> tmp;
		Ans.insert(pair<int, bool>(tmp, true));
	}

	int StudsCount; //Count of studs
	cin >> StudsCount;

	int StudAnswers; //Count of studs answers
	int CorrectAnswers = 0; //Count of studs correct answers
	int answer;

	for (int i = 0; i < StudsCount; i++) { //Each student
		cin >> StudAnswers; //Enter the count of stud answers
		for (int i = 0; i < StudAnswers; i++) { 
			cin >> answer; //Enter the i answer
			if (Ans[answer])
				CorrectAnswers++;
		}
		cout << CorrectAnswers << endl;
		CorrectAnswers = 0;
	}
	
	return 0;
}