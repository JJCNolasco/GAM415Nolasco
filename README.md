# Paintball Platform Prototype

## Overview
This project is a first-person paintball platform prototype developed in **Unreal Engine 5** for *GAM 415: Graphics Game Engine*. The project focuses heavily on **gameplay programming in C++**, combined with Blueprint scripting for rapid iteration and UI systems.

The goal of this project was to design and integrate multiple systems including **procedural terrain generation, rendering techniques, AI combat, UI systems, and gameplay mechanics** into a polished and functional prototype.

---

## Gameplay Preview


---

## Core Systems

### Procedural Terrain System
- Procedural terrain generation using **Perlin Noise**
- Editable parameters for terrain shaping
- Runtime terrain modification via **player raytrace interaction**
- Custom mesh and UV generation

---

### Portal System (Rendering)
- Fully functional portal system using:
  - **Scene Capture Components**
  - **Render Targets**
- Real-time rendering of alternate viewpoints
- Player can **see through and teleport between portals**
- Material-based portal surface rendering

---

### Dynamic Minimap System
- Built using **Scene Capture + Render Target**
- Displays:
  - Player position
  - Enemy indicators
- Updates in real-time

---

### Combat System
- Projectile-based combat written primarily in **C++**
- Refactored knockback system for consistency
- Damage handling for player and AI
- Projectile color randomization with matching splatter decals
- Niagara particle systems for:
  - Muzzle effects
  - Impact/splatter effects

---

### AI System
- Behavior Tree and Blackboard implementation
- AI roaming, perception, and attack logic
- Fixed movement animation issues (no sliding)
- Fully integrated with combat and damage systems

---

### Health, Damage & Respawn
- Shared health system for player and AI
- Death triggered at zero health
- Respawn system with **4 randomized spawn points**
- Two damage barriers:
  - **Platform barrier** (partial damage + conditional respawn)
  - **Out-of-bounds barrier** (instant death + respawn)

---

### Scoring System
- Score increases on confirmed kills
- Integrated with UI scoreboard and player list
- Tracks gameplay performance

---

## UI Systems

### Menus
- Main Menu (Play, Settings, Credits, Exit)
- Pause Menu (Resume, Quit options)
- Controls Menu
- Credits screen with animated scroll

### Player UI
- Scoreboard system
- Dynamic player list
- Player name input system
- Heart-based health UI (updates in real-time)

---

## Materials & Visual Effects
- Dynamic Material Instances
- Procedural mesh materials
- Projectile and decal color randomization
- Splatter decals applied on impact
- Niagara systems for particle effects

---

## Audio & Feedback
- Background music (BGM)
- Combat sound effects
- UI interaction sounds
- Enhanced gameplay feedback

---

## Technologies Used
- Unreal Engine 5
- C++
- Blueprint Visual Scripting
- Niagara VFX System
- Render Targets & Scene Capture
- Visual Studio

---

## Key Focus Areas
- Gameplay programming in C++
- Rendering systems (portals, minimap)
- Procedural generation
- AI behavior and combat systems
- UI system integration
- Combining engine-level systems with gameplay features

---

## Future Improvements
- Environmental kill credit (tracking knock-off eliminations)
- Improved AI combat decision-making
- Enhanced animation blending (aim offsets, smoother transitions)
- Multiplayer support

---

## Additional Media
> *(Add more screenshots or GIFs here)*

![Portal System](PASTE_IMAGE_LINK_HERE)

![Minimap](PASTE_IMAGE_LINK_HERE)

![Procedural Terrain](PASTE_IMAGE_LINK_HERE)

---

## Author
Joseph Nolasco  
Gameplay Programmer
