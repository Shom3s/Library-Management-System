#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;

// Structure to represent a book in the Library Management System
struct Book {
    int bookID;
    string title;
    string author;
    int yearPublished;
    string genre;
    double price;
    int copiesAvailable;
    double rating;
};

const int DATA_SIZE = 10000;
const int SEARCH_SIZE = 100;
Book library[DATA_SIZE]; // Array for storing books
Book searchBooks[SEARCH_SIZE]; // Array for search inputs

// Function to generate random values
template <typename T>
T getRandomValue(T min, T max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate random book data
void generateData() {
    const string titles[] = { "The Great Gatsby", "1984", "To Kill a Mockingbird", "Pride and Prejudice", "Moby Dick", "War and Peace", "The Odyssey", "Ulysses", "The Catcher in the Rye", "Jane Eyre" };
    const string authors[] = { "F. Scott Fitzgerald", "George Orwell", "Harper Lee", "Jane Austen", "Herman Melville", "Leo Tolstoy", "Homer", "James Joyce", "J.D. Salinger", "Charlotte Bronte" };
    const string genres[] = { "Fiction", "Classic", "Drama", "Romance", "Adventure", "Mystery", "Fantasy", "Horror", "Science Fiction", "Biography" };

    for (int i = 0; i < DATA_SIZE; ++i) {
        library[i].bookID = i + 1;
        library[i].title = titles[getRandomValue(0, 9)];
        library[i].author = authors[getRandomValue(0, 9)];
        library[i].yearPublished = getRandomValue(1900, 2024);
        library[i].genre = genres[getRandomValue(0, 9)];
        library[i].price = getRandomValue(100, 1000);
        library[i].copiesAvailable = getRandomValue(1, 20);
        library[i].rating = static_cast<double>(getRandomValue(1, 100)) / 10.0;
    }

    for (int i = 0; i < SEARCH_SIZE; ++i) {
        searchBooks[i].bookID = getRandomValue(1, DATA_SIZE + 5000); // IDs out of range for testing
    }
}

// Function to save the data to a CSV file
void saveToCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file for writing: " << filename << endl;
        return;
    }

    file << "BookID,Title,Author,YearPublished,Genre,Price,CopiesAvailable,Rating\n";
    for (int i = 0; i < DATA_SIZE; ++i) {
        file << library[i].bookID << ","
            << library[i].title << ","
            << library[i].author << ","
            << library[i].yearPublished << ","
            << library[i].genre << ","
            << library[i].price << ","
            << library[i].copiesAvailable << ","
            << library[i].rating << "\n";
    }

    file.close();
    cout << "Data successfully saved to " << filename << endl;
}

// Function to display the first N books
void displayBooks(Book arr[], int size, int count) {
    for (int i = 0; i < count && i < size; ++i) {
        cout << "BookID: " << arr[i].bookID
            << " | Title: " << arr[i].title
            << " | Author: " << arr[i].author
            << " | Year: " << arr[i].yearPublished
            << " | Genre: " << arr[i].genre
            << " | Price: " << arr[i].price
            << " | Copies: " << arr[i].copiesAvailable
            << " | Rating: " << arr[i].rating << endl;
    }
}

// Bubble Sort with swap count
void bubbleSort(Book arr[], int size, bool (*compare)(Book, Book), int& swapCount) {
    swapCount = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (compare(arr[j + 1], arr[j])) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
}

// Quick Sort with swap count
int partition(Book arr[], int low, int high, bool (*compare)(Book, Book), int& swapCount) {
    Book pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (compare(arr[j], pivot)) {
            ++i;
            swap(arr[i], arr[j]);
            swapCount++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swapCount++;
    return i + 1;
}

void quickSort(Book arr[], int low, int high, bool (*compare)(Book, Book), int& swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, compare, swapCount);
        quickSort(arr, low, pi - 1, compare, swapCount);
        quickSort(arr, pi + 1, high, compare, swapCount);
    }
}

// Linear Search
bool linearSearch(Book arr[], int size, int id, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; ++i) {
        comparisons++;
        if (arr[i].bookID == id) {
            return true;
        }
    }
    return false;
}

// Binary Search
int binarySearch(Book arr[], int size, int id, int& comparisons) {
    int left = 0, right = size - 1;
    comparisons = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid].bookID == id) {
            return mid;
        }
        else if (arr[mid].bookID < id) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Comparator function for sorting
bool compareByBookID(Book a, Book b) {
    return a.bookID < b.bookID;
}


// Function to calculate the total value of books in stock
void calculateTotalValue() {
    double totalValue = 0;
    for (int i = 0; i < DATA_SIZE; ++i) {
        totalValue += library[i].price * library[i].copiesAvailable;
    }
    cout << "\nThe total value of books in stock is: RM" << totalValue << endl;
}

