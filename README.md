# Practical Work Nº 3 | Video Game Programming I

## 🎮 Activity
This project was created as part of the **third practical assignment** in the course *Video Game Programming I*.

The goal: build a C++ game where a radioactive train must reach the end of its route with as many wagons as possible.

## 🕹️ Gameplay

[![Ver video del gameplay](https://img.youtube.com/vi/smJ-HRKNhSI/0.jpg)](https://www.youtube.com/watch?v=smJ-HRKNhSI)


## 📝 Objective
Guide a train carrying radioactive material safely to the end of the track, collecting new wagons and avoiding explosions.

### Main mechanics:
- The train starts with a locomotive and two wagons, each randomly numbered between 0 and 9.
- As the train moves, it encounters new wagons.
- To add a new wagon, the player must quickly solve a random addition problem (three numbers from 0 to 9).
- If the answer is correct and given within 5 seconds, the wagon is inserted into the train, sorted by its value.
- If the player answers incorrectly or takes too long, a wagon is removed from the train.

The train scrolls from the top-left of the screen to the right, looping to the next lane below.

## ⏱️ Game over conditions

- **WIn:** keep the train running and collect as many wagons as possible.  
- **Lose:** if all three key elements are destroyed (the locomotive and two wagons).

## 📦 Linked List Implementation

The train uses a **linked list** data structure to:

- Insert new wagons sorted by value.
- Remove wagons dynamically when the player fails.

This shows real-time use of insertion, sorting, and deletion with linked lists.

### Controls

- **Keyboard:** Enter the answer to the math problem when prompted.
- The train moves automatically.

## ⚙️ Technologies used

- C++
- SFML
- Visual Studio

## 🖼️ Assets & License

Graphics used in this project:
- Custom sprites and tiles

---

## 📦 Download
[Download on itch.io](https://juliocz36.itch.io/radioactive-train)

---

## 👨‍💻 Autor

**JulioCZ**  
- Technical Degree in Video Game Design and Programming
