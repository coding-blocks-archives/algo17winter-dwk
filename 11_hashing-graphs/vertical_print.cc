// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    map<int, vector<Node*> > m;

    map<int, vector<Node*> >::iterator begIt = m.begin();
    map<int, vector<Node*> >::iterator endIt = m.end();

    typedef map<int, vector<Node*> >::iterator mit;

    for(mit it = begIt; it != endIt; ++it){
        pair<int, vector<Node*> >& p = *it;

    }




}