#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const string PNR_FILE = "last_pnr.txt";

int get_last_pnr() {
    int last_pnr = 0;
    ifstream fin(PNR_FILE);
    if (fin) {
        fin >> last_pnr;
    }
    fin.close();
    return last_pnr;
}

void update_last_pnr(int new_pnr) {
    ofstream fout(PNR_FILE);
    fout << new_pnr;
    fout.close();
}

class booking {
protected:
    int pnr;
    char flight_name[10], time_arrival[7], time_departure[7];
    long long date_of_journey;
    int choice, source, destination;

public:
    void d_pnr() {
        int last_pnr = get_last_pnr();
        pnr = last_pnr + 1;
        update_last_pnr(pnr);
    }

    int j_detail() {
        cout << "\nEnter Date Of Journey (DDMMYY): ";
        cin >> date_of_journey;
        cout << "\n1. Delhi(1) \n2. Mumbai(2) \n3. Bangalore(3) \n4. Chennai(4)" << endl;
        cout << "\nEnter Source: ";
        cin >> source;
        cout << "Enter destination: ";
        cin >> destination;

        if ((source == 1 && destination == 2) || (source == 2 && destination == 1)) // Delhi <-> Mumbai
        {
            cout << "\n\tFlights Found" << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\t\tDistance:\n";
            cout << "1. Vistara \t05:30\t\t07:30\t\tRs.4200\t\tRefundable\t\t1147 km\n";
            cout << "2. GoAir\t08:00\t\t10:00\t\tRs.3800\t\tRefundable\t\t1147 km\n";
            cout << "3. Jet Airways\t12:30\t\t14:30\t\tRs.4500\t\tRefundable\t\t1147 km\n";
        }
        else if ((source == 1 && destination == 3) || (source == 3 && destination == 1)) // Delhi <-> Bengaluru
        {
            cout << "\tFlights Found" << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\t\tDistance:\n";
            cout << "1. AirAsia \t06:00\t\t08:30\t\tRs.5000\t\tRefundable\t\t1703 km\n";
            cout << "2. IndiGo\t09:30\t\t12:00\t\tRs.4800\t\tRefundable\t\t1703 km\n";
            cout << "3. SpiceJet\t14:00\t\t16:30\t\tRs.5500\t\tRefundable\t\t1703 km\n";

        }
        else if ((source == 1 && destination == 4) || (source == 4 && destination == 1)) // Delhi <-> Chennai
        {
            cout << "\tFlights Found" << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\t\tDistance:\n";
            cout << "1. Air India \t07:00\t\t09:30\t\tRs.5800\t\tRefundable\t\t1767 km\n";
            cout << "2. Vistara\t10:30\t\t13:00\t\tRs.5600\t\tRefundable\t\t1767 km\n";
            cout << "3. GoAir\t15:00\t\t17:30\t\tRs.6200\t\tRefundable\t\t1767 km\n";
        }
        else if ((source == 2 && destination == 3) || (source == 3 && destination == 2)) // Mumbai <-> Bengaluru
        {
            cout << "\tFlights Found" << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\t\tDistance:\n";
            cout << "1. Jet Airways \t08:30\t\t10:30\t\tRs.4000\t\tRefundable\t\t845 km\n";
            cout << "2. IndiGo\t11:30\t\t13:30\t\tRs.3800\t\tRefundable\t\t845 km\n";
            cout << "3. SpiceJet\t15:30\t\t17:30\t\tRs.4500\t\tRefundable\t\t845 km\n";
        }
        else if ((source == 2 && destination == 4) || (source == 4 && destination == 2)) // Mumbai <-> Chennai
        {
            cout << "\tFlights Found" << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\t\tDistance:\n";
            cout << "1. AirAsia \t09:30\t\t12:00\t\tRs.5000\t\tRefundable\t\t1034 km\n";
            cout << "2. Vistara\t13:00\t\t15:30\t\tRs.4800\t\tRefundable\t\t1034 km\n";
            cout << "3. GoAir\t16:30\t\t19:00\t\tRs.5500\t\tRefundable\t\t1034 km\n";
        }
        else if ((source == 3 && destination == 4) || (source == 4 && destination == 3)) // Bengaluru <-> Chennai
        {
            cout << "\tFlights Found" << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\t\tDistance:\n";
            cout << "1. SpiceJet \t10:30\t\t12:00\t\tRs.3500\t\tRefundable\t\t291 km\n";
            cout << "2. IndiGo\t13:30\t\t15:00\t\tRs.3200\t\tRefundable\t\t291 km\n";
            cout << "3. Air India \t16:00\t\t17:30\t\tRs.4000\t\tRefundable\t\t317 km\n";
        }
        else if (source == destination) // Condition
        {
            cout << "\nSource and destination can't be the same.\nTry again\n\n\n"
                 << endl;
            return j_detail();
        }
        else
        {
            cout << "\nNo flights available for the selected route.\n"
                 << endl;
            return j_detail();
        }
        return 0; // Return success
    }


