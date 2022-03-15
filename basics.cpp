#include <bits/stdc++.h>
using namespace std;

class File{
    private:
        string name;
        string path;
        int size;
        string content;
        static int count;
        
    void setName(string newName){
        this->name = newName;
    }
    
    void setPath(string newPath){
        this->path = newPath;
    }
    
    public:
        File(string name,string path){
            this->name = name;
            this->path = path;
            this->size = 0;
            this->content = "";
            count++;
        }
        
    static int getCount(){
        return count;
    }
    
    string getName(){
        return this->name;
    }
    
    string getPath(){
        return this->path;
    }
    
    int getSize(){
        return this->size;
    }
    
    string getContent(){
        return this->content;
    }
    
    string getAbsolutePath(){
        return this->path + '\\' + this->name;
    }
    
    void renameFile(string newName){
        this->setName(newName);
    }
    
    void moveFile(string newPath){
        this->setPath(newPath);
    }
    
    
    void setContent(string newContent){
        this->content = newContent;
        this->size = this->content.size();
    }
    
    void addContent(string newContent){
        this->content = this->content + newContent;
        this->size = this->content.size();
    }
    
};

int File :: count = 0;


int main()
{
    File f("abc","C:\\home");
    f.renameFile("movie");
    cout<<f.getAbsolutePath()<<endl;
    f.moveFile("D:\\akash\\Documents");
    f.renameFile("binaryTree.cpp");
    cout<<f.getAbsolutePath();
    cout<<f.getCount();
    return 0;
}


