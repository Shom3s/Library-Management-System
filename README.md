# 📚 Library Management System

A **C++ Library Management System** developed to manage library books and their records efficiently.

The system uses **CSV file storage** to save and retrieve library data, providing a simple implementation of file handling and record management using C++.

---

## 📌 Project Overview

The **Library Management System** is a C++ application designed to simplify basic library operations.

The project demonstrates how C++ can be used to manage structured records while storing data persistently in a CSV file.

---

## ✨ Features

- 📚 Manage library records
- ➕ Add new records
- 🔍 Search and retrieve records
- ✏️ Update existing information
- 🗑️ Manage stored records
- 📋 Display library information
- 💾 Save data using CSV file storage
- 🔄 Read existing data from CSV files
- ✅ Basic input and data validation

---

## 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| **C++** | Main programming language |
| **CSV** | Data storage |
| **File Handling** | Reading and writing records |
| **Visual Studio** | Development environment |

---

## 📂 Project Structure

```text
Library-Management-System/
│
├── AA project Library Management System.sln
├── AA project Library Management System.vcxproj
├── AA project Library Management System.vcxproj.filters
├── AA project Library Management System.vcxproj.user
│
├── LibraryData.csv
├── Source.cpp
│
└── README.md
```

---

## 📁 Important Files

### `Source.cpp`

Contains the main **C++ source code** and application logic for the Library Management System.

### `LibraryData.csv`

Stores the library records and allows information to remain available after the program is closed.

### `AA project Library Management System.sln`

Visual Studio solution file used to open the complete project.

### `AA project Library Management System.vcxproj`

Contains the Visual Studio C++ project configuration.

---

## ⚙️ How the System Works

```text
User
  │
  ▼
Library Management System
  │
  ▼
Select Operation
  │
  ├── Add Record
  ├── View Records
  ├── Search Record
  ├── Update Record
  └── Manage Records
  │
  ▼
Process Request
  │
  ▼
Read / Write LibraryData.csv
  │
  ▼
Display Result
```

---

## 💾 Data Storage

The system uses:

```text
LibraryData.csv
```

to store library information.

The basic data flow is:

```text
User Input
    │
    ▼
C++ Application
    │
    ▼
File Handling
    │
    ▼
LibraryData.csv
```

Using CSV storage keeps the project lightweight and eliminates the need for a separate database server.

---

## 🚀 Getting Started

### Prerequisites

Make sure you have:

- Visual Studio with C++ development tools

or

- A compatible C++ compiler such as GCC/G++

---

## 📥 Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/Library-Management-System.git
```

Navigate into the project:

```bash
cd Library-Management-System
```

---

## ▶️ How to Run

### Using Visual Studio

1. Clone or download this repository.
2. Open:

```text
AA project Library Management System.sln
```

3. Make sure `LibraryData.csv` is available in the required directory.
4. Build the solution.
5. Run the application.
6. Select the desired library operation.

---

### Using G++

You can also try compiling the source file manually:

```bash
g++ Source.cpp -o LibraryManagementSystem
```

Run on Windows:

```bash
LibraryManagementSystem.exe
```

Run on Linux/macOS:

```bash
./LibraryManagementSystem
```

> Some changes may be required if the original source code uses Visual Studio-specific functionality.

---

## 🎯 Programming Concepts Demonstrated

This project demonstrates knowledge of:

- C++ Programming
- Object-Oriented Programming (OOP)
- File Handling
- CSV Data Processing
- CRUD Operations
- Data Validation
- Conditional Statements
- Loops
- Functions
- Record Management
- Problem Solving

---

## 🔮 Future Improvements

- [ ] Replace CSV storage with MySQL
- [ ] Add user authentication
- [ ] Add librarian and member accounts
- [ ] Add book borrowing and return tracking
- [ ] Add due-date management
- [ ] Add overdue fine calculation
- [ ] Add graphical user interface (GUI)
- [ ] Add advanced book searching
- [ ] Add database integration
- [ ] Develop a web or mobile version

---

## 👨‍💻 Author

**Shomeswaran A/L Mugunthan**

Bachelor of Computer Science (Software Development) with Honours  
Universiti Teknikal Malaysia Melaka (UTeM)

🌐 **Portfolio:** [https://shomeswaran.xyz](https://shomeswaran.xyz)

📧 **Email:** [shomezwaran@gmail.com](mailto:shomezwaran@gmail.com)

---

## 📄 License

This project was developed for **educational and academic purposes**.

---

⭐ **If you find this project useful, feel free to star the repository!**
