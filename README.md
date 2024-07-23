<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>ESP32 Light Tracker</h1>

<h2>Description</h2>
<p>The ESP32 Light Tracker is a project to control servos that track light using Light Dependent Resistors (LDRs). This project allows three modes of operation: automatic light tracking, manual control via Bluetooth, and a panic mode that sets the servos to a predefined position. It also includes advanced features like automatic LDR calibration and diagnostic mode.</p>

<h2>Features</h2>
<ul>
    <li><strong>Real-time Light Tracking:</strong> The system continuously monitors light intensity using LDRs and adjusts the position of the servos to maximize light exposure.</li>
    <li><strong>Efficiency Optimization:</strong> Dynamically tracks the light's position, significantly increasing efficiency.</li>
    <li><strong>Bluetooth Control:</strong> Integrates Bluetooth functionality, allowing users to remotely control and monitor the system via a smartphone or other Bluetooth-enabled devices.</li>
    <li><strong>Emergency Mode (Panic):</strong> In case of emergencies, the system can activate a panic mode, moving the servos to a predefined safe position.</li>
    <li><strong>Automatic LDR Calibration:</strong> Calibrates the LDRs at startup to ensure accurate light tracking.</li>
    <li><strong>Diagnostic Mode:</strong> Continuously prints the values of the LDRs and the angles of the servos for easy troubleshooting.</li>
</ul>

<h2>Requirements</h2>

<h3>Hardware Requirements</h3>
<ul>
    <li><strong>Minimum MCU:</strong> 256-512kB Flash, 16-24kB SRAM, 16MHz</li>
    <li><strong>Recommended MCU:</strong> 512kB-1MB+ Flash, 24-32kB+ SRAM, 32-48MHz+</li>
</ul>

<h3>Compatible Microcontrollers</h3>
<ul>
    <li><strong>Definitely Works:</strong> GIGA, Portenta (any), ESP32/8266, Teensy 3.5+, STM32 (>256kB), Pico/RP2040 (any)</li>
    <li><strong>May Work (with external data/minimal UI):</strong> Uno R4, Nano 33 (any), MKR (any), Due/Zero, STM32 (256kB)</li>
    <li><strong>May Work (with heavy adjustments/limited build):</strong> ATMega2560, Genuino 101, Teensy 3.2 (/3.1), STM32F0</li>
    <li><strong>Definitely Won't Work:</strong> Uno (classic up to R3), Nano (classic and Every), Leonardo/Duemilanove, Micro, Pro, Esplora, Teensy 2/LC, STM8 (|32<256kB), ATtiny (any)</li>
</ul>

<h3>Components</h3>
<ul>
    <li>ESP32</li>
    <li>4x Light Dependent Resistors (LDRs)</li>
    <li>2x Servo Motors</li>
    <li>1x Bluetooth Module (integrated into ESP32)</li>
    <li>Resistors</li>
</ul>

<h3>Connection Scheme</h3>
<p><img src="https://drive.google.com/uc?export=view&id=1QWrT_bZSrWUGSNd7l1CWe_IeeuWR4Lq9" alt="Connection Scheme"></p>
<p><img src="https://drive.google.com/uc?export=view&id=1lQeS_DON3KihkdE4mqvhljHWYpZLRqEF" alt="Connection Scheme"></p>

<h2>Installation and Setup</h2>

<h3>Clone the Repository</h3>
<pre><code>git clone https://github.com/Yagoox/ESP32-Light-Tracker.git</code></pre>

<h3>Navigate to the Project Directory</h3>
<pre><code>cd ESP32-Light-Tracker</code></pre>

<h3>Install Dependencies</h3>
<p>Ensure you have the necessary libraries installed in your Arduino IDE or other development environments.</p>

<h3>Setup Wokwi Simulation</h3>
<p>To simulate the project using Wokwi, ensure you have the <code>wokwi.toml</code> file configured properly in the project directory. Here is an example of the configuration:</p>
<pre><code>
[wokwi]
version = 1
elf = "build/esp32doit-devkit-v1/firmware.elf"
firmware = "build/esp32doit-devkit-v1/firmware.bin"

[[net.forward]]
from = "localhost:8180"
to = "target:80"
</code></pre>

