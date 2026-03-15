<a name="readme-top"></a>

<div align="center">

<h1 align="center">ESP32 Light Tracker</h1>

<br>

# Welcome to the ESP32 Light Tracker repository

---

<div align="center">

[![CI Status][ci-shield]][ci-link]
[![PlatformIO][platformio-shield]][platformio-link]
[![MIT License][license-shield]][license-link]

</div>

[ci-shield]: https://img.shields.io/github/actions/workflow/status/YagoBorba/ESP32-Light-Tracker/ci.yml?branch=main&style=flat-square&logo=githubactions&label=CI
[ci-link]: https://github.com/YagoBorba/ESP32-Light-Tracker/actions
[platformio-shield]: https://img.shields.io/badge/PlatformIO-ESP32-F5822A?style=flat-square&logo=platformio&logoColor=white
[platformio-link]: https://platformio.org/
[license-shield]: https://img.shields.io/github/license/YagoBorba/ESP32-Light-Tracker?style=flat-square&logo=github&labelColor=black&color=508CF9
[license-link]: https://github.com/YagoBorba/ESP32-Light-Tracker/blob/main/LICENSE

</br>

</div>

## ❤️ About the Project

> [!IMPORTANT]
> ESP32 Light Tracker was designed to make solar/light tracking projects practical and accessible with embedded hardware. If this project helps you, leave a star in the repository. ⭐

The ESP32 Light Tracker controls two servo motors based on readings from four LDR sensors. It supports three operating modes: automatic light tracking, manual control via Bluetooth, and panic mode (safe predefined servo position). The project also includes automatic LDR calibration and a diagnostic mode for real-time telemetry.

## ✨ Features

- 🚀 **Real-time Light Tracking:** Continuously monitors LDR readings and adjusts servo position to maximize light exposure.
- 📈 **Efficiency Optimization:** Dynamically follows the strongest light direction to improve capture efficiency.
- 📶 **Bluetooth Control:** Enables remote manual control and monitoring using Bluetooth-capable devices.
- 🆘 **Emergency Mode (Panic):** Moves servos to a predefined safe position when panic mode is activated.
- 🎯 **Automatic LDR Calibration:** Calibrates sensors at startup for more stable and accurate tracking.
- 🩺 **Diagnostic Mode:** Prints LDR values and servo angles continuously for troubleshooting and tuning.

## 🛠️ Under the Hood (Main Technologies)

- **[ESP32](https://www.espressif.com/en/products/socs/esp32):** Main microcontroller platform.
- **[PlatformIO](https://platformio.org/):** Build system and project management for embedded development.
- **[Wokwi](https://wokwi.com/):** Hardware simulation environment for virtual testing.
- **Arduino-compatible libraries:** Servo control, Bluetooth, sensor reading, and utility modules.

## 📋 Requirements

### Hardware Requirements

- **Minimum MCU:** 256-512kB Flash, 16-24kB SRAM, 16MHz
- **Recommended MCU:** 512kB-1MB+ Flash, 24-32kB+ SRAM, 32-48MHz+

### Compatible Microcontrollers

- **Definitely Works:** GIGA, Portenta (any), ESP32/8266, Teensy 3.5+, STM32 (>256kB), Pico/RP2040 (any)
- **May Work (with external data/minimal UI):** Uno R4, Nano 33 (any), MKR (any), Due/Zero, STM32 (256kB)
- **May Work (with heavy adjustments/limited build):** ATMega2560, Genuino 101, Teensy 3.2/3.1, STM32F0
- **Definitely Won't Work:** Uno (classic up to R3), Nano (classic and Every), Leonardo/Duemilanove, Micro, Pro, Esplora, Teensy 2/LC, STM8 (32<256kB), ATtiny (any)

### Components

- ESP32
- 4x Light Dependent Resistors (LDRs)
- 2x Servo Motors
- 1x Bluetooth Module (integrated into ESP32)
- Resistors

### Connection Scheme

![Connection Scheme 1](https://drive.google.com/uc?export=view&id=1QWrT_bZSrWUGSNd7l1CWe_IeeuWR4Lq9)

![Connection Scheme 2](https://drive.google.com/uc?export=view&id=1lQeS_DON3KihkdE4mqvhljHWYpZLRqEF)

## 🚀 Getting Started

### Clone the Repository

```bash
git clone https://github.com/YagoBorba/ESP32-Light-Tracker.git
```

### Navigate to Project Directory

```bash
cd ESP32-Light-Tracker
```

### Install Dependencies

Ensure the required Arduino/PlatformIO libraries are available in your environment.

### Setup Wokwi Simulation

Use the existing `wokwi.toml` in the root folder. Example expected config:

```toml
[wokwi]
version = 1
elf = "build/esp32doit-devkit-v1/firmware.elf"
firmware = "build/esp32doit-devkit-v1/firmware.bin"

[[net.forward]]
from = "localhost:8180"
to = "target:80"
```

## ▶️ Usage

1. **Upload the code:** Use PlatformIO, Arduino IDE, or another compatible environment to flash the ESP32.
2. **Connect the hardware:** Wire all components according to the connection diagrams.
3. **Power on:** Start the board and observe servo adjustment based on real-time light readings.
4. **Bluetooth control:** Connect from a Bluetooth-enabled device to manually control/monitor behavior.
5. **Simulate with Wokwi:** Validate behavior virtually before deploying to hardware.

## 📁 Project Structure

```text
.
├── include/
│   ├── bluetooth.h   # Bluetooth control interfaces
│   ├── config.h      # Pin definitions and system config
│   ├── ldr.h         # LDR reading interfaces
│   ├── servos.h      # Servo control interfaces
│   └── utils.h       # Shared utility helpers
├── src/
│   ├── bluetooth.cpp # Bluetooth implementation
│   ├── ldr.cpp       # LDR implementation
│   ├── main.cpp      # Main application logic
│   ├── servos.cpp    # Servo implementation
│   └── utils.cpp     # Utility implementation
├── lib/
├── test/
├── platformio.ini
└── wokwi.toml
```

## 🧪 Advanced Features

- **Customizable Tracking Algorithm:** Tune tracking behavior for different environments.
- **Data Logging (optional extension):** Record light intensity and servo positions for analysis.
- **Remote Updates (optional extension):** Extend to firmware updates via Bluetooth or Wi-Fi.

## 🤝 Want to Contribute?

Contributions are welcome.

1. Fork the repository.
2. Create a feature branch:

```bash
git checkout -b feature/YourFeatureName
```

3. Commit your changes:

```bash
git commit -m "Add your message here"
```

4. Push your branch:

```bash
git push origin feature/YourFeatureName
```

5. Open a Pull Request with a clear description.

## ✅ Testing

1. Ensure hardware is connected according to the connection scheme.
2. Execute available test scripts/check routines.
3. Review serial logs and behavior to validate expected operation.

## 🕒 Version History

- **v1.0:** Initial release with basic light tracking.
- **v1.1:** Added Bluetooth control and panic mode.
- **v1.2:** Improved tracking algorithm and performance.
- **v1.3:** Added automatic LDR calibration and diagnostic mode.

## 📝 License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for more details.

## 📚 References

- [ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- [Servo Motor Control with ESP32](https://randomnerdtutorials.com/esp32-servo-motor-web-server/)
- [Bluetooth Communication with ESP32](https://randomnerdtutorials.com/esp32-bluetooth-classic-arduino-ide/)

---

<div align="right">
    <a href="#readme-top">Back to Top</a>
</div>
