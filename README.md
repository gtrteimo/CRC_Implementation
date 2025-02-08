# Cyclic Redundancy Check (CRC) Implementation

## The Assignment

The goal of this assignment was to create a C program that simulates the process of sending and receiving data. The data gets encoded and decoded using a cyclic redundancy check (CRC) polynomial to detect bit flips during transmission.

We were given full freedom in how to implement this process.

---

## My Implementation

- The program runs in the command line, allowing the user to interact with it.
- The user first selects a fixed polynomial for CRC calculation: **CRC-32, CRC-16, or CRC-5**.
- Then, the user specifies the number of characters they want to enter (for efficiency purposes).
- The program prompts the user to input that exact number of characters, which are then encoded.
- To simulate real-world transmission errors, I implemented a feature that **intentionally flips bits** in the data.
- After the simulated transmission, the program checks for errors and reports whether any bit flips were detected.

---

## My Design Choices

- **Dynamic Memory Allocation:**  
  Instead of using a fixed `uint64_t` array (as suggested by the professor), I chose to store data in a **dynamically sized `uint8_t` array**. This makes the program more flexible, handling different data sizes efficiently.

- **Command-Line Interface (CLI):**  
  I opted for a simple console-based interface rather than a GUI or file-based approach. This keeps the implementation lightweight and easy to run on different systems.

- **Modular Design:**  
  The program is structured in a way that separates key functionalities, making it easier to modify or extend.

- **Precomputed CRC Calculation:**  
  The CRC is calculated in advance, which makes the encoding and decoding process more streamlined and efficient.

---

## Things That Would Be Nice to Improve (But I Can’t Be Bothered)

- **Custom CRC Polynomials:**  
  Right now, the program only supports CRC-32, CRC-16, and CRC-5. It would be great to allow the user to input a custom polynomial, but I didn’t implement this.

- **File Input/Output Support:**  
  The program currently relies on user input via the terminal. Adding file reading and writing would make it more scalable and useful for automation.

---

## Can You Use It?

Yes! You can use, modify, copy, publish, or even sell this program. For more details, check the license.

If you’re a programmer and want to understand how everything works, the source code includes comments explaining each part of the implementation.

---

## How Do I Use It?

1. **Download the release** and run it from the terminal. (Although, since it's just a simulation, it might not be super useful on its own.)
2. **Download the source code, modify it to suit your needs, and compile it** using a C compiler. If you're not using `make`, you have do everything manualy otherwise simply run:

   ```sh
   make
