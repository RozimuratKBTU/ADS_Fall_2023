#include <bits/stdc++.h>
using namespace std;

struct Student{
    double gpa;
    string name;
    string surname;
};

bool cmp(Student student1, Student student2){
    if(student1.gpa == student2.gpa){
        if(student1.surname == student2.surname){
            return student1.name < student2.name;
        }
        return student1.surname < student2.surname;
    }
    return student1.gpa < student2.gpa;
}


void merge(vector <Student> &v, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;
    vector <Student> L(n1);
    vector <Student> M(n2);

    for (int i = 0; i < n1; i++)
        L[i] = v[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = v[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (cmp(L[i], M[j])) {
            v[k++] = L[i++];
        } else {
            v[k++] = M[j++];
        }
    }

    while (i < n1) {
        v[k++] = L[i++];
    }

    while (j < n2) {
        v[k++] = M[j++];
    }
}

void mergeSort(vector <Student> &v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main(){
    int n; cin >> n;
    vector<Student> st(n);
    map<string, double> mp =  {
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
    for(auto &student : st){
        cin >> student.surname >> student.name;
        int m; cin >> m;
        double sum = 0, sum1 = 0;
        while(m--){
            string mark; int credits;
            cin >> mark >> credits;
            sum += mp[mark] * credits;
            sum1 += credits;
        }
        student.gpa = sum/sum1;
    }
    mergeSort(st, 0, st.size()-1);
    for(auto i : st){
        cout << i.surname << " " << i.name << " " << fixed << setprecision(3) << i.gpa << endl;
    }
}