#include <iostream>
#include <map>
#include <string>
#include <fstream>

struct musicPair{
	musicPair(std::string s, std::string a) : song(s), album(a){}
	std::string song, album;
};


class Artist{
	public:
		std::string name() const { return name_; }
		size_t songCount() const { return songCount_; }
		void setName(std::string n) { name_ = n; }
		void setSongCount(size_t c) { songCount_  = c; }
	private:
		std::string name_;
		size_t songCount_;
};

class ArtistLenCmp {
public:
	ArtistLenCmp() = default;

	// sort by length first, and then alphabetically
	std::string operator() {
		return Artist.name();
	}
	bool operator()(const Artist& a, const std::string& b) const {
		return (a.name().size() < b.size()) || (a.name().size() == b.size() && a.name() < b); }

	private:
		// no data
	};

class Library{
	public:
		size_t getSize() { return size_; }
		void addArtist(Artist a, musicPair& mp){
			if(!findArtist(a.name())){
				collection.insert(std::pair<Artist, musicPair>(a, mp));
				// collection[artist] = mp;
				// collection.insert({artist, mp});

				std::cout << "I CAN FUCKING MODIFY IF I WANT TO" << std::endl;
			}
			// insert(std::pair<const std::string, const musicPair>(artist, mp));
		}
		bool findArtist(std::string name){
			for(auto element : collection){
				if(element.first.name() == name){ return true; }
			}
			return false;
		}
	private:
		size_t size_;
		std::multimap<Artist, musicPair, ArtistLenCmp> collection;
};
int main() {
	Library l;
	Artist a;
	a.setName("Metallica");
	auto b = musicPair(std::string("Ain't my Bitch"), std::string("Load"));
	l.addArtist(a, b);
	return 0;
}
