#include <iostream>
#include <cstring>   // for strlen, strcpy

using std::cout, std::endl, std::cin, std::string;

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
	if (size >= capacity)
		throw string("List full");
	names[size] = name;
	gpas[size] = gpa;
	size++;
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa) {
	if (gpaPtr != nullptr)
		*gpaPtr = newGpa;
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa) {
	cout << "Name: " << name << endl;
	cout << "GPA: " << gpa << endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size) {
	if (size == 0)
		throw string("No students");
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		sum += gpas[i];
	}
	return static_cast<int> (sum)/size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
		try {
			string n;
			cout << "Enter student name: ";
			cin >> n;
			char* name = new char[n.size() + 1];

			strcpy(name, n.c_str());

			double gpa;
			cout << "Enter student gpa: ";
			cin >> gpa;

			addStudent(name, gpa, names, gpas, size, capacity);
		} catch (string error_msg) {
			cout << error_msg << endl;
			return 1;
		}
                break;
            }
            case 2: {
                // TODO: implement menu logic
		int old_gpa_idx;
		cout << "Enter index to change: ";
		cin >> old_gpa_idx;
			    
		double new_gpa;
		cout << "Enter new GPA: ";
		cin >> new_gpa;

		updateGPA(&gpas[old_gpa_idx], new_gpa);
		break;
            }
            case 3: {
                // TODO: implement menu logic
		for (int i = 0; i < size; i++) {
			printStudent(names[i], gpas[i]);
		}
                break;
            }
            case 4: {
                // TODO: implement menu logic
		try {
			cout << "Average GPA: " << averageGPA(gpas, size) << endl;
		} catch (string error) {
			cout << error << endl;
		}
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory 
    if (size > 0) {
    	for (int i = 0; i < size; i++) {
		delete names[i];
	}
    }
    return 0;
}
