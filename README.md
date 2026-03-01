# 🌡 Arduino DHT11 I2C Weather Station

A structured embedded systems project that measures temperature and humidity using a DHT11 sensor and displays the readings on a 16x2 I2C LCD.

This project demonstrates clean firmware architecture, non-blocking timing using `millis()`, and modular design principles.

---

## 📷 Circuit Diagram

![Circuit Diagram](images/circuit_diagram.png)

---

## 🔧 Hardware Components

- Arduino UNO
- DHT11 Temperature & Humidity Sensor
- 16x2 LCD with I2C Module
- 10kΩ Pull-up Resistor (if using bare DHT11)
- Jumper Wires
- Breadboard

---

## 🔌 Pin Configuration

### DHT11

| DHT11 Pin | Arduino UNO |
|------------|------------|
| VCC        | 5V |
| GND        | GND |
| DATA       | Digital Pin 11 |

### I2C LCD

| LCD Pin | Arduino UNO |
|----------|------------|
| VCC      | 5V |
| GND      | GND |
| SDA      | A4 |
| SCL      | A5 |

I2C Address used: `0x27`

---

## ⚙️ Features

- Non-blocking sampling using `millis()`
- Error handling for sensor read failures
- Modular function-based firmware design
- Clean serial debugging output
- Stable I2C communication

---

## 📂 Project Structure
