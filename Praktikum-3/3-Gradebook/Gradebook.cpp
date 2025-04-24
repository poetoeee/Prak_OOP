#include "Gradebook.hpp"
#include <map>
#include <vector>

using namespace std;

void Gradebook::addOrUpdateStudent(const string &studentName, double grade){
    auto x = studentGrades.find(studentName);
    if (x != studentGrades.end()) {
        x->second = grade;
    } else {
        studentGrades[studentName] = grade;
    }
}

bool Gradebook::removeStudent(const string &studentName){
    auto x = studentGrades.find(studentName);
    if (x != studentGrades.end()) {
        studentGrades.erase(x);
        return true;
    } else {
        return false;
    }
}

bool Gradebook::getGrade(const string &studentName, double &grade) const{
    auto x = studentGrades.find(studentName);
    if (x != studentGrades.end()) {
        grade = x->second;
        return true;
    } else {
        return false;
    }
}

bool Gradebook::studentExists(const string &studentName) const{
    auto x = studentGrades.find(studentName);
    if (x != studentGrades.end()) {
        return true;
    } else {
        return false;
    }
}

void Gradebook::printGrades() const{
    int cnt = 0;
    for (auto x = studentGrades.begin(); x != studentGrades.end(); x++){
        cnt++;
        cout << cnt << ". " << x->first << ": " << x->second << endl;
    }
}

void Gradebook::printGradesRank() const{
    vector<pair<string, double>> sortedGrades;
    for (auto x = studentGrades.begin(); x != studentGrades.end(); x++){
        sortedGrades.push_back(make_pair(x->first, x->second));
    }
    sort(sortedGrades.begin(), sortedGrades.end(), [](pair<string, double> a, pair<string, double> b){
        return a.second > b.second;
    });
    int cnt = 0;
    for (auto x = sortedGrades.begin(); x != sortedGrades.end(); x++){
        cnt++;
        cout << cnt << ". " << x->first << ": " << x->second << endl;
    }
}

vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const{
    vector<string> result;
    for (auto x = studentGrades.begin(); x != studentGrades.end(); x++){
        if (x->second > threshold) {
            result.push_back(x->first);
        }
    }return result;
}

double Gradebook::getAverageGrade() const{
    double sum = 0.0;
    for (auto x = studentGrades.begin(); x != studentGrades.end(); x++){
        sum += x->second;
    }return sum/studentGrades.size();
}

size_t Gradebook::getNumberOfStudents() const{
    return studentGrades.size();
}

// int main(){
//     Gradebook gradebook;
//     gradebook.addOrUpdateStudent("satu", 85.5);
//     gradebook.addOrUpdateStudent("dua", 92.0);
//     gradebook.addOrUpdateStudent("tiga", 78.0);
//     gradebook.addOrUpdateStudent("empat", 95.0);
//     gradebook.addOrUpdateStudent("lima", 88.0);
//     gradebook.printGradesRank();
//     vector<string> above90 = gradebook.getStudentsWithGradeAbove(90.0);
//     for (string name : above90) {
//         cout << "Above 90: " << name << endl;
//     }
//     cout << "Average: " << gradebook.getAverageGrade() << endl;
//     cout << "Number of students: " << gradebook.getNumberOfStudents() << endl;

//     return 0;
// }