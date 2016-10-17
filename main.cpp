#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>

using std::string;
using std::unordered_map;
using std::deque;

class solution {
public:
  int longestSubstring(const string & s, int k) {
    unordered_map<char, deque<size_t>> dict;
    size_t begin = s.size(), end = 0, i;
    i = 0;
    while (i < s.size() && !valLtTwo(dict)) {
      if (dict.find(s[i]) == dict.end())
	dict[s[i]] = deque<size_t>();
      dict[s[i]].push_back(i);
      i++;
    }

    // for (auto it = dict.begin(); it != dict.end(); ++it) {
    //   if (it->second.front() < begin)
    // 	begin = it->second.front();
    //   if (it->second.back() > end)
    // 	end = it->second.back();
    // }
    // std::cout << "begin = " << begin << ", end = " << end << std::endl;
    // std::cout << s.substr(begin, end-begin+1) << std::endl;

    while (i < s.size() && valLtTwo(dict)) {
      if (dict.find(s[i]) == dict.end())
	dict[s[i]] = deque<size_t>();
      dict[s[i]].push_back(i);
      i++;
    }

    size_t begin_new(s.size()), end_new(0);
    for (auto it = dict.begin(); it != dict.end(); ++it) {
      if (it->second.front()<begin_new)
	begin_new = it->second.front();
      if (it->second.back() > end_new)
	end_new = it->second.back();
    }

    std::cout << "begin_new = " << begin_new << ", end_new = " << end_new-1 << std::endl;
    std::cout << s.substr(begin_new, end_new-begin_new) << std::endl;

    return 0;
  }

private:
  bool valLtTwo(unordered_map<char,deque<size_t>> & a_map) {
    if (!a_map.empty()) {
      for (auto it = a_map.begin(); it != a_map.end(); ++it)
	if (it->second.size() < 2)
	  return false;
      return true;
    }
    else
      return false;
  }
};

int main() {
  // string s{"aaabb"};
  // int k = 3;

  string s{"ababbc"};
  int k = 2;

  solution soln;
  int substr = soln.longestSubstring(s, k);
  
}
