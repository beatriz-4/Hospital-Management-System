/* Project - Hosplital System (TMF 1434)
   Created by Group 2 ( Due Date : 24/6/2024) */
   
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <termios.h>
#include <unistd.h>
using namespace std;

/*Treatments for patient (optional single or multiple treatments)*/
class Treatment{
public:
    string name;
    string date;
    Treatment *next;
    
    // constructor
    Treatment(string n = "", string d = "") : name(n), date(d), next(nullptr) {}
};

/*Patient's info for Admission*/
class Patient {
public:
    string name;
    int iD;
    string department;
    Treatment *Front;
    Treatment *Rear;
    string admissionDate;
    string dischargeDate;
    int lengthOfStay;
    Patient* next;
    
    //constructor
    Patient(string n = "", int i = 0, string d = "", string b = "", string aD = "", string dD = "", int l = 0)
        : name(n), iD(i), department(d), Front(nullptr), Rear(nullptr), admissionDate(aD), dischargeDate(dD), lengthOfStay(l), next(nullptr) {}
};

class Admission {
    public:
    Patient* admissionFront;
    Patient* admissionRear;
    int numOfPatient;
    
    //constructor
    Admission() {
        admissionFront = nullptr;
        admissionRear = nullptr;
        numOfPatient = 0;
    }
    
    /*pre_set for admitted patients */
    void pre_set(){
        // Patient 1
        Patient* newPatient1 = new Patient;
        newPatient1->name = "Aisha";
        newPatient1->iD = 1;
        
        Treatment* treatment1 = new Treatment;
        treatment1->name = "Checkup";
        treatment1->date = "02/01/2024";   // DD/MM/YYYY format
        treatment1->next = nullptr;
        newPatient1->Front = treatment1;
        newPatient1->Rear = treatment1;
        
        newPatient1->admissionDate = "01/01/2024";    // DD/MM/YYYY format
        newPatient1->department = "Haematology";
        newPatient1->lengthOfStay = 3;
        newPatient1->dischargeDate = calculateDischargeDate(newPatient1->admissionDate, newPatient1->lengthOfStay);
        newPatient1->next = nullptr;

        admissionFront = newPatient1;
        admissionRear = newPatient1;
        numOfPatient++;
        
        // Patient 2
        Patient* newPatient2 = new Patient;
        newPatient2->name = "Bryn";
        newPatient2->iD = 2;

        Treatment* treatment2 = new Treatment;
        treatment2->name = "Surgery";
        treatment2->date = "04/01/2024";   // DD/MM/YYYY format
        treatment2->next = nullptr;
        newPatient2->Front = treatment2;
        newPatient2->Rear = treatment2;

        newPatient2->admissionDate = "02/01/2024";    // DD/MM/YYYY format
        newPatient2->department = "Haematology";
        newPatient2->lengthOfStay = 5;
        newPatient2->dischargeDate = calculateDischargeDate(newPatient2->admissionDate, newPatient2->lengthOfStay);
        newPatient2->next = nullptr;

        admissionRear->next = newPatient2;
        admissionRear = newPatient2;
        numOfPatient++;
        
        // Patient 3
        Patient* newPatient3 = new Patient;
        newPatient3->name = "Chelsea";
        newPatient3->iD = 3;

        Treatment* treatment3 = new Treatment;
        treatment3->name = "Surgery";
        treatment3->date = "05/01/2024";   // DD/MM/YYYY format
        treatment3->next = nullptr;
        newPatient3->Front = treatment3;
        newPatient3->Rear = treatment3;

        newPatient3->admissionDate = "03/01/2024";    // DD/MM/YYYY format
        newPatient3->department = "Neurology";
        newPatient3->lengthOfStay = 10;
        newPatient3->dischargeDate = calculateDischargeDate(newPatient3->admissionDate, newPatient3->lengthOfStay);
        newPatient3->next = nullptr;

        admissionRear->next = newPatient3;
        admissionRear = newPatient3;
        numOfPatient++;
        
        // Patient 4
        Patient* newPatient4 = new Patient;
        newPatient4->name = "Dayang";
        newPatient4->iD = 4;

        Treatment* treatment4 = new Treatment;
        treatment4->name = "Checkup";
        treatment4->date = "07/01/2024";   // DD/MM/YYYY format
        treatment4->next = nullptr;
        newPatient4->Front = treatment4;
        newPatient4->Rear = treatment4;

        newPatient4->admissionDate = "04/01/2024";    // DD/MM/YYYY format
        newPatient4->department = "Cardiology";
        newPatient4->lengthOfStay = 4;
        newPatient4->dischargeDate = calculateDischargeDate(newPatient4->admissionDate, newPatient4->lengthOfStay);
        newPatient4->next = nullptr;

        admissionRear->next = newPatient4;
        admissionRear = newPatient4;
        numOfPatient++;
        
        // Patient 5
        Patient* newPatient5 = new Patient;
        newPatient5->name = "Ean";
        newPatient5->iD = 5;

        Treatment* treatment5 = new Treatment;
        treatment5->name = "Checkup";
        treatment5->date = "06/01/2024";   // DD/MM/YYYY format
        treatment5->next = nullptr;
        newPatient5->Front = treatment5;
        newPatient5->Rear = treatment5;

        newPatient5->admissionDate = "05/01/2024";    // DD/MM/YYYY format
        newPatient5->department = "Cardiology";
        newPatient5->lengthOfStay = 2;
        newPatient5->dischargeDate = calculateDischargeDate(newPatient5->admissionDate, newPatient5->lengthOfStay);
        newPatient5->next = nullptr;

        admissionRear->next = newPatient5;
        admissionRear = newPatient5;
        numOfPatient++;
    }
    