<h2>Usage</h2>
<ol>
    <li><strong>Upload the Code:</strong> Use the Arduino IDE or another compatible environment to upload the provided code to the ESP32.</li>
    <li><strong>Connect the Hardware:</strong> Follow the connection scheme to connect all components correctly.</li>
    <li><strong>Power On:</strong> Power on the ESP32 and observe the servo motors adjusting the solar panel's orientation based on real-time sunlight tracking.</li>
    <li><strong>Bluetooth Control:</strong> Use a Bluetooth-enabled device to connect to the ESP32 and remotely control or monitor the system.</li>
    <li><strong>Simulate with Wokwi:</strong> Use the Wokwi simulation environment to test the project virtually.</li>
</ol>

<h2>Project Structure</h2>
<ul class="project-structure">
<li class="folder">src/</li>
<li class="file">config.h: Pin definitions and configurations.</li>
<li class="file">main.cpp: Main file with project logic.</li>
<li class="file">servos.h: Functions for servo control.</li>
<li class="file">servos.cpp: Implementation of servo control functions.</li>
<li class="file">bluetooth.h: Functions for Bluetooth control.</li>
<li class="file">bluetooth.cpp: Implementation of Bluetooth control functions.</li>
<li class="file">ldr.h: Functions for LDR reading.</li>
<li class="file">ldr.cpp: Implementation of LDR reading functions.</li>
<li class="file">utils.h: Utility functions.</li>
<li class="file">utils.cpp: Implementation of utility functions.</li>
</ul>

<h2>Advanced Features</h2>
<ul>
    <li><strong>Customizable Tracking Algorithm:</strong> Modify the tracking algorithm to suit different environmental conditions or preferences.</li>
    <li><strong>Data Logging:</strong> Implement data logging to record sunlight intensity and panel positions for analysis.</li>
    <li><strong>Remote Updates:</strong> Enable remote firmware updates via Bluetooth or Wi-Fi.</li>
</ul>

<h2>Contribution</h2>
<p>We welcome contributions to the ESP32 Light Tracker project. Please follow these guidelines:</p>

<h3>Fork the Repository</h3>
<p>Create a personal fork of the repository on GitHub.</p>

<h3>Create a Feature Branch</h3>
<pre><code>git checkout -b feature/YourFeatureName</code></pre>

<h3>Commit Your Changes</h3>
<pre><code>git commit -m "Add your message here"</code></pre>

<h3>Push to the Branch</h3>
<pre><code>git push origin feature/YourFeatureName</code></pre>

<h3>Open a Pull Request</h3>
<p>Provide a detailed description of your changes and submit a pull request for review.</p>

<h2>Testing</h2>
<p>To run tests, follow these steps:</p>
<ol>
    <li><strong>Setup Test Environment:</strong> Ensure all hardware components are connected as per the connection scheme.</li>
    <li><strong>Execute Test Scripts:</strong> Run the provided test scripts to verify the functionality of the system.</li>
    <li><strong>Review Test Results:</strong> Analyze the test outputs and logs to ensure the system is working as expected.</li>
</ol>

<h2>Version History</h2>
<ul>
    <li><strong>v1.0:</strong> Initial release with basic light tracking functionality.</li>
    <li><strong>v1.1:</strong> Added Bluetooth control and emergency mode.</li>
    <li><strong>v1.2:</strong> Improved tracking algorithm and performance optimizations.</li>
    <li><strong>v1.3:</strong> Added advanced features like automatic LDR calibration and diagnostic mode.</li>
</ul>

<h2>License</h2>
<p>This project is licensed under the MIT License - see the LICENSE file for details.</p>

<h2>References and Additional Resources</h2>
<ul>
    <li><a href="https://docs.espressif.com/projects/esp-idf/en/latest/esp32/">ESP32 Documentation</a></li>
    <li><a href="https://www.arduino.cc/en/Main/Software">Arduino IDE</a></li>
    <li><a href="https://randomnerdtutorials.com/esp32-servo-motor-web-server/">Servo Motor Control with ESP32</a></li>
    <li><a href="https://randomnerdtutorials.com/esp32-bluetooth-classic-arduino-ide/">Bluetooth Communication with ESP32</a></li>
</ul>

</body>
</html>
