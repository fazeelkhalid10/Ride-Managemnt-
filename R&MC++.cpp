#include<iostream>
#include<fstream>
#include<sstream>
#include<conio.h>
#include<string>
#include<cstdlib>
#include<Windows.h>
using namespace std;
class Name
{
private:
	char* fname;
	char* lname;
public:
	Name();
	Name(char* fN, char* lN);
	Name(const Name&);
	char* setter1();
	char* setter2();
	void getter();
	friend ostream& operator<<(ostream& out, const Name& n);
	~Name();
};
Name::Name()
{
	fname = new char[20];
	lname = new char[20];

}
Name::Name(char* fN, char* lN)
{
	fname = fN;
	lname = lN;
}
Name::Name(const Name& f)
{
	fname = new char[20];
	lname = new char[20];
	fname = f.fname;
	lname = f.lname;
}
char* Name::setter1()
{
	return fname;
}
char* Name::setter2()
{
	return lname;
}
void Name::getter()
{
	cout << "\nYour First Name:\n" << fname;
	cout << "\nYour Last Name:\n" << lname;
}
Name::~Name()
{
	delete[]fname;
	delete[] lname;
}
ostream& operator<<(ostream& out, const Name& n)
{
	out << n.fname << " " << n.lname << endl;
	return out;
}
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int, int, int);
	int setday();
	int setmonth();
	int setyear();
	friend ostream& operator<<(ostream& out, const Date& m);
};
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int a, int b, int c)
{

	this->day = a;
	this->month = b;
	this->year = c;
}
int Date::setday()
{
	return day;
}
int Date::setmonth()
{
	return month;
}
int Date::setyear()
{
	return year;
}
ostream& operator<<(ostream& out, const Date& m)
{
	out << m.day << " / " << m.month << " / " << m.year;
	return out;
}
class mTime {
private:
	int hour;
	int min;
	int sec;
	friend ostream& operator<<(ostream& out, const mTime& n);
public:
	mTime();
	mTime(int, int, int);
	int setterh();
	int setterm();
	int setters();

};
mTime::mTime()
{
	hour = 0;
	min = 0;
	sec = 0;
}
mTime::mTime(int i, int j, int k)
{
	hour = i;
	min = j;
	sec = k;
}
int mTime::setterh()
{
	return hour;
}
int mTime::setterm()
{
	return min;
}
int mTime::setters()
{
	return sec;
}
ostream& operator<<(ostream& out, const mTime& n)
{
	out << n.hour << ":" << n.min << ":" << n.sec << endl;
	return out;
}
//composition is used
class Service
{
private:
	char* source;
	char* destination;
	float distance;
	Date bookingDate;
	mTime bookingTime;
	bool status;
	float fuelrate;
	int cID;
	int dID;
	int vID;
	int k, x, y, z;
public:
	Service();
	Service(char* s, char* d, float);
	int customerID()
	{
		int maximum;
		maximum = 100000000000;
		srand(time(0));
		cID = rand() % maximum;
		return cID;
	}
	void Dat()
	{
		int a, b, c;
		cout << "\n\Enter Date:\n";
		cout << "Enter Day :";
		cin >> a;
		cout << "\nEnter Month :";
		cin >> b;
		cout << "\nEnter year (2022 to 2025): ";
		cin >> c;
		if (a > 31 || b > 12 || c > 2025 || c < 2022)
		{
			while (a > 31 || b > 12 || c > 2025 || c < 2022)
			{
				cout << "\nInvalid input input agiain\n";
				cout << "Enter Day :";
				cin >> a;
				cout << "\nEnter Month :";
				cin >> b;
				cout << "\nEnter year (2022 to 2025: ";
				cin >> c;
			}
			Date bookingDate(a, b, c);
			cout << endl;
			cout << bookingDate;

		}
		else
		{
			Date bookingDate(a, b, c);
			cout << endl;
			cout << bookingDate;
		}
		x = a;
		y = b;
		z = c;
	}
	int setx()
	{
		return x;
	}
	int sety()
	{
		return y;
	}
	int setz()
	{
		return z;
	}
	void Tim()
	{
		int d, e, f;
		cout << "\nEnter Time\n";
		cout << "Enter Hours\n";
		cin >> d;
		cout << "Enter Minutes\n";
		cin >> e;
		cout << "Enter Seconds\n";
		cin >> f;
		if (d > 24 || e > 59 || f > 59)
		{
			while (d > 24 || e > 59 || f > 59)
			{
				cout << "\nInvalid Input\n";
				cout << "\nEnter Time\n";
				cout << "Enter Hours\n";
				cin >> d;
				cout << "Enter Minutes\n";
				cin >> e;
				cout << "Enter Seconds\n";
				cin >> f;
			}
			mTime bookingTime(d, e, f);
			cout << endl;
			cout << bookingTime;

		}
		else
		{
			mTime bookingTime(d, e, f);
			cout << endl;
			cout << bookingTime;

		}

	}
	void setter()
	{
		cout << "\nEnter Customer  id\n";
		cID = 0;
		cin >> cID;
		string name = to_string(cID);
		string x;
		string line;
		int flag = 0;
		fstream myfile;
		myfile.open("customerids.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				break;
			}

		}
		myfile.close();
		if (flag != 1)
		{
			cout << "\nCustomer Not found\n";
			setter();
		}
		if (flag == 1)
		{
			cin.ignore();
			cout << "\nEnTer Source 1.RIDE , 2.BOTH , 3.TRANSPORTATION:\n";
			cin >> k;;
			cout << "\nEnter Destination:\n";
			cin >> destination;
			cout << "\nEnter Distance:\n";
			cin >> distance;
		}
	}
	int souce()
	{
		return k;
	}
	char* destinatn()
	{

		return destination;
	}
	float dis()
	{
		return distance;
	}
	float fuel()
	{
		return fuelrate;
	}
	int customerid()
	{
		return cID;
	}
};