    /*function to admit new patiets */
    void enq(){
        cout << " *** Patinet's Admission ***" << endl;
        string n, d, aD;
        int i, l;
        
        Patient *admitted = new Patient;
        cout << "Enter patient's name: ";
        cin.ignore();    //clear the newline character left by previous input
        getline(cin, n);
        admitted->name = n;
        
        cout << "Enter patient's ID: ";
        cin >> i;
        admitted->iD = i;

        addTreatment(admitted);

        cout << "Department: ";
        cin.ignore(); // Clear the newline character left by previous input
        getline(cin, d);
        admitted->department = d;

        cout << "Admission date (DD/MM/YYYY): ";
        getline(cin, aD);
        admitted->admissionDate = aD;

        cout << "Length of stay (days): ";
        cin >> l;
        admitted->lengthOfStay = l;

        admitted->dischargeDate = calculateDischargeDate(admitted->admissionDate, admitted->lengthOfStay);
        admitted->next = nullptr;
        
        if(admissionFront == nullptr){
            admissionFront = admitted;
            admissionRear = admitted;
        } else {
            admissionRear->next = admitted;
            admissionRear = admitted;
        }
        cout << n << " is admitted\n";
        numOfPatient++;
    }
    
    /* function to add treatment */
    void addTreatment(Patient *current){
        string name, date;
        Treatment *newTreatment = new Treatment;
        cout << "Enter treatment [Checkup | Surgery]: ";
        cin.ignore(); // Clear the newline character left by previous input
        getline(cin, name);
        newTreatment->name = name;
        
        cout << "Enter date (DD/MM/YYYY): ";
        getline(cin, date);
        newTreatment->date = date;
        
        newTreatment->next = nullptr;
        
        if(current->Front == nullptr){
            current->Front = newTreatment;
            current->Rear = newTreatment;
        } else {
            current->Rear->next = newTreatment;
            current->Rear = newTreatment;
        }
    }
        
    /* function to add additinal treatment to a patient */
    void extraTreatment(){
        Patient *current = admissionFront;
            
        //display all patients
        int x=1;
        while(current != nullptr){
            cout << x << " - Name: " << current->name << "   Current treatment: " << current->Rear->name << "(" << current->Rear->date << ")" << endl;
            current = current->next;
            x++;
        }
            
        //choose patient to add aditional treatment
        int choose;
        cout << "Choose which patient you would like to add new treatment to (enter the number): ";
        cin >> choose;
            
        //traverse until the chosen patient
        current = admissionFront;
        int count = 1;
        while(current != nullptr && count < choose){
            current = current->next;
            count++;
        }
            
        //insert new treatment's info
        if(current != nullptr){
            cout << current->name << "'s New treatment\n";
            addTreatment(current);
        } else {
            cout << "Invalid patient choice.\n";
        }
    }
    
    
    /* List of patient admitted based on Admission Date */
    void listAdmission(){
        Patient *current = admissionFront;
        current = mergeSort(admissionFront, compareByAdmissionDate);
        while(current != nullptr){
            cout << "| Admission Date: " << current->admissionDate;
            cout << " | Name: " << current->name << endl;
            current = current->next;
        }
    }
    
