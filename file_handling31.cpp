//! cin.get(); -> used to ignore new line  character present in the file / buffer , when taking i/p from Keyboard
//! fin.ignore(); ->  Consume the newline character left in the buffer when taking i/p from file 

#include<iostream>
#include<fstream>
using namespace std;
int ID=0;
class student
{
    public :
    int id;
    string name ;
    int age;
    string stream;

    void AddStudent()
    {
        cout<<"Enter your name"<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"Enter your age"<<endl;
        // cin.ignore();      
        cin>>age; 
        cout<<"Enter your stream"<<endl; 
        cin.ignore();  
        getline(cin,stream);
        ID++;  

        ofstream fout; 
        fout.open("c:/Myfile/student.txt",ios::app);
        fout<<"\n"<<ID; 
        fout<<"\n"<<name;
        fout<<"\n"<<age;
        fout<<"\n"<<stream;
        fout.close();

        fout.open("c:/Myfile/id.txt",ios::app);
        fout<<"\n"<<ID; 
        fout.close();

        cout<<"Record added successfully to file "<<endl;
        
    }

    void printAllStudent()
    {
        ifstream fin;
        fin.open("c:/Myfile/student.txt"); 
        student s;
        while(!fin.eof())
        {   
            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);
            // fin.ignore();  
            fin>>s.age;
            fin.ignore();
            getline(fin,s.stream);
              
            cout<<"\n id = "<<s.id;
            cout<<"\n name = "<<s.name;
            cout<<"\n age = "<<s.age; 
            cout<<"\n stream = "<<s.stream;   
        }
        fin.close();
    }

    void search(int id) 
    {   
        ifstream fin;
        fin.open("c:/Myfile/student.txt"); 
        student s;
        while(!fin.eof())
        {   //cout<<"hello"<<endl;
            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);
            // fin.ignore(); //! i think no need to write fin.ignore() fun before taking int i/p from file ; 
            fin>>s.age;
            fin.ignore();
            getline(fin,s.stream);

            if(id==s.id)
            {  // cout<<"hello Rupesh "<<endl;

                cout<<"\n id = "<<s.id;
                cout<<"\n name = "<<s.name;
                cout<<"\n age = "<<s.age; 
                cout<<"\n stream = "<<s.stream; 
                break;  
            }  
             
        }
        fin.close();
        

    }

    void Delete(int id)
    {
        ifstream fin;
        fin.open("c:/Myfile/student.txt");   
        student s;
        ofstream fout;
        fout.open("c:/Myfile/temp.txt");
        while(!fin.eof())
        {
            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);
            // fin.ignore();
            fin>>s.age;
            fin.ignore();
            getline(fin,s.stream); 
            if(id!=s.id) 
            {
                fout<<"\n"<< s.id;
                fout<<"\n"<<s.name;
                fout<<"\n"<<s.age;
                fout<<"\n"<<s.stream; 
            } 
        } 
        fin.close();
        fout.close();
        remove("c:/Myfile/student.txt");
        rename("c:/Myfile/temp.txt","c:/Myfile/student.txt");
        cout<<"Record has been successfully deleted  "<<endl;
    }

    void update(int id)
    {
       Delete(id);
            
        cout<<"Enter your name"<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"Enter your age"<<endl;
        // cin.ignore();      
        cin>>age; 
        cout<<"Enter your stream"<<endl; 
        cin.ignore();  
        getline(cin,stream);  

        ofstream fout; 
        fout.open("c:/Myfile/student.txt",ios::app);
        fout<<"\n"<<id; 
        fout<<"\n"<<name;
        fout<<"\n"<<age;
        fout<<"\n"<<stream;
        fout.close();

        cout<<"Record updated successfully to file "<<endl;
    }
};

int main()
{   
   
    ifstream fin;
    fin.open("c:/Myfile/id.txt");

    if(!fin)
    {
        cout<<"File not found !!"<<endl; 
    }else
    {
            if(fin.eof()!=0)
        {
            fin>>ID;
            // ID++;  
        }
    }
    fin.close();
    

    while(true)
    {
        cout<<"\n\n*********************************** Enter your choice ********************************************* "<<endl;
        cout<<"Enter 1 to Add student : "<<endl;
        cout<<"Enter 2 to Print All Student : "<<endl;
        cout<<"Enter 3 to search Student by id : "<<endl;
        cout<<"Enter 4 to update Student Record : "<<endl;
        cout<<"Enter 5 to Delete student Record  : "<<endl;  
        int choice ;
        cin>>choice;
        student s;
        
        switch(choice)
        { 
            case 1: s.AddStudent();
                    break;   
            case 2: s.printAllStudent();
                    break;
            case 3: cout<<"Enter id of student : ";
                    cin>>ID;
                    s.search( ID);
                    break;
            case 4: cout<<"Enter id of student : ";
                    cin>>ID;
                    s.update(ID);
                    break;
            case 5: cout<<"Enter id of student : ";
                    cin>>ID;
                    s.Delete(ID);
                    break;
            default: cout<<"You might have entered wrong choice "<<endl;
        } 
    }
   

    return 0;
} 