#include "TurtleProgram.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	TurtleProgram* tp1 = new TurtleProgram();
	TurtleProgram* tp2 = new TurtleProgram("F", "10");
	TurtleProgram* tp3 = new TurtleProgram(*tp1);
	TurtleProgram* tp4 = new TurtleProgram();
	*tp4 = *tp2;
	TurtleProgram* tp5 = new TurtleProgram("R", "90");

	cout << "tp1: " << *tp1 << endl;
	cout << "tp2: " << *tp2 << endl;
	cout << "tp3: " << *tp3 << endl;
	cout << "tp4: " << *tp4 << endl;
	cout << "tp5: " << *tp5 << endl;

	cout << "tp4 != tp5: " << (tp4 != tp5) << endl;
	cout << "tp2 == tp4: " << (tp2 == tp4) << endl;
	cout << "tp4 == tp5: " << (tp4 == tp5) << endl;

	cout << "length of tp4: " << tp4->getLength() << endl;
	cout << "string at index 0 of tp2 is: " << tp2->getIndex(0) << endl;
	cout << "tp2: " << *tp2 << endl;
	tp2->setIndex("R", 0);
	cout << "modified tp2: " << *tp2 << endl;

	cout << "action 1 in main" << endl;
	*tp1 = *tp2 + *tp5;

	cout << "tp2 + tp5: " << *tp1 << endl;

	cout << "action 2 in main" << endl;
	*tp2 += *tp5;
	cout << "tp2 += tp5: " << *tp2 << endl;

	cout << "action 3" << endl;
	*tp4 = *tp5 * 4;
	cout << "tp5 * 4: " << *tp4 << endl;

	cout << "action 4" << endl;
	*tp5 *= 4;
	cout << "tp5 *= 4: " << *tp5 << endl;

	delete tp1;
	delete tp2;
	delete tp3;
	delete tp4;
	delete tp5;

	return 0;
}
