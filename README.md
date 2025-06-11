# Inventory Management System

A console-based inventory management system written in C++ that allows users to manage product data through two roles: **Admin** and **Staff**.

## 📦 Features

### Admin
- Add new products to the inventory
- Search products by:
  - ID
  - Name
  - Supplier
  - Cost Price
  - Selling Price
  - Count
- Update individual fields of any product
- Delete products from the inventory

### Staff
- View all inventory records
- Search products using the same criteria as admin

## 💾 Data Storage

- Data is stored in `data.txt`
- Temporary updates are processed through `temp.txt`

> ⚠️ **Important:**  
> Ensure both `data.txt` and `temp.txt` files exist **in the same folder** as the compiled executable.  
> If not, file access errors may occur during runtime.

# Inventory Management System

A console-based inventory management system written in C++ that allows users to manage product data through two roles: **Admin** and **Staff**.

## 📦 Features

### Admin
- Add new products to the inventory
- Search products by:
  - ID
  - Name
  - Supplier
  - Cost Price
  - Selling Price
  - Count
- Update individual fields of any product
- Delete products from the inventory

### Staff
- View all inventory records
- Search products using the same criteria as admin

## 💾 Data Storage

- Data is stored in `data.txt`
- Temporary updates are processed through `temp.txt`

> ⚠️ **Important:**  
> Ensure both `data.txt` and `temp.txt` files exist **in the same folder** as the compiled executable.  
> If not, file access errors may occur during runtime.

## 🔧 How to Run

Just copy all the files (`main.cpp`, `data.txt`, `temp.txt`) into one folder and open that folder in your C++ compiler (like VS Code, Code::Blocks, or Dev-C++).