Service::Service()
{
	source = new char[10];
	destination = new char[10];
	distance = 0;
	fuelrate = 200;
	cID = 0;
	dID = 0;
	vID = 0;
}
Service::Service(char* s, char* d, float dis)
{
	source = s;
	destination = d;
	distance = dis;
}
//inheritance is being used
//setters of ride are being used
class Ride :public Service
{
	int noofPassengers;
	char* RideType;
	float DriverRanking;
	float VehicleRanking;
public:
	Ride()
	{
		RideType = new char[20];
		noofPassengers = 0;
		DriverRanking = 0;
		VehicleRanking = 0;
	}
	void TASK15()
	{
		cout << "FOR BOOKING A RIDE\n";
		setter();
		Dat();
		cout << "\nEnter noof passenger :\n";
		cin >> noofPassengers;
		cout << "\nRIDE TYPE::intracity or intercity\n";
		cin >> RideType;
		int q = customerid();
		if (souce() == 3)
		{
			float f;
			char a[10];
			cout << "\nEnter GOODSWEIGHT (kg) :\n";
			cin >> f;
			cout << "\nEnter Goodstype :\n";
			cin >> a;
			/*Delivery c(f, a);*/
			cout << "\nTHESE ARE AVAILABLE VEHICLE FOR YOU :\n\n";
			fstream newfile;
			cout << endl;
			newfile.open("CARTRANSPORT.txt", ios::in);
			if (newfile.is_open()) {
				string tp;
				while (getline(newfile, tp)) {
					cout << tp << "\n";
				}
				newfile.close();
			}
			string name, x, line, vid;
			cout << "\n\nEnter Vehicle Name\n";
			cin.ignore();
			getline(cin, name);
			cout << "\nEnter Vehicle id\n";
			cin.ignore();
			cin >> vid;
			cout << "\n\nThese ARE AVAILABLE DRIVERS\t:\n\n";
			fstream lfile;
			cout << endl;
			lfile.open("DRIVERTRANSPORTATION.txt", ios::in);
			if (lfile.is_open()) {
				string p;
				while (getline(lfile, p)) {
					cout << p << "\n";
				}
				lfile.close();
			}
			string choice, driverid;
			cout << "\n\nEnter Driver Name\n";
			cin.ignore();
			getline(cin, choice);
			cout << "\nEnter id of Driver\n";
			cin.ignore();
			cin >> driverid;
			fstream myfile;
			myfile.open("CARTRANSPORT1.txt");
			while (getline(myfile, line))
			{
				if (line.substr(0, name.size()) == name)
				{
					x = line;
					break;
				}

			}
			cout << endl;
			cout << "CHARGES PER KM :" << extractIntegerWords(x);
			int amount = 0;
			amount = extractIntegerWords(x) * dis();
			cout << "\nTotal amount :" << amount;
			myfile.close();
			cout << "\n\nYour Data getting Saved\n";
			ofstream uk;
			uk.open("DriverHistorylive.txt", ios::app);
			uk << "\n" << driverid << "\t" << choice;
			uk.close();
			ofstream fel;
			fel.open("Deliverysameday.txt", ios::app);
			fel << "\n" << setx() << "/" << sety() << "/" << setz() << "\t" << "Name:" << choice << "\tDestination:\t" << destinatn();
			fel.close();
			ofstream fe;
			fe.open("SameVehicle.txt", ios::app);
			fe << "\n" << vid << "\t" << name << "\tCustomer id:\t" << q;
			fe.close();
			ofstream fle;
			fle.open("ServiceHistoryVehicle.txt", ios::app);
			fle << "\n" << vid << "\t" << name << "\tRECENTSERVICE:" << destinatn() << "\tTotal Amount:" << amount;
			fle.close();
			ofstream fout;
			fout.open("CustomerHistory.txt", ios::app);
			fout << "\n" << q << " " << name << " " << "Total:" << amount << " " << destinatn() << " " << "Distance:" << dis();
			fout.close();
			ofstream file;
			file.open("CustomerHistorylive.txt", ios::app);
			file << "\n" << q << " " << name << " " << "Total:" << amount << " " << destinatn() << " " << "Distance:" << dis() << "status : 0" << "DATE:" << setx() << "/" << sety() << "/" << setz();
			file.close();
		}
		if (souce() == 1)
		{
			cout << "\n\nTHESE ARE AVAILABLE VEHICLE FOR YOU\n";
			fstream newfile;
			newfile.open("CARIDE.txt", ios::in);
			if (newfile.is_open()) {
				string tp;
				while (getline(newfile, tp)) {
					cout << tp << "\n";
				}
				newfile.close();
			}
			string name, x, line, vid;
			cout << "\n\nEnter Vehicles Name:\n";
			cin.ignore();
			getline(cin, name);
			cout << "\nEnter Vehicles id:\n";
			cin.ignore();
			cin >> vid;
			cout << "\n\nThese ARE AVAILABLE DRIVERS\t:\n";
			fstream lfile;
			cout << endl;
			lfile.open("DRIVERRIDE.txt", ios::in);
			if (lfile.is_open()) {
				string p;
				while (getline(lfile, p)) {
					cout << p << "\n";
				}
				lfile.close();
			}
			string choice, driverid;
			cout << "\n\nEnter Drivers Name:\n";
			cin.ignore();
			getline(cin, choice);
			cin.ignore();
			cout << "\nEnter Drivers I'D:\n";
			cin >> driverid;
			fstream myfile;
			myfile.open("CARIDE1.txt");
			while (getline(myfile, line))
			{
				if (line.substr(0, name.size()) == name)
				{
					x = line;
					break;
				}

			}
			cout << endl;
			cout << "CHARGES PER KM :" << extractIntegerWords(x);
			int amount = 0;
			amount = extractIntegerWords(x) * dis();
			cout << "\nTotal amount :" << amount;
			myfile.close();
			ofstream uk;
			uk.open("DriverHistorylive.txt", ios::app);
			uk << "\n" << driverid << "\t" << choice;
			uk.close();
			ofstream fe;
			fe.open("SameVehicle.txt", ios::app);
			fe << "\n" << vid << "\t" << name << "\tCustomer id:\t" << q;
			fe.close();
			ofstream fle;
			fle.open("ServiceHistoryVehicle.txt", ios::app);
			fle << "\n" << vid << "\t" << name << "\tRECENTSERVICE:" << destinatn() << "\tTotal Amount:" << amount;
			fle.close();
			cout << "\n\nYour Data getting Saved\n";
			ofstream fout;
			fout.open("CustomerHistory.txt", ios::app);
			fout << "\n" << q << " " << name << " " << "Total:" << amount << " " << destinatn() << " " << "Distance:" << dis();
			fout.close();
			ofstream file;
			file.open("CustomerHistorylive.txt", ios::app);
			file << "\n" << q << " " << name << " " << "Total:" << amount << " " << destinatn() << " " << "Distance:" << dis() << "status : 0" << "DATE:\t" << setx() << "/" << sety() << "/" << setz();
			file.close();
		}
		if (souce() == 2)
		{
			cout << "\n\nSearching A vehicle for you\n";
			cout << "\nTHESE ARE AVAILABLE VEHICLE FOR YOU\n";
			fstream newfile;
			newfile.open("CARBOTH.txt", ios::in);
			if (newfile.is_open()) {
				string tp;
				while (getline(newfile, tp)) {
					cout << tp << "\n";
				}
				newfile.close();
			}
			string name, x, line, vid;
			cout << "\n\nEnter Vehicles Name:\n";
			cin.ignore();
			getline(cin, name);
			cout << "\nEnter Vehicle Id:\n";
			cin >> vid;
			cout << "\n\nThese ARE AVAILABLE DRIVERS\t:\n\n";
			fstream lfile;
			cout << endl;
			lfile.open("DRIVERBOTH.txt", ios::in);
			if (lfile.is_open()) {
				string p;
				while (getline(lfile, p)) {
					cout << p << "\n";
				}
				lfile.close();
			}
			string choice, driverid;
			cout << "\n\nEnter Drivers Name:\n";
			cin.ignore();
			getline(cin, choice);
			cout << "\nEnter Drivers ID:\n";
			cin.ignore();

			fstream myfile;
			myfile.open("CARBOTH1.txt");
			while (getline(myfile, line))
			{
				if (line.substr(0, name.size()) == name)
				{
					x = line;
					break;
				}

			}
			cout << endl;
			cout << "CHARGES PER KM :" << extractIntegerWords(x);
			int amount = 0;
			amount = extractIntegerWords(x) * dis();
			cout << "\nTotal amount :" << amount;
			myfile.close();
			cout << "\n\nYour Data getting Saved\n";
			ofstream uk;
			uk.open("DriverHistorylive.txt", ios::app);
			uk << "\n" << driverid << "\t" << choice;
			uk.close();
			ofstream fe;
			fe.open("SameVehicle.txt", ios::app);
			fe << "\n" << vid << "\t" << name << "\tCustomer id:\t" << q;
			fe.close();
			ofstream fle;
			fle.open("ServiceHistoryVehicle.txt", ios::app);
			fle << "\n" << vid << "\t" << name << "\tRECENTSERVICE:" << destinatn() << "\tTotal Amount:" << amount;
			fle.close();
			ofstream fout;
			fout.open("CustomerHistory.txt", ios::app);
			fout << "\n" << q << " " << name << " " << "Total:" << amount << " " << destinatn() << " " << "Distance:" << dis();
			fout.close();
			ofstream file;
			file.open("CustomerHistorylive.txt", ios::app);
			file << "\n" << q << " " << name << " " << "Total:" << amount << " " << destinatn() << " " << "Distance:" << dis() << "status : 0" << "DATE:" << setx() << "/" << sety() << "/" << setz();
			file.close();


		}

	}
	void Task17()
	{
		system("cls");
		cin.ignore();
		string x, y;
		string line, name;
		int flag = 0;
		cout << "\n Enter the id of Customer  : ";
		cin >> name;
		cout << "\nEnter the id of Driver : ";
		cin.ignore();
		cin >> y;
		fstream myfile;
		myfile.open("CustomerHistorylive.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				x = line;
				break;
			}

		}
		myfile.close();
		if (flag != 1)
		{
			cout << "\nNO RIDE BOOKED\n";

		}
		if (flag == 1)
		{
			cout << "\nService booked :\n\n\n";
			cout << x;
			int l;
			cin.ignore();
			cout << "\n\nPRESS 1 to Completed Service\n";
			cin >> l;
			if (l == 1)
			{
				fstream ahm;
				ahm.open("Completedservice.txt", ios::app);
				ahm << "\n" << x;
				ahm.close();
				ifstream file;
				file.open("CustomerHistorylive.txt");
				ofstream temp;
				temp.open("temp.txt");
				while (getline(file, line))
				{
					if (line.substr(0, name.size()) != name)
						temp << line << endl;
				}
				file.close();
				temp.close();
				remove("CustomerHistorylive.txt");
				rename("temp.txt", "CustomerHistorylive.txt");
				ifstream fle;
				fle.open("DriverHistorylive.txt");
				ofstream temps;
				temps.open("temp.txt");
				while (getline(fle, line))
				{
					if (line.substr(0, y.size()) != y)
						temps << line << endl;
				}
				fle.close();
				temps.close();
				remove("DriverrHistorylive.txt");
				rename("temp.txt", "DriverHistorylive.txt");
			}
			string cdno;
			cout << "\nEnter MASTER CARD NUMBER For Payment\n";
			cin >> cdno;
			cin.ignore();
			cout << "\nYou Completed The service\n";
			DriverRanking = 0;
			cout << "\nGive Driver a rating :\n";
			cin >> DriverRanking;
			VehicleRanking = 0;
			cout << "\nGive Vehicle a Ranking :\n";
			cin >> VehicleRanking;
			cout << "\t\t\t\t\t\tTHANK YOU !";
			fstream alm;
			alm.open("DRIVERSERVICES.txt", ios::app);
			alm << "\n" << y << "\tRANK:" << DriverRanking << "\tCUSTOMER ID : " << x;
			alm.close();
		}
	}
	int extractIntegerWords(string str)
	{
		stringstream ss;
		ss << str;
		string temp;
		int found;
		while (!ss.eof()) {
			ss >> temp;
			if (stringstream(temp) >> found)
				temp = "";
		}
		return found;
	}

};
class Delivery :public Service
{
	float goodsweight;
	char* goodstype;
public:
	Delivery()
	{
		goodsweight = 0;
		goodstype = new char[10];
	}
	Delivery(float i, char* arr, char* r, char* y, float f) :Service(r, y, f)
	{
		i = goodsweight;
		for (int i = 0; i < 10; i++)
		{
			goodstype[i] = arr[i];
		}
	}
	int settergood();
	char* settergoods();

};
int Delivery::settergood()
{
	return goodsweight;
}
char* Delivery::settergoods()
{
	return goodstype;
}
class Person
{
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	Person()
	{
		Age = 0;
		Nid = 0;

	}
	Person(int i, int k)
	{
		Age = i;
		Nid = k;
	}
	int ag()
	{
		return Age;
	}
	void task1()
	{
		system("cls");
		char* first = new char[20];
		char* last = new char[20];
		int d, m, y;
		cout << "\nRegister Yorself\n";
		cout << "\nEnter First Name\n ";
		cin >> first;
		cout << "\nEnter Second Name\n";
		cin >> last;
		Name pName(first, last);
		cout << endl;
		cout << pName;
		cout << "\nEnter Date of Birth\n";
		cout << "\nEnter Day\n";
		cin >> d;
		cout << "\nEnter Month\n";
		cin >> m;
		cout << "\nEnter year\n";
		cin >> y;
		if (d > 31 || m > 12)
		{
			while (d > 31 || m > 12)
			{
				cout << "\nInvalid input input agiain\n";
				cout << "Enter Day :";
				cin >> d;
				cout << "\nEnter Month :";
				cin >> m;
				cout << "\nEnter year (2022 to 2025: ";
				cin >> y;
			}
			Date DOB(d, m, y);
			cout << endl;
			cout << DOB;

		}
		else
		{
			Date DOB(d, m, y);
			cout << endl;
			cout << DOB;
		}
		int age;
		cout << "\nEnter Your Age\n";
		cin >> age;
		Service c;
		Nid = c.customerID();
		cout << "\nYour ID\n";
		cout << Nid;
		cout << "\nYour Data getting Saved\n";
		ofstream fout;
		fout.open("Customer.txt", ios::app);
		fout << "\n" << first << " " << last;
		fout.close();
		ofstream id;
		id.open("customerids.txt", ios::app);
		id << "\n" << Nid << " " << first << " " << last;
		id.close();
		ofstream files;
		files.open("Record.txt", ios::app);
		files << "\n" << first << " " << last << "\t" << d << "/" << m << "/" << y << "\t" << age << "\t" << Nid;
		files.close();
		cout << "\nData Inserted Successfully\n";

	}



};
class Customer :public Person
{
private:
	int cID;
	Service** bookinghistory;
public:
	Customer();

};
//inheritance and polymorphism
class Driver :public Person
{
private:
	int dId;
	char** licenselist;
	int nooflicense;
	float overallranking;
	float sallary;
	int experience;
	int status;
	Service** serviceHistory;
public:
	Driver()
	{
		sallary = 0;
		nooflicense = 0;
		experience = 0;
		overallranking = 0;
		licenselist = new char* [50];
		for (int i = 0; i < 50; i++)
		{
			licenselist[i] = new char;
		}
	}
	Driver(float s, int e, float r, int i, int k, int l) :Person(i, k)
	{

		sallary = s;
		nooflicense = l;
		experience = e;
		overallranking = r;

	}
	int drivrID()
	{
		int maximum;
		maximum = 100000000000;
		dId = rand() % maximum;
		return dId;
	}
	void Task2()
	{
		char first[10];
		char second[10];
		cout << "\nEnter First Name of Driver\t:\n";
		cin >> first;
		cout << "\nEnter Second Name of Driver\t:\n";
		cin >> second;
		cout << "\nEnTer Source 1.RIDE , 2.BOTH , 3.TRANSPORTATION:\n";
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				licenselist[i][j];
			}
		}
		int k;
		cin >> k;
		int f;
		f = drivrID();
		cout << "\nYour I'D:\t" << f;
		if (k == 1)
		{
			ofstream fout;
			fout.open("DRIVERRIDE.txt", ios::app);
			fout << "\n" << f << "\tName:\t" << first << " " << second << "\tRanking:" << overallranking;
			fout.close();
		}
		if (k == 2)
		{
			ofstream fout;
			fout.open("DRIVERBOTH.txt", ios::app);
			fout << "\n" << f << "\tName:\t" << first << " " << second << "\tRanking:" << overallranking;
			fout.close();
		}
		if (k == 3)
		{
			ofstream fout;
			fout.open("DRIVERTRANSPORTATION.txt", ios::app);
			fout << "\n" << f << "\tName:\t" << first << " " << second << "\tRanking:" << overallranking;
			fout.close();
		}
		if (nooflicense == 1)
		{
			ofstream fout;
			fout.open("DRIVER1.txt", ios::app);
			fout << "\n" << first << " " << second << f;
			fout.close();
		}
		if (nooflicense > 1)
		{
			ofstream fout;
			fout.open("DRIVER1.txt", ios::app);
			fout << "\n" << first << " " << second;
			fout.close();
			ofstream file;
			file.open("DRIVER3.txt", ios::app);
			file << "\n" << first << " " << second << "\t No of Licence:" << nooflicense;
			file.close();
		}
		if (overallranking >= 4.5)
		{
			ofstream file;
			file.open("DRIVERATING.txt", ios::app);
			file << "\n" << first << " " << second << "\t Rating :" << overallranking;
			file.close();
			ofstream fout;
			fout.open("sallaryold.txt", ios::app);
			fout << "\n" << first << " " << second << "\t" << sallary;
			fout.close();
			float newsall = sallary + (15 * sallary / 100);
			ofstream ft;
			ft.open("sallarynew.txt", ios::app);
			ft << "\n" << first << " " << second << "\t" << newsall;
			ft.close();
		}

		ofstream files;
		files.open("Driver2.txt", ios::app);
		files << "\n" << f << first << " " << second << ",Sallary:" << sallary << ",Experience:" << experience << ",Ranking:" << overallranking << ",id:" << drivrID() << ",Age:" << ag();
		files.close();
		cout << "\nDriver Registered Successfully\n";

	}


};
class Feature
{
	int fId;
	char* description;
	float cost;
public:
	Feature()
	{
		fId = 0;
		*description = NULL;
		cost = 0;
	}
	void setter(int l, char* p, int c)
	{
		fId = l;
		description = p;
		cost = c;
	}
	int returnfid()
	{
		return fId;
	}
	int returncost()
	{
		return cost;
	}
	char* returndescript()
	{
		return description;
	}
	~Feature()
	{
		delete[] description;
	}

};
class Vehicle
{
	int vId;
	int type;
	int registrationNo;
	float avgMileage;
	char* LicenseType;
	bool status;
	char* fuletype;
	float overallranking;
	Date manufacturingdate;
	Feature* list;
	Service serviceHistory;
	string car;
	int d, m, y, c;
public:
	Vehicle()
	{
		vId = 0;
		registrationNo = 0;
		avgMileage = 0;
		LicenseType = new char[20];
		status = 0;
		fuletype = new char[20];
		overallranking = 0;
		d = 0;
		m = 0;
		y = 0;
	}
	void setter()
	{
		cout << "\nREGISTER YOUR CAR\n";
		cout << "Enter Car name:\n";
		cin >> car;
		cout << "Enter Vehicle id :\n";
		cin >> vId;
		cout << "\nENTER TYPE 1.RIDE 2.TRANSPORTATION 3.BOTH:\n";
		cin >> type;

		cin.ignore();
		cout << "\nEnter Registration Number :\n";
		cin >> registrationNo;
		cout << "\nEnter Average Milleage :\n";
		cin >> avgMileage;
		cout << "LICENSE \n";
		cin.ignore();
		cout << "1. Motorcar/jeep 2. Motorbike / rickshaw 3. LTV 4. HTV 5. Tractor(agricultural) 6. PSV 7. International driver's permit";
		cout << "\nEnter License TYPE  :\n";
		cin >> LicenseType;
		cout << "\nENTER FUEL TYPE  DIESEL OR  PETROL:\n";
		cin >> fuletype;
		cout << "\nEnter Overall Ranking\n";
		cin >> overallranking;
		cin.ignore();
		cout << "\nEnter Manufacturing Date\n";
		cout << "\nEnter Day\n";
		cin >> d;
		cout << "\nEnter Month\n";
		cin >> m;
		cout << "\nEnter year\n";
		cin >> y;
		if (d > 31 || m > 12)
		{
			while (d > 31 || m > 12)
			{
				cout << "\nInvalid input input agiain\n";
				cout << "Enter Day :";
				cin >> d;
				cout << "\nEnter Month :";
				cin >> m;
				cout << "\nEnter year (2022 to 2025: ";
				cin >> y;
			}
			Date manufacturingDate(d, m, y);
			cout << endl;
			cout << manufacturingDate;

		}
		else
		{
			Date manufacturingDate(d, m, y);
			cout << endl;
			cout << manufacturingDate;

		}
		cout << "\nEnter cost per KM\n";
		cin >> c;
		if (type == 1)
		{
			fstream only;
			only.open("CARIDE.txt", ios::app);
			only << "\n" << vId << "\t" << car << "\tRanking:" << overallranking;
			only.close();
			fstream files;
			files.open("CARIDE1.txt", ios::app);
			files << "\n" << car << "\t" << c;
			files.close();
		}
		if (type == 2)
		{
			fstream only;
			only.open("CARTRANSPORT.txt", ios::app);
			only << "\n" << vId << "\t" << car << "\tRanking:" << overallranking;
			only.close();
			fstream files;
			files.open("CARTRANSPORT1.txt", ios::app);
			files << "\n" << car << "\t" << c;
			files.close();
		}
		if (type == 3)
		{
			fstream only;
			only.open("CARBOTH.txt", ios::app);
			only << "\n" << vId << "\t" << car << "\tRanking:" << overallranking;
			only.close();
			fstream files;
			files.open("CARBOTH1.txt", ios::app);
			files << "\n" << car << "\t" << c;
			files.close();
		}
		fstream only;
		only.open("CAR1.txt", ios::app);

		only << "\n" << car << "\t VEHICLE TYPE:" << LicenseType;
		only.close();
		fstream files;
		files.open("CAR2.txt", ios::app);
		files << "\n" << car << "," << vId << "," << registrationNo << "," << avgMileage << "," << LicenseType << "," << fuletype << overallranking << "," << d << "/" << m << "/" << y << "," << c;
		files.close();
		cout << "\nCar Registered\n";
	}
	void TASK5()
	{
		cout << "\t\t\t\t\t\tThese are our VEHICLES\n";
		fstream newfile;
		newfile.open("CAR1.txt", ios::in);
		if (newfile.is_open()) {
			string tp;
			while (getline(newfile, tp)) {
				cout << tp << "\n";
			}
			newfile.close();
		}
		string line, name;
		cin.ignore();
		cout << "\nPlease Enter the name of vehicle you want to delete: ";
		cin >> name;
		ifstream myfile;
		myfile.open("CAR1.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) != name)
				temp << line << endl;
		}
		myfile.close();
		temp.close();
		remove("CAR1.txt");
		rename("temp.txt", "CAR1.txt");
		ifstream myfile1;
		myfile1.open("CAR2.txt");
		ofstream temp1;
		temp1.open("temp.txt");
		while (getline(myfile1, line))
		{
			if (line.substr(0, name.size()) != name)
				temp1 << line << endl;
		}
		cout << "The Vehicle with the name " << name << " has been deleted if it exsisted" << endl;
		myfile1.close();
		temp1.close();
		remove("CAR2.txt");
		rename("temp.txt", "CAR2.txt");
	}


};
class TMS
{
public:
	void welcome();
	void Disclaimer();
	void menu();
};
void TMS::welcome()
{
	system("COLOR 70");
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t_______    _______     _______   _________ " << endl;
	cout << "\t\t\t\t\t|         |       |   |              |    " << endl;
	cout << "\t\t\t\t\t|         |       |   |              |    " << endl;
	cout << "\t\t\t\t\t|_____    |_______|   |_______       |    " << endl;
	cout << "\t\t\t\t\t|         |       |           |      |    " << endl;
	cout << "\t\t\t\t\t|         |       |   ________|      |    " << endl;
	cout << endl << endl;
	cout << "\t\t\t\t ~~~  F A S T    T R A N S P O R T    S E R V I C E ~~~";
	cout << "\n\n\n\n\n\t\t\t\t\t\tPRESS C TO CONTINUE\n\n";
	char x = _getch();
	if (x == 'c')
	{
		system("CLS");
		Disclaimer();

	}
}
void TMS::Disclaimer()
{
	system("COLOR 07");
	ifstream fin;
	fin.open("Customer.txt", ios::in);
	char word[100], w[50], first[100];
	int c = 0;
	cout << "\n\n\n\n\n\t\t\t\t\tBEFORE MOVING ON ENTER YOURSELF\n\n\n\n\n\n";
	cout << "\nEnter Your First Name:\n";
	cin >> first;
	cin.ignore();
	cout << "\nEnter Your Last Name:\n";
	cin.get(w, 50);
	while (!fin.eof())
	{
		fin >> word;
		if (strcmp(word, w) == 0)
			c++;
	}
	if (c != 0)
		cout << "\nYou Are Already Registered Hello !" << first;
	else
		cout << "\nGet Registered yourself First\n";
	fin.close();
	char y;
	cout << "\n\n\n\n\t\t\t\t\t\tPRESS c TO CONTINUE\n";
	y = _getch();
	if (y == 'c')
	{
		system("cls");
		menu();
	}

}
void TMS::menu()
{
	system("cls");
	cout << "--------------------------------------- Welcome to Transport Managment System ------------------------------------------";
	cout << endl << endl;
	cout << "________________________________________________________________________________________________________________________";
	cout << "\n[1] Add a New Customer" << endl;
	cout << "[2] Add a New Driver" << endl;
	cout << "[3] Remove a Driver" << endl;
	cout << "[4] Add a New Vehicle" << endl;
	cout << "[5] Remove a Vehicle" << endl;
	cout << "[6] Print List of All Customers" << endl;
	cout << "[7] Print list of All Drivers" << endl;
	cout << "[8] Print list of All Vehicles with there Catrgory" << endl;
	cout << "[9] Print Detail & Service History of Vehicle" << endl;
	cout << "[10] Print History of a Customer" << endl;
	cout << "[11] Print History of a Driver with Services" << endl;
	cout << "[12] Print list of All Drivers with Ranking 4.5+" << endl;
	cout << "[13] Print List of All Drivers with Multiple licenses" << endl;
	cout << "[14] Print Updated Sallary of All Drivers" << endl;
	cout << "[15] Add a Service Request" << endl;
	cout << "[16] Cancel a Service" << endl;
	cout << "[17] Complete a Service" << endl;
	cout << "[18] Print Details of All customers who used Same vehicle" << endl;
	cout << "[19] Print list of All Drivers who Completed delivery  Same day" << endl;
	cout << "[20] Print Details of All pending Services on Particular Day" << endl;
	cout << "[21] Print Details of All pending services of  a particular driver" << endl;
	cout << "[22] Print Details of All cancelled services of a customer " << endl;
	cout << "[23] Any other Button to Exit Program" << endl;
	int x;
	cout << "\n\nYOUR Selection No::";
	cin.ignore();
	cin >> x;
	if (x == 1)
	{
		system("cls");
		Person obj(0, 0);
		obj.task1();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 2)
	{
		int e, n, o;
		float s, r;
		system("cls");
		cout << "\nREGISTER A DRIVER\n";
		cout << "\nEnter Experience in Years:\n";
		cin >> e;
		cout << "\nEnter No of license:\n";
		cin >> n;
		cout << "\nEnter Overall Ranking out of 5:\n";
		cin >> r;
		cout << "\nEnter Sallary:\n";
		cin >> s;
		cout << "\nEnter Age:\n";
		cin >> o;
		Driver c7(s, e, r, o, 0, n);
		c7.Task2();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 3)
	{
		system("cls");
		cout << "\t\t\t\t\t\tThese are our Drivers\n";
		fstream newfile;
		newfile.open("DRIVER1.txt", ios::in);
		if (newfile.is_open()) {
			string tp;
			while (getline(newfile, tp)) {
				cout << tp << "\n";
			}
			newfile.close();
		}
		string line, name;
		cout << "\nPlease Enter the name of DRIVER you want to delete: ";
		cin >> name;
		ifstream myfile;
		myfile.open("DRIVER1.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) != name)
				temp << line << endl;
		}
		myfile.close();
		temp.close();
		remove("DRIVER1.txt");
		rename("temp.txt", "DRIVER1.txt");
		ifstream myfile1;
		myfile1.open("Driver2.txt");
		ofstream temp1;
		temp1.open("temp.txt");
		while (getline(myfile1, line))
		{
			if (line.substr(0, name.size()) != name)
				temp1 << line << endl;
		}
		cout << "The Driver with the name " << name << " has been deleted if it exsisted" << endl;
		myfile1.close();
		temp1.close();
		remove("Driver2.txt");
		rename("temp.txt", "Driver2.txt");
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin.ignore();
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 4)
	{
		system("cls");
		Vehicle c8;
		c8.setter();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 5)
	{
		system("cls");
		Vehicle c9;
		c9.TASK5();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 6)
	{
		system("cls");
		cout << "\t\t\t\t\tThese are our Respected Customers\n";
		cout << endl << endl << endl << endl;
		fstream newfile;
		newfile.open("Customer.txt", ios::in);
		if (newfile.is_open()) {
			string tp;
			while (getline(newfile, tp)) {
				cout << tp << "\n";
			}
			newfile.close();
		}
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 7)
	{
		system("cls");
		cout << "\t\t\t\t\t\tThese are our Respected Drivers\n";
		fstream newfile;
		cout << endl << endl << endl << endl;
		newfile.open("DRIVER1.txt", ios::in);
		if (newfile.is_open()) {
			string tp;
			while (getline(newfile, tp)) {
				cout << tp << "\n";
			}
			newfile.close();
		}
		int i;
		cout << "\n\n\n\n\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 8)
	{
		system("cls");
		cout << "\t\t\t\t\t\tThese are our Latest Vehicles\n";
		fstream newfile;
		cout << endl << endl << endl << endl;
		newfile.open("CAR1.txt", ios::in);
		if (newfile.is_open()) {
			string tp;
			while (getline(newfile, tp)) {
				cout << tp << "\n";
			}
			newfile.close();
		}
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}

	}
	if (x == 9)
	{
		system("cls");
		cout << "\t\t\t\t\t\tThis is Vehicle History\n";
		cout << endl << endl << endl;
		string x;
		string line, name;
		int flag = 0;
		cout << "\nPlease Enter the Vehicle id : ";
		cin >> name;
		cout << endl << endl << endl;
		fstream myfile;
		myfile.open("ServiceHistoryVehicle.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				x = line;
				cout << x << endl;
			}

		}
		if (flag != 1)
		{
			cout << "\nNO History found\n";
		}
		myfile.close();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 10)
	{
		system("cls");
		cout << "\t\t\t\t\t\tThis is Customers History\n";
		cout << endl << endl << endl;
		string x;
		string line, name;
		int flag = 0;
		cout << "\nPlease Enter the id of Customer : ";
		cin >> name;
		cout << endl << endl << endl;
		fstream myfile;
		myfile.open("CustomerHistory.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				x = line;
				cout << x << endl;
			}

		}
		if (flag != 1)
		{
			cout << "\nCustomer Not found\n";
		}
		myfile.close();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}

	}
	if (x == 11)
	{
		system("cls");
		cout << "\t\t\t\t\tHistory of Driver with Services\n";
		cout << endl << endl << endl;
		string x;
		string line, name;
		int flag = 0;
		cout << "\nPlease Enter the id of Driver : ";
		cin >> name;
		cout << endl << endl << endl;
		fstream myfile;
		myfile.open("DRIVERSERVICES.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				x = line;
				cout << x << endl;
			}

		}
		if (flag != 1)
		{
			cout << "\nDriver Not found\n";
		}
		myfile.close();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 12)
	{
		system("cls");
		cout << "\t\t\t\t\t\tMost Rated Drivers\n";
		fstream newfile;
		cout << endl << endl << endl << endl;
		newfile.open("DRIVERATING.txt", ios::in);
		if (newfile.is_open()) {
			string tp;
			while (getline(newfile, tp)) {
				cout << tp << "\n";
			}
			newfile.close();
		}
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 13)
	{
		system("cls");
		cout << "\t\t\t\t\tThese are our MultiLicensed Drivers\n";
		fstream newfile;
		cout << endl << endl << endl << endl;
		newfile.open("DRIVER3.txt", ios::in);
		if (newfile.is_open()) {
			string tp;
			while (getline(newfile, tp)) {
				cout << tp << "\n";
			}
			newfile.close();
		}
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 14)
	{
		system("cls");
		cout << "\t\t\t\t\tThese are Selected Drivers\n";
		cout << "\n\nPREVIOUS SALLARY:\n ";
		fstream newfile;
		cout << endl << endl << endl;
		newfile.open("sallaryold.txt", ios::in);
		if (newfile.is_open()) {
			string tp;
			while (getline(newfile, tp)) {
				cout << tp << "\n";
			}
			newfile.close();
		}
		cout << "\n\nUpdated Sallary:\n";
		fstream newile;
		cout << endl << endl << endl;
		newile.open("sallarynew.txt", ios::in);
		if (newile.is_open()) {
			string tp;
			while (getline(newile, tp)) {
				cout << tp << "\n";
			}
			newile.close();
		}
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}

	}
	if (x == 15)
	{
		system("cls");
		Ride c0;
		c0.TASK15();
		int i;
		cin.ignore();
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 16)
	{
		system("cls");
		cin.ignore();
		string x, y;
		string line, name;
		int flag = 0;
		cout << "\n Enter the id of Customer  : ";
		cin >> name;
		cout << "\nEnter the id of Driver : ";
		cin.ignore();
		cin >> y;
		fstream myfile;
		myfile.open("CustomerHistorylive.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				x = line;
				break;
			}

		}
		if (flag != 1)
		{
			cout << "\nNO RIDE BOOKED\n";
			int i;
			cout << "\n\n\n\n\t\t\t\t\t\t\tENTER 1 FOR MENU:";
			cin.ignore();
			cin >> i;
			if (i == 1)
			{
				menu();
			}
		}
		if (flag == 1)
		{
			cout << "\nService booked :\n\n\n";
			cout << x;
		}
		myfile.close();
		int l;
		cin.ignore();
		cout << "\nPRESS 1 to Cancel Service\n";
		cin >> l;
		if (l == 1)
		{
			fstream ahm;
			ahm.open("Cancelledservice.txt", ios::app);
			ahm << "\n" << x;
			ahm.close();
			ifstream file;
			file.open("CustomerHistorylive.txt");
			ofstream temp;
			temp.open("temp.txt");
			while (getline(file, line))
			{
				if (line.substr(0, name.size()) != name)
					temp << line << endl;
			}
			file.close();
			temp.close();
			remove("CustomerHistorylive.txt");
			rename("temp.txt", "CustomerHistorylive.txt");
			ifstream fle;
			fle.open("DriverHistorylive.txt");
			ofstream temps;
			temps.open("temp.txt");
			while (getline(fle, line))
			{
				if (line.substr(0, y.size()) != y)
					temps << line << endl;
			}
			fle.close();
			temps.close();
			remove("DriverrHistorylive.txt");
			rename("temp.txt", "DriverHistorylive.txt");
		}
		if (l != 1)
		{
			menu();
		}
		cout << "\nAs You cancelled Service you have to pay 5 percent of Total amount:\n";
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin.ignore();
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 17)
	{
		system("cls");
		Ride c5;
		c5.Task17();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 18)
	{
		system("cls");
		cout << "\t\t\t\t\t\tCustomers who used same Vehicle\n";
		cout << endl << endl << endl;
		string x;
		string line, name;
		int flag = 0;
		cout << "\nPlease Enter the Vehicle id : ";
		cin >> name;
		cout << endl << endl << endl;
		fstream myfile;
		myfile.open("SameVehicle.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				x = line;
				cout << x << endl;
			}

		}
		if (flag != 1)
		{
			cout << "\nNO History found\n";
		}
		myfile.close();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}

	}
	if (x == 19)
	{
		system("cls");
		cout << "\t\t\t\t\tThis is transport Completion of  Drivers on sameday\n";
		cout << endl << endl << endl;
		string x;
		string line, name;
		int flag = 0;
		cout << "\nPlease Enter the day  : ";
		cin >> name;
		cout << endl << endl << endl;
		fstream myfile;
		myfile.open("Deliverysameday.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				x = line;
				cout << x << endl;
			}

		}
		if (flag != 1)
		{
			cout << "\nDay Not found\n";
		}
		myfile.close();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 20)
	{
		system("cls");
		cout << "\t\t\t\t\tThese are Pending Services\n";
		fstream newfile;
		cout << endl << endl << endl << endl;
		newfile.open("CustomerHistorylive.txt", ios::in);
		if (newfile.is_open()) {
			string tp;
			while (getline(newfile, tp)) {
				cout << tp << "\n";
			}
			newfile.close();
		}
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 21)
	{
		system("cls");
		cout << "\t\t\t\t\tThese Drivers Have some Pending Services\n";
		cout << endl << endl << endl;
		string x;
		string line, name;
		int flag = 0;
		cout << "\nPlease Enter the id of Driver : ";
		cin >> name;
		cout << endl << endl << endl;
		fstream myfile;
		myfile.open("DriverHistorylive.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				x = line;
				cout << x << endl;
			}

		}
		if (flag != 1)
		{
			cout << "\nDriver Not found\n";
		}
		myfile.close();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
	if (x == 22)
	{
		system("cls");
		cout << "\t\t\t\t\t\tThis is Cancelled Services\n";
		cout << endl << endl << endl;
		string x;
		string line, name;
		int flag = 0;
		cout << "\nPlease Enter the id of Customer : ";
		cin >> name;
		cout << endl << endl << endl;
		fstream myfile;
		myfile.open("Cancelledservice.txt");
		while (getline(myfile, line))
		{
			if (line.substr(0, name.size()) == name)
			{
				flag = 1;
				x = line;
				cout << x << endl;
			}

		}
		if (flag != 1)
		{
			cout << "\nCustomer Not found\n";
		}
		myfile.close();
		int i;
		cout << "\n\n\n\n\t\t\t\t\t\tENTER 1 FOR MENU:";
		cin >> i;
		if (i == 1)
		{
			menu();
		}
	}
}
int main()
{

	TMS s;
	s.welcome();

	return 0;
}
