#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
void user(int ar[], int& size);
void personalinfo(int ar[], int& size) {
	int pin, x; string name;
back:
	cout << "Enter your name: ";
	cin >> name;
	cout << "Create your password:";
	cin >> x;
	cout << "Enter your password: ";
	cin >> pin;
	/*int count = 0;
	while ((pin != 1234) && (count < 5)) {
		cout << "Try agian!" << endl;

	}*/

	int count = 0;
	while (count < 5) {
		if (pin != x) {
			cout << "Try agian!" << endl;
			cin >> pin;
			count++;
		}
		else
		{
			user(ar, size);
		}
		goto back;
	}



	ofstream personInfo("info.txt");
	personInfo << name << " ";
	personInfo.close();
}
void showdestination() {
	ifstream destination;
	destination.open("booking.txt");
	string des[5];
	for (int i = 0; i <= 4; i++) {
		getline(destination, des[i]);
	}
	destination.close();
	cout << "*******************************************************" << endl;
	for (int i = 0; i <= 4; i++)
		cout << "                       " << des[i] << "                           " << endl;
	cout << "*******************************************************" << endl;
}
void source() {
	showdestination();
	int choice1;
	cout << "select your source : ";
	cin >> choice1;
	ofstream sourcedata("datasource.txt");
	sourcedata << choice1 << " ";
	sourcedata.close();
}
void destination() {
	showdestination();
	int choice2;
	cout << "select your destination :";
	cin >> choice2;
	ofstream dataDestination("dataset.txt");
	dataDestination << choice2 << " ";
	dataDestination.close();
}
void time() {
	ifstream time("time.txt");
	string des[5];
	int timechoice;
	for (int i = 0; i <= 4; i++) {
		getline(time, des[i]);
	}
	time.close();
	cout << "*******************************************************" << endl;
	for (int i = 0; i <= 4; i++) {
		cout << "                       " << des[i] << endl;
	}
	cout << "*******************************************************" << endl;
	cout << "please enter the time: ";
	cin >> timechoice;
	ofstream timimg("timing.txt");
	timimg << timechoice << " ";
	timimg.close();
}
void ticket() {
	ifstream ticketselect("ticket.txt");
	string tick[4];
	int ticketchoose;
	for (int i = 0; i <= 3; i++) {
		getline(ticketselect, tick[i]);
	}
	ticketselect.close();
	cout << "*******************************************************" << endl;
	cout << " First class   single   = 1200L.E " << endl;
	cout << " First class   return   = 2000L.E" << endl;
	cout << "Second class   single   = 600L.E" << endl;
	cout << "Second class   return  = 1000L.E" << endl;
	cout << "*********************************************************" << endl;
	cout << "                                                           " << endl;
	for (int i = 0; i <= 3; i++)
		cout << "                 " << tick[i] << "                      " << endl;

	cout << "*******************************************************" << endl;
	cout << "select type of ticket: ";
	cin >> ticketchoose;
	ofstream ticketData("dataticket.txt");
	ticketData << ticketchoose << " ";
	ticketData.close();
}
void print() {
	ifstream destination;
	destination.open("booking.txt");
	string des[5];
	for (int i = 0; i <= 4; i++) {
		getline(destination, des[i]);
	}
	destination.close();

	ifstream sourcedata("datasource.txt");
	int datasor;
	sourcedata >> datasor;
	sourcedata.close();
	//cout << des[datasor-1];

	ifstream dataDestination("dataset.txt");
	int datadest;
	dataDestination >> datadest;
	dataDestination.close();
	//cout << des[datadest-1];

	ifstream ticketselect("ticket.txt");
	string tick[4];
	for (int i = 0; i <= 3; i++)
		getline(ticketselect, tick[i]);
	ticketselect.close();

	ifstream ticketData("dataticket.txt");
	int dataticket;
	ticketData >> dataticket;
	ticketData.close();
	//cout<<tick[dataticket-1];

	ifstream time("time.txt");
	string timee[5];
	for (int i = 0; i <= 4; i++)
		getline(time, timee[i]);
	time.close();

	ifstream timing("timing.txt");
	int datatime;
	timing >> datatime;
	timing.close();

	ifstream prices1;
	prices1.open("prices.txt");
	string pr[4];
	for (int i = 0; i <= 3; i++) {
		getline(prices1, pr[i]);
	}


	//cout<<timee[datatime-1];
	cout << "*******************************************************" << endl;
	cout << "                     TICKET INFO                     " << endl;
	cout << "                                                     " << endl;
	cout << "      SOURCE:" << des[datasor - 1] << "              " << endl;
	cout << "                                                     " << endl;
	cout << "      DESTINATION:" << des[datadest - 1] << "        " << endl;
	cout << "                                                     " << endl;
	cout << "      TIME:" << timee[datatime - 1] << "           " << endl;
	cout << "                                                     " << endl;
	cout << "      CLASS AND TYPE:" << tick[dataticket - 1] << "  " << endl;
	cout << "                                                     " << endl;
	cout << "        prices:" << pr[dataticket - 1] << "  LE       " << endl;
	cout << "*******************************************************" << endl;

}
void del(int tick[], int& size) {
	if ((size < 0) || (size == 0)) {
		cout << "no tickets available" << endl;
	}
	else {
		for (int i = 0; i < size; i++)
		{
			tick[i];
		}
		size--;
		cout << "remaining tickets" << "   " << endl;
		cout << size << endl;
		cout << "one ticket is taken" << endl;

	}


}
void add(int tick[], int& size) {
	size++;
	cout << size << endl;
	ofstream numberoftickets("numbertickets.txt");
	numberoftickets << size << " ";
	numberoftickets.close();

}
//void read(int size) {
//	ifstream open("numbertickets.txt");
//	open >> size;
//	open.close();
//}