    /*Function to discharge patient */
    void deq(){
        cout << "** Discharge Patients **" << endl;

        if(admissionFront == nullptr){
            cout << "No patient to discharge.\n";
        } else {
            Patient *toDischarge = mergeSort(admissionFront, compareByDischargeDate);
            
            // Output name of patients to be discharged
            cout << toDischarge->name << " is discharge.\n";
            
            // Discharge the patient
            admissionFront = toDischarge->next;
            delete toDischarge;
            numOfPatient--;
        }
    }
    
    
    /*List of patient to be discharged based on Discharge Date */
    void listDischarge(){
        // Sort patients based on discharge date
        Patient* current = mergeSort(admissionFront, compareByDischargeDate);
        
        // Display sorted patients
        while(current != nullptr){
            cout << "Discharge Date: " << current->dischargeDate << "  Name: " << current->name << endl;
            current = current->next;
        }
    }
    
    
    /* Function to calculate discharge date */
    string calculateDischargeDate(string admissionDate, int length){
        int year = stoi(admissionDate.substr(6, 4));  // Extract year from "YYYY/MM/DD"
        int month = stoi(admissionDate.substr(3, 2)); // Extract month
        int day = stoi(admissionDate.substr(0, 2));   // Extract day
        
        day += length;
        while (day > 30){
            day-=30;
            if(month > 12){
                month = 1;
                year++;
            }
        }
        return to_string(day) + "/" + (month < 10 ? "0" : "") + to_string(month) + "/" + to_string(year);
    }


    /* Function to sort patient using Merge Sort */
    Patient* mergeSort(Patient* head, bool comparator(Patient*, Patient*)) {
        
    Patient* originalCurrent = admissionFront;
    Patient* newFront = nullptr;
    Patient* newPrevious = nullptr;

    while (originalCurrent != nullptr) {
        // Create a new node and copy data
        Patient* newNode = new Patient(*originalCurrent);

        // Link the new node
        if (newFront == nullptr) {
            newFront = newNode;
        } else {
            newPrevious->next = newNode;
        }
        newPrevious = newNode;

        // Move to next node in original list
        originalCurrent = originalCurrent->next;
    }

    // Set admissionRear to the last node of the new list
    admissionRear = newPrevious;

    // Set admissionFront to the new front of the list
    admissionFront = newFront;
    
       // If head is empty or has only single patient, return head;
        if (head==nullptr || head->next ==nullptr) {
            return head;
        }
        
        //find middle
        Patient* middle = mid_node(head, nullptr);
        Patient* half = middle->next;
        middle->next = nullptr;

        return merge(mergeSort(head, comparator), mergeSort(half, comparator), comparator);     //recursively split and merge

    }
    
    
    /* Function to merge two sorted linked list */
    Patient *merge(Patient *left, Patient *right, bool comparator(Patient*, Patient*)){
    
        if (left==nullptr) return right;
        if (right == nullptr) return left;
        
        if(comparator(left, right)){
            left->next = merge(left->next, right, comparator);
            return left;
        } else {
            right->next = merge(left, right->next, comparator);
            return right;
        }
    }
    
    
    /* Function to find middle node */
    Patient *mid_node(Patient *start, Patient *last){
        if(start == nullptr)
           return nullptr;
        
        Patient *middle = start;
        Patient *current = start->next;
        while(current != last){
            current = current->next;
            if(current != last){
                middle = middle->next;
                current = current->next;
            }
        }
        return middle;
    }
    