    int select_flight() {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nFlight selected: IndiGo" << endl;
                strcpy(flight_name, "IndiGo");
                strcpy(time_departure, "08:00");
                strcpy(time_arrival, "11:05");
                break;
            case 2:
                cout << "\nFlight selected: Air India" << endl;
                strcpy(flight_name, "Air India");
                strcpy(time_departure, "14:00");
                strcpy(time_arrival, "17:05");
                break;
            case 3:
                cout << "\nFlight selected: SpiceJet" << endl;
                strcpy(flight_name, "SpiceJet");
                strcpy(time_departure, "19:00");
                strcpy(time_arrival, "22:05");
                break;
            default:
                cout << "Wrong input entered.\nTry again" << endl;
                return select_flight();
        }
        return 0;
    }

    int getpnr() {
        return pnr;
    }
};

class passenger : public booking {
protected:
    char first_name[20], last_name[20], email[50];
    int age, gender;
    long long  phone_no; //phone number

public:
    void p_detail(int x) {
        if (x == 1) {
            d_pnr();
            j_detail();
            select_flight();
        }
        cout << "\n\nEnter Passenger Details";
        cout << "\nFirst Name: ";
        cin >> first_name;
        cout << "Last Name: ";
        cin >> last_name;
    }

    int gender_check() {
        cout << "\nGender:\n 1. Male\n 2. Female\n";
        cout << "Enter your choice: ";
        cin >> gender;
        if (gender > 2) {
            cout << "\n\nWrong input entered.\nTry again\n\n" << endl;
            return gender_check();
        }
        return 0;
    }

    void more_details() {
        cout << "Age: ";
        cin >> age;
        cout << "Email Id: ";
        cin >> email;

        // Validate mobile number (10 digits)
        while (true) {
            cout << "Contact no. (10 digits): ";
            cin >> phone_no;
            if (to_string(phone_no).length() == 10) {
                break;
            }
            cout << "Invalid mobile number. Please enter exactly 10 digits.\n";
        }

        cout << "\n\nDetails Entered:\n";
        cout << "Name: " << first_name << " " << last_name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Email id: " << email << endl;
        cout << "Contact No.: " << phone_no << endl;
    }

    void display() {
        cout << "PNR: " << pnr << endl;
        cout << "Flight: " << flight_name << endl;
        cout << "Name: " << first_name << " " << last_name << endl;
        cout << "date_of_journey: " << date_of_journey << endl;
        cout << "Departure Time: " << time_departure << endl;
        cout << "Arrival Time: " << time_arrival << endl;
    }
};

class payment {
protected:
    long int choice1;
    long long bank, card, date, cvv, user_id;
    char password[10];

public:
    void payment_detail() {
        cout << "\n\nHow would you like to pay?:\n";
        cout << "\n1. Debit Card(1) \n2. Credit Card(2) \n3. Net Banking(3)";
        cout << "\n\nEnter your choice: ";
        cin >> choice1;
        switch (choice1) {
            case 1:
                // Validate card number (12 digits)
                while (true) {
                    cout << "\nEnter card no. (12 digits): ";
                    cin >> card;
                    if (to_string(card).length() == 12) {
                        break;
                    }
                    cout << "Invalid card number. Please enter exactly 12 digits.\n";
                }
                cout << "Enter expiry date (MMYY): ";
                cin >> date;
                cout << "Enter CVV no.: ";
                cin >> cvv;
                cout << "\nTransaction Successful\n";
                break;
            case 2:
                // Validate card number (12 digits)
                while (true) {
                    cout << "\nEnter card no. (12 digits): ";
                    cin >> card;
                    if (to_string(card).length() == 12) {
                        break;
                    }
                    cout << "Invalid card number. Please enter exactly 12 digits.\n";
                }
                cout << "Enter expiry date (MM/YY): ";
                cin >> date;
                cout << "Enter password: ";
                cin >> password;
                for (int i = 0; password[i] != '\0'; i++) {
                    if (password[i] < '0' || password[i] > '9') {
                        cout << "Wrong input. Password must be numeric.\n";
                        return payment_detail();
                    }
                }

                cout << "\nTransaction Successful !!!\n";
                break;
            case 3:
                cout << "Banks Available: \n1. State Bank of India(1) \n2. HDFC Bank(2) \n3. ICICI Bank(3) \n4. Axis Bank(4) \n5. Others(5)";

                
                while (true) {
                    cout << "\n\nEnter your choice: ";
                    cout << "\nSelect your bank (1-5): ";
                    cin >> bank;

                    if (bank >= 1 && bank <= 5) break;
                    cout << "Invalid choice. Please select a valid bank (1-5).\n";
                }

                cout << "\nYou have selected: " << bank;
                cout << "\nEnter User ID: ";
                cin >> user_id;


                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Wrong input. User ID must be numeric.\n";
                    return payment_detail();
                }

                // Validate Password (Numeric only)
                cout << "\nEnter Password (numeric only): ";
                cin >> password;
                for (int i = 0; password[i] != '\0'; i++) {
                    if (password[i] < '0' || password[i] > '9') {
                        cout << "Wrong input. Password must be numeric.\n";
                        return payment_detail();
                    }
                }

                cout << "\nTransaction Successful\n";
                break;

            default:
                cout << "\nWrong input entered.\nTry again\n\n";
                return payment_detail();
        }
    }
};

