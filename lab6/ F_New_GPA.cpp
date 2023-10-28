#include "iostream"
#include "map"
#include "vector"
#include "iomanip"

using namespace std;

struct Student{
    double  gpa;
    string name;
    string  surname;
};

bool compare(Student s1, Student s2){
    if(s1.gpa == s2.gpa){
        if(s1.surname == s2.surname){
            return s1.name < s2.name;
        }
        return s1.surname < s2.surname;
    }
    return s1.gpa < s2.gpa;
}

int partition(vector<Student> &v, int low, int high){
    Student pivot = v[high];
    int i = low-1;
    for (int j = low; j < high; ++j) {
        if(compare(v[j] , pivot)){
            i++;
            swap(v[i] , v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return i+1;
}

void quickSort(vector <Student> &st,int low, int high){
    if(low < high){
        int pi = partition(st,low, high);
        quickSort(st,low,pi - 1);
        quickSort(st,pi+1,high);
    }
}

int main(){
    int n; cin>>n;
    vector<Student> v(n);
    map<string, double> mp ={
            {"A+", 4.00},
            {"A", 3.75},
            {"B+", 3.50},
            {"B", 3.00},
            {"C+", 2.50},
            {"C", 2.00},
            {"D+", 1.50},
            {"D", 1.00},
            {"F", 0}
    };
    // mp["A+"] = 4.0;
    // mp["A"] = 3.75;

    for (auto &student: v ) {
        cin>>student.surname>>student.name;
        double sum1 =0, sum2 =0;
        int m; cin>>m;
        while( m--){
            string mark; int credits;
            cin>>mark>>credits;
            sum1 += mp[mark] * credits;
            sum2 += credits;
        }

        student.gpa = sum1/ sum2;
    }

    quickSort(v,0,v.size() - 1);
    for (auto i: v) {
        cout<<i.surname<<" "<<i.name<<" " <<fixed << setprecision(3)<<i.gpa<<endl;
    }

}