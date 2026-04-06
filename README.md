# 🎮 Paintball Platform Prototype

## 📌 Overview
This project is a first-person paintball platform prototype developed in Unreal Engine 5 using a combination of **C++ and Blueprint scripting**. The focus of this project was to build a complete gameplay loop involving combat, AI behavior, respawning, scoring systems, and UI integration.

The prototype emphasizes **gameplay programming, system integration, and player feedback**, combining multiple systems into a functional and polished experience.

---

## 🎥 Gameplay Preview
> *(Replace these with your own GIFs or screenshots)*

![Gameplay GIF](PASTE_GIF_LINK_HERE)

![Combat Screenshot](PASTE_IMAGE_LINK_HERE)

---

## 🧠 Core Features

### ⚔️ Combat System
- Projectile-based combat using C++
- Consistent knockback system
- Damage application for both player and AI
- Hit feedback with sound and visual effects

### 🤖 AI System
- Behavior Tree and Blackboard-driven AI
- Enemy roaming, perception, and attack logic
- Fixed movement animation issues (no more sliding)
- Fully integrated with damage and combat systems

### ❤️ Health & Damage System
- Shared health system for player and AI
- Real-time damage handling
- Heart-based UI that updates dynamically

### 💀 Death & Respawn System
- Death triggered when health reaches zero
- Respawn system with **4 randomized spawn points**
- Seamless return to gameplay loop

### 🧱 Damage Barriers
- Platform fall barrier:
  - Applies partial damage
  - Respawns player if health reaches zero
- Out-of-bounds barrier:
  - Applies lethal damage (instant death)
  - Forces immediate respawn

### 🏆 Scoring System
- Score increases on confirmed kills
- Tracks player performance during gameplay
- Integrated with UI scoreboard

---

## 🖥️ UI Systems

### 🎮 Menus
- Main Menu (Play, Settings, Credits, Exit)
- Pause Menu (Resume, Quit options)
- Controls Menu
- Credits Screen with animated scroll

### 📊 Player UI
- Scoreboard system
- Dynamic player list
- Player name input system
- Heart-based health display

---

## 🔊 Audio & Feedback
- Background music (BGM)
- Combat sound effects (shooting, hits, etc.)
- UI interaction sounds
- Enhanced feedback for player actions

---

## 🛠️ Technologies Used
- Unreal Engine 5
- C++
- Blueprint Visual Scripting
- Visual Studio

---

## 🎯 What I Focused On
- Gameplay programming and system design
- AI behavior and combat interactions
- UI integration and player feedback systems
- Combining C++ and Blueprint workflows effectively

---

## 🚀 Future Improvements
- Environmental kill credit (assigning points when enemies are knocked off platforms)
- Improved AI combat decision-making
- Expanded animation blending (aim offsets, smoother transitions)
- Multiplayer support

---

## 📸 Additional Media
> *(Add more screenshots or GIFs here)*

![UI Screenshot](PASTE_IMAGE_LINK_HERE)

![AI Behavior](PASTE_IMAGE_LINK_HERE)

---

## 📂 How to Run
1. Clone the repository  
2. Open the `.uproject` file in Unreal Engine 5  
3. Build the project (if needed) via Visual Studio  
4. Press Play in the editor  

---

## 👤 Author
Joseph Nolasco  
Gameplay Programmer

---
