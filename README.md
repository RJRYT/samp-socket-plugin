# SA-MP Socket Plugin (SSL-Free)

![GitHub topic](https://img.shields.io/badge/topic-samp--plugin-blue?logo=github)
![Built without OpenSSL](https://img.shields.io/badge/SSL-Free-lightgrey?logo=lock)
![Windows](https://img.shields.io/badge/platform-Windows-blue?logo=windows)
![Linux](https://img.shields.io/badge/platform-Linux-green?logo=linux)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/RJRYT/samp-socket-plugin?label=release)
![GitHub license](https://img.shields.io/github/license/RJRYT/samp-socket-plugin)
![GitHub stars](https://img.shields.io/github/stars/RJRYT/samp-socket-plugin?style=social)
![GitHub all releases](https://img.shields.io/github/downloads/RJRYT/samp-socket-plugin/total?label=downloads)

A fast and minimal socket plugin for SA-MP (San Andreas Multiplayer), designed to run without SSL and provide simple TCP/UDP communication capabilities for SA-MP scripts.

---

## Features

* Lightweight & minimal
* SSL-free build (for security-paranoid or minimalist environments)
* Easy to compile on Linux and Windows
* Compatible with most modern AMX-based SA-MP scripts

---

### Why I Built This Version

The original BlueG Socket plugin had a major drawback — it relied on OpenSSL (`libcrypto`, `libeay32.dll`, `ssleay32.dll`) which caused runtime issues on both Linux and Windows:

#### 🐧 Linux Issue

```ini
Failed (libcrypto.so.0.9.8: cannot open shared object file: No such file or directory)
```

#### 🪟 Windows Issue

```ini
This application failed to start because libeay32.dll and ssleay32.dll were not found.
```

These external dependencies were either missing, incompatible, or flagged by antivirus software. Most users had no idea how to get the right versions or where to place them.

### ✅ The Solution

I rebuilt the plugin from source and **completely removed OpenSSL**, eliminating these issues:

* 🚫 No more `libcrypto` dependency on Linux
* 🚫 No more `libeay32.dll` / `ssleay32.dll` needed on Windows
* ✅ Just drop the plugin and it works — no DLLs, no errors, no headaches

This makes the plugin **lightweight**, **portable**, and **production-ready**, especially for custom backend communication (e.g., Node.js, Python, etc.).

Built to make your SA-MP experience smoother. 💡

---

## Installation

### Prerequisites

* **SA-MP Server** (0.3.7 or later)
* **Visual C++ Redistributable** (if using Windows DLL)
* **`socket.inc`**: Place it in your `pawno/include` folder

### Windows (x86)

1. Download the latest `socket.dll` from the [Releases](https://github.com/RJRYT/samp-socket-plugin/releases) page.
2. Copy `socket.dll` to your SA-MP server's `plugins` folder
3. Copy `socket.inc` to `pawno/include/`
4. Add `socket` to your `server.cfg` plugins line:

   ```ini
   plugins socket
   ```

### Linux (x86/x64)

1. Download `socket.so` from the [Releases](https://github.com/RJRYT/samp-socket-plugin/releases) page.
2. Copy `socket.so` to your `plugins` folder
3. Copy `socket.inc` to `pawno/include/`
4. Update `server.cfg`:

   ```ini
   plugins socket.so
   ```

> Make sure the plugin file has execute permissions:

```bash
chmod +x plugins/socket.so
```

---

## Build Guide

### Linux

#### Requirements

* `g++`
* `make`

#### Steps

```bash
git clone https://github.com/RJRYT/samp-socket-plugin.git
cd samp-socket-plugin/socket
make
```

Output: `Release/socket.so`

### Windows

#### -Requirements

* [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022)
* `MSBuild` CLI (included in Build Tools)

#### Build Steps

```bash
git clone https://github.com/RJRYT/samp-socket-plugin.git
msbuild "absolute\path\to\socket.vcxproj" /p:Configuration=Release /p:Platform=Win32
```

Output: `Release/socket.dll`

---

## Usage

```pawn
#include <socket>

new Socket:g_socket;

public OnGameModeInit()
{
    g_socket = socket_create(TCP);
    socket_connect(g_socket, "127.0.0.1", 7000);
}

public onSocketAnswer(Socket:id, data[], data_len)
{
    printf("[TCP Server] %s", data);
}
```

---

## License

This project is licensed under the MIT License. See [LICENSE](./LICENSE) for more info.

---

## Credits

* Original by [pBlueG](https://github.com/pBlueG/Socket)
* SSL-free rebuild and cross-platform packaging by [RJRYT](https://github.com/RJRYT)

---

## Releases

Find prebuilt binaries for Windows and Linux under [Releases](https://github.com/RJRYT/samp-socket-plugin/releases)

We recommend using GitHub Releases for cleaner version management without bloating the repo size.

---

## Contributing

Feel free to fork and PR! For bugs, open a GitHub issue with detailed info. Contributions are always welcome.

---

## Contact

* Discord: RJRYT
* GitHub: [github.com/RJRYT](https://github.com/RJRYT)
