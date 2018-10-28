// it is a bit broken but the main concept is there
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
      // while(std::getline(stream, line, ',')){
      //   std::istringstream ss(line);
      //   std::string firstname_, lastname_, fullname_;
      //   int score1,score2, score3, score4, score5, score6;
      //   int score_ = 0;
      //   while(ss >> firstname_ >> lastname_){
      //     fullname_ = firstname_ + " " + lastname_;
      //     for(int i =0 ; i < 5; ++i){
      //       std::cout << line << std::endl;
      //       // while(scores >> tmp1 >> tmp2){ std::cout << tmp1 << " " << tmp2; }
      //     }
      //     //   while(scores >> score_){
      //     //    std::cout << score_ << sd
      //     //   }
      //     }
      //     Student student(fullname_, score_);
      //     student.setGrade(student.calculateLetterGrade(score_));
      //     fucking->push_back(student);
      //   }
      std::string firstname_, lastname_, fullname_;
      while(std::getline(stream, line, ',')) {
        int score_keeper_ = 0;
        Student student;
        std::istringstream ss(line);
        // std::cout << line  << std::endl;
        // std::getline(stream, line2, ',');
        while(ss >> firstname_ >> lastname_){
          fullname_ = firstname_ + lastname_;
          student.setName(fullname_);
        }
        std::istringstream sl(line);
        // std::getline(sl, line);
        // int score_ = std::stoi(line);
        int score_;
        sl >> score_;
        score_keeper_ = student.score();
        student.setScore(score_keeper_+score_);
        // std::cout << score_keeper_ << std::endl;
        // std::cout  << score_keeper_ << std::endl;
        // for(int i = 0; i < 6; ++i){
        //   std::getline(stream, line2);
        //   std::cout << line2  << std::endl;
        // }
        // while(std::getline(ss, line2)){
        //   std::cout << line2   << "marked" << std::endl;
        // }
        // std::cout << line2 << std::endl;
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
  auto e = s.loadVector();
  for(auto student : e){
    std::cout << student.score() << std::endl;
  }
  // std::cout << student[0].name() << std::endl;
  // for(size_t i = 0; i < 23; ++i){
  //   std::cout << student[i].name() << std::endl;
  // }
  return 0;
}
