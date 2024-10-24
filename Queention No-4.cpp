#include <iostream>
#include <string>
#include <algorithm>

struct Reservation {
    std::string name;
    std::string phone;
    std::string reservationDate;

    // Constructor for convenience
    Reservation(std::string n, std::string p, std::string d)
        : name(n), phone(p), reservationDate(d) {}
};

// Comparison function for sorting by name, then by phone, then by date
bool compareReservations(const Reservation& a, const Reservation& b) {
    if (a.name != b.name)
        return a.name < b.name; // Sort by name
    if (a.phone != b.phone)
        return a.phone < b.phone; // Sort by phone
    return a.reservationDate < b.reservationDate; // Sort by reservation date
}

// Function to perform binary search
void binarySearchReservation(Reservation reservations[], int n,
                             const std::string& name, const std::string& phone) {
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if we found the reservation
        if (reservations[mid].name == name && reservations[mid].phone == phone) {
            std::cout << "Reservation found:\n";
            std::cout << "Name: " << reservations[mid].name << "\n";
            std::cout << "Phone: " << reservations[mid].phone << "\n";
            std::cout << "Date: " << reservations[mid].reservationDate << "\n";
            found = true;
            break;
        }
        // If current name is less than the target name, ignore the left half
        else if (reservations[mid].name < name ||
                (reservations[mid].name == name && reservations[mid].phone < phone)) {
            left = mid + 1;
        }
        // If current name is greater than the target name, ignore the right half
        else {
            right = mid - 1;
        }
    }

    if (!found) {
        std::cout << "No reservation found for " << name << " with phone " << phone << ".\n";
    }
}

int main() {
    // Sample reservations
    Reservation reservations[] = {
        {"Alice Johnson", "123-456-7890", "2024-10-25"},
        {"Bob Smith", "987-654-3210", "2024-10-26"},
        {"Alice Johnson", "123-456-7890", "2024-11-01"},
        {"Charlie Brown", "555-555-5555", "2024-11-02"},
        {"Bob Smith", "123-654-7890", "2024-10-28"}
    };

    int n = sizeof(reservations) / sizeof(reservations[0]);

    // Sort reservations by name, phone number, and date
    std::sort(reservations, reservations + n, compareReservations);

    // Search for a reservation
    std::string name, phone;
    std::cout << "Enter the customer's name: ";
    std::getline(std::cin, name);
    std::cout << "Enter the customer's phone number: ";
    std::getline(std::cin, phone);

    // Perform the search
    binarySearchReservation(reservations, n, name, phone);

    return 0;
}

