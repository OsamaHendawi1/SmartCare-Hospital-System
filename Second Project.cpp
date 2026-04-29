// Second Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>
#include <numbers>
#include <algorithm>
#include <vector>
using namespace std;


struct Appointment {

	string Patient_Name;
	string Doctor_Name;
	string Time;
};

struct Patient_Data {
	string Name;
	int age;
	string Disease;
};


struct Billing {
	string Service;
	int num;
	double cost;
};



// The first screen: This is a screen that requests login information.
class System_App {
private:
	string User_Name = "Osama";
	int Password = 123456789;

	string Enter_User_Name;
	int Enter_Password;
	bool Success = false;
	int NumOfTry = 0;


public:

	bool First_Display() {
		cout << "\t\t\t===== LOGIN SCREEN =====" << endl;
		cout << "\n";

		do {

			cout << "Please Enter the User Name :";
			cin >> Enter_User_Name;

			cout << "Please Enter the Password :";
			cin >> Enter_Password;



			if (Enter_Password == Password && Enter_User_Name == User_Name) {


				cout << "Login Successful Welcome :) " << endl;

				Success = true;

			}
			else {

				cout << "Username Or Password Wrong !!" << endl;
				cout << "Trys Left = " << 3 - (NumOfTry + 1) << endl;

			}


			NumOfTry++;

		}

		while (!Success && (NumOfTry < 3));

		return Success;


	}
};





class Third_Display {
private:
	int choice;
	bool Running = true;
public:
	vector <Appointment> APP;
	void Appointment_Management() {
		do {

			cout << "Select one of this :\n";
			cout << "\t\t\t 1- Book Appointment\n";
			cout << "\t\t\t 2- View Appointment\n";
			cout << "\t\t\t 3- Back\n";
			cin >> choice;
			switch (choice) {
			case 1:
				Book_Appointment();
				break;
			case 2:
				View_Appointment();
				break;

			case 3:
				Running = false;
				cout << "Exit Menu\n";
				break;
			}
		} while (Running);

	}

	void Book_Appointment() {
		Appointment App;

		cout << "Enter Patient Name : ";
		// Important: clear leftover newline character from previous cin >> input
		// to ensure getline() works correctly
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, App.Patient_Name);


		cout << "Enter Doctor Name : ";
		// Important: clear leftover newline character from previous cin >> input
		// to ensure getline() works correctly
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, App.Doctor_Name);


		cout << "Enter Time : ";
		cin >> App.Time;


		APP.push_back(App);
		int index = APP.size() - 1;
		cout << "The patient name is : " << App.Patient_Name << endl;
		cout << "The doctor name is : " << App.Doctor_Name << endl;
		cout << "The time is : " << App.Time << endl;
		cout << "The Index of Array is : " << index << endl;

	}

	void View_Appointment() {
		if (APP.empty()) {
			cout << "No Appointments Found !\n";
			return;
		}

		for (int i = 0; i < APP.size(); i++) {
			cout << "Index: " << i << " | ";
			cout << "Patient: " << APP[i].Patient_Name << " | ";
			cout << "Doctor: " << APP[i].Doctor_Name << " | ";
			cout << "Time: " << APP[i].Time << " | \n\n" ;

		}
	}

};


// The Fouth Display

class Billing_System {
private:
	int choice;
	bool Running = true;



public:
	vector<Billing>Bills;
	void billing_SYSTE() {
		do {

			cout << "Select one of this :\n";
			cout << "\t\t\t 1- Creat Bill\n";
			cout << "\t\t\t 2- View Bills\n";
			cout << "\t\t\t 3- Back\n";
			cin >> choice;
			switch (choice) {
			case 1:
				Creat_Bill();
				break;
			case 2:
				View_Bills();
				break;
			case 3:
				Running = false;
				cout << "Exit Menu !\n";
				break;



			}
		} while (Running);

	}


	void Creat_Bill() {
		Billing BB;
		cout << "Choose which the services :\n";
		cout << "\t\t\t 1- Checkup (50$)\n";
		cout << "\t\t\t 2- Surgery (200$)\n";
		cin >> BB.num;
		
		if (BB.num == 1) {
			BB.Service = "Checkup";
			BB.cost = 50;

		}
		else if (BB.num == 2) {
			BB.Service = "Surgery";
			BB.cost = 200;
		}
		
		if (BB.cost >= 200)
			BB.cost *= 0.9;

		BB.cost = BB.cost + (BB.cost * 0.16);
		Bills.push_back(BB);
		int index = Bills.size() - 1;
		cout << "Bill Creared Successfully :)\n";
	}

	void View_Bills() {
		if (Bills.empty()) {
			cout << "No Bills Found !\n";
			return;
		}

		for (int i = 0; i < Bills.size(); i++) {

			cout << "Index: " << i << " | ";
			cout << "Service: " << Bills[i].Service << " | ";
			cout << "Cost: " << Bills[i].cost  << " | \n\n";

		}
	}

};

// The Fifth Display


class View_Records  {
private:
	int choice;
	bool Running = true;


public:

	void Show_All_Records (
		vector <Patient_Data>& PD,
		vector <Appointment>& APP, 
		vector<Billing>& Bills ) {

		do {

			cout << "Choose one ! " << endl;
			cout << "\t\t\t1- Patients \n";
			cout << "\t\t\t2- Appointments\n";
			cout << "\t\t\t3- Bills\n";
			cout << "\t\t\t4- Back\n";
			cin >> choice;

			switch (choice) {
			case 1:
				Show_Patient_Services(PD);
				break;
			case 2:
				Show_Appointment_Services(APP);
				break;
			case 3:
				Show_Appointment_Services(Bills);
				break;
			case 4:
				Running = false;
				break;
			}


		} while (Running);
	}

