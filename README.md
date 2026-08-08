# 4WD DC Motor Motion Control (Tinkercad Simulation)

An Arduino-based 4-wheel drive (4WD) motion control system designed and simulated in **Tinkercad**. The project uses dual **L293D** motor driver ICs to control four DC motors and execute a precise timed motion sequence.

---

## 📌 Project Overview

This repository contains the circuit configuration, C++ code, and documentation for simulating a 4-motor robotic vehicle. The system executes a continuous multi-phase motion routine:
1. **Forward Motion**: All 4 motors drive forward for **30 seconds**.
2. **Reverse Motion**: All 4 motors reverse direction for **60 seconds (1 minute)**.
3. **Alternating Turns**: The vehicle alternates between differential right and left turns for **60 seconds (1 minute)**.

---

## 🛠️ Components Used

| Component | Quantity | Description |
| :--- | :---: | :--- |
| **Arduino Uno R3** | 1 | Microcontroller Unit |
| **L293D Motor Driver IC** | 2 | Dual H-Bridge Drivers for 4 DC Motors |
| **DC Motors** | 4 | Drive Motors (Front Right/Left, Rear Right/Left) |
| **9V External Battery** | 1 | Dedicated Motor Power Supply |
| **Breadboard & Jumper Wires** | 1 | Circuit Interconnections |

---

## 🔌 Circuit Pinout & Wiring

### Power Connections
* **GND Rail**: Shared ground connecting Arduino GND, L293D GND Pins (4, 5, 12, 13), and 9V Battery Negative (-).
* **+5V Logic Rail**: Powered by Arduino 5V for L293D VSS (Pin 16) and Enable Pins (1, 9).
* **+9V Motor Rail**: Powered by 9V External Battery connected to L293D VC (Pin 8) to provide motor current.

### Motor Driver Wiring
* **L293D #1 (Right Motors)**:
  * Front Right Motor $\rightarrow$ `OUT1` (Pin 3), `OUT2` (Pin 6) | Control Pins: `Pin 2`, `Pin 3`
  * Rear Right Motor $\rightarrow$ `OUT3` (Pin 11), `OUT4` (Pin 14) | Control Pins: `Pin 4`, `Pin 5`
* **L293D #2 (Left Motors)**:
  * Front Left Motor $\rightarrow$ `OUT1` (Pin 3), `OUT2` (Pin 6) | Control Pins: `Pin 6`, `Pin 7`
  * Rear Left Motor $\rightarrow$ `OUT3` (Pin 11), `OUT4` (Pin 14) | Control Pins: `Pin 8`, `Pin 11`

---

## ⚙️ Motion Routine Logic
Forward (30s)  --->  2. Reverse (60s)  --->  3. Alternate Turns (60s)
5s Right Turn  --->  5s Left Turn (x6)    

---
🔗 Tinkercad Simulation Link
View and run the interactive simulation directly on Tinkercad:
https://www.tinkercad.com/things/2EdWUzzNb1T/editel?sharecode=W57LN9DGBVFdyYZA5iR5JhKfdIRvvoRIqCj3FwiKfHA 

---

## 📹 Simulation Video Demonstration

Watch the full simulation execution and motion sequence in action:
https://drive.google.com/file/d/1s63bQ5bV9YMxTmocURF8_NZky2FTvPn8/view?usp=drive_link
