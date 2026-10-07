# Light Based Text Transmission (Li-Fi)

A simple Arduino-based visible-light communication prototype that transmits text from one computer to another using an LED as the transmitter and a solar panel or photodiode as the receiver.

## Project overview

This project demonstrates short-range Li-Fi text communication using two Arduino UNO boards. The transmitter converts characters from the Serial Monitor into Manchester-encoded signals and drives an LED. The receiver detects the light signal through a light sensor/photodiode or solar panel and decodes the signal before printing the received character to the Serial Monitor.

The project report describes the system as using an LED transmitter, solar-panel receiver, and two Arduino UNO boards. It also describes On-Off Keying (OOK), line-of-sight communication, and the use of Manchester encoding in the implementation.

## Hardware

- 2 × Arduino UNO
- 1 × LED / LED strip / LED bulb
- 1 × solar panel or photodiode/light sensor
- 1 × DC-DC boost converter
- 1 × 2N2222 transistor/amplifier circuit
- Resistors
- Jumper/connecting wires
- 2 × computers/laptops for the Arduino Serial Monitors

## Pin configuration

### Transmitter

| Component | Arduino pin |
|---|---|
| LED signal | D9 |

### Receiver

| Component | Arduino pin |
|---|---|
| Light sensor / photodiode signal | A0 |

The source code uses `MAN_1200` for Manchester communication while the Serial Monitor is configured at 9600 baud.

## Repository structure

```text
lifi-text-transmission/
├── README.md
├── LICENSE
├── docs/
│   └── hardware.md
├── src/
│   ├── transmitter/
│   │   └── transmitter.ino
│   └── receiver/
│       └── receiver.ino
└── lib/
    └── Manchester/
        ├── Manchester.cpp
        ├── Manchester.h
        ├── keywords.txt
        └── library.json
```

## Software setup

1. Install the Arduino IDE.
2. Install/copy the included `Manchester` library into the Arduino libraries directory, or add it through the IDE's library mechanism.
3. Connect the transmitter Arduino and upload `src/transmitter/transmitter.ino`.
4. Connect the receiver Arduino and upload `src/receiver/receiver.ino`.
5. Open a Serial Monitor for each Arduino at **9600 baud**.
6. Enter text on the transmitter Serial Monitor.
7. Align the LED and receiver so the light signal reaches the sensor.
8. The decoded text should appear on the receiver Serial Monitor.

## How it works

```text
Laptop / Serial Monitor
        │
        ▼
Transmitter Arduino UNO
        │
        ▼
Manchester encoding
        │
        ▼
LED ──────── visible light ────────► Solar panel / photodiode
                                      │
                                      ▼
                               Receiver Arduino UNO
                                      │
                                      ▼
                               Serial Monitor
                                      │
                                      ▼
                               Received text
```

## Important notes

- The receiver requires a clear optical path; an obstruction can interrupt the signal.
- Ambient light can affect a practical optical receiver.
- The receiver sketch contains a `threshold` variable inherited from the project code; the current sketch does not directly use that variable in the decoding logic.
- The project documentation describes the prototype as a short-range educational/experimental Li-Fi system rather than a production networking system.

## Future improvements

Possible extensions described in the project documentation include image/audio transmission, improved modulation techniques, higher data rates, and better handling of ambient-light interference.

## Project information

**Project:** Light Based Text Transmission (Li-Fi)  
**Department:** Electrical & Electronics Engineering  
**Institution:** Godavari Institute of Engineering & Technology (A)  
**Project year:** 2024–2025

Authors:
- P Venkata Siva Ajay
- P Akhil
- M Vaishnavi

Supervisor: Mr. Amar Kiran, Associate Professor, EEE
