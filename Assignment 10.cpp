#include <iostream>
#include <string>
using namespace std;

class Track
{
private:
    string title,artist,album,genre,releaseDate;
    Track *next;
    Track *previous;

public:
    Track(string t, string a, string al, string g, string r)
        : title(t), artist(a), album(al), genre(g), releaseDate(r), next(nullptr), previous(nullptr) {}

    friend class MusicLibrary;
};

class MusicLibrary
{
private:
    Track *head;

public:
    MusicLibrary() : head(nullptr) {}

    ~MusicLibrary()
    {
        while (head)
        {
            Track *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addTrack()
    {
        string title, artist, album, genre, releaseDate;
        cout << "Enter track title: ";
        cin >> title;
        cout << "Enter artist: ";
        cin >> artist;
        cout << "Enter album: ";
        cin >> album;
        cout << "Enter genre: ";
        cin >> genre;
        cout << "Enter release date: ";
        cin >> releaseDate;

        Track *newTrack = new Track(title, artist, album, genre, releaseDate);

        if (!head)
        {
            head = newTrack;
        }
        else
        {
            Track *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newTrack;
            newTrack->previous = temp;
        }
        cout << "Track added successfully.\n";
    }

    void updateTrack(const string &title)
    {
        if (!head)
        {
            cout << "No tracks in the library.\n";
            return;
        }

        Track *current = head;
        while (current)
        {
            if (current->title == title)
            {
                cout << "Enter new artist: ";
                cin >> current->artist;
                cout << "Enter new album: ";
                cin >> current->album;
                cout << "Enter new genre: ";
                cin >> current->genre;
                cout << "Enter new release date: ";
                cin >> current->releaseDate;
                cout << "Track updated successfully.\n";
                return;
            }
            current = current->next;
        }
        cout << "Track not found.\n";
    }

    void deleteTrack(const string &title)
    {
        if (!head)
        {
            cout << "No tracks in the library.\n";
            return;
        }

        Track *current = head;
        while (current)
        {
            if (current->title == title)
            {
                if (current == head) // Deleting the head track
                {
                    head = head->next;
                    if (head)
                    {
                        head->previous = nullptr;
                    }
                }
                else
                {
                    current->previous->next = current->next;
                    if (current->next)
                    {
                        current->next->previous = current->previous;
                    }
                }
                delete current;
                cout << "Track deleted successfully.\n";
                return;
            }
            current = current->next;
        }
        cout << "Track not found.\n";
    }

    void displayTracks() const
    {
        if (!head)
        {
            cout << "No tracks in the library.\n";
            return;
        }
        Track *current = head;
        while (current)
        {
            cout << "Title: " << current->title << ", Artist: " << current->artist
                 << ", Album: " << current->album << ", Genre: " << current->genre
                 << ", Release Date: " << current->releaseDate << endl;
            current = current->next;
        }
    }
};

int main()
{
    MusicLibrary library;
    int choice;
    string title;

    do
    {
        cout << "1. Add Track\n2. Update Track\n3. Delete Track\n4. Display Tracks\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            library.addTrack();
            break;
        case 2:
            cout << "Enter title to update: ";
            cin >> title;
            library.updateTrack(title);
            break;
        case 3:
            cout << "Enter title to delete: ";
            cin >> title;
            library.deleteTrack(title);
            break;
        case 4:
            library.displayTracks();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
