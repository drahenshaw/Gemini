# Gemini Game Engine

## Introduction

Gemini is a Two-Dimensional C++ Game Engine written in C++. It uses OpenGL, more specifically GLEW and GLFW to render graphics.
The engine has rotational hit-box detection physics based on the Separating Axis Theorem. The overall goal for Gemini is to
practice implementing various Game Design Programming Patterns.

## Demo Game built using Gemini

I built a "Flappy Bird" style game using Gemini.

## Future Goals

### Audio Engine

Integrating an Audio Engine into Gemini is the next step using OpenAL.
Parts of the audio library are deprecated, so parsing audio files will need to be done manually.

### Planned Features

Powerups: A few different powerups that impact score, game pace, visual effects, etc.
TextRendering: Using FreeType to display a menu and score for the player.
Achievements: Use of the Observer pattern to unlock based on in game events. 

## Game Programming Patterns

Singleton: Only used sparingly for a GameManager and the Engine classes. The pattern is enforced with get_instance() and private constructors.
Service Locator: Decoupling audio, logging, and resource management from the rest of the code - this is a future goal as the project expands.
GameState: Keeping track of various stages of the game using state classes.
GameLoop: Infinite GameLoop until exit conditions are met.
Command: May expand on this as the project grows, but not needed now for simple input.
Observer: I love trophy hunting, so this one is a future goal!

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
