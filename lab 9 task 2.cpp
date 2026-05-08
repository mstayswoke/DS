#include<iostream>
using namespace std;

class Node
{
public:

    int SongID;
    string SongName;
    float Duration;

    Node* next;
    Node* prev;

    Node(int id, string name, float dur)
    {
        SongID = id;
        SongName = name;
        Duration = dur;

        next = NULL;
        prev = NULL;
    }
};

class Playlist
{
public:

    Node* head;
    Node* current;

    Playlist()
    {
        head = NULL;
        current = NULL;
    }

    void addSong(int id, string name, float dur)
    {
        Node* newNode = new Node(id, name, dur);

        if (head == NULL)
        {
            head = newNode;
            current = head;
        }

        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteSong(string name)
    {
        if (head == NULL)
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->SongName != name)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Song not found" << endl;
            return;
        }

        if (temp == head)
        {
            head = head->next;

            if (head != NULL)
            {
                head->prev = NULL;
            }

            delete temp;
            current = head;
        }

        else
        {
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }

            temp->prev->next = temp->next;

            delete temp;
        }
    }

    void playNext()
    {
        if (current == NULL)
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        if (current->next == NULL)
        {
            cout << "No Next Song" << endl;
            return;
        }

        current = current->next;

        cout << "Playing Next : " << current->SongName << endl;
    }

    void playPrevious()
    {
        if (current == NULL)
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        if (current->prev == NULL)
        {
            cout << "No Previous Song" << endl;
            return;
        }

        current = current->prev;

        cout << "Playing Previous : " << current->SongName << endl;
    }

    void reversePlaylist()
    {
        Node* temp = NULL;
        Node* curr = head;

        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        if (temp != NULL)
        {
            head = temp->prev;
        }

        cout << "Playlist Reversed" << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        Node* temp = head;

        cout << "\nPlaylist Songs" << endl;

        while (temp != NULL)
        {
            cout << "ID : " << temp->SongID << endl;
            cout << "Name : " << temp->SongName << endl;
            cout << "Duration : " << temp->Duration << " mins" << endl;
            cout << endl;

            temp = temp->next;
        }
    }
};

int main()
{
    Playlist p;

    p.addSong(1, "Shape of You", 4.2);
    p.addSong(2, "Believer", 3.5);
    p.addSong(3, "Perfect", 4.0);

    p.display();

    cout << endl;

    p.playNext();
    p.playNext();
    p.playPrevious();

    cout << endl;

    p.deleteSong("Believer");

    cout << "After Deleting Song" << endl;

    p.display();

    cout << endl;

    p.reversePlaylist();

    p.display();

    return 0;
}