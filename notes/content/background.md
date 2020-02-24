# Background

## WebAssembly

- Originally created in 2015 for fast code execution in web browsers, based on the wasm.js (mozilla) and native client (google) projects
- Now a portable compile target meant to run in a stack based machine
- MVP release in March of 2017
- Supports mainly C/C++ but many other languages are emerging
- Spec in development
- Empahsis on minimal nondeterminism
- As of 2019 >50% use for malicous purposes

## IoT and WebAssembly

- Good fit since WASM is meant to be simple, size- and load-time-efficient
- First exploration of execution outside the browser
- Non-web execution is a stated goel of the working groups
- Introduces exciting ways of using new languages to target many platforms
- Potential to become a widely adopted and portable format
- Possibility of a native WASM cpu

## Microcontroller

- small computer on a single chip
- built for minimal power consumption
- not very sophisticated => cheap and offer more usecases
- focus on interrupt latency to reduce latency

### ESP32

- Popular microcontroller by espressif
- Includes WiFi and bluetooth
- Made for IoT with additional functionality such as filters
- Very low power consumption
- Big limitaions to reach power and price targets

## Microbenchmarking

- Mostly compare the performance of two chips
- In this case, compare the performance of WebAssembly vs native code
- Run tests with m,ore and less predictable branching
- Testing with common algorithms (sort, matrix multiplication ...)
