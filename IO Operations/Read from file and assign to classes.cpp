// it is a bit broken but the main concept is there
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Student{
  public:
    Student(std::string name, size_t score, char grade) : name_(name), score_(score), grade_(grade){}
    Student(){}
    std::string name() { return name_; }
    size_t score() { return score_; }
    char grade() { return grade_; }

    void setName(const std::string n) { name_ = n; }
    void setScore(size_t s) { score_ = s; }
    void setGrade(char g) { grade_ = g; }
    friend std::ostream& operator<<(std::ostream& os, const Student& student){
      os << student.name_ << std::endl;
      os << student.score_ << std::endl;
      os << student.grade_ << std::endl;
      return os;
    }
    ~Student(){}
  private:
    std::string name_;
    size_t score_;
    char grade_;
};

int main() {
  Student student[23];
  std::string line;
  std::fstream stream("text_file");
  while(std::getline(stream, line, ',')){
    std::stringstream ss(line);
    std::string name;
    while(ss >> name){ student->setName(name); ss.clear(); }
  }
  // std::cout << student[0].name() << std::endl;
  for(size_t i = 0; i < 23; ++i){
    std::cout << student[i].name() << std::endl;
  }
  return 0;
}
