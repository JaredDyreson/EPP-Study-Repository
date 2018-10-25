#include <iostream>
#include <queue>
#include <string>

struct Song{
  Song(std::string s, std::string a) : song(s), artist(a){}
  std::string song, artist;
  friend std::ostream& operator<<(std::ostream& os, Song &song){
    std::cout << song.song << std::endl;
    std::cout << song.artist << std::endl;
    return os;
  }
};

int main(){
    std::queue<Song> spotifyUpNext;
    Song songOne("Under Again", "Bullet for my Valentine");
    Song songTwo("Out of Time", "A Day to Remember");
    spotifyUpNext.push(songOne);
    spotifyUpNext.push(songTwo);
    std::cout << spotifyUpNext.size() << std::endl;
    for(size_t i = 0; i <= spotifyUpNext.size(); i++){ 
      std::cout << "Now Playing: " << std::endl;
      std::cout << spotifyUpNext.front() << std::endl;
      std::cout << std::endl;
      spotifyUpNext.pop();
    }
    return 0;
}
