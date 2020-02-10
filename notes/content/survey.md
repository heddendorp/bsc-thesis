# Survey of existing WebAssembly runtimes
## Requirements
 - This project needs a C runtime
 - Runtime has to provide a C API to be embedded into the code
 - Runtime should provide a way to call native code
## Findings
 - Many JIT solutions but none appear usable on the ESP32 as they are not designed to be run in such a constricted environment
 - Extrmely poor documentation, most projects have spotty documentation at best
 - Very few experimental projects
   - The best information is from reading code that does certain things on the platform
   - Luckily people do experiment with the ESP32 a fair bit
   - Working out how things work in principle from experimantel code is somewhat hard
 - WASM3 seems to be a very promising project
   - Meant for use on embedded systems
   - Already comes with very basic ESP32 examples
   - Has ways to call native code
   - Has a team that responds even to fairly basic questions
   - Is apparently the fastest runtime currently available