using namespace std;
void admin(int ar[], int& size) {
back2:
	cout << "*******************************************************" << endl;
	cout << "                                                       " << endl;
	cout << "                          ADMIN                        " << endl;
	cout << "                                                       " << endl;
	cout << "                          MENU                         " << endl;
	cout << "                                                       " << endl;
	cout << "                      1- ADD TICKET                    " << endl;
	cout << "                                                       " << endl;
	cout << "                      2-USER INFO                      " << endl;
	cout << "                                                       " << endl;
	cout << "*******************************************************" << endl;
	cout << "Enter your choice: " << endl;
	int num;
	int exitnumber = 999;
	char ans1;
	cin >> num;
	switch (num) {
	case 1:
		add(ar, size);
		cout << " Do You Want To Continue ? (Y/N)" << endl;
		cout << "Or switch to user?(U)" << endl;
		cin >> ans1;
		if (ans1 == 'y' || ans1 == 'Y') {
			admin(ar, size);
		}
		else if (ans1 == 'u' || ans1 == 'U') {
			user(ar, size);
		}

		else if (ans1 == 'n' || ans1 == 'N')
		{
			cout << "Thank You" << endl;
			exit(exitnumber); //if exitnum becomes =1 means the program is terminated successfully
		}

	case 2:
		print();
		add(ar, size);
		cout << " Do You Want To Continue ? (Y/N)" << endl;
		cout << "Or switch to user?(U)" << endl;
		cin >> ans1;
		if (ans1 == 'y' || ans1 == 'Y') {
			admin(ar, size);
		}
		else if (ans1 == 'u' || ans1 == 'U') {
			user(ar, size);
		}

		else if (ans1 == 'n' || ans1 == 'N')
		{
			cout << "Thank You" << endl;
			exit(exitnumber); //if exitnum becomes =1 means the program is terminated successfully
		}
	}
	goto back2;
}

using namespace std;
int main()
{

	int size = 20;
	/*read(size);*/
	int serag[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	cout << "*******************************************************" << endl;
	cout << "                                                     " << endl;
	cout << "             LOCAL  TRAIN TICKET  SYSTEM              " << endl;
	cout << "                                                     " << endl;
	cout << "                                                     " << endl;
	cout << "                                                     " << endl;
	cout << "                        MENU                          " << endl;
	cout << "                       1-USER                         " << endl;
	cout << "                       2-ADMIN                        " << endl;
	cout << "                                                     " << endl;
	cout << "*******************************************************" << endl;
	int x;
	cout << " Enter your choice: " << endl;
	cin >> x;
	switch (x) {
	case 1: {
		personalinfo(serag, size);
		user(serag, size);
	}
		  break;
	case 2:
		admin(serag, size);
		break;
	}
}
using namespace std;
void user(int ar[], int& size) {
	cout << "*******************************************************" << endl;
	cout << "                                                     " << endl;
	cout << "                         USER                        " << endl;
	cout << "                                                    " << endl;
	cout << "                         MENU                        " << endl;
	cout << "                                                     " << endl;
	cout << "                   1-BOOKING A TICKET                " << endl;
	cout << "                                                     " << endl;
	cout << "                 2-SHOW YOUR BOOKNG INFO             " << endl;
	cout << "                                                     " << endl;
	cout << "*******************************************************" << endl;
	cout << "Enter your choice: " << endl;
	int num;
	int exitnum = 999;
	char ans = 'N';
	cin >> num;
	switch (num) {
	case 1://cout << "Booking a ticket" << endl;
		source();
		destination();
		time();
		ticket();
		del(ar, size);
		print();
		cout << " Do You Want To Continue ? (Y/N)" << endl;
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			user(ar, size);
		}
		else if (ans == 'n' || ans == 'N')
		{
			cout << "Thank You" << endl;
			exit(exitnum); //if exitnum becomes =1 means the program is terminated successfully
		}

	case 2:
		print();
		cout << " Do You Want To Continue ? (Y/N)" << endl;
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
			main();
		else if (ans == 'n' || ans == 'N')
		{
			cout << "Thank You" << endl;
			exit(exitnum); //if exitnum becomes =1 means the program is terminated successfully
		}


	}
}