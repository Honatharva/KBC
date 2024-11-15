#include <iostream>
#include <string>
using namespace std;

class QuizShow {
public:
    char useLifeline, lifelineChoice;
    int lifelineCount = 0;
    bool lifelines[3] = {true, true, true}; // 50-50, Audience Poll, Answer Predictor
    void displayRules();
    void useLifelines();
    void askQuestion(const string& question, const string& options, char correctAnswer, int prize, int& totalEarnings);
};

void QuizShow::displayRules() {
    string name;
    cout << "Welcome to KON BANEGA LAKHPATHI\n";
    cout << "Enter your name: ";
    cin >> name;
    cout << "\n******* GAME RULES *******\n";
    cout << "1. Total of 7 questions with increasing rewards.\n";
    cout << "2. You can use (Y/y) for yes and (N/n) for no.\n";
    cout << "3. Three lifelines available, each can be used only once:\n";
    cout << "   A. 50-50 - Removes two incorrect options.\n";
    cout << "   B. Audience Poll - Displays percentage chances for each option.\n";
    cout << "   C. Answer Predictor - Directly gives the correct answer.\n";
    cout << "4. Incorrect answers result in disqualification.\n";
    cout << "*************************\n";
}

void QuizShow::useLifelines() {
    if (lifelineCount >= 3) {
        cout << "\nAll lifelines have been used.\n";
        return;
    }
    cout << "\nAvailable Lifelines:\n";
    if (lifelines[0]) cout << "A. 50-50\n";
    if (lifelines[1]) cout << "B. Audience Poll\n";
    if (lifelines[2]) cout << "C. Answer Predictor\n";

    cout << "Enter your choice: ";
    cin >> lifelineChoice;

    switch (lifelineChoice) {
        case 'A':
        case 'a':
            if (lifelines[0]) {
                cout << "\nHint: Two incorrect options removed.\n";
                lifelines[0] = false;
                lifelineCount++;
            } else {
                cout << "\n50-50 lifeline already used.\n";
            }
            break;
        case 'B':
        case 'b':
            if (lifelines[1]) {
                cout << "\nAudience Poll:\nA: 40%\nB: 30%\nC: 20%\nD: 10%\n";
                lifelines[1] = false;
                lifelineCount++;
            } else {
                cout << "\nAudience Poll lifeline already used.\n";
            }
            break;
        case 'C':
        case 'c':
            if (lifelines[2]) {
                cout << "\nAnswer Predictor: Option A is correct.\n";
                lifelines[2] = false;
                lifelineCount++;
            } else {
                cout << "\nAnswer Predictor lifeline already used.\n";
            }
            break;
        default:
            cout << "\nInvalid choice. Please choose again.\n";
            useLifelines();
    }
}

void QuizShow::askQuestion(const string& question, const string& options, char correctAnswer, int prize, int& totalEarnings) {
    char userAnswer;
    cout << "\nQuestion for " << prize << " INR:\n";
    cout << question << "\n" << options << "\n";

    cout << "Would you like to use a lifeline? (Y/N): ";
    cin >> useLifeline;
    if (useLifeline == 'Y' || useLifeline == 'y') {
        useLifelines();
    }

    cout << "Enter your answer: ";
    cin >> userAnswer;

    if (tolower(userAnswer) == tolower(correctAnswer)) {
        totalEarnings += prize;
        cout << "\nCorrect Answer! You have won " << prize << " INR.\n";
        cout << "Total Earnings: " << totalEarnings << " INR\n";
    } else {
        cout << "\nWrong Answer! Game Over.\n";
        cout << "Total Earnings: " << totalEarnings << " INR\n";
        exit(0);
    }
}

int main() {
    QuizShow game;
    int totalEarnings = 0;

    game.displayRules();

    game.askQuestion("When did India gain independence?",
                     "A) 1947  B) 1946\nC) 1943  D) 1945", 
                     'A', 1000, totalEarnings);
                     
    game.askQuestion("Which is a major tribal group in Bihar?",
                     "A) Santhals  B) Todas\nC) Bhils  D) Lepchas",
                     'A', 2000, totalEarnings);

    game.askQuestion("Which organization does not belong to the UN?",
                     "A) ASEAN  B) ILO\nC) WHO  D) FAO",
                     'A', 5000, totalEarnings);

    game.askQuestion("When was the Battle of Plassey fought?",
                     "A) 1757  B) 1775\nC) 1564  D) 1671",
                     'A', 10000, totalEarnings);

    game.askQuestion("The wife of which famous sports person was captain of the Indian volleyball team?",
                     "A) Milkha Singh  B) Prakash Padukone\nC) Dhyan Chand  D) K.D. Jadav",
                     'A', 20000, totalEarnings);

    game.askQuestion("Which branch of science deals with tumors?",
                     "A) Oncology  B) Serology\nC) Chromology  D) Urology",
                     'A', 50000, totalEarnings);

    game.askQuestion("What is the currency of Yugoslavia?",
                     "A) Pound  B) Peso\nC) Dinar  D) Lira",
                     'C', 100000, totalEarnings);

    cout << "\nCongratulations! You have completed the game with total earnings of " << totalEarnings << " INR.\n";
    return 0;
}
