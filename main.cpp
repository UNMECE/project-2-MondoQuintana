#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <functional>
using namespace std;

class Student{
    private:
        string first_name;
        string last_name;
        double gpa;
        int grad_year;
        string grad_semester;
        int enrolled_year;
        string enrolled_semester;
        bool graduate;
    public:
        Student(){
            this->first_name="FNAME";
            this->last_name="LNAME";
            this->gpa=0.00;
            this->grad_year=9999;
            this->grad_semester="Spring";
            this->enrolled_year=9999;
            this->enrolled_semester="Fall";
            this->graduate=false;
        }
        Student(string FNAME, string LNAME, double GPA, int GRADYEAR, string GRADSEMESTER, int ENROLLEDYEAR, string ENROLLEDSEMESTER, bool IsGraduate){
            this->first_name=FNAME;
            this->last_name=LNAME;
            this->gpa=GPA;
            this->grad_year=GRADYEAR;
            this->grad_semester=GRADSEMESTER;
            this->enrolled_year=ENROLLEDYEAR;
            this->enrolled_semester=ENROLLEDSEMESTER;
            this->graduate=IsGraduate;
        }
        Student(Student &student){
            this->first_name=student.getFirstName();
            this->last_name=student.getLastName();
            this->gpa=student.getGPA();
            this->grad_year=student.getGradYear();
            this->grad_semester=student.getGradSemester();
            this->enrolled_year=student.getEnrolledYear();
            this->enrolled_semester=student.getEnrolledSemester();
            bool isGraduate;
            if (student.getIsGraduate()=="Yes"){
                isGraduate=true;
            }
            else{
                isGraduate=false;
            };
            this->graduate=isGraduate;
        }
        void setFirstName(string FNAME){
            this->first_name=FNAME;
        }
        string getFirstName(){
            return first_name;
        }
        void setLasttName(string LNAME){
            this->last_name=LNAME;
        }
        string getLastName(){
            return last_name;
        }
        void setGPA(double GPA){
            this->gpa=GPA;
        }
        double getGPA(){
            return gpa;
        }
        void setGradYear(int GRADYEAR){
            this->grad_year=GRADYEAR;
        }
        int getGradYear(){
            return grad_year;
        }
        void setGradSemester(string GRADSEMESTER){
            this->grad_semester=GRADSEMESTER;
        }
        string getGradSemester(){
            return grad_semester;
        }
        void setEnrolledYear(int ENROLLEDYEAR){
            this->enrolled_year=ENROLLEDYEAR;
        }
        int getEnrolledYear(){
            return enrolled_year;
        }
        void setEnrolledSemester(string ENROLLEDSEMESTER){
            this->enrolled_semester=ENROLLEDSEMESTER;
        }
        string getEnrolledSemester(){
            return enrolled_semester;
        }
        void setIsGraduate(bool IsGraduate){
            this->graduate=IsGraduate;
        }
        string getIsGraduate(){
            if (graduate==false)
            {
                return "No";
            }
            else
            {
                return "Yes";
            }
            
        }
        ~Student(){};
};

ostream &operator<<(ostream &os, Student &student){
    os<<"Student "<<student.getFirstName()<<" "<<student.getLastName()<<endl<<"GPA: "<<student.getGPA()<<endl<<"Graduation Year: "<<student.getGradYear()<<endl
    <<"Graduation Semester: "<<student.getGradSemester()<<endl<<"Enrolled Year: "<<student.getEnrolledYear()<<endl<<"Enrolled Semester: "<<student.getEnrolledSemester()<<endl<<"Graduate: "<<student.getIsGraduate()<<endl;
    return os;
};

class Art_Student:public Student{
    private:
        string art_emphasis;
    public:
        Art_Student():Student(){
            art_emphasis="None";
        };
        void setArtEmphasis(int ARTEMPHASIS){
            if (0<ARTEMPHASIS<4)
            {
                string a = "Art Studio";
                string b = "Art History";
                string c = "Art Education";
                if (ARTEMPHASIS==1)
                {
                    this->art_emphasis=a;
                }
                else if (ARTEMPHASIS==2)
                {
                    this->art_emphasis=b;
                }
                else if (ARTEMPHASIS==3)
                {
                    this->art_emphasis=c;
                }
            }
            else{
                cout<<"No Change. Invalid Selection."<<endl;
            }  
        }
        string getArtEmphasis(){
            return art_emphasis;
        }
        ~Art_Student(){};
};

