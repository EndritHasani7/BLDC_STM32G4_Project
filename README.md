# BLDC Motor Control with STM32G4 and DRV8300

This project implements a Brushless DC (BLDC) motor control system using the STM32G4 microcontroller.  
The system is designed around a modular software architecture with separated motor control, sensing, PWM generation, and fault management layers.  
An external DRV8300 gate driver is used to drive the three-phase power stage.  
The STM32G4 advanced timer peripherals generate high-resolution PWM signals for motor commutation.  
The firmware is developed using STM32CubeIDE and HAL drivers.

## System Architecture

The software is organized into dedicated functional modules:

- `main.c` initializes peripherals and runs the main control loop.  
- `bldc_sm.c` implements the BLDC state machine and commutation logic.  
- `pwm.c` configures and controls the timer-based PWM generation.  
- `sense.c` handles current and signal acquisition using ADC peripherals.  
- `drv8300.c` manages communication and configuration of the DRV8300 gate driver.  
- `fault.c` detects and handles fault conditions such as overcurrent or driver errors.  
- `stm32g4xx_it.c` contains interrupt service routines.  
- `stm32g4xx_hal_msp.c` manages low-level hardware initialization.  

## Hardware Platform

- STM32G4 series microcontroller  
- DRV8300 three-phase gate driver  
- External MOSFET power stage  
- Current sensing circuitry  
- Three-phase BLDC motor  

## Control Strategy

The firmware implements structured motor state control including startup, run, and fault states.  
PWM outputs are generated using advanced timers to ensure precise commutation timing.  
ADC measurements are used for monitoring system behavior and protection.  
Fault handling logic ensures safe shutdown during abnormal operating conditions.  

## Key Features

- Modular motor control architecture  
- Timer-based PWM generation  
- External gate driver interface  
- Current sensing support  
- Fault detection and protection logic  
- Interrupt-driven control structure  

## Development Environment

- STM32CubeIDE  
- STM32 HAL drivers  
- ARM Cortex-M4 core (STM32G4)  

## Application

This project demonstrates embedded motor control design principles suitable for industrial, robotics, and automotive-related applications.  
It showcases real-time control, peripheral synchronization, and power electronics interfacing using STM32G4 microcontrollers.
