#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

class Student{
  public:
    std::string name(){ return name_; }
    int score() { return score_; }
    void setName(std::string n) { name_ = n; }
    void setScore(size_t s){ score_ = s; }
    void addToRaw(int i) { raw.push_back(i); }
    int sumRaw() { return std::accumulate(raw.begin(), raw.end(), 0); }
    // void caseLoop();
  private:
    std::string name_;
    int score_;
    std::vector<int> raw;
};

int main() {
  std::vector<Student> st;
  std::string line, line2;
  std::fstream source("text_file");
  if(!source.is_open()){ std::cerr << "cannot open file" << std::endl; exit(1); }
  std::string firstname_, lastname_, fullname_;
  int score_;
  int tmp;
  while(std::getline(source, line, ',')){
    score_=0;
    Student student;
    std::stringstream ss(line); // >> score2 >> score3 >> score4 >> score5 >> score6
    while(ss >> firstname_ >> lastname_){
      fullname_ = firstname_ + " " + lastname_;
      student.setName(fullname_);
    }
    // std::stringstream scorestream(line);
    std::getline(ss, line2);
    for(auto e : line2){
      if(isdigit(e)){ score_+=e; }
    }
    std::cout << line2 << std::endl;
    // while(scorestream >> tmp){
    //   student.addToRaw(score_);
    //   score_+=tmp;
    // }
    // std::cout << student.sumRaw() << std::endl;
    // student.setScore(student.sumRaw());
    student.setScore(score_);
    st.push_back(student);
    // scorestream.clear();
    // std::cout << student.score() << std::endl;
    // std::cout << line << std::endl;
  }
  // for(auto s : st){
  //   std::cout << s.name() << std::endl;
  //   std::cout << s.score() << std::endl;
  // }

  // char selection = '\0';
  // do{
  //   std::cout << "Select either A or Q: ";
  //   std::cin  >> selection;
  //   switch(selection){
  //     case 'A':
  //       std::cout << "A" << std::endl;
  //       break;;
  //     case 'Q':
  //       break;;
  //     default:
  //       std::cerr << "Invailid" << std::endl;
  //       break;;
  //   }
  // } while (selection != 'Q');
  source.close();
  return 0;
}
