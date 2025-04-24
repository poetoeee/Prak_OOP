#include "Playback.hpp"

using namespace std;

void Playback::addToQueue(const Song &song){
    playbackQueue.push(song);
}

void Playback::addToQueue(const Playlist &playlist){
    for (const Song &song:playlist.getSongs()) {
        playbackQueue.push(song);
    }
}

void Playback::next(){
    if (!playbackQueue.empty()){
        cout << "Memutar: " << playbackQueue.front() << endl;
        playbackQueue.pop();
    } else{
        cout << "Antrian kosong" << endl;
    }
}

void Playback::playAll(){
    while (!playbackQueue.empty()){
        cout << "Memutar: " << playbackQueue.front() << endl;
        playbackQueue.pop();
    }
}

void Playback::skip(){
    if (!playbackQueue.empty()){
        playbackQueue.pop();
    } else{
        cout << "Antrian kosong" << endl;
    }
}

void Playback::clearQueue(){
    while (!playbackQueue.empty()) {
        playbackQueue.pop();
    }
}

bool Playback::isEmpty() const{
    return playbackQueue.empty();
}

size_t Playback::queueSize() const{
    return playbackQueue.size();
}