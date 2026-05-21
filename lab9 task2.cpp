#include <iostream>
#include <string>
using namespace std;

struct SongNode {
    int songID;
    string songName;
    float duration;
    SongNode* next;
    SongNode* prev;
};

class PlaylistManager {
private:
    SongNode* head;
    SongNode* tail;
    SongNode* currentSong;

public:
    PlaylistManager() {
        head = NULL;
        tail = NULL;
        currentSong = NULL;
    }

    void addSong(int id, string name, float duration) {
        SongNode* newSong = new SongNode();
        newSong->songID = id;
        newSong->songName = name;
        newSong->duration = duration;
        newSong->next = NULL;
        newSong->prev = NULL;

        if (head == NULL) {
            head = newSong;
            tail = newSong;
            currentSong = head;
        }
        else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "Added: " << name << " (" << duration << " mins)" << endl;
    }

    void deleteSong(string name) {
        if (head == NULL) {
            cout << "Playlist is empty" << endl;
            return;
        }

        SongNode* temp = head;
        while (temp != NULL && temp->songName != name) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found" << endl;
            return;
        }

        if (temp == currentSong) {
            if (temp->next != NULL) {
                currentSong = temp->next;
            }
            else {
                currentSong = temp->prev;
            }
        }

        if (temp == head && temp == tail) {
            head = NULL;
            tail = NULL;
            currentSong = NULL;
        }
        else if (temp == head) {
            head = head->next;
            head->prev = NULL;
        }
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Deleted: " << name << endl;
    }

    void playNext() {
        if (currentSong == NULL) {
            cout << "No song playing" << endl;
            return;
        }

        if (currentSong->next != NULL) {
            currentSong = currentSong->next;
            cout << "Now Playing: " << currentSong->songName << endl;
        }
        else {
            cout << "End of playlist" << endl;
        }
    }

    void playPrevious() {
        if (currentSong == NULL) {
            cout << "No song playing" << endl;
            return;
        }

        if (currentSong->prev != NULL) {
            currentSong = currentSong->prev;
            cout << "Now Playing: " << currentSong->songName << endl;
        }
        else {
            cout << "Start of playlist" << endl;
        }
    }

    void shufflePlaylist() {
        if (head == NULL || head->next == NULL) {
            cout << "Need more songs to shuffle" << endl;
            return;
        }

        SongNode* curr = head;
        SongNode* temp = NULL;

        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != NULL) {
            tail = head;
            head = temp->prev;
        }

        cout << "Playlist shuffled" << endl;
    }

    void displayPlaylist() {
        if (head == NULL) {
            cout << "Playlist empty" << endl;
            return;
        }

        SongNode* temp = head;
        while (temp != NULL) {
            cout << "ID:" << temp->songID << " | " << temp->songName << " | " << temp->duration << " mins";
            if (temp == currentSong) {
                cout << " << NOW PLAYING";
            }
            cout << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PlaylistManager myPlaylist;

    myPlaylist.addSong(101, "i like the way u kiss me", 5.55);
    myPlaylist.addSong(102, "superman", 8.02);
    myPlaylist.addSong(103, "Hotel California", 6.30);
    myPlaylist.addSong(104, "espresso", 3.03);
    myPlaylist.displayPlaylist();

    myPlaylist.playNext();
    myPlaylist.playNext();
    myPlaylist.playPrevious();

    myPlaylist.deleteSong("Hotel California");
    myPlaylist.displayPlaylist();

    myPlaylist.shufflePlaylist();
    myPlaylist.displayPlaylist();

    myPlaylist.addSong(105, "Yesterday", 2.05);
    myPlaylist.addSong(106, "Sweet Child O' Mine", 5.56);
    myPlaylist.displayPlaylist();

    return 0;
}