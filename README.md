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



Resume Samples

resume1.txt (Software Engineer)

Name: John Doe
Education: Bachelor
Experience: 3 years
Skills: C, C++, Java, Python, SQL

resume2.txt (Data Scientist)

Name: Alice Smith
Education: Master
Experience: 4 years
Skills: Python, R, Machine Learning, Data Visualization, SQL

resume3.txt (Cyber Security Analyst)

Name: Michael Johnson
Education: Bachelor
Experience: 2 years
Skills: Network Security, Penetration Testing, Ethical Hacking, SIEM Tools

resume4.txt (Cloud Engineer)

Name: Emily Davis
Education: Bachelor
Experience: 3 years
Skills: AWS, Azure, Docker, Kubernetes, Terraform

resume5.txt (Full Stack Developer)

Name: Robert Brown
Education: Bachelor
Experience: 4 years
Skills: React, Node.js, Express.js, MongoDB, REST APIs, TypeScript

resume6.txt (Software Engineer - Another Candidate)

Name: Sarah Johnson
Education: Bachelor
Experience: 5 years
Skills: Java, Python, JavaScript, SQL, Git

resume7.txt (Data Scientist - Another Candidate)

Name: David Miller
Education: Master
Experience: 3 years
Skills: Python, TensorFlow, NLP, SQL, Deep Learning

