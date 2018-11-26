// it is a bit broken but the main concept is there
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

class Student{
  public:
    Student(std::string name, size_t score) : name_(name), score_(score), grade_('\0'){}
    Student(){}
    std::string name() { return name_; }
    size_t score() { return score_; }
    char grade() { return grade_; }

    void setName(const std::string n) { name_ = n; }
    void setScore(size_t s) { score_ = s; }
    void setGrade(char g) { grade_ = g; }
    std::vector<Student> loadVector(){
      std::vector<Student>* fucking = new std::vector<Student>;
      std::string line, line2;
      std::fstream stream("text_file");
      int score_ = 0;
      int tmp_ = 0, tmp_2 = 0;
      while(std::getline(stream, line)){
        // line.erase(std::remove(line.begin(), line.end(), ','), line.end());
        auto position = line.find_first_not_of(',');
        // std::cout << position+1 << std::endl;
        if(position != std::string::npos){ line.erase(position); }
        std::cout << line << std::endl;
        std::string firstname_, lastname_, fullname_;
        std::istringstream ss(line);
        while(ss >> firstname_ >> lastname_){
          fullname_ = firstname_ + " " + lastname_;
          // std::cout << fullname_ << std::endl;
        }
        std::cout << "clearing buffer.." << std::endl;
        ss.clear();
        ss.seekg(0, std::ios::beg);
        while(ss >> tmp_ >> tmp_2){

          score_+=tmp_;
          std::cout << tmp_  << "marker" << std::endl;
        }
        std::cout << "Score: " << score_ << std::endl;
        // score_=0;
        // tmp_=0;

      }
        return *fucking;
    }
    char calculateLetterGrade(size_t score){
      char grade;
      if (score == 100 && score < 100 && score >= 90){
        grade = 'A';
      }
      else if (score <= 89 && score >= 80){
        grade = 'B';
      }
      else if (score <= 79 && score >= 70){
        grade = 'C';
      }
      else if (score <= 69 && score >= 60){
        grade = 'D';
      }
      else {
        grade = 'F';
      }
      return grade;
    }
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
  Student s;
  s.loadVector();
  // auto e =
  // for(auto student : e){
  //   std::cout << student.score() << std::endl;
  // }
  // std::cout << student[0].name() << std::endl;
  // for(size_t i = 0; i < 23; ++i){
  //   std::cout << student[i].name() << std::endl;
  // }
  return 0;
}
