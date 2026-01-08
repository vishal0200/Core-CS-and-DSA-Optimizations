#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

class LibraryManager {
private:
    const string fileName = "bookData.txt";

public:
    void addBook();
    void showAllBooks();
    void extractBook();
};

int main() {
    LibraryManager library;
    char choice;

    while (true) {
        cout << "\n----------------------------------\n";
        cout << "1 - Show All Books\n";
        cout << "2 - Extract Book\n";
        cout << "3 - Add Book (ADMIN)\n";
        cout << "4 - Exit\n";
        cout << "----------------------------------\n";
        cout << "Enter Your Choice: ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case '1':
            library.showAllBooks();
            break;
        case '2':
            library.extractBook();
            break;
        case '3':
            library.addBook();
            break;
        case '4':
            cout << "\nExiting program...\n";
            return 0;
        default:
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}

void LibraryManager::addBook() {
    string id, name, author;
    string fileId, fileNameTemp, fileAuthor;
    bool exists = false;

    cout << "\n----- ADD BOOK -----";
    cout << "\nEnter Book ID: ";
    getline(cin, id);

    cout << "Enter Book Name: ";
    getline(cin, name);

    cout << "Enter Author Name: ";
    getline(cin, author);

    // Check for duplicate ID
    ifstream inFile(fileName);
    while (getline(inFile, fileId, '*') &&
           getline(inFile, fileNameTemp, '*') &&
           getline(inFile, fileAuthor)) {
        if (fileId == id) {
            exists = true;
            break;
        }
    }
    inFile.close();

    if (exists) {
        cout << "\nBook with this ID already exists.\n";
        return;
    }

    ofstream outFile(fileName, ios::app);
    outFile << id << "*" << name << "*" << author << endl;
    outFile.close();

    cout << "\nBook added successfully.\n";
}

void LibraryManager::showAllBooks() {
    string id, name, author;
    ifstream file(fileName);

    if (!file) {
        cout << "\nNo books found.\n";
        return;
    }

    cout << "\n\nBook ID\t\tBook Name\t\tAuthor\n";
    cout << "-----------------------------------------------\n";

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author)) {
        cout << id << "\t\t" << name << "\t\t" << author << endl;
    }

    file.close();
}

void LibraryManager::extractBook() {
    string searchId;
    string id, name, author;
    bool found = false;

    showAllBooks();

    cout << "\nEnter Book ID to extract: ";
    getline(cin, searchId);

    ifstream inFile(fileName);
    ofstream tempFile("temp.txt");

    while (getline(inFile, id, '*') &&
           getline(inFile, name, '*') &&
           getline(inFile, author)) {

        if (id == searchId) {
            found = true;
            cout << "\nBook Extracted Successfully:\n";
            cout << "ID: " << id << ", Name: " << name
                 << ", Author: " << author << endl;
        } else {
            tempFile << id << "*" << name << "*" << author << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove(fileName.c_str());
    rename("temp.txt", fileName.c_str());

    if (!found) {
        cout << "\nBook not found.\n";
    }
}