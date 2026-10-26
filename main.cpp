#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

// ==================== BASE CLASS ====================
class Product {
protected:
    int id;
    string name;
    int quantity;
    double price;

public:
    Product(int i, string n, int q, double p)
        : id(i), name(n), quantity(q), price(p) {}

    virtual void display() const {
        cout << left << setw(10) << id
             << setw(25) << name
             << setw(12) << quantity
             << fixed << setprecision(2) << price << endl;
    }

    virtual double getValue() const {
        return quantity * price;
    }

    virtual ~Product() {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void setName(const string& n) { name = n; }
    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }
};

// ==================== DERIVED CLASS ====================
class StockProduct : public Product {
public:
    StockProduct(int i, string n, int q, double p)
        : Product(i, n, q, p) {}

    void display() const override {
        Product::display();
        if (quantity <= 5)
            cout << "  ** LOW STOCK ALERT **" << endl;
    }

    double getValue() const override {
        return Product::getValue();
    }
};

// ==================== INVENTORY MANAGER ====================
class InventoryManager {
private:
    vector<Product*> products;
    const string dataFile = "inventory_data.txt";
    const string receiptFile = "sales_receipts.txt";

    Product* findProduct(int id) const {
        for (Product* p : products) {
            if (p->getId() == id)
                return p;
        }
        return nullptr;
    }

    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int readInt(const string& prompt, int minimum) {
        int value;
        while (true) {
            cout << prompt;
            if (cin >> value && value >= minimum) {
                clearInput();
                return value;
            }
            cout << "Invalid input. Enter a whole number >= "
                 << minimum << ".\n";
            clearInput();
        }
    }

    double readPrice(const string& prompt) {
        double value;
        while (true) {
            cout << prompt;
            if (cin >> value && value >= 0) {
                clearInput();
                return value;
            }
            cout << "Invalid price. Enter a non-negative number.\n";
            clearInput();
        }
    }

    string readName(const string& prompt) {
        string value;
        while (true) {
            cout << prompt;
            getline(cin, value);
            if (!value.empty())
                return value;
            cout << "Name cannot be empty.\n";
        }
    }

public:
    InventoryManager() {
        loadFromFile();
    }

    ~InventoryManager() {
        saveToFile();
        for (Product* p : products)
            delete p;
        products.clear();
    }

    // ---------- ADD PRODUCT ----------
    void addProduct() {
        int id = readInt("Enter Product ID: ", 1);

        if (findProduct(id) != nullptr) {
            cout << "A product with this ID already exists.\n";
            return;
        }

        string name = readName("Enter Product Name: ");
        int quantity = readInt("Enter Quantity: ", 0);
        double price = readPrice("Enter Price: ");

        products.push_back(
            new StockProduct(id, name, quantity, price)
        );

        saveToFile();
        cout << "Product added successfully!\n";
    }

    // ---------- VIEW PRODUCTS ----------
    void viewProducts() const {
        if (products.empty()) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "\n================ INVENTORY ================\n";
        cout << left << setw(10) << "ID"
             << setw(25) << "Name"
             << setw(12) << "Quantity"
             << "Price\n";
        cout << string(60, '-') << endl;

        for (const Product* p : products)
            p->display();
    }

    // ---------- SEARCH PRODUCT ----------
    void searchProduct() const {
        int id = readSearchId();
        Product* p = findProduct(id);

        if (p != nullptr) {
            cout << "\nProduct found:\n";
            cout << left << setw(10) << "ID"
                 << setw(25) << "Name"
                 << setw(12) << "Quantity"
                 << "Price\n";
            p->display();
        } else {
            cout << "Product not found.\n";
        }
    }

