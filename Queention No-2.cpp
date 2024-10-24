#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

// Node structure for a song
struct Song {
    std::string title;
    Song* next;

    // Constructor to create a new song node
    Song(const std::string& t) : title(t), next(nullptr) {}
};

// Function to add a song to the end of the playlist
void addSong(Song*& head, const std::string& title) {
    Song* newSong = new Song(title);
    if (!head) {
        head = newSong;
    } else {
        Song* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
}

// Function to remove a song by title
void removeSong(Song*& head, const std::string& title) {
    Song* temp = head;
    Song* prev = nullptr;

    while (temp && temp->title != title) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        std::cout << "Song not found: " << title << std::endl;
        return;
    }

    if (!prev) {  // Removing the head node
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    std::cout << "Removed song: " << title << std::endl;
}

// Function to print the playlist
void printPlaylist(Song* head) {
    Song* temp = head;
    std::cout << "Playlist:" << std::endl;
    while (temp) {
        std::cout << "- " << temp->title << std::endl;
        temp = temp->next;
    }
}

// Function to count the number of songs in the playlist
int countSongs(Song* head) {
    int count = 0;
    Song* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to shuffle the playlist
void shufflePlaylist(Song*& head) {
    int n = countSongs(head);
    if (n < 2) return;  // No need to shuffle if less than 2 songs

    // Store all songs in a vector
    std::vector<Song*> songs;
    Song* temp = head;
    while (temp) {
        songs.push_back(temp);
        temp = temp->next;
    }

    // Shuffle the vector using Fisher-Yates algorithm
    srand(time(nullptr));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(songs[i], songs[j]);
    }

    // Rebuild the linked list from the shuffled vector
    head = songs[0];
    for (int i = 0; i < n - 1; ++i) {
        songs[i]->next = songs[i + 1];
    }
    songs[n - 1]->next = nullptr;
}

// Main function to demonstrate playlist operations
int main() {
    Song* playlist = nullptr;

    // Add songs to the playlist
    addSong(playlist, "Song A");
    addSong(playlist, "Song B");
    addSong(playlist, "Song C");
    addSong(playlist, "Song D");

    // Print the playlist
    printPlaylist(playlist);

    // Remove a song from the playlist
    removeSong(playlist, "Song B");
    printPlaylist(playlist);

    // Shuffle the playlist
    shufflePlaylist(playlist);
    printPlaylist(playlist);

    return 0;
}