    /* Function to search patient using Binary Search */
    void binarySearch(Patient*head, int value){
        Patient *start = head;
        Patient *last = nullptr;
        
        do{
            Patient *mid = mid_node(start, last);
            
            
            if(mid == nullptr){
                cout << "Patient with ID (" << value << " not found.\n";
                return;
            }
            
            if(mid->iD == value){
                cout << "Patient found:\n";
                cout << "ID: " << mid->iD << "   Name: " << mid->name << " has " << mid->Rear->name << " at " << mid->department << " department on "<< mid->Rear->date << endl;
                return;
            } else if (mid->iD < value){
                start = mid->next;
            } else {
                last = mid;
            }
        } while (last == NULL || last != start);
    }



/* View the selected patient treatment history */
void viewMedicalHistory() {
        cout << "***** View Medical History *****" << endl;

        // Display all patients
        Patient* current = admissionFront;
        int x=1;
        while (current != nullptr) {
            cout << x<<" - Name: " << current->name << " (ID - " << current->iD << ")" << endl;
            current = current->next;
            x++;
        }

        int choose;
        cout << "Enter which patient's medical history to view: ";
        cin >> choose;
        
        x=1;
        // raverse until the chosen patient
        current = admissionFront;
        while (current != nullptr && x<choose) {
            current = current->next;
            x++;
        }
        // Display the patient name, ID and treatments history
            cout << "Name: " << current->name << " (" << current->iD << ")" << endl;
            Treatment* treatment = current->Front;
            while (treatment != nullptr) {
                cout << "Treatment: " << treatment->name << " (" << treatment->date << ")" << endl;
                treatment = treatment->next;
            }
            cout << endl;

    }

/* Compare patients' admission date to be used in merge sort*/
static bool compareByAdmissionDate(Patient* a, Patient* b) {
    // Extract year, month, and day from admissionDate string
    int yearA = stoi(a->admissionDate.substr(6, 4));
    int monthA = stoi(a->admissionDate.substr(3, 2));
    int dayA = stoi(a->admissionDate.substr(0, 2));

    int yearB = stoi(b->admissionDate.substr(6, 4));
    int monthB = stoi(b->admissionDate.substr(3, 2));
    int dayB = stoi(b->admissionDate.substr(0, 2));

    // Compare by year first, then month, then day
    if (yearA != yearB) {
        return yearA < yearB;
    }
    if (monthA != monthB) {
        return monthA < monthB;
    }
    return dayA < dayB;
}

/* Compare patients' discharge date to be used in merge sort*/
static bool compareByDischargeDate(Patient* a, Patient* b) {
    // Extract year, month, and day from dischargeDate string
    int yearA = stoi(a->dischargeDate.substr(6, 4));
    int monthA = stoi(a->dischargeDate.substr(3, 2));
    int dayA = stoi(a->dischargeDate.substr(0, 2));

    int yearB = stoi(b->dischargeDate.substr(6, 4));
    int monthB = stoi(b->dischargeDate.substr(3, 2));
    int dayB = stoi(b->dischargeDate.substr(0, 2));

    // Compare by year first, then month, then day
    if (yearA != yearB) {
        return yearA < yearB;
    }
    if (monthA != monthB) {
        return monthA < monthB;
    }
    return dayA < dayB;
}

/* Compare patients' treatment date to be used in merge sort*/
static bool compareByTreatmentDate(Patient* a, Patient* b) {
    // Retrieve the latest treatment date for each patient
    Treatment* treatmentA = a->Rear;  // Assuming Rear points to the last treatment
    Treatment* treatmentB = b->Rear;  // Assuming Rear points to the last treatment

    // Extract treatment dates from treatment string format
    // Example extraction assuming "DD/MM/YYYY" format
    int dayA = stoi(treatmentA->date.substr(0, 2));
    int monthA = stoi(treatmentA->date.substr(3, 2));
    int yearA = stoi(treatmentA->date.substr(6, 4));

    int dayB = stoi(treatmentB->date.substr(0, 2));
    int monthB = stoi(treatmentB->date.substr(3, 2));
    int yearB = stoi(treatmentB->date.substr(6, 4));

    // Compare the treatment dates
    // Compare by year first, then month, then day
    if (yearA != yearB) {
        return yearA < yearB;
    }
    if (monthA != monthB) {
        return monthA < monthB;
    }
    return dayA < dayB;
}


/* Compare patients' treatment to be used in merge sort*/
static bool compareByTreatment(Patient* a, Patient* b) {
    // Get the rear treatment of patient a
    Treatment* aRear = a->Rear;
    bool aSurgery = (aRear != nullptr && aRear->name == "Surgery");

    // Get the rear treatment of patient b
    Treatment* bRear = b->Rear;
    bool bSurgery = (bRear != nullptr && bRear->name == "Surgery");

    // Determine order based on presence of "Surgery" treatment in rear treatment
    if (aSurgery && !bSurgery) {
        return true;  // a comes before b
    } else if (!aSurgery && bSurgery) {
        return false; // b comes before a
    } else {
        return false; // or handle the case where neither has "Surgery" (assuming false returns b comes before a)
    }
}
    static bool compareByiD(Patient *a, Patient *b){
        return a->iD <= b->iD;
    }

