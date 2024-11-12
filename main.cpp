#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
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
        /* test of getting a vector Student to print. Did not work or compile.
        Student printStudent(Student &student){
            Student s = student;
            cout<<s<<endl;
        }*/
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
    
    
    return 0;
}