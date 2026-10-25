#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Patient {
private:
    int id;
    string name;
    int age;
    string condition;
    bool admitted;

public:
    Patient(int patientId, string patientName, int patientAge, string patientCondition)
        : id(patientId), name(patientName), age(patientAge),
          condition(patientCondition), admitted(false) {}

    int getId() const { return id; }
    bool isAdmitted() const { return admitted; }
    void admit() { admitted = true; }
    void discharge() { admitted = false; }

    void display() const {
        cout << "\nPatient ID: " << id
             << "\nName: " << name
             << "\nAge: " << age
             << "\nCondition: " << condition
             << "\nAdmission Status: "
             << (admitted ? "Admitted" : "Not Admitted") << "\n";
    }
};

class Doctor {
private:
    int id;
    string name;
    string specialization;
    string schedule;

public:
    Doctor(int doctorId, string doctorName, string doctorSpecialization, string doctorSchedule)
        : id(doctorId), name(doctorName),
          specialization(doctorSpecialization), schedule(doctorSchedule) {}

    int getId() const { return id; }

    void display() const {
        cout << "\nDoctor ID: " << id
             << "\nName: " << name
             << "\nSpecialization: " << specialization
             << "\nSchedule: " << schedule << "\n";
    }
};

class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    int nextPatientId = 1;
    int nextDoctorId = 1;

    int findPatientIndex(int id) const {
        for (int i = 0; i < static_cast<int>(patients.size()); i++)
            if (patients[i].getId() == id) return i;
        return -1;
    }

    int findDoctorIndex(int id) const {
        for (int i = 0; i < static_cast<int>(doctors.size()); i++)
            if (doctors[i].getId() == id) return i;
        return -1;
    }

    int readInteger(const string& message) {
        int value;
        while (true) {
            cout << message;
            if (cin >> value) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    string readText(const string& message) {
        string value;
        while (true) {
            cout << message;
            getline(cin, value);
            if (value.find_first_not_of(" \t\r\n") != string::npos) return value;
            cout << "Input cannot be empty.\n";
        }
    }

public:
    void addPatient() {
        cout << "\n--- Add New Patient ---\n";
        string name = readText("Enter patient name: ");
        int age;
        do {
            age = readInteger("Enter patient age: ");
            if (age < 0 || age > 130)
                cout << "Enter a valid age between 0 and 130.\n";
        } while (age < 0 || age > 130);
        string condition = readText("Enter medical condition: ");
        patients.emplace_back(nextPatientId++, name, age, condition);
        cout << "Patient added successfully.\n";
    }

    void displayPatients() const {
        cout << "\n--- Patient Records ---\n";
        if (patients.empty()) {
            cout << "No patients registered.\n";
            return;
        }
        for (const Patient& patient : patients) patient.display();
    }

    void searchPatient() const {
        cout << "\n--- Search Patient ---\n";
        int id = readInteger("Enter patient ID: ");
        int index = findPatientIndex(id);
        if (index == -1) cout << "Patient not found.\n";
        else patients[index].display();
    }

    void admitPatient() {
        cout << "\n--- Patient Admission ---\n";
        int id = readInteger("Enter patient ID: ");
        int index = findPatientIndex(id);
        if (index == -1) cout << "Patient not found.\n";
        else if (patients[index].isAdmitted()) cout << "Patient is already admitted.\n";
        else {
            patients[index].admit();
            cout << "Patient admitted successfully.\n";
        }
    }

    void dischargePatient() {
        cout << "\n--- Patient Discharge ---\n";
        int id = readInteger("Enter patient ID: ");
        int index = findPatientIndex(id);
        if (index == -1) cout << "Patient not found.\n";
        else if (!patients[index].isAdmitted())
            cout << "Patient is not currently admitted.\n";
        else {
            patients[index].discharge();
            cout << "Patient discharged successfully.\n";
        }
    }

    void addDoctor() {
        cout << "\n--- Add New Doctor ---\n";
        string name = readText("Enter doctor name: ");
        string specialization = readText("Enter specialization: ");
        string schedule = readText("Enter schedule (e.g. Sunday 9 AM - 1 PM): ");
        doctors.emplace_back(nextDoctorId++, name, specialization, schedule);
        cout << "Doctor added successfully.\n";
    }

    void displayDoctors() const {
        cout << "\n--- Doctor Directory & Schedules ---\n";
        if (doctors.empty()) {
            cout << "No doctors registered.\n";
            return;
        }
        for (const Doctor& doctor : doctors) doctor.display();
    }

    void searchDoctor() const {
        cout << "\n--- Search Doctor ---\n";
        int id = readInteger("Enter doctor ID: ");
        int index = findDoctorIndex(id);
        if (index == -1) cout << "Doctor not found.\n";
        else doctors[index].display();
    }

    void run() {
        int choice;
        do {
            cout << "\n=================================\n";
            cout << "   HOSPITAL MANAGEMENT SYSTEM\n";
            cout << "=================================\n";
            cout << "1. Add Patient\n";
            cout << "2. Display All Patients\n";
            cout << "3. Search Patient\n";
            cout << "4. Admit Patient\n";
            cout << "5. Discharge Patient\n";
            cout << "6. Add Doctor\n";
            cout << "7. Display Doctors & Schedules\n";
            cout << "8. Search Doctor\n";
            cout << "0. Exit\n";
            cout << "=================================\n";
            choice = readInteger("Enter your choice: ");

            switch (choice) {
                case 1: addPatient(); break;
                case 2: displayPatients(); break;
                case 3: searchPatient(); break;
                case 4: admitPatient(); break;
                case 5: dischargePatient(); break;
                case 6: addDoctor(); break;
                case 7: displayDoctors(); break;
                case 8: searchDoctor(); break;
                case 0: cout << "Thank you for using the system.\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    HospitalManagementSystem hospital;
    hospital.run();
    return 0;
}
