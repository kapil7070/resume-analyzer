# Resume Analyzer

## Description

The Resume Analyzer is a modular C program that reads one or more resume files, analyzes them against specific job requirements, scores each resume, and then selects the best candidate based on the highest score. The program follows a modular design with header files in the `header` folder and source files in the `src` folder.

## Project Structure

project/ 
├── header/ │ 
   ├── resume.h │ 
   ├── resume_parser.h │ 
   ├── job.h │ ├── scoring.h │ 
   └── utils.h 
   
└── src/ 
├── main.c 
├── resume_parser.c 
├── job.c 
├── scoring.c 
└── utils.c


## Resume File Format

Each resume file should be a plain text file formatted as follows (order of lines can vary):
Name: John Doe 
Education: Bachelor's in Computer Science 
Experience: 3 
Skills: C, C++, Java, Python


## Prerequisites

- A C compiler such as GCC or Microsoft Visual Studio's `cl.exe`.
- **Windows Users:** The project includes a macro to map `strcasecmp` to `_stricmp` for MSVC compatibility.

## Build Instructions

### Using GCC (Linux/Windows MinGW)

Open a terminal in the project directory and run:

```bash
gcc -I header src/main.c src/resume_parser.c src/job.c src/scoring.c src/utils.c -o resume_analyzer
```
Using MSVC (cl.exe)
Open the Developer Command Prompt and run:

```bash
cl /I header src\main.c src\resume_parser.c src\job.c src\scoring.c src\utils.c 
```
Execution
After building the project, run the program from the command line. For example, to analyze resumes for a "Software Engineer" position:
```bash
 .\main.exe "Software Engineer" resume1.txt resume2.txt
```

