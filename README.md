# OOP Project — Examination System

Console-based Examination Management System implemented in C++ (Windows). The application manages teacher and student login flows, a question bank, quiz generation, scheduled quizzes with timers, and basic quiz result analysis.

## Key Features
- Teacher and student login and display flows.
- Load instructors from `csvs/instructor.csv` and students from `csvs/student.csv`.
- Question bank and quiz generation stored as binary files under `bin/`.
- Generate quizzes from the question bank or create custom quizzes.
- Quiz timers and simple answer/key analysis.

## Project layout
- `examination_system.cpp` — Main C++ source file.
- `bin/` — Binary quiz files (e.g., `pf.bin`, `oop.bin`, `new_quiz.bin`).
- `csvs/` — Input CSV files: `instructor.csv`, `student.csv`.
- `OOP project report.pdf` / `OOP project report.docx` — Documentation.

> Note: The repository was reorganized so CSVs live in `csvs/` and `.bin` quiz files live in `bin/`. The code references these relative paths.

## Build & Run (Windows)
This project uses `windows.h` and `conio.h` so MSVC/Visual Studio is recommended.

- Using Visual Studio (Developer Command Prompt):

```powershell
cl /EHsc examination_system.cpp
examination_system.exe
```

- Using MinGW/G++ (may require compatible headers):

```powershell
g++ -o examination_system.exe examination_system.cpp
./examination_system.exe
```

If you encounter missing header errors, compile with MSVC or install a MinGW distribution that provides `windows.h` and `conio.h`.

## Data files & paths used by the code
- `csvs/instructor.csv` — used in `login::teacher_login()`.
- `csvs/student.csv` — used in `login::student_login()` and `course_registration`.
- `bin/` — contains `.bin` quiz files referenced in `teacher::set_q_paper()` (e.g., `bin/pf.bin`).

If you move these files, update the paths in `examination_system.cpp` accordingly.

## License
MIT
