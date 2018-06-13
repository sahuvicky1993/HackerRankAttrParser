#include "def.h"


int main() {
    
    vector<string> s,qry;
    int n,q;
    string input,query;
    cin>>n>>q;
    // We have to write this otherwise getline will not ignore whitespaces and you will end-up getting exrta line in map
    cin.ignore(1,'\n'); 
    for(int i=0;i<n;i++){ // Read strings here
        getline(cin,input);
        if(shouldContinue(input)) // check if we still have the data to store otherwise skip the lines
        s.push_back(input);
        else
        continue;
    }
    //cout<<"s.size()\n"<<s.size();
    create_DB(s,0);
    //show_map();
    // We have created the database now read queries and  ans it base on available info
    for(int i=0;i<q;i++){// read queries here
        getline(cin,query);
        qry.push_back(query);
    }
    //cout<<"q.size()\n"<<qry.size();
    create_DB(qry,1);
    // we are done
    return 0;
}

