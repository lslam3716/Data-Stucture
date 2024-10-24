#include <iostream>
#include <vector>
using namespace std;

// Struct to store historical sales data for each product
struct SalesData {
    int avg_sales;     // Average daily sales
    int lead_time;     // Lead time to restock (in days)
    int safety_stock;  // Safety stock to avoid stockouts
};

// Function to calculate the restocking threshold
int calculate_threshold(const SalesData& data) {
    return (data.avg_sales * data.lead_time) + data.safety_stock;
}

// Function to identify products that need restocking
vector<int> identify_restock(const vector<int>& inventory, const vector<SalesData>& sales_data) {
    vector<int> restock_list;  // Stores indices of products to be restocked

    for (size_t i = 0; i < inventory.size(); ++i) {
        int threshold = calculate_threshold(sales_data[i]);
        if (inventory[i] <= threshold) {
            restock_list.push_back(i);  // Add product index to restock list
        }
    }
    return restock_list;
}

int main() {
    // Inventory data: Current quantity of each product
    vector<int> inventory = {50, 30, 5, 80, 12};

    // Historical sales data for each product
    vector<SalesData> sales_data = {
        {5, 2, 10},  // Product 0: avg_sales=5, lead_time=2, safety_stock=10
        {2, 5, 5},   // Product 1: avg_sales=2, lead_time=5, safety_stock=5
        {8, 3, 15},  // Product 2: avg_sales=8, lead_time=3, safety_stock=15
        {1, 7, 10},  // Product 3: avg_sales=1, lead_time=7, safety_stock=10
        {10, 2, 20}  // Product 4: avg_sales=10, lead_time=2, safety_stock=20
    };

    // Identify products that need restocking
    vector<int> restock_list = identify_restock(inventory, sales_data);

    // Output the results
    cout << "Products to restock:" << endl;
    for (int index : restock_list) {
        cout << "Product " << index
             << " (Current: " << inventory[index]
             << ", Threshold: " << calculate_threshold(sales_data[index]) << ")"
             << endl;
    }

    return 0;
}
