#include "Playlist.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Playlist::Playlist(string playlistName){
    name = playlistName;
}

const string& Playlist::getName() const{
    return name;
}

const vector<Song>& Playlist::getSongs() const{
    return songs;
}

void Playlist::addSong(const Song &song){
    auto x = find(songs.begin(), songs.end(), song);
    if (x == songs.end()) {
        songs.push_back(song);
    }
}

bool Playlist::removeSong(const Song &songToRemove){
    for (auto x = songs.begin(); x != songs.end(); ++x) {
        if (*x == songToRemove) {
            songs.erase(x);
            return true;
        }
    }return false;
}

void Playlist::removeSongByIndex(size_t index){
    if(index < songs.size()){
        songs.erase(songs.begin() + index);
    }
    else{
        throw out_of_range("Index out of range");
    }
}

size_t Playlist::numberOfSongs() const{
    return songs.size();
}

ostream &operator<<(ostream &os, const Playlist &playlist){
    os << "Playlist: " << playlist.name << " (" << playlist.numberOfSongs() << " lagu)" << endl;
    int cnt = 0;
    for (auto song : playlist.songs) {
        cnt++;
        os << cnt << ". " << song << endl;
    }
    return os;
}

// int main(){
//     Playlist playlist("Playlist oop");
//     playlist.addSong(Song("satu", "artist"));
//     playlist.addSong(Song("dua", "artistt"));
//     playlist.addSong(Song("tiga", "artisttt"));
//     playlist.removeSongByIndex(1);
//     cout << playlist <<endl;
//     return 0;
// }