// Function to generate a report of highly rated books
void generateHighlyRatedReport() {
    double threshold;
    cout << "Enter the rating threshold: ";
    cin >> threshold;

    cout << "\nBooks with a rating above " << threshold << ":\n";
    for (int i = 0; i < DATA_SIZE; ++i) {
        if (library[i].rating > threshold) {
            cout << "BookID: " << library[i].bookID
                << " | Title: " << library[i].title
                << " | Rating: " << library[i].rating << endl;
        }
    }
}

// Function to simulate purchasing a book
void purchaseBook() {
    int bookID, quantity;
    cout << "Enter the Book ID to purchase: ";
    cin >> bookID;
    cout << "Enter the quantity to purchase: ";
    cin >> quantity;

    for (int i = 0; i < DATA_SIZE; ++i) {
        if (library[i].bookID == bookID) {
            if (library[i].copiesAvailable >= quantity) {
                double totalCost = library[i].price * quantity;
                library[i].copiesAvailable -= quantity;
                cout << "\nPurchase successful! Total cost: RM" << totalCost << endl;
                return;
            }
            else {
                cout << "\nInsufficient copies available!" << endl;
                return;
            }
        }
    }
    cout << "\nBook ID not found!" << endl;
}


// Menu System
void menu() {
    int choice;
    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Display Unsorted Data" << endl;
        cout << "2. Sorting Options" << endl;
        cout << "3. Searching Options" << endl;
        cout << "4. Additional Functionalities" << endl;
        cout << "5. Save Data to CSV (Excel)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayBooks(library, DATA_SIZE, 100);
            break;
        case 2: {
            int sortChoice;
            cout << "\nSorting Options" << endl;
            cout << "1. Bubble Sort" << endl;
            cout << "2. Quick Sort" << endl;
            cout << "Enter your choice: ";
            cin >> sortChoice;

            int swapCount = 0;
            auto start = chrono::high_resolution_clock::now();

            if (sortChoice == 1) {
                bubbleSort(library, DATA_SIZE, compareByBookID, swapCount);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double, milli> elapsed = end - start;
                cout << "\nBubble Sort completed in " << elapsed.count() << " ms with " << swapCount << " swaps." << endl;
            }
            else if (sortChoice == 2) {
                quickSort(library, 0, DATA_SIZE - 1, compareByBookID, swapCount);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double, milli> elapsed = end - start;
                cout << "\nQuick Sort completed in " << elapsed.count() << " ms with " << swapCount << " swaps." << endl;
            }
            else {
                cout << "Invalid sorting choice!" << endl;
            }

            displayBooks(library, DATA_SIZE, 100);
            break;
        }
        case 3: {
            int searchChoice;
            cout << "\nSearching Options" << endl;
            cout << "1. Linear Search" << endl;
            cout << "2. Binary Search" << endl;
            cout << "Enter your choice: ";
            cin >> searchChoice;

            int comparisons = 0;
            auto start = chrono::high_resolution_clock::now();

            if (searchChoice == 1) {
                cout << "\nLinear Search Results:" << endl;
                for (int i = 0; i < SEARCH_SIZE; ++i) {
                    bool found = linearSearch(library, DATA_SIZE, searchBooks[i].bookID, comparisons);
                    cout << "BookID: " << searchBooks[i].bookID << " - " << (found ? "FOUND" : "NOT FOUND") << endl;
                }
            }
            else if (searchChoice == 2) {
                cout << "\nBinary Search Results:" << endl;
                for (int i = 0; i < SEARCH_SIZE; ++i) {
                    int result = binarySearch(library, DATA_SIZE, searchBooks[i].bookID, comparisons);
                    cout << "BookID: " << searchBooks[i].bookID << " - " << (result != -1 ? "FOUND" : "NOT FOUND") << endl;
                }
            }
            else {
                cout << "Invalid searching choice!" << endl;
            }

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> elapsed = end - start;
            cout << "\nSearch completed in " << elapsed.count() << " ms with " << comparisons << " total comparisons." << endl;
            break;
        }
        case 4: {
            int subChoice;
            cout << "\nAdditional Functionalities:" << endl;
            cout << "1. Calculate Total Value of Books" << endl;
            cout << "2. Generate Highly Rated Books Report" << endl;
            cout << "3. Purchase a Book" << endl;
            cout << "Enter your choice: ";
            cin >> subChoice;

            switch (subChoice) {
            case 1:
                calculateTotalValue();
                break;
            case 2:
                generateHighlyRatedReport();
                break;
            case 3:
                purchaseBook();
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
            break;
        }
        
        case 5:
            saveToCSV("LibraryData.csv");
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);
}

int main() {
    srand(time(0)); // Seed for random number generation
    generateData(); // Generate initial data
    menu(); // Display menu
    return 0;
}
