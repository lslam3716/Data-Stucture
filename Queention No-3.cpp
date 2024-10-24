#include <iostream>
#include <vector>
#include <string>

// Structure to represent a book
struct Book {
    std::string title;
    std::string author;
    int publicationYear;

    // Constructor for convenience
    Book(std::string t, std::string a, int y)
        : title(t), author(a), publicationYear(y) {}
};

// Function to merge two halves of the array
void merge(std::vector<Book>& books, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors to hold the two halves
    std::vector<Book> leftArray(n1);
    std::vector<Book> rightArray(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; ++i)
        leftArray[i] = books[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = books[mid + 1 + j];

    // Merge the two halves back into the original vector
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i].title <= rightArray[j].title) {
            books[k] = leftArray[i];
            ++i;
        } else {
            books[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    // Copy any remaining elements from the left half
    while (i < n1) {
        books[k] = leftArray[i];
        ++i;
        ++k;
    }

    // Copy any remaining elements from the right half
    while (j < n2) {
        books[k] = rightArray[j];
        ++j;
        ++k;
    }
}

// Recursive function to perform Merge Sort
void mergeSort(std::vector<Book>& books, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the two halves recursively
        mergeSort(books, left, mid);
        mergeSort(books, mid + 1, right);

        // Merge the sorted halves
        merge(books, left, mid, right);
    }
}

// Function to print the list of books
void printBooks(const std::vector<Book>& books) {
    for (const auto& book : books) {
        std::cout << "Title: " << book.title
                  << ", Author: " << book.author
                  << ", Year: " << book.publicationYear << std::endl;
    }
}

// Main function to demonstrate the sorting of books by title
int main() {
    // Sample books
    std::vector<Book> books = {
        {"The Great Gatsby", "F. Scott Fitzgerald", 1925},
        {"1984", "George Orwell", 1949},
        {"To Kill a Mockingbird", "Harper Lee", 1960},
        {"Pride and Prejudice", "Jane Austen", 1813},
        {"Moby Dick", "Herman Melville", 1851}
    };

    std::cout << "Books before sorting:\n";
    printBooks(books);

    // Sort the books by title using Merge Sort
    mergeSort(books, 0, books.size() - 1);

    std::cout << "\nBooks after sorting by title:\n";
    printBooks(books);

    return 0;
}

