#include <cstdio>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#define PB push_back
using namespace std;
 
struct Category {
  Category(string name, const vector<string> & keywords, int need)
    : name(name), keywords(keywords), need(need) {}
  bool match(const set<string> & words) {
    int appear = 0;
    for (set<string>::iterator it = words.begin(); it != words.end(); it++) {
      appear += has(*it);
      if (appear >= need) {
        return true;
      }
    }
    return appear >= need;
  }
  bool has(const string & word) {
    for (int i = 0; i < keywords.size(); i++) {
      if (word == keywords[i]) {
        return true;
      }
    }
    return false;
  }
  string name;
  vector<string> keywords;
  int need;
};
 
int main() {
  char temp[9999];
  gets(temp);
  int N;
  sscanf(temp, "%d", &N);
  while (N--) {
    gets(temp);
    int C;
    sscanf(temp, "%d", &C);
    vector<Category> categories;
    for (int i = 0; i < C; i++) {
      gets(temp);
      char name[99];
      vector<string> keywords;
      int size, need;
      sscanf(temp, "%s%d%d", name, &size, &need);
      while (size--) {
        gets(temp);
        keywords.PB(temp);
      }
      categories.PB(Category(name, keywords, need));
    }
    set<string> words;
    while (gets(temp) && temp[0]) {
      for (int i = 0; temp[i]; i++) {
        if (!isalpha(temp[i])) {
          temp[i] = ' ';
        }
      }
      istringstream ss(temp);
      string s;
      while (ss >> s) {
        words.insert(s);
      }
    }
    bool first = true;
    for (int i = 0; i < categories.size(); i++) {
      if (categories[i].match(words)) {
        printf("%s%s", first ? "" : ",", categories[i].name.c_str());
        first = false;
      }
    }
    puts(first ? "SQF Problem." : "");
  }
  return 0;
}