    static bool compareByLengthOfStay(Patient* a, Patient* b) {
        return a->lengthOfStay <= b->lengthOfStay;
    }


/* Menu that shows sorting patients based on treatment date, priority of medical attention and length of stay */
void sortRecord() {
    int choice;
    cout << "**** Organize Patient *****" << endl;
    Patient *current = admissionFront;
    while (choice != 4) {
        cout << "[1] - Treatment Date  [2] - Priority of medical attention  [3] - Length Of Stay  [4] - Exit" << endl;
        cout << "Enter: ";
        cin >> choice;
        if (choice == 1) {
            current = mergeSort(admissionFront, compareByTreatmentDate);
            
            while (current != nullptr) {
                // Display rear treatment
                cout << "Name: " << current->name << "  Treatment Date: " << current->Rear->date << endl;
                current = current->next;
            }
        } else if (choice == 2) {
            current = mergeSort(admissionFront, compareByTreatment);
            cout << "Priotize patients based on treatment" << endl;

            while (current != nullptr) {
                Treatment* rearTreatment = current->Rear;
                cout << "Name: " << current->name << "  Treatment : " << rearTreatment->name << endl;
                current = current->next;
            }
        } else if (choice == 3) {
            current = mergeSort(admissionFront, compareByLengthOfStay);

            while (current != nullptr) {
                // Display rear treatment
                Treatment* rearTreatment = current->Rear;
                cout << "Name: " << current->name << "  Length of stay " << current->lengthOfStay << endl;
                current = current->next;
            }
        } else if (choice == 4) {
            cout << "Back to main page" << endl;
        } else {
            cout << "Invalid. try again" << endl;
        }
        cout << endl;
    }
    cout << endl;
}


/* Function to edit patient's info */
void edit() {
    
    // check if patient exist
    if (numOfPatient == 0) {
        cout << "No patients to edit." << endl;
        return;
    }

    cout << "**** Edit Patient Record *****" << endl;

    // Display all patients
    Patient* current = admissionFront;
    int count = 1;
    while (current != nullptr) {
        cout << count << " - Name: " << current->name << "  ID: " << current->iD << "  Treatment: " << current->Rear->name << "  (" << current->Rear->date<< ")" << endl;
        current = current->next;
        count++;
    }

    // Ask user which patient to edit
    int choose;
    cout << "Enter the number of the patient you want to edit: ";
    cin >> choose;

    if (choose < 1 || choose > numOfPatient) {
        cout << "Invalid selection. Please enter a valid number." << endl;
        return;
    }

    // Traverse to the chosen patient
    current = admissionFront;
    while(current !=NULL && choose!=numOfPatient) {
        current = current->next;
    }

    // Edit patient record
    cout << "Enter patient's name: ";
    cin.ignore(); // Clear newline character
    getline(cin, current->name);

    cout << "Enter patient's ID: ";
    cin >> current->iD;

    cout << "Department: ";
    getline(cin, current->department);

    cout << "Length of Stay (days): ";
    cin >> current->lengthOfStay;
    
    cout << "Admission Date (DD/MM/YYYY): ";
    getline(cin, current->admissionDate);
    
    cout << "Treatment: ";
    getline(cin, current->Rear->name);
    
    cout << "Treatment Date: ";
    getline(cin, current->Rear->date);
    // Update discharge date based on new length of stay
    current->dischargeDate = calculateDischargeDate(current->admissionDate, current->lengthOfStay);

    cout << "Patient record updated successfully." << endl;
    
}


/* Search patient's name using Linear Search */
void searchName(Patient* current, string name) {
    bool found = false;
    while (current != NULL) {
        if (current->name == name) {
            cout << name << " has "<< current->Rear->name << " treatment at "<< current->department<< " on " << current->Rear->date << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << name << " is not found" << endl;
    }
}


/* Search all patients with 'treament' using Linear Search */
void searchTreatment(Patient* current, string x) {
    bool found = false;
    while (current != NULL) {
        if (current->Rear->name ==x) {
            cout << "Name: " << current->name << "   Treatment: " << x << "(" << current->Rear->date<<")"<<endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Patient with treatment " << x << " not found" << endl;
    }
}

/* Menu of search patient name, ID and Type of treatment */
void searchRecord() {    // linear search
    int x = 0, i;
    string n, t;
    cout << "**** Search Patient *****" << endl;
    while (x != 4) {
        cout << "[1] - Patient's Name  [2] - Patient's ID  [3] - Type of Treatment  [4] - Exit" << endl;
        cout << "Enter: ";
        cin >> x;
        cout<< endl;
        
        if (x == 1) {
            cout << "Enter the patient's name: ";
            cin >> n;
            searchName(admissionFront, n);
        }
        else if (x == 2) {
            cout << "Enter the patient's ID: ";
            cin >> i;
            Patient *current = mergeSort(admissionFront, compareByiD);
            binarySearch(admissionFront, i);
            }
        else if (x == 3) {
            string t;
    cout << "Enter treatment type: ";
    cin >> t;
    searchTreatment(admissionFront, t);
    }
        else if (x == 4) {
            cout << "Back to main page" << endl;
        }
        else {
            cout << "Invalid input, try again" << endl;
        }
        cout << endl;
    }
}

   /* Function to display all patient admitted */
    void display() {
        Patient* current = admissionFront;
        while (current != nullptr) {
            cout << "Name: " << current->name << " | Admission Date: " << current->admissionDate << " | Discharge Date: " << current->dischargeDate << endl;
            current = current->next;
        }
        cout << endl;
    }
    
    
    /* Menu that consist of admit, discharge , update, add new treatment and view medical history */
    void transaction_Management(){
        int x;
        cout << "****** Transaction Management ******" << endl;
        while(x!=6){
            cout << "[1] - Admit Patient   [2] - Discharge Patient  [3] - Update Patient Detail  [4] - Add new Treatment  "<<endl;
            cout << "[5] - View Patient Medical History  [6] - Exit" << endl;
            cout << "Enter: ";
            cin >> x;
            
            switch(x){
                case 1:
                    listAdmission();
                    enq();
                    break;
                case 2:
                    listDischarge();
                    deq();
                    break;
                case 3:
                    edit();
                    break;
                case 4:
                    extraTreatment();
                    break;
                case 5:
                    viewMedicalHistory();
                    break;
                case 6:
                    cout << "Back to main menu" << endl;
                    break;
                default:
                    cout << "Invalid, try again" << endl;
            }
        }
        cout << endl;
    }
    
    /* Menu that consist of search and sort patient */
    void viewDetail(){
        int x;
        cout << "**** View Detail ******" << endl;
        while(x!=3){
            cout << "[1] - Search Patient  [2] - Sort Patient  [3] - Exit" << endl;
            cout << "Enter: ";
            cin >> x;
            
            switch(x){
                case 1:
                    searchRecord();
                    break;
                case 2:
                    sortRecord();
                    break;
                case 3:
                    cout << "Back to Main Page" << endl;
                    break;
                default:
                    cout << "invalid, try again" << endl;
            }
        }
    }
    
    /* menu that consist of list of patient admitted and discharge */
    void summary(){
        cout << "   Total of patient admitted: " << numOfPatient << endl <<endl;
        cout << "Total Patient for Admission" << endl;
        listAdmission();
        cout << endl;
                
        
        cout << "Total Patient for Discharge" << endl;
        listDischarge();
        cout << endl;

        
         cout << "Press Enter to continue..."<<endl;
        cin.get();
    }
    
    /* Admission's Menu */
    void admissionMenu(){
        int choice;
        do {
        cout << "1. Display Patient\n2. Transaction Management\n3. View Patient's Detail\n4. Reports and Summaries\n5.Exit" << endl;
        cout << "Enter: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                transaction_Management();
                break;
            case 3:
                viewDetail();
                break;
            case 4:
                summary();
                break;
            case 5:
                cout << "Exiting";
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
    system("cls");
    }
};




/* Patients info for Appointment */
class Patients {
public:
    string name;
    int patientId;
    string department;
    string treatment;
    string date;
    string time;
    Patients *next;
    
    //constructor
    Patients(string n = "", int i = 0, string d="", string t="", string dt="", string time= "") : name(n), patientId(i), department(d), treatment(t), date(dt), time(time), next(nullptr) {}
};

class Appointment : public Admission{
public:
    Patients *appointmentFront;
    Patients *appointmentRear;
    int numOfOutPatient;
    
    //constructor
    Appointment() {
        appointmentFront = nullptr;
        appointmentRear = nullptr;
        numOfOutPatient = 0;
    }
    
    /* Pre_set patients for appointment */
void appointment_pre_Set(){
    // Patient 1
    Patients* newPatient1 = new Patients;
    newPatient1->name = "John Doe";
    newPatient1->patientId = 1;
    newPatient1->treatment = "Blood test";
    newPatient1->date = "01/04/2024";   // DD/MM/YYYY format
    newPatient1->time = "08:00";
    newPatient1->department = "Cardiology";
    newPatient1->next = nullptr;

    appointmentFront = newPatient1;
    appointmentRear = newPatient1;
    numOfOutPatient++;
    
    
    // Patient 2
    Patients* newPatient2 = new Patients;
    newPatient2->name = "Jane Smith";
    newPatient2->patientId = 2;
    newPatient2->treatment = "X-Ray";
    newPatient2->date = "02/04/2024";   // DD/MM/YYYY format
    newPatient2->time = "10:30";
    newPatient2->department = "Haematology";
    newPatient2->next = nullptr;

    appointmentRear->next = newPatient2;
    appointmentRear = newPatient2;
    numOfOutPatient++;
    
    
    // Patient 3
    Patients* newPatient3 = new Patients;
    newPatient3->name = "Peter Jones";
    newPatient3->patientId = 3;
    newPatient3->treatment = "Medication therapy";
    newPatient3->date = "03/04/2024";   // DD/MM/YYYY format
    newPatient3->time = "13:00";
    newPatient3->department = "Neurology";
    newPatient3->next = nullptr;

    appointmentRear->next = newPatient3;
    appointmentRear = newPatient3;
    numOfOutPatient++;

    // Patient 4
    Patients* newPatient4 = new Patients;
    newPatient4->name = "Mary Brown";
    newPatient4->patientId = 4;
    newPatient4->treatment = "Urine Test";
    newPatient4->date = "04/04/2024";   // DD/MM/YYYY format
    newPatient4->time = "15:00";
    newPatient4->department = "Haematology";
    newPatient4->next = nullptr;

    appointmentRear->next = newPatient4;
    appointmentRear = newPatient4;
    numOfOutPatient++;
    
    // Patient 5
    Patients* newPatient5 = new Patients;
    newPatient5->name = "David Lee";
    newPatient5->patientId = 5;
    newPatient5->treatment = "Medical theraphy";
    newPatient5->date = "05/04/2024";   // DD/MM/YYYY format
    newPatient5->time = "11:00";
    newPatient5->department = "Neurology";
    newPatient5->next = nullptr;

    appointmentRear->next = newPatient5;
    appointmentRear = newPatient5;
    numOfOutPatient++;
}

/* Function to add new patients for appointment */
void addAppointment() {
    string n, d,t,dt, tm;
    Patients *appointment = new Patients;
    cout << "Enter name: ";
    cin.ignore(); // Clear the newline character left by previous input
    getline(cin, n);
    appointment->name = n;
        
    cout << "Enter patient ID: ";
    cin >> appointment->patientId;
    
    cout << "Enter department: ";
    cin.ignore();
    getline(cin, d);
    appointment->department = d;
    
    cout <<"Treatment: ";
    getline(cin,t);
    appointment->treatment = t;
    
    cout << "Date(DD/MM/YYYY): ";
    getline(cin, dt);
    appointment->date = dt;
    
    cout << "Time(MM:SS): ";
    getline(cin, tm);
    appointment->time = tm;

    appointment->next = nullptr;
    
    if (appointmentFront == nullptr) {
        appointmentFront = appointment;
        appointmentRear = appointment;
    } else {
        appointmentRear->next = appointment;          //'next' pointer of previous node oint to newtreatment
        appointmentRear = appointment;                // previous node point to newTreatment
    }

    cout << appointment->name << " is admitted\n";
    numOfOutPatient++;
    
    cout << "Appointment added successfully!\n\n";
    
}


/* Function to cancel or dequeue appointment*/
void deleteAppointment() {
    if (appointmentFront==nullptr) {
        cout << "No appointments available to cancel.\n";
        return;
    }
    else{
        int choice;
        cout<<"[1] - Delete Current appointmnt  [2] - Cancel Appointment  [3] - exit" << endl;
        cout << "Enter: ";
        cin >> choice;
        if(choice==1){
            
            Patients *toDelete = appointmentFront;
            cout << toDelete->name << " is deleted" << endl;
            appointmentFront = toDelete->next;
            delete toDelete;
            numOfOutPatient--;
            
        } else if(choice==2){
            
            int x=1;
            Patients *current = appointmentFront;
            while(current!=nullptr){
                cout << x<< " - Name: " << current->name << " Current treatment: " << current->treatment<< "(" << current->date <<")" << " at " << current->time << endl;
                current = current->next;
                x++;
            }
            int choose;
            cout << "Which patient's appointment would you like to cancel?" << endl;
            cout << "Enter: ";
            cin >> choose;
            
            if(choose>numOfOutPatient){
                cout << "Invalid choice" << endl;
                return;
            }
            
            // traverse until chosen patient
            current = appointmentFront;
            Patients *previous = nullptr;
            x=1;
            while(current!=nullptr && x<choose){
                previous = current;
                current = current->next;
                x++;
            }
            Patients *toCancel = current;
            
            if(toCancel == appointmentFront){
                appointmentFront = toCancel->next;
                
            } else {
                previous->next = toCancel->next;
            }
            
            // cancel appointment
            cout << toCancel->name << " is deleted." << endl;
            delete toCancel;
            numOfOutPatient--;
        }
    }
}


/* Function to view all appointments */
void viewAppointments() {
    cout << "   Total Appointment: " << numOfOutPatient << endl << endl;
    Patients *current = appointmentFront;
    if(current ==nullptr) {
        cout << "No appointments available to view.\n";
        return;
    } else {
    cout << "All Appointments:\n";
    while (current!=nullptr) {
        cout << "Patient ID: " << current->patientId << "  Date: " << current->date << "  Time: " << current->time <<"   Treatment: " << current->treatment << endl;
        current=current->next;
    }
}
cout << endl;
}

/* Appointment Menu */
void appointmentMenu(){
        int choice;
    while (choice!=4) {
        cout << "1. Add Appointment\n";
        cout << "2. Cancel or Delete Appointment\n";
        cout << "3. View All Apppointment\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                deleteAppointment();
                break;
            case 3:
                viewAppointments();
                break;
            case 4:
                cout << "Go to Main Page" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
system("cls");
}


/*Function to group patients based on department */
void listPatient(string department){
    cout << "| IN-PATIENTS  |" << endl;
    Patient *inPatient = admissionFront;
    while(inPatient != NULL){
        if(inPatient->department == department){
            cout << "Name : " << inPatient->name << "   Treatment : " << inPatient->Rear->name << endl;
        }
        inPatient = inPatient->next;
    }
    cout << endl;
    
    cout << "| OUT-PATIENTS  |" << endl;
    Patients *outPatient = appointmentFront;
    while(outPatient != NULL){
        if(outPatient->department == department){
            cout << "Name : " << outPatient->name << "   Treatment : " << outPatient->treatment << endl;
        }
        outPatient = outPatient->next;
    }
    cout << "__________________________________________________________________" ;
    cout << endl;
    cout << endl;
}


/* Function to view all In-Patient and Out-Patient in the hosplital based on department */
void viewAllDepartment(){
    cout << "  Total Patients In Hospital: " << numOfPatient+numOfOutPatient << endl << endl;
    cout << "  CARDIOLOGY DEPARTMENT" << endl;
    listPatient("Cardiology");
    
    cout << "  HAEMATOLOGY DEPARTMENT" << endl;
    listPatient("Haematology");
    
    cout << "  NEUROLOGY DEPARTMENT" << endl;
    listPatient("Neurology");
    
    }

};


int main() {
    
    Appointment menu;
    int choice;
    menu.pre_set();
    menu.appointment_pre_Set();
    
    do{
        cout << "**** HOSPITAL SYSTEM ****" << endl;
        cout << "[1] - Admission   [2] - Appointment   [3] - Department  [4] - Exit" << endl;
        cout << " Enter: ";
        cin >> choice;
        cout << endl;
        switch(choice){
            case 1:
                menu.admissionMenu();
                break;
            case 2:
                menu.appointmentMenu();
                break;
            case 3:
                menu.viewAllDepartment();
                break;
            case 4:
                cout << "Exiting";
            default:
                cout << "Invalid try again"<< endl;
        }
        cout << endl;
    } while(choice!=4);
    
    
    return 0;
}
