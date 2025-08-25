# ✈️ Airline Management System in C++

## 📌 Project Overview
This Airline Management System is a console-based application developed in C++ to automate the process of booking, canceling, and checking flight tickets. It uses object-oriented programming principles and file handling to manage passenger records efficiently and securely.

Developed as part of an experiential learning case study at **C. V. Raman Global University**, this project demonstrates practical application of C++ in building real-world systems.

---

## 🧠 Problem Statement
Traditional airline record management systems rely heavily on manual processes, which are:
- Error-prone
- Time-consuming
- Difficult to scale

This project addresses these issues by:
- Automating ticket booking and cancellation
- Validating user inputs
- Storing passenger data persistently using file handling

---

## 🎯 Objectives
- Implement a modular and user-friendly airline reservation system
- Use C++ classes to encapsulate booking, passenger, and payment logic
- Ensure data integrity and validation
- Provide persistent storage using binary files

---

## 🛠️ Features
- **Book a Flight**: Select source/destination, choose a flight, enter passenger details, and make payment
- **Cancel a Flight**: Enter PNR to cancel a ticket and receive a refund
- **Check Ticket**: Retrieve ticket details using PNR
- **File Handling**: Store and manage bookings in `domestic.txt`
- **PNR Generation**: Auto-incremented and stored in `last_pnr.txt`
- **Input Validation**: Ensures correct format for phone numbers, card details, and passwords

---

## 🧱 Technologies Used
- **Language**: C++
- **Concepts**: OOP (Encapsulation, Inheritance), File I/O, Input Validation
- **Storage**: Binary file handling (`ifstream`, `ofstream`)
- **Platform**: Console-based (Windows)

---

## 📁 File Structure
```
├── main.txt              # Main source code
├── last_pnr.txt          # Stores last used PNR number
├── domestic.txt          # Stores passenger booking records
├── domestic1.txt         # Temporary file for cancellation
├── README.md             # Project documentation
```

---

## 🧩 Class Breakdown

### `booking`
- Generates PNR
- Handles journey details and flight selection

### `passenger` (inherits `booking`)
- Stores passenger info: name, age, gender, email, phone
- Validates inputs
- Displays ticket details

### `payment`
- Handles payment via Debit/Credit/Net Banking
- Validates card number, CVV, password

---

## 🔄 Booking Flow
1. Display main menu
2. Select "Book Flight"
3. Enter journey details
4. Choose flight
5. Enter passenger details
6. Make payment
7. Save booking to file
8. Display ticket

---

## 🔁 Cancellation Flow
1. Select "Cancel Flight"
2. Enter PNR
3. Search and remove record from file
4. Refund Rs. 1000

---

## 🔍 Ticket Check Flow
1. Select "Check Ticket"
2. Enter PNR
3. Display ticket if found

---

## 🧪 Sample Run
```text
Welcome To Flight Reservation System

1. Book Flight
2. Cancel Flight
3. Check Ticket
4. Exit

Please enter your choice: 1
Only Domestic flights are available at the moment
Enter Source: 1 (Delhi)
Enter Destination: 2 (Mumbai)
Flights Found:
1. Vistara ...
Enter your choice: 1
Enter Passenger Details...
Transaction Successful!
Ticket Booked Successfully!
```

---

## 🚀 Future Enhancements
- GUI using Qt or SFML
- Database integration (MySQL or SQLite)
- Cloud-based storage
- QR code generation for tickets
- OTP-based authentication
- Dynamic pricing algorithms

---



Let me know if you'd like this tailored for GitHub Pages or with embedded screenshots and diagrams.
