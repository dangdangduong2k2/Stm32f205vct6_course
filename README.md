# 📘 Stm32f205vct6_course

This repository provides a collection of **bare-metal firmware examples** for the **STM32F205VCT6** microcontroller, written using **direct register access** (no HAL, no CMSIS, no SPL). It's designed for learning how STM32 peripherals work from the ground up.

---

## 🧠 What’s inside?

Each module demonstrates the configuration of one or more peripherals using their memory-mapped registers — helping you deeply understand how the STM32F2 series operates at the hardware level.

---

## 🧩 Topics Covered

- ✅ GPIO (input/output using `MODER`, `ODR`, `IDR`)
- ✅ UART (register-level config for TX/RX via `USARTx`)
- ✅ External Interrupts (EXTI + NVIC + SYSCFG)
- ✅ Timers for delay and PWM
- ✅ ADC (single channel read, polling method)
- ✅ Delay using `SysTick`
- ✅ Clock configuration via `RCC` and `FLASH`
- ✅ Vector table relocation and memory remap (if needed)

---

## ⚙️ Toolchain

- 💻 **IDE**: STM32CubeIDE, Keil, or VS Code with Makefile
- 🔧 **Compiler**: `arm-none-eabi-gcc`
- 🛠 **Startup & Linker**: Custom `startup.s` and `linker.ld` (or CMSIS ones)
- 🧱 **Target MCU**: STM32F205VCT6 (Cortex-M3, 256 KB Flash, 100 pins)

---

## 📁 Folder Structure

