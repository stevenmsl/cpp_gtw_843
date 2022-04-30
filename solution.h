
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <stack>

using namespace std;
namespace sol830
{

  class Master
  {
  private:
    string _secret;
    unordered_set<string> wordSet;

  public:
    Master(string secret, vector<string> &words);
    int guess(string s);
  };

  class Solution
  {
  private:
    int match(string &source, string &target);

  public:
    string find(vector<string> &words, Master &master);
  };
}
#endif