    int readSearchId() const {
        int id;
        while (true) {
            cout << "Enter Product ID: ";
            if (cin >> id && id > 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return id;
            }
            cout << "Invalid ID. Enter a positive whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // ---------- UPDATE PRODUCT ----------
    void updateProduct() {
        int id = readSearchId();
        Product* p = findProduct(id);

        if (p == nullptr) {
            cout << "Product not found.\n";
            return;
        }

        cout << "Current details:\n";
        p->display();

        string name = readName("Enter New Product Name: ");
        int quantity = readInt("Enter New Quantity: ", 0);
        double price = readPrice("Enter New Price: ");

        p->setName(name);
        p->setQuantity(quantity);
        p->setPrice(price);

        saveToFile();
        cout << "Product updated successfully!\n";
    }

    // ---------- DELETE PRODUCT ----------
    void deleteProduct() {
        int id = readSearchId();

        for (size_t i = 0; i < products.size(); i++) {
            if (products[i]->getId() == id) {
                delete products[i];
                products.erase(products.begin() + i);
                saveToFile();
                cout << "Product deleted successfully!\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    // ---------- LOW STOCK ALERT ----------
    void lowStockReport() const {
        bool found = false;

        cout << "\n========== LOW STOCK PRODUCTS ==========\n";
        for (const Product* p : products) {
            if (p->getQuantity() <= 5) {
                p->display();
                found = true;
            }
        }

        if (!found)
            cout << "No low-stock products.\n";
    }

    // ---------- INVENTORY REPORT ----------
    void inventoryReport() const {
        int totalQuantity = 0;
        double totalValue = 0;

        for (const Product* p : products) {
            totalQuantity += p->getQuantity();
            totalValue += p->getValue();
        }

        cout << "\n========== INVENTORY REPORT ==========\n";
        cout << "Total Products: " << products.size() << endl;
        cout << "Available Stock (units): "
             << totalQuantity << endl;
        cout << fixed << setprecision(2);
        cout << "Total Inventory Value: " << totalValue << endl;
    }

    // ---------- SALES RECEIPT BONUS ----------
    void sellProduct() {
        int id = readSearchId();
        Product* p = findProduct(id);

        if (p == nullptr) {
            cout << "Product not found.\n";
            return;
        }

        int quantitySold = readInt("Enter Quantity to Sell: ", 1);

        if (quantitySold > p->getQuantity()) {
            cout << "Insufficient stock. Available: "
                 << p->getQuantity() << endl;
            return;
        }

        double total = quantitySold * p->getPrice();
        p->setQuantity(p->getQuantity() - quantitySold);

        ofstream receipt(receiptFile.c_str(), ios::app);
        if (receipt.is_open()) {
            receipt << fixed << setprecision(2);
            receipt << "\n========== SALES RECEIPT ==========\n";
            receipt << "Product ID: " << p->getId() << endl;
            receipt << "Product Name: " << p->getName() << endl;
            receipt << "Quantity Sold: " << quantitySold << endl;
            receipt << "Unit Price: " << p->getPrice() << endl;
            receipt << "Total Amount: " << total << endl;
            receipt << "Remaining Stock: " << p->getQuantity() << endl;
            receipt << "===================================\n";
        } else {
            cout << "Warning: Could not write receipt file.\n";
        }
        receipt.close();

        saveToFile();

        cout << "\n========== SALES RECEIPT ==========\n";
        cout << "Product: " << p->getName() << endl;
        cout << "Quantity Sold: " << quantitySold << endl;
        cout << fixed << setprecision(2);
        cout << "Unit Price: " << p->getPrice() << endl;
        cout << "Total Amount: " << total << endl;
        cout << "Remaining Stock: " << p->getQuantity() << endl;
        cout << "Receipt saved to " << receiptFile << endl;

        if (p->getQuantity() <= 5)
            cout << "LOW STOCK ALERT!\n";
    }

    // ---------- SAVE DATA ----------
    void saveToFile() const {
        ofstream file(dataFile.c_str());

        if (!file.is_open()) {
            cout << "Warning: Could not save inventory data.\n";
            return;
        }

        for (const Product* p : products) {
            file << p->getId() << '|'
                 << p->getName() << '|'
                 << p->getQuantity() << '|'
                 << setprecision(15) << p->getPrice() << '\n';
        }
    }

    // ---------- LOAD DATA ----------
    void loadFromFile() {
        ifstream file(dataFile.c_str());
        if (!file.is_open())
            return;

        string line;

        while (getline(file, line)) {
            size_t a = line.find('|');
            size_t b = line.find('|', a == string::npos ? 0 : a + 1);
            size_t c = line.find('|', b == string::npos ? 0 : b + 1);

            if (a == string::npos || b == string::npos ||
                c == string::npos)
                continue;

            try {
                int id = stoi(line.substr(0, a));
                string name = line.substr(a + 1, b - a - 1);
                int quantity = stoi(line.substr(b + 1, c - b - 1));
                double price = stod(line.substr(c + 1));

                if (id > 0 && quantity >= 0 && price >= 0 &&
                    findProduct(id) == nullptr) {
                    products.push_back(
                        new StockProduct(id, name, quantity, price)
                    );
                }
            } catch (...) {
                // Ignore malformed records.
            }
        }
    }

    // ---------- MAIN MENU ----------
    void run() {
        int choice;

        do {
            cout << "\n====================================\n";
            cout << "     INVENTORY MANAGEMENT SYSTEM\n";
            cout << "          DEVIXO SOLUTIONS\n";
            cout << "====================================\n";
            cout << "1. Add Product\n";
            cout << "2. View Products\n";
            cout << "3. Search Product\n";
            cout << "4. Update Product\n";
            cout << "5. Delete Product\n";
            cout << "6. Low Stock Alert\n";
            cout << "7. Inventory Report\n";
            cout << "8. Sell Product (Bonus)\n";
            cout << "9. Save Inventory\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                cout << "Invalid input. Enter a menu number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1: addProduct(); break;
                case 2: viewProducts(); break;
                case 3: searchProduct(); break;
                case 4: updateProduct(); break;
                case 5: deleteProduct(); break;
                case 6: lowStockReport(); break;
                case 7: inventoryReport(); break;
                case 8: sellProduct(); break;
                case 9:
                    saveToFile();
                    cout << "Inventory saved successfully.\n";
                    break;
                case 0:
                    saveToFile();
                    cout << "Inventory saved. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }

        } while (choice != 0);
    }
};

// ==================== MAIN FUNCTION ====================
int main() {
    InventoryManager inventory;
    inventory.run();
    return 0;
}