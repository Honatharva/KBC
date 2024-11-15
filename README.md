# KBC
KBL Mini-Project: Players answer a series of 7 questions to win increasing cash rewards. Features lifelines like 50-50, Audience Poll, and Answer Predictor, usable only once. Incorrect answers end the game. Includes rules display, lifeline logic, and gameplay flow for an engaging user experience.
# Kaun Banega Lakhpati (KBL) - CLI Game 🎮

Kaun Banega Lakhpati (KBL) is a simple command-line game inspired by the famous quiz show *Kaun Banega Crorepati (KBC)*. The game challenges players with a series of trivia questions, offering lifelines to help answer tough ones.

## Features 🚀

- **7 Questions** with increasing difficulty levels.
- **Lifelines**:
  - 50-50: Eliminates two incorrect options.
  - Audience Poll: Displays the probability of each option being correct.
  - Answer Predictor: Reveals the correct answer.
- Earn increasing rewards for each correct answer.
- A game-over system when the wrong answer is chosen.

## Game Rules 📜

1. Answer the questions correctly to win the prize money for each question.
2. Use lifelines wisely:
   - Each lifeline can only be used once.
   - You must use a lifeline if you choose to do so.
3. Incorrect answers end the game immediately.
4. Total winnings are displayed upon game completion.

## How to Play 🎲

1. Clone the repository or download the source code.
2. Compile the game using a C++ compiler:
   ```bash
   g++ kbl_game.cpp -o kbl_game
