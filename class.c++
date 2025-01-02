#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Student{
    private: 
    int id,age;
    string name;
    public:
    Student(int id,string name, int age):
    id(id), name(name), age(age){}
   void data() const{
    cout<<"Id: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
   }
   int getid(){return id;}
    string getname(){return name;}
    int getage(){return age;}
    void setName(const string &newName){name=newName;}
    void setage(int newage){age =newage;}
}; 
vector<Student>student;
void create(int id, const string &name, int age){
    student.emplace_back(id, name, age);
    cout<<"sucessfully!"<<endl;
}
void read(){
    for( auto students : student){
        students.data();
    }
}
void update(int id , const string &newName, int newage){
for(auto &students : student){
    if(students.getid()==id){
        students.setName(newName);
        students.setage(newage);
        cout<<"Sucessfully!"<<endl;
        return;
    }
}
}
void deletee(int id){
   for(size_t i=0; i<student.size(); i++){
    if(student[i].getid()==id){
        student.erase(student.begin()+i);
        cout<<"sucessfully!"<<endl;
    return;
    }
   }
}
int main(){
  int num;
  string name;int id,age; 
    do{
        cout<<"-----------------------------------------\n";
        cout<<"                1. Create Student\n";
        cout<<"                2. Read Student\n";
        cout<<"                3. Update Student\n";
        cout<<"                4. Delete Student\n";
        cout<<"                5. Exit\n";
        cin>>num;
        switch(num){
            case 1:
             
            cout<<"Insert id:";cin>>id;
            cout<<"Insert Name:";
            cin.ignore();
            getline(cin, name);
            cout<<"Insert Age:";cin>>age;
            create(id,name,age);
            break;
           
            case 2:
             read();
            break;

            case 3:
           
            cout<<"Insert id: ";cin>>id;
            cout<<"Insert name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Insert age: ";cin>>age;
            update(id,name,age);
            break;
            
            case 4:
           
             cout<<"Insert id:";cin>>id;
             deletee(id);             
            break;
            default:
            cout<<"Not found!";
            break;
        }


    }while(num!=5);
    return 0;
}