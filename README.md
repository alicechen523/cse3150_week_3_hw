This program manages student names and their GPAs and stores them in two separate arrays. The menu allows the user to have different options: add a student and their GPA, update a GPA, prints all stored students, and computing the average GPA of all the students. 

This program uses pointers and arrays to store data. The main function initializes an array called names (char* names[capacity]) that has size capacity, with each index storing a char pointer that we allocate space on the heap every time a new student is added. double gpas[capacity] is an array that stores doubles and we can use pointers as function parameters to either set names[] or gpas[] to a specific value or memory address. 

consts are used in the function parameters to prevent data from being modified during the function call. For example, in printStudent() and averageGPA(), we do not make any changes to the values, so we apply const to those variables. We use references (&) similarly to pointers to save changes to the variable after the function call. 

We use casting in averageGPA() to convert the double sum to an int to show that this is a valid conversion using static_cast. Errors are handled by throwing exceptions when they are raised, such as when the student list is at capacity or if gpas[] is empty when attempting to calculate averageGPA(). 

The program's control flow is handed using a do-while loop as long as the user does not quit the menu system. A switch statement is used to handle the different menu options and breaks after every case to return back to the menu. 
