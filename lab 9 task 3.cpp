#include<iostream>
using namespace std;

class Node
{
public:

    int PlayerID;
    int Score;

    Node* next;

    Node(int id, int score)
    {
        PlayerID = id;
        Score = score;

        next = NULL;
    }
};

class Game
{
public:

    Node* head;
    Node* current;

    Game()
    {
        head = NULL;
        current = NULL;
    }

    void addPlayer(int id, int score)
    {
        Node* newNode = new Node(id, score);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            current = head;
        }

        else
        {
            Node* temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }

        cout << "Player Added : " << id << endl;
    }

    void removePlayer(int id)
    {
        if (head == NULL)
        {
            cout << "No Players in Game" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        if (head->PlayerID == id)
        {
            if (head->next == head)
            {
                cout << "Player " << head->PlayerID << " Removed" << endl;

                delete head;
                head = NULL;
                current = NULL;

                return;
            }

            Node* last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            head = head->next;
            last->next = head;

            cout << "Player " << temp->PlayerID << " Removed" << endl;

            delete temp;
            current = head;

            return;
        }

        do
        {
            prev = temp;
            temp = temp->next;

        } while (temp != head && temp->PlayerID != id);

        if (temp == head)
        {
            cout << "Player Not Found" << endl;
            return;
        }

        prev->next = temp->next;

        if (current == temp)
        {
            current = temp->next;
        }

        cout << "Player " << temp->PlayerID << " Removed" << endl;

        delete temp;
    }

    void nextTurn()
    {
        if (current == NULL)
        {
            cout << "Game Over" << endl;
            return;
        }

        cout << "Player " << current->PlayerID << " Turn" << endl;

        current = current->next;
    }

    void skipPlayer()
    {
        if (current == NULL)
        {
            cout << "Game Over" << endl;
            return;
        }

        cout << "Player " << current->PlayerID << " Skipped" << endl;

        current = current->next;

        cout << "Now Player " << current->PlayerID << " Turn" << endl;

        current = current->next;
    }

    void displayPlayers()
    {
        if (head == NULL)
        {
            cout << "No Players" << endl;
            return;
        }

        Node* temp = head;

        cout << "\nPlayers List" << endl;

        do
        {
            cout << "Player ID : " << temp->PlayerID << endl;
            cout << "Score : " << temp->Score << endl;
            cout << endl;

            temp = temp->next;

        } while (temp != head);
    }

    void checkWinner()
    {
        if (head != NULL && head->next == head)
        {
            cout << "Winner is Player " << head->PlayerID << endl;
        }
    }
};

int main()
{
    Game g;

    g.addPlayer(1, 100);
    g.addPlayer(2, 80);
    g.addPlayer(3, 60);
    g.addPlayer(4, 40);

    g.displayPlayers();

    cout << endl;

    g.nextTurn();
    g.nextTurn();

    cout << endl;

    g.skipPlayer();

    cout << endl;

    g.removePlayer(3);

    g.displayPlayers();

    cout << endl;

    g.removePlayer(2);
    g.removePlayer(4);

    g.displayPlayers();

    cout << endl;

    g.checkWinner();

    return 0;
}