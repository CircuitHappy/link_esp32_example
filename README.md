# Example project for Ableton Link on ESP32
Minimal example for using Ableton Link with esp-idf on ESP32

## Usage
* Setup esp-idf following the instructions on https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html
* Clone repository with `git clone --recursive https://github.com/mathiasbredholt/link_esp32_example.git`
* Run `idf.py menuconfig` and setup WiFi credentials under `Example Connection Configuration`
* Build and flash by running `idf.py build && idf.py flash`