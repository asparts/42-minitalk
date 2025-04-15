# 📡 42 Minitalk

A minimalist client-server communication program built entirely in C using **UNIX signals**. Developed as part of the 42 curriculum, this project explores inter-process communication (IPC) by transmitting messages bit by bit using `SIGUSR1` and `SIGUSR2`.

---

## 🧠 Project Overview

**Minitalk** consists of two programs:

- **Server**: Waits for messages and prints them upon receipt.
- **Client**: Sends a string message to the server using UNIX signals.

The client encodes each character of the message into binary and sends it to the server, one bit at a time. The server reconstructs the message from the received signals and displays it.

---

## 🔧 Features

- 📬 Send messages from client to server using only `SIGUSR1` and `SIGUSR2`.
- 🖨️ Server displays the received message upon completion.
- 🔁 Server can handle multiple messages from clients without restarting.


## 🗂️ Project Structure
42-minitalk/ 
├── client.c # Client source code  <br>
├── server.c # Server source code  <br>
├── client_bonus.c # Client with bonus features  <br>
├── server_bonus.c # Server with bonus features  <br>
├── Makefile # Build instructions  <br>
└── README.md # Project documentation <br>


---

## 🚀 Getting Started

### 📋 Prerequisites

- 🧰 [GCC](https://gcc.gnu.org/) compiler
- 🖥️ Unix-like operating system (e.g., Linux, macOS)

### 🛠️ Installation & Usage

1. **Clone the repository:**
   git clone https://github.com/asparts/42-minitalk.git
   cd 42-minitalk
2. **Compile:**
   make
3. **Run the server:**
   ./server
   (The server will display its Process ID (PID). Note this PID for the next step.)
5. **In a separate terminal, run the client:**
   ./client <server_pid> "Your message here"
   (Replace <server_pid> with the PID displayed by the server.)
For example:
./client 12345 "Hello, World!"
The server will display: Hello, World!

# 🧹 Cleaning Up
Remove object files: make clean
Remove all compiled files: make fclean
Recompile everything: make re

# 📸 Screenshot
![image](https://github.com/user-attachments/assets/ba6b0ecc-f430-4b4e-877f-77369c5ece9b)

# 📝 License
This project is licensed under the MIT License.
