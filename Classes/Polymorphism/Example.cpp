#include <iostream>
#include <string>
class Entity{
  public:
    std::string getName(){ return name_; }
    void setName(std::string n) { name_ = n; }
  private:
    std::string name_;
};

class Soldier : public Entity {
  public:
    std::string getWeapon() { return weaponName_; }
    void setWeapon(std::string w) { weaponName_ = w; }
  private:
    std::string weaponName_;
};
class Medic : public Entity{
  //
};


int main() {
  // both Entity and Soldier have access to the setName and getName functions
  Entity* person = new Soldier();
  person->setName("Jinx");
  // now 
  return 0;
}
