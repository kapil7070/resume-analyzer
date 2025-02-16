# Resume Analysis System

This is an educational Resume Analysis System implemented in C that demonstrates fundamental programming concepts. The system allows users to:
- Add and manage resumes with skills and experience
- Add job positions with requirements
- Analyze how well a resume matches a job position
- Get detailed feedback and recommendations

## Project Structure
```
├── include/
│   ├── resume.h    (Header file with data structures and function declarations)
│   └── utils.h     (Header file for utility functions)
├── src/
│   ├── main.c      (Main program with menu interface)
│   ├── resume.c    (Resume and job matching implementation)
│   └── utils.c     (Helper functions for UI and input)
├── Makefile        (For easy compilation)
└── README.md       (This file)
```

## How to Compile and Run

### Using Make (Recommended)
1. Open terminal in the project directory
2. Run:
   ```bash
   make
   ./resume_analyzer
   ```

### Manual Compilation
If you don't have Make installed, you can compile manually:
```bash
gcc src/main.c src/resume.c src/utils.c -o resume_analyzer
./resume_analyzer
```

## Features
1. Resume Management
   - Add new resumes with personal information
   - Input skills and work experience
   - View all stored resumes

2. Job Position Management
   - Add new job positions
   - Specify required skills and experience
   - View all job positions

3. Analysis and Matching
   - Compare resumes against job requirements
   - Get detailed match analysis
   - Receive recommendations for improvement

## Usage
1. Start by adding a resume (Option 1)
2. Add a job position (Option 2)
3. Use the analysis feature (Option 5) to see how well the resume matches the job

## Educational Value
This project demonstrates:
- Structured Programming in C
- Data Structures (structs)
- File I/O Operations
- User Input Handling
- Algorithm Implementation (matching logic)