class Physics_Student:public Student{
    private:
        string concentration;
    public:
        Physics_Student():Student(){
            concentration="None";
        };
        void setConcentration(int CONCENTRATION){
            if (0<CONCENTRATION<3)
            {
                string a = "Biophysics";
                string b = "Earth and Planetary Sciences";
                if (CONCENTRATION==1)
                {
                    this->concentration=a;
                }
                else
                {
                    this->concentration=b;
                }
            }
            else{
                cout<<"No Change. Invalid Selection."<<endl;
            }  
        }
        string getConcentration(){
            return concentration;
        }
        ~Physics_Student(){};
};

int main(){
    /*
    Art_Student a;
    cout<<a<<endl;

    vector<Art_Student*> art_students;
    art_students.push_back(new Art_Student);
    cout<<*art_students[0]<<endl;
    */
    srand(time(0));
    uniform_real_distribution<double> zero_to_six(0,6);
    default_random_engine re(time(0));
    auto gpa_set = bind(zero_to_six,re);
    vector <Art_Student*> art_students;
    vector <Physics_Student*> physics_students;
    for (int i = 0; i < 5; i++)
    {
        art_students.push_back(new Art_Student);
        physics_students.push_back(new Physics_Student);
    }
    for (int i = 0; i < art_students.size(); i++)
    {
        double gpa = gpa_set();//(rand()%500)/100.00;
        art_students[i]->setGPA(gpa);
        physics_students[i]->setGPA(gpa);
        int gradyear = 2025 + rand()%10;
        art_students[i]->setGradYear(gradyear);
        physics_students[i]->setGradYear(gradyear);
        int enrolledyear = 2000 + rand()%20;
        art_students[i]->setEnrolledYear(enrolledyear);
        physics_students[i]->setEnrolledYear(enrolledyear);
        int artemp = 1 + rand()%3;
        art_students[i]->setArtEmphasis(artemp);
        int con = 1 + rand()%2;
        physics_students[i]->setConcentration(con);
    }
    std::ofstream outfile("Students.txt");
    for (int i = 0; i < art_students.size(); i++)
    {
        outfile <<"Student "<<i+1<<endl<<*art_students[i];/*<<"Student "<<art_students[i]->getFirstName()<<i+1<<" "<<art_students[i]->getLastName()<<endl
                <<"Art Emphasis: "<<art_students[i]->getArtEmphasis()<<endl
                <<"GPA: "<<art_students[i]->getGPA()<<endl
                <<"Graduation Year: "<<art_students[i]->getGradYear()<<endl
                <<"Graduation Semester: "<<art_students[i]->getGradSemester()<<endl
                <<"Enrolled: "<<art_students[i]->getEnrolledSemester()<<" "<<art_students[i]->getEnrolledYear()<<endl
                <<"Graduate: "<<art_students[i]->getIsGraduate()<<endl;*/
    }
    for (int i = 0; i < physics_students.size(); i++)
    {
        outfile <<"Student "<<i+1<<endl<<*physics_students[i];/*<<"Student "<<physics_students[i]->getFirstName()<<i+1<<" "<<physics_students[i]->getLastName()<<endl
                <<"Art Emphasis: "<<physics_students[i]->getConcentration()<<endl
                <<"GPA: "<<physics_students[i]->getGPA()<<endl
                <<"Graduation Year: "<<physics_students[i]->getGradYear()<<endl
                <<"Graduation Semester: "<<physics_students[i]->getGradSemester()<<endl
                <<"Enrolled: "<<physics_students[i]->getEnrolledSemester()<<" "<<physics_students[i]->getEnrolledYear()<<endl
                <<"Graduate: "<<physics_students[i]->getIsGraduate()<<endl;*/
    }
    
    outfile.close();
    
    
    return 0;
}