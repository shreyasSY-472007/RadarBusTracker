# RadarBusTracker
🚌 Hacker-themed bus passenger management system with C Circular Queue backend,  matrix rain, moving buses, radar sweep, live EKG graph, command terminal &amp; FIFO visualization.


# 🚌 BUS_TRACK.SYS — Radar Bus Tracker

```
  ___  _   _ ____     _____ ____      _  ____ _  __
 | __ )| | | / ___|   |_   _|  _ \    / \/ ___| |/ /
 |  _ \| | | \___ \     | | | |_) |  / _ \___ \ ' /
 | |_) | |_| |___) |    | | |  _ <  / ___ \__) | . \
 |____/ \___/|____/     |_| |_| \_\/_/   \____/|_|\_\

[ HALIYAL TRANSIT AUTHORITY ] [ CIRCULAR QUEUE ENGINE v3.0 ] [ FIFO ARMED ]
```

> **A professional hacker-themed bus passenger management system** built with a **C language Circular Queue** backend and a fully animated terminal-style frontend. Simulates a real bus ticket counter with radar visuals, live EKG graphs, command terminal, and passenger queue visualization.

---

## 🖥️ Badges

![Boot Sequence](https://img.shields.io/badge/Boot-Sequence%20Animated-00ff41?style=flat-square&labelColor=010a01)
![Matrix Rain](https://img.shields.io/badge/Matrix-Rain%20Canvas-00ff41?style=flat-square&labelColor=010a01)
![Circular Queue](https://img.shields.io/badge/Data%20Structure-Circular%20Queue-00cfff?style=flat-square&labelColor=010a01)
![Language](https://img.shields.io/badge/Backend-C%20Language-ffb000?style=flat-square&labelColor=010a01)
![Frontend](https://img.shields.io/badge/Frontend-HTML%20%2B%20CSS%20%2B%20JS-00ff41?style=flat-square&labelColor=010a01)
![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)

---

## 📋 Table of Contents

- [Features](#-features)
- [Data Structure](#-data-structure--circular-queue)
- [Project Structure](#-project-structure)
- [Bus Routes](#-bus-routes)
- [How to Run](#-how-to-run)
- [Command Terminal](#-command-terminal-reference)
- [Tech Stack](#-tech-stack)
- [Algorithm](#-algorithm)

---

## ✨ Features

### 🎮 Visual & Animation

| Feature | Description |
|---|---|
| **Matrix Rain** | Full-screen falling katakana + hex characters on canvas |
| **Moving Buses** | 7 pixel-art buses with spinning wheels, headlights, exhaust trails |
| **Radar Sweep** | Top-right animated radar with ping blips and bus labels |
| **Network Nodes** | Drifting neural-net graph with blue data packets |
| **CRT Scanlines** | Authentic retro phosphor monitor overlay with flicker |
| **Glitch Strip** | Random horizontal scan-line flash effect |
| **Particle Bursts** | Green burst on enqueue · Red burst on dequeue · Siren on full |
| **Hex Row** | Animated hexagonal grid cells that randomly light up |
| **Floating Hex Data** | `0xFF` style hex values drifting upward |
| **Boot Sequence** | Realistic kernel boot log before UI appears |
| **Glitch Text** | Logo + bus ID glitch with RGB chromatic aberration |
| **Custom Cursor** | Crosshair ring with lerp follow animation |

### 🚌 Core Functionality

| Feature | Description |
|---|---|
| **5 Bus Routes** | Haliyal → Dharwad / Dandeli / Ramnagar / Belagavi / Hubli |
| **Circular Queue** | 15-seat FIFO queue per bus, mirrors C backend exactly |
| **Add Passenger** | Name + ID + Seat with auto-suggestion of next free seat |
| **Remove Passenger** | FIFO dequeue — first boarded, first removed |
| **Seat Map** | Live 5×3 grid showing occupied/free seats with ASCII avatars |
| **Bus Status** | Green / Amber / Red LED with animated blink |

### 📊 Dashboard Widgets

| Widget | Description |
|---|---|
| **Speedometer Gauges** | 4 arc gauges: passengers, free seats, occupancy, fill |
| **Live EKG Graph** | Scrolling heartbeat chart updating every 500ms |
| **Queue Ring Visualizer** | Animated donut showing all 15 slots + front/rear pointers |
| **Passenger Queue Table** | FIFO list with avatars + name scramble-reveal animation |
| **Progress Bar** | Animated shimmer bar, changes colour at 80% and 100% |
| **Stats Row** | Real-time: passengers / free seats / max / occupancy % |

### 💻 Command Terminal

Fully interactive hacker terminal — control everything by typing commands.

### 🎭 Passenger Avatars + Name Scramble

Each passenger gets a unique ASCII face from their name, e.g. `▲(◉ω◉)`. New names scramble through random characters before revealing.

### 🔊 Sound Effects

Web Audio API keyboard clicks + success/error tones on every action.

---

## 🔵 Data Structure — Circular Queue

The core is a **Circular Queue (Ring Buffer)** implemented in **C**.

```c
#define MAX_SEATS 15

typedef struct {
    char name[64];
    char passengerId[32];
    int  seatId;
} Passenger;

typedef struct {
    Passenger data[MAX_SEATS];
    int  front;   // points to first element
    int  rear;    // points to last inserted
    int  count;   // current passenger count
} CircularQueue;
```

### Wrap-around Visualized

```
After 3 enqueues:
  [ P1 | P2 | P3 | __ | __ | __ | __ | __ | __ | __ | __ | __ | __ | __ | __ ]
     ↑           ↑
  front        rear

After dequeue (P1 removed — FIFO):
  [ __ | P2 | P3 | __ | __ | __ | __ | __ | __ | __ | __ | __ | __ | __ | __ ]
          ↑   ↑
       front rear

Wrap-around (rear circles back to index 0):
  rear = (rear + 1) % MAX_SEATS
```

### Complexity

| Operation | Time | Space |
|---|---|---|
| `enqueue()` | O(1) | O(1) |
| `dequeue()` | O(1) | O(1) |
| `isFull()` | O(1) | O(1) |
| `isEmpty()` | O(1) | O(1) |
| `getAll()` | O(n) | O(n) |

---

## 📁 Project Structure

```
bus-track-sys/
│
├── radar_bus_tracker.html     ← Frontend (open in browser — no server needed)
├── bus_tracker_backend.c      ← C backend (compile + run in terminal)
└── README.md                  ← This file
```

---

## 🗺️ Bus Routes

| Bus ID | From | To | Max Seats |
|--------|------|----|-----------|
| BUS_01 | Haliyal | Dharwad | 15 |
| BUS_02 | Haliyal | Dandeli | 15 |
| BUS_03 | Haliyal | Ramnagar | 15 |
| BUS_04 | Haliyal | Belagavi | 15 |
| BUS_05 | Haliyal | Hubli | 15 |

---

## ▶️ How to Run

### 🌐 Frontend — Open in Browser

```bash
# macOS
open radar_bus_tracker.html

# Windows
start radar_bus_tracker.html

# Linux
xdg-open radar_bus_tracker.html
```

> ✅ No server, no npm install, no dependencies. Pure HTML + CSS + JS.

---

### ⚙️ Backend — Compile & Run C

```bash
# Compile
gcc bus_tracker_backend.c -o bus_tracker

# Run
./bus_tracker
```

**Windows (MinGW / MSVC):**
```bash
gcc bus_tracker_backend.c -o bus_tracker.exe
bus_tracker.exe
```

**Sample session:**
```
╔══════════════════════════════════════╗
║     RADAR BUS TRACKER — MAIN MENU   ║
╚══════════════════════════════════════╝
  [1] Bus 1  Haliyal → Dharwad
  [2] Bus 2  Haliyal → Dandeli
  [3] Bus 3  Haliyal → Ramnagar
  [4] Bus 4  Haliyal → Belagavi
  [5] Bus 5  Haliyal → Hubli
  [0] Exit
  Select Bus ID: 1

┌─────────────────────────────┐
│  BUS 1 DASHBOARD            │
│  Route: Haliyal → Dharwad   │
│  Passengers:  0 / 15        │
├─────────────────────────────┤
│  [1] Add Passenger          │
│  [2] Remove Passenger       │
│  [3] Show Passengers        │
│  [4] Bus Status             │
│  [0] Back to Main Menu      │
└─────────────────────────────┘
  Action: 1
  Passenger Name : Ravi Kumar
  Passenger ID   : P-20241
  Seat ID        : 3
  ✓ Ravi Kumar added to Bus 1 (Seat 3)
```

---

## 💻 Command Terminal Reference

Use the built-in terminal panel on the dashboard page:

| Command | Example | Description |
|---|---|---|
| `help` | `help` | List all commands |
| `status` | `status` | Bus stats + front/rear queue pointers |
| `list` | `list` | All passengers in FIFO order |
| `add` | `add ravi P001 3` | Add passenger (name id seat) |
| `remove` | `remove` | Dequeue front passenger (FIFO) |
| `front` | `front` | Inspect front of queue |
| `rear` | `rear` | Inspect rear of queue |
| `buses` | `buses` | All 5 bus capacities |
| `capacity` | `capacity` | Occupancy % |
| `ping` | `ping` | System latency check |
| `clear` | `clear` | Clear terminal output |

> 💡 **Arrow Up / Down** to scroll command history.

---

## 🛠️ Tech Stack

| Layer | Technology | Purpose |
|---|---|---|
| **Backend Logic** | C Language | Circular Queue data structure |
| **Frontend** | HTML5 | Structure & layout |
| **Styling** | CSS3 | Hacker/terminal theme, all animations |
| **Scripting** | Vanilla JavaScript | Queue logic mirror, UI, canvas control |
| **Canvas — Matrix** | HTML5 Canvas 2D | Falling katakana rain |
| **Canvas — Network** | HTML5 Canvas 2D | Node graph + data packets |
| **Canvas — Road** | HTML5 Canvas 2D | Moving buses + exhaust trails |
| **Canvas — Radar** | HTML5 Canvas 2D | Sweep, blips, rings |
| **Canvas — Particles** | HTML5 Canvas 2D | Bursts + floating hex chars |
| **Audio** | Web Audio API | Clicks, boops, tones |
| **Fonts** | VT323, Share Tech Mono | Terminal aesthetic (Google Fonts) |

---

## 🔬 Algorithm

### Enqueue
```c
int enqueue(CircularQueue *q, Passenger p) {
    if (isFull(q)) return 0;
    q->rear = (q->rear + 1) % MAX_SEATS;  // circular wrap
    q->data[q->rear] = p;
    q->count++;
    return 1;
}
```

### Dequeue (FIFO)
```c
int dequeue(CircularQueue *q, Passenger *out) {
    if (isEmpty(q)) return 0;
    *out     = q->data[q->front];
    q->front = (q->front + 1) % MAX_SEATS;  // circular wrap
    q->count--;
    return 1;
}
```

### Why Circular Queue?

- **No memory waste** — slots reuse as passengers board/alight
- **O(1) operations** — both enqueue and dequeue are constant time
- **True FIFO** — first boarded is first to leave
- **Fixed memory** — 15 slots × 5 buses = 75 passenger records total

---

## 🧑‍💻 Author

Shreyas SY
Built with 💚 and five canvas layers.

> *"Any sufficiently advanced bus tracking system is indistinguishable from a hacker terminal."*

---

## 📄 License

MIT — free to fork, modify, and use.

---

<div align="center">

`[ BUS_TRACK.SYS ONLINE ]` &nbsp;|&nbsp; `[ FIFO ARMED ]` &nbsp;|&nbsp; `[ 5 ROUTES ACTIVE ]`

</div>
