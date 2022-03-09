#include <iostream>
#include <sstream>
using namespace std;

class Student {
    private:
        int age = -1, standard = -1;
        string first_name = "", last_name = "";
    public:
        void set_age(const int& in) {
            this->age = in;
        }
        void set_standard(const int& in) {
            this->standard = in;
        }
        void set_first_name(const string& in) {
            this->first_name = in;
        }
        void set_last_name(const string& in) {
            this->last_name = in;
        }
        int get_age() {
            return this->age;
        }
        string get_last_name() {
            return this->last_name;
        }
        string get_first_name() {
            return this->first_name;
        }
        int get_standard() {
            return this->standard;
        }
        string to_string() {
            cout << this->get_age() << "," << this->get_first_name() << "," << this->get_last_name() << "," << this->get_standard();
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    st.to_string();
    
    return 0;
}
