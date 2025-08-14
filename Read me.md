# Library Management System

This C++ program implements a simple Library Management System. It allows users to manage a collection of books, including adding, displaying, searching, issuing, returning, and deleting books.

## Features

-   **Add Book:** Add new books to the library with details like ID, title, and author.
-   **Display Books:** View all books in the library with their details and status.
-   **Search Book:** Search for a book by its ID.
-   **Issue Book:** Issue a book to a student, recording the student's name and issue date.
-   **Return Book:** Return a book, marking it as available and recording the return date.
-   **Delete Book:** Remove a book from the library.
-   **Date Tracking:** Automatically tracks issue and return dates.
-   **User-Friendly Menu:** Provides a simple menu-driven interface for easy interaction.

## How to Compile and Run

1.  **Clone the repository (if applicable) or copy the code:**
    ```bash
    git clone [repository URL] #If you have the git repository
    ```

2.  **Compile the C++ code:**
    ```bash
    g++ main.cpp -o library
    ```
    (Ensure you have a C++ compiler like g++ installed.)

3.  **Run the executable:**
    ```bash
    ./library
    ```

4.  **Follow the menu prompts:** The program will display a menu of options. Enter the corresponding number to perform an action.

## Code Structure

-   **`Book` struct:** Defines the structure for a book, including its ID, title, author, issue status, and date information.
-   **`Library` class:** Manages the collection of books using a linked list. It contains methods for adding, displaying, searching, issuing, returning, and deleting books.
-   **`main()` function:** Provides the main menu loop and handles user input.

## Dependencies

-   Standard C++ libraries: `iostream`, `string`, `ctime`. No external libraries are required.

## Example Usage

1.  **Add a book:**
    -   Select option 1.
    -   Enter the book's ID, title, and author.

2.  **Display all books:**
    -   Select option 2.
    -   The program will display a list of all books with their details.

3.  **Issue a book:**
    -   Select option 4.
    -   Enter the book's ID and the student's name.

4.  **Return a book:**
    -   Select option 5.
    -   Enter the book's ID.

5.  **Exit the program:**
    -   Select option 7.

## Notes

-   The program uses a linked list to store books, allowing for dynamic memory allocation.
-   Date information is automatically generated using the `ctime` library.
-   Input validation is minimal; ensure correct input formats are used.
-   This is a simple implementation and can be extended with additional features like user authentication, file storage, and advanced search options.