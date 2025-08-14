#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
    string issuedTo;
    string issueDate;
    string returnDate;
    Book* next;
};

class Library {
private:
    Book* head;

public:
    Library() {
        head = NULL;
        addBook(1, "C++ Programming", "Bjarne Stroustrup", false);
        addBook(2, "Clean Code", "Robert C Martin", false);
        addBook(3, "The Pragmatic Programmer", "Andy Hunt", false);
        addBook(4, "Design Patterns", "Erich Gamma", false);
        addBook(5, "Algorithms Unlocked", "Thomas Cormen", false);
        addBook(6, "Data Structures in C++", "Adam Drozdek", false);
        addBook(7, "Effective Modern C++", "Scott Meyers", false);
        addBook(8, "Introduction to Algorithms", "CLRS", false);
        addBook(9, "Object Oriented Programming", "Grady Booch", false);
        addBook(10, "Programming Pearls", "Jon Bentley", false);
    }

    string getCurrentDate() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        char dateStr[11];
        strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", ltm);
        return string(dateStr);
    }

    void addBook(int id, string title, string author, bool showMessage = true) {
        Book* newBook = new Book{id, title, author, false, "", "", "", NULL};
        if (!head) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
        if (showMessage) {
            cout << "✅ Book added successfully.\n";
        }
    }

    void displayBooks() {
        if (!head) {
            cout << "📚 No books in the library.\n";
            return;
        }
        Book* temp = head;
        while (temp) {
            cout << "\n📘 ID: " << temp->id
                 << "\n  Title: " << temp->title
                 << "\n  Author: " << temp->author
                 << "\n  Status: " << (temp->isIssued ? "Issued" : "Available");
            if (temp->isIssued) {
                cout << "\n  Issued To: " << temp->issuedTo
                     << "\n  Issued On: " << temp->issueDate;
            }
            if (!temp->returnDate.empty()) {
                cout << "\n  Returned On: " << temp->returnDate;
            }
            cout << "\n-------------------------";
            temp = temp->next;
        }
    }

    void searchBook(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "\n🔍 Book Found:";
                cout << "\n📘 Title: " << temp->title
                     << "\n✍️ Author: " << temp->author
                     << "\n📦 Status: " << (temp->isIssued ? "Issued" : "Available");
                if (temp->isIssued) {
                    cout << "\n👤 Issued To: " << temp->issuedTo
                         << "\n📅 Issued On: " << temp->issueDate;
                }
                if (!temp->returnDate.empty()) {
                    cout << "\n📥 Returned On: " << temp->returnDate;
                }
                cout << "\n-------------------------\n";
                return;
            }
            temp = temp->next;
        }
        cout << "❌ Book not found.\n";
    }

    void issueBook(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->id == id) {
                if (!temp->isIssued) {
                    cout << "👤 Enter Student Name: ";
                    cin.ignore();
                    getline(cin, temp->issuedTo);
                    temp->isIssued = true;
                    temp->issueDate = getCurrentDate();
                    temp->returnDate = "";
                    cout << "✅ Book issued to " << temp->issuedTo << " on " << temp->issueDate << ".\n";
                } else {
                    cout << "⚠️ Book is already issued to " << temp->issuedTo << ".\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "❌ Book not found.\n";
    }

    void returnBook(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->id == id) {
                if (temp->isIssued) {
                    temp->isIssued = false;
                    temp->returnDate = getCurrentDate();
                    cout << "✅ Book returned successfully on " << temp->returnDate << ".\n";
                    temp->issuedTo = "";
                    temp->issueDate = "";
                } else {
                    cout << "⚠️ Book was not issued.\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "❌ Book not found.\n";
    }

    void deleteBook(int id) {
        if (!head) {
            cout << "📚 No books to delete.\n";
            return;
        }

        if (head->id == id) {
            Book* temp = head;
            head = head->next;
            delete temp;
            cout << "🗑️ Book deleted successfully.\n";
            return;
        }

        Book* curr = head;
        while (curr->next && curr->next->id != id) {
            curr = curr->next;
        }

        if (curr->next) {
            Book* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            cout << "🗑️ Book deleted successfully.\n";
        } else {
            cout << "❌ Book not found.\n";
        }
    }

    ~Library() {
        while (head) {
            Book* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Library lib;
    int choice, id;
    string title, author;

    do {
        cout << "\n===== 📚 Library Management Menu =====\n";
        cout << "1. ➕ Add New Book to Library\n";
        cout << "2. 📖 Display All Books\n";
        cout << "3. 🔍 Search Book by ID\n";
        cout << "4. 🧑‍🎓 Issue Book to Student\n";
        cout << "5. 🔁 Return Book from Student\n";
        cout << "6. ❌ Delete Book from Library\n";
        cout << "7. 🚪 Exit System\n";
        cout << "Choose an option (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                lib.addBook(id, title, author);
                break;

            case 2:
                lib.displayBooks();
                break;

            case 3:
                cout << "Enter Book ID to search: ";
                cin >> id;
                lib.searchBook(id);
                break;

            case 4:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                lib.issueBook(id);
                break;

            case 5:
                cout << "Enter Book ID to return: ";
                cin >> id;
                lib.returnBook(id);
                break;

            case 6:
                cout << "Enter Book ID to delete: ";
                cin >> id;
                lib.deleteBook(id);
                break;

            case 7:
                cout << "👋 Exiting system. Goodbye!\n";
                break;

            default:
                cout << "⚠️ Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}