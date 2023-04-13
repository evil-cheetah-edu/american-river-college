# SAT Course Scheduler

## Specifications

Given `5` subjects: `A`, `B`, `C`, `D`, `E`

The following periods `CANNOT BE` **on the same period**:
- A and B
- B and E
- D and C
- C and E
___
`Requirements`:
- Output the rows that meet criteria
- Create a function `initTable` that initializes a table of courses
- Create a function `isRowSat` that checks for the following criteria