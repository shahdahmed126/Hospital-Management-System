# Hospital Management System (C++)

A console-based Hospital Management System written in C++. This educational project demonstrates object-oriented programming and basic record management.

## Features

### Patient management
- Add patients with automatically assigned IDs.
- Display all patient records.
- Search for a patient by ID.
- Admit and discharge patients.
- Show each patient's admission status.
- Validate age (0–130) and prevent empty text fields.

### Doctor management
- Add doctors with automatically assigned IDs.
- Store each doctor's name, specialization, and schedule.
- Display the doctor directory and schedules.
- Search for a doctor by ID.

## Technologies
- C++
- Standard Library: `iostream`, `vector`, `string`, `limits`

## Project structure

```text
Hospital_Management_System/
├── main.cpp
└── README.md
```

## How to compile and run

With `g++`, open a terminal in this folder and run:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o hospital
./hospital
```

On Windows PowerShell, run the generated executable with:

```powershell
.\hospital.exe
```

You can also open `main.cpp` in Code::Blocks or Visual Studio and build/run the project.

## Example output

The following is an illustrative sample session. IDs start at 1 and are assigned automatically during each run.

```text
=================================
   HOSPITAL MANAGEMENT SYSTEM
=================================
1. Add Patient
2. Display All Patients
3. Search Patient
4. Admit Patient
5. Discharge Patient
6. Add Doctor
7. Display Doctors & Schedules
8. Search Doctor
0. Exit
=================================
Enter your choice: 1

--- Add New Patient ---
Enter patient name: Sara Ali
Enter patient age: 28
Enter medical condition: Flu
Patient added successfully.

Enter your choice: 2

--- Patient Records ---

Patient ID: 1
Name: Sara Ali
Age: 28
Condition: Flu
Admission Status: Not Admitted

Enter your choice: 4

--- Patient Admission ---
Enter patient ID: 1
Patient admitted successfully.

Enter your choice: 6

--- Add New Doctor ---
Enter doctor name: Dr. Omar Hassan
Enter specialization: Cardiology
Enter schedule (e.g. Sunday 9 AM - 1 PM): Sunday 9 AM - 1 PM
Doctor added successfully.

Enter your choice: 7

--- Doctor Directory & Schedules ---

Doctor ID: 1
Name: Dr. Omar Hassan
Specialization: Cardiology
Schedule: Sunday 9 AM - 1 PM

Enter your choice: 0
Thank you for using the system.
```

## OOP concepts demonstrated
- **Encapsulation:** Patient and Doctor data are kept in private fields.
- **Classes and objects:** `Patient`, `Doctor`, and `HospitalManagementSystem`.
- **Vectors:** Records are held in `vector` containers while the program is running.
- **Searching:** Records are found by their IDs.
- **Input validation:** Numeric input and empty text are checked.
- **Control flow:** Loops and `switch` statements drive the menu.

## Limitations
- Records are stored in memory only and disappear when the program exits.
- This is a learning/demo project, not a production hospital system.
- It does not include a database, authentication, appointments, billing, or medical-record security.

## Possible future improvements
- Save/load records using files or a database.
- Add appointment booking.
- Add login and role-based access.
- Add edit/delete operations.
- Add unit tests.

## License
Provided for educational use.
