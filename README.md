# Devixo-Inventory-Management-System
Object-Oriented Inventory Management System developed in C++ for Devixo Solutions Internship — Task 03. Features include product management, stock monitoring and low-stock alerts, inventory valuation reports, file-based data persistence, and sales receipt generation.

# 📦 Inventory Management System

### Devixo Solutions Internship — Task 03 | C++

A console-based **Inventory Management System** developed in C++ as part of the Devixo Solutions internship. The project demonstrates object-oriented programming, inheritance, polymorphism, vector-based product management, file handling, inventory reporting, stock monitoring, and sales receipt generation.

---

## 📌 Table of Contents

- [Project Overview](#-project-overview)
- [Objectives](#-objectives)
- [Features](#-features)
- [Technologies Used](#-technologies-used)
- [Programming Concepts](#-programming-concepts)
- [Project Structure](#-project-structure)
- [Getting Started](#-getting-started)
- [How to Use](#-how-to-use)
- [Data Storage and File Handling](#-data-storage-and-file-handling)
- [Input Validation](#-input-validation)
- [Testing](#-testing)
- [Limitations](#-limitations)
- [Future Improvements](#-future-improvements)
- [Internship Information](#-internship-information)
- [Author](#-author)

---

## 📖 Project Overview

The Inventory Management System provides a simple way to manage product records through an interactive command-line interface.

Users can add new products, view inventory records, search for products by ID, update product information, delete products, monitor low-stock items, and generate inventory reports. The application also supports sales transactions by generating receipts and updating product quantities after a sale.

Product records and sales transactions are stored in text files to support file-based data management.

This project was developed to apply object-oriented programming and fundamental C++ techniques to a practical inventory management application.

## 🎯 Objectives

The main objectives of this project are to:

- Apply classes and objects to organize product records and inventory operations.
- Implement inheritance and polymorphism through product-related classes.
- Use functions to create a modular and maintainable program.
- Manage product collections using STL vectors.
- Implement file handling to save and load inventory records.
- Provide product addition, searching, updating, and deletion operations.
- Monitor product quantities and identify low-stock items.
- Generate inventory reports, including inventory value and stock availability.
- Generate sales receipts and update inventory after sales.
- Develop an interactive menu-driven console application.

## ✨ Features

| Feature | Description |
|---|---|
| Add Product | Adds a new product with its details, price, and quantity. |
| View Products | Displays the products stored in the inventory. |
| Search Product | Finds a product using its unique ID. |
| Update Product | Updates the information of an existing product. |
| Delete Product | Removes an existing product from the inventory. |
| Stock Monitoring | Tracks available quantities of products. |
| Low-Stock Alerts | Identifies products whose quantities meet the program's low-stock threshold. |
| Inventory Reports | Displays total products, available stock, and total inventory value. |
| Save Data | Saves product records to a text file. |
| Load Data | Loads saved product records from the text file. |
| Sales Receipt | Generates a receipt for a completed sale. |
| Update Stock After Sale | Deducts the sold quantity from the available inventory. |

### ⭐ Bonus Feature

The application supports **sales receipt generation and automatic inventory quantity updates after a sale**.

When a sale is processed, the program updates the available stock and records the sales receipt in a text file, provided the file operation succeeds.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Standard Library:** `iostream`, `vector`, `string`, `fstream`, and other required standard headers
- **Data Structure:** `vector<Product*>`
- **Data Storage:** Text files (`inventory_data.txt` and `sales_receipts.txt`)
- **Development Environment:** Code Utility Online Compiler

## 🧠 Programming Concepts

### 1. Classes and Objects

The program uses classes to represent products and manage inventory operations.

- **`Product`** — provides the common product interface and shared product information.
- **`StockProduct`** — represents a stock-managed product and implements product-specific behaviour.
- **`InventoryManager`** — manages product records and provides inventory operations.

### 2. Encapsulation

Product information is managed through class members and public methods, helping organize access to product details and updates.

### 3. Inheritance

The `StockProduct` class inherits from the `Product` base class, allowing shared product functionality to be reused.

### 4. Polymorphism

Virtual functions, including `display()` and `getValue()`, allow product behaviour to be accessed through the base-class interface.

### 5. Functions

Separate member functions handle operations such as adding, viewing, searching, updating, deleting, selling, saving, loading, and reporting products.

### 6. Vectors

The program uses `vector<Product*>` to maintain a dynamically sized collection of product objects.

### 7. File Handling

File streams are used to save and retrieve inventory records and maintain sales receipt records.

### 8. Menu-Driven Programming

A menu-driven interface allows users to select inventory operations and interact with the program through the console.

### 9. Inventory Calculations

The application calculates product values using price and quantity information and combines these values to produce an inventory valuation report.

### 10. Stock Monitoring

The application checks product quantities against a low-stock threshold and identifies products that may need restocking.

## 📁 Project Structure

The repository is organized as follows:

```text
Devixo-Inventory-Management-System/
│
├── main.cpp
├── inventory_data.txt
├── sales_receipts.txt
├── README.md
├── screenshots/
│   ├── libraries, class
│   ├── input validation function
└── Devixo_Inventory_Management_System_Report.pdf
```

## 🚀 Getting Started

### Prerequisites

You need a C++ compiler that supports the standard library and file input/output.

Examples include:

- GCC / G++
- Code::Blocks
- Visual Studio
- A compatible online C++ compiler

### Installation

1. Clone or download this repository.
2. Open the project directory.
3. Open `main.cpp` in your preferred C++ editor or compiler.
4. Compile and execute the program.

### Compile Using G++

If G++ is installed, run:

```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o inventory
```

On Windows, run:

```bash
inventory.exe
```

On Linux or macOS, run:

```bash
./inventory
```

Alternatively, paste the contents of `main.cpp` into a compatible online C++ compiler and run it.

## 🖥️ How to Use

After starting the application, the main menu presents the available inventory operations.

```text
================================
   INVENTORY MANAGEMENT SYSTEM
================================
1. Add Product
2. View Products
3. Search Product
4. Update Product
5. Delete Product
6. Low-Stock Report
7. Inventory Report
8. Sell Product (Bonus)
9. Save Inventory
0. Exit
================================
Enter your choice:
```
### Example Workflow

1. Select **Add Product** and enter the required product information.
2. Select **View Products** to review the inventory.
3. Select **Search Product** to find a product by its ID.
4. Select **Update Product** to modify an existing product.
5. Select **Low-Stock Report** to identify products requiring restocking.
6. Select **Inventory Report** to view inventory statistics and total value.
7. Select **Sell Product (Bonus)** to process a sale and generate a receipt.
8. Select **Save Inventory** to save inventory.
9. Select **Exit** to close the application.

## 💾 Data Storage and File Handling

The application uses text files for file-based storage.

### `inventory_data.txt`

Stores product records so that inventory information can be saved and loaded.

### `sales_receipts.txt`

Stores sales receipt records generated when sales are processed.

The inventory data file uses a pipe-separated format. A record may resemble the following, depending on the final implementation:

```text
101|Notebook|120.00|10
102|Pen|30.00|4
```

**Important:** These files are created or accessed relative to the program's working directory. Some online compilers use temporary storage, so persistence across separate executions depends on the compiler environment.

## 🛡️ Input Validation

The application should be tested for appropriate handling of invalid input, including:

- Invalid menu choices.
- Non-numeric input where a number is required.
- Invalid product IDs.
- Negative or otherwise invalid prices and quantities.
- Attempts to search for products that do not exist.
- Attempts to update or delete nonexistent products.
- Attempts to sell more units than are available.
- Attempts to process a sale with an invalid quantity.

The precise validation behaviour depends on the final implementation. Document only the checks that are actually implemented and tested in `main.cpp`.

## 🧪 Testing

The program should be tested through its interactive menu.

| Test | Expected Behaviour |
|---|---|
| Add a product | The product is added to the inventory. |
| View products | Stored product records are displayed. |
| Search product | The matching product is displayed when found. |
| Update product | The selected product's information is updated. |
| Delete product | The selected product is removed. |
| Low-stock report | Products meeting the low-stock condition are displayed. |
| Inventory report | Product count, available stock, and inventory value are reported. |
| Sell product | The sold quantity is deducted from available stock. |
| Generate receipt | Sales details are written to the receipt file when the file operation succeeds. |
| Save and load data | Product records are written to and read from the inventory file. |
| Invalid input | The program handles invalid entries according to its validation logic. |
| Insufficient stock | A sale exceeding the available quantity is rejected. |

## ⚠️ Limitations

- The application uses a console-based interface rather than a graphical user interface.
- Inventory and sales records are stored in text files rather than a database.
- The application does not provide user authentication or role-based access.
- The data-file format may restrict certain characters in product names.
- File persistence depends on the execution environment and working directory.
- Sales reporting and inventory management are limited to the features implemented in the current version.

## 🔮 Future Improvements

Potential extensions include:

- A graphical user interface.
- Database integration using SQLite or MySQL.
- Product categories and supplier management.
- Product expiry-date and batch tracking.
- Sales history search and revenue reports.
- Barcode-based product identification.
- User authentication and administrative roles.
- Improved error handling and data-file recovery.
- Exporting inventory reports to CSV or PDF.

## 🎓 Internship Information

- **Organization:** Devixo Solutions
- **Program:** C++ Programming Internship
- **Task Number:** Task 03
- **Project:** Inventory Management System
- **Language:** C++

This project was developed to demonstrate practical C++ programming skills, object-oriented design, data structures, file handling, inventory management, and sales processing.

## 👩‍💻 Author

**Ayesha Raheela**  
BS Computer Science Student

GitHub: [Ayesha Raheela]([[https://github.com/ayesharaheela1410-zr](https://github.com/ayesharaheela1410-zr/Devixo-Inventory-Management-System)]