	void Show_Patient_Services(vector <Patient_Data>& PD) {
		if (PD.empty()) {
			cout << "No Patients Found !\n";
			return;
		}
		for (int i = 0; i < PD.size(); i++) {
			cout << "Index is : " << i << " | " << "Name is : "
				<< PD[i].Name << " | " << "Age is : "
				<< PD[i].age << " | " << "Disease is : "
				<< PD[i].Disease << endl;
		}
	}


	void Show_Appointment_Services(vector <Appointment>& APP) {
		if (APP.empty()) {
			cout << "No Appointments Found !\n";
			return;
		}
		for (int i = 0; i < APP.size(); i++) {
			cout << "Index is : " << i << " | " << "Doctor Name is : "
				<< APP[i].Doctor_Name << " | " << "Patient Name is : "
				<< APP[i].Patient_Name << " | " << "Time is : "
				<< APP[i].Time << endl;
		}
	}
	void Show_Appointment_Services(vector<Billing>& Bills) {
		if (Bills.empty()) {
			cout << "No Bills Found !\n";
			return;
		}
		for (int i = 0; i < Bills.size(); i++) {
			cout << "Index is : " << i << " | " << "Cost is : "
				<< Bills[i].cost << " | " << "Service is : "
				<< Bills[i].Service << " | " << "Time is : " << endl;
		}
	}

};




class Patient_Manager {
private:
	vector<Patient_Data> PD;
public:
	vector<Patient_Data>& GetPatient()
	{
		// TODO: insert return statement here
		return PD;
	}

	void Menu() {
		int choice;
		bool running = true;

		do {
			cout << "\n--- Patient Management ---\n";
			cout << "\t\t\t1- Add Patient\n";
			cout << "\t\t\t2- View Patients\n";
			cout << "\t\t\t3- Delete Patient\n";
			cout << "\t\t\t0- Back\n";
			cin >> choice;

			switch (choice) {
			case 1:
				Add_Patient();
				break;
			case 2:
				View_Patients();
				break;
			case 3:
				Delete_Patient();
				break;
			case 0:
				running = false;
				break;
			default:
				cout << "Invalid choice!\n";
			}

		} while (running);
	}

private:

	void Add_Patient() {
		int age;
		string Name, Disease;
		// Important: clear leftover newline character from previous cin >> input
		// to ensure getline() works correctly
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Enter Name: ";
		// NOTE: getline is used instead of cin >> to allow spaces in input
		getline(cin, Name);

		cout << "Enter Age: ";
		cin >> age;
		// Important: clear leftover newline character from previous cin >> input
		// to ensure getline() works correctly
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Enter Disease: ";
		// NOTE: getline is used instead of cin >> to allow spaces in input
		getline(cin, Disease);

		Patient_Data P;
		P.Name = Name;
		P.age = age;
		P.Disease = Disease;

		PD.push_back(P);

		cout << "Patient added successfully!\n";
	}

	void View_Patients() {
		if (PD.empty()) {
			cout << "No patients found!\n";
			return;
		}

		for (int i = 0; i < PD.size(); i++) {
			cout << "Index: " << i
				<< " | Name: " << PD[i].Name
				<< " | Age: " << PD[i].age
				<< " | Disease: " << PD[i].Disease
				<< endl;
		}
	}

	void Delete_Patient() {
		if (PD.empty()) {
			cout << "No patients to delete!\n";
			return;
		}

		int index;

		View_Patients();

		cout << "Enter index to delete: ";
		cin >> index;

		if (index >= 0 && index < PD.size()) {
			PD.erase(PD.begin() + index);
			cout << "Deleted successfully!\n";
		}
		else {
			cout << "Invalid index!\n";
		}
	}
};




class Second_Display {
private:

	Third_Display Third_D;

	Billing_System Billing_Sys;

	View_Records View_Rec;

	Patient_Manager Patient_Manag;

	int choice;
	bool Running = true;

	//vector <Patient_Data> PD;
public:

	void Show_Menu() {
		do {

		cout << "Enter the choice number : ( 0,1,2,3,4 )" << endl;
		cout << "\n";
		cout << "\t\t\t1- Patient Management\n";
		cout << "\t\t\t2- Appointment Management\n";
		cout << "\t\t\t3- Billing System\n";
		cout << "\t\t\t4- View Records \n";
		cout << "\t\t\t5- Exit\n";

		cin >> choice;
		switch (choice) {
		case 1:
			Patient_Manag.Menu();
			break;

		case 2:
			Third_D.Appointment_Management();
			break;

		case 3:
			Billing_Sys.billing_SYSTE();
			break;

		case 4:
			View_Rec.Show_All_Records(Patient_Manag.GetPatient(), Third_D.APP, Billing_Sys.Bills);
			break;

		case 5:
			Running = false;
			cout << "Exit \n";
	}

		} while (Running);
	

	}

};



int main() {
	System_App App;
	if (App.First_Display()) {
		cout << "Ready to go to the second page !!!" << endl;
		Second_Display Second_Screen;
		Second_Screen.Show_Menu();
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


