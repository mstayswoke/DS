#include <iostream>
using namespace std;

struct PlayerNode {
    int playerID;
    int score;
    PlayerNode* next;
};

class GameSystem {
private:
    PlayerNode* current;
    int playerCount;

public:
    GameSystem() {
        current = NULL;
        playerCount = 0;
    }

    void addPlayer(int id) {
        PlayerNode* newPlayer = new PlayerNode();
        newPlayer->playerID = id;
        newPlayer->score = 0;

        if (current == NULL) {
            newPlayer->next = newPlayer;
            current = newPlayer;
        }
        else {
            newPlayer->next = current->next;
            current->next = newPlayer;
        }

        playerCount++;
        cout << "Player " << id << " joined the game" << endl;
    }

    void removePlayer(int id) {
        if (current == NULL) {
            cout << "No players in game" << endl;
            return;
        }

        if (playerCount == 1 && current->playerID == id) {
            delete current;
            current = NULL;
            playerCount--;
            cout << "Player " << id << " left the game" << endl;
            return;
        }

        PlayerNode* temp = current;
        PlayerNode* prev = NULL;

        do {
            prev = temp;
            temp = temp->next;
        } while (temp != current && temp->playerID != id);

        if (temp->playerID != id) {
            cout << "Player not found" << endl;
            return;
        }

        if (temp == current) {
            current = current->next;
        }

        prev->next = temp->next;
        delete temp;
        playerCount--;
        cout << "Player " << id << " left the game" << endl;

        if (playerCount == 1) {
            cout << "\nGAME OVER! Player " << current->playerID << " wins!" << endl;
        }
    }

    void nextTurn() {
        if (current == NULL) {
            cout << "No players in game" << endl;
            return;
        }

        current = current->next;
        cout << "Player " << current->playerID << "'s turn (Score: " << current->score << ")" << endl;
    }

    void skipPlayer() {
        if (current == NULL) {
            cout << "No players in game" << endl;
            return;
        }

        if (playerCount < 2) {
            cout << "Need more players to skip" << endl;
            return;
        }

        current = current->next->next;
        cout << "Player " << current->playerID << "'s turn (Score: " << current->score << ")" << endl;
    }

    void updateScore(int points) {
        if (current != NULL) {
            current->score += points;
            cout << "Player " << current->playerID << " score: " << current->score << endl;
        }
    }

    void displayPlayers() {
        if (current == NULL) {
            cout << "No players in game" << endl;
            return;
        }

        cout << "\nPlayers in game:" << endl;
        PlayerNode* temp = current;

        do {
            cout << "Player " << temp->playerID << " - Score: " << temp->score;
            if (temp == current) {
                cout << " << CURRENT TURN";
            }
            cout << endl;
            temp = temp->next;
        } while (temp != current);

        cout << "Total players: " << playerCount << endl;
    }

    int getPlayerCount() {
        return playerCount;
    }
};

int main() {
    GameSystem game;

    game.addPlayer(1);
    game.addPlayer(2);
    game.addPlayer(3);
    game.addPlayer(4);
    game.displayPlayers();

    cout << "\n GAME STARTS " << endl;
    game.nextTurn();
    game.updateScore(10);

    game.nextTurn();
    game.updateScore(15);

    game.nextTurn();
    game.updateScore(20);

    cout << "\n SKIPPING TURN " << endl;
    game.skipPlayer();

    cout << "\n PLAYER LEAVES " << endl;
    game.removePlayer(2);
    game.displayPlayers();

    game.nextTurn();
    game.nextTurn();

    cout << "\n MORE PLAYERS LEAVE " << endl;
    game.removePlayer(3);
    game.removePlayer(4);

    return 0;
}