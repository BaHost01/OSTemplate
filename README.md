XMPL OS

XMPL OS is an experimental operating system focused on modular architecture and script-driven control. It combines low-level programming (Assembly + C) with high-level scripting (Lua) to create a flexible and extensible environment.

---

🚀 Vision

XMPL is not just an OS — it’s a hybrid platform where:

- The kernel controls the hardware
- The system exposes functionality through syscalls
- Lua scripts control system behavior

---

🧠 Architecture

Bootloader (Assembly)
        ↓
Kernel (C)
        ↓
Syscalls (int 0x80)
        ↓
Lua Runtime
        ↓
CLI / Apps

---

⚙️ Technologies

- Assembly (Bootloader)
- C (Kernel)
- Lua (Scripting & CLI)
- FAT12 (Filesystem)
- QEMU (Emulation)

---

📁 Project Structure

xmpl/
 ├── boot/        # Bootloader
 ├── kernel/      # Kernel, syscalls, interrupts
 ├── drivers/     # Hardware drivers (keyboard, video, etc.)
 ├── fs/          # Filesystem (FAT12)
 ├── lua/         # Lua integration
 ├── user/        # User scripts & apps
 ├── build/       # Build scripts
 └── image/       # Bootable image

---

🔥 Current Features

- Functional x86 bootloader
- Kernel loaded into memory
- Direct VGA text output
- Keyboard input via BIOS
- Basic Linux-style CLI
- Embedded Lua runtime
- Foundation for interrupt-based syscalls

---

🧪 Build & Run

Requirements

- "clang"
- "nasm"
- "ld"
- "qemu-system-x86_64"
- "dosfstools" (mkfs.fat)

Build

cd xmpl/build
./build.sh

Run

qemu-system-x86_64 -drive format=raw,file=../image/xmpl.img

---

💻 CLI (XMPL Shell)

Example:

xmpl> help
xmpl> clear
xmpl> exit

Planned:

- "run script.lua"
- "echo"
- modular command system

---

📦 Filesystem

- Based on FAT12
- Initial support for reading data
- Goal: load "/init.lua" directly from disk

---

🌙 Lua Integration

XMPL uses Lua as the main control layer:

write("XMPL initialized")

while true do
    write("xmpl> ")
    local cmd = read()
end

Lua interacts with the kernel through exposed syscalls.

---

🧩 Roadmap

Next steps

- [ ] Full FAT12 parser (real file loading)
- [ ] Proper IDT + real syscalls ("int 0x80")
- [ ] Protected mode (32-bit)
- [ ] Memory management
- [ ] Process system
- [ ] Scheduler
- [ ] Multi-program execution
- [ ] Real hardware drivers (no BIOS)

---

⚠️ Status

XMPL OS is under active development.

- Not stable
- Not secure
- Built for learning and experimentation

---

🧠 Philosophy

«Full control. Minimal abstraction.
Simple kernel, powerful scripting system.»

---

📜 License

Define as needed (MIT recommended).

---

👤 Author

XMPL OS developed by you.
