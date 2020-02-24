# Microcontrollers and the ESP32

## Structure

- Microconctrollers
  - Intro
  - Parts
  - Application
- ESP32 SoC
  - low cost, low power SoC with WiFi sand bluetooth
  - Wildly popular
  - Big limitations
- FreeRTOS
  - RTOS intro
  - FreeRTOS

## Text

### Microcontroller|Intro

Since this thesis is focused on the use of WebAssembly on microncontrollers we'd like to shortly introduce the concept and limitations. A microcontroller (**MCU** for microcontroller unit) is a small computer, meant to fulfill a very specifc requirement without a complex operating system. They are designed for embedded applications from implanable medical devices to toys and very prominently in IoT devices. Devices will often have multiple microcntrollers each responsible for a very specific function, a car for example could include amongst others a MCU to control the mirror adjustemnts, one to handle fuel injection and another one for traction control.

### Microcontroller|Parts

Core elements of a MCU are the processor, memory and I/O peripherals. The Processor (CPU) can be though of as the brain of the MCU, it performes basic arithmetic, logic and I/Ooperations. The memory is where aby data is store the processor needs to fullfill it's tasks. Mainly there is program memory, which holds the MCUs instructions and Data memory, which servers as temporary storage while a program is exectued. Lastly the I/O peripherals are the controllers connection to the outside world, they allow the receiving and sending of information, such as receiving a signal from a switch and turning on a light in response.

### ESP32|low cost

For this thesis we want to specifically focus on the ESP32 system on a chip (SoC). A very popular low-cost, low power series of microcontrollers with integarted WiFi and bluetooth. Developed by the Shanghai based comapny Espressif Systems this successor to the ESP8266 offers a great platform for IoT and embedded projects. Comapred to the the MCU described before the ESP32 has additional processing power and I/O options that make it a great platform for developing secure IoT devcices. It gained popularity fast after being released in september of 2016.

### ESP32|popular

The ESP32 systems family provides an excellent base for many IoT applications. There are multiple version available from ones very well suited for hobbyists to ones usable in industrial manufactures. With a low price point and area footprint they still provide significant performance and many operational features.

### ESP32|limitations

To reach price and power consumtion targets the ESP32 has significant hardware limitations. This introduces some constraints when working with the platform. The Operating system for example can hardly be called that. Compared to popular operating systems like windows and linus the used FreeRTOS can be thought of like a thread library. This speciality will be further explained in a following passage.

### FreeRTOS|intro

Many MCUs are used in applications where throughput is less importance than a guaranteed performance. This is why the ESP32 uses FreeRTOS, a real time operating system (RTOS) is specifically intedned to be used in time critical situations. A key characteristic of such an operating system is the predictable behaviour of the scheduler, the part of the operating system that decides which task should be run by the CPU at any give time. Most schedulers allow the user to set priorities for tasks in order to decide which task should be run next.

### FreeRTOS|FreeRTOS

FreeRTOS specifically is the leading RTOS amongst MCUs and is designed to be small enough to run on a microcontroller. Since most applications in which MCUs are used don't warrant the use of a full RTOS, FreeRTOS only provides the core scheduling functionality, timing and synchronisation primitives. It can however be estenden by using addon compontents for example to make use of a specific networking stack. FreeRTOS also built a significant comminuty and support for many platforms in its 15 yaer development.
