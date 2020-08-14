#include <bits/stdc++.h>
using namespace std;

struct node  { 
    string tag;
    map<string, string> m;  
    vector<node*>leaves;
    node* parent;

    node* FindWithTag(string t) {
        for (vector<node*>::iterator it = leaves.begin(); it != leaves.end(); ++it) {
            if (t.compare((*it)->tag) == 0) {
                return *it;
            }
        }
        return nullptr;
    }
}; 

struct node* newNode(string tag, node* par) { 
    struct node* node = new struct node(); 
    node->parent = par;
    node->tag = tag;
    return(node); 
}; 
  
int main() {
    int num, numQ;
    scanf("%d %d\n", &num, &numQ);
    node* root = newNode("root", nullptr);
    node* currentNode = root;
    for (int i = 0; i < num; ++i) {
        string line;
        getline(cin, line);
        long unsigned int location = line.find('/');
        if (location > line.size()) { //normal line
            location = line.find(' ');
            if (location == -1) location = line.find('>');
            node* node2 = newNode(line.substr(1,location-1), currentNode);
            string leftover = line.substr(location+1);
            while (location < leftover.size() && location != -1) {
                location = leftover.find(' ');
                string attribute = leftover.substr(0,location);
                leftover = leftover.substr(location+1);
                location = leftover.find('"');
                leftover = leftover.substr(location+1);
                location = leftover.find('"');
                string value = leftover.substr(0,location);
                location = leftover.find(' ');
                leftover = leftover.substr(location+1);
                node2->m.insert({attribute,value});
            }
            currentNode->leaves.push_back(node2);
            currentNode = node2;
        } else { //end line
            if (currentNode->parent != nullptr)
                currentNode = currentNode->parent;
        }
    }
    for (int i = 0; i < numQ; ++i) {
        string query;
        getline(cin,query);
        int location = query.find('.');
        bool error = false;
        node* current = root;
        while (location != -1) {
            string tag = query.substr(0,location);
            current = current->FindWithTag(tag);
            if (current == nullptr) {
                error = true;
                break;
            }
            query.erase(0,location+1);
            location = query.find('.');
        }
        if (error) {
            cout << "Not Found!" << endl;
            continue;
        }
        location = query.find('~');
        string tag = query.substr(0,location);
        current = current->FindWithTag(tag);
        if (current == nullptr) {
            cout << "Not Found!" << endl;
            continue;
        }
        string attribute = query.substr(location+1);
        //cout << attribute <<endl;

        auto it = current->m.find(attribute);
        if (it != current->m.end())
            cout << it->second << endl;
        else cout << "Not Found!" << endl;
    }
    return 0;
}
