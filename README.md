# 🏥 Hospital Management System (C Project)

A simple and functional **Hospital Management System** built using **C language**.
It allows you to manage **patients and doctors**, including admission, discharge, and listing records.
Data is stored in local text files using file handling in C.

---

## 🚀 Features

### 👨‍⚕️ Patient Management

* Admit a new patient
* Store patient details: ID, Name, Address, Disease, Admission Date
* View all patients
* Discharge a patient (removes record)

### 🩺 Doctor Management

* Add a new doctor
* Store doctor details: ID, Name, Address, Specialization, Date
* View all doctors

### 📁 File Handling

* All patient data stored in **patient.txt**
* All doctor data stored in **doctor.txt**
* Temporary file usage for delete operation

### 🎨 Console Highlights

* Colored text using ANSI escape codes
* Clean and readable console output
* Simple menu-driven interface

---

## 📂 Project Structure

```
Hospital Management System/
│── hospital.c
│── patient.txt        (auto-created)
│── doctor.txt         (auto-created)
│── temp.txt           (auto-created for delete operations)
└── README.md
```

---

## 🛠️ Technologies Used

* **C Programming Language**
* **File Handling (Binary read/write)**
* **Structures (`struct`)**
* **ANSI Color Codes for UI**
* **Time Library** for auto-generating date

---

## 🧵 How It Works

### 🎛️ Main Menu

```
1. Admit Patient
2. Patient List
3. Discharge Patient
4. Add Doctor
5. Doctors List
0. Exit
```

### ➿ Functional Flow

* User selects an option
* Corresponding function executes (`admitPatient()`, `doctorList()` etc.)
* Data is written/read from file
* Returns to main menu

---

## ▶️ How to Run

### **Using GCC**

```bash
gcc hospital.c -o hospital
./hospital
```

### **On Windows (MinGW)**

```bash
gcc hospital.c -o hospital.exe
hospital.exe
```

> Ensure `conio.h` is available (supported by TurboC/MinGW on Windows).

---

## 📝 Future Improvements (optional)

You may add these to impress recruiters:

* Edit patient/doctor record
* Search by name/id
* Login/Authentication system
* Convert `.txt` to `.csv` for easier viewing
* GUI version using Python/Java/Qt

---

## 📜 Author

**Mrunal Joshi**
Hospital Management System built using the C programming language.


Just tell me!