void createfile(passenger p) {
    ofstream fin("domestic.txt", ios::binary | ios::app);
    fin.write((char*)&p, sizeof(p));
    fin.close();
}

void cancelticket(int x) {
    passenger p;
    int f = 0;
    ifstream fout("domestic.txt", ios::binary | ios::app);
    ofstream fin("domestic1.txt", ios::binary | ios::app);
    fout.read((char *)&p, sizeof(p));
    while (fout) {
        if (p.getpnr() != x)
            fin.write((char *)&p, sizeof(p));
        else {
            p.display();
            cout << "\nYour Above ticket is being canceled:\n" << "Amount refunded: Rs 1000\n";
            f++;
        }
        fout.read((char *)&p, sizeof(p));
    }
    if (f == 0)
        cout << "Ticket not found\n";
    fout.close();
    fin.close();
    remove("domestic.txt");
    rename("domestic1.txt", "domestic.txt");
}

void checkticket(int x) {
    passenger p;
    int found = 0;
    ifstream fin("domestic.txt", ios::binary); // Open file for reading

    if (!fin) { // Check if file exists
        cout << "Error: Could not open the file!" << endl;
        return;
    }

    while (fin.read((char*)&p, sizeof(p))) { // Proper file reading loop
        if (p.getpnr() == x) {
            cout << "\nTicket Found!\n";
            p.display();
            found = 1;
            break; // Stop searching once found
        }
    }

    fin.close(); // Close file after reading

    if (!found) // If ticket is not found
        cout << "Ticket not found.\n";
}


int main() {
    class booking d1;
    class passenger p1;
    class payment p2;
    int ch, ch1, n;
    char input;
    do {
        system("CLS");
        cout << "\n\n \t\tWelcome To Flight Reservation System" << endl << endl;
        cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
        cout << "\t   Book your Flight tickets at affordable prices!" << endl;
        cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>";

        cout << "\n\n\t\t\t1. Book Flight(1) \n\t\t\t2. Cancel Flight(2) \n\t\t\t3. Check Ticket(3) \n\t\t\t4. Exit(4)" << endl;
        cout << "\n\t\t Please enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                system("CLS");
                cout << "Only Domestic fligts are available at the moment" << endl;
                cout << "1. Domestic Flights" << endl;
                cout << "\nPlease enter your option: ";
                cin >> ch1;
                switch (ch1) {
                    case 1:
                        p1.p_detail(1);
                        p1.gender_check();
                        p1.more_details();
                        p2.payment_detail();
                        p1.display();
                        createfile(p1);
                        break;
                    default:
                        cout << "Wrong input entered\nTry again\n\n\n" << endl;
                        return main();
                }
                break;
            case 2:
                system("CLS");
                cout << "Only Domestic fligts are available for cancellation" << endl;
                cout << "\n1. Domestic Flights" << endl;
                cout << "\nPlease enter your option: ";
                cin >> ch1;
                if (ch1 == 1) {
                    cout << "Please enter your PNR no.: ";
                    cin >> n;
                    cancelticket(n);
                }
                else {
                    cout << "Wrong input entered\nTry again\n\n\n";
                    return main();
                }
                break;
            case 3:
                system("CLS");
                cout << "\n1. Domestic Flights" << endl;
                cout << "\nPlease enter your option: ";
                cin >> ch1;
                if (ch1 == 1) {
                    cout << "Please enter your PNR no.: ";
                    cin >> n;
                    checkticket(n);
                }
                else {
                    cout << "Wrong input entered.\nTry again\n\n\n";
                    return main();
                }
                break;
            case 4:
                cout << "\n\n\t\t\t\tThank you for using our service....\n\n\n\n" << endl;
                return 0;
            default:
                cout << "Wrong input entered\nTry again.\n\n\n\n" << endl;
                
                break;

              
        }
        cout << "\n\n\nDo you wish to continue (Y/N): ";
        cin >> input;
    } while (input == 'Y' || input == 'y');
    return 0;
}