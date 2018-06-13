#include"def.h"

//Create database here, Let it be global
map<string,pair<string,string> > m;

// Here is our parsing logic which helps us removing un-necessary words and char
void create_DB(vector<string> input,int op){
	vector<string>::iterator it=input.begin();
	for(;it!=input.end();++it){
        std::string line;
        vector<string> wordVector;
        line =*it;
        std::size_t prev = 0, pos;
        while ((pos = line.find_first_of(" <>';\"=.~", prev)) != std::string::npos)
        {
            if (pos > prev)
                wordVector.push_back(line.substr(prev, pos-prev));
            prev = pos+1;
        }
    if (prev < line.length())
        wordVector.push_back(line.substr(prev, std::string::npos));
    if(op==0)
    store(wordVector);
    else if(op==1)
    ansToQueries(wordVector);
    //printVector(wordVector);
	}//for
}//Fn

void store(vector<string>s ){
    vector<string>::iterator it=s.begin();
   //printVector(s);
   // Big Issue here toDo check why can't use ++it outside 
   string value("NULL"),name("NULL"),tag("NULL");
   for(;it!=s.end();++it){
    if(strstr((*it).c_str(),"tag")) tag=*it;
    if(strstr((*it).c_str(),"value")){++it;
         value=*it;
    }
    if(strstr((*it).c_str(),"name")){++it;
        name=*it;
    }
   }
  
  //cout<<tag<<" "<<value<<" "<<name<<"\n";
   m.insert( make_pair(tag, make_pair(value,name)) );
   
}
void show_map(void){
    map<string,pair<string,string> >::iterator it=m.begin();
    for(;it!=m.end();++it){
        cout<<it->first<<" "<<(it->second).first<<" "<<(it->second).second<<endl;
    }//for
}
void ansToQueries(vector<string> q){
    // key  VALUE VALUE
    // tag1 value NULL
    // tag2 NULL  name
    string tag;
    map<string,pair<string,string> >:: iterator m_it;
    //std::pair<std::map<string,pair<string,string> >::iterator,bool> ret;
    vector<string>::iterator it;
    for(it=q.begin();it!=q.end();++it){
        if(strstr((*it).c_str(),"tag")){
        tag=*it;
        continue;
        }
        else if(strstr((*it).c_str(),"value")){
            m_it=m.find(tag);
            ((m_it->second).first=="NULL") ? cout<<"Not Found\n": cout<<(m_it->second).first<<"\n";
        }
        else if(strstr((*it).c_str(),"name")){
             m_it=m.find(tag);
             ((m_it->second).second=="NULL") ? cout<<"Not Found\n":cout<<(m_it->second).second<<"\n";
        }
    }
    
}

bool shouldContinue(string ip){
	if(ip.find('/') != std::string::npos)  // '/' is encountered in the i/p which means we should not continue (storing) further
	return false;

return true;
}

void printVector(vector<string> wordVector){
	vector<string>::iterator i;
    for(i=wordVector.begin();i!=wordVector.end();++i)
    cout<<*i<<endl;
}
